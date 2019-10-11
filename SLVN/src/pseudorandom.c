#include <pseudorandom.h>

SLVN_RESULT slvn_init_mt(slvn_mt* mt)
{
	mt->mti = N + 1;
	return SLVN_OK;
}

SLVN_RESULT slvn_init_genrand64(slvn_mt* mt, unsigned long long seed)
{
	mt->mt[0] = seed;
	for (mt->mti = 1; mt->mti < N; mt->mti++)
	{
		mt->mt[mt->mti] = (6364136223846793005ULL * (mt->mt[mt->mti - 1] ^ (mt->mt[mt->mti - 1] >> 62)) + mt->mti);
	}

	if (mt->mt[mt->mti] == 0)
	{
		return SLVN_UNEXPECTED_RESULT;
	}
	return SLVN_OK;
}

unsigned long long slvn_genrand64_int(slvn_mt* mt)
{
	int i;
	unsigned long long x;
	static unsigned long long a[2] = { 0ULL, MATRIX_A };

	if (mt->mti >= N)
	{
		if (mt->mti == N + 1) // This means that the genrand64 has not been called 
		{
			slvn_init_genrand64(mt, 5489ULL);
			SLVN_PRINT("SLVN_MT WARNING: As init_genrand64 was not called, a default seed 5489ULL was used.");
		}

		for (i = 0; i < N - M; i++)
		{
			x = (mt->mt[i] & UPPER_MASK) | (mt->mt[i + 1] & LOWER_MASK);
			mt->mt[i] = mt->mt[i + M] ^ (x >> 1) ^ a[(int)(x & 1ULL)];
		}

		for (; i < N - 1; i++)
		{
			x = (mt->mt[i] & UPPER_MASK) | (mt->mt[i + 1] & LOWER_MASK);
			mt->mt[i] = mt->mt[i + (M - N)] ^ (x >> 1) ^ a[(int)(x & 1ULL)];
		}

		x = (mt->mt[N - 1] & UPPER_MASK) | (mt->mt[0] & LOWER_MASK);
		mt->mt[N - 1] = mt->mt[M - 1] ^ (x >> 1) ^ a[(int)(x & 1ULL)];

		mt->mti = 0;
	}

	x = mt->mt[mt->mti++];

	// Tempering the matrices
	// Multiply each generated word by a suitable w * x invertible matrix T from the right
	// First three temperings improve the most significant bits
	// Last one improves the least significant bits

	x ^= (x >> 29) & 0x5555555555555555ULL;
	x ^= (x << 17) & 0x71D67FFFEDA60000ULL;
	x ^= (x << 37) & 0xFFF7EEE000000000ULL;
	x ^= (x >> 43);

	return x;
}
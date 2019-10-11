//	This is an implementation of the Mersenne Twister pseudo random number generator
//	 MT19937 as a 64-bit implementation
//
//	 Based on the original implementation by:
//	 M. Matsumoto and T. Nishimura,
//	 Mersenne Twister: A 623-dimensionally equidistributed
//	 uniform pseudorandom number generator
//   ACM Transactions on Modeling and Computer Simulation,
//   Vol. 8, No. 1, January 1998, pp 3--30.

#ifndef SLVN_PSEUDORANDOM_H
#define SLVN_PSEUDORANDOM_H

#include <core.h>
#include <debug.h>


#define N			312
#define M			156
#define MATRIX_A	0xB5026F5AA96619E9ULL
#define UPPER_MASK	0xFFFFFFFF80000000ULL	/* MSB (33)*/
#define LOWER_MASK	0x7FFFFFFFULL			/* LSB (33)*/

typedef struct
{
	unsigned long long mt[N];
	int mti;
} slvn_mt;

SLVN_EXTERN_BEGIN
SLVN_RESULT			SLVN_API	slvn_init_mt(slvn_mt* mt);
SLVN_RESULT			SLVN_API	slvn_init_genrand64(slvn_mt* mt, unsigned long long seed);
unsigned long long	SLVN_API	slvn_genrand64_int(slvn_mt* mt);
SLVN_EXTERN_END


#endif // SLVN_PSEUDORANDOM_H
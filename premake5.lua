workspace "SLVN"
	configurations {"Debug", "Release"}
	targetdir "./builds/%{cfg.buildcfg}/%{cfg.platform}"
	objdir "./builds/obj/%{cfg.buildcfg}/%{cfg.platform}"
	location "./project-files"

	libdirs {
		"../builds/%{cfg.buildcfg}/%{cfg.platform}"
	}
	
	configuration "Debug"
		defines {
			"DEBUG"
		}
	
	configuration "Release"
		defines {
			"NDEBUG"
		}
	
	configuration "macosx"	
		platforms { "x64" }
	configuration "not macosx"
		platforms { "x86", "x64" }

	configuration "windows"
		characterset "MBCS"
		systemversion "10.0.17763.0"
		defines {
			"_CRT_SECURE_NO_WARNINGS",
			"WIN32_LEAN_AND_MEAN"
		}

project "SLVN"
	targetname "slvn"
	kind "SharedLib"
	-- kind "WindowedApp"
	language "C++"
	files { "./slvn/include/**.h", "./slvn/src/**.cpp", "./slvn/src/**.h" }

	defines {"AJP_BUILD_DLL"}
	links {}
	configuration "x64"
		libdirs {}
		
	configuration "x86"
		libdirs {}
		
	configuration "not macosx"
		includedirs {"./slvn/include"}
	configuration "macosx"
		sysincludedirs {"./slvn/include"}

	configuration "windows"
		defines {}
		links {}

	configuration "not windows"
		defines {}

	configuration "linux"
		defines {}

	configuration "macosx"
		defines {}

	configuration "android"
		defines {}

	configuration "Debug"
		defines {"DEBUG"}
		symbols "On"	

	configuration "Release"
		defines {"NDEBUG"}
		optimize "On"


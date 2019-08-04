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
		systemversion "10.0.17134.0"
		defines {
			"_CRT_SECURE_NO_WARNINGS",
			"WIN32_LEAN_AND_MEAN"
		}

project "slvn_hashtable"
	targetname "slvn_hashtable"
	kind "ConsoleApp"
	-- kind "WindowedApp"
	language "C"
	files { "./slvn/hashtable/include/**.h", "./slvn/hashtable/src/**.c", "./slvn/hashtable/src/**.h" }

	defines {}
	links {}
	configuration "x64"
		libdirs {}
		
	configuration "x86"
		libdirs {}
	
	configuration "not macosx"
		includedirs {"./slvn/hashtable/include"}
	configuration "macosx"
		sysincludedirs {"./slvn/hashtable/include"}

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


project "slvn_window"
	targetname "slvn_window"
	kind "ConsoleApp"
	-- kind "WindowedApp"
	language "C"
	links {"glfw3"}
	files { "./slvn/window/include/**.h", "./slvn/window/src/**.c", "./slvn/window/src/**.h" }

	defines {}
	links {}
	configuration "x64"
		libdirs {}
		
	configuration "x86"
		libdirs {}
		
	configuration "not macosx"
		includedirs {"./slvn/window/include", "./slvn/window/libs/glfw/include"}
		libdirs {"./slvn/window/libs/glfw/lib-vc2019/"}
	configuration "macosx"
		sysincludedirs {"./slvn/window/include", "./slvn/window/libs/glfw/include"}

	configuration "windows"
		defines {}
		links {}

	configuration "not windows"
		defines {}

	configuration "linux"
		defines {}

	configuration "Debug"
		defines {"DEBUG"}
		symbols "On"	

	configuration "Release"
		defines {"NDEBUG"}
		optimize "On"


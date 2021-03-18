workspace "ChessFw"
	configurations { "debug", "release" }

-- enable warnings
-- flags "FatalWarnings"
-- warnings "Extra"

project "ChessFw"
	kind "StaticLib"
	language "C++"
	--cppdialect "C++17"
	buildoptions "-std=c++2a"
	targetdir "bin/%{cfg.buildcfg}"

	files { "include/**.hpp", "source/**.cpp" }
	includedirs { "include" }

	filter "configurations:debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:release"
		defines { "RELEASE" }
		optimize "On"

project "ChessFwTest"
	kind "ConsoleApp"
	language "C++"

	buildoptions "-std=c++2a"
	targetdir "bin/%{cfg.buildcfg}"

	files { "tests/tests.cpp" }
	includedirs { "include" }
	links { "ChessFw" }

	filter "configurations:debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:release"
		defines { "RELEASE" }
		optimize "On"

project "ConsoleChess"
	kind "ConsoleApp"
	language "C++"

	buildoptions "-std=c++2a"
	targetdir "bin/%{cfg.buildcfg}"

	files { "examples/ConsoleChess.cpp" }
	includedirs { "include" }
	links { "ChessFw" }

	filter "configurations:debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:release"
		defines { "RELEASE" }
		optimize "On"
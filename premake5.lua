workspace "ChessFw"
	configurations { "debug", "release" }

function useCpp20()
	filter "system:windows"
		cppdialect "C++latest"

	filter "system:linux"
		buildoptions "-std=c++20"
	
	filter {}
end
	
project "ChessFw"
	kind "StaticLib"
	language "C++"
	useCpp20()

	targetdir "bin/%{cfg.buildcfg}"

	files { "include/**.hpp", "source/**.cpp" }
	includedirs { "include" }

	filter "configurations:debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:release"
		defines { "RELEASE" }
		optimize "On"

	filter {}

project "ConsoleChess"
	kind "ConsoleApp"
	language "C++"
	useCpp20()
	
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

	filter {}
workspace "ChessFw"
	configurations { "Debug", "Release" }

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

	targetdir "Bin/%{cfg.buildcfg}"
	builddir "Obj"

	files { "Include/**.hpp", "Source/**.cpp" }
	includedirs { "Include" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"

	filter {}

project "SDL2Chess"
	kind "ConsoleApp"
	language "C++"
	useCpp20()

	targetdir "Examples/Bin/%{cfg.buildcfg}"
	builddir "Examples/Obj"

	files { "Examples/SDL2Chess/Source/**.cpp" }
	includedirs { "Include" }

	links { "ChessFw", "SDL2", "SDL2_image" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"
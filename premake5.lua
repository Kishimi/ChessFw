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
	objdir "Obj"

	files { "Include/**.hpp", "Source/**.cpp" }
	includedirs { "Include" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"

	filter {}

project "ChessApp"
	kind "ConsoleApp"
	language "C++"
	useCpp20()

	targetdir "Examples/Bin/%{cfg.buildcfg}"
	objdir "Examples/Obj"

	files { "Examples/ChessApp/Source/**.cpp" }
	includedirs { "Include" }

	links { "ChessFw", "sfml-graphics", "sfml-system" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"
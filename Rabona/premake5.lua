workspace "Rabona"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Rabona"
	location "Rabona"
	kind "SharedLib"
	language "C++"

	targetdir("bin/".. outputdir .."/%{prj.name}")
	objdir("bin-int/".. outputdir .."/%{prj.name}")
	
	
	files
	{
		
		"src/**.h",
		"src/**.cpp"

	}
	
	includedirs
	{

		"%{prj.name}/vendor/spdlog/include",
		"Rabona/Rabona.h"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0.18362.0"

		defines
		{
			"RB_BUILD_DLL",
			"RB_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{

		("{COPY} %{cfg.buildtarget.realpath} ../bin/" ..outputdir.. "/Sandbox")

		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "on"
			
	filter "configurations:Release"
		defines "HZ_Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "on"
	

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	
	targetdir ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")
	
	files
	{
		"../%{prj.name}/src/**.h",
		"../%{prj.name}/src/**.cpp"

	}
	
	includedirs
	{
		"Rabona/vendor/spdlog/include",
		"../Rabona/src"
	}
	links
	{
		"Rabona"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0.18362.0"

		defines
		{
			"RB_PLATFORM_WINDOWS"
			
			
		}

	

		

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "on"
			
	filter "configurations:Release"
		defines "HZ_Release"
		symbols "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		symbols "on"
workspace "Rabona"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Rabona/vendor/GLFW/include"

include "Rabona/vendor/GLFW"

project "Rabona"
	location "Rabona"
	kind "SharedLib"
	language "C++"

	targetdir("bin/".. outputdir .."/%{prj.name}")
	objdir("bin-int/".. outputdir .."/%{prj.name}")
	
	pchheader "rbpch.h"
	pchsource "Rabona/src/rbpch.cpp"
	
	files
	{
		
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}
	
	includedirs
	{

		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"Opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"RB_BUILD_DLL",
			"RB_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
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

	
	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}
	
	includedirs
	{
		"Rabona/vendor/spdlog/include",
		"Rabona/src"
	
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
		defines "RB_DEBUG"
		symbols "on"
			
	filter "configurations:Release"
		defines "RB_Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RB_DIST"
		optimize "on"
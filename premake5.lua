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
IncludeDir["Glad"] = "Rabona/vendor/Glad/include"
IncludeDir["ImGui"] = "Rabona/vendor/imgui/include"

include "Rabona/vendor/GLFW"
include "Rabona/vendor/Glad"
include "Rabona/vendor/imgui"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	}

	links
	{
		"Glad",
		"GLFW",
		"ImGui",
		"Opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"RB_BUILD_DLL",
			"RB_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		buildoptions "/MDd"
		symbols "on"
			
	filter "configurations:Release"
		defines "HZ_Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		buildoptions "/MD"
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
		buildoptions "/MDd"
		symbols "on"
			
	filter "configurations:Release"
		defines "RB_Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "RB_DIST"
		buildoptions "/MD"
		optimize "on"
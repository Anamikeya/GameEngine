#pragma once

#ifdef RB_PLATFORM_WINDOWS
	#ifdef RB_BUILD_DLL
		#define RABONA_API __declspec(dllexport)
	#else
#define RABONA_API __declspec(dllimport)
	#endif
#else	
	#error Rabona only supports windows
	
#endif

#ifdef RB_ENABLE_ASSERTS
	#define RB_CLIENT_ASSERT(x, ...) { RB_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define RB_CORE_ASSERT*x, ...) {if(!(x)) {RB_CORE_ERROR("Assertion Failed: {0})", __VA_ARGS__); __debugbreak()} 
#else
	#define RB_CLIENT_ASSERT(x, ...)
	#define RB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x) 
#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace Rabona {
	class RABONA_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//macros for CORE logging function to avoid large line of initialization

#define RB_CORE_TRACE(...)    ::Rabona::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define RB_CORE_INFO(...)     ::Rabona::Log::GetCoreLogger()->info(__VA_ARGS__);
#define RB_CORE_WARN(...)     ::Rabona::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define RB_CORE_ERROR(...)    ::Rabona::Log::GetCoreLogger()->error(__VA_ARGS__);
#define RB_CORE_FATAL(...)    ::Rabona::Log::GetCoreLogger()->fatal(__VA_ARGS__);

//CLIENT LOGGING MACROS

#define RB_CLIENT_TRACE(...)    ::Rabona::Log::GetClientLogger()->trace(__VA_ARGS__);
#define RB_CLIENT_INFO(...)     ::Rabona::Log::GetClientLogger()->info(__VA_ARGS__);
#define RB_CLIENT_WARN(...)     ::Rabona::Log::GetClientLogger()->warn(__VA_ARGS__);
#define RB_CLIENT_ERROR(...)    ::Rabona::Log::GetClientLogger()->error(__VA_ARGS__);
#define RB_CLIENT_FATAL(...)    ::Rabona::Log::GetClientLogger()->fatal(__VA_ARGS__);

//if dist built 
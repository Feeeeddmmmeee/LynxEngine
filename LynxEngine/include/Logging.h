#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_NONE 4

#ifndef LYNX_LOG_LEVEL
	#define LYNX_LOG_LEVEL LOG_LEVEL_INFO
#endif

namespace Lynx
{
	class Logger {
		public:
			static std::shared_ptr<spdlog::logger> &getClientLogger()
			{
				static std::shared_ptr<spdlog::logger> clientLogger = createLogger("CLIENT");
				return clientLogger;
			}
			static std::shared_ptr<spdlog::logger> &getEngineLogger()
			{
				static std::shared_ptr<spdlog::logger> engineLogger = createLogger("LYNX");
				return engineLogger;
			}

		protected:
			static std::shared_ptr<spdlog::logger> createLogger(std::string name)
			{
				auto logger = spdlog::stdout_color_mt(name);
				logger->set_level(spdlog::level::trace);
				logger->set_pattern("%^[%Y-%m-%d %T] [%P] [%n] [%l]: %v%$");
				return logger;
			}
	};
}

#if LYNX_LOG_LEVEL <= LOG_LEVEL_DEBUG
	#define LYNX_DEBUG(...) Lynx::Logger::getClientLogger()->debug(__VA_ARGS__)
	#define LYNX_ENGINE_DEBUG(...) Lynx::Logger::getEngineLogger()->debug(__VA_ARGS__)
#else
	#define LYNX_DEBUG(...)
	#define LYNX_ENGINE_DEBUG(...)
#endif

#if LYNX_LOG_LEVEL <= LOG_LEVEL_INFO
	#define LYNX_INFO(...)  Lynx::Logger::getClientLogger()->info(__VA_ARGS__)
	#define LYNX_ENGINE_INFO(...)  Lynx::Logger::getEngineLogger()->info(__VA_ARGS__)
#else
	#define LYNX_INFO(...)
	#define LYNX_ENGINE_INFO(...)
#endif

#if LYNX_LOG_LEVEL <= LOG_LEVEL_WARN
	#define LYNX_WARN(...)  Lynx::Logger::getClientLogger()->warn(__VA_ARGS__)
	#define LYNX_ENGINE_WARN(...)  Lynx::Logger::getEngineLogger()->warn(__VA_ARGS__)
#else
	#define LYNX_WARN(...)
	#define LYNX_ENGINE_WARN(...)
#endif

#if LYNX_LOG_LEVEL <= LOG_LEVEL_ERROR
	#define LYNX_ERROR(...) Lynx::Logger::getClientLogger()->error(__VA_ARGS__)
	#define LYNX_ENGINE_ERROR(...) Lynx::Logger::getEngineLogger()->error(__VA_ARGS__)
#else
	#define LYNX_ERROR(...)
	#define LYNX_ENGINE_ERROR(...)
#endif

#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

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

// TODO: being able to disable individual log levels
#ifndef LYNX_STRIP_LOGS
	#define LYNX_ERROR(...) Lynx::Logger::getClientLogger()->error(__VA_ARGS__)
	#define LYNX_WARN(...)  Lynx::Logger::getClientLogger()->warn(__VA_ARGS__)
	#define LYNX_INFO(...)  Lynx::Logger::getClientLogger()->info(__VA_ARGS__)
	#define LYNX_DEBUG(...) Lynx::Logger::getClientLogger()->debug(__VA_ARGS__)

	#define LYNX_ENGINE_ERROR(...) Lynx::Logger::getEngineLogger()->error(__VA_ARGS__)
	#define LYNX_ENGINE_WARN(...)  Lynx::Logger::getEngineLogger()->warn(__VA_ARGS__)
	#define LYNX_ENGINE_INFO(...)  Lynx::Logger::getEngineLogger()->info(__VA_ARGS__)
	#define LYNX_ENGINE_DEBUG(...) Lynx::Logger::getEngineLogger()->debug(__VA_ARGS__)
#else
	#define LYNX_ERROR(...)
	#define LYNX_WARN(...)
	#define LYNX_INFO(...)
	#define LYNX_DEBUG(...)

	#define LYNX_ENGINE_ERROR(...)
	#define LYNX_ENGINE_WARN(...)
	#define LYNX_ENGINE_INFO(...)
	#define LYNX_ENGINE_DEBUG(...)
#endif

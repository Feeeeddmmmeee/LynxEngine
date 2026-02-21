#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#define LYNX_LOG_LEVEL_DEBUG 0
#define LYNX_LOG_LEVEL_INFO 1
#define LYNX_LOG_LEVEL_WARN 2
#define LYNX_LOG_LEVEL_ERROR 3
#define LYNX_LOG_LEVEL_NONE 4

#ifndef LYNX_CLIENT_LOG_LEVEL
	#define LYNX_CLIENT_LOG_LEVEL LYNX_LOG_LEVEL_DEBUG
#endif

#ifndef LYNX_ENGINE_LOG_LEVEL
	#define LYNX_ENGINE_LOG_LEVEL LYNX_LOG_LEVEL_NONE
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

#define LYNX_LOG_INTERNAL(level, threshold, logger, ...) \
    (((level) <= (threshold)) ? logger(__VA_ARGS__) : (void)0)

#define LYNX_DEBUG(...) LYNX_LOG_INTERNAL(LYNX_CLIENT_LOG_LEVEL, LYNX_LOG_LEVEL_DEBUG, Lynx::Logger::getClientLogger()->debug, __VA_ARGS__)
#define LYNX_INFO(...)  LYNX_LOG_INTERNAL(LYNX_CLIENT_LOG_LEVEL, LYNX_LOG_LEVEL_INFO,  Lynx::Logger::getClientLogger()->info,  __VA_ARGS__)
#define LYNX_WARN(...)  LYNX_LOG_INTERNAL(LYNX_CLIENT_LOG_LEVEL, LYNX_LOG_LEVEL_WARN,  Lynx::Logger::getClientLogger()->warn,  __VA_ARGS__)
#define LYNX_ERROR(...) LYNX_LOG_INTERNAL(LYNX_CLIENT_LOG_LEVEL, LYNX_LOG_LEVEL_ERROR, Lynx::Logger::getClientLogger()->error, __VA_ARGS__)

#define LYNX_ENGINE_DEBUG(...) LYNX_LOG_INTERNAL(LYNX_ENGINE_LOG_LEVEL, LYNX_LOG_LEVEL_DEBUG, Lynx::Logger::getEngineLogger()->debug, __VA_ARGS__)
#define LYNX_ENGINE_INFO(...)  LYNX_LOG_INTERNAL(LYNX_ENGINE_LOG_LEVEL, LYNX_LOG_LEVEL_INFO,  Lynx::Logger::getEngineLogger()->info,  __VA_ARGS__)
#define LYNX_ENGINE_WARN(...)  LYNX_LOG_INTERNAL(LYNX_ENGINE_LOG_LEVEL, LYNX_LOG_LEVEL_WARN,  Lynx::Logger::getEngineLogger()->warn,  __VA_ARGS__)
#define LYNX_ENGINE_ERROR(...) LYNX_LOG_INTERNAL(LYNX_ENGINE_LOG_LEVEL, LYNX_LOG_LEVEL_ERROR, Lynx::Logger::getEngineLogger()->error, __VA_ARGS__)

#ifndef LYNX_DISABLE_ASSERTS
	#define LYNX_ASSERT(x, ...) do { \
		if(!(x)) { \
			LYNX_ERROR("Assertion failed! {}", __VA_ARGS__);\
			std::exit(1); \
		} \
	} while(0) 
	#define LYNX_ENGINE_ASSERT(x, ...) do { \
		if(!(x)) { \
			LYNX_ENGINE_ERROR("Assertion failed! {}", __VA_ARGS__);\
			std::exit(1); \
		} \
	} while(0) 
#else
	#define LYNX_ASSERT(x, ...) (void)0
	#define LYNX_ENGINE_ASSERT(x, ...) (void)0
#endif

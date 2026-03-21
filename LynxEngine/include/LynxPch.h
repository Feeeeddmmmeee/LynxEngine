#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits>
#include <array>
#include <chrono>

#ifdef LYNX_VULKAN
#define VULKAN_HPP_NO_STRUCT_CONSTRUCTORS
#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_raii.hpp>
#endif

#include <stb/stb_image.h>
#include <tiny_obj_loader.h>

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/hash.hpp>

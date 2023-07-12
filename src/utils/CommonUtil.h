// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#pragma once

#include <Token.h>

#include <queue>
#include <string>

namespace ts::compiler {

/**
 * Util for general simplification of tasks
 */
class CommonUtil {
 public:
  static void replaceAll(std::string &haystack, const std::string &needle,
                         const std::string &replacement);
  static std::string getLastFragment(const std::string &haystack,
                                     const std::string &needle);
};

}  // namespace ts::compiler
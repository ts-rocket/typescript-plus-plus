// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#include "../utils/CodeLoc.h"

#include <utility>

#include "utils/CommonUtil.h"

namespace ts::compiler {

CodeLoc::CodeLoc(size_t line, size_t col, std::string sourceFilePath)
    : sourceFilePath(std::move(sourceFilePath)), line(line), col(col) {
  CommonUtil::replaceAll(this->sourceFilePath, "\\", "/");
}

CodeLoc::CodeLoc(const antlr4::Token *token, std::string sourceFilePath)
    : sourceFilePath(std::move(sourceFilePath)),
      line(token->getLine()),
      col(token->getCharPositionInLine() + 1) {
  CommonUtil::replaceAll(this->sourceFilePath, "\\", "/");
}

/**
 * Returns the code location as a string for using it as a map key or similar
 *
 * @return Code location string
 */
std::string CodeLoc::toString() const {
  return "L" + std::to_string(line) + "C" + std::to_string(col);
}

/**
 * Returns the code location in a pretty form
 *
 * @return Pretty code location
 */
std::string CodeLoc::toPrettyString() const {
  return (sourceFilePath.empty() ? "" : sourceFilePath + ":") +
         std::to_string(line) + ":" + std::to_string(col);
}

/**
 * Returns the line number in a pretty form
 *
 * @return Pretty line number
 */
std::string CodeLoc::toPrettyLine() const { return "L" + std::to_string(line); }

/**
 * Returns the line and column numbers in a pretty form
 *
 * @return Pretty line and column numbers
 */
std::string CodeLoc::toPrettyLineAndColumn() const { return toString(); }

}  // namespace ts::compiler

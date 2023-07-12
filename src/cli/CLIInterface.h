// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#pragma once

#include <utility>

#include "cli11/CLI11.hpp"

namespace ts::compiler {

enum OptLevel : uint8_t {
  O0 = 0,  // No optimization
  O1 = 1,  // Only basic optimizations
  O2 = 2,  // Default optimization level
  O3 = 3,  // Aggressively optimize for performance
  Os = 4,  // Optimize for code size
  Oz = 5,  // Aggressively optimize for code size
};

/**
 * Representation of the various cli options
 */
struct CliOptions {
  std::string mSourceFile;
  std::string mOutputPath;
  unsigned short mCompileJobCount = 0;  // 0 for auto
  bool mPrintDebugOutput = false;
  bool mDumpCST = false;
  bool mDumpAST = false;
  bool mDumpIR = false;
  bool mDumpSymbolTables = false;
  bool mDisableAstOpt = false;
  OptLevel mOptLevel = O2;
  bool mGenerateDebugInfo = false;
};

/**
 * Helper class to setup the cli interface and command line parser
 */
class CLIInterface {
 public:
  // Constructors
  explicit CLIInterface() = default;

  // Public methods
  void createInterface();
  int parse(int argc, char **argv);

  // Public members
  CliOptions mCliOptions;

 private:
  // Members
  CLI::App mApp = CLI::App{"Typescript Programming Language", "Typescript"};
};

}  // namespace ts::compiler

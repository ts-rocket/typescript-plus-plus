// Copyright (c) 2021-2023 ChilliBits. All rights reserved.

#include "CLIInterface.h"

#include <exception/CliError.h>
#include <llvm/ADT/Triple.h>
#include <llvm/Support/Host.h>

#include "utils/CompilerWarning.h"
#include "utils/FileUtil.h"

namespace ts::compiler {

void CLIInterface::createInterface() {
  // Allow positional args
  mApp.allow_windows_style_options();
  mApp.allow_extras();
  mApp.positionals_at_end();
  mApp.footer("(c) menmen 2021-2023");

  // Add version flag
  std::string versionName = std::string(TS_VERSION);
  std::string builtBy = std::string(TS_BUILT_BY);
  std::string versionString = "ts2llvm version " + versionName +
                              "\nbuilt by: " + builtBy +
                              "\n\n(c) menmen 2021-2023";
  mApp.set_version_flag("--version,-v", versionString);

  // source file
  mApp.add_option<std::string>("<source-file>", mCliOptions.mSourceFile,
                               "source file")
      ->check(CLI::ExistingFile)
      ->required();

  // output path
  mApp.add_option<std::string>("--output,-o", mCliOptions.mOutputPath,
                               "output file")
      ->check(CLI::ExistingDirectory);

  // --debug-output
  mApp.add_flag<bool>("--debug-output,-d", mCliOptions.mPrintDebugOutput,
                      "Enable debug output");
  // --dump-cst
  mApp.add_flag<bool>("--dump-cst,-cst", mCliOptions.mDumpCST,
                      "Dump CST as serialized string and SVG image");

  // --dump-ast
  mApp.add_flag<bool>("--dump-ast,-ast", mCliOptions.mDumpAST,
                      "Dump AST as serialized string and SVG image");
  // --dump-symtab
  mApp.add_flag<bool>("--dump-symtab,-symtab", mCliOptions.mDumpSymbolTables,
                      "Dump serialized symbol tables");
  // --dump-ir
  mApp.add_flag<bool>("--dump-ir,-ir", mCliOptions.mDumpIR, "Dump LLVM-IR");

  // --jobs
  mApp.add_option<unsigned short>(
      "--jobs,-j", mCliOptions.mCompileJobCount,
      "Compile jobs (threads), used for compilation");

  // Opt levels
  mApp.add_flag_callback(
      "-O0", [&]() { mCliOptions.mOptLevel = O0; },
      "Disable optimization for the output executable.");
  mApp.add_flag_callback(
      "-O1", [&]() { mCliOptions.mOptLevel = O1; },
      "Optimization level 1. Only basic optimization is executed.");
  mApp.add_flag_callback(
      "-O2", [&]() { mCliOptions.mOptLevel = O2; },
      "Optimization level 2. More advanced optimization is applied.");
  mApp.add_flag_callback(
      "-O3", [&]() { mCliOptions.mOptLevel = O3; },
      "Optimization level 3. Aggressive optimization for best performance.");
  mApp.add_flag_callback(
      "-Os", [&]() { mCliOptions.mOptLevel = Os; },
      "Optimization level s. Size optimization for output executable.");
  mApp.add_flag_callback(
      "-Oz", [&]() { mCliOptions.mOptLevel = Oz; },
      "Optimization level z. Aggressive optimization for best size.");
}

/**
 * Start the parsing process
 *
 * @param argc Argument count
 * @param argv Argument vector
 * @return Return code
 */
int CLIInterface::parse(int argc, char **argv) {
  try {
    mApp.parse(argc, argv);
  } catch (const CLI::ParseError &parseError) {
    return mApp.exit(parseError);
  }
  return 0;
}

}  // namespace ts::compiler

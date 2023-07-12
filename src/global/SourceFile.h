/*
 * SourceFile.h
 *
 *  Created on: 2023年7月5日
 *      Author: lxs
 */
#ifndef SRC_SOURCEFILE_H_
#define SRC_SOURCEFILE_H_
#include <memory>
#include <string>
#include <utility>

#include "TypeScriptLexer.h"
#include "TypeScriptParser.h"
#include "cli/CLIInterface.h"
#include "exception/AntlrThrowingErrorListener.h"
#include "utils/CompilerWarning.h"

namespace ts::compiler {
struct SourceFileAntlrCtx {
  // Create error handlers for lexer and parser
  std::unique_ptr<AntlrThrowingErrorListener> lexerErrorHandler;
  std::unique_ptr<AntlrThrowingErrorListener> parserErrorHandler;
  std::unique_ptr<antlr4::ANTLRInputStream> inputStream;
  std::unique_ptr<TypeScriptLexer> lexer;
  std::unique_ptr<antlr4::CommonTokenStream> tokenStream;
  std::unique_ptr<TypeScriptParser> parser;
};

enum CompileStageType : uint8_t {
  NONE,
  LEXER,
  PARSER,
  CST_VISUALIZER,
  AST_BUILDER,
  AST_OPTIMIZER,
  AST_VISUALIZER,
  IMPORT_COLLECTOR,
  SYMBOL_TABLE_BUILDER,
  TYPE_CHECKER_PRE,
  TYPE_CHECKER_POST,
  BORROW_CHECKER,
  ESCAPE_ANALYZER,
  IR_GENERATOR,
  IR_OPTIMIZER,
  OBJECT_EMITTER
};

enum CompileStageIOType {
  IO_CODE,
  IO_TOKENS,
  IO_CST,
  IO_AST,
  IO_IR,
  IO_OBJECT_FILE
};

struct TimerOutput {
  uint64_t lexer = 0;
  uint64_t parser = 0;
  uint64_t cstVisualizer = 0;
  uint64_t astBuilder = 0;
  uint64_t astOptimizer = 0;
  uint64_t astVisualizer = 0;
  uint64_t importCollector = 0;
  uint64_t symbolTableBuilder = 0;
  uint64_t typeCheckerPre = 0;
  uint64_t typeCheckerPost = 0;
  uint64_t borrowChecker = 0;
  uint64_t escapeAnalyzer = 0;
  uint64_t irGenerator = 0;
  uint64_t irOptimizer = 0;
  uint64_t objectEmitter = 0;
  uint64_t executionEngine = 0;
};

struct CompilerOutput {
  std::string cstString;
  std::string astString;
  std::string symbolTableString;
  std::string irString;
  std::string irOptString;
  std::string asmString;
  std::vector<CompilerWarning> warnings;
  TimerOutput times;
};

class SourceFile {
 public:
  explicit SourceFile(const CliOptions &cliOptions);
  SourceFile(const SourceFile &) = delete;

  // Compiler pipeline triggers
  void runLexer();
  void runParser();
  void runCSTVisualizer();

  SourceFileAntlrCtx antlrCtx;
  CompileStageType previousStage = NONE;
  std::string mCacheKey;
  CompilerOutput mCompilerOutput;
  std::string mFilePath;
  std::string mOutputPath;
  bool mPrintDebugOutput = false;
  bool mDumpCST = false;

 private:
  void visualizerPreamble(std::stringstream &output) const;
  void visualizerOutput(std::string outputName,
                        const std::string &output) const;
  void printStatusMessage(const char *stage, const CompileStageIOType &in,
                          const CompileStageIOType &out, uint64_t stageRuntime,
                          bool fromThread = false,
                          unsigned short stageRuns = 0) const;
};
}  // namespace ts::compiler
#endif

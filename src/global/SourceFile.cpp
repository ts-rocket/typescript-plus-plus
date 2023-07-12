/*
 * SourceFile.cpp
 *
 *  Created on: 2023年7月5日
 *      Author: lxs
 */
#include "SourceFile.h"

#include "exception/CompilerError.h"
#include "utils/CommonUtil.h"
#include "utils/FileUtil.h"
#include "utils/Timer.h"
#include "visualizer/CSTVisualizer.h"

namespace ts::compiler {

SourceFile::SourceFile(const CliOptions &cliOptions)
    : mFilePath(cliOptions.mSourceFile),
      mOutputPath(cliOptions.mOutputPath),
      mPrintDebugOutput(cliOptions.mPrintDebugOutput),
      mDumpCST(cliOptions.mDumpCST) {
  if (!mOutputPath.empty()) {
    if (!FileUtil::dirExists(mOutputPath)) {
      FileUtil::createDirs(mOutputPath);
    }
  } else {
    mOutputPath = ".";
  }
}
void SourceFile::runLexer() {
  // Check if this stage has already been done
  if (previousStage >= LEXER) return;

  Timer timer(&mCompilerOutput.times.lexer);
  timer.start();

  // Read from file
  std::ifstream fileInputStream(mFilePath);
  if (!fileInputStream)
    throw CompilerError(
        SOURCE_FILE_NOT_FOUND,
        "Source file at path '" + mFilePath + "' does not exist.");

  // Create error handlers for lexer and parser
  antlrCtx.lexerErrorHandler =
      std::make_unique<AntlrThrowingErrorListener>(MODE_LEXER);
  antlrCtx.parserErrorHandler =
      std::make_unique<AntlrThrowingErrorListener>(MODE_PARSER);

  // Tokenize input
  antlrCtx.inputStream =
      std::make_unique<antlr4::ANTLRInputStream>(fileInputStream);
  antlrCtx.lexer =
      std::make_unique<TypeScriptLexer>(antlrCtx.inputStream.get());
  antlrCtx.lexer->removeErrorListeners();
  antlrCtx.lexer->addErrorListener(antlrCtx.lexerErrorHandler.get());
  antlrCtx.tokenStream =
      std::make_unique<antlr4::CommonTokenStream>(antlrCtx.lexer.get());

  // Calculate cache key
  std::stringstream cacheKeyString;
  cacheKeyString << std::hex
                 << std::hash<std::string>{}(antlrCtx.tokenStream->getText());
  mCacheKey = cacheKeyString.str();

  previousStage = LEXER;
  timer.stop();
  printStatusMessage("Lexer", IO_CODE, IO_TOKENS, mCompilerOutput.times.lexer);
}

void SourceFile::runParser() {
  if (previousStage >= PARSER) return;

  Timer timer(&mCompilerOutput.times.parser);
  timer.start();

  // Parse input
  antlrCtx.parser = std::make_unique<TypeScriptParser>(
      antlrCtx.tokenStream.get());  // Check for syntax errors
  antlrCtx.parser->removeErrorListeners();
  antlrCtx.parser->addErrorListener(antlrCtx.parserErrorHandler.get());
  antlrCtx.parser->removeParseListeners();

  previousStage = PARSER;
  timer.stop();
  printStatusMessage("Parser", IO_TOKENS, IO_CST, mCompilerOutput.times.parser);
}

void SourceFile::runCSTVisualizer() {
  // Only execute if enabled
  if (!mDumpCST) return;

  // Check if this stage has already been done
  if (previousStage >= CST_VISUALIZER) return;

  Timer timer(&mCompilerOutput.times.cstVisualizer);
  timer.start();

  // Generate dot code for this source file
  std::stringstream dotCode;
  visualizerPreamble(dotCode);
  CSTVisualizer cstVisualizer(antlrCtx.lexer.get(), antlrCtx.parser.get());
  dotCode << std::any_cast<std::string>(
                 cstVisualizer.visit(antlrCtx.parser->singleExpression()))
          << "}";
  antlrCtx.parser->reset();

  // If this is the root source file, output the serialized string and the SVG
  // file
  mCompilerOutput.cstString = dotCode.str();
  visualizerOutput("CST", mCompilerOutput.cstString);

  previousStage = CST_VISUALIZER;
  timer.stop();
  printStatusMessage("CST Visualizer", IO_CST, IO_CST,
                     mCompilerOutput.times.cstVisualizer);
}

void SourceFile::visualizerPreamble(std::stringstream &output) const {
  output << "digraph {\n rankdir=\"TB\";\n";
  std::string replacedFilePath = mFilePath;
  CommonUtil::replaceAll(replacedFilePath, "\\", "/");
  output << " label=\"" + replacedFilePath + "\";\n ";
}

void SourceFile::visualizerOutput(std::string outputName,
                                  const std::string &output) const {
  // Dump to console
  std::cout << "\nSerialized " << outputName << ":\n\n" << output << "\n";

  // Check if the dot command exists
  // GCOV_EXCL_START
  if (FileUtil::isCommandAvailable("dot"))
    throw CompilerError(IO_ERROR,
                        "Please check if you have installed 'Graphviz Dot' and "
                        "added it to the PATH variable");
  // GCOV_EXCL_STOP

  // Generate SVG
  std::cout << "\nGenerating SVG file ... ";
  std::transform(outputName.begin(), outputName.end(), outputName.begin(),
                 ::tolower);
  const std::string fileBasePath =
      mOutputPath + FileUtil::DIR_SEPARATOR + FileUtil::getFileName(mFilePath);
  const std::string dotFilePath = fileBasePath + ".dot";
  const std::string svgFilePath = fileBasePath + ".svg";
  FileUtil::writeToFile(dotFilePath, output);
  FileUtil::exec("dot -Tsvg -o" + svgFilePath + " " + dotFilePath);
  std::cout << "done.\nSVG file can be found at: " << svgFilePath << ".svg\n";
}

void SourceFile::printStatusMessage(const char *stage,
                                    const CompileStageIOType &in,
                                    const CompileStageIOType &out,
                                    uint64_t stageRuntime,
                                    bool fromThread /*=false*/,
                                    unsigned short stageRuns /*=0*/) const {
  if (mPrintDebugOutput) {
    const char *const compilerStageIoTypeName[] = {
        "Code", "Tokens", "CST", "AST", "IR", "OBJECT_FILE"};
    // Build output string
    std::stringstream outputStr;
    outputStr << "[" << stage << "] for " << mFilePath << ": ";
    outputStr << compilerStageIoTypeName[in] << " --> "
              << compilerStageIoTypeName[out];
    outputStr << " (" << std::to_string(stageRuntime) << " ms";
    if (stageRuns > 0)
      outputStr << "; " << std::to_string(stageRuns) << " runs";
    outputStr << ")\n";

    // Print
    std::cout << outputStr.str();
  }
}

}  // namespace ts::compiler

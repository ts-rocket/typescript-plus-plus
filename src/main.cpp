/*
 * main.cpp
 *
 *  Created on: 2023年7月5日
 *      Author: lxs
 */
#include "cli/CLIInterface.h"
#include "global/SourceFile.h"

using namespace ts::compiler;

bool compile(CliOptions &cliOptions) {
  SourceFile source(cliOptions);
  source.runLexer();
  source.runParser();
  source.runCSTVisualizer();

  return EXIT_SUCCESS;
}

/**
 * Entry point to the ts compiler
 *
 * @param argc Argument count
 * @param argv Argument vector
 * @return Return code
 */
int main(int argc, char **argv) {
  CLIInterface cli;
  cli.createInterface();
  cli.parse(argc, argv);

  compile(cli.mCliOptions);

  return EXIT_SUCCESS;
}

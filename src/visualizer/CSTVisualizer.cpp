/*
 * CSTVisualizer.cpp
 *
 *  Created on: 2023年7月5日
 *      Author: lxs
 */
#include "CSTVisualizer.h"

#include "utils/CommonUtil.h"

namespace ts::compiler {
std::string CSTVisualizer::buildRule(antlr4::ParserRuleContext *ctx) {
  std::stringstream result;

  // Prepare strings
  std::string codeLoc = tokenToCodeLoc(*ctx->start);
  std::string ruleName = mRuleNames[ctx->getRuleIndex()];
  std::string nodeId = codeLoc + "_" + ruleName;

  // Build result
  result << nodeId << R"( [color="lightgreen",label=")" << ruleName << "\"];\n";

  // Link parent node with the current one
  std::string parentNodeIdBackup = mParentNodeId;
  if (!mParentNodeId.empty())
    result << getSpaces() << mParentNodeId << " -> " << nodeId << ";\n";
  mParentNodeId = nodeId;  // Set parentNodeId for children

  // Visit all the children
  for (const auto &child : ctx->children) {
    result << getSpaces();

    auto token = dynamic_cast<antlr4::tree::TerminalNode *>(child);
    if (token) {  // Terminal node
      std::string terminalCodeLoc = tokenToCodeLoc(*token->getSymbol());
      std::string terminalText = token->getText();
      CommonUtil::replaceAll(terminalText, "\\", "\\\\");
      CommonUtil::replaceAll(terminalText, "\"", "\\\"");
      std::string terminalName = std::string(mVocabulary.getSymbolicName(
                                     token->getSymbol()->getType())) +
                                 ": " + terminalText;

      result << terminalCodeLoc << R"( [color="lightblue",label=")"
             << terminalName << "\"];\n";
      result << getSpaces() << nodeId << " -> " << terminalCodeLoc << "\n";
    } else {  // Non-terminal node
      result << std::any_cast<std::string>(visit(child));
    }
  }

  // Restore parent node id
  mParentNodeId = parentNodeIdBackup;

  return result.str();
}

std::string CSTVisualizer::getSpaces() const {
  std::string spaces;
  for (int i = 0; i < mCurrentTabs; i++) spaces += " ";
  return spaces;
}

std::string CSTVisualizer::tokenToCodeLoc(const antlr4::Token &token) {
  return "L" + std::to_string(token.getLine()) + "C" +
         std::to_string(token.getCharPositionInLine());
}
}  // namespace ts::compiler

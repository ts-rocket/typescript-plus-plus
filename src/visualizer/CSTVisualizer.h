/*
 * CSTVisualizer.h
 *
 *  Created on: 2023年7月5日
 *      Author: lxs
 */

#ifndef SRC_VISUALIZER_CSTVISUALIZER_H_
#define SRC_VISUALIZER_CSTVISUALIZER_H_

#include "TypeScriptLexer.h"
#include "TypeScriptParser.h"
#include "TypeScriptParserVisitor.h"

namespace ts::compiler {

class CSTVisualizer : public TypeScriptParserVisitor {
 public:
  CSTVisualizer(const TypeScriptLexer *lexer, const TypeScriptParser *parser)
      : mVocabulary(lexer->getVocabulary()),
        mRuleNames(parser->getRuleNames()){};

 private:
  // Members
  const antlr4::dfa::Vocabulary &mVocabulary;
  const std::vector<std::string> mRuleNames;
  int mCurrentTabs = 2;
  std::string mParentNodeId;

  // Private methods
  std::string buildRule(antlr4::ParserRuleContext *ctx);
  [[nodiscard]] std::string getSpaces() const;
  [[nodiscard]] static std::string tokenToCodeLoc(const antlr4::Token &token);

 public:
  // Visitor methods
  virtual std::any visitInitializer(
      TypeScriptParser::InitializerContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBindingPattern(
      TypeScriptParser::BindingPatternContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeParameters(
      TypeScriptParser::TypeParametersContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeParameterList(
      TypeScriptParser::TypeParameterListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeParameter(
      TypeScriptParser::TypeParameterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitConstraint(
      TypeScriptParser::ConstraintContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeArguments(
      TypeScriptParser::TypeArgumentsContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeArgumentList(
      TypeScriptParser::TypeArgumentListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeArgument(
      TypeScriptParser::TypeArgumentContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitType_(TypeScriptParser::Type_Context *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIntersection(
      TypeScriptParser::IntersectionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPrimary(
      TypeScriptParser::PrimaryContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitUnion(TypeScriptParser::UnionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitRedefinitionOfType(
      TypeScriptParser::RedefinitionOfTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPredefinedPrimType(
      TypeScriptParser::PredefinedPrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrayPrimType(
      TypeScriptParser::ArrayPrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitParenthesizedPrimType(
      TypeScriptParser::ParenthesizedPrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitThisPrimType(
      TypeScriptParser::ThisPrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTuplePrimType(
      TypeScriptParser::TuplePrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitObjectPrimType(
      TypeScriptParser::ObjectPrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitReferencePrimType(
      TypeScriptParser::ReferencePrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitQueryPrimType(
      TypeScriptParser::QueryPrimTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPredefinedType(
      TypeScriptParser::PredefinedTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeReference(
      TypeScriptParser::TypeReferenceContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitNestedTypeGeneric(
      TypeScriptParser::NestedTypeGenericContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeGeneric(
      TypeScriptParser::TypeGenericContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeIncludeGeneric(
      TypeScriptParser::TypeIncludeGenericContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeName(
      TypeScriptParser::TypeNameContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitObjectType(
      TypeScriptParser::ObjectTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeBody(
      TypeScriptParser::TypeBodyContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeMemberList(
      TypeScriptParser::TypeMemberListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeMember(
      TypeScriptParser::TypeMemberContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrayType(
      TypeScriptParser::ArrayTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTupleType(
      TypeScriptParser::TupleTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTupleElementTypes(
      TypeScriptParser::TupleElementTypesContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFunctionType(
      TypeScriptParser::FunctionTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitConstructorType(
      TypeScriptParser::ConstructorTypeContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeQuery(
      TypeScriptParser::TypeQueryContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeQueryExpression(
      TypeScriptParser::TypeQueryExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertySignatur(
      TypeScriptParser::PropertySignaturContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeAnnotation(
      TypeScriptParser::TypeAnnotationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitCallSignature(
      TypeScriptParser::CallSignatureContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitParameterList(
      TypeScriptParser::ParameterListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitRequiredParameterList(
      TypeScriptParser::RequiredParameterListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitParameter(
      TypeScriptParser::ParameterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitOptionalParameter(
      TypeScriptParser::OptionalParameterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitRestParameter(
      TypeScriptParser::RestParameterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitRequiredParameter(
      TypeScriptParser::RequiredParameterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAccessibilityModifier(
      TypeScriptParser::AccessibilityModifierContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIdentifierOrPattern(
      TypeScriptParser::IdentifierOrPatternContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitConstructSignature(
      TypeScriptParser::ConstructSignatureContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIndexSignature(
      TypeScriptParser::IndexSignatureContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMethodSignature(
      TypeScriptParser::MethodSignatureContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeAliasDeclaration(
      TypeScriptParser::TypeAliasDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitConstructorDeclaration(
      TypeScriptParser::ConstructorDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitInterfaceDeclaration(
      TypeScriptParser::InterfaceDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitInterfaceExtendsClause(
      TypeScriptParser::InterfaceExtendsClauseContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitClassOrInterfaceTypeList(
      TypeScriptParser::ClassOrInterfaceTypeListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEnumDeclaration(
      TypeScriptParser::EnumDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEnumBody(
      TypeScriptParser::EnumBodyContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEnumMemberList(
      TypeScriptParser::EnumMemberListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEnumMember(
      TypeScriptParser::EnumMemberContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitNamespaceDeclaration(
      TypeScriptParser::NamespaceDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitNamespaceName(
      TypeScriptParser::NamespaceNameContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitImportAliasDeclaration(
      TypeScriptParser::ImportAliasDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDecoratorList(
      TypeScriptParser::DecoratorListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDecorator(
      TypeScriptParser::DecoratorContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDecoratorMemberExpression(
      TypeScriptParser::DecoratorMemberExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDecoratorCallExpression(
      TypeScriptParser::DecoratorCallExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitProgram(
      TypeScriptParser::ProgramContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitSourceElement(
      TypeScriptParser::SourceElementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitStatement(
      TypeScriptParser::StatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBlock(TypeScriptParser::BlockContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitStatementList(
      TypeScriptParser::StatementListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAbstractDeclaration(
      TypeScriptParser::AbstractDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitImportStatement(
      TypeScriptParser::ImportStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFromBlock(
      TypeScriptParser::FromBlockContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMultipleImportStatement(
      TypeScriptParser::MultipleImportStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitExportStatement(
      TypeScriptParser::ExportStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitVariableStatement(
      TypeScriptParser::VariableStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitVariableDeclarationList(
      TypeScriptParser::VariableDeclarationListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitVariableDeclaration(
      TypeScriptParser::VariableDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEmptyStatement_(
      TypeScriptParser::EmptyStatement_Context *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitExpressionStatement(
      TypeScriptParser::ExpressionStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIfStatement(
      TypeScriptParser::IfStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDoStatement(
      TypeScriptParser::DoStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitWhileStatement(
      TypeScriptParser::WhileStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitForStatement(
      TypeScriptParser::ForStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitForVarStatement(
      TypeScriptParser::ForVarStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitForInStatement(
      TypeScriptParser::ForInStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitForVarInStatement(
      TypeScriptParser::ForVarInStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitVarModifier(
      TypeScriptParser::VarModifierContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitContinueStatement(
      TypeScriptParser::ContinueStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBreakStatement(
      TypeScriptParser::BreakStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitReturnStatement(
      TypeScriptParser::ReturnStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitYieldStatement(
      TypeScriptParser::YieldStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitWithStatement(
      TypeScriptParser::WithStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitSwitchStatement(
      TypeScriptParser::SwitchStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitCaseBlock(
      TypeScriptParser::CaseBlockContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitCaseClauses(
      TypeScriptParser::CaseClausesContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitCaseClause(
      TypeScriptParser::CaseClauseContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDefaultClause(
      TypeScriptParser::DefaultClauseContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitLabelledStatement(
      TypeScriptParser::LabelledStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitThrowStatement(
      TypeScriptParser::ThrowStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTryStatement(
      TypeScriptParser::TryStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitCatchProduction(
      TypeScriptParser::CatchProductionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFinallyProduction(
      TypeScriptParser::FinallyProductionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDebuggerStatement(
      TypeScriptParser::DebuggerStatementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFunctionDeclaration(
      TypeScriptParser::FunctionDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitClassDeclaration(
      TypeScriptParser::ClassDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitClassHeritage(
      TypeScriptParser::ClassHeritageContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitClassTail(
      TypeScriptParser::ClassTailContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitClassExtendsClause(
      TypeScriptParser::ClassExtendsClauseContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitImplementsClause(
      TypeScriptParser::ImplementsClauseContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitClassElement(
      TypeScriptParser::ClassElementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertyDeclarationExpression(
      TypeScriptParser::PropertyDeclarationExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMethodDeclarationExpression(
      TypeScriptParser::MethodDeclarationExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGetterSetterDeclarationExpression(
      TypeScriptParser::GetterSetterDeclarationExpressionContext *ctx)
      override {
    return buildRule(ctx);
  }

  virtual std::any visitAbstractMemberDeclaration(
      TypeScriptParser::AbstractMemberDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertyMemberBase(
      TypeScriptParser::PropertyMemberBaseContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIndexMemberDeclaration(
      TypeScriptParser::IndexMemberDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGeneratorMethod(
      TypeScriptParser::GeneratorMethodContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGeneratorFunctionDeclaration(
      TypeScriptParser::GeneratorFunctionDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGeneratorBlock(
      TypeScriptParser::GeneratorBlockContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGeneratorDefinition(
      TypeScriptParser::GeneratorDefinitionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIteratorBlock(
      TypeScriptParser::IteratorBlockContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIteratorDefinition(
      TypeScriptParser::IteratorDefinitionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFormalParameterList(
      TypeScriptParser::FormalParameterListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFormalParameterArg(
      TypeScriptParser::FormalParameterArgContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitLastFormalParameterArg(
      TypeScriptParser::LastFormalParameterArgContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFunctionBody(
      TypeScriptParser::FunctionBodyContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitSourceElements(
      TypeScriptParser::SourceElementsContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrayLiteral(
      TypeScriptParser::ArrayLiteralContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitElementList(
      TypeScriptParser::ElementListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrayElement(
      TypeScriptParser::ArrayElementContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitObjectLiteral(
      TypeScriptParser::ObjectLiteralContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertyExpressionAssignment(
      TypeScriptParser::PropertyExpressionAssignmentContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitComputedPropertyExpressionAssignment(
      TypeScriptParser::ComputedPropertyExpressionAssignmentContext *ctx)
      override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertyGetter(
      TypeScriptParser::PropertyGetterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertySetter(
      TypeScriptParser::PropertySetterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMethodProperty(
      TypeScriptParser::MethodPropertyContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertyShorthand(
      TypeScriptParser::PropertyShorthandContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitRestParameterInObject(
      TypeScriptParser::RestParameterInObjectContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGetAccessor(
      TypeScriptParser::GetAccessorContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitSetAccessor(
      TypeScriptParser::SetAccessorContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPropertyName(
      TypeScriptParser::PropertyNameContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArguments(
      TypeScriptParser::ArgumentsContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArgumentList(
      TypeScriptParser::ArgumentListContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArgument(
      TypeScriptParser::ArgumentContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitExpressionSequence(
      TypeScriptParser::ExpressionSequenceContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFunctionExpressionDeclaration(
      TypeScriptParser::FunctionExpressionDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTemplateStringExpression(
      TypeScriptParser::TemplateStringExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTernaryExpression(
      TypeScriptParser::TernaryExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitLogicalAndExpression(
      TypeScriptParser::LogicalAndExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGeneratorsExpression(
      TypeScriptParser::GeneratorsExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPreIncrementExpression(
      TypeScriptParser::PreIncrementExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitObjectLiteralExpression(
      TypeScriptParser::ObjectLiteralExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitInExpression(
      TypeScriptParser::InExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitLogicalOrExpression(
      TypeScriptParser::LogicalOrExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGenericTypes(
      TypeScriptParser::GenericTypesContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitNotExpression(
      TypeScriptParser::NotExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPreDecreaseExpression(
      TypeScriptParser::PreDecreaseExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArgumentsExpression(
      TypeScriptParser::ArgumentsExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitThisExpression(
      TypeScriptParser::ThisExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitFunctionExpression(
      TypeScriptParser::FunctionExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitUnaryMinusExpression(
      TypeScriptParser::UnaryMinusExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAssignmentExpression(
      TypeScriptParser::AssignmentExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPostDecreaseExpression(
      TypeScriptParser::PostDecreaseExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTypeofExpression(
      TypeScriptParser::TypeofExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitInstanceofExpression(
      TypeScriptParser::InstanceofExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitUnaryPlusExpression(
      TypeScriptParser::UnaryPlusExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitDeleteExpression(
      TypeScriptParser::DeleteExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGeneratorsFunctionExpression(
      TypeScriptParser::GeneratorsFunctionExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrowFunctionExpression(
      TypeScriptParser::ArrowFunctionExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIteratorsExpression(
      TypeScriptParser::IteratorsExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEqualityExpression(
      TypeScriptParser::EqualityExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBitXOrExpression(
      TypeScriptParser::BitXOrExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitCastAsExpression(
      TypeScriptParser::CastAsExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitSuperExpression(
      TypeScriptParser::SuperExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMultiplicativeExpression(
      TypeScriptParser::MultiplicativeExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBitShiftExpression(
      TypeScriptParser::BitShiftExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitParenthesizedExpression(
      TypeScriptParser::ParenthesizedExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAdditiveExpression(
      TypeScriptParser::AdditiveExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitRelationalExpression(
      TypeScriptParser::RelationalExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitPostIncrementExpression(
      TypeScriptParser::PostIncrementExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitYieldExpression(
      TypeScriptParser::YieldExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBitNotExpression(
      TypeScriptParser::BitNotExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitNewExpression(
      TypeScriptParser::NewExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitLiteralExpression(
      TypeScriptParser::LiteralExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrayLiteralExpression(
      TypeScriptParser::ArrayLiteralExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMemberDotExpression(
      TypeScriptParser::MemberDotExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitMemberIndexExpression(
      TypeScriptParser::MemberIndexExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIdentifierExpression(
      TypeScriptParser::IdentifierExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBitAndExpression(
      TypeScriptParser::BitAndExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitBitOrExpression(
      TypeScriptParser::BitOrExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAssignmentOperatorExpression(
      TypeScriptParser::AssignmentOperatorExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitVoidExpression(
      TypeScriptParser::VoidExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAsExpression(
      TypeScriptParser::AsExpressionContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrowFunctionDeclaration(
      TypeScriptParser::ArrowFunctionDeclarationContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrowFunctionParameters(
      TypeScriptParser::ArrowFunctionParametersContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitArrowFunctionBody(
      TypeScriptParser::ArrowFunctionBodyContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitAssignmentOperator(
      TypeScriptParser::AssignmentOperatorContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitLiteral(
      TypeScriptParser::LiteralContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTemplateStringLiteral(
      TypeScriptParser::TemplateStringLiteralContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitTemplateStringAtom(
      TypeScriptParser::TemplateStringAtomContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitNumericLiteral(
      TypeScriptParser::NumericLiteralContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIdentifierName(
      TypeScriptParser::IdentifierNameContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitIdentifierOrKeyWord(
      TypeScriptParser::IdentifierOrKeyWordContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitReservedWord(
      TypeScriptParser::ReservedWordContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitKeyword(
      TypeScriptParser::KeywordContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitGetter(TypeScriptParser::GetterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitSetter(TypeScriptParser::SetterContext *ctx) override {
    return buildRule(ctx);
  }

  virtual std::any visitEos(TypeScriptParser::EosContext *ctx) override {
    return buildRule(ctx);
  }
};
}  // namespace ts::compiler
#endif /* SRC_VISUALIZER_CSTVISUALIZER_H_ */

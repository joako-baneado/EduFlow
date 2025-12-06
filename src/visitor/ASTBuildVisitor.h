#pragma once
#include "EduFlowBaseVisitor.h"
#include "EduFlowParser.h"
#include "ast/ASTNodes.h"
#include <memory>
#include <any>

using namespace antlr4;

class ASTBuildVisitor : public EduFlowBaseVisitor {
public:
    std::unique_ptr<Program> rootProgram;

    ASTBuildVisitor() : rootProgram(std::make_unique<Program>()) {}

    virtual std::any visitProgram(EduFlowParser::ProgramContext *ctx) override;
    virtual std::any visitCourseDef(EduFlowParser::CourseDefContext *ctx) override;
    virtual std::any visitRuleDef(EduFlowParser::RuleDefContext *ctx) override;
    virtual std::any visitWorkflowDef(EduFlowParser::WorkflowDefContext *ctx) override;
    
    // Simulación
    virtual std::any visitSimulationDef(EduFlowParser::SimulationDefContext *ctx) override;
    virtual std::any visitStudentDef(EduFlowParser::StudentDefContext *ctx) override;
    
    // Expresiones
    virtual std::any visitExpression(EduFlowParser::ExpressionContext *ctx) override;
    virtual std::any visitTerm(EduFlowParser::TermContext *ctx) override;

    // Auxiliares
    void processCourseCommand(EduFlowParser::CourseCommandContext *ctx, CourseDef* course);
};
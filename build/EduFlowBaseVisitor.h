
// Generated from /mnt/c/Users/User/Documents/GitHub/EduFlow/src/EduFlow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "EduFlowVisitor.h"


namespace antlr4 {

/**
 * This class provides an empty implementation of EduFlowVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  EduFlowBaseVisitor : public EduFlowVisitor {
public:

  virtual std::any visitProgram(EduFlowParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(EduFlowParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefinition(EduFlowParser::DefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExecution(EduFlowParser::ExecutionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCourseDef(EduFlowParser::CourseDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCourseCommand(EduFlowParser::CourseCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRuleDef(EduFlowParser::RuleDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWorkflowDef(EduFlowParser::WorkflowDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStageDef(EduFlowParser::StageDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStageCommand(EduFlowParser::StageCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimulationDef(EduFlowParser::SimulationDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStudentDef(EduFlowParser::StudentDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStudentProperty(EduFlowParser::StudentPropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnrollmentDef(EduFlowParser::EnrollmentDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScheduleBlock(EduFlowParser::ScheduleBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSession(EduFlowParser::SessionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdList(EduFlowParser::IdListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(EduFlowParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(EduFlowParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(EduFlowParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlr4

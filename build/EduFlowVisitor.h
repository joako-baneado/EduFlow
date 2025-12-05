
// Generated from /mnt/c/Users/User/Documents/GitHub/EduFlow/src/EduFlow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "EduFlowParser.h"


namespace antlr4 {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by EduFlowParser.
 */
class  EduFlowVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by EduFlowParser.
   */
    virtual std::any visitProgram(EduFlowParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(EduFlowParser::StatementContext *context) = 0;

    virtual std::any visitDefinition(EduFlowParser::DefinitionContext *context) = 0;

    virtual std::any visitExecution(EduFlowParser::ExecutionContext *context) = 0;

    virtual std::any visitCourseDef(EduFlowParser::CourseDefContext *context) = 0;

    virtual std::any visitCourseCommand(EduFlowParser::CourseCommandContext *context) = 0;

    virtual std::any visitRuleDef(EduFlowParser::RuleDefContext *context) = 0;

    virtual std::any visitWorkflowDef(EduFlowParser::WorkflowDefContext *context) = 0;

    virtual std::any visitStageDef(EduFlowParser::StageDefContext *context) = 0;

    virtual std::any visitStageCommand(EduFlowParser::StageCommandContext *context) = 0;

    virtual std::any visitSimulationDef(EduFlowParser::SimulationDefContext *context) = 0;

    virtual std::any visitStudentDef(EduFlowParser::StudentDefContext *context) = 0;

    virtual std::any visitStudentProperty(EduFlowParser::StudentPropertyContext *context) = 0;

    virtual std::any visitEnrollmentDef(EduFlowParser::EnrollmentDefContext *context) = 0;

    virtual std::any visitScheduleBlock(EduFlowParser::ScheduleBlockContext *context) = 0;

    virtual std::any visitSession(EduFlowParser::SessionContext *context) = 0;

    virtual std::any visitIdList(EduFlowParser::IdListContext *context) = 0;

    virtual std::any visitExpression(EduFlowParser::ExpressionContext *context) = 0;

    virtual std::any visitTerm(EduFlowParser::TermContext *context) = 0;

    virtual std::any visitValue(EduFlowParser::ValueContext *context) = 0;


};

}  // namespace antlr4

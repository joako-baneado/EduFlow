
// Generated from /mnt/c/Users/User/Documents/GitHub/EduFlow/src/EduFlow.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace antlr4 {


class  EduFlowParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, DEFINE = 28, COURSE = 29, RULE = 30, WORKFLOW = 31, SIMULATE = 32, 
    STAGE = 33, SET = 34, WHERE = 35, USING = 36, FOR = 37, STUDENT = 38, 
    ATTEMPT = 39, ENROLL = 40, IN = 41, DAY = 42, LOGICAL_OP = 43, OPERATOR = 44, 
    ID = 45, ATTR_ID = 46, STRING = 47, INT = 48, FLOAT = 49, TIME = 50, 
    WS = 51, COMMENT = 52
  };

  enum {
    RuleProgram = 0, RuleStatement = 1, RuleDefinition = 2, RuleExecution = 3, 
    RuleCourseDef = 4, RuleCourseCommand = 5, RuleRuleDef = 6, RuleWorkflowDef = 7, 
    RuleStageDef = 8, RuleStageCommand = 9, RuleSimulationDef = 10, RuleStudentDef = 11, 
    RuleStudentProperty = 12, RuleEnrollmentDef = 13, RuleScheduleBlock = 14, 
    RuleSession = 15, RuleIdList = 16, RuleExpression = 17, RuleTerm = 18, 
    RuleValue = 19
  };

  explicit EduFlowParser(antlr4::TokenStream *input);

  EduFlowParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~EduFlowParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class StatementContext;
  class DefinitionContext;
  class ExecutionContext;
  class CourseDefContext;
  class CourseCommandContext;
  class RuleDefContext;
  class WorkflowDefContext;
  class StageDefContext;
  class StageCommandContext;
  class SimulationDefContext;
  class StudentDefContext;
  class StudentPropertyContext;
  class EnrollmentDefContext;
  class ScheduleBlockContext;
  class SessionContext;
  class IdListContext;
  class ExpressionContext;
  class TermContext;
  class ValueContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DefinitionContext *definition();
    ExecutionContext *execution();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  DefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CourseDefContext *courseDef();
    RuleDefContext *ruleDef();
    WorkflowDefContext *workflowDef();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionContext* definition();

  class  ExecutionContext : public antlr4::ParserRuleContext {
  public:
    ExecutionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimulationDefContext *simulationDef();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecutionContext* execution();

  class  CourseDefContext : public antlr4::ParserRuleContext {
  public:
    CourseDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFINE();
    antlr4::tree::TerminalNode *COURSE();
    antlr4::tree::TerminalNode *ID();
    std::vector<CourseCommandContext *> courseCommand();
    CourseCommandContext* courseCommand(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CourseDefContext* courseDef();

  class  CourseCommandContext : public antlr4::ParserRuleContext {
  public:
    CourseCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *STRING();
    ExpressionContext *expression();
    ScheduleBlockContext *scheduleBlock();
    antlr4::tree::TerminalNode *ID();
    IdListContext *idList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CourseCommandContext* courseCommand();

  class  RuleDefContext : public antlr4::ParserRuleContext {
  public:
    RuleDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFINE();
    antlr4::tree::TerminalNode *RULE();
    antlr4::tree::TerminalNode *ID();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleDefContext* ruleDef();

  class  WorkflowDefContext : public antlr4::ParserRuleContext {
  public:
    WorkflowDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFINE();
    antlr4::tree::TerminalNode *WORKFLOW();
    antlr4::tree::TerminalNode *ID();
    std::vector<StageDefContext *> stageDef();
    StageDefContext* stageDef(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WorkflowDefContext* workflowDef();

  class  StageDefContext : public antlr4::ParserRuleContext {
  public:
    StageDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAGE();
    antlr4::tree::TerminalNode *STRING();
    std::vector<StageCommandContext *> stageCommand();
    StageCommandContext* stageCommand(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StageDefContext* stageDef();

  class  StageCommandContext : public antlr4::ParserRuleContext {
  public:
    StageCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *WHERE();
    ExpressionContext *expression();
    IdListContext *idList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StageCommandContext* stageCommand();

  class  SimulationDefContext : public antlr4::ParserRuleContext {
  public:
    SimulationDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIMULATE();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *USING();
    antlr4::tree::TerminalNode *ID();
    StudentDefContext *studentDef();
    EnrollmentDefContext *enrollmentDef();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimulationDefContext* simulationDef();

  class  StudentDefContext : public antlr4::ParserRuleContext {
  public:
    StudentDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *STUDENT();
    std::vector<StudentPropertyContext *> studentProperty();
    StudentPropertyContext* studentProperty(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StudentDefContext* studentDef();

  class  StudentPropertyContext : public antlr4::ParserRuleContext {
  public:
    StudentPropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *INT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StudentPropertyContext* studentProperty();

  class  EnrollmentDefContext : public antlr4::ParserRuleContext {
  public:
    EnrollmentDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTEMPT();
    antlr4::tree::TerminalNode *ENROLL();
    antlr4::tree::TerminalNode *IN();
    IdListContext *idList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnrollmentDefContext* enrollmentDef();

  class  ScheduleBlockContext : public antlr4::ParserRuleContext {
  public:
    ScheduleBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SessionContext *> session();
    SessionContext* session(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScheduleBlockContext* scheduleBlock();

  class  SessionContext : public antlr4::ParserRuleContext {
  public:
    SessionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DAY();
    std::vector<antlr4::tree::TerminalNode *> TIME();
    antlr4::tree::TerminalNode* TIME(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionContext* session();

  class  IdListContext : public antlr4::ParserRuleContext {
  public:
    IdListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdListContext* idList();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOGICAL_OP();
    antlr4::tree::TerminalNode* LOGICAL_OP(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ATTR_ID();
    antlr4::tree::TerminalNode *OPERATOR();
    ValueContext *value();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace antlr4

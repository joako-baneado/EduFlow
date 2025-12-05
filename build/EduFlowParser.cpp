
// Generated from /mnt/c/Users/User/Documents/GitHub/EduFlow/src/EduFlow.g4 by ANTLR 4.13.2


#include "EduFlowVisitor.h"

#include "EduFlowParser.h"


using namespace antlrcpp;
using namespace antlr4;

using namespace antlr4;

namespace {

struct EduFlowParserStaticData final {
  EduFlowParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  EduFlowParserStaticData(const EduFlowParserStaticData&) = delete;
  EduFlowParserStaticData(EduFlowParserStaticData&&) = delete;
  EduFlowParserStaticData& operator=(const EduFlowParserStaticData&) = delete;
  EduFlowParserStaticData& operator=(EduFlowParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag eduflowParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<EduFlowParserStaticData> eduflowParserStaticData = nullptr;

void eduflowParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (eduflowParserStaticData != nullptr) {
    return;
  }
#else
  assert(eduflowParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<EduFlowParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "definition", "execution", "courseDef", "courseCommand", 
      "ruleDef", "workflowDef", "stageDef", "stageCommand", "simulationDef", 
      "studentDef", "studentProperty", "enrollmentDef", "scheduleBlock", 
      "session", "idList", "expression", "term", "value"
    },
    std::vector<std::string>{
      "", "'{'", "'}'", "'credits'", "'='", "'capacity'", "'department'", 
      "'level'", "'prerequisites'", "'schedule'", "'eligibility'", "'alternatives'", 
      "';'", "'require'", "'max_credits'", "'allow'", "'courses'", "'enforce'", 
      "'id'", "'major'", "'credits_completed'", "','", "':'", "'-'", "'['", 
      "']'", "'('", "')'", "'define'", "'course'", "'rule'", "'workflow'", 
      "'simulate'", "'stage'", "'set'", "'where'", "'using'", "'for'", "'student'", 
      "'attempt'", "'enroll'", "'in'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "DEFINE", "COURSE", "RULE", 
      "WORKFLOW", "SIMULATE", "STAGE", "SET", "WHERE", "USING", "FOR", "STUDENT", 
      "ATTEMPT", "ENROLL", "IN", "DAY", "LOGICAL_OP", "OPERATOR", "ID", 
      "ATTR_ID", "STRING", "INT", "FLOAT", "TIME", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,52,238,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,4,0,42,8,0,11,
  	0,12,0,43,1,0,1,0,1,1,1,1,3,1,50,8,1,1,2,1,2,1,2,3,2,55,8,2,1,3,1,3,1,
  	4,1,4,1,4,1,4,1,4,5,4,64,8,4,10,4,12,4,67,9,4,1,4,1,4,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,3,5,96,8,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,7,1,7,1,7,1,7,1,7,4,7,114,8,7,11,7,12,7,115,1,7,1,7,1,8,1,8,1,8,1,8,
  	5,8,124,8,8,10,8,12,8,127,9,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,3,9,143,8,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,5,11,160,8,11,10,11,12,11,163,9,11,1,11,
  	1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,177,8,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,5,14,191,
  	8,14,10,14,12,14,194,9,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,16,
  	1,16,1,16,1,16,5,16,208,8,16,10,16,12,16,211,9,16,3,16,213,8,16,1,16,
  	1,16,1,17,1,17,1,17,5,17,220,8,17,10,17,12,17,223,9,17,1,18,1,18,1,18,
  	1,18,1,18,1,18,3,18,231,8,18,1,18,3,18,234,8,18,1,19,1,19,1,19,0,0,20,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,1,1,0,47,49,
  	243,0,41,1,0,0,0,2,49,1,0,0,0,4,54,1,0,0,0,6,56,1,0,0,0,8,58,1,0,0,0,
  	10,70,1,0,0,0,12,99,1,0,0,0,14,108,1,0,0,0,16,119,1,0,0,0,18,130,1,0,
  	0,0,20,146,1,0,0,0,22,155,1,0,0,0,24,166,1,0,0,0,26,180,1,0,0,0,28,186,
  	1,0,0,0,30,197,1,0,0,0,32,203,1,0,0,0,34,216,1,0,0,0,36,233,1,0,0,0,38,
  	235,1,0,0,0,40,42,3,2,1,0,41,40,1,0,0,0,42,43,1,0,0,0,43,41,1,0,0,0,43,
  	44,1,0,0,0,44,45,1,0,0,0,45,46,5,0,0,1,46,1,1,0,0,0,47,50,3,4,2,0,48,
  	50,3,6,3,0,49,47,1,0,0,0,49,48,1,0,0,0,50,3,1,0,0,0,51,55,3,8,4,0,52,
  	55,3,12,6,0,53,55,3,14,7,0,54,51,1,0,0,0,54,52,1,0,0,0,54,53,1,0,0,0,
  	55,5,1,0,0,0,56,57,3,20,10,0,57,7,1,0,0,0,58,59,5,28,0,0,59,60,5,29,0,
  	0,60,61,5,45,0,0,61,65,5,1,0,0,62,64,3,10,5,0,63,62,1,0,0,0,64,67,1,0,
  	0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,68,1,0,0,0,67,65,1,0,0,0,68,69,5,2,
  	0,0,69,9,1,0,0,0,70,95,5,34,0,0,71,72,5,3,0,0,72,73,5,4,0,0,73,96,5,48,
  	0,0,74,75,5,5,0,0,75,76,5,4,0,0,76,96,5,48,0,0,77,78,5,6,0,0,78,79,5,
  	4,0,0,79,96,5,47,0,0,80,81,5,7,0,0,81,82,5,4,0,0,82,96,5,48,0,0,83,84,
  	5,8,0,0,84,85,5,4,0,0,85,96,3,34,17,0,86,87,5,9,0,0,87,88,5,4,0,0,88,
  	96,3,28,14,0,89,90,5,10,0,0,90,91,5,4,0,0,91,96,5,45,0,0,92,93,5,11,0,
  	0,93,94,5,4,0,0,94,96,3,32,16,0,95,71,1,0,0,0,95,74,1,0,0,0,95,77,1,0,
  	0,0,95,80,1,0,0,0,95,83,1,0,0,0,95,86,1,0,0,0,95,89,1,0,0,0,95,92,1,0,
  	0,0,96,97,1,0,0,0,97,98,5,12,0,0,98,11,1,0,0,0,99,100,5,28,0,0,100,101,
  	5,30,0,0,101,102,5,45,0,0,102,103,5,1,0,0,103,104,5,13,0,0,104,105,3,
  	34,17,0,105,106,5,12,0,0,106,107,5,2,0,0,107,13,1,0,0,0,108,109,5,28,
  	0,0,109,110,5,31,0,0,110,111,5,45,0,0,111,113,5,1,0,0,112,114,3,16,8,
  	0,113,112,1,0,0,0,114,115,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,
  	117,1,0,0,0,117,118,5,2,0,0,118,15,1,0,0,0,119,120,5,33,0,0,120,121,5,
  	47,0,0,121,125,5,1,0,0,122,124,3,18,9,0,123,122,1,0,0,0,124,127,1,0,0,
  	0,125,123,1,0,0,0,125,126,1,0,0,0,126,128,1,0,0,0,127,125,1,0,0,0,128,
  	129,5,2,0,0,129,17,1,0,0,0,130,142,5,34,0,0,131,132,5,14,0,0,132,133,
  	5,4,0,0,133,143,5,48,0,0,134,135,5,15,0,0,135,136,5,4,0,0,136,137,5,16,
  	0,0,137,138,5,35,0,0,138,143,3,34,17,0,139,140,5,17,0,0,140,141,5,4,0,
  	0,141,143,3,32,16,0,142,131,1,0,0,0,142,134,1,0,0,0,142,139,1,0,0,0,143,
  	144,1,0,0,0,144,145,5,12,0,0,145,19,1,0,0,0,146,147,5,32,0,0,147,148,
  	5,47,0,0,148,149,5,36,0,0,149,150,5,45,0,0,150,151,5,1,0,0,151,152,3,
  	22,11,0,152,153,3,26,13,0,153,154,5,2,0,0,154,21,1,0,0,0,155,156,5,37,
  	0,0,156,157,5,38,0,0,157,161,5,1,0,0,158,160,3,24,12,0,159,158,1,0,0,
  	0,160,163,1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,164,1,0,0,0,163,
  	161,1,0,0,0,164,165,5,2,0,0,165,23,1,0,0,0,166,176,5,34,0,0,167,168,5,
  	18,0,0,168,169,5,4,0,0,169,177,5,47,0,0,170,171,5,19,0,0,171,172,5,4,
  	0,0,172,177,5,47,0,0,173,174,5,20,0,0,174,175,5,4,0,0,175,177,5,48,0,
  	0,176,167,1,0,0,0,176,170,1,0,0,0,176,173,1,0,0,0,177,178,1,0,0,0,178,
  	179,5,12,0,0,179,25,1,0,0,0,180,181,5,39,0,0,181,182,5,40,0,0,182,183,
  	5,41,0,0,183,184,3,32,16,0,184,185,5,12,0,0,185,27,1,0,0,0,186,187,5,
  	1,0,0,187,192,3,30,15,0,188,189,5,21,0,0,189,191,3,30,15,0,190,188,1,
  	0,0,0,191,194,1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,195,1,0,0,0,
  	194,192,1,0,0,0,195,196,5,2,0,0,196,29,1,0,0,0,197,198,5,42,0,0,198,199,
  	5,22,0,0,199,200,5,50,0,0,200,201,5,23,0,0,201,202,5,50,0,0,202,31,1,
  	0,0,0,203,212,5,24,0,0,204,209,5,45,0,0,205,206,5,21,0,0,206,208,5,45,
  	0,0,207,205,1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,
  	213,1,0,0,0,211,209,1,0,0,0,212,204,1,0,0,0,212,213,1,0,0,0,213,214,1,
  	0,0,0,214,215,5,25,0,0,215,33,1,0,0,0,216,221,3,36,18,0,217,218,5,43,
  	0,0,218,220,3,36,18,0,219,217,1,0,0,0,220,223,1,0,0,0,221,219,1,0,0,0,
  	221,222,1,0,0,0,222,35,1,0,0,0,223,221,1,0,0,0,224,234,5,45,0,0,225,226,
  	5,46,0,0,226,227,5,44,0,0,227,234,3,38,19,0,228,230,5,26,0,0,229,231,
  	3,34,17,0,230,229,1,0,0,0,230,231,1,0,0,0,231,232,1,0,0,0,232,234,5,27,
  	0,0,233,224,1,0,0,0,233,225,1,0,0,0,233,228,1,0,0,0,234,37,1,0,0,0,235,
  	236,7,0,0,0,236,39,1,0,0,0,16,43,49,54,65,95,115,125,142,161,176,192,
  	209,212,221,230,233
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  eduflowParserStaticData = std::move(staticData);
}

}

EduFlowParser::EduFlowParser(TokenStream *input) : EduFlowParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

EduFlowParser::EduFlowParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  EduFlowParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *eduflowParserStaticData->atn, eduflowParserStaticData->decisionToDFA, eduflowParserStaticData->sharedContextCache, options);
}

EduFlowParser::~EduFlowParser() {
  delete _interpreter;
}

const atn::ATN& EduFlowParser::getATN() const {
  return *eduflowParserStaticData->atn;
}

std::string EduFlowParser::getGrammarFileName() const {
  return "EduFlow.g4";
}

const std::vector<std::string>& EduFlowParser::getRuleNames() const {
  return eduflowParserStaticData->ruleNames;
}

const dfa::Vocabulary& EduFlowParser::getVocabulary() const {
  return eduflowParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView EduFlowParser::getSerializedATN() const {
  return eduflowParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

EduFlowParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::ProgramContext::EOF() {
  return getToken(EduFlowParser::EOF, 0);
}

std::vector<EduFlowParser::StatementContext *> EduFlowParser::ProgramContext::statement() {
  return getRuleContexts<EduFlowParser::StatementContext>();
}

EduFlowParser::StatementContext* EduFlowParser::ProgramContext::statement(size_t i) {
  return getRuleContext<EduFlowParser::StatementContext>(i);
}


size_t EduFlowParser::ProgramContext::getRuleIndex() const {
  return EduFlowParser::RuleProgram;
}


std::any EduFlowParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::ProgramContext* EduFlowParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, EduFlowParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(40);
      statement();
      setState(43); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == EduFlowParser::DEFINE

    || _la == EduFlowParser::SIMULATE);
    setState(45);
    match(EduFlowParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

EduFlowParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EduFlowParser::DefinitionContext* EduFlowParser::StatementContext::definition() {
  return getRuleContext<EduFlowParser::DefinitionContext>(0);
}

EduFlowParser::ExecutionContext* EduFlowParser::StatementContext::execution() {
  return getRuleContext<EduFlowParser::ExecutionContext>(0);
}


size_t EduFlowParser::StatementContext::getRuleIndex() const {
  return EduFlowParser::RuleStatement;
}


std::any EduFlowParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::StatementContext* EduFlowParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, EduFlowParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EduFlowParser::DEFINE: {
        enterOuterAlt(_localctx, 1);
        setState(47);
        definition();
        break;
      }

      case EduFlowParser::SIMULATE: {
        enterOuterAlt(_localctx, 2);
        setState(48);
        execution();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

EduFlowParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EduFlowParser::CourseDefContext* EduFlowParser::DefinitionContext::courseDef() {
  return getRuleContext<EduFlowParser::CourseDefContext>(0);
}

EduFlowParser::RuleDefContext* EduFlowParser::DefinitionContext::ruleDef() {
  return getRuleContext<EduFlowParser::RuleDefContext>(0);
}

EduFlowParser::WorkflowDefContext* EduFlowParser::DefinitionContext::workflowDef() {
  return getRuleContext<EduFlowParser::WorkflowDefContext>(0);
}


size_t EduFlowParser::DefinitionContext::getRuleIndex() const {
  return EduFlowParser::RuleDefinition;
}


std::any EduFlowParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::DefinitionContext* EduFlowParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 4, EduFlowParser::RuleDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(51);
      courseDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(52);
      ruleDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(53);
      workflowDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecutionContext ------------------------------------------------------------------

EduFlowParser::ExecutionContext::ExecutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

EduFlowParser::SimulationDefContext* EduFlowParser::ExecutionContext::simulationDef() {
  return getRuleContext<EduFlowParser::SimulationDefContext>(0);
}


size_t EduFlowParser::ExecutionContext::getRuleIndex() const {
  return EduFlowParser::RuleExecution;
}


std::any EduFlowParser::ExecutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitExecution(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::ExecutionContext* EduFlowParser::execution() {
  ExecutionContext *_localctx = _tracker.createInstance<ExecutionContext>(_ctx, getState());
  enterRule(_localctx, 6, EduFlowParser::RuleExecution);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    simulationDef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CourseDefContext ------------------------------------------------------------------

EduFlowParser::CourseDefContext::CourseDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::CourseDefContext::DEFINE() {
  return getToken(EduFlowParser::DEFINE, 0);
}

tree::TerminalNode* EduFlowParser::CourseDefContext::COURSE() {
  return getToken(EduFlowParser::COURSE, 0);
}

tree::TerminalNode* EduFlowParser::CourseDefContext::ID() {
  return getToken(EduFlowParser::ID, 0);
}

std::vector<EduFlowParser::CourseCommandContext *> EduFlowParser::CourseDefContext::courseCommand() {
  return getRuleContexts<EduFlowParser::CourseCommandContext>();
}

EduFlowParser::CourseCommandContext* EduFlowParser::CourseDefContext::courseCommand(size_t i) {
  return getRuleContext<EduFlowParser::CourseCommandContext>(i);
}


size_t EduFlowParser::CourseDefContext::getRuleIndex() const {
  return EduFlowParser::RuleCourseDef;
}


std::any EduFlowParser::CourseDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitCourseDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::CourseDefContext* EduFlowParser::courseDef() {
  CourseDefContext *_localctx = _tracker.createInstance<CourseDefContext>(_ctx, getState());
  enterRule(_localctx, 8, EduFlowParser::RuleCourseDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(EduFlowParser::DEFINE);
    setState(59);
    match(EduFlowParser::COURSE);
    setState(60);
    match(EduFlowParser::ID);
    setState(61);
    match(EduFlowParser::T__0);
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EduFlowParser::SET) {
      setState(62);
      courseCommand();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(68);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CourseCommandContext ------------------------------------------------------------------

EduFlowParser::CourseCommandContext::CourseCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::CourseCommandContext::SET() {
  return getToken(EduFlowParser::SET, 0);
}

tree::TerminalNode* EduFlowParser::CourseCommandContext::INT() {
  return getToken(EduFlowParser::INT, 0);
}

tree::TerminalNode* EduFlowParser::CourseCommandContext::STRING() {
  return getToken(EduFlowParser::STRING, 0);
}

EduFlowParser::ExpressionContext* EduFlowParser::CourseCommandContext::expression() {
  return getRuleContext<EduFlowParser::ExpressionContext>(0);
}

EduFlowParser::ScheduleBlockContext* EduFlowParser::CourseCommandContext::scheduleBlock() {
  return getRuleContext<EduFlowParser::ScheduleBlockContext>(0);
}

tree::TerminalNode* EduFlowParser::CourseCommandContext::ID() {
  return getToken(EduFlowParser::ID, 0);
}

EduFlowParser::IdListContext* EduFlowParser::CourseCommandContext::idList() {
  return getRuleContext<EduFlowParser::IdListContext>(0);
}


size_t EduFlowParser::CourseCommandContext::getRuleIndex() const {
  return EduFlowParser::RuleCourseCommand;
}


std::any EduFlowParser::CourseCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitCourseCommand(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::CourseCommandContext* EduFlowParser::courseCommand() {
  CourseCommandContext *_localctx = _tracker.createInstance<CourseCommandContext>(_ctx, getState());
  enterRule(_localctx, 10, EduFlowParser::RuleCourseCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(EduFlowParser::SET);
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EduFlowParser::T__2: {
        setState(71);
        match(EduFlowParser::T__2);
        setState(72);
        match(EduFlowParser::T__3);
        setState(73);
        match(EduFlowParser::INT);
        break;
      }

      case EduFlowParser::T__4: {
        setState(74);
        match(EduFlowParser::T__4);
        setState(75);
        match(EduFlowParser::T__3);
        setState(76);
        match(EduFlowParser::INT);
        break;
      }

      case EduFlowParser::T__5: {
        setState(77);
        match(EduFlowParser::T__5);
        setState(78);
        match(EduFlowParser::T__3);
        setState(79);
        match(EduFlowParser::STRING);
        break;
      }

      case EduFlowParser::T__6: {
        setState(80);
        match(EduFlowParser::T__6);
        setState(81);
        match(EduFlowParser::T__3);
        setState(82);
        match(EduFlowParser::INT);
        break;
      }

      case EduFlowParser::T__7: {
        setState(83);
        match(EduFlowParser::T__7);
        setState(84);
        match(EduFlowParser::T__3);
        setState(85);
        expression();
        break;
      }

      case EduFlowParser::T__8: {
        setState(86);
        match(EduFlowParser::T__8);
        setState(87);
        match(EduFlowParser::T__3);
        setState(88);
        scheduleBlock();
        break;
      }

      case EduFlowParser::T__9: {
        setState(89);
        match(EduFlowParser::T__9);
        setState(90);
        match(EduFlowParser::T__3);
        setState(91);
        match(EduFlowParser::ID);
        break;
      }

      case EduFlowParser::T__10: {
        setState(92);
        match(EduFlowParser::T__10);
        setState(93);
        match(EduFlowParser::T__3);
        setState(94);
        idList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(97);
    match(EduFlowParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleDefContext ------------------------------------------------------------------

EduFlowParser::RuleDefContext::RuleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::RuleDefContext::DEFINE() {
  return getToken(EduFlowParser::DEFINE, 0);
}

tree::TerminalNode* EduFlowParser::RuleDefContext::RULE() {
  return getToken(EduFlowParser::RULE, 0);
}

tree::TerminalNode* EduFlowParser::RuleDefContext::ID() {
  return getToken(EduFlowParser::ID, 0);
}

EduFlowParser::ExpressionContext* EduFlowParser::RuleDefContext::expression() {
  return getRuleContext<EduFlowParser::ExpressionContext>(0);
}


size_t EduFlowParser::RuleDefContext::getRuleIndex() const {
  return EduFlowParser::RuleRuleDef;
}


std::any EduFlowParser::RuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitRuleDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::RuleDefContext* EduFlowParser::ruleDef() {
  RuleDefContext *_localctx = _tracker.createInstance<RuleDefContext>(_ctx, getState());
  enterRule(_localctx, 12, EduFlowParser::RuleRuleDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(EduFlowParser::DEFINE);
    setState(100);
    match(EduFlowParser::RULE);
    setState(101);
    match(EduFlowParser::ID);
    setState(102);
    match(EduFlowParser::T__0);
    setState(103);
    match(EduFlowParser::T__12);
    setState(104);
    expression();
    setState(105);
    match(EduFlowParser::T__11);
    setState(106);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WorkflowDefContext ------------------------------------------------------------------

EduFlowParser::WorkflowDefContext::WorkflowDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::WorkflowDefContext::DEFINE() {
  return getToken(EduFlowParser::DEFINE, 0);
}

tree::TerminalNode* EduFlowParser::WorkflowDefContext::WORKFLOW() {
  return getToken(EduFlowParser::WORKFLOW, 0);
}

tree::TerminalNode* EduFlowParser::WorkflowDefContext::ID() {
  return getToken(EduFlowParser::ID, 0);
}

std::vector<EduFlowParser::StageDefContext *> EduFlowParser::WorkflowDefContext::stageDef() {
  return getRuleContexts<EduFlowParser::StageDefContext>();
}

EduFlowParser::StageDefContext* EduFlowParser::WorkflowDefContext::stageDef(size_t i) {
  return getRuleContext<EduFlowParser::StageDefContext>(i);
}


size_t EduFlowParser::WorkflowDefContext::getRuleIndex() const {
  return EduFlowParser::RuleWorkflowDef;
}


std::any EduFlowParser::WorkflowDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitWorkflowDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::WorkflowDefContext* EduFlowParser::workflowDef() {
  WorkflowDefContext *_localctx = _tracker.createInstance<WorkflowDefContext>(_ctx, getState());
  enterRule(_localctx, 14, EduFlowParser::RuleWorkflowDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(EduFlowParser::DEFINE);
    setState(109);
    match(EduFlowParser::WORKFLOW);
    setState(110);
    match(EduFlowParser::ID);
    setState(111);
    match(EduFlowParser::T__0);
    setState(113); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(112);
      stageDef();
      setState(115); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == EduFlowParser::STAGE);
    setState(117);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StageDefContext ------------------------------------------------------------------

EduFlowParser::StageDefContext::StageDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::StageDefContext::STAGE() {
  return getToken(EduFlowParser::STAGE, 0);
}

tree::TerminalNode* EduFlowParser::StageDefContext::STRING() {
  return getToken(EduFlowParser::STRING, 0);
}

std::vector<EduFlowParser::StageCommandContext *> EduFlowParser::StageDefContext::stageCommand() {
  return getRuleContexts<EduFlowParser::StageCommandContext>();
}

EduFlowParser::StageCommandContext* EduFlowParser::StageDefContext::stageCommand(size_t i) {
  return getRuleContext<EduFlowParser::StageCommandContext>(i);
}


size_t EduFlowParser::StageDefContext::getRuleIndex() const {
  return EduFlowParser::RuleStageDef;
}


std::any EduFlowParser::StageDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitStageDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::StageDefContext* EduFlowParser::stageDef() {
  StageDefContext *_localctx = _tracker.createInstance<StageDefContext>(_ctx, getState());
  enterRule(_localctx, 16, EduFlowParser::RuleStageDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(EduFlowParser::STAGE);
    setState(120);
    match(EduFlowParser::STRING);
    setState(121);
    match(EduFlowParser::T__0);
    setState(125);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EduFlowParser::SET) {
      setState(122);
      stageCommand();
      setState(127);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(128);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StageCommandContext ------------------------------------------------------------------

EduFlowParser::StageCommandContext::StageCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::StageCommandContext::SET() {
  return getToken(EduFlowParser::SET, 0);
}

tree::TerminalNode* EduFlowParser::StageCommandContext::INT() {
  return getToken(EduFlowParser::INT, 0);
}

tree::TerminalNode* EduFlowParser::StageCommandContext::WHERE() {
  return getToken(EduFlowParser::WHERE, 0);
}

EduFlowParser::ExpressionContext* EduFlowParser::StageCommandContext::expression() {
  return getRuleContext<EduFlowParser::ExpressionContext>(0);
}

EduFlowParser::IdListContext* EduFlowParser::StageCommandContext::idList() {
  return getRuleContext<EduFlowParser::IdListContext>(0);
}


size_t EduFlowParser::StageCommandContext::getRuleIndex() const {
  return EduFlowParser::RuleStageCommand;
}


std::any EduFlowParser::StageCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitStageCommand(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::StageCommandContext* EduFlowParser::stageCommand() {
  StageCommandContext *_localctx = _tracker.createInstance<StageCommandContext>(_ctx, getState());
  enterRule(_localctx, 18, EduFlowParser::RuleStageCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(EduFlowParser::SET);
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EduFlowParser::T__13: {
        setState(131);
        match(EduFlowParser::T__13);
        setState(132);
        match(EduFlowParser::T__3);
        setState(133);
        match(EduFlowParser::INT);
        break;
      }

      case EduFlowParser::T__14: {
        setState(134);
        match(EduFlowParser::T__14);
        setState(135);
        match(EduFlowParser::T__3);
        setState(136);
        match(EduFlowParser::T__15);
        setState(137);
        match(EduFlowParser::WHERE);
        setState(138);
        expression();
        break;
      }

      case EduFlowParser::T__16: {
        setState(139);
        match(EduFlowParser::T__16);
        setState(140);
        match(EduFlowParser::T__3);
        setState(141);
        idList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(144);
    match(EduFlowParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimulationDefContext ------------------------------------------------------------------

EduFlowParser::SimulationDefContext::SimulationDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::SimulationDefContext::SIMULATE() {
  return getToken(EduFlowParser::SIMULATE, 0);
}

tree::TerminalNode* EduFlowParser::SimulationDefContext::STRING() {
  return getToken(EduFlowParser::STRING, 0);
}

tree::TerminalNode* EduFlowParser::SimulationDefContext::USING() {
  return getToken(EduFlowParser::USING, 0);
}

tree::TerminalNode* EduFlowParser::SimulationDefContext::ID() {
  return getToken(EduFlowParser::ID, 0);
}

EduFlowParser::StudentDefContext* EduFlowParser::SimulationDefContext::studentDef() {
  return getRuleContext<EduFlowParser::StudentDefContext>(0);
}

EduFlowParser::EnrollmentDefContext* EduFlowParser::SimulationDefContext::enrollmentDef() {
  return getRuleContext<EduFlowParser::EnrollmentDefContext>(0);
}


size_t EduFlowParser::SimulationDefContext::getRuleIndex() const {
  return EduFlowParser::RuleSimulationDef;
}


std::any EduFlowParser::SimulationDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitSimulationDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::SimulationDefContext* EduFlowParser::simulationDef() {
  SimulationDefContext *_localctx = _tracker.createInstance<SimulationDefContext>(_ctx, getState());
  enterRule(_localctx, 20, EduFlowParser::RuleSimulationDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(EduFlowParser::SIMULATE);
    setState(147);
    match(EduFlowParser::STRING);
    setState(148);
    match(EduFlowParser::USING);
    setState(149);
    match(EduFlowParser::ID);
    setState(150);
    match(EduFlowParser::T__0);
    setState(151);
    studentDef();
    setState(152);
    enrollmentDef();
    setState(153);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StudentDefContext ------------------------------------------------------------------

EduFlowParser::StudentDefContext::StudentDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::StudentDefContext::FOR() {
  return getToken(EduFlowParser::FOR, 0);
}

tree::TerminalNode* EduFlowParser::StudentDefContext::STUDENT() {
  return getToken(EduFlowParser::STUDENT, 0);
}

std::vector<EduFlowParser::StudentPropertyContext *> EduFlowParser::StudentDefContext::studentProperty() {
  return getRuleContexts<EduFlowParser::StudentPropertyContext>();
}

EduFlowParser::StudentPropertyContext* EduFlowParser::StudentDefContext::studentProperty(size_t i) {
  return getRuleContext<EduFlowParser::StudentPropertyContext>(i);
}


size_t EduFlowParser::StudentDefContext::getRuleIndex() const {
  return EduFlowParser::RuleStudentDef;
}


std::any EduFlowParser::StudentDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitStudentDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::StudentDefContext* EduFlowParser::studentDef() {
  StudentDefContext *_localctx = _tracker.createInstance<StudentDefContext>(_ctx, getState());
  enterRule(_localctx, 22, EduFlowParser::RuleStudentDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(EduFlowParser::FOR);
    setState(156);
    match(EduFlowParser::STUDENT);
    setState(157);
    match(EduFlowParser::T__0);
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EduFlowParser::SET) {
      setState(158);
      studentProperty();
      setState(163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(164);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StudentPropertyContext ------------------------------------------------------------------

EduFlowParser::StudentPropertyContext::StudentPropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::StudentPropertyContext::SET() {
  return getToken(EduFlowParser::SET, 0);
}

tree::TerminalNode* EduFlowParser::StudentPropertyContext::STRING() {
  return getToken(EduFlowParser::STRING, 0);
}

tree::TerminalNode* EduFlowParser::StudentPropertyContext::INT() {
  return getToken(EduFlowParser::INT, 0);
}


size_t EduFlowParser::StudentPropertyContext::getRuleIndex() const {
  return EduFlowParser::RuleStudentProperty;
}


std::any EduFlowParser::StudentPropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitStudentProperty(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::StudentPropertyContext* EduFlowParser::studentProperty() {
  StudentPropertyContext *_localctx = _tracker.createInstance<StudentPropertyContext>(_ctx, getState());
  enterRule(_localctx, 24, EduFlowParser::RuleStudentProperty);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(EduFlowParser::SET);
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EduFlowParser::T__17: {
        setState(167);
        match(EduFlowParser::T__17);
        setState(168);
        match(EduFlowParser::T__3);
        setState(169);
        match(EduFlowParser::STRING);
        break;
      }

      case EduFlowParser::T__18: {
        setState(170);
        match(EduFlowParser::T__18);
        setState(171);
        match(EduFlowParser::T__3);
        setState(172);
        match(EduFlowParser::STRING);
        break;
      }

      case EduFlowParser::T__19: {
        setState(173);
        match(EduFlowParser::T__19);
        setState(174);
        match(EduFlowParser::T__3);
        setState(175);
        match(EduFlowParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(178);
    match(EduFlowParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnrollmentDefContext ------------------------------------------------------------------

EduFlowParser::EnrollmentDefContext::EnrollmentDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::EnrollmentDefContext::ATTEMPT() {
  return getToken(EduFlowParser::ATTEMPT, 0);
}

tree::TerminalNode* EduFlowParser::EnrollmentDefContext::ENROLL() {
  return getToken(EduFlowParser::ENROLL, 0);
}

tree::TerminalNode* EduFlowParser::EnrollmentDefContext::IN() {
  return getToken(EduFlowParser::IN, 0);
}

EduFlowParser::IdListContext* EduFlowParser::EnrollmentDefContext::idList() {
  return getRuleContext<EduFlowParser::IdListContext>(0);
}


size_t EduFlowParser::EnrollmentDefContext::getRuleIndex() const {
  return EduFlowParser::RuleEnrollmentDef;
}


std::any EduFlowParser::EnrollmentDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitEnrollmentDef(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::EnrollmentDefContext* EduFlowParser::enrollmentDef() {
  EnrollmentDefContext *_localctx = _tracker.createInstance<EnrollmentDefContext>(_ctx, getState());
  enterRule(_localctx, 26, EduFlowParser::RuleEnrollmentDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(EduFlowParser::ATTEMPT);
    setState(181);
    match(EduFlowParser::ENROLL);
    setState(182);
    match(EduFlowParser::IN);
    setState(183);
    idList();
    setState(184);
    match(EduFlowParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScheduleBlockContext ------------------------------------------------------------------

EduFlowParser::ScheduleBlockContext::ScheduleBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EduFlowParser::SessionContext *> EduFlowParser::ScheduleBlockContext::session() {
  return getRuleContexts<EduFlowParser::SessionContext>();
}

EduFlowParser::SessionContext* EduFlowParser::ScheduleBlockContext::session(size_t i) {
  return getRuleContext<EduFlowParser::SessionContext>(i);
}


size_t EduFlowParser::ScheduleBlockContext::getRuleIndex() const {
  return EduFlowParser::RuleScheduleBlock;
}


std::any EduFlowParser::ScheduleBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitScheduleBlock(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::ScheduleBlockContext* EduFlowParser::scheduleBlock() {
  ScheduleBlockContext *_localctx = _tracker.createInstance<ScheduleBlockContext>(_ctx, getState());
  enterRule(_localctx, 28, EduFlowParser::RuleScheduleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(EduFlowParser::T__0);
    setState(187);
    session();
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EduFlowParser::T__20) {
      setState(188);
      match(EduFlowParser::T__20);
      setState(189);
      session();
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(195);
    match(EduFlowParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SessionContext ------------------------------------------------------------------

EduFlowParser::SessionContext::SessionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::SessionContext::DAY() {
  return getToken(EduFlowParser::DAY, 0);
}

std::vector<tree::TerminalNode *> EduFlowParser::SessionContext::TIME() {
  return getTokens(EduFlowParser::TIME);
}

tree::TerminalNode* EduFlowParser::SessionContext::TIME(size_t i) {
  return getToken(EduFlowParser::TIME, i);
}


size_t EduFlowParser::SessionContext::getRuleIndex() const {
  return EduFlowParser::RuleSession;
}


std::any EduFlowParser::SessionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitSession(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::SessionContext* EduFlowParser::session() {
  SessionContext *_localctx = _tracker.createInstance<SessionContext>(_ctx, getState());
  enterRule(_localctx, 30, EduFlowParser::RuleSession);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(EduFlowParser::DAY);
    setState(198);
    match(EduFlowParser::T__21);
    setState(199);
    match(EduFlowParser::TIME);
    setState(200);
    match(EduFlowParser::T__22);
    setState(201);
    match(EduFlowParser::TIME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdListContext ------------------------------------------------------------------

EduFlowParser::IdListContext::IdListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> EduFlowParser::IdListContext::ID() {
  return getTokens(EduFlowParser::ID);
}

tree::TerminalNode* EduFlowParser::IdListContext::ID(size_t i) {
  return getToken(EduFlowParser::ID, i);
}


size_t EduFlowParser::IdListContext::getRuleIndex() const {
  return EduFlowParser::RuleIdList;
}


std::any EduFlowParser::IdListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitIdList(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::IdListContext* EduFlowParser::idList() {
  IdListContext *_localctx = _tracker.createInstance<IdListContext>(_ctx, getState());
  enterRule(_localctx, 32, EduFlowParser::RuleIdList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(EduFlowParser::T__23);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == EduFlowParser::ID) {
      setState(204);
      match(EduFlowParser::ID);
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == EduFlowParser::T__20) {
        setState(205);
        match(EduFlowParser::T__20);
        setState(206);
        match(EduFlowParser::ID);
        setState(211);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(214);
    match(EduFlowParser::T__24);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

EduFlowParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<EduFlowParser::TermContext *> EduFlowParser::ExpressionContext::term() {
  return getRuleContexts<EduFlowParser::TermContext>();
}

EduFlowParser::TermContext* EduFlowParser::ExpressionContext::term(size_t i) {
  return getRuleContext<EduFlowParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> EduFlowParser::ExpressionContext::LOGICAL_OP() {
  return getTokens(EduFlowParser::LOGICAL_OP);
}

tree::TerminalNode* EduFlowParser::ExpressionContext::LOGICAL_OP(size_t i) {
  return getToken(EduFlowParser::LOGICAL_OP, i);
}


size_t EduFlowParser::ExpressionContext::getRuleIndex() const {
  return EduFlowParser::RuleExpression;
}


std::any EduFlowParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::ExpressionContext* EduFlowParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, EduFlowParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    term();
    setState(221);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == EduFlowParser::LOGICAL_OP) {
      setState(217);
      match(EduFlowParser::LOGICAL_OP);
      setState(218);
      term();
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

EduFlowParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::TermContext::ID() {
  return getToken(EduFlowParser::ID, 0);
}

tree::TerminalNode* EduFlowParser::TermContext::ATTR_ID() {
  return getToken(EduFlowParser::ATTR_ID, 0);
}

tree::TerminalNode* EduFlowParser::TermContext::OPERATOR() {
  return getToken(EduFlowParser::OPERATOR, 0);
}

EduFlowParser::ValueContext* EduFlowParser::TermContext::value() {
  return getRuleContext<EduFlowParser::ValueContext>(0);
}

EduFlowParser::ExpressionContext* EduFlowParser::TermContext::expression() {
  return getRuleContext<EduFlowParser::ExpressionContext>(0);
}


size_t EduFlowParser::TermContext::getRuleIndex() const {
  return EduFlowParser::RuleTerm;
}


std::any EduFlowParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::TermContext* EduFlowParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 36, EduFlowParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(233);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case EduFlowParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        match(EduFlowParser::ID);
        break;
      }

      case EduFlowParser::ATTR_ID: {
        enterOuterAlt(_localctx, 2);
        setState(225);
        match(EduFlowParser::ATTR_ID);
        setState(226);
        match(EduFlowParser::OPERATOR);
        setState(227);
        value();
        break;
      }

      case EduFlowParser::T__25: {
        enterOuterAlt(_localctx, 3);
        setState(228);
        match(EduFlowParser::T__25);
        setState(230);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 105553183375360) != 0)) {
          setState(229);
          expression();
        }
        setState(232);
        match(EduFlowParser::T__26);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

EduFlowParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* EduFlowParser::ValueContext::STRING() {
  return getToken(EduFlowParser::STRING, 0);
}

tree::TerminalNode* EduFlowParser::ValueContext::INT() {
  return getToken(EduFlowParser::INT, 0);
}

tree::TerminalNode* EduFlowParser::ValueContext::FLOAT() {
  return getToken(EduFlowParser::FLOAT, 0);
}


size_t EduFlowParser::ValueContext::getRuleIndex() const {
  return EduFlowParser::RuleValue;
}


std::any EduFlowParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<EduFlowVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

EduFlowParser::ValueContext* EduFlowParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 38, EduFlowParser::RuleValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 985162418487296) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void EduFlowParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  eduflowParserInitialize();
#else
  ::antlr4::internal::call_once(eduflowParserOnceFlag, eduflowParserInitialize);
#endif
}

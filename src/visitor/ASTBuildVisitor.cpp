#include "ASTBuildVisitor.h"
using namespace antlr4;

std::any ASTBuildVisitor::visitProgram(EduFlowParser::ProgramContext *ctx) {
    for (auto stmt : ctx->statement()) visit(stmt); return 0;
}

std::any ASTBuildVisitor::visitCourseDef(EduFlowParser::CourseDefContext *ctx) {
    auto course = std::make_unique<CourseDef>();
    course->id = ctx->ID()->getText();
    for (auto cmd : ctx->courseCommand()) processCourseCommand(cmd, course.get());
    rootProgram->courses.push_back(std::move(course));
    return 0;
}

void ASTBuildVisitor::processCourseCommand(EduFlowParser::CourseCommandContext *ctx, CourseDef* course) {
    std::string text = ctx->getText();
    if (text.find("credits=") != std::string::npos && ctx->INT()) course->credits = std::stoi(ctx->INT()->getText());
    else if (text.find("level=") != std::string::npos && ctx->INT()) course->level = std::stoi(ctx->INT()->getText());
    else if (text.find("eligibility=") != std::string::npos && ctx->ID()) course->eligibilityRule = ctx->ID()->getText();
}

std::any ASTBuildVisitor::visitRuleDef(EduFlowParser::RuleDefContext *ctx) {
    auto rule = std::make_unique<RuleDef>();
    rule->id = ctx->ID()->getText();
    if (ctx->expression()) {
        std::any exprResult = visit(ctx->expression());
        if (exprResult.has_value()) rule->condition = std::unique_ptr<ExprNode>(std::any_cast<ExprNode*>(exprResult));
    }
    rootProgram->rules.push_back(std::move(rule));
    return 0;
}

// --- WORKFLOWS Y STAGES ---
std::any ASTBuildVisitor::visitWorkflowDef(EduFlowParser::WorkflowDefContext *ctx) {
    auto wf = std::make_unique<WorkflowDef>();
    wf->id = ctx->ID()->getText();
    
    // Visitamos los Stages
    for (auto stageCtx : ctx->stageDef()) {
        auto stage = std::make_unique<StageDef>();
        stage->name = stageCtx->STRING()->getText();
        
        // Procesar comandos del stage (max_credits)
        for (auto cmd : stageCtx->stageCommand()) {
            std::string text = cmd->getText();
            if (text.find("max_credits=") != std::string::npos && cmd->INT()) {
                stage->max_credits = std::stoi(cmd->INT()->getText());
            }
        }
        wf->stages.push_back(std::move(stage));
    }
    
    rootProgram->workflows.push_back(std::move(wf));
    return 0;
}

std::any ASTBuildVisitor::visitSimulationDef(EduFlowParser::SimulationDefContext *ctx) {
    auto sim = std::make_unique<SimulationDef>();
    sim->name = ctx->STRING()->getText();
    
    // Capturamos el ID del Workflow ("using MATRICULA...")
    if (ctx->ID()) {
        sim->workflowId = ctx->ID()->getText();
    }

    if (ctx->studentDef()) {
        std::any stResult = visit(ctx->studentDef());
        sim->student = std::unique_ptr<StudentDef>(std::any_cast<StudentDef*>(stResult));
    }

    if (ctx->enrollmentDef() && ctx->enrollmentDef()->idList()) {
        for (auto idToken : ctx->enrollmentDef()->idList()->ID()) {
            sim->coursesToEnroll.push_back(idToken->getText());
        }
    }
    rootProgram->simulations.push_back(std::move(sim));
    return 0;
}

std::any ASTBuildVisitor::visitStudentDef(EduFlowParser::StudentDefContext *ctx) {
    auto student = std::make_unique<StudentDef>();
    for (auto prop : ctx->studentProperty()) {
        std::string text = prop->getText();
        if (text.find("id=") != std::string::npos && prop->STRING()) student->id = prop->STRING()->getText();
        else if (text.find("credits_completed=") != std::string::npos && prop->INT()) student->credits_completed = std::stoi(prop->INT()->getText());
    }
    return student.release();
}

std::any ASTBuildVisitor::visitExpression(EduFlowParser::ExpressionContext *ctx) { return visit(ctx->term(0)); }

std::any ASTBuildVisitor::visitTerm(EduFlowParser::TermContext *ctx) {
    if (ctx->ATTR_ID() && ctx->OPERATOR() && ctx->value()) {
        std::string attr = ctx->ATTR_ID()->getText();
        std::string op = ctx->OPERATOR()->getText();
        std::string valStr = ctx->value()->getText();
        size_t dotPos = attr.find('.');
        auto left = std::make_unique<VariableAccess>(attr.substr(0, dotPos), attr.substr(dotPos + 1));
        auto right = std::make_unique<IntLiteral>(std::stoi(valStr));
        auto bin = std::make_unique<BinaryOp>(op, std::move(left), std::move(right));
        return (ExprNode*)bin.release();
    }
    return (ExprNode*)nullptr;
}
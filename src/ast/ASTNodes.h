#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

struct ExprNode : public ASTNode {
    virtual ~ExprNode() = default;
};

struct IntLiteral : public ExprNode {
    int value;
    IntLiteral(int v) : value(v) {}
    void print(int indent = 0) const override { std::cout << std::string(indent, ' ') << "Int: " << value << "\n"; }
};

struct VariableAccess : public ExprNode {
    std::string structName, fieldName;
    VariableAccess(std::string s, std::string f) : structName(s), fieldName(f) {}
    void print(int indent = 0) const override { std::cout << std::string(indent, ' ') << "Var: " << structName << "." << fieldName << "\n"; }
};

struct BinaryOp : public ExprNode {
    std::string op;
    std::unique_ptr<ExprNode> left, right;
    BinaryOp(std::string o, std::unique_ptr<ExprNode> l, std::unique_ptr<ExprNode> r) : op(o), left(std::move(l)), right(std::move(r)) {}
    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Op: " << op << "\n";
        left->print(indent + 2); right->print(indent + 2);
    }
};

struct CourseDef : public ASTNode {
    std::string id;
    int credits = 0, level = 0;
    std::string eligibilityRule;
    void print(int indent = 0) const override {
        std::string pad(indent, ' ');
        std::cout << pad << "Course: " << id << " (" << credits << " cr)\n";
    }
};

struct RuleDef : public ASTNode {
    std::string id;
    std::unique_ptr<ExprNode> condition;
    void print(int indent = 0) const override {
        std::string pad(indent, ' ');
        std::cout << pad << "Rule: " << id << "\n";
        if (condition) condition->print(indent + 2);
    }
};

// --- NUEVO: Estructura de Stages ---
struct StageDef : public ASTNode {
    std::string name;
    int max_credits = 999;
    void print(int indent = 0) const override {
        std::string pad(indent, ' ');
        std::cout << pad << "Stage: " << name << " (Max Credits: " << max_credits << ")\n";
    }
};

struct WorkflowDef : public ASTNode {
    std::string id;
    std::vector<std::unique_ptr<StageDef>> stages;

    void print(int indent = 0) const override {
        std::string pad(indent, ' ');
        std::cout << pad << "Workflow: " << id << "\n";
        for(const auto& s : stages) s->print(indent + 2);
    }
};

struct StudentDef : public ASTNode {
    std::string id;
    int credits_completed = 0;
    void print(int indent = 0) const override { std::cout << std::string(indent, ' ') << "Student: " << id << "\n"; }
};

struct SimulationDef : public ASTNode {
    std::string name;
    std::string workflowId; // <--- NUEVO: ID del workflow a usar
    std::unique_ptr<StudentDef> student;
    std::vector<std::string> coursesToEnroll;

    void print(int indent = 0) const override {
        std::string pad(indent, ' ');
        std::cout << pad << "Simulacion: " << name << " using " << workflowId << "\n";
        if(student) student->print(indent + 2);
    }
};

struct Program : public ASTNode {
    std::vector<std::unique_ptr<CourseDef>> courses;
    std::vector<std::unique_ptr<RuleDef>> rules;
    std::vector<std::unique_ptr<WorkflowDef>> workflows;
    std::vector<std::unique_ptr<SimulationDef>> simulations;

    const CourseDef* findCourse(const std::string& id) const {
        auto it = std::find_if(courses.begin(), courses.end(), [&](const auto& c){ return c->id == id; });
        return (it != courses.end()) ? it->get() : nullptr;
    }

    // Helper para buscar workflow
    const WorkflowDef* findWorkflow(const std::string& id) const {
        auto it = std::find_if(workflows.begin(), workflows.end(), [&](const auto& w){ return w->id == id; });
        return (it != workflows.end()) ? it->get() : nullptr;
    }

    void print(int indent = 0) const override {
        std::cout << "--- EduFlow AST ---\n";
        for (const auto& c : courses) c->print(indent + 2);
        for (const auto& w : workflows) w->print(indent + 2);
        for (const auto& s : simulations) s->print(indent + 2);
    }
};
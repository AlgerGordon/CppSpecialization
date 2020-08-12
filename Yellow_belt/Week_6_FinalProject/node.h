//
// Created by General on 11.08.2020.
//


#pragma once

#include "date.h"
#include "token.h"

#include <memory>
#include <string>

using namespace std;

class Node{
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date)
            : cmp_(cmp), date_(date) {};
    bool Evaluate(const Date& date, const string& event) const override;

private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const string& event)
            : cmp_(cmp), event_(event) {};
    bool Evaluate(const Date& date, const string& event) const override;

private:
    Comparison cmp_;
    const string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation op, shared_ptr<Node> left,
                         shared_ptr<Node> expression)
            : op_(op), left_(left), expression_(expression) {}

    bool Evaluate(const Date& date, const string& event) const override;

private:
    LogicalOperation op_;
    shared_ptr<Node> left_;
    shared_ptr<Node> expression_;
};
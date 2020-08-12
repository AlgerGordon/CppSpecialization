//
// Created by General on 11.08.2020.
//

#include "node.h"

#include <iostream>


bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp_ == Comparison::Less) {
        return date < date_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return !(date_ < date);
    } else if (cmp_ == Comparison::Greater) {
        return date_ < date;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return !(date < date_);
    } else if (cmp_ == Comparison::NotEqual) {
        return (date < date_) || (date_ < date);
    } else if (cmp_ == Comparison::Equal) {
        return !((date < date_) || (date_ < date));
    }
    return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp_ == Comparison::Less) {
        return event < event_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return !(event_ < event);
    } else if (cmp_ == Comparison::Greater) {
        return event_ < event;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return !(event < event_);
    } else if (cmp_ == Comparison::NotEqual) {
        return (event < event_) || (event_ < event);
    } else if (cmp_ == Comparison::Equal) {
        return !((event < event_) || (event_ < event));
    }
    return false;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (op_ == LogicalOperation::And) {
        return left_->Evaluate(date, event) && expression_->Evaluate(date, event);
    } else if (op_ == LogicalOperation::Or) {
        return left_->Evaluate(date, event) || expression_->Evaluate(date, event);
    }
    return false;
}

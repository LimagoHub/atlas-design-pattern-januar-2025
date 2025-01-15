//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once
#include "abstract_node.h"
#include <ostream>
namespace composite {

    class node : public abstract_node{
    public:

        explicit node(const std::string &name) : abstract_node(name) {}

        void print(std::ostream &os) const override {
            os << "Node: ";
            abstract_node::print(os);
        }

        auto get_children() const -> const  Children& override {
            return children;
        }

        void append(AbstractNodeShared child) {
            children.push_back(child);
            child->set_parent(weak_from_this());
        }

        friend std::ostream &operator<<(std::ostream &os, const node &node) {
            node.print(os);
            return os;
        }

    private:
        Children children;
    };

} // composite

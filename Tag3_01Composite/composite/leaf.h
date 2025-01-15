//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once
#include "abstract_node.h"


namespace composite {

    class leaf : public abstract_node{
    public:
        leaf(const std::string &name)
                : abstract_node(name) {
        }

        auto print(std::ostream &os) const -> void override {
            os << std::string{"Leaf: "};
            abstract_node::print(os);
        }
    };

} // composite

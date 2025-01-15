//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "NodeVisitor.h"
#include "IteratorVisitor.h"


namespace composite {

    class abstract_node : public std::enable_shared_from_this<abstract_node>{
    public:
        using AbstractNodeShared = std::shared_ptr<abstract_node>;
        using AbstractNodeWeak = std::weak_ptr<abstract_node>;
        using Children = std::vector<AbstractNodeShared>;

        explicit abstract_node(std::string name = "undef"):name_{std::move(name)}{}
        abstract_node(const abstract_node&) = delete;
        abstract_node& operator = (const abstract_node&) = delete;
        abstract_node(const abstract_node&&) = delete;
        abstract_node& operator = (const abstract_node&&) = delete;
        virtual ~abstract_node() = default;

        auto get_name() const->const std::string & {
            return name_;
        }

        auto set_name(const std::string &name)-> void {
            name_ = name;
        }

        auto get_parent() const-> AbstractNodeWeak {
            return parent_;
        }

        auto set_parent(const AbstractNodeWeak &parent)->void {
            parent_ = parent;
        }

        virtual auto get_children()const  ->const  Children& {
            static Children dummy{};
            return dummy;
        }

        virtual auto print_info(std::ostream& os) const  -> void {
        }

        friend auto operator<<(std::ostream &os, const abstract_node &node)-> std::ostream & {
            node.print_info(os);
            return os;
        }

        auto print() const -> void {
            print_info(std::cout);
            std::cout << std::endl;

            for (const auto& child : get_children()) {
                child->print();
            }
        }

        virtual auto accept(NodeVisitor& v) -> void = 0;

        auto iterate(NodeVisitor& v) -> void {
            v.visit_node(*this);
            for (const auto& child : get_children()) {
                child->iterate(v);
            }
        }

        struct Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = abstract_node;
            using pointer = AbstractNodeShared;  // or also value_type*
            using reference = abstract_node&;  // or also value_type&

            Iterator() {}
            Iterator(pointer ptr) : index(0) {
                ptr->iterate(visitor);
                
                //std::cout << "Iterator(pointer ptr) call " << std::endl;
                //for (auto& item : visitor.get_nodes()) {
                //    item->print_info(std::cout);
                //    std::cout << std::endl;
                //}
                //std::cout << visitor.get_nodes().at(index) << std::endl;
            }

            reference operator*() { return *visitor.get_nodes().at(index); }
            pointer operator->() { return visitor.get_nodes().at(index); }

            // Prefix increment
            Iterator& operator++() {
                index++;
                if (index >= visitor.get_nodes().size()) {
                    index = -1;
                }
                return *this; 
            }

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.index == b.index; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.index != b.index; };

        private:
            IteratorVisitor visitor;
            size_t index{ static_cast<size_t>(-1) };
        };

        Iterator begin() { return Iterator(shared_from_this()); }
        Iterator end() { return Iterator(); }

    private:
        AbstractNodeWeak parent_;
        std::string name_;
    };
}

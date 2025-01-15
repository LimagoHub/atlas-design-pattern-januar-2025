cmake_minimum_required(VERSION 3.17)
project(Tag3_01Konto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tag3_01Konto main.cpp
        composite/abstract_node.h
        "composite/Konto.h"
        "composite/Kontogruppe.h"
        "composite/NodeVisitor.h"
        "composite/NodeVisitor.cpp"
        "composite/IteratorVisitor.h" "composite/IteratorVisitor.cpp" "composite/PrintVisitor.h" "composite/AddSaldoVisitor.h")

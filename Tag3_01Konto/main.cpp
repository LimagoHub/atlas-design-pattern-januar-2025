#include <iostream>
#include "composite/abstract_node.h"
#include "composite/Kontogruppe.h"
#include "composite/Konto.h"

#include "composite/IteratorVisitor.h"
#include "composite/PrintVisitor.h"
#include "composite/AddSaldoVisitor.h"

using Kontogruppe = composite::Kontogruppe;
using Konto = composite::Konto;

void travers(std::shared_ptr<composite::abstract_node> myNode) {
    std::cout << *myNode << std::endl;
    for(auto & child : myNode->get_children()){
        travers(child);
    }
}
int main() {
    auto root =std::make_shared<Kontogruppe>("root");

    auto e1 = std::make_shared<Kontogruppe>("e1");
    auto e2 = std::make_shared<Kontogruppe>("e2");
    auto e3 = std::make_shared<Kontogruppe>("e3");
    auto e3_1 = std::make_shared<Kontogruppe>("e3_1");
    auto e3_2 = std::make_shared<Kontogruppe>("e3_2");
    auto e3_3 = std::make_shared<Kontogruppe>("e3_3");

    auto e2_1 = std::make_shared<Konto>("e2_1", 10);
    auto e2_2 = std::make_shared<Konto>("e2_2", 100);

    root->append(e1);
    root->append(e2);
    root->append(e3);

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    e2->append(e2_1);
    e2->append(e2_2);

    //travers(root);
    //root->print();

    //composite::IteratorVisitor iterator_visitor;
    //root->iterate(iterator_visitor);

    //for (auto &item : *root) {
    //    item.print_info(std::cout);
    //    std::cout << std::endl;
    //}

    composite::PrintVisitor print_visitor;
    root->iterate(print_visitor);

    composite::AddSaldoVisitor saldo_visitor{5};
    root->iterate(saldo_visitor);

    root->iterate(print_visitor);

    return 0;
}


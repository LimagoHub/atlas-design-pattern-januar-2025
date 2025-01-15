#include <iostream>
#include "composite/abstract_node.h"
#include "composite/node.h"
#include "composite/leaf.h"

using node = composite::node;
using leaf = composite::leaf;

void travers(std::shared_ptr<composite::abstract_node> myNode) {
    std::cout << *myNode << std::endl;
    for(auto & child : myNode->get_children()){
        travers(child);
    }
}
int main() {
    auto root =std::make_shared<node>("root");

    auto e1 = std::make_shared<node>("e1");
    auto e2 = std::make_shared<node>("e2");
    auto e3 = std::make_shared<node>("e3");
    auto e3_1 = std::make_shared<node>("e3_1");
    auto e3_2 = std::make_shared<node>("e3_2");
    auto e3_3 = std::make_shared<node>("e3_3");

    auto e2_1 = std::make_shared<leaf>("e2_1");
    auto e2_2 = std::make_shared<leaf>("e2_2");

    root->append(e1);
    root->append(e2);
    root->append(e3);

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    e2->append(e2_1);
    e2->append(e2_2);

    //travers(root);

    root->ausgabe();


   e3.iterate(v);

   for(auto item :e3) {

   }

    return 0;
}


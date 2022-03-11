#include "ManageNode.hpp"
#include <iostream>

int main()
{
    ManageNode nodes;

    nodes.add(1);
    nodes.add(3);
    nodes.add(2);
    std::cout << "__ Add: 1, 3, 2" << std::endl;
    nodes.printValues();
    nodes.deleteNode(nodes.find(3));
    nodes.deleteNode(nodes.find(2));
    // nodes.deleteNode(nodes.find(1));
    std::cout << "__ Find: 3" << std::endl;
    std::cout << "__ Delete: 3" << std::endl;
    nodes.printValues();
    std::cout << "__ Pack" << std::endl;
    nodes.pack();
    nodes.printValues();
}
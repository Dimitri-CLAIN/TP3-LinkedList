#include "ManageNode.hpp"
#include <iostream>

int main()
{
    ManageNode nodes;

    std::cout << "__ Add: 1, 3, 2" << std::endl;
    nodes.add(1);
    nodes.add(3);
    nodes.add(2);
    nodes.printValues();

    // std::cout << "__ Find: 3" << std::endl;
    // std::cout << "__ Delete: 3" << std::endl;
    // nodes.deleteNode(nodes.find(3));
    // std::cout << "__ Find: 2" << std::endl;
    // std::cout << "__ Delete: 2" << std::endl;
    // nodes.deleteNode(nodes.find(2));
    std::cout << "__ Find: 1" << std::endl;
    std::cout << "__ Delete: 1" << std::endl;
    nodes.deleteNode(nodes.find(1));
    nodes.printValues();

    std::cout << "__ Add: 5" << std::endl;
    nodes.add(5);
    nodes.printValues();

    std::cout << "__ Find: " << nodes.countNode() << " nodes" << std::endl;
    std::cout << "__ Alive " << nodes.countAliveNode() << std::endl;

    std::cout << "__ Pack" << std::endl;
    nodes.pack();
    nodes.printValues();

    std::cout << "__ Add: 8" << std::endl;
    nodes.add(8);
    nodes.printValues();
    
    std::cout << "__ Find: " << nodes.countNode() << " nodes" << std::endl;
    nodes.~ManageNode();
}
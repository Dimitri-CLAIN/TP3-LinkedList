#include <iostream>
#include "ManageNode.hpp"

ManageNode::ManageNode()
{
    struct Node *first = (struct Node*) malloc(sizeof(struct Node));

    _header = (struct Header*) malloc(sizeof(struct Header));
    _trailer = (struct Trailer*) malloc(sizeof(struct Trailer));
    first->value = -1;
    first->next = (struct Node*)_trailer;
    first->prev = (struct Node*)_header;
    _header->next = first;
    _trailer->prev = first;
}

ManageNode::~ManageNode()
{
    // TODO Free all node
}

void ManageNode::add(int value)
{
    struct Node *tmp = _header->next;

    try {

        while (tmp != (struct Node*)_trailer) {
            if (tmp->value == -1) {
                tmp->value = value;
                return;
            }
            tmp = tmp->next;
        }
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

        newNode->value = value;
        newNode->next = (struct Node*)_trailer;
        _trailer->prev->next = newNode;
        newNode->prev = _trailer->prev;
        _trailer->prev = newNode;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ManageNode::printValues()
{
    struct Node *tmp = _header->next;

    try {
        while (tmp != (struct Node*)_trailer) {
            if (tmp->value != -1) {
                std::cout << tmp->value << std::endl;
            }
            tmp = tmp->next;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
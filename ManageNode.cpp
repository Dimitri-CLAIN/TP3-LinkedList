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

struct Node *ManageNode::find(int value)
{
    struct Node *tmp = _header->next;

    try {
        while (tmp != (struct Node*)_trailer) {
            if (tmp->value == value) {
                return tmp;
            }
            tmp = tmp->next;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return nullptr;
}

void ManageNode::deleteNode(struct Node *node)
{
    struct Node *tmp = _header->next;

    try {
        while (tmp != (struct Node*)_trailer) {
            if (tmp == node) {
                node->value = -1;
            }
            tmp = tmp->next;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ManageNode::freeNode(struct Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // TODO free; Gere pas le header et tailer
}

void ManageNode::pack()
{
     struct Node *tmp = _header->next;

    try {
        while (tmp != (struct Node*)_trailer) {
            if (tmp->value == -1) {
                freeNode(tmp);
            }
            tmp = tmp->next;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void ManageNode::printValues()
{
    int i = 0;
    struct Node *tmp = _header->next;

    try {
        while (tmp != (struct Node*)_trailer) {
            if (tmp->value != -1) {
                std::cout << i << "\t|\t" << tmp->value << "\t--\t😀" << std::endl;
            } else {
                std::cout << i << "\t|\t" << tmp->value << "\t--\t💀" << std::endl;
            }
            i++;
            tmp = tmp->next;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
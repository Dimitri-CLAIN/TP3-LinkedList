#include <iostream>
#include "ManageNode.hpp"

ManageNode::ManageNode()
{
    _header = (struct Header*) malloc(sizeof(struct Header));
    _trailer = (struct Trailer*) malloc(sizeof(struct Trailer));
    _header->next = (struct Node*)_trailer;
    _trailer->prev = (struct Node*)_header;
}

ManageNode::~ManageNode()
{
    struct Node *tmp = _header->next;
    struct Node *tofree;

    try {
        while (tmp != (struct Node*)_trailer) {
            tofree = tmp;
            tmp = tmp->next;
            if (tofree->next == (struct Node*)_trailer && tofree->prev == (struct Node*)_header) {
                freeNode(tofree, 4);
            } else {
                freeNode(tofree, 1);
            }
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int ManageNode::countDelNode() 
{
    int res = 0;
    struct Node *tmp = _header->next;

    try
    {
        while (tmp != (struct Node*)_trailer)
        {
            if (tmp->value == -1)
                res++;
            tmp = tmp->next;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return res;
    
}

int ManageNode::countAliveNode() 
{
    int res = 0;
    struct Node *tmp = _header->next;

    try
    {
        while (tmp != (struct Node*)_trailer)
        {
            if (tmp->value != -1)
                res++;
            tmp = tmp->next;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return res;
    
}

int ManageNode::countNode() 
{
    int res = 0;
    struct Node *tmp = _header->next;

    try
    {
        while (tmp != (struct Node*)_trailer)
        {
            res++;
            tmp = tmp->next;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return res;
    
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
        if (_trailer->prev == (struct Node*)_header) {
            ((struct Header *)_trailer->prev)->next = newNode;
        } else {
            _trailer->prev->next = newNode;
        }
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

void ManageNode::freeNode(struct Node *node, int mode)
{
    if (mode == 1) {
        node->next->prev = (struct Node*)_header;
        _header->next = node->next;
    } else if (mode == 2) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    } else if (mode == 3) {
        node->prev->next = (struct Node*)_trailer;
        _trailer->prev = node->prev;
    } else if (mode == 4) {
        _header->next = (struct Node*)_trailer;
        _trailer->prev = (struct Node*)_header;
    }
    free(node);
}

void ManageNode::pack()
{
    struct Node *tmp = _header->next;
    struct Node *tofree;

    try {
        while (tmp != (struct Node*)_trailer) {
            tofree = tmp;
            tmp = tmp->next;
            if (tofree->value == -1 && tofree->next != (struct Node*)_trailer && tofree->prev != (struct Node*)_header) {
                freeNode(tofree, 2);
            }
            if (tofree->value == -1 && tofree->next != (struct Node*)_trailer && tofree->prev == (struct Node*)_header) {
                freeNode(tofree, 1);
            }
            if (tofree->value == -1 && tofree->next == (struct Node*)_trailer && tofree->prev != (struct Node*)_header) {
                freeNode(tofree, 3);
            }
            if (tofree->value == -1 && tofree->next == (struct Node*)_trailer && tofree->prev == (struct Node*)_header) {
                freeNode(tofree, 4);
            }
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

void ManageNode::printAliveValues()
{
    int i = 0;
    struct Node *tmp = _header->next;

    try {
        while (tmp != (struct Node*)_trailer) {
            if (tmp->value != -1) {
                std::cout << i << "\t|\t" << tmp->value << "\t--\t😀" << std::endl;
            }
            i++;
            tmp = tmp->next;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
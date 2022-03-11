#include "Node.hpp"

class ManageNode
{
private:
    struct Header *_header;
    struct Trailer *_trailer;

public:
    ManageNode();
    ~ManageNode();
    void add(int value); // Ajoute une valeur dans une Node libre ou crée une Node pour la valeur
    Node *find(int value); // Cherche la premiére node.value == value
    void deleteNode(struct Node *node); // set la value à -1;
    void pack();
    void printValues();
};
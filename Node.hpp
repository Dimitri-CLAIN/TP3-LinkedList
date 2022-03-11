struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Header
{
    struct Node *next;
};

struct Trailer
{
    struct Node *prev;
};
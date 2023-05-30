#ifndef ARRAYBINARAYSEARCHTREE_HPP
#define ARRAYBINARAYSEARCHTREE_HPP

#include "AbstractBST.hpp"
#define MAX_NUM_NODES 128

class ArrayNode
{
public:
    int key;
    char value;
    ArrayNode(int key, char value) : key(key), value(value) {}
};

class ArrayBinarySearchTree : public AbstractBST
{
private:
    ArrayNode *node[MAX_NUM_NODES];

public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();

    bool isEmpty();
    void addBST(int key, int value);
    void removeBST(int keyToDelete);
    bool searchBST(int targetKey);
};
#endif
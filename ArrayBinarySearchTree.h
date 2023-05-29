#ifndef ARRAYBINARAYSEARCHTREE_HPP
#define ARRAYBINARAYSEARCHTREE_HPP

#define MAX_NUM_NODES 128
#include "AbstractBST.h"

class ArrayNode
{
public:
    int key;
    int value;
    ArrayNode(int key, int value) : key(key), value(value) {}
};

class ArrayBinarySearchTree : public AbstractBST
{
private:
    ArrayNode node[MAX_NUM_NODES];

public:
    ArrayBinarySearchTree();
    ~ArrayBinarySearchTree();

    bool isEmpty();
    void addBST(int key, int value);
    void removeBST(int keyToDelete);
    bool searchBST(int targetKey);
};
#endif
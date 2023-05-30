#include "ArrayBinarySearchTree.hpp"
#include <iostream>
using namespace std;

ArrayBinarySearchTree::ArrayBinarySearchTree()
{
    for (int i = 0; i < MAX_NUM_NODES; i++)
    {
        node[i] = nullptr;
    }
}

ArrayBinarySearchTree::~ArrayBinarySearchTree()
{
    for (int i = 0; i < MAX_NUM_NODES; i++)
    {
        delete node[i];
    }
}

bool ArrayBinarySearchTree::isEmpty()
{
    if (node[0] == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ArrayBinarySearchTree::addBST(int key, int value)
{
    int index = 0;
    while (index < MAX_NUM_NODES && node[index] != nullptr)
    {
        if (key < node[index]->key)
        {
            // Go to the left child
            index = (2 * index) + 1;
        }
        else if (key > node[index]->key)
        {
            // Go to the right child
            index = (2 * index) + 2;
        }
        else
        {
            // If key already exists, update the value
            node[index]->value = value;
            return;
        }
    }

    if (index < MAX_NUM_NODES)
    {
        node[index] = new ArrayNode(key, value);
    }
    else
    {
        cout << "The Array BST is full." << endl;
    }
}

void ArrayBinarySearchTree::removeBST(int keyToDelete)
{
    if (isEmpty())
    {
        cout << "The BST is empty." << endl;
    }
    else
    {
        int index = 0;
        while (index < MAX_NUM_NODES && node[index] != nullptr)
        {
            if (keyToDelete < node[index]->key)
            {
                // Go to the left child
                index = (2 * index) + 1;
            }
            else if (keyToDelete > node[index]->key)
            {
                // Go to the right child
                index = (2 * index) + 2;
            }
            else // node[index]->key = keyToDelete
            {
                break;
            }
        }

        if (index >= MAX_NUM_NODES || node[index] == nullptr)
        {
            cout << "Key is not found in the BST." << endl;
        }

        int leftChildIndex = (2 * index) + 1;
        int rightChildIndex = (2 * index) + 2;

        // Case 1: No child
        if (node[leftChildIndex] == nullptr && node[rightChildIndex] == nullptr)
        {
            node[index] = nullptr;
        }

        // Case 2: Only one child
        else if (node[leftChildIndex] == nullptr)
        {
            node[index] = node[rightChildIndex];
            node[rightChildIndex] = nullptr;
        }
        else if (node[rightChildIndex] == nullptr)
        {
            node[index] = node[leftChildIndex];
            node[leftChildIndex] = nullptr;
        }

        // Case 3: Has two subtrees
        else
        {
            // Smallest node in the right subtree
            int smallestNodeIndex = (2 * rightChildIndex) + 1;
            while (node[smallestNodeIndex] != nullptr)
            {
                smallestNodeIndex = (2 * smallestNodeIndex) + 1;
            }
            node[index]=node[smallestNodeIndex];
            node[smallestNodeIndex]=nullptr;
        }
    }
}

bool ArrayBinarySearchTree::searchBST(int targetKey)
{
    int index = 0;
    while (index < MAX_NUM_NODES && node[index] != nullptr)
    {
        if (targetKey < node[index]->key)
        {
            // Go to the left child
            index = (2 * index) + 1;
        }
        else if (targetKey > node[index]->key)
        {
            // Go to the right child
            index = (2 * index) + 2;
        }
        else
        {
            // Key found in the BST
            return true;
        }
    }
    // Key not found in the BST
    return false;
}

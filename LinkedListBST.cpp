#include "LinkedListBST.h"
#include <iostream>

LinkedListBST::LinkedListBST() {
    root = nullptr;
}



bool LinkedListBST::isEmpty() {
    return root == nullptr;
}

void LinkedListBST::addBST(int data) {
    std::cout << "Adding " << data << std::endl;
    root = add(root, data);
}

Node* LinkedListBST::add(Node* root, int data) {
    if (root == nullptr)
        root = getNewNode(data);
    else if (root->data > data)
        root->left = add(root->left, data);
    else
        root->right = add(root->right, data);
    return root;
}

Node* LinkedListBST::getNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool LinkedListBST::searchBST(int data) {
    if (search(root, data)) {
        std::cout << "Search result for " << data << ": 1" << std::endl;
        return true;
    }
    else {
        return false;
    }
}

bool LinkedListBST::search(Node* root, int data) {
    if (root == nullptr)
        return false;
    else if (root->data == data)
        return true;
    else if (root->data > data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

void LinkedListBST::max(int& output) {
    if (!isEmpty()) {
        Node* temp = root;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        output = temp->data;
    }
    else {
        std::cout << "The tree is empty" << std::endl;
    }
}

void LinkedListBST::min(int& output) {
    if (!isEmpty()) {
        Node* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        output = temp->data;
    }
    else {
        std::cout << "The tree is empty" << std::endl;
    }
}

void LinkedListBST::inorder() {
    std::cout << "The traversal yields:" << std::endl;
    inorder(root);
}

void LinkedListBST::inorder(Node* root) {
    if (root == nullptr)
        return;
    else {
        inorder(root->left);
        std::cout << root->data << std::endl;
        inorder(root->right);
    }
}

void LinkedListBST::removeBST(int data) {
    std::cout << "Removing " << data << std::endl;
    root = remove(root, data);
}

Node* LinkedListBST::remove(Node* root, int data) {
    if (root == nullptr)
        return root;
    else if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = remove(root->right, minRight->data);
        }
    }
    return root;
}

Node* LinkedListBST::findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}
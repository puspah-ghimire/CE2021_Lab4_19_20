#include "ArrayBinarySearchTree.hpp"
#include <iostream>
using namespace std;
int main()
{
    ArrayBinarySearchTree A_BST;
    cout << "The following are the outputs of Binary Search Tree implementation using Arrays." << endl;
    cout << "Is BST empty? " << (A_BST.isEmpty() ? "Yes" : "No") << endl;

    A_BST.addBST(10, 100);
    cout << "Added (10, 100) to the BST." << endl;
    A_BST.addBST(5, 50);
    cout << "Added (5, 50) to the BST." << endl;
    A_BST.addBST(8, 80);
    cout << "Added (8, 80) to the BST." << endl;
    A_BST.addBST(4, 40);
    cout << "Added (4, 40) to the BST." << endl;
    A_BST.addBST(14, 140);
    cout << "Added (14, 140) to the BST." << endl;
    A_BST.addBST(12, 120);
    cout << "Added (12, 120) to the BST." << endl;
    A_BST.addBST(16, 160);
    cout << "Added (16, 160) to the BST." << endl;
    A_BST.addBST(15, 150);
    cout << "Added (15, 150) to the BST." << endl;
    A_BST.addBST(18, 180);
    cout << "Added (18, 180) to the BST." << endl;

    A_BST.removeBST(14);

    cout << "Removed (14, 140)" << endl;
    cout << "Is key 14 in the BST? " << (A_BST.searchBST(14) ? "Yes" : "No") << endl;
    cout << "Is key 15 in the BST? " << (A_BST.searchBST(15) ? "Yes" : "No") << endl;
    cout << "Is key 16 in the BST? " << (A_BST.searchBST(16) ? "Yes" : "No") << endl;
    cout << "Is key 18 in the BST? " << (A_BST.searchBST(18) ? "Yes" : "No") << endl;

    return 0;
}
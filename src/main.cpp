#include "ArrayBinarySearchTree.hpp"
#include <iostream>
using namespace std;
int main()
{
    ArrayBinarySearchTree A_BST;
    cout << "Is BST empty? " << (A_BST.isEmpty() ? "Yes" : "No") <<endl;
    A_BST.addBST(1,10);
    A_BST.addBST(2,20);
    A_BST.removeBST(1);
    cout<<"Removed key 1 and its value."<<endl;
    cout << "Is key 1 in the BST? " << (A_BST.searchBST(1) ? "Yes" : "No") <<endl;
    cout << "Is key 2 in the BST? " << (A_BST.searchBST(2) ? "Yes" : "No") <<endl;
}
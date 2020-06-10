#include <iostream>
#include "BinaryTree.h"


int main() {

//    std::vector<int> data = {12, 24, 6, 8};
//    BinaryTree tree(data);
    BinaryTree tree;
    tree.insert(12);
    tree.insert(24);
    tree.insert(6);
    tree.insert(8);
    // tree.debug();
    tree.inorder_traversal(false);
    tree.inorder_traversal(true);
    std::cout << tree.search(5);
    std::cout << tree.search(6);
    std::cout << tree.search(8);
    return 0;
}

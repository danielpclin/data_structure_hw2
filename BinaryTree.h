//
// Created by 林柏臣 on 2020/6/2.
//

#ifndef DATA_STRUCTURE_HW2_BINARYTREE_H
#define DATA_STRUCTURE_HW2_BINARYTREE_H
struct node {
    node* next;
    int index;
    int data;
};

class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const std::vector<int>& data);
    ~BinaryTree();
    void insert(int data);
    void inorder_traversal(bool reverse);
    bool search(int target);
    void debug();
private:
    static struct node* left_child(struct node* node);
    static struct node* right_child(struct node* node);
    struct node* root = nullptr;
    static struct node *get_node(node* head, int idx);

    bool create_node(int idx, int data);
};


#endif //DATA_STRUCTURE_HW2_BINARYTREE_H

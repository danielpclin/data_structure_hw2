//
// Created by 林柏臣 on 2020/6/2.
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include <stack>
#include "BinaryTree.h"

void BinaryTree::insert(int data) {
    int idx = 0;
    node* tmp = BinaryTree::get_node(root, idx);
    while (true){
        if(tmp != nullptr){
            if(tmp->data > data){
                idx = idx * 2 + 1;
                tmp = left_child(tmp);
            }else if(tmp->data < data){
                idx = idx * 2 + 2;
                tmp = right_child(tmp);
            }else{
                // data already exists
                break;
            }
        }else{
            create_node(idx, data);
            break;
        }
    }
}

void BinaryTree::inorder_traversal(bool reverse) {
    if (!reverse){
        node* current = root;
        std::stack<node *> inorder;
        while (true){
            while (current){
                inorder.push(current);
                current = left_child(current);
            }
            if (inorder.empty()){
                break;
            }else{
                node* poped = inorder.top();
                std::cout << poped->data << " ";
                inorder.pop();
                current = right_child(poped);
            }
        }
        std::cout << std::endl;
    }else{
        node* current = root;
        std::stack<node *> inorder;
        while (true){
            while (current){
                inorder.push(current);
                current = right_child(current);
            }
            if (inorder.empty()){
                break;
            }else{
                node* poped = inorder.top();
                std::cout << poped->data << " ";
                inorder.pop();
                current = left_child(poped);
            }
        }
        std::cout << std::endl;
    }
}

bool BinaryTree::search(int target) {
    node* current = root;
    while(current){
        if(current->data == target){
            return true;
        }else if(current->data > target){
            current = left_child(current);
        }else if(current->data < target){
            current = right_child(current);
        }else{
            // unreachable
            assert(false);
        }
    }
    return false;
}

BinaryTree::BinaryTree(const std::vector<int>& data) {
    for(int _data : data){
        insert(_data);
    }
}

BinaryTree::BinaryTree() = default;

BinaryTree::~BinaryTree() {
    node* prev = root;
    node* tmp = nullptr;
    while(prev){
        tmp = prev->next;
        free(prev);
        prev = tmp;
    }
}

node* BinaryTree::left_child(node *node) {
    return get_node(node, node->index * 2 + 1);
}

node* BinaryTree::right_child(node *node) {
    return get_node(node, node->index * 2 + 2);
}

bool BinaryTree::create_node(int idx, int data) {
    node* prev = root;
    node* tmp = nullptr;
    if(root == nullptr){
        root = (node*)malloc(sizeof(node));
        root->index = idx;
        root->data = data;
        root->next = nullptr;
        return true;
    }else{
        while(prev){
            tmp = prev->next;
            if(prev->index < idx){
                if(tmp == nullptr){
                    node* current = static_cast<node *>(malloc(sizeof(node)));
                    current->index = idx;
                    current->data = data;
                    prev->next = current;
                    current->next = nullptr;
                    return true;
                }else if(tmp->index > idx){
                    node* current = static_cast<node *>(malloc(sizeof(node)));
                    current->index = idx;
                    current->data = data;
                    prev->next = current;
                    current->next = tmp;
                    return true;
                }else if(tmp->index == idx){
                    return false;
                }
            }
            prev = prev->next;
        }
    }
    return false;
}

node* BinaryTree::get_node(node* head, int idx) {
    node* tmp = head;
    while(tmp){
        if(tmp->index == idx){
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

void BinaryTree::debug(){
    node* tmp = root;
    while(tmp){
        std::cout << "index: " << tmp->index << ", data: " << tmp->data << std::endl;
        tmp = tmp->next;
    }
}
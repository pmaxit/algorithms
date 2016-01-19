#ifndef BST
#define BST

#include <iostream>
#include <string>
#include <sstream>
#include "btree.h"

using namespace std;

template<class T>
class BSTree: public BTree<T>{

public:

    BSTree():BTree<T>(){}

    ~BSTree(){
    }

    Node<T> *insertKey(T data, Node<T> *root = nullptr){
        if(root == NULL) return new Node<T>(data);

        if(root->key < data)
            root->right = insertKey(data, root->right);
        else
            root->left  = insertKey(data, root->left);

        return root;
    }

    T getMinValue(Node<T> *root){
        while(root->left) root = root->left;
        return root->key;
    }

    Node<T> *searchKey(T data, Node<T> *root = nullptr){
        if(root == NULL)
            return NULL;

        if(data < root->key)
            return searchKey(data, root->left);
        else if(data > root->key)
            return searchKey(data, root->right);
        else
            return root;
    }

    Node<T> *deleteKey(T data, Node<T> *root = nullptr){
        // base case
        if(root == NULL) return root;

        if(data < root->key)
            root->left = deleteKey(data, root->left);

        else if(data > root->key)
            root->right = deleteKey(data,root->right);
        else{
            if(root->left == NULL){
                Node<T> *temp = root->right;
                delete(root);
                return temp;
            }
            else if(root->right == NULL){
                Node<T> *temp = root->left;
                delete(root);
                return temp;
            }

            // it has two children
            T val = getMinValue(root->right);
            root->key = val;
            root->right = deleteKey(val, root->right);
        }

        return root;
    }
};

#endif // BSTree


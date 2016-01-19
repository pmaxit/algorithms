#ifndef BTREE
#define BTREE

#include<iostream>
#include<sstream>

#include "node.h"
#include "bstutil.h"

using namespace std;

template<class T>
class BTree{

public:
    BTree(){}

    ~BTree(){
        delTree(root);
    }

    void delTree(Node<T> *root){
        Node<T> *temp = root;
        if(temp){
            delTree(root->left);
            delTree(root->right);
            delete(temp);
        }

    }

    friend ostream &operator<<(ostream &output, const BTree &bstree){
        printPretty(bstree.root, 0, 0, output);

        return output;
    }

    BTree &operator<<(T data){
        root = insertNode(data);
        return *this;
    }

/*
 *  input items from istream
 *
 *  Usages: cin>> bstree;
 */
    friend istream &operator>>(istream &input, BTree &bstree){
        T data;
        std::string line;
        std::getline(input, line);
        std::istringstream iss(line);

        while(iss >> data){
            bstree.root = bstree.insertNode(data);
        }
        return input;
    }

    void inorder(Node<T> *root = nullptr, ostream& output = std::cout) const{

        if(root != nullptr){
            inorder(root->left);
            output<<root->key<<"  ";
            inorder(root->right);
        }
    }

    Node<T> *getRoot(){ return root; }

    Node<T> *deleteNode(T data){
        return deleteKey(data, root);
    }

    Node<T> *insertNode(T data){
        return insertKey(data, root);
    }

    Node<T> *searchNode(T data){
        return searchKey(data, root);
    }

    Node<T> *ChangeKey(T oldData, T newData){
        root = deleteNode(oldData);

        root = insertNode(newData);

        return root;
    }

    virtual Node<T> *insertKey(T data, Node<T>* root) = 0;

    virtual Node<T> *deleteKey(T data, Node<T> *root) = 0;

    virtual Node<T> *searchKey(T data, Node<T> *root) = 0;


private:
    Node<T> *root;
};

#endif // BTREE


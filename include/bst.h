#ifndef BST
#define BST

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
class BSTree{

public:

    typedef struct node{
        T key;
        struct node *left;
        struct node *right;

        node(T key, struct node *left=NULL, struct node *right=NULL):key(key),
            left(left), right(right){

        }

    }Node;

    BSTree():root(NULL){}

    ~BSTree(){
        delTree(root);
    }

    void delTree(Node *root){
        Node *temp = root;
        if(temp){
            delTree(root->left);
            delTree(root->right);
            delete(temp);
        }

    }

    friend ostream &operator<<(ostream &output, const BSTree &bstree){
        bstree.inorder(bstree.root, output);
        return output;
    }

    BSTree &operator<<(T data){
        root = insert(data, root);
        return *this;
    }

    // cin>>bstree;
    // enter list of numbers to be inserted 1 2 3 4 5
    friend istream &operator>>(istream &input, BSTree &bstree){
        T data;
        std::string line;
        std::getline(input, line);
        std::istringstream iss(line);

        while(iss >> data){
            bstree.root = bstree.insert(data, bstree.root);
        }
        return input;
    }

    Node * insert(T data, Node *root = nullptr){
        if(root == NULL) return new Node(data);

        if(root->key < data)
            root->right = insert(data, root->right);
        else
            root->left  = insert(data, root->left);

        return root;
    }
    T getMinValue(Node *root){
        while(root->left) root = root->left;
        return root->key;
    }

    Node *deleteNode(T data){
        return deleteKey(data, root);
    }

    Node *deleteKey(T data, Node *root = nullptr){
        // base case
        if(root == NULL) return root;

        if(data < root->key)
            root->left = deleteKey(data, root->left);

        else if(data > root->key)
            root->right = deleteKey(data,root->right);
        else{
            if(root->left == NULL){
                Node *temp = root->right;
                delete(root);
                return temp;
            }
            else if(root->right == NULL){
                Node *temp = root->left;
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

    void inorder(Node *root = nullptr, ostream& output = std::cout) const{

        if(root != nullptr){
            inorder(root->left);
            output<<root->key<<"  ";
            inorder(root->right);
        }
    }

private:
    Node *root;
};

#endif // BSTree


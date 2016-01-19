#ifndef REDBLACK
#define REDBLACK

#include <iostream>
#include "bst.h"

/*
 * Implementation of red black trees
 *
 */
template<class T>
class RedBlack: public BSTree<T>{

public:
    RedBlack():BSTree<T>(){}

    Node<T> *insertKey(T data, Node<T>* root){
        return root;
    }

    Node<T> *deleteKey(T data, Node<T> *root){
        return root;
    }
};

#endif // REDBLACK


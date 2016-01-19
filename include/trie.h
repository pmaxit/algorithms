#ifndef TRIE_H
#define TRIE_H
#include "node.h"
#include <string>

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

template<class T=string>
class Trie{
public:
    Trie();
    ~Trie(); // deconstruct everything

    TrieNode<T>* put(T key, T value);
    TrieNode<T>* put(T key);

    TrieNode<T>* get(T key);

    T & operator[](const T key){
        TrieNode<T> *res = get(key);
        if(res)
            return res->key;
        else{
            // insert the key
        }
    }

private:

    TrieNode<T>* getTrieNode();
    void deleteTree(TrieNode<T>*root);

    TrieNode<T> *root;
    int count;
};

#endif // TRIE_H


template<class T>
Trie<T>::~Trie(){
    deleteTree(root);
}

template<class T>
void Trie<T>::deleteTree(TrieNode<T> *root){
    if(root == NULL)
        return;
    for(int i=0; i< ALPHABET_SIZE; i++)
        deleteTree(root->children[i]);
    delete(root);
}

template<class T>
TrieNode<T> *Trie<T>::getTrieNode(){
    TrieNode<T> *node = new TrieNode<T>();
    for(int i=0; i< ALPHABET_SIZE; i++){
        node->children[i] = NULL;
    }
    node->isLeaf = 0;
    return node;
}

// implementation
template<class T>
Trie<T>::Trie(){
    root = getTrieNode(); // here key is undefined
}

template<class T>
TrieNode<T>* Trie<T>::put(T key){
    return put(key, key);
}

template<class T>
TrieNode<T> *Trie<T>::put(T key, T value){
    TrieNode<T> *pCrawl=root;
    for(int i=0; i< key.length(); i++){
        int index = CHAR_TO_INDEX(key[i]);
        if(!pCrawl->children[index])
            pCrawl->children[index] = getTrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->key= value; // storing the actual key in last node
    pCrawl->isLeaf =1;
    count++;

    return pCrawl;
}

template<class T>
TrieNode<T>* Trie<T>::get(T key){
    TrieNode<T> *pCrawl = root;
    int i=0;
    while(pCrawl && i<key.length()){
        int index= CHAR_TO_INDEX(key[i++]);
        if( pCrawl->children[index])
            pCrawl = pCrawl->children[index];
        else
            return nullptr;
    }
    if(pCrawl && pCrawl->isLeaf)
        return pCrawl;
    else
        return nullptr;
}

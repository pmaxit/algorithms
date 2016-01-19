#ifndef NODE
#define NODE

#define ALPHABET_SIZE 26

template<class T>
struct Node{
    T key;
    Node *left;
    Node *right;

    Node(T key, Node *left=NULL, Node *right=NULL):key(key),
        left(left), right(right){

    }

};

template<class T>
struct TrieNode{
    T key;
    int isLeaf;
    TrieNode *children[ALPHABET_SIZE];
};


#endif // NODE


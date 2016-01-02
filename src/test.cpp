#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

int main(int argc, const char *argv[])
{

    BSTree<int> bstree;
    cin>>bstree;

    cout<<bstree<<endl;
    bstree.deleteNode(87);
    cout<<bstree<<endl;
    return 0;
}

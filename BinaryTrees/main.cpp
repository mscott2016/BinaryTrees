//
//  main.cpp
//  BinaryTrees
//
//  Created by Marley on 2/8/18.
//  Copyright © 2018 Mar Z Mar. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <list>
#include "BinaryTree.hpp"



using namespace std;

int depth(const BinaryTree<int> & T, const  BinaryTree<int>::Position& p)
{
    if (p.isRoot())
        return 0;
    else
        return 1 + depth(T, p.parent()) ;
}//Returns the depth of the BinaryTree

int height(const BinaryTree<int>& T){
    int h = 0;
    BinaryTree<int>:: PositionList nodes = T.positions(); // list of all nodes for
    for ( BinaryTree<int>::PositionList:: iterator q = nodes.begin(); q != nodes.end(); ++q) {
        if (q->isExternal())
            h = max(h, depth(T, *q)); // get max depth among leaves
}
    return h;
} //Returns the height of the BinaryTree
int main(void )
{
    BinaryTree<int> myTree ;
    BinaryTree<int>::Position myTreePos ;
    
    cout << myTree.size()<< endl;
    myTree.addRoot();
    cout << myTree.size()<< endl;
    myTree.expandExternal(myTree.root());
    cout << myTree.size()<< endl;
    cout << depth(myTree,myTree.root())<< endl;
    myTreePos = myTree.root().left();
    cout << depth(myTree,myTreePos)<< endl;
    cout << height(myTree)<< endl;
    if (myTreePos.isExternal())
        cout << "node is external"<< endl;
    else if (myTreePos.isInternal())
        cout << "node is internal"<< endl;
    cout << myTree.size()<< endl;
    myTree.~BinaryTree();
    cout << myTree.size()<< endl;
    return EXIT_SUCCESS;
}




//
//  BinaryTree.hpp
//  BinaryTrees
//
//  Created by Marley on 2/8/18.
//  Copyright © 2018 Mar Z Mar. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include <cstdlib>
////////////////////////////////////
// Templated Node Interface
///////////////////////////////////
template <typename E>                                            // base element type
class Node {                                                    // a node of the tree
public:
    Node() : elt(), par(NULL), left(NULL), right(NULL) { }        // constructor
    
    
private:
    E    elt;                                                    // element value
    Node*   par;                                                // parent
    Node*   left;                                                // left child
    Node*   right;                                                // right child
    
    template <class U> friend class BinaryTree;
    template <class U> friend class Position;
};


////////////////////////////////////
// Templated Binary Tree Interface
///////////////////////////////////

template <typename E>                     // base element type
class BinaryTree
{
public:                                     // public types
    
    
    //Defines a node position
    class Position
    {
    public:
        Position(Node <E>* _v = NULL) : v(_v) { }        // constructor
        
        //Returns the element at the position
        E& operator*()
        {
            return v->elt;
        }
        
        //Returns a Position object
        Position left() const                // get left child
        {
            return Position(v->left);
        }
        
        //Returns a Position object
        Position right() const                // get right child
        {
            return Position(v->right);
        }
        
        //Returns a Position object
        Position parent() const                // get parent
        {
            return Position(v->par);
        }
        
        //Returns true or false
        bool isRoot() const                // root of tree?
        {
            return v->par == NULL;
        }
        
        //Returns true or false
        bool isExternal() const                // an external node?
        {
            return v->left == NULL && v->right == NULL;
        }
        
        //Returns true or false
        bool isInternal() const                // an external node?
        {
            return ! isExternal();
        }
        
    private:
        Node<E>* v;
        template <class U> friend class BinaryTree;
    };//End Position class definition
    
    
    /* Position List type definition*/
    
    typedef std::list<Position> PositionList;
    
    
public: //Binary member functions
    BinaryTree() : _root(NULL), n(0) { }
    ~BinaryTree(){
        destroyTree(_root);
    }            // The destructor need to properly deletes all nodes in the tree to prevent memory leaks.
    void destroyTree(Node<E> * nods)
    {
       if (nods == NULL)
           return;
        n--;
        destroyTree(nods->left);// deletes left
        destroyTree(nods->right); // deletes right
        if (nods->right == NULL && nods->left == NULL )
        {
            nods = NULL;
            delete nods;
        }
        // deletes the node
      
    }
    int size() const
    {
        return n;
    }// Returns and integer tof the number of nodes.
    
    bool empty() const
    {
        return size() == 0;
    }// Returns a true if the tree is empty else false.
    Position root() const
    {
     return Position(_root);
    }// Return the position of the root node.
    void addRoot()
    {
        _root = new Node<E> ;
        n = 1;
    }// Creates and adds the initial root node to the tree this must be added first.
    
    void expandExternal(const Position& p)
    {
        Node<E> * vNew = p.v;
        vNew->left = new Node <E>;
        vNew->right = new Node <E>;
        vNew->left->par = vNew;
        vNew->right->par = vNew;
        n += 2;
    }//Expands each external node with a left and right child that are empty.
    
    PositionList positions() const
    {
        PositionList pl;
        preorder(_root, pl);
        return PositionList(pl);
    }// Returns a std:list of the nodes in the tree call preorder() function.
    void preorder(Node<E>* v, PositionList& pl) const
    {
        pl.push_back(Position(v));
        if (v->left != NULL)
        {
            preorder(v->left, pl);
        }
        if (v->right != NULL)
        {
            preorder(v->right, pl);
        }
        
    }// Traversal algorithm for the tree to populate the PositionList
    
private:
    Node <E> * _root;                                    // pointer to the root
    int n;                                                // number of nodes
};


#endif /* BinaryTree_hpp */


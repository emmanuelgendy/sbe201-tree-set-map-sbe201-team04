//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_BST_HPP
#define SBE201_WORDCOUNT_MAPS_BST_HPP

#include <iostream>
#include <string>
#include <queue>

namespace bst
{

struct BSTNode
{
    std::string item;
    BSTNode* left;
    BSTNode* right;
};

using Tree = BSTNode *;

Tree create()
{
    return nullptr;
}

bool isEmpty( Tree node )
{

}

bool isLeaf( Tree node )
{

}

int size( Tree node )
{

}

bool find( Tree tree, std::string item )
{

}

void insert( Tree &tree, std::string item )
{

}

Tree minNode( Tree tree )
{

}

Tree maxNode( Tree tree )
{

}

void remove( Tree &tree, std::string item )
{

}


void clear( Tree &tree )
{

}

void preorder( Tree tree )
{

}

void inorder( Tree tree )
{

}

void postorder( Tree tree )
{

}

void breadthFirst( Tree tree )
{

}

}


#endif //SBE201_WORDCOUNT_MAPS_BST_HPP_HPP

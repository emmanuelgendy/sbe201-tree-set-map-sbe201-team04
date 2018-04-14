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
    BSTNode *left;
    BSTNode *right;
};

using Tree = BSTNode *;

Tree create()
{
    return nullptr;
}

bool isEmpty(Tree node)
{
    return node == nullptr;
}

bool isLeaf(Tree node)
{
    return (node->left == nullptr) && (node->right == nullptr);
}

int size(Tree node)
{
    if (!isEmpty(node))
    {
        return 1 + size(node->right) + size(node->left);
    }
    else
        return 0;
}

bool find(Tree tree, std::string item)
{
    if (!isEmpty(tree))
    {
        if (item == tree->item)
            return true;
        else if (item < tree->item)
            return find(tree->left, item);
        else
            return find(tree->right, item);
    }
    if (isEmpty(node))
    {
        return false;
    }
}

void insert(Tree &tree, std::string item)
{
    if (isEmpty(tree))
    {
        tree = BSTNode(item, nullptr, nullptr);
    }
    else
    {
        if (item < tree->item)
        {
            insert(tree->left, item);
        }
        else
        {
            insert(tree->right, item);
        }
    }
}

Tree minNode(Tree tree)
{
    if (!isEmpty(tree))
    {
        if (tree->left == null)
        {
            return tree->item;
        }
        else
            return minNode(tree->left);
    }
}

Tree maxNode(Tree tree)
{
    if (!isEmpty(tree))
    {
        if (tree->right == null)
        {
            return tree->item;
        }
        else
            return maxNode(tree->right);
    }
}

void remove(Tree &tree, std::string item)
{
    if (isEmpty(tree))
        return;

    if (item == tree->item)
    {
        if (!isEmpty(tree->left) && !isEmpty(tree->right))
        {
            BSTNode *minRight = minNode(tree->right);
            tree->item = minRight->item;
            remove(tree->right, minRight->item);
        }
        else
        {
            BSTNode *discard = tree;

            if (isLeaf(tree))
                tree = nullptr;
            else if (!isEmpty(tree->left))
                tree = tree->left;
            else
                tree = tree->right;

            delete discard;
        }
    }
    else if (item < tree->item)
        remove(tree->left, item);
    else
        remove(tree->right, item);
}

void clear(Tree &tree)
{
    bool(!isEmpty(tree))
    {
        clear(tree->left);
        clear(tree->right);
        delete tree;
        tree = nullptr;
    }
}

void preorder(Tree tree)
{
    if (tree)
    {
        std::cout << item;
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(Tree tree)
{
    if (tree)
    {
        inorder(tree->left);
        std::cout << item;
        inorder(tree->right);
    }
}

void postorder(Tree tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        std::cout << item;
    }
}

void breadthFirst(Tree tree)
{
    std::queue<BSTNode *> Q;
    Q.push(tree);
    while (Q.empty())
    {
        BSTNode *current = Q.front();
        std::cout << current->item << std::endl;
        if (current->left != nullptr)
            Q.push(current->left);
        if (current->right != nullptr)
            Q.push(current->right);
        Q.pop();
    }
}
}

#endif //SBE201_WORDCOUNT_MAPS_BST_HPP_HPP

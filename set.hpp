//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_SET_HPP
#define SBE201_WORDCOUNT_MAPS_SET_HPP

#include "bst.hpp"

namespace set
{

using WordSet = bst::BSTNode *;

WordSet create()
{
    return nullptr;
}

bool isEmpty(WordSet &wset)
{
    return bst::isEmpty(wset);
}

int size(WordSet &wset)
{
    return bst::size(wset);
}

bool contains(WordSet &wset, std::string item)
{
    bst::find(wset, item);
}

void remove(WordSet &wset, std::string to_remove)
{
    bst::remove(wset, to_remove);
}

void insert(WordSet &wset, std::string new_item)
{
    if (!bst::find(wset, new_item))
        bst::insert(wset, new_item);
}

void printAll(WordSet &wset)
{
    if (!(set::isEmpty(wset)))
    {
        printAll(wset->left);
        std::cout << wset->item << std::endl;
        printAll(wset->right);
    }
}

WordSet union_(WordSet &set1, WordSet &set2)
{
    WordSet S3 = create();
    bst::BSTNode *current;
    if (bst::q.empty())
    {
        bst::BreadthFirst(set1);
        bst::BreadthFirst(set2);
    }
    else
    {
        std::cout << "error old data exists";
        exit;
    }
    while (!bst::q.empty())
    {
        current = bst::q.front();
        set::insert(S3, current->item);
        bst::q.pop();
    }
    return S3;
}

WordSet intersect(WordSet &set1, WordSet &set2)
{
    WordSet S3 = create();
    bst::BSTNode *current;
    if (bst::q.empty())
    {
        bst::BreadthFirst(set1);
    }
    else
    {
        std::cout << "error old data exists";
        exit;
    }
    while (!bst::q.empty())
    {
        current = bst::q.front();
        if (contains(set2, current->item))
        {
            set::insert(S3, current->item);
        }
        bst::q.pop();
    }
    return S3;
}

bool equals(WordSet &set1, WordSet &set2)
{
    if ((set::size(set1)) == (set::size(set2)))
    {
    }
    else exit;
}
}
#endif //SBE201_WORDCOUNT_MAPS_SET_HPP

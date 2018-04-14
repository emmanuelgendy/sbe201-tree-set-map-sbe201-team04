//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDCOUNT_MAPS_MAP_HPP
#define SBE201_WORDCOUNT_MAPS_MAP_HPP

#include <string>
#include <iostream>

namespace map
{

struct MapNode
{
    std::string key;
    int value;
    MapNode *left;
    MapNode *right;
};

using WordMap = MapNode *;

WordMap create()
{
    return nullptr;
}

bool isEmpty(WordMap wmap)
{
    return wmap == nullptr;
}

bool isLeaf(WordMap wmap)
{
    return wmap->left == nullptr && wmap->right == nullptr;
}

int size(WordMap wmap)
{
    if (!isEmpty(wmap))
        return 1 + size(wmap->left) + size(wmap->right);
    else
        return 0;
}
void insert(WordMap &wmap, std::string key)
{
    if (isEmpty(wmap))
    {
        wmap = new MapNode;
        wmap->left = nullptr;
        wmap->right = nullptr;
        wmap->key = key;
        wmap->value = 0;
    }
    else if (key.compare(wmap->key) < 0)
    {
        insert(wmap->left, key);
    }
    else if (key.compare(wmap->key) > 0)
    {
        insert(wmap->right, key);
    }
    //Didn't write else condition cuz u asked to ignore the key if already found
}

bool contain(WordMap wmap, std::string key)
{
    if (isEmpty(wmap))
    {
        return false;
    }
    else
    {
        if (key.compare(wmap->key) == 0)
        {
            return true;
        }
        else if (key.compare(wmap->key) < 0)
        {
            contain(wmap->left, key);
        }
        else
        {
            contain(wmap->right, key);
        }
    }
}

int &at(WordMap wmap, std::string key)
{
    if (!contain(wmap, key))
    {
        std::cout << "Key not found!" << std::endl;
        exit(1);
    }
    else
    {
        if (key.compare(wmap->key) == 0)
        {
            return wmap->value;
        }
        else if (key.compare(wmap->key) < 0)
        {
            at(wmap->left, key);
        }
        else
        {
            at(wmap->right, key);
        }
    }
}
int &value(WordMap &wmap, std::string key)
{
    if (!contain(wmap, key))
    {
        insert(wmap, key);
    }
    return at(wmap, key);
}

WordMap minNode(WordMap wmap)
{
    if (wmap->left)
        return minNode(wmap->left);
    else
    {
        return wmap;
    }
}

void remove(WordMap &wmap, std::string key)
{
    if (contain(wmap, key))
    {
        if (key.compare(wmap->key) == 0)
        {
            if (!isEmpty(wmap->left) && !isEmpty(wmap->left))
            {
                WordMap minMap = minNode(wmap->right);
                wmap->key = minMap->key;
                wmap->value = minMap->value;
                remove(wmap->right, minMap->key);
            }
            else
            {
                if (isLeaf(wmap))
                {
                    wmap = nullptr;
                    delete wmap; //why do we use a dicard pointer where we can delete it directly
                }
                else if (!isEmpty(wmap->left))
                {
                    wmap = wmap->left;
                }
                else
                {
                    wmap = wmap->right;
                }
            }
        }
        else if (key.compare(wmap->key) < 0)
        {
            remove(wmap->left, key);
        }
        else
        {
            remove(tree->right, data);
        }
    }
}

void clear(WordMap &wmap)
{
    if (!isEmpty(wmap))
    {
        clear(wmap->left);
        clear(wmap->right);
        delete wmap;
        wmap = nullptr;
    }
}

void printAll(WordMap wmap) //InOrder
{
    if (wmap)
    {
        printAll(wmap->left);
        std::cout << wmap->key << ":" << wmap->value << std::endl;
        printAll(wmap->right);
    }
}
}

#endif //SBE201_WORDCOUNT_MAPS_MAP_HPP

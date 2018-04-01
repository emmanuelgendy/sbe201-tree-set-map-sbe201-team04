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

bool isEmpty( WordMap wmap )
{

}

bool isLeaf( WordMap wmap )
{

}

int size( WordMap wmap )
{

}

bool find( WordMap wmap, std::string key )
{

}


int &at( WordMap wmap, std::string key )
{
    if ( isEmpty( wmap ))
    {
        std::cout << "Key not found!" << std::endl;
        exit( 1 );
    }
    else
    {
        // COMPLETE HERE







        // DONE HERE
    }
}

void insert( WordMap &wmap, std::string key )
{
    if ( isEmpty( wmap ))
    {
        wmap = new MapNode;
        wmap->left = nullptr;
        wmap->right = nullptr;
        wmap->key = key;
        wmap->value = 0;
    }
    else if( key.compare( wmap->key ) != 0 ) // Ignore when the key is already found
    {
        // COMLETE HERE




        // DONE HERE
    }
}

WordMap minNode( WordMap wmap )
{
    if ( wmap->left )
        return minNode( wmap->left );
    else
    {
        return wmap;
    }
}

void remove( WordMap &wmap, std::string key )
{

}



int &value( WordMap &wmap , std::string key )
{
    if( !find( wmap , key ))
    {
        insert( wmap , key );
    }
    return at( wmap , key );
}

void clear( WordMap &wmap )
{
    if ( !isEmpty( wmap ))
    {
        clear( wmap->left );
        clear( wmap->right );
        delete wmap;
        wmap = nullptr;
    }
}

void printAll( WordMap wmap )
{
    if( wmap )
    {
        printAll( wmap->left );
        std::cout << wmap->key << ":" << wmap->value << std::endl;
        printAll( wmap->right );
    }
}

}

#endif //SBE201_WORDCOUNT_MAPS_MAP_HPP

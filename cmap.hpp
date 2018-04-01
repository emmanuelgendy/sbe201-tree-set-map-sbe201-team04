//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDS_CMAP_HPP
#define SBE201_WORDS_CMAP_HPP

namespace char_map
{
struct MapNode
{
    char key;
    int value;
    MapNode *left;
    MapNode *right;
};


using CharMap = MapNode *;

CharMap create()
{
    return nullptr;
}

bool isEmpty( CharMap cmap )
{

}

bool isLeaf( CharMap cmap )
{

}

int size( CharMap cmap )
{

}

bool find( CharMap cmap, char key )
{
    if ( isEmpty( cmap ))
        return false;
    else
    { // COMPLETE THIS





    }
}


int &at( CharMap cmap, char key )
{
    if ( isEmpty( cmap ))
    {
        std::cout << "Key not found!" << std::endl;
        exit( 1 );
    }
    else
    { // COMPLETE THIS





    }
}

void insert( CharMap &cmap, char key )
{
    if ( isEmpty( cmap ))
    {
        cmap = new MapNode;
        cmap->left = nullptr;
        cmap->right = nullptr;
        cmap->key = key;
        cmap->value = 0;
    }
    else if( key.compare( cmap->key ) != 0 ) // Ignore when the key is already found
    {
        if ( key < cmap->key )
            insert( cmap->left, key );
        else insert( cmap->right, key );
    }
}

CharMap minNode( CharMap cmap )
{
    if ( cmap->left )
        return minNode( cmap->left );
    else
    {
        return cmap;
    }
}

void remove( CharMap &cmap, char key )
{

}



int &value( CharMap &cmap , char key )
{

}

void clear( CharMap &cmap )
{

}

void printAll( CharMap cmap )
{
    if( cmap )
    {
        printAll( cmap->left );
        std::cout << cmap->key << ":" << cmap->value << std::endl;
        printAll( cmap->right );
    }
}


}

#endif //SBE201_WORDS_CMAP_HPP

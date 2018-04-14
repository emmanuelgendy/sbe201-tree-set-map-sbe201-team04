//
// Created by asem on 01/04/18.
//

#ifndef SBE201_WORDS_CMAP_HPP
#define SBE201_WORDS_CMAP_HPP
#include <iostream>
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
return cmap == nullptr;
}

bool isLeaf( CharMap cmap )
{
return cmap->left==nullptr;
return cmap->right==nullptr;
}

int size( CharMap cmap )
{
if(!isEmpty(cmap)){
return 1+size(cmap->left)+size(cmap->right);}
else 
return 0;
}

bool find( CharMap cmap, char key)
{
    if ( isEmpty( cmap ))
        return false;
    else
    { if ( key== cmap->key )
            return true;

        else if ( key < cmap->key)
            return find( cmap->left , key );

        else return find( cmap->right ,key );
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
    {  if (key==(cmap->key))
        {
            return cmap->value;
        }
        else if (key<cmap->key)
        {
            at(cmap->left, key);
        }
        else
        {
            at(cmap->right, key);
        }

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
    else if( key!=cmap->key ) // Ignore when the key is already found
    {
        if ( key<cmap->key)
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

if ( isEmpty( cmap )) return;

    if ( key == cmap->key )
    {
        if ( !isEmpty( cmap->left ) && !isEmpty( cmap->right ))
        {
           CharMap minRight = minNode( cmap->right );
           cmap->key= minRight->key;
            remove( cmap->right, minRight->key );
        } else
        {
         CharMap discard = cmap;

            if ( isLeaf( cmap ))
              cmap= nullptr;
            else if ( !isEmpty( cmap->left ))
               cmap = cmap->left;
            else
               cmap= cmap->right;

            delete discard;
        }

    } else if ( key< cmap->key)
        remove( cmap->left, key );
    else remove( cmap->right, key);
}




int &value( CharMap &cmap , char key )
{
if (!find(cmap, key))
    {
        insert(cmap, key);
    }
    return at(cmap, key);
}


void clear( CharMap &cmap ){
 if ( !isEmpty( cmap ))
    {
        clear(cmap->left );
        clear( cmap->right );
        delete cmap;
        cmap = nullptr;
    }
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

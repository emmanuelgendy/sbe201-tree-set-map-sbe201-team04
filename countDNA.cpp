//
// Created by asem on 01/04/18.
//

#include "cmap.hpp"
#include "helpers.hpp"


int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::string dna = getFileFirstLine( argv[1] );

        char_map::CharMap cMap = char_map::create();

        // Complete here!



        // Done here!

        char_map::printAll( cMap );
    }

    return 0;
}
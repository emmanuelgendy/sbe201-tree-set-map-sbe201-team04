//
// Created by asem on 01/04/18.
//

#include "set.hpp"
#include "helpers.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::vector<std::string> words = getFileWords(argv[1]);

        set::WordSet S1 = set::create();// COMPLETE HERE
        for (int i=0 ; i<words.size();++i) 
        {
            set::insert(S1,(words[i]));
        }
        set::printAll(S1) ;
        // DONE HERE
    }

    return 0;
}
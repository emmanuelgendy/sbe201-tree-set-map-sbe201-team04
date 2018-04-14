//
// Created by asem on 01/04/18.
//
// Submitted by Habiba on 14th April 2018
//

#include "map.hpp"
#include "helpers.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::vector<std::string> words = getFileWords(argv[1]);
        
        map::WordMap wMap = map::create();
        
        int sumWordsText = 0;
        int sumUniqueWords = 0;
        
        for (int i = 0; i < words.size(); ++i)
        {
            if (!map::contain(wMap, words[i]))
            {
                map::insert(wMap, words[i]);
                sumUniqueWords++;
            }
            sumWordsText++;
        }

        std::cout << "The Sum of All the Words in the File = " << sumWordsText << std::endl;
        std::cout << "The Sum of Repeated Words in the File = " << sumUniqueWords << std::endl;
    }

    return 0;
}

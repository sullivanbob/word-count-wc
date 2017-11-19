
/*
   wc.cpp       Extremely Simple word count program.
   Bob Sulllivan
   11/18/17
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

void readData(std::istream& in, std::string &str)
{
    char c;
    size_t ccount = 0;
    size_t wcount = 0;
    size_t ncount = 0;
    bool seeWord = false;

    while (in.get(c)) // loop getting single characters
    {
        ccount++;
        if (isspace(c))
        {
            seeWord = false;
            if ('\n' == c)
            {
                ncount++;
            }
        }
        else
        {
            if (false == seeWord)
            {
                wcount++;
            }
            seeWord = true;
        }
    }
    std::cout << std::setw(4) << ncount; 
    std::cout << std::setw(5) << wcount;
    std::cout << std::setw(5) << ccount;
    if (0 < str.length())
    {
        std::cout << " " << str;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::string instr = "";
    if ( argc > 1 )
    {
        // Read the data from the passed file..
        std::ifstream ifile(argv[1]);
        instr = argv[1];

        if ( NULL != ifile )
        {
            readData(ifile, instr);
        }
        else
        {
            // Deal with error condition
            std::cerr << "Cannot open input file " << instr << std::endl;
            exit(-1);
        }
    }
    else
    {
        // Read the data from stdin (std::cin).
        readData(std::cin, instr);
    }
    return(0);
}


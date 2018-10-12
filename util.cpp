#include "util.hpp"

std::vector<int> readInstance(std::string file, int *numQuadros) {

    std::vector<int> pages;

    std::fstream read (file, std::fstream::in | std::fstream::out);

    int page;

    read >> *numQuadros;

    while(true){
        read >> page;
        if( read.eof() ) break;
        pages.push_back(page);
    }

    read.close();

    return pages;
}
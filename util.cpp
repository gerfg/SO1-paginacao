#include "util.hpp"

std::queue<int> readInstance(std::string file, int *numQuadros) {

    std::queue<int> pages;

    std::fstream read (file, std::fstream::in | std::fstream::out);

    int page;

    read >> *numQuadros;

    while(true){
        read >> page;
        if( read.eof() ) break;
        pages.push(page);
    }

    read.close();    

    return pages;
}
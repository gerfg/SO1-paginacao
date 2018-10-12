#ifndef IALGORITHM_HPP
#define IALGORITHM_HPP

#include <vector>
#include <iostream>

class IAlgorithm {
protected:
    std::vector<int> pages;
    std::vector<int> frames;

    int pageFault;
    unsigned int lastFrame;

protected:
    IAlgorithm(std::vector<int> paginas,int framesCount):
    pages(paginas),
    pageFault(0),
    lastFrame(0)
    {
        frames.resize(framesCount, -1);
    };

    void showFrames(){
        for (auto && fr : frames){
            std::cout << fr << " ";
        }
        std::cout << "\n";
    };
};

#endif
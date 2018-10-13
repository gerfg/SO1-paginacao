#ifndef IALGORITHM_HPP
#define IALGORITHM_HPP

#include <vector>
#include <iostream>

class IAlgorithm {
protected:
    std::vector<int> pages;
    std::vector<int> frames;

    int pageFault;

    IAlgorithm(std::vector<int> paginas, int framesCount):
    pages(paginas),
    pageFault(0)
    {
        frames.resize(framesCount, -1);
    };

    void showFrames(){
        std::cout << "Frames: ";
        for (auto && fr : frames){
            std::cout << fr << " ";
        }
        std::cout << "\n";
    };

    void showPages(){
        std::cout << "Pages: ";
        for (auto && pg : pages){
            std::cout << pg << " ";
        }
        std::cout << "\n";
    };

    bool pageOnRam(int page) {
        for(auto&& fr : frames) {
            if (fr == page) {
                return true;
            }
        }
        return false;
    }
};

#endif
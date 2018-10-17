#include "lru.hpp"

LRU::LRU(std::vector<int> pages, int framesCount):
IAlgorithm(pages, framesCount),
pags(pages) 
{
    this->positionToStartTheSearch = 0;
    int frameToReplace;
    while(!pags.empty()){
        std::cout << "Pages[0]: " << pags[0] << "\n";
        if (!pageOnRam(pags[0])) {
            pageFault++;
            frameToReplace = leastRecentlyAccessed();
            updateFrame(frameToReplace);
            pags.erase(pags.begin());
        } else {
            pags.erase(pags.begin());
        }
        this->positionToStartTheSearch++;
        showPages();
        showFrames();
        std::cout << "\n\n";
    }
};

int LRU::leastRecentlyAccessed() {
    int last = 0;
    int frame = -1;

    // bool existPage = false;
    // for(int fr = 0; fr < frames.size(); fr++) {
    //     existPage = false;
    //     for(int pg = 0; pg < pags.size(); pg++) {
    //         if (frames[fr] == pags[pg]) {
    //             existPage = true;
    //             break;
    //         }
    //     }
        
    //     if (!existPage) {
    //         return fr;
    //     }
    // }
    std::cout << "Search Least Recently Accessed\n";
    for(int j=0; j < frames.size(); j++){
        
        if (frames[j] == -1) {
            return j;
        }

        std::cout << "Frame: " << frames[j] << "\n";
        
        for(int i = this->positionToStartTheSearch; i != 0; i--) {
            if (frames[j] == this->pages[i]) {

                if (i <= last) {
                    last = i;
                    frame = j;
                }
                
                break;
            }
        }
    }
    
    return frame;
}

void LRU::updateFrame(int framePosition) {
    this->frames[framePosition] = this->pags[0];
}
#include "lru.hpp"

LRU::LRU(std::vector<int> pages, int framesCount):
IAlgorithm(pages, framesCount),
pags(pages) 
{
    this->positionToStartTheSearch = -1;
    int frameToReplace;
    while(!pags.empty()){
        if (!pageOnRam(pags[0])) {
            pageFault++;
            frameToReplace = leastRecentlyAccessed();
            updateFrame(frameToReplace);
            pags.erase(pags.begin());
        } else {
            pags.erase(pags.begin());
        }
        this->positionToStartTheSearch++;
    }
    std::cout << "LRU " << pageFault << "\n";
};

int LRU::leastRecentlyAccessed() {
    for(size_t i = 0; i < frames.size(); i++) {
        if(frames[i] == -1)
            return i;
    }

    int count;
    int last[frames.size()];
    for(int j=0; j < frames.size(); j++){
        count = 0;
        for(int i = positionToStartTheSearch; i != 0; i--) {
            if (frames[j] == this->pages[i]) {
                last[j] = count;
                break;
            }
            count++;
        }
    }

    int major = 0;
    int frame = -1;
    for(int i = 0; i < frames.size(); i++) {
        if (last[i] > major){
            major = last[i];
            frame = i;
        }
    }
    return frame;
}

void LRU::updateFrame(int framePosition) {
    this->frames[framePosition] = this->pags[0];
}

void LRU::showPags(){
    std::cout << "Pags: ";
        for (auto && pg : pags){
            std::cout << pg << " ";
        }
        std::cout << "\n";
}
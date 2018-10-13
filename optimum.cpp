#include "optimum.hpp"

Optimum::Optimum(std::vector<int> pages, int framesCount):
IAlgorithm(pages, framesCount),
pags(pages) 
{
    int frameToReplace;
    while(!pags.empty()){
        if (!pageOnRam(pags[0])) {
            pageFault++;
            frameToReplace = willNotBeRecentlyAccessed();
            updateFrame(frameToReplace);
            pags.erase(pags.begin());
        } else {
            pags.erase(pags.begin());
        }
    }
};

int Optimum::willNotBeRecentlyAccessed() {
    int last = 0;
    int frame = -1;

    bool existPage = false;
    for(int fr = 0; fr < frames.size(); fr++) {
        existPage = false;
        for(int pg = 0; pg < pags.size(); pg++) {
            if (frames[fr] == pags[pg]) {
                existPage = true;
                break;
            }
        }
        
        if (!existPage) {
            return fr;
        }
    }
    

    for(int j=0; j < frames.size(); j++){
        
        if (frames[j] == -1) {
            return j;
        }
        
        for(int i = 0; i < pags.size(); i++) {
            if (frames[j] == pags[i]) {

                if (i >= last) {
                    last = i;
                    frame = j;
                }
                
                break;
            }
        }
    }
    
    return frame;
}

void Optimum::updateFrame(int framePosition) {
    this->frames[framePosition] = this->pags[0];
}
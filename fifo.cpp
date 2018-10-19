#include "fifo.hpp"

Fifo::Fifo(std::vector<int> pages, int numQuadros):
IAlgorithm(pages, numQuadros),
lastFrame(0)
{
    for(auto p: pages) {
        pagesQueue.push(p);
    }

    while(!pagesQueue.empty()){
        if (!pageOnRam(pagesQueue.front())) {
            pageFault++;
            updateFrames(pagesQueue.front());
            pagesQueue.pop();
        } else {
            pagesQueue.pop();
        }
    }
    std::cout << "FIFO " << pageFault << "\n";
}

void Fifo::updateFrames(int page) {
        if (lastFrame == frames.size())
            lastFrame = 0;

        frames[lastFrame] = page;
        lastFrame++;
    }
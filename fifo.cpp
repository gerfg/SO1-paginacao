#include "fifo.hpp"

Fifo::Fifo(std::vector<int> pages, int numQuadros):
IAlgorithm(pages, numQuadros),
lastFrame(0)
{
    std::cout << frames.size() << "\n";
    
    for(auto p: pages) {
        pagesQueue.push(p);
        std::cout << p << " ";
    }
    std::cout << "\nfront Queue: " << pagesQueue.front() << "\n";

    while(!pagesQueue.empty()){
        if (!pageOnRam(pagesQueue.front())) {
            std::cout << "Pagina não está na RAM\n";
            pageFault++;
            updateFrames(pagesQueue.front());
            showFrames();
            pagesQueue.pop();
        } else {
            std::cout << "Página está na RAM\n";
            pagesQueue.pop();
        }
    }
    std::cout << pageFault << "\n";
}

void Fifo::updateFrames(int page) {
        if (lastFrame == frames.size())
            lastFrame = 0;

        frames[lastFrame] = page;
        lastFrame++;
    }
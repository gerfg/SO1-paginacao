#include "fifo.hpp"

Fifo::Fifo(std::vector<int> pages, int numQuadros):
IAlgorithm(pages, numQuadros)
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

bool Fifo::pageOnRam(int page) {
    for(auto&& fr : frames) {
        if (fr == page) {
            return true;
        }
    }
    return false;
}

void Fifo::updateFrames(int page) {
    
    if (lastFrame == frames.size())
        lastFrame = 0;

    frames[lastFrame] = page;
    lastFrame++;
}
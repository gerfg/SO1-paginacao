#ifndef FIFO_HPP
#define FIFO_HPP

#include "ia.hpp"

#include <iostream>
#include <string>
#include <queue>

class Fifo : public IAlgorithm {
private:
    std::queue<int> pagesQueue;
    unsigned int lastFrame;

    void updateFrames(int page);
public:
    Fifo(std::vector<int> pages, int numQuadros);
};

#endif
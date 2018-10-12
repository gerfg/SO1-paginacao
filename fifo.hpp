#ifndef FIFO_HPP
#define FIFO_HPP

#include "ia.hpp"

#include <iostream>
#include <string>

class Fifo : public IAlgorithm {
public:
    Fifo(std::queue<int> pages, int numQuadros);
};

#endif
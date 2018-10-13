#ifndef OPTIMUM_HPP
#define OPTIMUM_HPP

#include "ia.hpp"

class Optimum : public IAlgorithm {

std::vector<int> pags;

int willNotBeRecentlyAccessed();

void updateFrame(int framePosition);

public:
    Optimum(std::vector<int> pages, int framesCount);
};

#endif
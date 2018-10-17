#ifndef LRU_HPP
#define LRU_HPP

#include "ia.hpp"

class LRU : public IAlgorithm {

std::vector<int> pags;
int positionToStartTheSearch;

int leastRecentlyAccessed();

void updateFrame(int framePosition);

public:
    LRU(std::vector<int> pages, int framesCount);
};

#endif
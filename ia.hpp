#ifndef IALGORITHM_HPP
#define IALGORITHM_HPP

#include <vector>
#include <queue>

class IAlgorithm {
protected:
    std::queue<int> paginas;
    std::vector<int> quadros;

    int faltaDePaginas;

protected:
    IAlgorithm(std::queue<int> paginas):
    paginas(paginas),
    faltaDePaginas(0)
    {};
};

#endif
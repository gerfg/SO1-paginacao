#include <iostream>
#include "fifo.hpp"
#include "optimum.hpp"
#include "lru.hpp"
#include "util.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cout << "Faltando Instancia\n./paginas instances/instance/.txt\n";
        return 0;
    }

    int numQuadros;
    std::vector<int> paginas = readInstance(argv[1], &numQuadros);

    // Fifo f(paginas, numQuadros);
    // Optimum op(paginas, numQuadros);
    LRU lru(paginas, numQuadros);
    
    return 0;
}

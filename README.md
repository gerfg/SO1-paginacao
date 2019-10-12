# Algoritmos de Paginação

Implementação em C++ de três algoritmos de paginação de sistemas operacionais para a disciplina de S01 - Sistemas Operacionais I. Dentre muitos algoritmos, os três selecionados pelo professor foram: FIFO, Ótimo de LRU.

### Algoritmos
#### FIFO

SO mantém uma fila de páginas na memória, em que, a página mais antiga esta no início da fila e a mais nova no fim da fila. Ao ocorrer uma falta de página, a página mais antiga, no início da fila, será removida e a página requerida será colocada no final da fila.

#### Ótimo

Cada página receberá um número representando a chance dela ser solicitada durante a execução de algum processo, sendo assim, as páginas com menos chances de serem referenciadas serão removidas da memória.
Este algoritmo é impossível de ser implementado, pois, não há como saber exatamente esse valor de possibilidade de ser referenciada de uma página. Ele é apenas usado para comparação e simulação com outros algoritmos.

#### LRU

Páginas que foram referenciadas muitas vezes tem mais chance de serem utilizadas novamente, logo, terão prioridade para permanecer na memória. Cada página terá um número referente as vezes que foi referenciada, logo, ao ocorrer uma falta de página, removeremos a com menor valor de vezes referenciada.

### Build e Utilização

#### Build
```shell
$ make
$ ./paginacao [instancia]
```

#### Utilização

O número referente a cada algoritmo representa o número de faltas de página da mesma instância em cada algoritmo.

```shell
$ ./paginacao instances/inst02
FIFO 15
OTM 9
LRU 14
```

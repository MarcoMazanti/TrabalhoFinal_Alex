#ifndef MEDIALOCALIDADE_H
#define MEDIALOCALIDADE_H

typedef struct {
    char location[50];
    int totalValor;
    int totalTransacoes;
} CidadeInfo;

void calcularMediaLocalidade();

#endif
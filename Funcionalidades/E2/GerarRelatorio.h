#ifndef GERARRELATORIO_H
#define GERARRELATORIO_H

typedef struct {
    char domain[50];
    int min_value;
    int max_value;
} IndicadorDominio;

void gerarRelatorio();

#endif
#include <stdio.h>
#include "../../include/modelRecord.h"
#include "GerarRelatorio.h"

#include <string.h>

#define MAX_DOMINIO 100

void gerarRelatorio() {
    Record r;

    FILE *fp = fopen("../bin/bankdataset.dat", "rb");
    FILE *out = fopen("../data/relatorio.txt", "w");

    IndicadorDominio dominio[MAX_DOMINIO];
    int dominioIndex = 0;
    int total = 0;
    int totalValor = 0;
    int totalTransacao = 0;

    if (!fp || !out) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while (fread(&r, sizeof(Record), 1, fp) == 1) {
        total++;
        totalValor += r.value;
        totalTransacao += r.transaction_count;

        int achou = 0;

        for (int i = 0; i < dominioIndex; i++) {
            if (strcmp(dominio[i].domain, r.domain) == 0) {
                if (r.value > dominio[i].max_value) dominio[i].max_value = r.value;
                if (r.value < dominio[i].min_value) dominio[i].min_value = r.value;
                achou = 1;
                break;
            }
        }

        if (!achou) {
            strcpy(dominio[dominioIndex].domain, r.domain);
            dominio[dominioIndex].max_value = dominio[dominioIndex].min_value = r.value;
            dominioIndex++;
        }
    }

    fprintf(out, "===== Relatorio Consolidado =====\n\n");
    fprintf(out, "Total de registros: %d\n", total);
    fprintf(out, "Valor total movimentado: R$ %d\n", totalValor);
    fprintf(out, "Total de transacoes: %d\n\n", totalTransacao);
    fprintf(out, "Valores por dominio:\n");

    for (int i = 0; i < dominioIndex; i++) {
        fprintf(out, "%-13s -> Maior: %d | Menor: %d\n", dominio[i].domain, dominio[i].max_value, dominio[i].min_value);
    }

    fclose(out);
    fclose(fp);

    printf("Relatorio gerado com sucesso.\n");
}
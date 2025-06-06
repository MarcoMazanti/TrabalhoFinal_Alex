#include <stdio.h>
#include <string.h>
#include "SomaDominio.h"
#include "../modelRecord.h"

#define MAX_DOMINIOS 100

void somaDominio() {
    Record r;

    FILE *fp = fopen("../bankdataset.dat", "rb");

    if (fp) {
        int quantDominios = 0;
        TotalTransacoesDominio totalDominios[MAX_DOMINIOS];
        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            int encontrado = 0;

            for (int i = 0; i < quantDominios; i++) {
                if (strcmp(totalDominios[i].domain, r.domain) == 0) {
                    totalDominios[i].totalTransacoes += r.transaction_count;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado && quantDominios < MAX_DOMINIOS) {
                strcpy(totalDominios[quantDominios].domain, r.domain);
                totalDominios[quantDominios].totalTransacoes = r.transaction_count;
                quantDominios++;
            }
        }

        fclose(fp);

        FILE *out = fopen("../resumo_transacoes.txt", "w");

        if (out) {
            fprintf(out, "+---------------+----------------------+\n");
            fprintf(out, "| Dominio       | Total de Transacoes  |\n");
            fprintf(out, "+---------------+----------------------+\n");


            printf("+---------------+----------------------+\n");
            printf("| Dominio       | Total de Transacoes  |\n");
            printf("+---------------+----------------------+\n");

            for (int i = 0; i < quantDominios; i++) {
                printf("| %-13s | %20d |\n", totalDominios[i].domain, totalDominios[i].totalTransacoes);

                fprintf(out, "| %-13s | %20d |\n", totalDominios[i].domain, totalDominios[i].totalTransacoes);
            }

            fprintf(out, "+---------------+----------------------+\n");

            printf("+---------------+----------------------+\n");

            fclose(out);
        } else {
            printf("Erro ao abrir arquivo.\n");
        }
    } else {
        printf("Erro ao abrir arquivo.\n");
    }
}
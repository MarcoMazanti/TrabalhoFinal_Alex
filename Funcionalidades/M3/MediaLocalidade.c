#include <stdio.h>
#include <string.h>
#include "../modelRecord.h"
#include "MediaLocalidade.h"

#include <stdlib.h>

#define MAX_LOCALIDADES 100

int compararCidades(const void *a, const void *b) {
    return strcmp(((CidadeInfo *)a)->location, ((CidadeInfo *)b)->location);
}

void calcularMediaLocalidade() {
    Record r;
    int quantCidades = 0;
    CidadeInfo totalLocalidade[MAX_LOCALIDADES];

    FILE *fp = fopen("../bankdataset.dat", "rb");

    if (fp) {
        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            int encontrado = 0;

            for (int i = 0; i < quantCidades; i++) {
                if (strcmp(totalLocalidade[i].location, r.location) == 0) {
                    totalLocalidade[i].totalTransacoes = r.transaction_count;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado && quantCidades < MAX_LOCALIDADES) {
                strcpy(totalLocalidade[quantCidades].location, r.location);
                totalLocalidade[quantCidades].totalTransacoes = r.transaction_count;
                totalLocalidade[quantCidades].totalValor = r.value;
                quantCidades++;
            }
        }

        fclose(fp);

        qsort(totalLocalidade, quantCidades, sizeof(CidadeInfo), compararCidades);

        FILE *out = fopen("../media_por_localidade.txt", "w");

        if (out) {
            printf("+---------------------+------------+\n");
            printf("| Localidade          | Media (R$) |\n");
            printf("+---------------------+------------+\n");

            fprintf(out, "Localidade,Media\n");

            for (int i = 0; i < quantCidades; i++) {
                double media = (double)totalLocalidade[i].totalValor / totalLocalidade[i].totalTransacoes;

                printf("| %-19s | %10.2f |\n", totalLocalidade[i].location, media);

                fprintf(out, "%s,%.2f\n", totalLocalidade[i].location, media);
            }

            printf("+---------------------+------------+\n");

            fclose(out);
        } else {
            printf("Erro ao abrir o arquivo.\n");
        }
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}
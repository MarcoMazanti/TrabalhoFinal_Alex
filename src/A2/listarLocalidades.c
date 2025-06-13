#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/modelRecord.h"
#include "listarLocalidades.h"

#define MAX_LOCALIDADES 500

int compareLocations(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int contem(char localidades[][50], int n, char *nova) {
    for (int i = 0; i < n; i++) {
        if (strcmp(localidades[i], nova) == 0) return 1;
    }
    return 0;
}

void listarLocalidades() {
    Record r;
    char localidades[MAX_LOCALIDADES][50];

    FILE *fp = fopen("../bin/bankdataset.dat", "rb");
    FILE *out = fopen("../data/localidades_ordenadas.txt", "w");

    if (fp && out) {
        int quant = 0;
        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            if (!contem(localidades, quant, r.location)) {
                strcpy(localidades[quant++], r.location);
            }
        }

        fclose(fp);

        qsort(localidades, quant, 50, compareLocations);

        printf("Lista de Localidades Distintas (Ordenadas):\n");
        printf("------------------------------------------\n");

        for (int i = 0; i < quant; i++) {
            printf("%s\n", localidades[i]);
            fprintf(out, "%s\n", localidades[i]);
        }

        fclose(out);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}
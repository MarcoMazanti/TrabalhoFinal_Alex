#include <stdio.h>
#include "../modelRecord.h"
#include "ExportarRegistros.h"

#include <stdlib.h>
#include <string.h>

void exportarRegistros() {
    char data[50];
    Record r;

    printf("Digite a data para filtrar(DD/MM/AAAA): ");
    scanf("%s", data);

    char dataConvertida[50];
    snprintf(dataConvertida, sizeof(dataConvertida), "../export_%.4s_%.2s_%.2s.csv", data + 6, data + 3, data);

    FILE *fp = fopen("../bankdataset.dat", "rb");
    FILE *csv = fopen(dataConvertida, "w");

    if (fp && csv) {
        fprintf(csv, "date,domain,location,value,transaction_count\n");

        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            char dataInicial[50];
            strcpy(dataInicial, r.date);

            char *dia = strtok(dataInicial, "/");
            char *mes = strtok(NULL, "/");
            char *ano = strtok(NULL, "/");

            char dataFormatada[50];
            snprintf(dataFormatada, sizeof(dataFormatada), "%02d/%02d/%s", atoi(dia), atoi(mes), ano);

            if (strcmp(dataFormatada, data) == 0) {
                fprintf(csv, "%s,%s,%s,%d,%d\n", dataFormatada, r.domain, r.location, r.value, r.transaction_count);
            }
        }

        fclose(fp);
        fclose(csv);

        printf("Arquivo \"%s\" exportado com sucesso!\n", dataConvertida + 3);
    } else {
        printf("Erro ao abrir arquivo.\n");
    }
}

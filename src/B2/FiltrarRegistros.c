#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "FiltrarRegistros.h"


#include "../../include/modelRecord.h"

void filtrarRegistros() {
    char nome[50];
    int count = 0;
    printf("Digite qual dominio deseja filtrar: ");
    scanf("%s", nome);

    FILE *fp = fopen("../bin/bankdataset.dat", "rb");
    Record r;

    for (int i = 0; i < strlen(nome); i++) {
        nome[i] = toupper(nome[i]);
    }

    char nomeSaida[100];
    sprintf(nomeSaida, "../data/filtro_dominio_%s.txt", nome);

    FILE *out = fopen(nomeSaida, "w");

    if (fp && out) {
        fprintf(out, "+--------------------------------------------------------------------+\n");
        fprintf(out, "| Data      | Dominio       | Localidade      | Valor   | Transacoes |\n");
        fprintf(out, "+--------------------------------------------------------------------+\n");

        printf("+--------------------------------------------------------------------+\n");
        printf("| Data      | Dominio       | Localidade      | Valor   | Transacoes |\n");
        printf("+--------------------------------------------------------------------+\n");

        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            if (strcmp(r.domain, nome) == 0) {
                if (count < 100) {
                    printf("| %-9s | %-13s | %-15s | %7d | %10d |\n", r.date, r.domain, r.location, r.transaction_count, r.value);

                    if (count == 99) {
                        printf("+--------------------------------------------------------------------+\n");
                    }
                }

                fprintf(out, "| %-9s | %-13s | %-15s | %7d | %10d |\n", r.date, r.domain, r.location, r.transaction_count, r.value);
                count++;
            }
        }

        fprintf(out, "+---------------------------------------------------------------------+\n");

        fclose(fp);
        fclose(out);
    } else {
        printf("erro ao abrir o arquivo.\n");
    }
}
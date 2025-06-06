#include <stdio.h>
#include "ListarRegistros.h"
#include "../modelRecord.h"

void listarRegistros() {
    FILE *fp = fopen("../bankdataset.dat", "rb");
    Record r;
    FILE *txt = fopen("../relatorio_registros.txt", "w");

    if (fp && txt) {
        int count = 0;
        fprintf(txt, "+--------------------------------------------------------------------+\n");
        fprintf(txt, "| Data      | Dominio       | Localidade      | Valor   | Transacoes |\n");
        fprintf(txt, "+--------------------------------------------------------------------+\n");


        printf("+--------------------------------------------------------------------+\n");
        printf("| Data      | Dominio       | Localidade      | Valor   | Transacoes |\n");
        printf("+--------------------------------------------------------------------+\n");

        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            if (count < 100) {
                printf("| %-9s | %-13s | %-15s | %7d | %10d |\n", r.date, r.domain, r.location, r.value, r.transaction_count);

                if (count == 99) {
                    printf("+--------------------------------------------------------------------+\n");
                }
            }
            fprintf(txt, "| %-9s | %-13s | %-15s | %7d | %10d |\n", r.date, r.domain, r.location, r.value, r.transaction_count);
            count++;
        }
        fprintf(txt, "+---------------------------------------------------------------------+\n");

        fclose(fp);
        fclose(txt);
    } else {
        printf("erro ao abrir o arquivo.\n");
    }
}
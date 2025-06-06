#include <stdio.h>
#include "../modelRecord.h"
#include "NovoRegistro.h"

#include <ctype.h>

void novoRegistro() {
    Record r;

    FILE *fp = fopen("../bankdataset.dat", "ab");

    if (!fp) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("Digite a data (DD/MM/AAAA): ");
    scanf("%s", r.date);

    printf("Digite o dominio: ");
    scanf("%s", r.domain);

    for (int i = 0; i < sizeof(r.domain); i++) {
        r.domain[i] = toupper(r.domain[i]);
    }

    printf("Digite a localidade: ");
    scanf("%s", r.location);

    do {
        printf("Digite o valor: ");
        scanf("%d", &r.value);
    } while (r.value <= 0);

    do {
        printf("Digite o numero de transacoes: ");
        scanf("%d", &r.transaction_count);
    } while (r.transaction_count <= 0);

    fwrite(&r, sizeof(Record), 1, fp);
    fclose(fp);

    printf("Registro adicionado com sucesso.\n");
}

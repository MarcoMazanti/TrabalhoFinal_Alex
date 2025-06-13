#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/modelRecord.h"
#include "BuscaRegistro.h"

int compareByValue(const void *a, const void *b) {
    return ((Record *)a)->value - ((Record *)b)->value;
}

void buscarPorValorSequencial(int valorBusca) {
    Record r;

    FILE *fp = fopen("../bin/bankdataset.dat", "rb");
    FILE *out = fopen("../data/busca_valor_sequencial.txt", "w");

    if (fp && out) {
        printf("=== Registro da Busca ===");
        while (fread(&r, sizeof(Record), 1, fp) == 1) {
            if (r.value == valorBusca) {
                printf("Data: %s\n", r.date);
                printf("Dominio: %s\n", r.domain);
                printf("Localidade: %s\n", r.location);
                printf("Valor: %d\n", r.value);
                printf("Transacoes: %d\n", r.transaction_count);
                printf("---------------------------\n");

                fprintf(out, "%s,%s,%s,%d,%d\n", r.date, r.domain, r.location, r.value, r.transaction_count);
            }
        }

        fclose(fp);
        fclose(out);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void buscarPorValorBinaria(int ValorBusca) {
    FILE *fp = fopen("../bin/bankdataset.dat", "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    int total = size / sizeof(Record);
    Record *vetor = malloc(size);
    fread(vetor, sizeof(Record), total, fp);
    fclose(fp);

    qsort(vetor, total, sizeof(Record), compareByValue);

    Record chave;
    chave.value = ValorBusca;

    Record *encontrado = bsearch(&chave, vetor, total, sizeof(Record), compareByValue);
    if (encontrado) {
        FILE *out = fopen("../data/busca_valor_sequencial.txt", "w");

        if (out) {
            printf("Data: %s\n", encontrado->date);
            printf("Dominio: %s\n", encontrado->domain);
            printf("Localidade: %s\n", encontrado->location);
            printf("Valor: %d\n", encontrado->value);
            printf("Transacoes: %d\n", encontrado->transaction_count);
            printf("---------------------------\n");

            fprintf(out, "%s,%s,%s,%d,%d\n", encontrado->date, encontrado->domain, encontrado->location, encontrado->value, encontrado->transaction_count);

            fclose(out);
        } else {
            printf("Erro ao abrir o arquivo.\n");
        }
    } else {
        printf("Valor nao encontrado.\n");
    }

    free(vetor);
}

void buscaRegistro() {
    char escolha[50];
    int valor;

    printf("digite como deseja procurar o valor(SEQUENCIAL/BINARIA): ");
    scanf("%s", escolha);

    printf("Digite o valor de busca: ");
    scanf("%d", &valor);

    if (strcasecmp(escolha, "SEQUENCIAL") == 0) {
        buscarPorValorSequencial(valor);
    } else if (strcasecmp(escolha, "BINARIA") == 0) {
        buscarPorValorBinaria(valor);
    }
}
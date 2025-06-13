#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "include/funcionalidades.h"

int main(void) {
    char resposta[2];

    do {
        printf("=========== MENU PRINCIPAL ===========\n");
        printf("[B1] Listar todos os registros\n");
        printf("[B2] Filtrar registros por dominio\n");
        printf("[M1] Somar total de transacoes por dominio\n");
        printf("[M2] Exportar registros por data\n");
        printf("[M3] Calcular media por localidade\n");
        printf("[A1] Buscar registro por valor (seq/bin)\n");
        printf("[A2] Listar localidades distintas ordenadas\n");
        printf("[E1] Inserir novo registro no arquivo\n");
        printf("[E2] Gerar relatorio consolidado\n");
        printf("[0] Sair do programa\n");
        printf("======================================\n");
        printf("Digite sua opcao: ");
        scanf("%s", resposta);

        if (strcasecmp(resposta, "B1") == 0) {
            listarRegistros();
        } else if (strcasecmp(resposta, "B2") == 0) {
            filtrarRegistros();
        } else if (strcasecmp(resposta, "M1") == 0) {
            somaDominio();
        } else if (strcasecmp(resposta, "M2") == 0) {
            exportarRegistros();
        } else if (strcasecmp(resposta, "M3") == 0) {
            calcularMediaLocalidade();
        } else if (strcasecmp(resposta, "A1") == 0) {
            buscaRegistro();
        } else if (strcasecmp(resposta, "A2") == 0) {
            listarLocalidades();
        } else if (strcasecmp(resposta, "E1") == 0) {
            novoRegistro();
        } else if (strcasecmp(resposta, "E2") == 0) {
            gerarRelatorio();
        } else {
            printf("Saindo do Programa!\n");
            break;
        }

        printf("\nAperte ENTER para voltar ao menu!\n");
        for (int i = 0;; i++) {
            if (_kbhit()) {
                if (getch() == 13) {
                    break;
                }
            }
        }

    } while (resposta[0] != '0');
    return  0;
}
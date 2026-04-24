#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas.h"
#include "funcoes.h"

int main() {

    ListaEstudantes lista;
    inicializar(&lista);

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir estudante\n");
        printf("2. Listar estudantes\n");
        printf("3. Remover estudante\n");
        printf("4. Consultar estudante\n");
        printf("5. Listar por nome da disciplina\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

        case 1: {
            Estudante e;

            printf("Numero do estudante: ");
            scanf("%d", &e.Numero_estudante);

            printf("Nome: ");
            scanf(" %[^\n]", e.nome);

            printf("Ano de frequencia: ");
            scanf("%d", &e.Ano_frequencia);

            inicializarCadeiras(&e);

            int qtd;
            printf("Quantas cadeiras deseja inserir? ");
            scanf("%d", &qtd);

            char nome_cadeira[30];

            for(int i = 0; i < qtd; i++) {
                printf("Nome da cadeira %d: ", i + 1);
                scanf(" %[^\n]", nome_cadeira);

                adicionarCadeira(&e, nome_cadeira);
            }

            inserir(&lista, e);
            break;
        }

        case 2:
            listar(&lista);
            break;

        case 3: {
            int numero;
            printf("Numero do estudante a remover: ");
            scanf("%d", &numero);
            remover(&lista, numero);
            break;
        }

        case 4: {
            int numero;
            printf("Numero do estudante a consultar: ");
            scanf("%d", &numero);
            consultar(&lista, numero);
            break;
        }

        case 5: {
            char disciplina[30];

            printf("Nome da disciplina: ");
            scanf(" %[^\n]", disciplina);

            listarPorNomeCadeiras(&lista, disciplina);
            break;
        }

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida\n");
        }

    } while(opcao != 0);

    liberar(&lista);
    return 0;
}
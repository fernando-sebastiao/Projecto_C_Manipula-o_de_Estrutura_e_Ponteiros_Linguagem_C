#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas.h"
#include "funcoes.h"

int main() {

    ListaEstudantes lista;
    inicializar(&lista);

    int opcao, i;

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
            int statusInt;
            printf("Quantas cadeiras deseja inserir? ");
            scanf("%d", &qtd);

            char nome_cadeira[30];

            for(i = 0; i < qtd; i++) {
                printf("Nome da cadeira %d: ", i + 1);
                scanf(" %[^\n]", nome_cadeira);

                 printf("Status (0=NAO_INSCRITO, 1=INSCRITO, 2=APROVADO, 3=REPROVADO): ");
                 scanf("%d", &statusInt);
                 adicionarCadeira(&e, nome_cadeira, (StatusCadeira)statusInt);
            }

            inserir(&lista, e);
            system("cls");
            break;
        }

        case 2:
        	system("cls");
            listar(&lista);
            break;

        case 3: {
        	system("cls");
            int numero;
            printf("Numero do estudante a remover: ");
            scanf("%d", &numero);
            remover(&lista, numero);
            break;
        }

        case 4: {
        	system("cls");
            int numero;
            printf("Numero do estudante a consultar: ");
            scanf("%d", &numero);
            consultar(&lista, numero);
            break;
        }

        case 5: {
        	system("cls");
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

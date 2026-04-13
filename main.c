#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "funcoes.h"
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Estudante *estudante;
	 ListaEstudantes lista;
    inicializar(&lista);

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir estudante\n");
        printf("2. Listar estudantes\n");
        printf("3. Remover estudante\n");
        printf("4. Consultar estudante\n");
        printf("5. Listar por numero de cadeiras\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1: {
        	system("cls");
            Estudante e;

            printf("Insira os dados do Aluno(a):\n");

            printf("Numero do estudante: ");
            scanf("%d", &e.Numero_estudante);

            printf("Nome: ");
            scanf(" %[^\n]", e.nome);

            printf("Ano de frequencia: ");
            scanf("%d", &e.Ano_frequencia);

            printf("Numero de cadeiras: ");
            scanf("%d", &e.Num_cadeiras);

            inserir(&lista, e);
            system("cls");
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
            printf("\n\n");
            break;
        }

        case 5: {
            int cadeiras;
            printf("Numero de cadeiras: ");
            scanf("%d", &cadeiras);
            listarPorCadeiras(&lista, cadeiras);
            printf("\n\n");
            break;
        }

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    liberar(&lista);
	return 0;
}

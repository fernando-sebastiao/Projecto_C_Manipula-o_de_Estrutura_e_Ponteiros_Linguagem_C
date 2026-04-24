#include "Estruturas.h"
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

void inicializar(ListaEstudantes *lista){
	lista->capacidade = 2;
	lista->tamanho = 0;
	lista->dados = malloc(lista->capacidade * sizeof(Estudante));
}

void inicializarCadeiras(Estudante *e)
{
	e->cap_cadeiras = 2;
	e->num_cadeiras = 0;
	e->cadeiras = malloc(e->cap_cadeiras * sizeof(Cadeira));
}

void adicionarCadeira(Estudante *e, char *nome_cadeira)
{
	if(e->num_cadeiras == e->cap_cadeiras)
	{
		e->cap_cadeiras *= 2;
		Cadeira *temp = realloc(e->cadeiras, e->cap_cadeiras * sizeof(Cadeira));
		if(temp != NULL)
			e->cadeiras = temp;
		else
			printf("Erro ao realocar memoria\n");
	}
	
	strcpy(e->cadeiras[e->num_cadeiras].nome, nome_cadeira);
	e->num_cadeiras++;
}

void aumentarCapacidade(ListaEstudantes *lista)
{
	
	lista->capacidade *=2;
	
	Estudante *temp = realloc(lista->dados, lista->capacidade * sizeof(Estudante));
	if(temp != NULL)
		lista->dados = temp; 
	else 
		printf("Erro ao realocar memoria\n");
}

void inserir(ListaEstudantes *lista, Estudante e){
	
	if(lista->tamanho == lista->capacidade)
	{
		aumentarCapacidade(lista);
	}
	
	lista->dados[lista->tamanho] = e;
	lista->tamanho++;
}

void listar(ListaEstudantes *lista)
{
	int i, j;
	for(i=0; i< lista->tamanho; i++)
	{
		Estudante e = lista->dados[i];
		printf("Numero: %d | Nome: %s | Ano: %d | Cadeiras: %d\n",
            lista->dados[i].Numero_estudante,
            lista->dados[i].nome,
            lista->dados[i].Ano_frequencia
		);
		printf("Cadeiras: \n");
		for(j=0; j < e.num_cadeiras; j++)
		{
			printf(" - %s\n", e.cadeiras[j].nome);
		}
		printf("\n");
	}
}

void remover(ListaEstudantes *lista, int numero){
	int i, j;
	for(i = 0; i < lista->tamanho; i++)
	{
		if(lista->dados[i].Numero_estudante == numero){
			free(lista->dados[i].cadeiras);
			for(j = i; j < lista->tamanho-1;j++)
			{
				lista->dados[j] = lista->dados[j+1];
			}
			lista->tamanho--;
			printf("Estudante removido com sucesso\n");
			return;
		}
	}
	
	printf("Estudante nao encontrado\n");
}

void consultar(ListaEstudantes *lista, int numero)
{
	int i, j;
	for(i = 0; i < lista->tamanho; i++)
	{
		if(lista->dados[i].Numero_estudante == numero)
		{
		Estudante e = lista->dados[i];	
			printf("Encontrado: \n");
            printf("Nome: %s | Ano: %d | Cadeiras: %d\n",
                lista->dados[i].nome,
                lista->dados[i].Ano_frequencia,
                lista->dados[i].Num_cadeiras);
			printf("Cadeiras: \n");
			for(j=0; j < e.num_cadeiras; j++)
			{
				printf(" - %s\n", e.cadeiras[j].nome);
			}

            return;
		}
	}
	
	printf("Estudante nao encontrado\n");
}

void listarPorNomeCadeiras(ListaEstudantes *lista, char *nome_cadeira)
{
    int i, j;

    for(i = 0; i < lista->tamanho; i++)
    {
        Estudante e = lista->dados[i];

        for(j = 0; j < e.num_cadeiras; j++)
        {
            if(strcmp(e.cadeiras[j].nome, nome_cadeira) == 0)
            {
                printf("Numero: %d | Nome: %s | Ano: %d | Total Cadeiras: %d\n",
                    e.Numero_estudante,
                    e.nome,
                    e.Ano_frequencia,
                    e.num_cadeiras);

                break; 
            }
        }
    }
}

void liberar(ListaEstudantes *lista) {
	int i;
    for(i = 0; i < lista->tamanho; i++) {
        free(lista->dados[i].cadeiras);
    }
    free(lista->dados);
}

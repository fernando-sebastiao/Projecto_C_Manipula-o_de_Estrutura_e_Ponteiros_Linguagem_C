#include "Estruturas.h"
#include<stdlib.h>
#include <stdio.h>


void inicializar(ListaEstudantes *lista){
	lista->capacidade = 2;
	lista->tamanho = 0;
	lista->dados = malloc(lista->capacidade * sizeof(Estudante));
}

void aumentarCapacidade(ListaEstudantes *lista)
{
	
	lista->capacidade *=2;
	
	Estudante *temp = realloc(lista->dados, lista->capacidade * sizeof(Estudante));
	if(temp == NULL)
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
	int i;
	for(i=0; i< lista->tamanho; i++)
	{
		printf("Numero: %d | Nome: %s | Ano: %d | Cadeiras: %d\n",
            lista->dados[i].Numero_estudante,
            lista->dados[i].nome,
            lista->dados[i].Ano_frequencia,
            lista->dados[i].Num_cadeiras);	
	}
}

void remover(ListaEstudantes *lista, int numero){
	int i, j;
	for(i = 0; i < lista->tamanho; i++)
	{
		if(lista->dados[i].Numero_estudante == numero){
			
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
	int i;
	for(i = 0; i < lista->tamanho; i++)
	{
		if(lista->dados[i].Numero_estudante == numero)
		{
			printf("Encontrado: \n");
			
			printf("Encontrado:\n");
            printf("Nome: %s | Ano: %d | Cadeiras: %d\n",
                lista->dados[i].nome,
                lista->dados[i].Ano_frequencia,
                lista->dados[i].Num_cadeiras);

            return;
		}
	}
	
	printf("Estudante nao encontrado\n");
}

void listarPorCadeiras(ListaEstudantes *lista, int cadeiras)
{
	int i;
	for(i=0; i < lista->tamanho;i++)
	{
		if(lista->dados[i].Num_cadeiras == cadeiras)
		{
			printf("Nome: %s | Ano: %d | Cadeiras: %d\n",
                lista->dados[i].nome,
                lista->dados[i].Ano_frequencia,
                lista->dados[i].Num_cadeiras);
		}
	}
}

void liberar(ListaEstudantes *lista) {
    free(lista->dados);
}

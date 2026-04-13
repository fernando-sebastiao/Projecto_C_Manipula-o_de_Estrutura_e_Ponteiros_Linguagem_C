
typedef struct
{
	int Numero_estudante;
	int Num_cadeiras;
	int Ano_frequencia;
	char nome[20];
} Estudante;


typedef struct {
    Estudante *dados;
    int tamanho;
    int capacidade;
} ListaEstudantes;

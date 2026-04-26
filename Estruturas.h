
typedef struct
{
	char nome[20];
	StatusCadeira status;
}Cadeira;

typedef enum {
    NAO_INSCRITO,
    INSCRITO,
    APROVADO,
    REPROVADO
} StatusCadeira;

typedef struct
{
	int Numero_estudante;
	int Num_cadeiras;
	int Ano_frequencia;
	char nome[20];

	Cadeira *cadeiras;
	int num_cadeiras;
	int cap_cadeiras;
} Estudante;


typedef struct {
    Estudante *dados;
    int tamanho;
    int capacidade;
} ListaEstudantes;

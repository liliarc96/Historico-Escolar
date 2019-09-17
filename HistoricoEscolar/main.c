#include <stdio.h>
#include <string.h>
#define	MAX 60
// Tipo base dos elementos da MoldeLista
typedef struct AlunoElementos {
    char nome[50];
    char disciplina[50];
    int matricula;
    float nota;
    // Outros elementos
} aluno_elemento;

// Estrutura da MoldeLista
typedef struct MoldeLista {
    aluno_elemento vetor[MAX];//vet que armazena elemento. da pilha
    int indiceLista; // posicao (indice) do ultimo elemento da MoldeLista
} t_lista; // tipo MoldeLista

/**
 * Cria uma nova MoldeLista, inicializa o indiceLista, e retorna o registro.
 *
 * @return Lista inicializada
 */

t_lista criar() {
    t_lista MoldeLista;

    MoldeLista.indiceLista = -1;

    return MoldeLista;
}

/**
 * Desloca os elementos da MoldeLista para a direita a partir de posicao
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 * @param posicao   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return Falso(0) se a posição for invalida ou se a MoldeLista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */

int deslocaDireita(t_lista * MoldeLista, int posicao) {
    int i;

    for (i=MoldeLista->indiceLista + 1; i>posicao; i--)
        MoldeLista->vetor[i] = MoldeLista->vetor[i-1];

    return 1;
}

/**
 * Verifica se a MoldeLista esta cheia ou nao.
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a MoldeLista estiver cheia, ou falso (0) caso contrario.
 */

int isCheia(t_lista * MoldeLista) {
    return (MoldeLista->indiceLista == MAX-1);
}

/**
 * Insere um elemento (dado) em determinada posicao da MoldeLista.
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 * @param posicao   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 * @param dado  elemento a ser inserido
 *
 * @return Falso(0) se a posição for invalida ou se a MoldeLista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */

int inserir (t_lista * MoldeLista, int posicao, aluno_elemento dado) {
    if ( isCheia(MoldeLista) || (posicao > MoldeLista->indiceLista + 1) || (posicao < 0) )
        return 0;

    deslocaDireita(MoldeLista, posicao);
    MoldeLista->vetor[posicao] = dado;
    (MoldeLista->indiceLista)++;
    return 1;
}

/**
 * Obtem a posicao de um elemento, a partir de seu valor.
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 * @param dado  aluno_elemento a ser buscado na MoldeLista
 *
 * @return a posicao do elemento, ou -1 se o elemento nao estiver na MoldeLista.
 */
int compara(aluno_elemento dado1, aluno_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}

int getPosicao(t_lista * MoldeLista, aluno_elemento dado) {
    int i;
    for (i=0; i<=MoldeLista->indiceLista; i++)
        if (compara(MoldeLista->vetor[i], dado)==0)
            return i;

    return -1;
}

/**
 * Obtem um elemento da MoldeLista especificado por posicao.
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 * @param posicao   posicao do elemento desejado
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
aluno_elemento * getElemento(t_lista * MoldeLista, int posicao) {
    // verifica se posicao eh valida
    if ( (posicao > MoldeLista->indiceLista) || (posicao < 0) )
        return 0;

    return &(MoldeLista->vetor[posicao]);
}

/**
 * Desloca os elementos da MoldeLista para a esquerda a partir de posicao
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 * @param posicao   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return 0 se a posição for invalida ou se a MoldeLista estiver cheia, caso contrario, retorna 1.
 */
int deslocaEsquerda(t_lista * MoldeLista, int posicao) {
    int i;

    for (i=posicao; i<(MoldeLista->indiceLista); i++)
        MoldeLista->vetor[i] = MoldeLista->vetor[i+1];

    return 1;
}

/**
 * Remove um elemento de determinada posicao da MoldeLista.
 *
 * @param MoldeLista ponteiro para a MoldeLista, a MoldeLista ja deve ter sido inicializada
 * @param posicao   posicao do elemento, a partir do qual sera iniciado o deslocamento.
 *
 * @return Falso(0) se a posição for invalida ou se a MoldeLista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int remover (t_lista *MoldeLista, int posicao) {
    if ( (posicao > MoldeLista -> indiceLista) || (posicao < 0) )
        return 0;

    deslocaEsquerda(MoldeLista, posicao);

    (MoldeLista->indiceLista)--;
    return 1;
}

void mostraLista(t_lista * MoldeLista)
{
	int	i;

	for (i = 0; i <= MoldeLista->indiceLista; i++)
		printf("[%s]\n", MoldeLista->vetor[i].nome);
}

void mostraMenu(){
    printf("ALUNA: Lília Ribeiro Cantalice\n"
           "DISCIPLINA: ESTRUTURA DE DADOS I\n"
           "PROFESSOR: WALLACE BONFIM\n\n"
           "------------------HISTÓRICO ESCOLAR------------------\n\n"
           "1 - INSERIR MATRÍCULAS, DISCIPLINAS E NOTAS\n"
           "2 - EXIBIR HISTÓRICOS\n"
           "0 - SAIR\n\n"
           "DIGITE SUA OPÇÃO: ");
}

int	main()
{
	t_lista listaAluno;
	aluno_elemento	elemento;
	aluno_elemento	* ponteiroElemento;
	int i = 0;
	int opcaoMenu, repeticao = 1;

	// criar MoldeLista
	listaAluno = criar();

	while(repeticao == 1){
        mostraMenu();
        scanf("%d", opcaoMenu);
        switch(opcaoMenu){
        case 1:
            printf("\n--INSERIR MATRÍCULAS, DISCIPLINAS E NOTAS--");

            printf("Digite a matrícula do aluno: \n");
            scanf("%d", &elemento.matricula); //Recebe a matrícula e guarda em listaAluno
            inserir(&listaAluno, i, elemento);

            printf("Digite o nome do aluno: \n");
            scanf("%s", &elemento.nome); //Recebe nome do aluno e guarda em listaAluno
            inserir(&listaAluno, i, elemento);

            printf("Digite o nome da disciclina: \n");
            scanf("%s", &elemento.disciplina); //Recebe nome da disciplina e guarda em listaAluno
            inserir(&listaAluno, i, elemento);

            printf("Digite a nota nessa disciplina: \n");
            scanf("%f", &elemento.nota); //Recebe nota da disciplina e guarda em listaAluno
            inserir(&listaAluno, i, elemento);
            i++;
            break;
        case 2:
            printf("\n--EXIBIR HISTÓRICOS--");

            mostraLista(&listaAluno);
            break;
        case 0:
            printf("\n--SAIR--");

            mostraLista(&listaAluno);
            repeticao = 0;
            break;
        default:
            printf("\n--OPÇÃO INVÁLIDA--");
            break;
        }
	}
/*
	// buscar e mostrar
	printf("\nEscreva um nome para procurar na MoldeLista.");
	scanf("%s", &elemento.nome);

	i = getPosicao(&listaAluno, elemento);

	if ((ponteiroElemento = getElemento(&listaAluno, i)) == NULL)
		printf("Nome não encontrado\n");
	else
		printf("Nome [%s] foi encontrado na posicao [%d]", ponteiroElemento->nome, i);

	if ((i = getPosicao(&listaAluno, elemento)) == -1)
		printf("Nome para remover não encontrado\n");
	else
		remover(&listaAluno, i);

	// mostrar o conteudo
	printf("LISTA FINAL\n");
	mostraLista(&listaAluno);
*/
	return 0;
}

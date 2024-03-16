#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definir Crud
void criar(char *nome, long matricula, char *curso, char *datanasc);

void ler(char *nome);

void atualizar(int posicao, int opcao, char *atualizacao);

void destruir(int posicao);

// Definir Objetos
typedef struct{
    char nome[255];
    long matricula;
    char curso[255];
    char dataNasc[255];
}Aluno;

typedef struct{
    Aluno alunos[100];
    int count;
}ListaDeAlunos;

// Definir funcões ultilitarias
void mostrarCriar();
void mostrarLer();
void mostrarAtualizar();
void mostrarDestruir();

void lerTodos();

void inicializarObjetoLista(ListaDeAlunos *listaParaInicializar);

ListaDeAlunos lista;

int main(){
    inicializarObjetoLista(&lista);

    int opcao;
    
    // Exemplos base
    criar("Gabriel", 31238123, "Ciencia da computacao", "16/12/2005");
    criar("Joao", 907828942, "Engenharia da computacao", "05/03/1999");
    criar("Pedro", 907828942, "Engenharia da computacao", "05/03/1999");

    while(1){
        printf("Selecione uma das Opcoes:");
        printf("\n[1] Ver Alunos");
        printf("\n[2] Adicionar um novo Aluno");
        printf("\n[3] Editar Dados do Aluno");
        printf("\n[4] Deletar Aluno");
        printf("\nSua Opcao: ");
        scanf("%d", &opcao);
        

        switch(opcao){
            case 1:
                mostrarLer();
            break;

            case 2:
                mostrarCriar();
            break;

            case 3:
                mostrarAtualizar();
            break;

            case 4:
                mostrarDestruir();
            break;

            default:
                printf("Opcao Invalida, tente novamente! \n\n");
            break;
        }
    }

    return 1;
}


void ler(char *nome){
    for(int i = 0; i < lista.count; i++){
        if(!strcmp(lista.alunos[i].nome, nome)){
            printf("\nNOME: %s", lista.alunos[i].nome);
            printf("\nMATRICULA: %ld", lista.alunos[i].matricula);
            printf("\nCURSO: %s", lista.alunos[i].curso);
            printf("\nDATA DE NASCIMENTO: %s", lista.alunos[i].dataNasc);
            printf("\n");
        }
    }
}

void criar(char *nome, long matricula, char *curso, char *datanasc){
    Aluno novoAluno;
    strcpy(novoAluno.nome, nome);
    novoAluno.matricula = matricula;
    strcpy(novoAluno.curso, curso);
    strcpy(novoAluno.dataNasc, datanasc);

    lista.alunos[lista.count++] = novoAluno;
}

void atualizar(int posicao, int opcao, char *atualizacao){
    switch (opcao)
    {
    case 1:
        strcpy(lista.alunos[posicao].nome, atualizacao);
        break;
    case 2:
        lista.alunos[posicao].matricula = atol(atualizacao);
        break;
    case 3:
        strcpy(lista.alunos[posicao].curso, atualizacao);
        break;
    case 4:
        strcpy(lista.alunos[posicao].dataNasc, atualizacao);
        break;
    default:
        break;
    }
    printf("\nAtualizacao Feita com Sucesso!\n");
}

void destruir(int posicao){
        
        if(posicao == lista.count - 1){
            lista.count--;
            return;
        }

        for(int i = posicao; i <= lista.count; i++){
            lista.alunos[i] = lista.alunos[i + 1];
        }
        lista.count--;

        printf("\nDeletado com Sucesso!\n");
}


void mostrarLer(){

    char opcao[255] = "";

    printf("\nDigite o nome do Aluno para buscar-lo.");
    printf("\nOu digite [0] para mostrar uma lista de todos os Alunos.");
    printf("\nSua Opcao: ");

    scanf("%s", &opcao);

    if(!strcmp(opcao, "0")){
        lerTodos();
    }
    ler(opcao);

}

void mostrarCriar(){
    char opcao[255] = "";

    char nome[255];

    long matricula;

    char curso[255];

    char dataNasc[255];

    printf("\nDigite o Nome do Aluno: ");
    scanf("%s", &nome);

    printf("\nDigite a Matricula do Aluno: ");
    scanf("%ld", &matricula);

    printf("\nDigite o Curso do Aluno: ");
    scanf("%s", &curso);

    printf("\nDigite a Data de Nascimento do Aluno: ");
    scanf("%s", &dataNasc);

    criar(nome, matricula, curso, dataNasc);

}

void mostrarAtualizar(){
    char nome[255];
    char atualizacao[255];
    int opcao;
    printf("\nDigite o Nome do Aluno que deseja Atualizar: ");
    scanf("%s", &nome);

    for(int i = 0; i < lista.count; i++){
        if(!strcmp(lista.alunos[i].nome, nome)){
            printf("\nO que deseja Atualizar?");
            printf("\n[1] Nome: %s", lista.alunos[i].nome);
            printf("\n[2] Matricula: %ld", lista.alunos[i].matricula);
            printf("\n[3] Curso: %s", lista.alunos[i].curso);
            printf("\n[4] Data de Nascimento: %s", lista.alunos[i].dataNasc);
            printf("\nO que deseja Atualizar?");
            printf("\nSua Opcao: ");
            scanf("%d", &opcao);

            printf("\nDigite a atualizacao: ");
            scanf("%s", &atualizacao);
            atualizar(i, opcao, atualizacao);
            return;
        }
    }
}

void mostrarDestruir(){
    char nome[255];

    printf("\nDigite o nome do Aluno que deseja Deletar: ");
    scanf("%s", nome);
    for(int i = 0; i < lista.count; i++){
        if(!strcmp(lista.alunos[i].nome, nome)){
            destruir(i);
        }
    }
}

void lerTodos(){
    for(int i = 0; i < lista.count; i++){
        printf("[ %s ]\n", lista.alunos[i].nome);
    }
}

void inicializarObjetoLista(ListaDeAlunos *listaParaInicializar){
    listaParaInicializar->count = 0;   
}
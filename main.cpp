

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/*
Uma faculdade precisa organizar os seus dados acadêmicos. O diretor informou as seguintes necessidades iniciais para a construção de um software:
Cadastro de Professores: nome, idade, cpf, telefone, e-mail, formação e endereço;
Cadastro de Aluno: nome, idade, cpf, telefone, email e endereço;
Cadastro de Curso: código e nome;
Cadastro de Disciplina: código, nome, curso, carga horária, professor e alunos;
Cadastro de endereço: logradouro, número, bairro, cidade e estado.
Construa registros para atender as essas necessidades iniciais do diretor, observando os dados de cada item acima e as relações entre eles.

*/

#define TAM 30
using namespace std;

struct Professores {
	int codigo;
	char nome[TAM];
	char idade[TAM];
	char cpf[TAM];
	char telefone[TAM];
	char email[TAM];
	char formacao[TAM];

};

struct Alunos {
	int codigo;
	char nome[TAM];
	char idade[4];
	char cpf[15];
	char telefone[10];
	char email[25];

};

struct Cursos {
	char nome[TAM];
	int codigo;

};

struct Disciplinas {
	int codigo;
	char nome[TAM];
	int carga_horaria[TAM];
	
    
};

struct Enderecos {
	char logradouro[TAM];
	int numero[TAM];
	char bairro[TAM];
	char cidade[TAM];
	char estado[TAM];
};

struct Notas {
	float nota1;
	float nota2;
	int falta;
};

//FUNCAO QUE IMPRIME AS OPCOES DAS FUNCIONALIDADES DO PROGRAMA
void menu(){
    cout << "\n\n\t\t----MENU ----"<<endl;
    cout << "\n\tDigite a opcao: "<<endl;
    cout << "\t1 - Listar cadastros\n";
    cout << "\t2 - Cadastrar aluno(a)\n";
    cout << "\t3 - Exibir aluno(a)\n";
    cout << "\t4 - Buscar aluno(a)\n";
    cout << "\t5 - Excluir aluno(a)\n";
    cout << "\t6 - Sair\n";
}


int cadastraaluno(Alunos aluno[], int qtdalunos){
	

	int Codigoprofessor, Codigocurso, Codigodisclipina;
	cout << "\t\t\nCadastro do aluno(a)" << endl;
	cout << "\tDigite o codigo: ";
	cin  >> aluno[qtdalunos].codigo;
	cout << "\n\tDigite o nome: ";
	cin  >> aluno[qtdalunos].nome;
	cout << "\n\tDigite o CPF: ";
	cin  >> aluno[qtdalunos].cpf;
	cout << "\n\tDigite o idade: ";
	cin  >> aluno[qtdalunos].idade;
	cout << "\n\tDigite o email: ";
	cin  >> aluno[qtdalunos].email;
	cout << "\n\tDigite o telefone: ";
	cin  >> aluno[qtdalunos].telefone;
	
	qtdalunos++;
    return qtdalunos;
	system("cls");
}

int listaalunos(Alunos aluno[], int qtd){
	cout << "\t\t----------- LISTA DE ALUNOS -----------\n";
	for(int i =0; i < qtd; i++){
		cout << "-CODIGO-|-NOME-|-IDADE-|-CPF-|-EMAIL-|-TELEFONE-" << endl;
		cout << aluno[i].codigo << "  |  " << aluno[i].nome << "  |  " << aluno[i].idade << "  |  " << aluno[i].cpf << "  |  " << aluno[i].email << "  |  " << aluno[i].telefone << endl;
	}
	system("pause");
	system("cls");
}

int BuscarAluno(Alunos aluno[], int qtd){
	
	int num = 0;
	cout << "Digite o codigo do aluno: ";
	cin >> num;
	
	for(int i=0; i < qtd; i++){
		
		if(num == aluno[i].codigo){
		cout << "Nome: " << aluno[i].nome << "  Idade: " << aluno[i].idade << "  Telefone: " << aluno[i].telefone << "\n\n";
		
		}
	
	}
	    system("pause");
	    system("cls");
	
        
}

int IncluirAluno(Alunos aluno[]){
	
	int dig;
	cout << ""
}

int main() {
	Alunos aluno[TAM];
	int qtdalunos = 0;
	int posicao = 0;
int opcao;

	
    do{
    	
    	menu();
    	cout << "\t=>";
    	cin >> opcao;
    	system("cls");
    	
    	switch(opcao){
    		case 1: listaalunos(aluno, qtdalunos);
    			break;
    		case 2: qtdalunos = cadastraaluno(aluno, qtdalunos);
    			break;
    		case 3: 
    			break;
    		case 4: BuscarAluno(aluno, qtdalunos);
    		        
    			break;
    		case 5: 
    			break;
    
		}
	}while(opcao != 6);
	
	return 0;
}
































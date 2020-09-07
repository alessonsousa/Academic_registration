

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
	char nome[TAM];
	int idade[TAM];
	int cpf[TAM];
	int telefone[TAM];
	char email[TAM];
	char formacao[TAM];
//	Enderecos endereco;
};

struct Alunos {
	char nome[TAM];
	int idade[TAM];
	int cpf[TAM];
	int telefone[TAM];
	char email[TAM];
//	Enderecos endereco;
};

struct Cursos {
	char nome[TAM];
	int codigo;

};

struct Disciplina {
	int codigo;
	char nome[TAM];
	int carga_horaria[TAM];
	Professores professor;
	//Alunos aluno;
    
};

struct Enderecos {
	char logradouro[TAM];
	int numero[TAM];
	char bairro[TAM];
	char cidade[TAM];
	char estado[TAM];
};

struct Notas {
	int nota1;
	int nota2;
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

Alunos cadastraaluno(){
	
	Alunos aluno;
	int Codigoprofessor, Codigocurso, Codigodisclipina;
	cout << "\t\t\nCadastro do aluno(a)" << endl;
	cout << "\tDigite o nome: ";
	cin  >> aluno.nome << endl;
	cout << "\tDigite o CPF: ";
	cin  >> aluno.cpf << endl;
	cout << "\tDigite o idade: ";
	cin  >> aluno.idade << endl;
	cout << "\tDigite o email: ";
	cin  >> aluno.email << endl;
	cout << "\tDigite o telefone: ";
	cin  >> aluno.telefone << endl;
	cout << "\tDigite o codigo do professor(a): ";
	cin  >> Codigoprofessor << endl;
	cout << "\tDigite o codigo do curso: ";
	cin  >> Codigocurso << endl;
	cout << "\tDigite o codigo do disclipina: ";
	cin  >> Codigodisclipina << endl;
}


int main() {
	
	Professores professor[] = {
	{}
	
	}
	
	int opcao;
    do{
    	menu();
    	cout << "\t=>";
    	cin >> opcao;
    	system("cls");
    	
    	switch(opcao){
    		case 1: 
    			break;
    		case 2: 
    			break;
    		case 3: 
    			break;
    		case 4: 
    			break;
    		case 5: 
    			break;
    
		}
	}while(opcao != 6);
	
	return 0;
}
































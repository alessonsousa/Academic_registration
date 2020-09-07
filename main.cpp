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

#define TAM 30;
using namespace std;

struct Professores {
	char nome[TAM];
	int idade[TAM];
	int cpf[TAM];
	int telefone[TAM];
	char email[TAM];
	char formacao[TAM];
	Enderecos endereco;
};

struct Alunos {
	char nome[TAM];
	int idade[TAM];
	int cpf[TAM];
	int telefone[TAM];
	char email[TAM];
	Enderecos endereco;
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
	Alunos aluno
    
};
logradouro, número, bairro, cidade e estado
struct Enderecos {
	char logradouro[TAM];
	int numero[TAM];
	char bairro[TAM];
	char cidade[TAM];
	char estado[TAM];
};
int main() {
	
	
	return 0;
}

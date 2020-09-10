
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
	int codigo;
	char nome[TAM];
};

struct Disciplinas {
	int codigo;
	char nome[TAM];
	int carga_horaria[TAM];
	Cursos curso;
  Professores professor;   
};

struct Enderecos {
	char logradouro[TAM];
	int numero[TAM];
	char bairro[TAM];
	char cidade[TAM];
	char estado[TAM];
};

struct Matriculas {
	float nota1;
	float nota2;
	int falta;
  Alunos aluno;
  Disciplinas disciplina;
};

//FUNCAO QUE IMPRIME AS OPCOES DAS FUNCIONALIDADES DO PROGRAMA
void menu(){
    cout << "\n\n\t\t----MENU ----"<<endl;
    cout << "\n\tDigite a opcao: "<<endl;
    cout << "\t1 - Listar Matricula\n";
    cout << "\t2 - Cadastrar aluno(a)\n";
    cout << "\t3 - Matricular aluno(a)\n";
    cout << "\t4 - Exibir aluno(a)\n";
    cout << "\t5 - Buscar aluno(a)\n";
    cout << "\t6 - Excluir aluno(a)\n";
    cout << "\t7 - Sair\n";
}



int cadastraaluno(Alunos aluno[], int qtdalunos){
	

	int Codigoprofessor = 0, Codigocurso, Codigodisclipina;
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



int Exibiralunos(Alunos aluno[], int qtd){
	cout << "\t\t----------- EXIBIR DE ALUNOS -----------\n";
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
		cout << "Codigo: " << aluno[i].codigo <<  "Nome: " << aluno[i].nome << "  Email: " << aluno[i].email << "  Telefone: " << aluno[i].telefone << endl;
		return i;
		}
	
	}
	    system("pause");
	    system("cls");
	
        
}

int IncluirAluno(Alunos aluno[], int qtd){
	
	int dig;
	cout << "nDigite o codigo: ";
	cin >> dig;
	for(int i=0; i < qtd; i++ ){
		if(dig == aluno[i].codigo){
			aluno[i] = aluno[i+1];
		}
	}
	
	qtd--;
	
}

int MatricularAluno(Matriculas matricula[], Alunos aluno[], int qtd){
  int aux, aux2, aux3, aux4, faltas;
  float nota1, nota2;
  Disciplinas disciplina[] = {
	{1, "SO", 80},
	{2, "ED", 80}
	};
	Professores professor[] = {
	{1,"Alesson", "19", "666666", "020103", "alesson@gmail.com", "sistema" },
	{2,"Luiz", "19", "666666", "020103", "luiz@gmail.com", "Quimica" }
};
	Cursos curso[] = {
	{1, "Sistemas de Informacao"},
	{2, "Geografia"},
	{3, "Quimica"}
};

  cout << "digite codigo aluno: ";
  cin >> aux;
  	for(int i=0; i < qtd; i++){
		if(aux == aluno[i].codigo){
		       cout << aluno[i].nome;
		}
    }
   cout << "\nDigite codigo diciplina: ";
   cin >> aux2;
  	for(int i=0; i < 3; i++){
		if(aux2 == disciplina[i].codigo){
		       cout << disciplina[i].nome;
		}
    }
    cout << "\nDigite codigo professor(a): ";
   cin >> aux3;
  	for(int i=0; i < 3; i++){
		if(aux3 == professor[i].codigo){
		       cout << professor[i].nome;
		}
    }
    cout << "\nDigite codigo curso: ";
   cin >> aux4;
  	for(int i=0; i < 3; i++){
		if(aux4 == curso[i].codigo){
		       cout << curso[i].nome;
		}
    }
    cout << "\nDigite nota 1: ";
    cin >> nota1;
    cout << "\nDigite nota 2: ";
    cin >> nota2;
    cout << "\nDigite a contidade de faltas: ";
    cin >> faltas;
}

int ListaMatricula(){
	
}
   

int main() {
  Matriculas matricula[TAM];
	Alunos aluno[TAM];
	int qtdalunos = 0;
	int posicao = 0;
    int opcao;
    int qtdprofessor = 2;
    
	

	

	
    do{
    	
    	menu();
    	cout << "\t=>";
    	cin >> opcao;
    	system("cls");
    	
    	switch(opcao){
    		case 1: ListaMatricula();
    			break;
    		case 2: qtdalunos = cadastraaluno(aluno, qtdalunos);
    			break;
      	case 3: MatricularAluno(matricula, aluno, qtdalunos);
    			break;
    		case 4: Exibiralunos(aluno, qtdalunos);
    			break;
    		case 5: BuscarAluno(aluno, qtdalunos);
    		        
    			break;
    		case 6: IncluirAluno(aluno, qtdalunos);
    			break;
    
		}
	}while(opcao != 6);
	
	return 0;
}


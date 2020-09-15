#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define tam 30
using namespace std;

struct Uf
{
    int codigo;
    char nome[30];
    char sigla[3];
};

struct Cidades
{
    int codigo;
    char nome[30];
    Uf uf;
};

struct Pessoa
{
    int codigo;
    char nome[25];
    int idade;
    char cpf[15];
    char telefone[20];
    char email[30];
    char logradouro[25];
    char numero[10];
    char bairro[20];
    Cidades cidade;
};

struct Professor
{
    Pessoa pessoa;
    char formacao[20];
};

struct Curso
{
    int codigo;
    char nome[30];
};

struct Disciplina
{
    int codigo;
    char nome[30];
    char cargaHoraria[20];
    Curso curso;
    Professor professor;
};

struct Matricula
{
    float nota1;
    float nota2;
    int faltas;
    Disciplina disciplina;
    Pessoa alunos;
};

void menu()
{
    cout << "\t-----MENU PRINCIPAL-----\n";
    cout << "(1) - Cadastra aluno\n";
    cout << "(2) - Listar aluno\n";
    cout << "(3) - Buscar aluno\n";
    cout << "(4) - Excluir aluno\n";
    cout << "(5) - matricular\n";
    cout << "(6) - Listar matricula\n";
    cout << "(7) - Sair\n";
    cout << "=>";
}

Pessoa CadastraAluno(int qtdeAlunos)
{
    Pessoa aluno;
    aluno.codigo = qtdeAlunos;
    cout << "\t-----CADASTRA-SE-----\n";
    cout << "Digite o nome: ";
    cin >> aluno.nome;
    cout << "Digite o telefone: ";
    cin >> aluno.telefone;
    cout << "Digite o CPF: ";
    cin >> aluno.cpf;
    cout << "Digite o email: ";
    cin >> aluno.email;

    system("cls");
    return aluno;
}

void ListarAlunos(Pessoa alunos[], int qtde)
{
    cout << "\t-----Alunos-----\n";
    for (int i = 0; i < qtde; i++)
    {
        cout << "Codigo: " << alunos[i].codigo << " Nome: " << alunos[i].nome << " Telefone: " << alunos[i].telefone << " Email: " << alunos[i].email << endl;
    }
    system("pause");
    system("cls");
}

int BuscarAluno(Pessoa alunos[], int qtde)
{
    int aux;
    cout << "\t-----ALUNO-----\n";
    cout << "Digite o codigo: ";
    cin >> aux;
    for (int i = 0; i < qtde; i++)
    {
        if (aux == alunos[i].codigo)
        {
            cout << "Nome: " << alunos[i].nome << " Telefone: " << alunos[i].telefone << " Email: " << alunos[i].email << endl;
        }
    }
    system("pause");
    system("cls");
}

int IncluirAluno(Pessoa alunos[], int qtde)
{

    int aux;
    cout << "Digite o codigo: ";
    cin >> aux;
    for (int i = 0; i < qtde; i++)
    {
        if (aux == alunos[i].codigo)
        {
            alunos[i] = alunos[i + 1];
            cout << "\t\nexcluido com sucesso!!!\n\n";
        }
    }
    system("pause");
    system("cls");
}
int codAluno, coddisciplina, Nota1, Nota2, faltas;
int Matricular(Pessoa alunos[], int qtde)
{

    cout << "\t-----FAZER MATRICULA-----\n";
    cout << "Digite o codigo do aluno: ";
    cin >> codAluno;
    cout << "\nDigite o codigo da disciplina: ";
    cin >> coddisciplina;
    cout << "\nDigite a nota 1: ";
    cin >> Nota1;
    cout << "\nDigite a nota 2: ";
    cin >> Nota2;
    cout << "\nDigite as faltas: ";
    cin >> faltas;
    system("cls");
}

void Listarmatrcicula(Pessoa alunos[], Disciplina disciplina[], int qtde)
{

    cout << "\t\n-----MATRICULAS-----\n";
    cout << " N | ALUNO | PROFESSOR(A) | DISCIPLINA | CURSO | N1 | N2 | TF | MEDIA | SITUACAO\n";
    for (int i = 0; i < qtde; i++)
    {
        if (codAluno == alunos[i].codigo)
        {
            cout << alunos[i].codigo << " | " << alunos[i].nome << " | ";
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (coddisciplina == disciplina[i].codigo)
        {
            cout << disciplina[i].professor.pessoa.nome << " | " << disciplina[i].nome << " | " << disciplina[i].curso.nome;
        }
    }
    cout << " | " << Nota1 << " | " << Nota2 << " | " << faltas << " | ";
    int total = Nota1 + Nota2;
    total = total / 2;
    cout << total << " | ";
    if (faltas >= 10 || total < 3.5)
    {
        cout << "Reprovado\n";
    }
    if (total < 7)
    {
        cout << "Recuperacao\n";
    }
    else
    {
        cout << "Aprovado\n";
    }

    system("pause");
    system("cls");
}

int main()
{

    int ContProf = 2;

    Professor professor[] = {
        {1, "Alesson Sousa", 19, "123456789", "66666666", "alesson@gmail.com", "Sitio carrapateira", "SN", "Calabaça", {1, "Varzea Alegre", {1, "Ceara", "CE"}}, "SI"},

        {2, "joao Pedro", 35, "123456789", "66666666", "joao@gmail.com", "carrapateira", "SN", "Calabaça", {1, "Varzea Alegre", {1, "Ceara", "CE"}}, "SI"}};

    Curso curso[] = {{1, "SI"}, {2, "CC"}};

    Disciplina disciplina[] = {
        {1, "PEED", "80", curso[0], professor[0]},
        {2, "MTC", "80", curso[0], professor[1]}};

    int opcao;
    Pessoa alunos[tam];
    int qtdeAlunos = 0;

    do
    {
        menu();

        cin >> opcao;
        system("cls");

        switch (opcao)
        {
        case 1:
            alunos[qtdeAlunos] = CadastraAluno(qtdeAlunos);
            qtdeAlunos++;
            break;
        case 2:
            ListarAlunos(alunos, qtdeAlunos);
            break;
        case 3:
            BuscarAluno(alunos, qtdeAlunos);
            break;
        case 4:
            IncluirAluno(alunos, qtdeAlunos);
            qtdeAlunos--;
            break;
        case 5:
            Matricular(alunos, qtdeAlunos);
            break;
        case 6:
            Listarmatrcicula(alunos, disciplina, qtdeAlunos);
            break;
        }

    } while (opcao != 7);
}
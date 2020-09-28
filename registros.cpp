#include<iostream>
#include<stdlib.h>

using namespace std;

struct Uf{
    int codigo;
    char nome[20];
    char sigla[3];
};

struct Cidade{
    int codigo;
    char nome[30];
    Uf uf;
};

struct Pessoa{
    int codigo;
    char nome[50];
    int idade;
    char cpf[14];
    char telefone[15];
    char email[30];
    char logradouro[30];
    char numero[10];
    char bairro[30];
    Cidade cidade;
};

struct Professor{
    Pessoa pessoa;
    char formacao[30];
};

struct Curso{
    int codigo;
    char nome[30];
};

struct Disciplina{
     int codigo;
     char nome[30];
     Curso curso;
     int cargaHoraria;
     Professor professor;
    // Pessoa alunos[40];
};

struct Matricula{
    Disciplina disciplina;
    Pessoa aluno;
    float nota1;
    float nota2;
    int totalFaltas;
};

void menu(){
    cout << "\n\n---- MENU PRINCIPAL ----\n\n";
    cout << "1 - Cadastrar Aluno\n";
    cout << "2 - Listar Alunos\n";
    cout << "3 - Exibir Aluno\n";
    cout << "4 - Excluir Aluno\n";
    cout << "5 - Professores\n";
    cout << "6 - Disciplinas\n";
    cout << "7 - Cursos\n";
    cout << "8 - Matricular\n";
    cout << "9 - Listar matriculas\n";
    cout << "0 - SAIR\n";
}

void listarProfessores(Professor ps[], int qtde){
    cout << "\n---- PROFESSORES ----\n";
    for(int i=0; i<qtde; i++){
        cout << ps[i].pessoa.codigo << " | " << ps[i].pessoa.nome << " | "
             << ps[i].formacao << " | " << ps[i].pessoa.email << " | "
             << ps[i].pessoa.cidade.nome << " | " << ps[i].pessoa.cidade.uf.sigla << endl;
    }
}

void listarDisciplinas(Disciplina ds[], int qtde){
    cout << "\n---- DISCIPLINAS ----\n";
    for(int i=0; i<qtde; i++){
        cout << ds[i].codigo << " | " << ds[i].nome << " | " << ds[i].curso.nome << endl;
    }
}

void listarCursos(Curso cs[], int qtde){
    cout << "\n---- CURSOS ----\n";
    for(int i=0; i<qtde; i++){
        cout << cs[i].codigo << " | " << cs[i].nome << endl;
    }
}

Pessoa cadastrarAluno(int qtdeAlunos){
    Pessoa a;
    a.codigo = qtdeAlunos;
    cout << "\n\n----CADASTRAR ALUNO---\n\n";
    cout << "Digite o nome: ";
    cin >> a.nome;
    cout << "Digite o CPF: ";
    cin >> a.cpf;

    return a;
}

void listarAlunos(Pessoa alunos[], int qtde){
    cout << "\n---- ALUNOS ----\n";
    for(int i=0; i<qtde; i++){
        cout << alunos[i].codigo << " | " << alunos[i].nome << endl;
    }
}

int buscarAluno(Pessoa alunos[], int codigo, int qtde){
    for(int i=0; i<qtde; i++){
        if(alunos[i].codigo == codigo)
            return i;
    }
    return -1;
}

int buscarDisciplina(Disciplina disciplinas[], int codigo, int qtde){
    for(int i=0; i<qtde; i++){
        if(disciplinas[i].codigo == codigo)
            return i;
    }
    return -1;
}

void excluirAluno(Pessoa alunos[], int indice, int qtde){
    for(int i=indice; i<qtde-1; i++){
        alunos[i] = alunos[i+1];
    }
}

void exibirAluno(Pessoa aluno){
    cout << "\n---- ALUNO ----\n";
    cout << aluno.codigo << " | " << aluno.nome << " | " << aluno.cpf << endl;
}

Matricula matricular(Pessoa alunos[], int qtdeAlunos, Disciplina disciplinas[], int qtdeDisciplina){
    cout << "\n---- REALIZAR MATRICULA ----\n";
    int codigoDisciplina, codigoAluno, indice;
    Matricula m;
    //GRAVANDO O ALUNO
    cout << "Digite o codigo do aluno: ";
    cin >> codigoAluno;

    indice = buscarAluno(alunos, codigoAluno, qtdeAlunos);
    if(indice!=-1){
       m.aluno = alunos[indice];
    }else {
        cout << "Aluno nao encontrado";
    }

    //GRAVANDO A DISCIPLINA
    cout << "Digite o codigo da disciplina: ";
    cin >> codigoDisciplina;

    indice = buscarDisciplina(disciplinas, codigoDisciplina, qtdeDisciplina);
    if(indice!=-1){
       m.disciplina = disciplinas[indice];
    }else {
        cout << "Disciplina nao encontrada";
    }
    cout << "Digite a nota 1 do aluno " << m.aluno.nome << ": ";
    cin >> m.nota1;
    cout << "Digite a nota 2 do aluno " << m.aluno.nome << ": ";
    cin >> m.nota2;
    cout << "Digite a qtde de faltas do aluno " << m.aluno.nome << ": ";
    cin >> m.totalFaltas;

    return m;
}

void listarMatriculas(Matricula matriculas[], int qtdeMatricula){
    float media = 0;
    cout << "\n---- MATRICULAS ----\n";
    for(int i=0; i<qtdeMatricula; i++){
        cout << i+1 << " | " << matriculas[i].aluno.nome << " | "
             << matriculas[i].disciplina.professor.pessoa.nome << " | "
             << matriculas[i].disciplina.nome << " | "
             << matriculas[i].disciplina.curso.nome << " | "
             << matriculas[i].nota1 << " | " << matriculas[i].nota2 << " | "
             << matriculas[i].totalFaltas << " | ";
             media = (matriculas[i].nota1+matriculas[i].nota2)/2;
             cout << media << " | ";
             if(matriculas[i].totalFaltas> 40*0.25 || media<3.5){
                cout << "Reprovado";
             }else if(media>=3.5 && media<7){
                 cout << "Recuperacao";
             }else{
                cout << "Aprovado";
             }

             cout << endl;
    }
}


int main(){

    const int qtdePre = 2;

    Professor professores[] = {
        {
            1, "Roberto Carlos", 28, "55555555", "3534-4444",
            "prof1@ifce.edu.br", "Rua Joao Emanuel", "25", "Centro",
            {1, "Cedro", {1,"Ceara", "CE"}},
            "Ciencias da Computacao"
        },
        {
            2, "Prof2", 28, "6666666", "2222-4444",
            "prof2@ifce.edu.br", "Rua dois", "22", "Centro",
            {1, "Cedro", {1,"Ceara", "CE"}},
            "Engenharia da Computacao"
        }
    };

    Curso cursos[] = { {1, "BSI"}, {2, "CC"} };

    Disciplina disciplinas[] = {
        {1, "PEED", cursos[0], 80, professores[0]},
        {2, "LLP", cursos[0], 120, professores[1]}
    };
    const int tam = 30;
    int qtdeAlunos = 0;
    int qtdeMatriculas = 0;
    Pessoa alunos[tam];
    Matricula matriculas[tam];

    int opcao;
    int indice;
    int codigoAluno;

    do{

        menu();
        cout << "Digite a opcao: ";
        cin >> opcao;
        system("cls");

        switch(opcao){
            case 1: alunos[qtdeAlunos] = cadastrarAluno(qtdeAlunos);
                    qtdeAlunos++;
                    break;

            case 2: listarAlunos(alunos, qtdeAlunos);
                    break;

            case 3: cout << "Digite o codigo do aluno: ";
                    cin >> codigoAluno;
                    indice = buscarAluno(alunos, codigoAluno, qtdeAlunos);
                    if(indice!=-1)
                        exibirAluno(alunos[indice]);
                    else
                        cout << "Aluno nao encontrado";
                    break;

            case 4: cout << "Digite o codigo do aluno: ";
                    cin >> codigoAluno;
                    indice = buscarAluno(alunos, codigoAluno, qtdeAlunos);
                    if(indice!=-1){
                        excluirAluno(alunos, indice, qtdeAlunos);
                        qtdeAlunos--;
                    }else {
                        cout << "Aluno nao encontrado";
                    }
                    listarAlunos(alunos, qtdeAlunos);
                    break;

            case 5: listarProfessores(professores, qtdePre);
                    break;

            case 6: listarDisciplinas(disciplinas, qtdePre);
                    break;

            case 7: listarCursos(cursos, qtdePre);
                    break;

            case 8: matriculas[qtdeMatriculas] = matricular(alunos, qtdeAlunos, disciplinas, qtdePre);
                    qtdeMatriculas++;
                   // cout << "\n" << matriculas[0].aluno.nome << endl;
                    break;
            case 9: listarMatriculas(matriculas, qtdeMatriculas);
                    break;
        }

    }while(opcao!=0);

    return 0;

}

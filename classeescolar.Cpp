#include <iostream>
#include <vector>
#include <string>
using namespace std;


// =============================
// Classe base: Pessoa
// =============================
class Pessoa {
protected:
    string nome;
    int idade;


public:
    Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
    virtual void exibirInfo() const {
        cout << "Nome: " << nome << "\nIdade: " << idade << endl;
    }
    string getNome() const { return nome; }
};


// =============================
// Classe Aluno
// =============================
class Aluno : public Pessoa {
private:
    int matricula;


public:
    Aluno(string nome, int idade, int matricula)
        : Pessoa(nome, idade), matricula(matricula) {}


    void exibirInfo() const override {
        cout << "=== Aluno ===" << endl;
        Pessoa::exibirInfo();
        cout << "Matricula: " << matricula << endl;
    }


    int getMatricula() const { return matricula; }
};


// =============================
// Classe Alunos (sistema de alunos)
// =============================
class Alunos {
private:
    vector<Aluno> lista;


public:
    void adicionar(const Aluno &aluno) {
        lista.push_back(aluno);
    }


    void listar() const {
        cout << "\n=== Lista de Alunos ===" << endl;
        for (const auto &a : lista) {
            a.exibirInfo();
            cout << endl;
        }
    }


    void buscar(int matricula) const {
        bool encontrado = false;
        for (const auto &a : lista) {
            if (a.getMatricula() == matricula) {
                cout << "\nAluno encontrado:" << endl;
                a.exibirInfo();
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            cout << "\nAluno nao encontrado!" << endl;
    }


    vector<Aluno> getLista() const {
        return lista;
    }
};


// =============================
// Classe Professor
// =============================
class Professor : public Pessoa {
private:
    string disciplina;


public:
    Professor(string nome, int idade, string disciplina)
        : Pessoa(nome, idade), disciplina(disciplina) {}


    void exibirInfo() const override {
        cout << "=== Professor ===" << endl;
        Pessoa::exibirInfo();
        cout << "Disciplina: " << disciplina << endl;
    }


    string getDisciplina() const { return disciplina; }
};


// =============================
// Classe Turma
// =============================
class Turma {
private:
    string codigo;
    Professor professor;
    vector<Aluno> alunos;


public:
    Turma(string codigo, Professor professor)
        : codigo(codigo), professor(professor) {}


    void adicionarAluno(const Aluno &aluno) {
        alunos.push_back(aluno);
    }


    void exibirTurma() const {
        cout << "\n===== Turma " << codigo << " =====" << endl;
        cout << "Professor responsavel:" << endl;
        professor.exibirInfo();
        cout << "\n--- Alunos ---" << endl;
        for (const auto &a : alunos) {
            a.exibirInfo();
            cout << endl;
        }
    }


    string getCodigo() const { return codigo; }
};


// =============================
// Classe Setor
// =============================
class Setor {
private:
    string nome;
    Pessoa responsavel;


public:
    Setor(string nome, Pessoa responsavel)
        : nome(nome), responsavel(responsavel) {}


    void exibirSetor() const {
        cout << "\n=== Setor: " << nome << " ===" << endl;
        cout << "Responsavel: " << responsavel.getNome() << endl;
    }


    string getNome() const { return nome; }
};


// =============================
// Classe Secretaria (controladora do sistema)
// =============================
class Secretaria {
private:
    vector<Turma> turmas;
    Alunos alunos;
    vector<Professor> professores;
    vector<Setor> setores;


public:
    // Cadastro
    void cadastrarAluno(const Aluno &aluno) { alunos.adicionar(aluno); }
    void cadastrarProfessor(const Professor &professor) { professores.push_back(professor); }
    void criarTurma(const Turma &turma) { turmas.push_back(turma); }
    void cadastrarSetor(const Setor &setor) { setores.push_back(setor); }


    // Listagens
    void listarAlunos() const { alunos.listar(); }


    void listarTurmas() const {
        cout << "\n=== Turmas Cadastradas ===" << endl;
        for (const auto &t : turmas)
            t.exibirTurma();
    }


    void listarSetores() const {
        cout << "\n=== Setores da Escola ===" << endl;
        for (const auto &s : setores)
            s.exibirSetor();
    }


    // Busca
    void buscarAluno(int matricula) const { alunos.buscar(matricula); }
};


// =============================
// Função principal
// =============================
int main() {
    Secretaria secretaria;


    // Professores
    Professor prof1("Katia barbosa", 40, "Matematica");
    Professor prof2("Cristiane Balieiro", 35, "portugues");
    Professor prof3("Paulo medeira", 45, "ingles");
    Professor prof4("anusa patricia", 45, "historia");
    Professor prof5("Deylla garzes", 38, "filosofia");
    Professor prof6("cleise aquino", 49, "Biologia");
    Professor prof7("lorena campos", 35, "quimica");
    Professor prof8("lucas", 35, "fisica");
    Professor prof9("Andressa souza", 42, "Arte");
    Professor prof10("Deylla garzes", 48, "Sociologia");
    Professor prof11("Denilson silva",49,"Geografia");
    Professor prof12("Paulo medeira", 45, "Linguagens");
    Professor prof13("Andressa souza", 43, "Educaçao fisica");
    Professor prof14("Katia barbosa", 40, "letramento matematico");
    Professor prof15("proscila silva", 39, "EPAEM");
    secretaria.cadastrarProfessor(prof1);
    secretaria.cadastrarProfessor(prof2);
    secretaria.cadastrarProfessor(prof3);
    secretaria.cadastrarProfessor(prof4);
    secretaria.cadastrarProfessor(prof5);
    secretaria.cadastrarProfessor(prof6);
    secretaria.cadastrarProfessor(prof7);
    secretaria.cadastrarProfessor(prof7);
    secretaria.cadastrarProfessor(prof8);
    secretaria.cadastrarProfessor(prof9);
    secretaria.cadastrarProfessor(prof10);
    secretaria.cadastrarProfessor(prof11);
    secretaria.cadastrarProfessor(prof12);
    secretaria.cadastrarProfessor(prof13);
    secretaria.cadastrarProfessor(prof14);
    secretaria.cadastrarProfessor(prof15);

    // Alunos
    Aluno a1("Joao", 16, 101);
    Aluno a2("Ana ester", 16, 102);
    Aluno a3("Ana julia", 15, 103);
    Aluno a4("gustavo william gomes da silva", 15, 104);
    Aluno a5("argenis", 16, 105);
    Aluno a6("Bruno", 16, 106);
    Aluno a7("edma", 15, 107);
    Aluno a8("francinei", 16, 108);
    Aluno a9("francisco", 16, 109);
    Aluno a10("helio", 15, 110);
    Aluno a11("henrrique", 16, 111);
    Aluno a12("jhonata", 16, 112);
    Aluno a13("jhon", 15, 113);
    Aluno a14("Julita", 16, 114);
    Aluno a15("leo", 16, 115);
    Aluno a16("Maria eduarda", 15, 116);
    Aluno a17("Maria luiza", 16, 117);
    Aluno a18("Miguel", 16, 118);
    Aluno a19("nayanne", 15, 119);
    Aluno a20("nicole", 16, 120);
    Aluno a21("otavio", 16, 121);
    Aluno a22("shymenne", 15, 122);
    Aluno a23("vitoria", 16, 123);
    Aluno a24("yasmim", 16, 124);

    // Turmas
    Turma t1("A1", prof1);
    t1.adicionarAluno(a1);
    t1.adicionarAluno(a2);
    t1.adicionarAluno(a3);
    t1.adicionarAluno(a4);
    t1.adicionarAluno(a5);
    t1.adicionarAluno(a6);
    t1.adicionarAluno(a7);
    t1.adicionarAluno(a8);
    t1.adicionarAluno(a9);
    t1.adicionarAluno(a10);
    t1.adicionarAluno(a11);
    t1.adicionarAluno(a12);
    Turma t2("B2", prof2);
    t2.adicionarAluno(a13);
    t1.adicionarAluno(a14);
    t1.adicionarAluno(a15);
    t1.adicionarAluno(a16);
    t1.adicionarAluno(a17);
    t1.adicionarAluno(a18);
    t1.adicionarAluno(a19);
    t1.adicionarAluno(a20);
    t1.adicionarAluno(a21);
    t1.adicionarAluno(a22);
    t1.adicionarAluno(a23);
    t1.adicionarAluno(a24);
    secretaria.criarTurma(t1);
    secretaria.criarTurma(t2);

    // Setores
    Pessoa func1("Fernanda Alves", 32);
    Pessoa func2("Ricardo Lima", 45);
    Setor s1("Secretaria", func1);
    Setor s2("Biblioteca", func2);
    secretaria.cadastrarSetor(s1);
    secretaria.cadastrarSetor(s2);


    // Exibições
    secretaria.listarAlunos();
    secretaria.buscarAluno(102);
    secretaria.listarTurmas();
    secretaria.listarSetores();


    return 0;
}

















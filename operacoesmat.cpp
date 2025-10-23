#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{   
    int idade;
    double salario, altura;  
    char genero;
    string nome;

    idade = 16;
    salario = 20.000;
    altura = 1.73;
    genero = 'F';
    nome = " maria luiza serrrao da silva";

    cout << fixed << setprecision(4);
    cout << "IDADE: " << idade << endl; 
    cout << "SALARIO: " << salario << endl;
    cout << "ALTURA: " << altura << endl;
    cout << "GENERO: " << endl; 
    cout << "NOME: " << nome << endl;

   return 0;

}
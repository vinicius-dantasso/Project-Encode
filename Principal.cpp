#include <iostream>
#include "Simd.h"
#include "cripto.h"
using namespace std;

int main() {
	unsigned int valor1, valor2, valor3, valor4, valor5, valor6, valor7, valor8; //variáveis para os valores inseridos
	char colchetes1, colchetes2, virgula; //variáveis para guardar os colchetes as virgulas

	cin >> colchetes1
		>> valor1
		>> virgula
		>> valor2
		>> virgula
		>> valor3
		>> virgula
		>> valor4
		>> colchetes2;
	
	cin >> colchetes1
		>> valor5
		>> virgula
		>> valor6
		>> virgula
		>> valor7
		>> virgula
		>> valor8
		>> colchetes2;

	cout << "\n";

	unsigned int xxma_main = Armazena(valor1, valor2, valor3, valor4); // Guarda os valores inseridos em um único de 32 bits
	unsigned int xxmb_main = Armazena(valor5, valor6, valor7, valor8);         

	cout << "Operandos em 32 bits: " << xxma_main << endl;
	cout << "Operandos em 32 bits: " << xxmb_main << endl;
	
	cout << "\n";

	unsigned int soma = Soma(xxma_main, xxmb_main); //Guarda o valor da soma dos valores inseridos em 32 bits
	cout << "Soma em 32 bits: " << soma << endl;
	unsigned int mult = Mult(xxma_main, xxmb_main); //Guarda o valor da mult dos valores inseridos em 32 bits
	cout << "Mult em 32 bits: " << mult << endl;

	cout << "\n";

	unsigned int soma1, soma2, soma3, soma4, mult1, mult2, mult3, mult4; //Variáveis feitas para guardar os valores da soma e mult de cada valor inserido
	soma1 = Primeiro(soma);
	soma2 = Segundo(soma);
	soma3 = Terceiro(soma);
	soma4 = Quarto(soma);
	
	mult1 = Primeiro(mult);
	mult2 = Segundo(mult);
	mult3 = Terceiro(mult);
	mult4 = Quarto(mult);

	cout << colchetes1;           //E então mostrá-las individualmente
	cout.width(3); cout.fill('0');
	cout << soma1;
	cout << virgula;
	cout.width(3); cout.fill('0');
	cout << soma2;
	cout << virgula;
	cout.width(3); cout.fill('0');
	cout << soma3;
	cout << virgula;
	cout.width(3); cout.fill('0');
	cout << soma4;
	cout << colchetes2 << " = Soma" << endl;

	cout << colchetes1;
	cout.width(3); cout.fill('0');
	cout << mult1;
	cout << virgula;
	cout.width(3); cout.fill('0');
	cout << mult2;
	cout << virgula;
	cout.width(3); cout.fill('0');
	cout << mult3;
	cout << virgula;
	cout.width(3); cout.fill('0');
	cout << mult4;
	cout << colchetes2 << " = Mult" << endl;

	cout << "\n";
	
	unsigned long long soma_cripto = Codificar(soma);      //Variáveis feitas p/ guardar o valor da soma e da mult codificadas em 64 bits
	cout << "Soma cripto 64 bits: " << soma_cripto << endl;
	unsigned long long mult_cripto = Codificar(mult);
	cout << "Mult cripto 64 bits: " << mult_cripto << endl;

	cout << "\n";

	unsigned int valor_soma_codificado = (soma_cripto >> 32); //Variável feita para guardar o valor indivdual da soma codificada (sem os valores das posições)
	unsigned int positions_soma = (soma_cripto << 32) >> 32;
	unsigned int P1_soma, P2_soma, P3_soma, P4_soma, P5_soma, P6_soma; //Variáveis para guardar os valores das posições individualmente (sem o valor da soma codificada)
	P1_soma = (positions_soma >> 27);
	P2_soma = (positions_soma << 5) >> 27;
	P3_soma = (positions_soma << 10) >> 27;
	P4_soma = (positions_soma << 15) >> 27;
	P5_soma = (positions_soma << 20) >> 27;
	P6_soma = (positions_soma << 25) >> 27;

	cout << "Valor codificado: " << valor_soma_codificado;
	cout << " ("
		<< P1_soma
		<< " "
		<< P2_soma
		<< " "
		<< P3_soma
		<< " "
		<< P4_soma
		<< " "
		<< P5_soma
		<< " "
		<< P6_soma
		<< ")\n";
	cout << "Soma decodificada: " << Decodificar(soma_cripto) << endl;//Valor da soma decodificado

	cout << "\n";
	
	unsigned int valor_mult_codificado = (mult_cripto >> 32);//Variável feita para guardar o valor indivdual da mult codificada (sem os valores das posições)
	unsigned int positions_mult = (mult_cripto << 32) >> 32;
	unsigned int P1_mult, P2_mult, P3_mult, P4_mult, P5_mult, P6_mult; //Variáveis para guardar os valores das posições individualmente (sem o valor da mult codificada)
	P1_mult = (positions_mult >> 27);
	P2_mult = (positions_mult << 5) >> 27;
	P3_mult = (positions_mult << 10) >> 27;
	P4_mult = (positions_mult << 15) >> 27;
	P5_mult = (positions_mult << 20) >> 27;
	P6_mult = (positions_mult << 25) >> 27;

	cout << "Valor codificado: " << valor_mult_codificado;
	cout << " ("
		<< P1_mult
		<< " "
		<< P2_mult
		<< " "
		<< P3_mult
		<< " "
		<< P4_mult
		<< " "
		<< P5_mult
		<< " "
		<< P6_mult
		<< ")\n";
	cout << "Mult decodificada: " << Decodificar(mult_cripto) << endl;//Valor da mult decodificado
}
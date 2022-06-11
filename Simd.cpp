#include <iostream>
#include "Simd.h"
using namespace std;

unsigned int Armazena(unsigned char a, unsigned char b, unsigned char c, unsigned char d) { //Guarda os valores inseridos em um só de 32 bits
	unsigned int xxm = (a << 24 | b << 16 | c << 8 | d);
	return xxm;
}

unsigned int Primeiro(int primeiro) { //Separa o primeiro valor
	unsigned int first = (primeiro >> 24);
	return first;
}

unsigned int Segundo(int segundo) { //Separa o segundo valor
	unsigned int second = ((segundo << 8) >> 24);
	return second;
}

unsigned int Terceiro(int terceiro) {//Separa o terceiro valor
	unsigned int third = ((terceiro << 16) >> 24);
	return third;
}

unsigned int Quarto(int quarto) {//Separa o quarto valor
	unsigned int forth = (quarto & 255);
	return forth;
}

unsigned int Soma(int soma1, int soma2) { //Soma os valores anteriormente separados
	unsigned int soma_primeiro = Primeiro(soma1) + Primeiro(soma2);
	unsigned int soma_segundo = Segundo(soma1) + Segundo(soma2);
	unsigned int soma_terceiro = Terceiro(soma1) + Terceiro(soma2);
	unsigned int soma_quarto = Quarto(soma1) + Quarto(soma2);

	unsigned int total_soma = Armazena(soma_primeiro, soma_segundo, soma_terceiro, soma_quarto);

	return total_soma;
}

unsigned int Mult(int mult1, int mult2) {//Multiplica os valores anteriormente separados
	unsigned int mult_primeiro = Primeiro(mult1) * Primeiro(mult2);
	unsigned int mult_segundo = Segundo(mult1) * Segundo(mult2);
	unsigned int mult_terceiro = Terceiro(mult1) * Terceiro(mult2);
	unsigned int mult_quarto = Quarto(mult1) * Quarto(mult2);

	unsigned int total_mult = (mult_primeiro << 24 | mult_segundo << 16 | mult_terceiro << 8 | mult_quarto);

	return total_mult;
}

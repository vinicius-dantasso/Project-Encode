#include <iostream>
#include "cripto.h"
#include <random>
using namespace std;

bool TestarBit(unsigned int test, unsigned int PT) { //Função testarbit p/ saber se um bit está ligado ou não

	if (PT & test) {
		return true;
	}
	else {
		return false;
	}
}

unsigned int LigarBit(unsigned int turn_on, unsigned int PL) { //Função para ligar um bit desligado
	return (turn_on | PL);
}

unsigned int DesligarBit(unsigned int turn_off, unsigned int PD) { //Função para desligar um bit ligado
	return (turn_off & PD);
}


unsigned long long Codificar(unsigned int cod1) {
	unsigned long long valor_Codificado = cod1;
	
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 31);

	unsigned long long rand1, rand2, rand3, rand4, rand5, rand6; //Guardar as posições aleatórias
	rand1 = dist(mt);
	rand2 = dist(mt);
	rand3 = dist(mt);
	rand4 = dist(mt);
	rand5 = dist(mt);
	rand6 = dist(mt);

	unsigned int mask1, mask2, mask3, mask4, mask5, mask6; //Cria as máscaras que usamos para testarbit
	mask1 = 1 << rand1;
	mask2 = 1 << rand2;
	mask3 = 1 << rand3;
	mask4 = 1 << rand4;
	mask5 = 1 << rand5;
	mask6 = 1 << rand6;

	if (TestarBit(valor_Codificado, mask1) == false) {
		valor_Codificado = LigarBit(valor_Codificado, mask1);
	}
	else {
		mask1 = ~(1 << rand1);
		valor_Codificado = DesligarBit(valor_Codificado, mask1);
	}

	if (TestarBit(valor_Codificado, mask2) == false) {
		valor_Codificado = LigarBit(valor_Codificado, mask2);
	}
	else {
		mask2 = ~(1 << rand2);
		valor_Codificado = DesligarBit(valor_Codificado, mask2);
	}
	
	if (TestarBit(valor_Codificado, mask3) == false) {
		valor_Codificado = LigarBit(valor_Codificado, mask3);
	}
	else {
		mask3 = ~(1 << rand3);
		valor_Codificado = DesligarBit(valor_Codificado, mask3);
	}
	
	if (TestarBit(valor_Codificado, mask4) == false) {
		valor_Codificado = LigarBit(valor_Codificado, mask4);
	}
	else {
		mask4 = ~(1 << rand4);
		valor_Codificado = DesligarBit(valor_Codificado, mask4);
	}
	
	if (TestarBit(valor_Codificado, mask5) == false) {
		valor_Codificado = LigarBit(valor_Codificado, mask5);
	}
	else {
		mask5 = ~(1 << rand5);
		valor_Codificado = DesligarBit(valor_Codificado, mask5);
	}
	
	if (TestarBit(valor_Codificado, mask6) == false) {
		valor_Codificado = LigarBit(valor_Codificado, mask6);
	}
	else {
		mask6 = ~(1 << rand6);
		valor_Codificado = DesligarBit(valor_Codificado, mask6);
	}
	
	unsigned long long resultado_Codificado = (valor_Codificado << 32 | rand1 << 27 | rand2 << 22 | rand3 << 17 | rand4 << 12 | rand5 << 7 | rand6 << 2 | 00);

	return resultado_Codificado;
}

unsigned int Decodificar(unsigned long long decod) {
	unsigned int first_bits = (decod >> 32); // separa o valor codificado
	unsigned int positions = (decod << 32) >> 32; // separa as posições

	unsigned int P1 = (positions >> 27); // salva as posições separadamente
	unsigned int P2 = (positions << 5) >> 27;
	unsigned int P3 = (positions << 10) >> 27;
	unsigned int P4 = (positions << 15) >> 27;
	unsigned int P5 = (positions << 20) >> 27;
	unsigned int P6 = (positions << 25) >> 27;

	unsigned int mask_decod1, mask_decod2, mask_decod3, mask_decod4, mask_decod5, mask_decod6;
	mask_decod1 = 1 << P1;
	mask_decod2 = 1 << P2;
	mask_decod3 = 1 << P3;
	mask_decod4 = 1 << P4;
	mask_decod5 = 1 << P5;
	mask_decod6 = 1 << P6;

	if (TestarBit(first_bits, mask_decod6) == true) {
		mask_decod6 = ~(1 << P6);
		first_bits = DesligarBit(first_bits, mask_decod6);
	}
	else {
		first_bits = LigarBit(first_bits, mask_decod6);
	}

	if (TestarBit(first_bits, mask_decod5) == true) {
		mask_decod5 = ~(1 << P5);
		first_bits = DesligarBit(first_bits, mask_decod5);
	}
	else {
		first_bits = LigarBit(first_bits, mask_decod5);
	}

	if (TestarBit(first_bits, mask_decod4) == true) {
		mask_decod4 = ~(1 << P4);
		first_bits = DesligarBit(first_bits, mask_decod4);
	}
	else {
		first_bits = LigarBit(first_bits, mask_decod4);
	}

	if (TestarBit(first_bits, mask_decod3) == true) {
		mask_decod3 = ~(1 << P3);
		first_bits = DesligarBit(first_bits, mask_decod3);
	}
	else {
		first_bits = LigarBit(first_bits, mask_decod3);
	}

	if (TestarBit(first_bits, mask_decod2) == true) {
		mask_decod2 = ~(1 << P2);
		first_bits = DesligarBit(first_bits, mask_decod2);
	}
	else {
		first_bits = LigarBit(first_bits, mask_decod2);
	}

	if (TestarBit(first_bits, mask_decod1) == true) {
		mask_decod1 = ~(1 << P1);
		first_bits = DesligarBit(first_bits, mask_decod1);
	}
	else {
		first_bits = LigarBit(first_bits, mask_decod1);
	}

	return first_bits;
}
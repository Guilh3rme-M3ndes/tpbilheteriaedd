#include <iostream>
#include <cstdlib>
using namespace std;
#define LIN 15
#define COL 40

/*
TP BILHETERIA
Aluno: Guilherme Mendes de Sousa
Disciplina: Estrutura de dados
Docente: Marco Aurelio Pires Marques
*/
void mostraMapa(int **matriz){
	for (int ii = 0; ii < LIN; ii++){
		for (int jj = 0; jj < COL; jj++){
			
			if (matriz[ii][jj] == 1) {
				cout << "#" << " ";
			}
			else
			cout << "." << " ";
		}
		cout << endl;
	}
}


void atualizaBilheteria (int linha, int *valor) {
	if (linha < 5) {
		*valor += 50;
	}
	else if (linha < 10) {
		*valor += 30;
	}
	else {
		*valor += 15;
	}
}

void alimentaBilheteria (int *valor, int **matriz) 
{
	for (int ii = 0; ii < LIN; ii++){
		for (int jj = 0; jj < COL; jj++){
			
			if (matriz[ii][jj] == 1) {
				atualizaBilheteria(ii, valor);
			}
		}
	}
}


void reservar(int **matriz, int linha, int coluna, int *total){
	if (matriz[linha][coluna] == 1) {
		cout << "A poltrona selecionada esta ocupada" << endl; 
	}
	else {
		matriz[linha][coluna] = 1;
		cout << "Poltrona reservada! " << endl;
		atualizaBilheteria(linha, total);
	}
}

void mostraFaturamento(int **matriz, int total){
	int ocupadas = 0;
	for (int ii = 0; ii < LIN; ii++){
		for (int jj = 0; jj < COL; jj++){
			
			if (matriz[ii][jj] == 1) {
				ocupadas++;
			}
		}
	}
	cout << "N de poltronas ocupadas: " << ocupadas << endl;
	cout << "Valor de bilheteria: RS" << total << endl;
}

int main(int argc, char** argv)
{
	int **mapa;
	int controle = 1;
	int total;
	total = 0;
	mapa = new int*[LIN];
	
	for (int ii = 0; ii < LIN; ii++){
		mapa[ii] = new int[COL];
	}
	for (int ii = 0; ii < LIN; ii++) {
		for (int jj = 0; jj < COL; jj++) {
			mapa[ii][jj] = 0;
		}
	}
	alimentaBilheteria(&total, mapa);
	cout << "Bem-vindo(a) ao gerenciador de poltronas do teatro! Escolha entre as opcoes abaixo" << endl << 
		"1 - Reservar assento" << endl <<
		"2 - Visualizar mapa de assentos" << endl <<
		"3 - Conferir faturamento atual" << endl <<
		"0 - Encerrar aplicativo" << endl;
	while(controle != 0){
		cout << "Informe a funcao escolhida: " << endl;
		cin >> controle;
		switch(controle) {
			case 1:
				int linha;
				int coluna;
				cout << "Informe a fileira: " << endl;
				cin >> linha;
				linha--;
				while (linha > 14 || linha < 0) {
					cout << "A fileira precisa estar entre 1 e 15! Informe outra: " << endl;
					cin >> linha;
					linha--;
				}
				cout << "Informe a coluna: " << endl;
				cin >> coluna;
				coluna--;
				while (coluna > 39 || coluna < 0) {
					cout << "A coluna precisa estar entre 1 e 40! Informe outra: " << endl;
					cin >> coluna;
					coluna--;
				}
				reservar(mapa, linha, coluna, &total);
			
				break;
			case 2:
				mostraMapa(mapa);
				cout << " # - ocupado " << endl << " . - livre " << endl; 
				break;
			case 3:
				mostraFaturamento(mapa, total);
				break;
			default:
				if(controle == 0) {
					cout << "Fim da execucao" << endl;
					for (int ii = 0; ii < LIN; ii++) {
						delete[] mapa[ii];
					}
					delete[] mapa;
				}
				else {
                    cout << "Opcao invalida " << endl;
				}
				break;
			
		}
	}
	
	return 0;
}
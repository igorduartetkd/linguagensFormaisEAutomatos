/*
 * By Igor Duarte - 10/10/2017 - Linguagens formais e automatos
 * alfabeto = {a, b}
 * aceita M1 ou M2 sendo que:
 * M1= {a*} e M2= {a(ba)*}
 * contato: igorduartetkd@gmail.com
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void maquina( int estado, int posicao);

string entrada;
int estados[4] = {0, 1, 2, 3};
int q0 = 0;
bool aceite[4] = {0, 0, 1, 1};
#define l 4 //quantidade de linhas da matriz de transicao
#define c 3 //quantidade de colunas da matriz de transicao
vector<int> matrizTransicao[l][c];
bool aceito;

int main(){
	//populando a matriz de transicao
	vector<int> aux;
	aux.push_back(1);
	aux.push_back(2);
	matrizTransicao[0][0] = aux;
	aux.clear();
	matrizTransicao[0][1] = matrizTransicao[0][2] = aux;
	matrizTransicao[1][0] = matrizTransicao[1][2] = aux;
	matrizTransicao[2][0] = matrizTransicao[2][2] = aux;
	matrizTransicao[3][0] = matrizTransicao[3][1] = aux;
	aux.push_back(3);
	matrizTransicao[1][1] = aux;
	aux.clear();
	aux.push_back(2);
	matrizTransicao[2][1] = aux;
	aux.clear();
	aux.push_back(1);
	matrizTransicao[3][2] = aux;
	//fim da populacao da matriz de transicao
	
	while(entrada != "0"){ //para de rodar quando ler 0.
		aceito = false;
		cin>>entrada;
		maquina(q0, 0);
		puts("");
		if(aceito){
			cout<<"String aceita!"<<endl;
		}else{
			cout<<"String recusada!"<<endl;
		}
	}
}

void maquina( int estado, int posicao){
	//imprimindo estado atual:
	cout<<"q"<<estado;
	
	if(posicao == (int)entrada.size()){
		if(aceite[estado]){
			aceito = true;
		}
		return;
	}
	cout<<"->";	
	
	vector<int> aux2 = matrizTransicao[estado][0]; //lambida transition
	//realizando transicoes lambida para todos os estados destino da matriz
	for(unsigned i = 0; i < aux2.size(); i++){
		cout<<"{";
		int x = (matrizTransicao[estado][posicao])[i];
		maquina(x, posicao);
		cout<<"}";
	} 
	
	
	
	char simbolo = entrada[posicao];
	aux2.clear();
	aux2 = matrizTransicao[estado][simbolo-96];
	posicao++;
	//fazendo a transicao para os estados da matriz de transicao
	//quando a entrada for o estado atual e ler a proxima letra
	for(unsigned i = 0; i < aux2.size(); i++){
		cout<<"(";
		int x = aux2[i];
		maquina(x, posicao);
		cout<<")";
	} 
	if(aceito){
		return;
	}
}

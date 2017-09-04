#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void executar(int estado, int posicao);

int estados[6] = {0, 1, 2, 3, 4, 5};
int q0 = 0;
bool aceite[6] = {1, 1, 1, 1, 0, 0};
int matrizTransicao[6][2] = {{3, 1},
							 {3, 2},
							 {2, 2},
							 {4, 1},
							 {4, 5},
							 {4, 2}};
string entrada;

int main(){
	
	while(entrada != "0"){
		cin>>entrada;
		executar(q0, 0);
	}
	
}

void executar(int estado, int posicao){
	//imprimindo estado atual:
	cout<<"q"<<estado;
	
	if(posicao == (int)entrada.size()){
		puts("");
		if(aceite[estado]){
			cout<<"String aceita!"<<endl;
		}else{
			cout<<"String recusada!"<<endl;
		}
		return;
	}
	cout<<"->";
	char aux = entrada[posicao];
	executar(matrizTransicao[estado][aux-97], ++posicao);
}

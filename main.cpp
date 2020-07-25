#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>

/* Estrutura de Dados - Arvore Binaria
	
	Dev-C++, Windows 10.
	
	Aluno: Ana Paula Rodrigues Bellon

*/
int main() {
	//setlocale(LC_ALL, “Portuguese”);
	Node *pRoot;
	makeTree(&pRoot);
	int option=0,aux;
	do{
		printf("1 - Menu Arvore Binaria;\n");
		printf("2 - EXIT.\n");
		printf("Entre com a opcao desejada: ");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1: menuBin();
					break;
			case 2: printf("------EXIT------\n");
					break;
			default:
					printf("Comando invalido! Tente novamente :)\n");
		}
	}while(option!=2);
		printf("Ate logo... \n");
	system("pause");
	return 0;
}

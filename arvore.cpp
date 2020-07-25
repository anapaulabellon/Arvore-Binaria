#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void makeTree(Node **pRoot){
	*pRoot = NULL;
}

void insert(Node **pRoot, int key2){
	if (*pRoot == NULL){
	      *pRoot = (Node *)malloc(sizeof (Node));
	      (*pRoot)->left = NULL;
	      (*pRoot)->right = NULL;
	      (*pRoot)->key = key2;
	}
	else{
		if (key2 < ((*pRoot)->key)){
			insert(&((*pRoot)->left), key2);
		}
		else{
			insert(&((*pRoot)->right), key2);
		}
	}
}

Node *HighRight(Node **node){
    if((*node)->right != NULL){
       return HighRight(&(*node)->right);
    }
    else{
       Node *aux = *node;
       if((*node)->left != NULL){
       	
          *node = (*node)->left;
        }
        else{
            *node = NULL;
            return aux;
        }
    }
        
}

Node *LowLeft(Node **node){
    if((*node)->left != NULL){
       return LowLeft(&(*node)->left);
    }
    else{
        Node *aux = *node;
        if((*node)->right != NULL){

          *node = (*node)->right;
        }
        else{
          *node = NULL;
        }
        return aux;
    }
}

void remove(Node **pRoot, int key){
    if(*pRoot == NULL){
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(key < (*pRoot)->key)
    	remove(&(*pRoot)->left, key);
    else 
    	if(key > (*pRoot)->key)
        	remove(&(*pRoot)->right, key);
    	else{
        	Node *pAux = *pRoot;
        	if (((*pRoot)->left == NULL) && ((*pRoot)->right == NULL)){
                free(pAux);
                (*pRoot) = NULL; 
        	}
        	else{
				//so tem o filho da direita
            	if ((*pRoot)->left == NULL){
                	(*pRoot) = (*pRoot)->right;
                	pAux->right = NULL;
                	free(pAux); pAux = NULL;
                }
            	else{
					//so tem filho da esquerda
                	if ((*pRoot)->right == NULL){
                    	(*pRoot) = (*pRoot)->left;
                    	pAux->left = NULL;
                    	free(pAux);
						pAux = NULL;
                    }
                	else{
                   		pAux = HighRight(&(*pRoot)->left);
                   		pAux->left = (*pRoot)->left;
                   		pAux->right = (*pRoot)->right;
                   		(*pRoot)->left = (*pRoot)->right = NULL;
                   		free((*pRoot));
						*pRoot = pAux;
						pAux = NULL;   
                   }
                }
             }
          }
}

void destroy(Node **pRoot){
	if(*pRoot != NULL){
		destroy(&(*pRoot)->left);
		destroy(&(*pRoot)->right);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void showInOrder(Node *pRoot){
    if(pRoot != NULL){
        showInOrder(pRoot->left);
        printf(" %i -", pRoot->key);
        showInOrder(pRoot->right);
    }
}

void showPreOrder(Node *pRoot){
    if(pRoot != NULL){
        printf(" %i -", pRoot->key);
        showPreOrder(pRoot->left);
        showPreOrder(pRoot->right);
    }
}

void showPostOrder(Node *pRoot){
    if(pRoot != NULL){
        showPostOrder(pRoot->left);
        showPostOrder(pRoot->right);
        printf(" %i -", pRoot->key);
    }
}

int countNodes(Node *pRoot){
	if(pRoot == NULL)
    	return 0;
	else
		return 1 + countNodes(pRoot->left) + countNodes(pRoot->right);
}

/* int countLeafs(Node *pRoot){
	if(pRoot == NULL)
    	return 0;
	if(pRoot->left == NULL && pRoot->right == NULL)
        return 1;
	return countLeafs(pRoot->left) + countLeafs(pRoot->right);
}
*/

int high(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}//maior

int height(Node *pRoot){
   if((pRoot == NULL) || (pRoot->left == NULL && pRoot->right == NULL))
       return 0;
   else
       return 1 + high(height(pRoot->left), height(pRoot->right));
}//altura

void menuBin(){
	int option=0, aux;
	Node *pRoot;
	makeTree(&pRoot);
	do{
		printf("1 - Inserir;\n");
		printf("2 - Exibir em ordem;\n");
		printf("3 - Exibir pos-ordem;\n");
		printf("4 - Exibir pre-ordem;\n");
		printf("5 - Altura da arvore;\n");
		printf("6 - Numero de nos;\n");
		printf("7 - Remover um no;\n");
		printf("8 - Destruir;\n");
		printf("9 - EXIT (A arvore sera destruida!).\n");
		printf("Entre com a opcao desejada: ");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1: printf("Entre com o valor inteiro a ser inserido: ");
					scanf("%d", &aux);
					insert(&pRoot,aux);
					printf("Valor inserido!\n");
					break;
			case 2: printf("--------------- Em Ordem: ---------------\n");
					showInOrder(&*pRoot);
					printf("\n-----------------------------------------\n");
					break;
			case 3: printf("--------------- Pos-Ordem: ---------------\n");
					showPostOrder(&*pRoot);
					printf("\n------------------------------------------\n");
					break;
			case 4: printf("--------------- Pre-Ordem: ---------------\n");
					showPreOrder(&*pRoot);
					printf("\n------------------------------------------\n");
					break;
			case 5: printf("Altura da arvore: %d\n",height(&*pRoot));
					break;
			case 6: printf("Numero de nos: %d\n",countNodes(&*pRoot));
					break;
			case 7: printf("Entre com o valor a ser removido: ");
					scanf("%d", &aux);
					remove(&pRoot,aux);
					break;
			case 8:	destroy(&pRoot);
					printf("Arvore destruida!\n");
					break;
			case 9: printf("------EXIT ARVORE BIN------\n");
					break;
			default:
					printf("Comando invalido! Tente novamente :)\n");
		}
	}while(option!=9);
		destroy(&pRoot);
}

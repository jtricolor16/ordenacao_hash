#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>




typedef struct No{				//Definição do struct das variáveis a serem utilizadas na lista
	char string[20];
	struct No *prox;
}TNo;

typedef TNo *TLista;		//Simplificação do uso de ponteiros e conversão do nome da variável TNo em TLista



//Protótipos das funções

int menu ();									//Função responsável por facilitar a usabilidade do software.
void zerarbuffer();								//Corrige o problema encontrado no uso do scanf e gets.
void zerahash(TLista a[]);						//Torna os valores do struct, inicialmente, igual a NULL.
void verificaespaco(char palavra[]);			//Impossibilitar o uso de espaço na sentença que irá para a lista.
int valor_string(char palavra[]);				//Descobre o valor total, em inteiro, da string.
int ordemalf(char lista[], char texto[]);			//Ordenar alfabeticamente os elementos da lista.
int inserir (TLista a[], int val, char palavra[]);			//Insere os valores nos segmentos do vetor de lista.
void exibirsegmento (TLista l);						//Exibe o segmento da lista.
void exibirtabela (TLista l[]);						//Exibe a tabela completa.
int buscar (TLista l[], char buscada[]);				//Busca pela palavra desejada na tabela.
int remover (TLista l[], char removida[]);			//Remove o elemento desejado da lista.
int alterar (TLista l[], char palavra[], char buscada[]);	//Altera o elemento indicado pelo novo.




//Função Main

int main (){
	TLista a[10];
	zerahash(a);
	char palavra[20], buscada[20], removida [20];
	int r=0, c, val, l, busc, rem, alt, val1;
	
	
	
	while (r!= 7){
		r=menu();
		switch(r){
			case 1:
				printf("\n\nDigite uma palavra, sem espaco, de no maximo 19 caracteres:\n\n");
				gets(palavra);
				verificaespaco(palavra);
				strupr(palavra);
				printf("\n\nA palavra digitada equivale a: %s\n", palavra);
				c=strlen(palavra);
				if(c>19){
					printf("\n\nO tamanho da palavra excedeu o espaco permitido.\n\n");
					printf("\n\nRepita o processo novamente.\n\n");
					system("PAUSE");
					break;
				}
				val=(valor_string(palavra))%10;
				printf("\n\nO valor equivale a: %d\n", val);
				l=inserir(a, val, palavra);
				system("PAUSE");
				break;
			case 2:
				printf("\n\nDigite a palavra que deseja remover:\n\n");
				gets(removida);
				verificaespaco(removida);
				strupr(removida);
				printf("\n\nA palavra digitada equivale a: %s\n", removida);
				strlen(buscada);
				if(c>19){
					printf("\n\nO tamanho da palavra excedeu o espaco permitido.\n\n");
					printf("\n\nRepita o processo novamente.\n\n");
					system("PAUSE");
					break;
				}
				rem=remover(a, removida);
				if(rem==1){
					printf("\n\nPalavra removida com sucesso!\n\n");
					system ("pause");
				}else{
					printf("\n\nPalavra nao encontrada\n\n");
					system ("pause");	
				}
				break;
			case 3:
				printf("\n\nDigite a palavra que deseja substituir:\n\n");
				gets(buscada);
				verificaespaco(buscada);
				strupr(buscada);
				printf("\n\nA palavra digitada equivale a: %s\n", buscada);
				strlen(buscada);
				if(c>19){
					printf("\n\nO tamanho da palavra excedeu o espaco permitido.\n\n");
					printf("\n\nRepita o processo novamente.\n\n");
					system("PAUSE");
					break;
				}
				val=(valor_string(buscada))%10;
				printf("\n\nO valor equivale a: %d\n", val);
				printf("\n\nDigite a nova palavra, sem espaco, de no maximo 19 caracteres:\n\n");
				gets(palavra);
				verificaespaco(palavra);
				strupr(palavra);
				printf("\n\nA palavra digitada equivale a: %s\n", palavra);
				c=strlen(palavra);
				if(c>19){
					printf("\n\nO tamanho da palavra excedeu o espaco permitido.\n\n");
					printf("\n\nRepita o processo novamente.\n\n");
					system("PAUSE");
					break;
				}
				val1=(valor_string(palavra))%10;
				printf("\n\nO valor equivale a: %d\n", val);
				if(val==val1){
					alt=alterar(a, palavra, buscada);
					if(alt==1){
						printf("\n\nPalavra alterada!\n\n");
						system("pause");
						break;
					}else{
						printf("\n\nPalavra não foi possível encontrar a palavra a ser substituída!\n\n");
						system("pause");
						break;	
					}
				}else{
					printf("\n\nPalavras pertencem a segmentos diferentes\n\n");
					system("pause");
					break;
				}		
			case 4:
				printf("\n\nDigite a palavra que deseja encontrar:\n\n");
				gets(buscada);
				verificaespaco(buscada);
				strupr(buscada);
				printf("\n\nA palavra digitada equivale a: %s\n", buscada);
				strlen(buscada);
				if(c>19){
					printf("\n\nO tamanho da palavra excedeu o espaco permitido.\n\n");
					printf("\n\nRepita o processo novamente.\n\n");
					system("PAUSE");
					break;
				}
				busc=buscar(a, buscada);
				if(busc<0){
					printf("\n\nPalavra nao encontrada\n\n");
					system ("pause");
				}else{
					printf("\n\nPalavra encontrada no segmento de numero %d!\n\n", busc);
					system ("pause");
				}
				break;
			case 5:
				printf("\n\nDigite a posicao do vetor de lista encadeadas desejada:\n\n");
				scanf("%d", &val);
				exibirsegmento(a[val]);
				system("PAUSE");
				break;
			case 6:
				exibirtabela(a);
				system("PAUSE");
				break;		
		}
	}
}




















//Implementação das demais funções

int menu (){
	int r;
	system ("cls");
	printf ("\n\n\nIMPLEMENTACAO DA TABELA HASH\n\n\n");
	printf("Digite <1> para inserir um valor na tabela\n\n");
	printf("Digite <2> para remover um valor da tabela\n\n");
	printf("Digite <3> para alterar um valor na tabela\n\n");
	printf("Digite <4> para buscar um valor na tabela\n\n");
	printf("Digite <5> para exibir os valores de um segmento da tabela\n\n");
	printf("Digite <6> para exibir todos os valores da tabela\n\n");
	printf("Digite <7> para sair\n\n");
	scanf ("%d", &r);
	zerarbuffer(r);
	return r;
}

void zerarbuffer(){ 
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void zerahash(TLista a[]){
	int i;
	for(i=0; i<10; i++){
		a[i]=NULL;
	}
}

void verificaespaco(char palavra[]){
	int i=0;
	while(palavra[i]!=' '){
		i++;
	}
	for(i; i<19; i++){
		palavra[i]='\0';
	}
}

int valor_string(char palavra[]){
	int i=0, valor=0;
	while(palavra[i] != '\0'){
		valor+=palavra[i];
		i++;
	}
	return valor;
}

int ordemalf(char lista[], char texto[]){
	int i, j;
	for(i=0, j=0; i<strlen(lista), j<strlen(texto); i++, j++){
		if(lista[i]<texto[j]){
			return 0;
		}else if(lista[i]>texto[j]){
			return 1;
		}
	}
	if(i>j){
		return 1;
	}else if(i<j){
		return 0;
	}else{
		return 2;
	}
}

int inserir (TLista a[], int val, char palavra[]){
	int ord, i=0, j=0;
	TLista aux, aux2;
	TLista novo = (TLista) malloc (sizeof(TNo));
	if(novo==NULL){
		printf("\nFALTA DE ESPACO NA MEMORIA\n");
		return 0;
	}
	if (a[val]==NULL){
		strcpy(novo->string, palavra);
		novo->prox=a[val];
		a[val]=novo;
		printf("\n\nElemento inserido com sucesso\n\n");
		return 1;	
	}
	aux=a[val];
	while(aux!=NULL){
		ord=ordemalf(aux->string, palavra);
		if(ord==2){
			printf("\n\nPALAVRAS IGUAIS\n\n");
			printf("\n\nNA PROXIMA VEZ, DIGITE PALAVRAS DIFERENTES\n\n");
			return 0;
		}
		aux=aux->prox;
		i++;
	}
	aux=a[val];
	aux2=a[val];
	while(aux!=NULL){
		ord=ordemalf(aux->string, palavra);
		j++;
		if(ord==0){
			strcpy(novo->string, palavra);
			if(aux->prox!=NULL && i==j){
				novo->prox=aux->prox;
				aux->prox=novo;
				printf("\ngo paulo\n");
			}else if(aux->prox==NULL && i==j){
				novo->prox=NULL;
				aux->prox=novo;
				printf("\neh nois!\n");
			}
		}else if (ord==1){
			break;
		}
		aux2=aux;
		aux=aux->prox;
	}
	if(ord==1 && aux==(a[val])){
		strcpy(novo->string, palavra);
		novo->prox=a[val];
		a[val]=novo;
		printf("\n\nElemento inserido com sucesso\n\n");
		return 1;	
	}else if (ord==1 && aux!=a[val]){
		strcpy(novo->string, palavra);
		novo->prox=aux;
		aux2->prox=novo;
		if(aux->prox==NULL){
			aux->prox=NULL;
		}
		printf("\nGOl!");
		return 1;
	}else{
		return 1;
	}
	
}

void exibirsegmento (TLista l){
	TLista aux;
	aux=l;
	if(aux==NULL){
		printf("Lista vazia!\n");
	}
	while (aux!=NULL){
		printf("%s\n", aux->string);
		aux=aux->prox;
	}
}

void exibirtabela (TLista l[]){
	TLista aux[1];
	int i;
	
	for(i=0; i<10; i++){
		aux[0]=l[i];
		printf("\nLista: %d\n", i);
		if (aux[0]==NULL){
			printf("Nenhuma palavra inserida!\n");
		}
		else{
			while (aux[0]!=NULL){
				printf("%s\n", aux[0]->string);
				aux[0]=aux[0]->prox;
			}
			printf("\n");	
		}	
	}
	printf("\n");
}

int buscar (TLista l[], char buscada[]){
	int i;
	TLista aux[1];
	for(i=0; i<10; i++){
		aux[0]=l[i];
		while(aux[0]!=NULL){
			if(strcmp(aux[0]->string,buscada)==0){
				return i;
			}
			aux[0]=aux[0]->prox;	
		}	
	}
	return -1;
}

int remover (TLista l[], char removida[]){
	int i;
	TLista aux[1], aux2[1];
	for (i=0; i<10; i++){
		aux[0]=l[i];
		aux2[0]=l[i];
		while(aux[0]!=NULL){
			if(aux[0]==l[i] && (strcmp(aux[0]->string,removida)==0)){
				l[i]=(l[i])->prox;
				free(aux[0]);
				return 1;
			}else if (aux[0]!=l[i] && (strcmp(aux[0]->string,removida)==0)){
				aux2[0]->prox=aux[0]->prox;
				free(aux[0]);
				aux[0]=aux2[0]->prox;
				return 1;
			}else{
				aux2[0]=aux[0];
				aux[0]=aux[0]->prox;
			}
		}
	}
	return 0;
}

int alterar (TLista l[], char palavra[], char buscada[]){
	int i;
	TLista aux[1];
	
	for(i=0; i<10; i++){
		aux[0]=l[i];
		while(aux[0]!=NULL){
			if(strcmp(aux[0]->string, buscada)==0){
				strcpy(aux[0]->string, palavra);
				return 1;
			}else{
				aux[0]=aux[0]->prox;
			}
		}
	}
	return 0;
}






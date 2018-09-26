#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define qtbuckts 30000

//int quant = 0;
int colisoes = 0;
int vazios = 0 ;

struct Node
{
	char* palavra;
	struct Node* next;
};

struct Node* N[qtbuckts];


int hash(char* palavra){ // Hash Método Horner
	int h = palavra[0];
	int i;
	for ( i = 1; i < strlen(palavra); ++i){
		h = ((h * 251) + palavra[i]) % qtbuckts;
	}

	return h;
}

void add(struct Node** N,char* palavra){  // #3 testar adicionar elementos sem calcular o hash
										  // #4 testar adicionar elemento calculando o hash
	int j = hash(palavra);
	//printf("%s %d  :",palavra, j );
	struct Node *aux ;
	aux = N[j];
	if (N[j]->palavra == NULL){
		N[j]->palavra = palavra;
		N[j]->next = NULL;
	}else{
		colisoes++;
		while(aux->next != NULL)
		aux = aux->next;
		aux->next = ( struct Node* ) malloc ( sizeof( struct Node ) );
		aux->next->palavra = palavra;
		aux->next->next = NULL;
		}

	/* *N = ( struct Node* ) malloc ( sizeof( struct Node ) ); // fazer alocação dinamica  de um ponteiro auxiliar
	 														//para percorrer a lista do bucket citado
	struct Node *aux = *N;
	while(*N[i]->next != NULL)
	aux = aux->next;
	aux->next = ( struct Node* ) malloc ( sizeof( struct Node ) );
    aux->next->palavra = palavra;
    aux->next->next = NULL;
	*/
}

/*FUNCÃO QUE PESQUISA NA TAELA HASH

    //CHAMA A FUNÇÃO QUE CALCULA O HASH
    //COMPARA A PALAVVRA DO TEXTO COM AS PALAVRAS ARMAZENADAS NO DICIONARIO

*/

void LeDicionario(){

    FILE *fp;

	fp = fopen("dicionario.txt", "r");
	if(fp == NULL){
		puts("Nao foi possivel abrir o arquivo.\n");
		return;
		}else{
		while(!feof(fp)){

			char* pDicio;
			pDicio = NULL;
    		pDicio = (char*) malloc(51*sizeof(char));
			fgets(pDicio, 51, fp);
			//pDicio[strlen(pDicio)] = '\0';
	        //printf("%s (pulo do ler)\n", pDicio);

	        /*
	        int i;
	        char* a;
	        		a = NULL;

	        for (i = 0; i < strlen(pDicio); i++)
	        {
	        	a[i]=pDicio[i];
	        }
	        a[i] = '\0';
	        */
	        //printf("%d \n",++quant);
			add(N,pDicio);
			}
		}
	fclose(fp);
}

void desenharTabela(struct Node** N){
	int i;
	struct Node *aux ;
	for (i = 0; i < qtbuckts; i++){
		printf("bucket[%d]\n",i);
		struct Node *aux = NULL;
		aux = N[i];
		while(aux != NULL){
		printf("%s ->", aux->palavra);
		aux = aux->next;
		}
		printf("\n\n\n\n\n\n\n");
	}

}

void Vazios(struct Node** N){
	int i;
	//int qt = 0;
	struct Node *aux ;
	for (i = 0; i < qtbuckts; i++){
		struct Node *aux = NULL;
		aux = N[i];
		if(aux->palavra == NULL){
		vazios++;
		}
	}
}

/*
void LeTexto(){
char pTexto[51];
    FILE *fp;

	fp = fopen("text.txt", "r");
	if(fp == NULL){
		puts("Nao foi possivel abrir o arquivo.\n");
		return;
		}
	while(1){
		fgets(pTexto, 51, fp);
		pTexto[strlen(pTexto)-1] = '\0';

		//CHAMA A FUNCÃO QUE PESQUISA NA TAELA HASH

		if(feof(fp)){
			break;
		}
	}
	fclose(fp);
}
*/

int main(void){
	int i;

	for (i = 0; i < qtbuckts; i++) // inicializando tabela
	{
		N[i] = ( struct Node* ) malloc ( sizeof( struct Node )*qtbuckts );
	}
	//add(N,"banana");


    LeDicionario(N);
    Vazios(N);
    printf("numero de buckets: %d\n", qtbuckts);
    printf("colisoes:  %d\n", colisoes);
    printf("vazios: %d\n", vazios);
    printf("usados: %d\n", qtbuckts - vazios);
    printf("col/buckets: %.2lf\n", (double)colisoes/(qtbuckts - vazios));
    //LeTexto();
	//desenharTabela(N);


    return 0;
}

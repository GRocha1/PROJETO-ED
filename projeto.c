#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//FUN��O QUE CALCULA O HASH

//FUNC�O QUE INSERE NA TAELA HASH

/*FUNC�O QUE PESQUISA NA TAELA HASH

    //CHAMA A FUN��O QUE CALCULA O HASH
    //COMPARA A PALAVVRA DO TEXTO COM AS PALAVRAS ARMAZENADAS NO DICIONARIO

*/

void LeDicionario(){
    char pDicio[51];
    FILE *fp;

	fp = fopen("dicionario.txt", "r");
	if(fp == NULL){
		puts("Nao foi possivel abrir o arquivo.\n");
		return;
		}
	while(1){
		fgets(pDicio, 51, fp);
		pDicio[strlen(pDicio)-1] = '\0';

		//CHAMA A FUN��O QUE CALCULA O HASH
		//CHAMA A FUNC�O QUE INSERE NA TAELA HASH

		if(feof(fp)){
			break;
		}
	}
	fclose(fp);
}

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

		//CHAMA A FUNC�O QUE PESQUISA NA TAELA HASH

		if(feof(fp)){
			break;
		}
	}
	fclose(fp);
}

int main(void){

    LeDicionario();
    LeTexto();

    return 0;
}

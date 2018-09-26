int hash(char* palavra){ //#1 testar essa função em separado
	int h = 0;
	int i;
	for ( i = 0; i < strlen(palavra); ++i){
		h =  h + (palavra[i]) ;
	}
	h = h%qtbuckts;
	//h = (h-1);
	return h;
}

int stringParaInt(char *string) {
    int h, primeira, segunda; //Inteiros que representam o tamanho,
                                    //o código da primeira letra da string
                                    //e o código da segunda letra.
    tamanho =  strlen(string);      //Mede o tamanho da string
    primeira = string[0];           //Obtém o código da primeira letra
    segunda = string[1];            //Obtém o código da segunda letra
    int resultado = (tamanho * primeira) + segunda; //Função de transformação
    return resultado%qtbuckts;  //Retorna número que representa a string
    }

int hash(string v, int M) { //Método de Horner //M = qtd. de buckets
   int i, h = v[0];
   for (i = 1; v[i] != '\0'; i++) 
      h = (h * 251 + v[i]) % M;
   return h;
}


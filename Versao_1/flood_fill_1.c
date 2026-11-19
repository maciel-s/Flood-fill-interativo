#include <stdio.h>
#define linhas 10
#define colunas 16

const char cores[][8] = {
	"\033[30m", // 0 - preto
	"\033[31m", // 1 - vermelho
	"\033[32m", // 2 - verde
	"\033[33m", // 3 - amarelo
	"\033[34m", // 4 - azul
	"\033[35m", // 5 - magenta
	"\033[36m", // 6 - ciano
	"\033[37m", // 7 - branco
	"\033[90m", // 8 - cinza
};

void print_matrix(int I[linhas][colunas]) {
	printf("\n");
	for (int i = 0; i < linhas; i++) {
		printf("%d ", i);
		for (int j = 0; j < colunas; j++) {
			printf("%s%c", cores[I[i][j]], 35);
		}
		printf("\033[0m\n");
	}
	printf("\n");
}

void colorir(int i, int j, int nova_cor, int cor_atual, int I[linhas][colunas]) {

	//verifica se a coordenada esta fora dos limites da matriz
	if (i < 0 || i >= linhas || j < 0 || j >= colunas) {
        	return; //para de rodar 
        }
        
        //verifica se a nova cor é igual a cor atual e verifica se as cores da coordenadas é diferente da cor atual
        if (nova_cor == cor_atual || I[i][j] != cor_atual) {
        	return; //para de rodar
	}
	
	//pinta a posicao de partida com a nova cor
	I[i][j] = nova_cor;
	
	int alterou;
	
	//repete enquanto tiver posicoes a pintar
	do{
		alterou = 0; //redefine o sinalizador
		
		for(int l = 0; l < linhas; l++){
			for(int c = 0; c < colunas; c++){
				
				//procura posicoes que tenham a cor original
				if(I[l][c] == cor_atual){
				
					int vizinho_pintado = 0;
					
					//verifica se o vizinho de cima já tem a nova cor
                    			if (l > 0 && I[l - 1][c] == nova_cor) vizinho_pintado = 1;

                    			//verifica se o vizinho de Baixo já tem a nova cor
                    			if (l < linhas - 1 && I[l + 1][c] == nova_cor) vizinho_pintado = 1;

                    			//verifica se o vizinho da esquerda já tem a nova cor
                    			if (c > 0 && I[l][c - 1] == nova_cor) vizinho_pintado = 1;

                    			//verifica se o vizinho da direita já tem a nova cor
                    			if (c < colunas - 1 && I[l][c + 1] == nova_cor) vizinho_pintado = 1;

                    			//se encontrou algum vizinho já pintado, pinta esta posicao também
                    			if (vizinho_pintado) {
                       				 I[l][c] = nova_cor;
                       				 alterou = 1; //registra que a matriz sofreu alteracoes 
                    			}
				}
			}
		}
		
	} while(alterou);
}

int main() {
int i, j, nova_cor, cor_atual;
// Caso de teste 1:
/*int I[linhas][colunas] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
{0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};*/

// Caso de teste 2:
/*int I[linhas][colunas] = {
{3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
{3,3,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{3,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0},
{0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};*/

// Caso de teste 3:
int I[linhas][colunas] = {
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{7,7,7,7,7,7,7,3,3,7,7,7,7,7,7,7},
{7,7,7,7,7,7,3,3,3,3,7,7,7,7,7,7},
{7,7,7,7,7,7,3,3,3,3,7,7,7,7,7,7},
{7,7,7,7,7,7,7,3,3,7,7,7,7,7,7,7},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
};

// Caso de teste 4
/*int I[linhas][colunas] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,4,4,4,4,0,0,0,0,4,4,4,4,0,0},
    {0,4,4,4,4,4,4,0,0,4,4,4,4,4,4,0},
    {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0},
    {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0},
    {0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0},
    {0,0,0,4,4,4,4,4,4,4,4,4,4,0,0,0},
    {0,0,0,0,4,4,4,4,4,4,4,4,0,0,0,0},
    {0,0,0,0,0,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0}
};*/

// Caso de teste 5
/*int I[linhas][colunas] = {
{0,0,0,0,0,7,7,7,7,7,7,0,0,0,0,0},
{0,0,0,0,7,7,7,7,7,7,7,7,0,0,0,0},
{0,0,0,7,7,0,0,7,7,0,0,7,7,0,0,0},
{0,0,0,7,7,0,0,7,7,0,0,7,7,0,0,0},
{0,0,0,7,7,7,7,7,7,7,7,7,7,0,0,0},
{0,0,0,7,7,7,7,7,7,7,7,7,7,0,0,0},
{0,0,0,7,7,7,7,7,7,7,7,7,7,0,0,0},
{0,0,0,7,7,7,7,7,7,7,7,7,7,0,0,0},
{0,0,0,7,0,7,7,0,0,7,7,0,7,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};*/

// Caso de teste 6
/*int I[linhas][colunas] = {
{0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,7,7,0,0,0,0,0,0,0,0},
{0,0,0,0,0,7,7,7,0,0,0,0,0,0,0,0},
{0,0,0,0,7,7,7,7,0,0,0,0,0,0,0,0},
{0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0},
{0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
{0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};*/

	//garante a repetição do programa
	while (1){
		//imprimir a matriz original
		print_matrix(I);
		
		//solicitar a nova cor
		printf("Digite a cor entre 0 e 8 (-1 para sair): \n");
		scanf("%d", &nova_cor);
		
		//verificar se a nova cor é diferente de -1, se for, encerra
		if(nova_cor == -1){
			break;
		}
		
		//solicitar a linha e coluna para mudançça de cor
		printf("Digite a linha 'i': \n");
		scanf("%d", &i);
		
		printf("Digite a coluna 'j': \n");
		scanf("%d", &j);
		
		//verificar se a linha e coluna estão dentro dos limites da matriz
		if(i >= 0 && i < linhas && j >= 0 && j < colunas){
		
			//guarda cor atual
			int cor_atual = I[i][j];
			
			//verificar se a nova cor é diferente da atual
			if(cor_atual != nova_cor){
				//chama a funcao colorir
				colorir(i, j, nova_cor, cor_atual, I);
			}
		}
	//repete
	}
}



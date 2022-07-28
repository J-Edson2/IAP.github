#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct cidade {
	int codigo;
	char nome[100];
	float celsius;
	float fahrenheit;
}CIDADE;

float conversor(float cs) {
	return ((9*cs)/5)+32;
}

struct cidade *gera_cidade (int cod, char nome[],float cels) {
	CIDADE *cid = (struct cidade*) malloc(sizeof(struct cidade));
	cid->codigo = cod;
	strcpy(cid->nome,nome);
	cid->celsius = cels;
	cid->fahrenheit = conversor(cels);
	return cid;
}


void vet_cidade(CIDADE vet[], int tam_vet) {
	for (int i = 0; i < tam_vet; i++) {
		printf("CIDADE : %s \nCÓDIGO : %d \nTEMPERATURA :\n(%f) celsius \n(%f)fahrenheit \n", vet[i].nome, vet[i].codigo, vet[i].celsius, vet[i].fahrenheit);
	    printf("\n \n");
	}
}

CIDADE *func(CIDADE vet[], int cod, int tam_vet) {
	for(int i = 0; i<=tam_vet;i++){
		if(vet[i].codigo == cod){
			return &vet[i];
		}
	}
	return NULL;
}

void altera_temperatura(CIDADE *cid, float numero) {
	cid->celsius = numero;
	cid->fahrenheit = conversor(numero);

}


int main(){
	setlocale(LC_ALL,"portuguese");
	struct cidade vet[3];

	char nome[100] = "Barbalha";
	vet[0] = *gera_cidade(1, nome, 40);
	printf("CIDADE : %s \nCÓDIGO : %d \nTEMPERATURA :\n(%f) celsius \n(%f)fahrenheit \n", vet[0].nome, vet[0].codigo, vet[0].celsius, vet[0].fahrenheit);
	printf("\n \n");
	
	strcpy(nome, "juazeiro");
	vet[1] = *gera_cidade(2, nome, 35);
	printf("CIDADE : %s \nCÓDIGO : %d \nTEMPERATURA :\n(%f) celsius \n(%f)fahrenheit \n", vet[1].nome, vet[1].codigo, vet[1].celsius, vet[1].fahrenheit);
	printf("\n \n");
	
	strcpy(nome, "fortaleza");
	vet[2] = *gera_cidade(3, nome, 25);
	printf("CIDADE : %s \nCÓDIGO : %d \nTEMPERATURA :\n(%f) celsius \n(%f)fahrenheit \n", vet[2].nome, vet[2].codigo, vet[2].celsius, vet[2].fahrenheit);
	printf("\n \n");
	printf("PROCEDIMENTO\n");
	printf("\n \n");

	vet_cidade(vet,3);
	
	int opcao = 1;
	int posicao = -1;
	float nova = 0;
	int achou = 0;
	
	
	do {
		printf("[1]->LISTAR \n[2]->ALTERAR TEMPERATURA \n[0]->sair \n");
		scanf("%d", &opcao);
		switch (opcao) {
			case 1: {
				vet_cidade(vet, 3);
				break;
			}
			case 2: {
				printf("Digite o codigo da cidade que vc quer alterar\n");
				scanf("%d", &posicao);
				fflush(stdin);
				if(posicao < 0) {
					printf("Opcao invalida\n");
				}
				
				int i= 0;
				for(; i < 3; i++) {
					if(posicao == vet[i].codigo){
						printf("digiteo novo valor: ");
						scanf("%f", &nova);
						fflush(stdin);
						vet[i].celsius = nova;
						vet[i].fahrenheit = conversor(nova);
						achou = 1;
						break;
					}
					else {
						achou = 0;
					}
				}
				if(!achou) printf("Não encotrado\n"); 
				break;
				
			}
			case 0: {
				printf("Programa encerrado!\n");
				opcao = 0;
				break;
			}
				
		}
	} while (opcao != 0);
			
	return 0;
}


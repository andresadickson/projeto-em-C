#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 200

typedef struct dados{
	int codigo;
	int ano;
	int status;
	int numero_funcionarios;
	char titulo[30];
	char descricao[50];
	char gerente[30];
	char linguagem[30];
	char empresa_hospedagem[30];
	float custo;

}base_projetos;

int posicao = 0;

void cadastrarProjeto(base_projetos cadastro[MAX]);
void relatorioProjeto(base_projetos cadastro[MAX]);
void buscarCodigo(base_projetos cadastro[MAX]);
void buscarStatus(base_projetos cadastro[MAX], int status);
void buscarAno(base_projetos cadastro[MAX]);
void imprimirDados(base_projetos cadastro[MAX], int indice);

int main(){
	setlocale(LC_ALL, "Portuguese");
	base_projetos cadastro[MAX];
	
	int escolha;
	
	system("cls");	
	do{
		system("cls");
		printf("****************************************************");
		printf("\n GESTÃO DE PROJETO ");
		printf("\n****************************************************");
		printf("\n Escolha uma opção do menu: ");
		printf("\n 1 - Cadastro Projeto");
		printf("\n 2 - Relatório de Dados");
		printf("\n 3 - Busca por Código");
		printf("\n 4 - Busca por Ano");
		printf("\n 5 - Relatório dos Projetos com status [1] A fazer");
		printf("\n 6 - Relatório dos Projetos com status [2] Fazendo");
		printf("\n 7 - Relatório dos Projetos com status [3] Concluído");
		printf("\n 8 - Sair\n");
		printf("\n Digite sua opção: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				relatorioProjeto(cadastro);
				break;
			case 3:
				buscarCodigo(cadastro);
				break;
			case 4:
				buscarAno(cadastro);
				break;
			case 5:
				buscarStatus(cadastro, 1);
				break;
			case 6:
				buscarStatus(cadastro, 2);
				break;
			case 7:
				buscarStatus(cadastro, 3);
				break;
			case 8:
				printf("\nSaindo da Aplicação\n");
				system("Pause");
				break;
			default:
				printf("\nOpção inexistente\n");
				system("Pause");
		}
	}while(escolha != 8);
	return 0;
}

void cadastrarProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n CADASTRO");
	printf("\n***************************************");
	char resp = 's';
	
	while(resp == 's' && posicao <= MAX){
		posicao++;
		printf("\nCódigo: %d ", posicao);
		cadastro[posicao].codigo = posicao;
		printf("\nInforme o Título do projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].titulo);
		
		printf("\nInforme a descrição do projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].descricao);
		
		printf("\nInforme a linguagem que será usada no projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].linguagem);
		
		printf("\nInforme o ano: ");
		fflush(stdin);
		scanf("%d", &cadastro[posicao].ano);
		
		printf("\nInforme o gerente do projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].gerente);
		
		printf("\nInforme a empresa de hospedagem: ");
		fflush(stdin);
		gets(cadastro[posicao].empresa_hospedagem);
		
		printf("\nInforme o custo do projeto: ");
		fflush(stdin);
		scanf("%f", &cadastro[posicao].custo);
		
		printf("\nInforme o número de funcionários envolvidos: ");
		fflush(stdin);
		scanf("%d", &cadastro[posicao].numero_funcionarios);
		
		printf("\nInforme o status: [1] - A fazer, [2] - Fazendo, [3] - Concluído: ");
		fflush(stdin);
		scanf("%d", &cadastro[posicao].status);
		
		if(posicao < MAX){
			printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Não: ");
			fflush(stdin);
			scanf("%c", &resp);
		}else{
			printf("\nSua base de Dados já chegou ao limite!!!\n");
			resp = 'n';
		}
	}
}
void relatorioProjeto(base_projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n RELATORIO ");
	printf("\n***************************************\n");
	int linha=1;
	
	if(posicao >= 1){
		while(linha <= posicao){
			imprimirDados(cadastro, linha);
			linha++;
		}	
			
	}else{
		printf("\nNão há registros cadastrados\n");
	}	
	system("Pause");
}

void buscarCodigo(base_projetos cadastro[MAX])
{
	system("cls");
	int codigo, achou;
	printf("***************************************");
	printf("\n BUSCA POR CÓDIGO ");
	printf("\n***************************************");
	printf("\nDigite o código desejado: ");
	scanf("%d", &codigo);
	achou = 0;
	int j = 1;
	
	while((achou == 0) && (j <= posicao)){
		if(codigo == cadastro[j].codigo){
			
			imprimirDados(cadastro, j);
			achou = 1;
			system("Pause");
		}
		j++;
	}
		if(achou == 0 ){
			printf("\nCódigo inexistente %d \n", codigo);
			system("Pause");
		}
}

void buscarAno(base_projetos cadastro[MAX])
{
	system("cls");
	int ano, achou;
	printf("***************************************");
	printf("\n BUSCA POR ANO ");
	printf("\n***************************************");
	printf("\nDigite o Ano desejado: ");
	scanf("%d", &ano);
	achou = 0;
	int j = 1;
	
	while(j <= posicao){
		if(ano == cadastro[j].ano){
			imprimirDados(cadastro, j);
			achou = 1;
		}
		j++;
	}
	
	if(achou == 0 ){
		printf("\nRegistros com o ano %d, não foram encontrados\n", ano);
	}
	system("Pause");
}
void buscarStatus(base_projetos cadastro[MAX], int status){
	system("cls");
	int j = 1;
	int achou = 0;
	if(posicao >= 1){
		while(j <= posicao){
			if(cadastro[j].status == status){
				imprimirDados(cadastro, j);
				achou = 1;
			}
			j++;
		}
	}
	
	if(achou == 0){
		printf("\nNenhum registro com o status %d\n", status);
		fflush(stdin);
	}
	
	system("Pause");
}


void imprimirDados(base_projetos cadastro[MAX], int indice){
	printf(
			"Código: %d\nTítulo: %s\nDescrição: %s\nLinguagem Utilizada: %s\nAno: %d\nGerente: %s\nEmpresa Hospedagem: %s\nCusto: %.2f\nNumero Funcionarios: %d\nStatus: %d\n",
			cadastro[indice].codigo, 
			cadastro[indice].titulo, 
			cadastro[indice].descricao, 
			cadastro[indice].linguagem, 
			cadastro[indice].ano, 
			cadastro[indice].gerente, 
			cadastro[indice].empresa_hospedagem, 
			cadastro[indice].custo, 
			cadastro[indice].numero_funcionarios, 
			cadastro[indice].status
			);
			
	fflush(stdin);
	printf("\n***************************************\n");
	fflush(stdin);
}

#include <stdio.h> // biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texpo por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// Inic�o da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	// Final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); // Coletando informa��es do usu�rio
	scanf("%s", cpf); // refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write,escrever
	fprintf(file,cpf); // salva o valor da v�riavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" de atualizar arquivo
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
			
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" de read
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar()
{
	

	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema!.\n");
		system("pause");
	}
	
	fclose(file);
	
	
		
}


int main()
{
	int opcao = 0; // Definindo v�riaveis
	int contador = 1;
	
	for(contador = 1;contador = 1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); // Armazena a escolha do usu�rio
	
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			consulta();		
			break;
			
			case 3:
			deletar();			
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; // Quebra la�o, fun��o e sai do sistema
			break;
			
			
			default:
			printf("Essa opc��o n�o esta dispon�vel!\n");
			system("pause");
			break;
				
		} // Fim da sele��o
	
		
	
	}
	
}

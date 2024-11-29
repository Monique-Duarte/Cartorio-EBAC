#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de aloca��o de texto por regi�o, exemplo acentua��o
#include <string.h> //biblioteca de aloca��o de string


int registro () // Fun��o respons�vel por cadastrar os registros
{   
	//inicio da cria��o das vari�veis
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [100];
	char cargo [40];
	//final da cria��o das vari�veis
	
	printf ("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a string, salvar em uma string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file;  // Cria��o de arquivo, acessa o FILE e cria o file
	file = fopen (arquivo, "w"); //Criando um arquivo com o nome do cpf que foi passado, "w"= escrita
	fprintf (file, cpf); // salva o valor da vari�vel dentro do arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // "a" atualizar o arquivo j� criado
	fprintf (file, ","); // inserindo "," na separa��o dos dados
	fclose(file); //fechamento do arquivo
	
	
	printf ("Digite o nome a ser cadastrado:  "); //coletando informa��es do usu�rio
	scanf("%s", nome); // %s refere-se a string
	file = fopen (arquivo, "a"); 
	fprintf (file, nome); 
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ","); 
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado:  "); //coletando informa��es do usu�rio
	scanf("%s", sobrenome); // %s refere-se a string
	file = fopen (arquivo, "a"); 
	fprintf (file, sobrenome); 
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ","); 
	fclose(file);	

	printf ("Digite o cargo a ser cadastrado:  "); //coletando informa��es do usu�rio
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose(file);
		
	system("pause");
	
}

int consultar ()
{
	setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
	char cpf [40];
	char conteudo [250];
	
	printf ("Digite o CPF a ser consultado:  ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); // "r"= leitura
	
	if (file == NULL)
	{
		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 250, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
		system("pause");
}


int deletar ()
{
	setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
	char cpf [40];
	
	printf ("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s", cpf);
	
	remove (cpf); // deletar o dado
	
	FILE *file;
	file = fopen (cpf, "r"); // "r"= leitura
	
	if (file == NULL);
	{
		printf ("Usu�rio deletado!. \n");
	}
	
	system("pause");
}



int main ()
	{
	int opcao=0; // Definindo as vari�veis
	int repit=1;
	
	for (repit=1;repit=1;)
	{
		system("cls"); //limpa a tela
					
		setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem

		printf (" ### Cart�rio da EBAC ### \n\n\n"); // inicio do menu
		printf ("Escolha a op��o desejada do menu: \n\n");
		printf ("\t1 - Registrar nomes \n\n");
		printf ("\t2 - Consultar nomes \n\n");
		printf ("\t3 - Deletar nomes \n\n");
		printf ("\t4 - Sair do sistema\n\n\n");
		printf("Op��o:   "); // Final do menu
	
		scanf ("%d", &opcao); // armazenando a escolha ao usu�rio
		
		system("cls"); //limpa a tela
		
		switch(opcao)
		{	
			case 1: 
			registro (); //chamada de fun��es
			break;
			
			case 2:
			consultar (); //chamada de fun��es
			break;
			
			case 3:
			deletar (); //chamada de fun��es
			break;
			
			case 4:
			printf ("Obrigada por utilizar o programa!\n\n");
			return 0;
			break;
			
			default:
			printf ("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
					
	} //fim da sess�o for

}


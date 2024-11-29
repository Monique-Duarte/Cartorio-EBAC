#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de alocação de texto por região, exemplo acentuação
#include <string.h> //biblioteca de alocação de string


int registro () // Função responsável por cadastrar os registros
{   
	//inicio da criação das variáveis
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [100];
	char cargo [40];
	//final da criação das variáveis
	
	printf ("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); // %s refere-se a string, salvar em uma string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file;  // Criação de arquivo, acessa o FILE e cria o file
	file = fopen (arquivo, "w"); //Criando um arquivo com o nome do cpf que foi passado, "w"= escrita
	fprintf (file, cpf); // salva o valor da variável dentro do arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // "a" atualizar o arquivo já criado
	fprintf (file, ","); // inserindo "," na separação dos dados
	fclose(file); //fechamento do arquivo
	
	
	printf ("Digite o nome a ser cadastrado:  "); //coletando informações do usuário
	scanf("%s", nome); // %s refere-se a string
	file = fopen (arquivo, "a"); 
	fprintf (file, nome); 
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ","); 
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado:  "); //coletando informações do usuário
	scanf("%s", sobrenome); // %s refere-se a string
	file = fopen (arquivo, "a"); 
	fprintf (file, sobrenome); 
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, ","); 
	fclose(file);	

	printf ("Digite o cargo a ser cadastrado:  "); //coletando informações do usuário
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
		printf ("Não foi possível abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 250, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
		system("pause");
}


int deletar ()
{
	setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
	char cpf [40];
	
	printf ("Digite o CPF do usuário a ser deletado:  ");
	scanf("%s", cpf);
	
	remove (cpf); // deletar o dado
	
	FILE *file;
	file = fopen (cpf, "r"); // "r"= leitura
	
	if (file == NULL);
	{
		printf ("Usuário deletado!. \n");
	}
	
	system("pause");
}



int main ()
	{
	int opcao=0; // Definindo as variáveis
	int repit=1;
	
	for (repit=1;repit=1;)
	{
		system("cls"); //limpa a tela
					
		setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem

		printf (" ### Cartório da EBAC ### \n\n\n"); // inicio do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t1 - Registrar nomes \n\n");
		printf ("\t2 - Consultar nomes \n\n");
		printf ("\t3 - Deletar nomes \n\n");
		printf ("\t4 - Sair do sistema\n\n\n");
		printf("Opção:   "); // Final do menu
	
		scanf ("%d", &opcao); // armazenando a escolha ao usuário
		
		system("cls"); //limpa a tela
		
		switch(opcao)
		{	
			case 1: 
			registro (); //chamada de funções
			break;
			
			case 2:
			consultar (); //chamada de funções
			break;
			
			case 3:
			deletar (); //chamada de funções
			break;
			
			case 4:
			printf ("Obrigada por utilizar o programa!\n\n");
			return 0;
			break;
			
			default:
			printf ("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
					
	} //fim da sessão for

}


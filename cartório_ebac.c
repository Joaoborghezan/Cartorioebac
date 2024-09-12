#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o, essa vai deixar colocar acentos sem dar erro na escrita
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o p�ra registro de usu�rio
{
	
	setlocale(LC_ALL, "Portuguese");
	
	//cira��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final da cria��o de vari�veis
	
	printf("Qual o CPF a ser cadastrado: \n\n\n");
	scanf("%s", cpf);
	//porcentagem s vai armazenar da string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquvio 
	file = fopen(arquivo, "w"); //cria o arquivo, o W � de write para escrever novos
	fprintf(file,cpf); //igual o printf, ao inv�s de passar pro usu�rio ele salva no arquivo
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo, "a"); // o A serve para atualizar a informa��o
	fprintf(file,","); //virgula serve para separar as informa��es com v�rgula
	fclose(file);
	
	printf("Digite o nome a ser cadastado: \n\n\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n\n\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n\n\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n\n\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); 
	//o R sirgnifica read - ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o localizamos esse CPF, por favor verificar o n�mero digitado! \n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	// vai buscar, vai buscar conteudo, tamanho m�ximo desse conte�do, e qual arquivo ele vai achar
	//while significa enquanto tiver
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);//usar printf pra mostrar a informa��o ao usu�rio.
		printf("\n\n");
	}
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //serve apenas para deletar
	
	FILE *file;
	file =fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o est� cadastrado no sistema, por favor inserir um CPF v�lido. \n\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;
	//apenas um igual � para atribuir um valor
	int x=1;
		
	for(x=1;x=1;)
	//for quer dizer fa�a, usamos o x=1;x=1; ele ir� continuar infinitamente, sempre voltando para o menu
	{
		
		system("cls");
		//esse comando vai limpar a tela, como se fosse redirecionar o usu�rio para uma outra tela de um site ap�s ele escolher uma op��o
		
		setlocale(LC_ALL, "Portuguese");
		// essa fun��o acima tem que colocar para poder usar acentos, para puxar a regi�o
	
		printf("### Cadastro de Alunos da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes \n\n\n");
		printf("Digite qual op��o voc� deseja: ");
		// a fun��o \t serve para dar um tab na interface do programa
	
		scanf("%d", &opcao);//serve para a resposta do usu�rio da op��o 1, 2 ou 3 para passar para o switch opcao
	
		system("cls");
		//esse comando vai limpar a tela, como se fosse redirecionar o usu�rio para uma outra tela de um site ap�s ele escolher uma op��o
		
		switch(opcao)
		{
			case 1://caso seja 1, vai para registro,2 consulta e 3 deletar
			registro();
			break;
			//essa fun��o fecha os dois pontos
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;	
		
			default:
			//usamos default para informar que � diferente do padr�o ou nenhuma das op��es
			printf("Essa op��o n�o est� dispon�vel, por favor insira um n�mero v�lido entre 1, 2 ou 3\n\n\n");
			system("pause");
			break;
		}
	 
		printf("Esse software � de livre uso e teste\n\n\n");
	}
}

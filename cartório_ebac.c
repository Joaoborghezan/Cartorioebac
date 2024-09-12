#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região, essa vai deixar colocar acentos sem dar erro na escrita
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função pára registro de usuário
{
	
	setlocale(LC_ALL, "Portuguese");
	
	//ciração de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final da criação de variáveis
	
	printf("Qual o CPF a ser cadastrado: \n\n\n");
	scanf("%s", cpf);
	//porcentagem s vai armazenar da string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquvio 
	file = fopen(arquivo, "w"); //cria o arquivo, o W é de write para escrever novos
	fprintf(file,cpf); //igual o printf, ao invés de passar pro usuário ele salva no arquivo
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo, "a"); // o A serve para atualizar a informação
	fprintf(file,","); //virgula serve para separar as informações com vírgula
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
		printf("Não localizamos esse CPF, por favor verificar o número digitado! \n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	// vai buscar, vai buscar conteudo, tamanho máximo desse conteúdo, e qual arquivo ele vai achar
	//while significa enquanto tiver
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo);//usar printf pra mostrar a informação ao usuário.
		printf("\n\n");
	}
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //serve apenas para deletar
	
	FILE *file;
	file =fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não está cadastrado no sistema, por favor inserir um CPF válido. \n\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;
	//apenas um igual é para atribuir um valor
	int x=1;
		
	for(x=1;x=1;)
	//for quer dizer faça, usamos o x=1;x=1; ele irá continuar infinitamente, sempre voltando para o menu
	{
		
		system("cls");
		//esse comando vai limpar a tela, como se fosse redirecionar o usuário para uma outra tela de um site após ele escolher uma opção
		
		setlocale(LC_ALL, "Portuguese");
		// essa função acima tem que colocar para poder usar acentos, para puxar a região
	
		printf("### Cadastro de Alunos da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes \n\n\n");
		printf("Digite qual opção você deseja: ");
		// a função \t serve para dar um tab na interface do programa
	
		scanf("%d", &opcao);//serve para a resposta do usuário da opção 1, 2 ou 3 para passar para o switch opcao
	
		system("cls");
		//esse comando vai limpar a tela, como se fosse redirecionar o usuário para uma outra tela de um site após ele escolher uma opção
		
		switch(opcao)
		{
			case 1://caso seja 1, vai para registro,2 consulta e 3 deletar
			registro();
			break;
			//essa função fecha os dois pontos
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;	
		
			default:
			//usamos default para informar que é diferente do padrão ou nenhuma das opções
			printf("Essa opção não está disponível, por favor insira um número válido entre 1, 2 ou 3\n\n\n");
			system("pause");
			break;
		}
	 
		printf("Esse software é de livre uso e teste\n\n\n");
	}
}

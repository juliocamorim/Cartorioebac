#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto po região
#include <string.h> //biblioteca responsável por cuidar dos string


int registro()  //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];									
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis

    printf(" \n #### Digite o CPF a ser cadastrado: ");  //coletando informação do usuário
    scanf("%s", cpf);  //%s refere-se o string
    
    strcpy(arquivo, cpf);  //responsável por copiar os valores da string
    
    FILE *file;      //cria o arquivo
    file = fopen(arquivo, "w");   //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);  //salva o valor da variável
    fclose(file);   // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, ","); //salva o valor da variável
    fclose(file); // fecha o arquivo
    
    printf(" \n #### Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file,nome); //salva o valor da variável
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, ","); //salva o valor da variável
    fclose(file); // fecha o arquivo
    
    printf(" \n #### Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file,sobrenome); //salva o valor da variável
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, ","); //salva o valor da variável
    fclose(file); // fecha o arquivo
     
    printf(" \n #### Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo); //salva o valor da variável
    fclose(file); // fecha o arquivo
    
    system("pause"); 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");   //definindo a linguagem
	
	//início da criação de variáveis
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis
	
	printf(" \n #### Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo! \n\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf(" Essas são as informações do usuário! \n\n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int exclusao()
{
    //início da criação de variável
	char cpf[40];
    //fim da criação de variável
        
    printf("\n #### Digite o CPF do usuário a ser excluído: \n");
    scanf("%s",cpf);
		FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
}

int main()
{
	int opcao=0;    //definindo variavéis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	
	printf(" \n ### Cartório da EBAC \n\n\n ###");
	printf(" Login de Administrador! \n\n ### Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(senhadigitada[10] = "admin");
	
	if(comparacao == 0)

	{
	    system ("cls");
	    for(laco=1;laco=1;)
      {
	 
	     system("cls");
	 
	      setlocale(LC_ALL, "Portuguese");   //definindo a linguagem
	
        	printf("######### Cartório da EBAC ####### \n\n");  //início do menu
    	    printf(" #### Escolha a opção desejada do Menu \n\n");
        	printf("\t1 - Registro de Nomes \n\n");
    	    printf("\t2 - Consulta de Nomes \n\n");
        	printf("\t3 - Exclusão de Nomes \n\n");
     	    printf("\t4 - Sair do Sistema! \n\n");
    	    printf("Opção:  ");         //fim do menu
	 
    	    scanf("%d",&opcao);   //armazenando a escolha do usuário
	
            system("cls"); //responsável por limpar a tela
	
    	    switch(opcao)  //início da seleção de menu
    	    { 
	            case 1:
	            registro(); //chamada de funções
	            break;
	   	
	            case 2:
	            consulta(); 
	            break;
	   	  
    	        case 3:
    	        exclusao();
  	            break;
	         
	            case 4:
	            printf(" \n Obrigado por utilizar o sistema! \n"); 
	            return 0;
	            break;
	     
	            default:
	            printf(" Está opção não está disponível! \n "); 
	            system("pause");
	            break;
	        }
     	}
	}
	
	else
        printf("\n\n ### Senha Incorreta! \n\n"); 
}


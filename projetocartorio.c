#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto po regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string


int registro()  //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];									
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis

    printf(" \n #### Digite o CPF a ser cadastrado: ");  //coletando informa��o do usu�rio
    scanf("%s", cpf);  //%s refere-se o string
    
    strcpy(arquivo, cpf);  //respons�vel por copiar os valores da string
    
    FILE *file;      //cria o arquivo
    file = fopen(arquivo, "w");   //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);  //salva o valor da vari�vel
    fclose(file);   // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, ","); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    printf(" \n #### Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file,nome); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, ","); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    printf(" \n #### Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file,sobrenome); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, ","); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
     
    printf(" \n #### Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo); //salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    system("pause"); 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");   //definindo a linguagem
	
	//in�cio da cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis
	
	printf(" \n #### Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo! \n\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf(" Essas s�o as informa��es do usu�rio! \n\n ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int exclusao()
{
    //in�cio da cria��o de vari�vel
	char cpf[40];
    //fim da cria��o de vari�vel
        
    printf("\n #### Digite o CPF do usu�rio a ser exclu�do: \n");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
	
	if(file == NULL);
	{
        printf(" Este usu�rio foi exclu�do com sucesso! \n");
        system("pause");
	}        
}

int main()
{
	int opcao=0;    //definindo variav�is
	int laco=1;
	
	for(laco=1;laco=1;)
   {
	 
	  system("cls");
	 
	  setlocale(LC_ALL, "Portuguese");   //definindo a linguagem
	
    	printf("######### Cart�rio da EBAC ####### \n\n");  //in�cio do menu
    	printf(" #### Escolha a op��o desejada do Menu \n\n");
    	printf("\t1 - Registro de Nomes \n\n");
    	printf("\t2 - Consulta de Nomes \n\n");
     	printf("\t3 - Exclus�o de Nomes \n\n");
    	printf("Op��o:  ");         //fim do menu
	 
    	scanf("%d",&opcao);   //armazenando a escolha do usu�rio
	
        system("cls"); //respons�vel por limpar a tela
	
    	switch(opcao)  //in�cio da sele��o de menu
    	{ 
	        case 1:
	        registro(); //chamada de fun��es
	        break;
	   	
	        case 2:
	        consulta(); 
	        break;
	   	 
    	    case 3:
  	        exclusao();
	        break;
	     
	        default:
	        printf(" Est� op��o n�o est� dispon�vel! \n ");
	        system("pause");
	        break;
	    }
	}
}

#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblio de alocação de texto por região
#include <string.h> //biblio de strings

int registrar()
   {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf); //salvando na string
    strcpy(arquivo, cpf); //copiar valores de string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file, cpf); //salva o valor da variavel
    fclose(file); //fechar arquivo
    
    file = fopen(arquivo, "a"); //abrir o arquivo de texto
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:\n");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:\n");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:\n");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    
   }


int consulta()
   {
    setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
	
	char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado:\n");
    scanf("%s", cpf); //salvando na string
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL) 
    {printf("Arquivo não localizado.\n");}
    
    while( fgets(conteudo, 200, file) != NULL)
   {
   	 printf("\nEssas são as informações do usuário.");
   	 printf("%s", conteudo);
   	 printf("\n\n");
   }
    
	fclose(file);
	system("pause");
    
   }


int deletar()
   {
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lê o arquivo
	
	if(file == NULL)
	{ printf("User não se encontra no sistema.\n");
	  system("pause"); }
	
	fclose(file);
   }

    
	int main()
{
	int opcao=0; //definindo variável 
	int x=1;
  
  
      for (x=1;x=1;)
	  {
	 
	  system("cls"); //limpa a tela
	  setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
	
	  printf("\t### Cartório da EBAC ###\n\n"); //inicio do menu
	  printf("\tEscolha a opção desejada:\n\n");
	  printf("\t 1 - Registrar nomes:\n");
	  printf("\t 2 - Consultar nomes:\n");
	  printf("\t 3 - Deletar nomes:\n");
	  printf("\t 4 - Sair do sistema:\n\n");
	  printf("\t Este software pertence a você.\n\n");
	  printf("\t opção:");   //fim do menu
	
	  scanf("%d", &opcao); //armazenando escolhas do user
	  system("cls"); //limpa a tela
	 
	    switch(opcao)
        
		{
	      case 1:
          registrar();
		  break;
		
		  case 2:
	  	  consulta();
		  break;
		  
		  case 3:
		  deletar();
 	      break;
 	      
 	      case 4:
 	      printf("\nObrigado por utilizar nosso sistema!\n\n\n");
 	      return 0;
 	      break;
 	      	
 	      default:
 	      printf("Essa opção não está disponível.\n\n");
	      system("pause");
		  break;
		  
	    } //fim do switch
	    
	   	
	  
      
	  }
}


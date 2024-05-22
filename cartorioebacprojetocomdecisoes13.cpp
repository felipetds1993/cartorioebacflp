#include <stdio.h>//biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria 
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()//fun��o responsavel por cadastrar os usuarios no sistema 
{
    //inicio cria��o de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis/string
    
    printf("digite o cpf a ser cadastrado: ");//coletando informa��o do usuario
    scanf("%s",cpf);//%s refere-se a string
    
    strcpy(arquivo,cpf);//responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w");//cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salvo o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//cria o arquivo e o "a" significa anexar 
    fprintf(file,",");//salvo v�rgula no arquivo
    fclose(file);//fecha o arquivo
    
    printf("digite o nome a ser cadastrado: ");//coletando nome do usuario
    scanf("%s",nome);//armazenar nome na string
    
    file = fopen(arquivo,"a");//cria o arquivo e o "a" significa anexar 
    fprintf(file,nome);//salvo nome do usuario
    fclose(file);//fecha o arquivo
    
    printf("digite o sobrenome a ser cadastrado: ");//coletando sobrenome do usuario
    scanf("%s",sobrenome);// armazenar sobrenome na string 
    
    file = fopen(arquivo,"a");//cria o arquivo e o "a" significa anexar 
    fprintf(file,sobrenome);//salvo sobrenome do usuario 
    fclose(file);//fecha o arquivo 
    
    file = fopen(arquivo,"a");//cria o arquivo e o "a" significa anexar
    fprintf(file,",");//salvo virgula no arquivo
    fclose(file);//fecha o arquivo
    
    printf("digite o cargo a ser cadastrado: ");//coletando cargo a ser cadastrado
    scanf("%s",cargo);//armazenar cargo na string 
    
    file = fopen(arquivo,"a");//cria o arquivo e o "a" significa anexar 
    fprintf(file,cargo);//salvo cargo no arquivo
    fclose(file);//fecha o arquivo 
    
    system("pause");//usado para pausar a execu��o do programa
    
    
    }

int consulta()
{
    char cpf[40];
    char conteudo[200];
    
    printf("digite o CPF a ser consultado: ");//coletando cpf para consulta 
    scanf("%s",cpf);//armazenar cpf na string 
    
    FILE * file;//cria o arquivo
    file = fopen(cpf,"r");//cria o arquivo e o "r" significa leitura da string  
    
    if(file == NULL)
    {
    printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");//arquivo n�o localizado
       
    }
    
    while(fgets(conteudo,200,file)!= NULL)//n�o h� mais linhas para ler no arquivo
    {
    printf("\n essas s�o as informa�oes do usu�rio");//informa��es do usu�rio est�o prestes a serem exibidas
    printf("%s",conteudo);//refere-se a string conteudo
    printf("\n\n");//linha de espa�o 
    }
    
    system("pause");//usado para pausar a execu��o do programa
}

int deletar()    
{   
    char cpf[40];
    
    printf("digite o cpf do usuario a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
            printf("o usuario n�o se encontra no sistema!.\n");
            system("pause");//usado para pausar a execu��o do programa
            
            }
            
    }

int main()
{
    int opcao=0;//Definindo variaveis
    int laco=1;//verificando valor 
    
    for(laco=1;laco=1;)
    {
                       
    system("cls");//responsavel por limpar a tela   
                  
    setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
    
    printf("###cartorio da EBAC###\n\n");//Inicio do menu
    printf("escolha a op��o desejada do menu:\n\n");
    printf("\t1-Registrar nomes\n");
    printf("\t2-Consultar nomes\n");
    printf("\t3-Deletar nomes\n\n");
    printf("op��o:");//Fim do menu; 
    
    scanf("%d",&opcao);//Armazenando a escolha do usuario; 
    
    system("cls");//responsavel por limpar a tela 
    
       switch(opcao)//inicio da sele��o do menu
       {
             case 1:
             registro();//chamada de fun��es
             break;
                                  
             case 2:
             consulta();//consulta de fun��es
             break;
                                  
             case 3:
             deletar();//deletar fun��es
             break;
             
                                         
             default:
             printf("essa op��o n�o est� disponivel!\n");
             system("pause");
             break;
        }        
            
    }
}

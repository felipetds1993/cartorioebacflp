#include <stdio.h>//biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria 
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()//função responsavel por cadastrar os usuarios no sistema 
{
    //inicio criação de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis/string
    
    printf("digite o cpf a ser cadastrado: ");//coletando informação do usuario
    scanf("%s",cpf);//%s refere-se a string
    
    strcpy(arquivo,cpf);//responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w");//cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salvo o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo,"a");//cria o arquivo e o "a" significa anexar 
    fprintf(file,",");//salvo vírgula no arquivo
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
    
    system("pause");//usado para pausar a execução do programa
    
    
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
    printf("não foi possivel abrir o arquivo, não localizado!.\n");//arquivo não localizado
       
    }
    
    while(fgets(conteudo,200,file)!= NULL)//não há mais linhas para ler no arquivo
    {
    printf("\n essas são as informaçoes do usuário");//informações do usuário estão prestes a serem exibidas
    printf("%s",conteudo);//refere-se a string conteudo
    printf("\n\n");//linha de espaço 
    }
    
    system("pause");//usado para pausar a execução do programa
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
            printf("o usuario não se encontra no sistema!.\n");
            system("pause");//usado para pausar a execução do programa
            
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
    printf("escolha a opção desejada do menu:\n\n");
    printf("\t1-Registrar nomes\n");
    printf("\t2-Consultar nomes\n");
    printf("\t3-Deletar nomes\n\n");
    printf("opção:");//Fim do menu; 
    
    scanf("%d",&opcao);//Armazenando a escolha do usuario; 
    
    system("cls");//responsavel por limpar a tela 
    
       switch(opcao)//inicio da seleção do menu
       {
             case 1:
             registro();//chamada de funções
             break;
                                  
             case 2:
             consulta();//consulta de funções
             break;
                                  
             case 3:
             deletar();//deletar funções
             break;
             
                                         
             default:
             printf("essa opção não está disponivel!\n");
             system("pause");
             break;
        }        
            
    }
}

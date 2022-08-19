#include<stdio.h>
#include<string.h>

typedef struct
{
    int codigo;
    char descricao[30];
    int idade;
    double preco;

}Registro;


void cadastrar(Registro reg);
void visualizar(Registro reg);
void buscarumRegistro(Registro reg);
void buscarRegistros(Registro reg);


int main()
{
     Registro reg;
    int n = -1;
    

     printf("\n\t1-cadastrar\n\t2-visualizar\n\t3-buscar um registro\n\t4-buscar registros\n\t5-finalizar \n");
    
    while(n != 0){
    printf("\tInforme o modulo desejado: ");
    scanf("%i", &n);
    switch(n)
    {
    case 1:
        cadastrar(reg);
        
        break;
    case 2:
        visualizar(reg);
      
       break;
    case 3:
	    buscarumRegistro(reg);
        
       break;
    case 4:
	    buscarRegistros(reg);
        
       break;
    case 5:
	   return 0;

       break;
    }
}
}
void cadastrar(Registro reg)
{
    FILE *arq;

    arq = fopen("exame.txt","a");
    printf("\tDigite o codigo: ");
    scanf("%i", &reg.codigo);
    setbuf(stdin,NULL);
    printf("\tDigite a descricao: ");
    fflush(stdin);
    gets(reg.descricao);
    printf("\tDigite a idade: ");
    scanf("%i", &reg.idade);
    setbuf(stdin,NULL);
    printf("\tDigite o preco: ");
    scanf("%lf", &reg.preco);
    setbuf(stdin,NULL);
    fprintf(arq,"%i %s %i %.2lf\n", reg.codigo,reg.descricao,reg.idade,reg.preco);
    fclose(arq);
}

void visualizar(Registro reg)
{
	 int i;
    FILE *arq;
  
    arq = fopen("exame.txt","r");
    
    while(fscanf(arq,"%i %s %i %lf",&reg.codigo, reg.descricao, &reg.idade, &reg.preco) != EOF)
    printf("\n\tCodigo: %i ,Descricao: %s ,Idade: %i, Preco: %.2lf\n", reg.codigo,reg.descricao,reg.idade,reg.preco);
    printf("\n\n");
}

void buscarumRegistro(Registro reg)
{
    FILE *arq;

    arq = fopen("exame.txt","r");
    int busca;
    int cont = 0;
    printf("\tDigite o codigo de busca: ");
    scanf("%i", &busca);
    while(!feof(arq))
    {

        fscanf(arq,"%i %s %i %lf",&reg.codigo, reg.descricao, &reg.idade, &reg.preco);
        if(busca == reg.codigo)
        {
            printf("\n\t%i , %s , %i, %.2lf\n", reg.codigo,reg.descricao,reg.idade,reg.preco);
            printf("\n\n");
            cont++;
        }

    }
    if(cont == 0)
    {
        printf("Sem cadastro\n");
    }

}

void buscarRegistros(Registro reg)
{
FILE *arq;

    arq = fopen("exame.txt","r");
    int busca;
    int cont = 0;
    printf("\tDigite a idade minima: ");
    scanf("%i", &busca);
    while(!feof(arq))
    {

        fscanf(arq,"%i %s %i %lf",&reg.codigo, reg.descricao, &reg.idade, &reg.preco);
        if(busca < reg.idade)
        {
            printf("\n\t%i , %s , %i, %.2lf\n", reg.codigo,reg.descricao, reg.idade, reg.preco);
            printf("\n\n");
            cont++;
        }

    }
    if(cont == 0)
    {
        printf("Sem cadastro\n");
    }
}

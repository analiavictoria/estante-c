/********************************************************************************************
ESTANTE VIRTUAL:
Sistema que armazena e exibe os livros que foram lidos e os que são recomendados pelo leitor.
********************************************************************************************/

#include <stdio.h>//in&out
#include <string.h>//manipulação de strings
#include <locale.h>//acentuação
#include <stdlib.h>//apagador
#include <conio.c>//cores

struct bookshelf{
    char title[100];//título
    char genre[30];//gênero
    int recommended;//recomendados
};
struct bookshelf books[10];//variável do tipo struct

void bookData(struct bookshelf books){
    printf("\t- %s\n",books.title);
    printf("\tGênero: %s \n", books.genre);
}

int main()
{
    //Utilizando caracteres e acentuação da língua portuguesa
    setlocale(LC_ALL, "Portuguese");
    
    int opc, choices=0, add, contLivros=3, i;
    
    //copia a string-origem para a string- destino
    strcpy(books[0].title, "Código Limpo"); 
    strcpy(books[0].genre, "Computação"); 
    books[0].recommended = 1;
    
    strcpy(books[1].title, "Design Patterns"); 
    strcpy(books[1].genre, "Computação"); 
    books[1].recommended = 1;
    
    strcpy(books[2].title, "Harry Potter e as Relíquias da Morte"); 
    strcpy(books[2].genre, "Fantasia"); 
    books[2].recommended = 1;
   
    do{
        //MENU
        system("cls");
        textcolor(11);
        printf("\tMINHA ESTANTE VIRTUAL\n\n");
        textcolor(15);
        printf("\tMenu:\n");
        printf("\t1 - Incluir livros lidos;\n");
        printf("\t2 - Consultar livros lidos;\n");
        printf("\t3 - Recomendar a amigos;\n\n");
        textcolor(11);
        printf("\tDigite a sua escolha: ");
        scanf("%d", &choices);
        system("cls");
        
        //OPÇÕES
        switch(choices){
            
            //Incluir
            case 1:
            printf("\tOrganizando a estante\n\n");
            do{
                textcolor(15);
                
                fflush(stdin);//limpando o buffer de memória
                printf("Título: ");
                fgets(books[contLivros].title, 100, stdin);
                printf("Gênero: ");
                scanf("%s", &books[contLivros].genre);
                fflush(stdin);
                printf("Recomenda este livro? (1)Sim / (0)Não: ");
                scanf("%d", &books[contLivros].recommended);
               
                contLivros++;
                
                textcolor(11);
                printf("\nDeseja incluir mais um livro? (1)Sim / (0)Não: ");
                scanf("%d", &add);
                printf("\n");
            }while(add!=0);
            break;
            
            //Listar
            case 2:
                printf("\tLivros lidos:\n\n");
                textcolor(15);
                for(i = 0;i<contLivros;i++){
                    bookData(books[i]);
                }     
            break;
            
            //Recomendar
            case 3:
                printf("\tRecomendações:\n\n");
                textcolor(15);
                for(i=0;i<contLivros;i++){
                    if(books[i].recommended == 1){
                        bookData(books[i]);
               		 }
				}       
            break;
            
        }//fim do switch
                
        textcolor(11);
        printf("\nDigite 1 para retornar a tela inicial ou 0 para sair: ");
        scanf("%d",&opc); 
    }while(opc!=0);
    
    textcolor(7);
    printf("\n");
    printf("\t    Até a proxima!");
    
    return 0;
}

/******************************************************************************************************************
Fontes:
- Baseado em uma atividade <https://github.com/analiavictoria/On14-TodasEmTech-s5-PG-I/tree/analia-silva/projeto>
- <personalizandoc.blogspot.com>;
- <linguagemc.com.br>;
- <codewithharry.com/blogpost/c-cheatsheet>
- C Handbook by Flavio Copes <https://flaviocopes.com>;
- Aulas no laboratório.
********************************************************************************************************************/

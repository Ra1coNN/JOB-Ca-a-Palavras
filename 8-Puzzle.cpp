#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//Fun��o de Cor

enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };

void textcolor (DOS_COLORS iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}


//Fun��o mover para a Direita
void moverDireita(int  matrizjogo[3][3])
{

    int i,j;
    int aux; //Guarda o valor enquanto est� trocando de posi��o.
    int aux2 = 0; //Variavel auxiliar para n�o trocar de posi��o mais de uma vez.


    for( i=0; i<3; i++ )
    {
        for( j=0; j<3; j++ )
        {
            if (matrizjogo[i][j] == 0 && aux2 == 0 && j<2) //Procura o Zero e verifica se na esquerda dele n�o � o final da matriz.
            {
                aux=matrizjogo[i][j+1];
                matrizjogo[i][j+1] = 0;
                matrizjogo[i][j] = aux;
                aux2 = 1;


            }
        }


    }



}

// Fun��o mover para Baixo
void moverBaixo(int  matrizjogo[3][3])
{

    int i,j;
    int aux;
    int aux2 = 0;


    for( i=0; i<3; i++ )
    {
        for( j=0; j<3; j++ )
        {
            if (matrizjogo[i][j] == 0 && aux2 == 0 && i<2) //Procura o Zero e verifica se na esquerda dele n�o � o final da matriz.
            {
                aux=matrizjogo[i+1][j];
                matrizjogo[i+1][j] = 0;
                matrizjogo[i][j] = aux;
                aux2 = 1;


            }
        }


    }



} // Fun��o Mover para cima
void moverCima(int  matrizjogo[3][3])
{

    int i,j;
    int aux;
    int aux2 = 0;


    for( i=0; i<3; i++ )
    {
        for( j=0; j<3; j++ )
        {
            if (matrizjogo[i][j] == 0 && aux2 == 0 && i>0) //Procura o Zero e verifica se na esquerda dele n�o � o final da matriz.
            {
                aux=matrizjogo[i-1][j];
                matrizjogo[i-1][j] = 0;
                matrizjogo[i][j] = aux;
                aux2 = 1;


            }
        }


    }



}


//Fun��o mover esquerda
void moverEsquerda(int  matrizjogo[3][3])
{

    int i,j;
    int aux;
    int aux2 = 0;


    for( i=0; i<3; i++ )
    {
        for( j=0; j<3; j++ )
        {
            if (matrizjogo[i][j] == 0 && aux2 == 0 && j>0) //Procura o Zero e verifica se na esquerda dele n�o � o final da matriz.
            {
                aux=matrizjogo[i][j-1];
                matrizjogo[i][j-1] = 0;
                matrizjogo[i][j] = aux;
                aux2 = 1;


            }
        }


    }



}


//R4: mover '0' para baixo
//void


//Fun��o de cria��o do Tabuleiro 8-Puzzle
void jogo(int  matrizjogo[3][3])
{

    int i,j;


    printf( "\nJOGO INICIADO:\n\n\n" );
    for( i=0; i<3; i++ )
    {
        for( j=0; j<3; j++ )

        {
            if(matrizjogo[i][j] == 0)
            {

                textcolor(BLACK);
                printf( "\t%d", matrizjogo[i][j]);
                textcolor(WHITE);

            }else

            printf( "\t%d", matrizjogo[i][j]);

        }
        printf("\n");

    }
}
bool Finalizacao(int  matrizjogo[3][3])
{
    int aux = 0; //variavel contador quando chegar em 7 significa que todos os n�meros da matriz tem a sua sequencia em ordem.
    int i,j;
    int atual=1; //variavel para come�ar no 1 para verifica��o

    for( int TAM=0; TAM<7; TAM++ ) //Vai repetir 7 vezes ver se todos os n�meros est�o em ordem.
    {
        for( i=0; i<3; i++ )
        {
            for( j=0; j<3; j++ )
            {

                if(matrizjogo[i][j] == atual) //Procurar valor atual come�ando pelo 1



                {
                    if(matrizjogo[i+1][j] == (atual+1) )  //Procurar valor atual na direita � o pr�ximo
                    {
                        aux++;


                    }
                    else if( matrizjogo[i-1][j] == (atual+1) )   //Procurar valor atual na esquerda � o pr�ximo
                    {
                        aux++;


                    }
                    else if( matrizjogo[i][j+1] == (atual+1)  )   //Procurar valor atual na Baixo � o pr�ximo
                    {
                        aux++;

                    }
                    else if(matrizjogo[i][j-1] == (atual+1))   //Procurar valor atual na Cima � o pr�ximo
                    {
                        aux++;


                    }


                }
            }


        }
        atual++;


    }
    if(aux == 7)
    {
        return true;

    }
    else return false;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matrizjogo[3][3] {1,8,3,2,0,4,6,7,5}; //Cria��o da matriz
    int i, j;
    bool finalJogo = false; //Variavel de parada do jogo
    char Movimento; //Variavel que recebe o movimento do usuario.

    while(finalJogo == false) //Enquanto o jogo n�o for finalizado ele vai rodar
    {
        jogo(matrizjogo); //Fun��o para printar matriz.

        printf("Escolha o pr�ximo movimente (Use as Teclas w,a,s,d)\n");

        scanf("%c",&Movimento); //Receber o movimento do usuario

        fflush(stdin); //Fun�ao para n�o pular o Scanf

        switch (Movimento)
        {
        case 'a':
            moverEsquerda(matrizjogo); //Vai para Esquerda
            break;

        case 'd':
            moverDireita(matrizjogo);
            break;

        case 'w':
            moverCima(matrizjogo);
            break;

        case 's':
            moverBaixo(matrizjogo);
            break;

        default:
            break;

        }
        system("cls"); //Apagar tela atual
        finalJogo=Finalizacao(matrizjogo); //Verifica se o jogo foi finalizado se Sim a variavel recebe TRUE quebrando while se n�o FALSE e o jogo continua.
    }
    jogo(matrizjogo); //print matriz
    printf("\n\nVoc� Ganhou o jogo!\n\n");
}




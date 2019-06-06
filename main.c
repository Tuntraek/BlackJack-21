#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
/*Feito por:
Guilherme Maiuri
Ian Heski
Christian*/

int pontos_P1;
int pontos_P2;
int jogar;
int P1_estourou = 0;
int P2_estourou = 0;
int P1_venceu = 0;
int P2_venceu = 0;
int primeiraCarta;
int segundaCarta;
int proximaCarta;
int carta_um;
int carta_dois;
int carta_tres;
int darCarta = 0;
int x = 0;
int jogoAcabou = 0;
int decisao;
int cartaImprimir;

int inicio_jogo(){



    decisao = 0;

    printf("Bem vindo(a) ao nosso jogo de BlackJack (21)!! \n");

    while(decisao == 0){
        printf("O que deseja fazer? \n 1 - Jogar \n 2 - Regras \n 3 - Sair\n");
        scanf("%d", &decisao);
        if(decisao > 3 || decisao <= 0){
            printf("\n");
            printf("Numero invalido! Tente novamente");
            printf("\n \n");
            decisao = 0;
            Sleep(1000);
        } else{
            menu(decisao);
        }
        system("cls");
    }
}
int regras(){

    printf("\n\n"
           "BlackJack: \n"
           "Jogo para dois jogadores onde o jogador tira duas cartas e soma os seus pontos, \n"
           "o objetivo é chegar a 21 pontos ou o mais proximo disso, se passar de 21 o jogador perde! \n"
           "Valor das cartas: A=1 ; 2=2 ; 3=3 ; 4=4 ; 5=5 ; 6=6 ; 7=7 ; 8=8 ; 9=9 ; 10=10 ; J=10 ; Q=10 e K=10 \n"
           "\n\n"
           "Pressione qualquer tecla para voltar ao menu!"
           "\n\n");
    getche();
    system("cls");
    inicio_jogo();
}

int sair(){

    printf("Obrigado por jogar!!");
    getch();

}

int menu(decisao){

    if(decisao == 1){
        system("cls");
        desenvolvimento();
    }else if(decisao == 2){
        regras();
    }else{
        sair();
    }
}

int resetDados(){
    P1_estourou =0;
    P1_venceu =0;
    P2_estourou =0;
    P2_venceu =0;
}

int mais_carta(){
    printf("\n");
    printf("Voce quer mais uma carta? 1 = sim, 0 = nao\n");
    scanf("%d", &darCarta);
        if((darCarta>1) || (darCarta<0)){
            printf("Opcao invalida;");
            printf("\n");
            mais_carta();
        }
    return darCarta;
}

int desenvolvimento(){
    player1_jogada();
    if(jogoAcabou == 1){
        return -1;
    }

    if(P1_venceu == 1){
        vencedor();

    } else if(P1_estourou == 1){
        vencedor();
        return -1;
    }
    else {
        player2_jogada();
        if(P2_venceu == 1){
        vencedor();

        } else if(P2_estourou == 1){
            vencedor();
        return -1;
        }
    }
}

char imprimirCarta(int valorCarta, int carta){
    if(carta == 1){
        carta_um = valorCarta;

        if(valorCarta == 1 || valorCarta > 10){
            if(valorCarta==1){
                primeiraCarta = 1;
                carta_um = 65;
            }else if(valorCarta==11){
                primeiraCarta = 10;
                carta_um = 74;
            }else if(valorCarta==12){
                primeiraCarta = 10;
                carta_um = 81;
            }else if(valorCarta==13){
                primeiraCarta = 10;
                carta_um = 75;
            }
            printf("Sua primeira carta e: %c", carta_um);
        }else{
            printf("Sua primeira carta e: %d", carta_um);
        }
    }else if(carta == 2){
        carta_dois = valorCarta;

        if(valorCarta == 1 || valorCarta > 10){
            if(valorCarta==1){
                segundaCarta = 1;
                carta_dois = 65;
            }else if(valorCarta==11){
                segundaCarta = 10;
                carta_dois = 74;
            }else if(valorCarta==12){
                segundaCarta = 10;
                carta_dois = 81;
            }else if(valorCarta==13){
                segundaCarta = 10;
                carta_dois = 75;
            }
            printf("Sua segunda carta e: %c", carta_dois);
        }else{
            printf("Sua segunda carta e: %d", carta_dois);
        }
    }else {
        carta_tres = valorCarta;

        if(valorCarta == 1 || valorCarta > 10){
            if(valorCarta==1){
                proximaCarta = 1;
                carta_tres = 65;
            }else if(valorCarta==11){
                proximaCarta = 10;
                carta_tres = 74;
            }else if(valorCarta==12){
                proximaCarta = 10;
                carta_tres = 81;
            }else if(valorCarta==13){
                proximaCarta = 10;
                carta_tres = 75;
            }
            printf("Você tirou um: %c", carta_tres);
        }else{
            printf("Você tirou um: %d", carta_tres);
        }
    }

}

void tirarPrimeiraMao(){
    primeiraCarta = rand()%12+1;
    imprimirCarta(primeiraCarta, 1);

    printf("\n");

    segundaCarta = rand()%12+1;
    imprimirCarta(segundaCarta, 2);
}

void tirarMaisCarta(){
    proximaCarta = rand()%12+1;
    imprimirCarta(proximaCarta, 3);
}

int player1_jogada(){
    //player 1-----------------------------------
    pontos_P1=0;
    printf("Player_1");
    printf("\n\n");

    tirarPrimeiraMao();

    pontos_P1 = primeiraCarta + segundaCarta;

    printf("\n\n");
    printf("Player 1 tem %d pontos", pontos_P1);

    mais_carta();

    while(darCarta == 1){

        tirarMaisCarta();
        pontos_P1 += proximaCarta;
        printf("\n");
        printf("Player 1 tem %d pontos", pontos_P1);
        printf("\n");


        if(pontos_P1 == 21){
            printf("\n");
            printf("Player 1 ganhou!");
            getch();
            system("cls");
            P1_venceu = 1;
            jogar_denovo();
            jogoAcabou =1;
            break;

        }else if(pontos_P1>21){
            printf("\n");
            printf("Player 1 estourou! \nPlayer 2 ganhou!");
            getch();
            system("cls");
            P1_estourou = 1;
            jogar_denovo();
            jogoAcabou =1;
            break;

        }else{
            mais_carta();
        }
    }
}

int player2_jogada(){
    //Vez do player 2--------------------------
    printf("\n");
    printf("Player_2");
    printf("\n\n");

    tirarPrimeiraMao();

    pontos_P2 = primeiraCarta + segundaCarta;

    printf("\n\n");
    printf("Player 2 tem %d pontos", pontos_P2);

    mais_carta();

    while(darCarta == 1){

        tirarMaisCarta();
        pontos_P2 += proximaCarta;

        printf("\n");
        printf("Player 2 tem %d pontos", pontos_P2);
        printf("\n");


        if(pontos_P2 == 21){
            printf("\n");
            printf("Player 2 ganhou!");
            getch();
            system("cls");
            P2_venceu = 1;
            jogar_denovo();
            jogoAcabou=1;
            break;

        }else if(pontos_P2>21){
            printf("\n");
            printf("Player 2 estourou! \nPlayer 1 ganhou!");
            getch();
            system("cls");
            P2_estourou = 1;
            darCarta = 0;
            jogar_denovo();
            jogoAcabou=1;
        }else{
            mais_carta();
        }
    }
    vencedor();
}

int vencedor(){
    if(jogoAcabou == 1){
        return -1;
    }
    if(P1_venceu == 1 || P2_estourou == 1){
        printf("\nPlayer 1 venceu");
        getch();
        system("cls");
        Sleep(1000);

    } else if(P2_venceu == 1 || P1_estourou == 1){
        printf("\nPlayer 2 venceu");
        getch();
        system("cls");
        Sleep(1000);

    } else {
        if(pontos_P1>pontos_P2){
            printf("\nPlayer 1 vence de %d a %d", pontos_P1, pontos_P2);
        } else if(pontos_P1<pontos_P2){
            printf("\nPlayer 2 vence de %d a %d", pontos_P2, pontos_P1);
        } else{
            printf("\nO jogo Empatou");
        }
        getch();
        system("cls");
        Sleep(1000);
        jogar_denovo();

    }
}

int jogar_denovo(){
    printf("\n");
    printf("Deseja jogar de novo? \n1 = sim \n2 = não \n3 = regras \n");
    scanf("%d", &jogar);

    if(jogar>3 || jogar<=0){
        printf("\nOpção inválida! Tente novamente.");
        jogar_denovo();
    }else {
        if(jogar == 1){
            Sleep(1000);
            system("cls");
            resetDados();
            desenvolvimento();
        }else if(jogar == 2){
            system("cls");
            printf("Obrigado por jogar!");
            getch();
            resetDados();
            jogoAcabou =1;
        } else{
            regras();
        }
    }
    return 0;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    inicio_jogo();

    return 0;
}

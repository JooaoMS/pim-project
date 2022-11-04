#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define SIZE 200

char nome [SIZE][50];
char email[SIZE][50];
char sexo[SIZE][11];
char telefone[SIZE][17];
char rg[SIZE][17];
int idade[SIZE];
int cpf[SIZE];
int op;
void cadastro();
void pesquisa();
void lista();
int a,b,L,L2;
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


int main (void){
		setlocale(LC_ALL, "Portuguese");
    int opcao;
	printf("\n MENU!");
    Sleep(2000);
	 do{
        inicio:
        opcao=0;
        L=2;L2=2;b=2;
        system("cls");
        system("color 0f");
        printf("\n\n      1 - Cadastros de Funcionarios! \n      2 - Cadastros de Clientes! \n      3 - Cadastros de Parceiros! \n      4 - Relatorios de Cadastros\n      5 - Sair!\n      6 - Pesquisar cadastros");
			 do{
        
            gotoxy(1,L);
            printf("-->");
            gotoxy(10,6);
            if(kbhit){a=getch();}
            if(a == 80 && b < 7){L2=L;L++;b++;}/*seta p/baixo*/
            if(a == 72 && b > 2){L2=L;L--;b--;}/*seta p/cima */
            if(L!=L2){gotoxy(1,L2);printf("   ");L2=L;}
            if(a == 13){opcao=b-1;}
        }while(opcao == 0);
        
        
               switch (opcao){
            case 1:
                system("cls");
                printf("\n   Cadastros de Funcionarios!\n");
                Sleep(2000);
               	cadastro();

                break;
            case 2:
                system("cls");
                printf("\n   Cadastros de Clientes!\n");
                Sleep(2000);
                break;
            case 3:
                system("cls");
                printf("\n    Cadastros de Parceiros!\n");
                Sleep(2000);
                break;
            case 4:
                system("cls");
                printf("\n    Relatorios de Cadastros!\n");
                Sleep(2000);
                  lista();
                break;
            case 5:
                system("cls");
                printf("\n Voce pediu para sair, prencione qualquer tecla para continuar\n");
               	system("exit");

                break;    
             case 6:
                system("cls");
                printf("\n    Pesquisa de cadastros!\n");
               	pesquisa();
                Sleep(2000);
                break;
            default:
                printf("voce deve escolher uma opcao valida\n");
                printf("Precione qualquer tecla para voltar ao menu\n");
                system("pause");
                goto inicio;
        }
     }while(opcao!=5);    
            return 0;
}
        
        
















void lista(){ //Função que mostra todos os cadastros feitos:
	int i;
	for(i=0;i<SIZE;i++){
		if(cpf[i]>0){
			printf("\nNome: %s\nEmail: %s\nCPF: %d \nNumero de Celular: %s \nSexo: %s \nRG: %s \nIdade: %d\n", nome[i], email[i], cpf[i], telefone[i],sexo[i],rg[i],idade[i]);
		}else{
			break;
		}
	}
	getchar();
	getchar();
	//testar com 1 ou 2 getchar, depende do "pc"
}







void cadastro(){
	static int linha;
	do{
		printf("\nDigite o nome: ");
		scanf("%s", &nome[linha]);
		
		printf("\nDigite o email: ");
		scanf("%s", &email[linha]);
		
		printf("\nDigite o CPF: ");
		scanf("%d", &cpf[linha]);
		
		printf("\nDigite o numero de celular: ");
		scanf("%s", &telefone[linha]);
		
		printf("\nDigite o sexo: ");
		scanf("%s", &sexo[linha]);
		
		printf("\nDigite o RG: ");
		scanf("%s", &rg[linha]);
		
		printf("\nDigite a idade: ");
		scanf("%d", &idade[linha]);		
		
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d", &op);
		system("cls");
		linha++;
	}while(op==1);
}  //fim da função cadastro






		//Começo da função de pesquisa de cadastros
void pesquisa(){
	int cpfPesquisa;
	char emailPesquisa[50];
	int i=0;
	do{ //loop enquanto para continuar pesquisando enquanto o usuario quiser
		printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar por email");
		scanf("%d", &op);
		switch(op){
			case 1: //CASO A PESQUISA SEJA PELO CPF:
				printf("\nDigite o CPF: ");
				scanf("%d", &cpfPesquisa);
				for(i=0;i<SIZE;i++){
					if(cpf[i]==cpfPesquisa){
						printf("\nNome: %s \nEmail: %s \nCPF: %d \nNumero de Celular: %s \nSexo: %s \nRG: %s \nIdade: %d", nome[i], email[i], cpf[i], telefone[i],sexo[i],rg[i],idade[i]);
					}
				}
				break;
			case 2: //CASO A PESQUISA SEJA PELO E-MAIL:
				printf("\nDigite o E-mail: ");
				scanf("%s", &emailPesquisa);
				for(i=0;i<SIZE;i++){
					if(strcmp(email[i], emailPesquisa)==0){
						printf("\nNome: %s\nEmail: %s\nCPF: %d \nNumero de Celular: %s \nSexo: %s \nRG: %s \nIdade: %d", nome[i], email[i], cpf[i], telefone[i],sexo[i],rg[i],idade[i]);
					}
				}
				break;
			default:
				printf("\n Opcao invalida");
				break;
		}
		printf("\nDigite 1 para continuar pesquisando ");
		scanf("%d", &op);
	}while(op==1);
} //Fim da função

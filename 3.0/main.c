#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//MUDA A POSIÇÃO DO CURSOR DO CONSOLE
void gotoxy(int x,int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
//ESCONDER CURSOR DO CONSOLE
void HideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

int main(){
	HideCursor();// ESCONDER O CURSOR DO CONSOLE
	system("color 0c");
	system("title GAME");
	//VARIAVEIS
	const int maxx=60, maxy=30;//MAXIMA POSIÇÃO DE X E Y
	const int conmaxx=100,conmaxy=100;
	const int maxxx=maxx-1, maxyy=maxy-1;//PARA A CRIAÇÃO DAS EXTREMIDADES
	int x=0, y=0;// VARAIVEIS XY PARA O MAPA
	int px=30, py=15;//POSIÇÃO INICIAL PLAYER
	int ix=30, iy=10;//POSIÇÃO INICIAL INIMIGO
	int ixt=0, iyt=0;//POSIÇÃO PLAYER PARA O INIMIGO
	int level=25, exp=0;//LEVEL E EXP PERSONAGEM
	int ilevel=0;//LEVEL DO INIMIGO
	int movini=0;//MOVIMENTO INIMIGO
	int veloini=10000;//VELOCIDADE INIMIGO
	int upi=1;// se inimigo upa ou não 1=true 0=false
	char parede=219;//219/178//176(recomendação)
	char perso=65;//A=65-Z=90(recomendação)
	char rastrop=0;//RASTRO PLAYER
	char inimigo=65;//LETRA INIMIGO
	char rastroi=0;//RASTRO INIMIGO
	char comand='e';
	//CRIAÇÃO EXTREMIDADES
	for(x=0;x<maxx;x++){
		for(y=0;y<maxy;y++)
			if(y==0 || x==0 || y==maxyy || x==maxxx){
			gotoxy(x,y);
			printf("%c",parede);
			}
		//CRIAÇÃO PERSONAGEM
		if(x==0 || y==0){
			gotoxy(px,py);
			printf("%c",perso);
		}
		//CRIAÇÃO INIMIGO
		if(x==0 || y==0){
			inimigo=65+ilevel;
			gotoxy(ix,iy);
			printf("%c",inimigo);
		}
	}
	for(y=0;y<100;y++){
		gotoxy(60,1);
		printf("Level:%d",level);
		gotoxy(60,2);
		printf("Experiencia:%d",exp);
	}
	//MOVIMENTAÇÃO PLAYER
	for(;;){
		if(kbhit()){
		comand=getch();
		//CIMA
		if(comand=='w'){
			py=py-1;
			if(py<=0){
				py=py+1;
			}
			gotoxy(px,py);
			printf("%c",perso);
			py=py+1;
			gotoxy(px,py);
			printf("%c",rastrop);
			py=py-1;
		}
		//BAIXO
		if(comand=='s'){
			py=py+1;
			if(py>=maxyy){
				py=py-1;
			}
			gotoxy(px,py);
			printf("%c",perso);
			py=py-1;
			gotoxy(px,py);
			printf("%c",rastrop);
			py=py+1;
		}
		//ESQUERDA
		if(comand=='a'){
			px=px-1;
			if(px<=0){
				px=px+1;
			}
			gotoxy(px,py);
			printf("%c",perso);
			px=px+1;
			gotoxy(px,py);
			printf("%c",rastrop);
			px=px-1;
		}
		//DIREITA
		if(comand=='d'){
			px=px+1;
			if(px>=maxxx){
				px=px-1;
			}
			gotoxy(px,py);
			printf("%c",perso);
			px=px-1;
			gotoxy(px,py);
			printf("%c",rastrop);
			px=px+1;
		}
		gotoxy(60,3);
		printf("px:%d/py%d/ix:%d/iy:%d/ilevel:%d      ",px,py,ix,iy,ilevel);
		}
		//MOVIMENTO INIMIGO	
		while(!kbhit()){
			if(movini==veloini){
				//UP LEVEL INIMIGO
				if(ix==px && iy==py){
					if(upi==1){
						ilevel=ilevel+1;
						inimigo=65+ilevel;
						if(inimigo==90){
							upi=0;
						}
					}
				}
				ixt=px;
				iyt=py;
				//ESQUERDA
				if(ixt<ix){
					ix=ix-1;
					if(ix>=maxxx){
						ix=ix+1;
					}
					gotoxy(ix,iy);
					printf("%c",inimigo);
					ix=ix+1;
					gotoxy(ix,iy);
					printf("%c",rastroi);
					ix=ix-1;
				}
				//DIREITA
				if(ixt>ix){
					ix=ix+1;
					if(ix>=maxxx){
						ix=ix-1;
					}
					gotoxy(ix,iy);
					printf("%c",inimigo);
					ix=ix-1;
					gotoxy(ix,iy);
					printf("%c",rastroi);
					ix=ix+1;
				}
				//BAIXO
				if(iyt>iy){
					iy=iy+1;
					if(iy>=maxyy){
						iy=iy-1;
					}
					gotoxy(ix,iy);
					printf("%c",inimigo);
					iy=iy-1;
					gotoxy(ix,iy);
					printf("%c",rastroi);
					iy=iy+1;
				}
				//CIMA
				if(iyt<iy){
					iy=iy-1;
					if(iy>=maxyy){
						iy=iy+1;
					}
					gotoxy(ix,iy);
					printf("%c",inimigo);
					iy=iy+1;
					gotoxy(ix,iy);
					printf("%c",rastroi);
					iy=iy-1;
				}
				movini=0;
				gotoxy(60,3);
				printf("px:%d/py%d/ix:%d/iy:%d/ilevel:%d         ",px,py,ix,iy,ilevel);
			}
			movini++;
		}
	}
	
	return 0;
}

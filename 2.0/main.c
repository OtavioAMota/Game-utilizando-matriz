#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x,int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

int main() {
	system("color 0a");
	//VARIAVEIS
	// x=y y=x
	const int maxpx=30, maxpy=60;
	const int imaxpx=maxpx-1; 
	const int imaxpy=maxpy-1;
	int px=0;
	int py=0;
	int persox=15;//CIMA/BAIXO INICIAL
	int persoy=30;//LADOS INICIAL
	int parede=178;//178//219
	char comand='e';
	//CRIAÇÃO
	for(py=0;py<maxpy;py++)
	for(px=0;px<maxpx;px++){
		//CRIAÇÃO DE LIMITE DE MAPA
		if(px==0 || py==0 || py==imaxpy || px==imaxpx){
			gotoxy(py,px);
			printf("%c",parede);
    	}
    	//CRIAÇÃO PERSONAGEM
    	if(px==20 || py==20){
    		gotoxy(persoy,persox);
    		printf("%c",'O');
		}
    }
    for(;;){
    	//MOVIMENTO PERSONAGEM
    	comand=getch();
    	//PARA CIMA
    	if(comand=='w'){
    		persox=persox-1;
    		gotoxy(persoy,persox);
    		printf("%c",'O');
    		persox=persox+1;
    		gotoxy(persoy,persox);
    		printf("%c",176);
    		persox=persox-1;
		}
		//PARA BAIXO
		if(comand=='s'){
			persox=persox+1;
			gotoxy(persoy,persox);
    		printf("%c",'O');
    		persox=persox-1;
    		gotoxy(persoy,persox);
    		printf("%c",176);
    		persox=persox+1;
		}
		//PARA ESQUERDA
		if(comand=='a'){
			persoy=persoy-1;
			gotoxy(persoy,persox);
    		printf("%c",'O');
    		persoy=persoy+1;
    		gotoxy(persoy,persox);
    		printf("%c",176);
    		persoy=persoy-1;
		}
		//PARA DIREITA
		if(comand=='d'){
			persoy=persoy+1;
			gotoxy(persoy,persox);
    		printf("%c",'O');
    		persoy=persoy-1;
    		gotoxy(persoy,persox);
    		printf("%c",176);
    		persoy=persoy+1;
		}
	}
    
	return 0;
}


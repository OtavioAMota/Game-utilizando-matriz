#include <stdio.h>
#include <stdlib.h>

int x, y, px=2, py=2, time;
char c, map[70][25];

int main() {
	system("color 70");
	for(y=0;y<25;y++){
		for(x=0;x<70;x++)
		// criação barreira
		if(y==24 || x==0 || y==0 || x==69 || y==5 || y>=6){
			map[x][y]=178;
		}
		//posição inicial do personagem
		map[px][py]='O';
	}
	//criação mapa
	printf("*********************************GAME*********************************\n");
	for (y=0;y<25;y++){
		for(x=0;x<70;x++)
			printf("%c", map[x][y]);
		printf("\n");
	}
	//loop movimento
	for(;;){
		if(time==30000000){
			time=0;
		//fisica do jogo "while"
		while(py<=3){
			py=py+1;
			map[px][py]='O';
			py=py-1;
			map[px][py]=0;
			py=py+1;
			system("cls");
			printf("*********************************GAME*********************************\n");
			for (y=0;y<25;y++){
				for(x=0;x<70;x++)
					printf("%c", map[x][y]);
					printf("\n");
			}
		}
		//pegar comando jogador
		if (kbhit()){
			c=getch();
			
		//movimento para baixo
		if(c=='s'){
			py=py+1;
			map[px][py]='O';
			py=py-1;
			map[px][py]=0;
			py=py+1;
			if(py==24){
				map[px][py]=178;
				py=py-1;
				map[px][py]='O';
			}
		}
		//movimento para cima
		if(c=='w'){
			py=py-1;
			map[px][py]='O';
			py=py+1;
			map[px][py]=0;
			py=py-1;
			if(py==0){
				map[px][py]=178;
				py=py+1;
				map[px][py]='O';
			}
			
		}
		//movimento para a esquerda
		if(c=='a'){
			px=px-1;
			map[px][py]='O';
			px=px+1;
			map[px][py]=0;
			px=px-1;
			if(px==0){
				map[px][py]=178;
				px=px+1;
				map[px][py]='O';
			}
		}
		//movimento para a direita
		if(c=='d'){
			px=px+1;
			map[px][py]='O';
			px=px-1;
			map[px][py]=0;
			px=px+1;
			if(px==69){
				map[px][py]=178;
				px=px-1;
				map[px][py]='O';
			}
		}
		//quitar do jogo
		if(c=='q'){
			printf("Voce parou o jogo.");
			break;
		}
	}
		// atualização de posição
		system("cls");
		printf("*********************************GAME*********************************\n");
		for (y=0;y<25;y++){
			for(x=0;x<70;x++)
				printf("%c", map[x][y]);
				printf("\n");
		}
		}else{
			time++;
		}
	}
	//fim do loop
	
	return 0;
}

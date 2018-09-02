#include<iostream>
#include<windows.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIRECTION -32
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

int number(int a){
	switch(a){
		case 2:
			return 2;
		case 4:
			return 4;
		case 8:
			return 8;
		case 7:
			return 16;
		case 5:
			return 32;
		case 10:
			return 64;
		case 11:
			return 128;
		case 13:
			return 256;
		case 512:
			return 512;
		case 1024:
			return 1024;
		case 2048:
			return 2048;
	}
}

int main(){
	srand((unsigned)time(NULL));
	char game[9][21];
	for(int a = 0; a < 9; a ++){
		for(int b = 0; b < 21; b ++){
			game[a][b] = '0';
		}
	}
	for(int i = 0; i < 9; i += 1){
		if(i % 2 == 1){
			for(int j = 0; j < 21; j += 5){
				game[i][j] = '*';
			}
		} else{
			for(int j = 0; j < 21; j ++){
				game[i][j] = '*';
			}
		}
		cout << endl;
	}
	for(int a = 0; a < 10; a ++){
		for(int b = 0; b < 21; b ++){
			cout << game[a][b];
		}
		cout << endl;
	}
	int easy_game[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			easy_game[i][j] = 0;
		}
	}
	
	char input = 0;
	while(input = getch()){
		if(input == DIRECTION){
			input = getch();
			for(int i = 0; i < 2; i++){
				int a = rand()%4, b = rand()%4;
				if (easy_game[a][b] == 0){
					easy_game[a][b] = 2;
				} else{
					i--;
				}
			} 
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					int num;
					num = easy_game[i][j];
					gotoxy((2*i)+1,(5*j)+1);
					if(((num%2)== 0) && num < 10){
						cout << "000" << number(num);
					} else if((num > 5) && (num < 11)){
						cout << "00" << number(num);
					} else if(num < 513){
						cout << "0" << number(num);
					} else{
						cout << num;
					}
				}
			}
			
			switch(input){
				case UP:
					for(int a = 0; a < 3; a++){
						for (int i = 0; i < 4; i++){
							for(int j = 1; j < 4; j++){
								if(easy_game[j-1][i] == 0){
									easy_game[j-1][i] = easy_game[j][i];
									easy_game[j][i] = 0;
								} 
							}
						}
				    }
				    for (int i = 0; i < 4; i++){
						for(int j = 1; j < 4; j++){
							if(easy_game[j-1][i] == easy_game[j][i]){
								if((easy_game[j-1][i] + easy_game[j][i]) <= 10){
									easy_game[j-1][i] += easy_game[j][i];
								} else if((easy_game[j-1][i] + easy_game[j][i]) == 14){
									easy_game[j-1][i] == 5;
								} else if((easy_game[j-1][i] + easy_game[j][i]) == 20){
									easy_game[j-1][i] == 11;
								} else if((easy_game[j-1][i] + easy_game[j][i]) == 22){
									easy_game[j-1][i] == 13;
								} else if((easy_game[j-1][i] + easy_game[j][i]) == 26){
									easy_game[j-1][i] == 512;
								} else {
									easy_game[j-1][i] += easy_game[j][i];
								}
								easy_game[j][i] == 0;
							} 
						}
					}
					for(int a = 0; a < 3; a++){
						for (int i = 0; i < 4; i++){
							for(int j = 1; j < 4; j++){
								if(easy_game[j-1][i] == 0){
									easy_game[j-1][i] = easy_game[j][i];
									easy_game[j][i] = 0;
								} 
							}
						}
				    }
					break;
				case LEFT:
					for(int a = 0; a < 3; a++){
						for (int i = 0; i < 4; i++){
							for(int j = 1; j < 4; j++){
								if(easy_game[i][j-1] == 0){
									easy_game[i][j-1] = easy_game[i][j];
									easy_game[i][j] = 0;
								} 
							}
						}
				    }
				    for (int i = 0; i < 4; i++){
						for(int j = 1; j < 4; j++){
							if(easy_game[i][j-1] == easy_game[i][j]){
								if((easy_game[i][j-1] + easy_game[i][j]) <= 10){
									easy_game[i][j-1] += easy_game[i][j];
								} else if((easy_game[i][j-1] + easy_game[i][j]) == 14){
									easy_game[i][j-1] == 5;
								} else if((easy_game[j-1][i] + easy_game[i][j]) == 20){
									easy_game[i][j-1] == 11;
								} else if((easy_game[j-1][i] + easy_game[i][j]) == 22){
									easy_game[i][j-1] == 13;
								} else if((easy_game[j-1][i] + easy_game[i][j]) == 26){
									easy_game[i][j-1] == 512;
								} else {
									easy_game[i][j-1] += easy_game[i][j];
								}
								easy_game[i][j] == 0;
							} 
						}
					}
					for(int a = 0; a < 3; a++){
						for (int i = 0; i < 4; i++){
							for(int j = 1; j < 4; j++){
								if(easy_game[i][j-1] == 0){
									easy_game[i][j-1] = easy_game[i][j];
									easy_game[i][j] = 0;
								} 
							}
						}
				    }
					break;
				case DOWN:
					for(int a = 0; a < 3; a++){
						for (int i = 4; i > 0; i--){
							for(int j = 3; j > 0; j--){
								if(easy_game[j+1][i] == 0){
									easy_game[j+1][i] = easy_game[j][i];
									easy_game[j][i] = 0;
								} 
							}
						}
				    }
				    for (int i = 4; i > 0; i--){
						for(int j = 1; j < 4; j++){
							if(easy_game[j+1][i] == easy_game[j][i]){
								if((easy_game[j+1][i] + easy_game[j][i]) <= 10){
									easy_game[j+1][i] += easy_game[j][i];
								} else if((easy_game[j+1][i] + easy_game[j][i]) == 14){
									easy_game[j+1][i] == 5;
								} else if((easy_game[j+1][i] + easy_game[j][i]) == 20){
									easy_game[j+1][i] == 11;
								} else if((easy_game[j+1][i] + easy_game[j][i]) == 22){
									easy_game[j+1][i] == 13;
								} else if((easy_game[j+1][i] + easy_game[j][i]) == 26){
									easy_game[j+1][i] == 512;
								} else {
									easy_game[j+1][i] += easy_game[j][i];
								}
								easy_game[j][i] == 0;
							} 
						}
					}
					for(int a = 0; a < 3; a++){
						for (int i = 4; i > 0; i--){
							for(int j = 1; j < 4; j++){
								if(easy_game[j+1][i] == 0){
									easy_game[j+1][i] = easy_game[j][i];
									easy_game[j][i] = 0;
								} 
							}
						}
				    }
				    break;
				case RIGHT:
					for(int a = 0; a < 3; a++){
						for (int i = 4; i > 0; i--){
							for(int j = 3; j > 0; j--){
								if(easy_game[i][j+1] == 0){
									easy_game[i][j+1] = easy_game[i][j];
									easy_game[i][j] = 0;
								} 
							}
						}
				    }
				    for (int i = 4; i > 0; i--){
						for(int j = 3; j > 0; j--){
							if(easy_game[i][j+1] == easy_game[i][j]){
								if((easy_game[i][j+1] + easy_game[i][j]) <= 10){
									easy_game[i][j+1] += easy_game[i][j];
								} else if((easy_game[i][j+1] + easy_game[i][j]) == 14){
									easy_game[i][j+1] == 5;
								} else if((easy_game[i][j+1] + easy_game[i][j]) == 20){
									easy_game[i][j+1] == 11;
								} else if((easy_game[i][j+1] + easy_game[i][j]) == 22){
									easy_game[i][j+1] == 13;
								} else if((easy_game[i][j+1] + easy_game[i][j]) == 26){
									easy_game[i][j+1] == 512;
								} else {
									easy_game[i][j+1] += easy_game[i][j];
								}
								easy_game[i][j] == 0;
							} 
						}
					}
					for(int a = 0; a < 3; a++){
						for (int i = 4; i > 0; i--){
							for(int j = 3; j > 0; j--){
								if(easy_game[i][j+1] == 0){
									easy_game[i][j+1] = easy_game[i][j];
									easy_game[i][j] = 0;
								} 
							}
						}
				    }
					break;
			}
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					int num;
					num = easy_game[i][j];
					gotoxy((2*i)+1,(5*j)+1);
					if(((num%2)== 0) && num < 10){
						cout << "000" << number(num);
					} else if((num > 5) && (num < 11)){
						cout << "00" << number(num);
					} else if(num < 513){
						cout << "0" << number(num);
					} else{
						cout << num;
					}
				}
			}
			int win = 0;
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					if(easy_game[i][j] > win){
						win = easy_game[i][j];
					}
				}
			}
			if(win == 2048){
				cout << "Gameover. You win!";
				break;
			}
		}
	}
	return 0;
}
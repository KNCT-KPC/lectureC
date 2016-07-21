#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>	//Sleep() 使いたいだけなんでLinux系統などは適宜読み込んで。

#define ROW 4
#define COL 13


void drow(int look[ROW][COL], char real[ROW][COL]){
	int i, j;

	printf(" 1       5       9      13\n");
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			switch(look[i][j]){
			case 0: 
				//printf(" %c", real[i][j]);	//デバッグ用
				printf("□");
				break;
			case 1: printf(" %c", real[i][j]);
				break;
			case 2: printf("  ");
				break;
			}
		}
		printf(" %d", i+1);
		puts("");
	}
}


int judge(int look[ROW][COL], char real[ROW][COL], int count, int *point){
	char a[2];
	int i, j, k=0;
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			if(look[i][j] == 1){
				//printf("\n中身 : %c\n", real[i][j]);
				a[k] = real[i][j];
				k++;
			}
		}
	}

	drow(look, real);

	if(a[0] == a[1]){
		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				if(look[i][j] == 1){
					look[i][j] = 2;
				}
			}
		}
		printf("\nお見事！正解です。\nそろった文字は「%c」です！\n", a[0]);
		count--;
		(*point)++;
	} else {
		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				if(look[i][j] == 1){
					look[i][j] = 0;
				}
			}
		}
		printf("\n残念！はずれです。\n");
	}

	printf("\n\n");
	return count;
}

int cpuopen(int look[ROW][COL], char real[ROW][COL], char know[ROW][COL], int count, int *point){
	//自分が開けたところは絶対覚えるマン
	int i, j, k, l;
	int x, y;
	int ans = 0;  //二つ選べた時のカウンタ

	while(ans != 2){
		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				if(look[i][j] == 2){
					know[i][j] = '0';
				}
			}
		}

		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				for(k=i; k<ROW; k++){
					for(l=j+1; l<COL; l++){
						if(know[i][j] != '0' || know[k][l] != '0'){
							if(know[i][j] == know[k][l]){
								look[i][j] = 1;
								look[k][l] = 1;
								ans = 2;
							}
						}
					}
				}
			}
		}

		//もし、for文で二つそろわなかったとき(knowの配列に一組もおなじカードがなかったとき)
		if(ans != 2){
			y = rand() % ROW;
			x = rand() % COL;
			if(look[y][x] == 0){
				look[y][x] = 1;
				know[y][x] = real[y][x];
				ans++;
			}
		}
	}
	//y = rand() % ROW;
	//x = rand() % COL;

	count = judge(look, real, count, point);
	return count;
}

int open(int look[ROW][COL], char real[ROW][COL], int count, int *point){
	int i,j, k;
	for(k=1; k<3; k++){					//二か所選択されるまで続きます。ぶっちゃけwhile文でいいと思った。
		drow(look, real);

		printf("\n%dつ目を開けます。\n", k);
		printf("\n上から何番目を選択しますか?\nあなたの選択：");
		scanf("%d", &i);
		printf("\n左から何番目を選択しますか?\nあなたの選択：");
		scanf("%d", &j);
		if(i>0 && i<=ROW && j>0 && j<=COL){	//範囲内が選択されたら
			if(look[i-1][j-1] == 0){	//選択したマスが伏せた状態だったら
				look[i-1][j-1] = 1;		//選択されたマスのカードを公開
			}else if(look[i-1][j-1] == 1){
				printf("そこはすでにオープンしています\n\n");
				k--;
			}else if(look[i-1][j-1] == 2){
				printf("そこはすでにカードがありません\n\n");
				k--;
			}
		} else {
			printf("そこにカードはありませんよ...？\n\n");
			k--;
		}

	}

	count = judge(look, real, count, point);	//芋づる式にcountの値をgame()まで返すためにやる
	return count;
}


char shuffle(char x[]){
	srand(unsigned(time(NULL)));
	int i, j, randum;
	char copy;

	for(i=0; i<52; i++){
		for(j=0; j<52; j++){
			randum = rand() % 52;
			copy = x[i];
			x[i] = x[randum];
			x[randum] = copy;
		}
	}
	return *x;
}

void winner(int playerpoint, int cpupoint){

	printf("Player vs CPU\n");
	printf(" %d - %d\n", playerpoint cpupoint);

	if(playerpoint > cpupoint){
		printf("プレイヤーの勝利！！おめでとう！！\n");
	} else if(playerpoint < cpupoint){
		printf("CPUの勝利...また挑戦してね！！\n");
	} else if(playerpoint == cpupoint){
		printf("引き分け！おしい！！\n");
	} else {
		printf("なんだかよくわかんないぞ...たまげたなぁ\n");
	}
	scanf("%*s");
}

void game(void){
	char x[] = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
	shuffle(x);

	/*
	//並び変わったかテスト
	int i;
	for(i=0; i<52; i++){
	printf("%c\n", x[i]);		
	}
	*/


	int look[ROW][COL] = {};	//0が伏せ状態、1が選択して開けた状態、2が取り除かれた状態

	char real[ROW][COL];
	int i,j, k=0;
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			real[i][j] = x[k];
			k++;
		}
	}

	char know[ROW][COL] = {};
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			know[i][j] = '0';
		}
	}//CPUのためのインチキ関数

	/*
	char playerword[26];	//揃えられた文字を保持する配列
	char computerword[26];	//揃えられた文字を保持する配列
	//今後のヴァージョンうｐのために残しておく。
	*/

	int playerpoint = 0;	//得点の管理
	int computerpoint = 0;	//得点の管理

	int count = 26;		//組み合わせのカウンタ
	int turn = rand() % 2;	//ターン管理

	int diff;	//揃えた時の続行カウント 

	printf("神経衰弱！！　ゲームスタート！！\n");
	while(count != 0){
		turn = (turn + 1) % 2;
		diff = count;

		printf("現在のスコア\n");
		printf("count  : %d\n", count);
		printf("player : %d\n", playerpoint);
		printf("cpu    : %d\n", computerpoint);
		puts("");

		if(turn == 0){
			printf("プレイヤーのターン\n");
			count = open(look, real, count, &playerpoint);
		}else{
			printf("CPUのターン\n");
			Sleep(3000);	//whindows.hに入っている関数です。もともとはLinux系統のsleeptime.hにあるやつ。
			count = cpuopen(look, real, know, count, &computerpoint);
		}
		if(diff != count) turn++;
	}

	printf("ゲーム終了！\n勝敗を判定します。\n");
	winner(playerpoint, computerpoint);
}


int main(void){
	game();

	return 0;
}

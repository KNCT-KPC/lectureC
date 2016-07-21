#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void drow(int look[13][4], char real[13][4]){
	int i, j;

	for(i=0; i<13; i++){
		for(j=0; j<4; j++){
			switch(look[i][j]){
			case 0: printf("□");
					break;
			case 1: printf("%c", real[i][j]);
					break;
			case 2: printf("×");
					break;
			}
			printf("\n");
		}
	}

}


int judge(int look[13][4], char real[13][4], int count, int point){
	char a[2];
	int i, j, k=0;
	for(i=0; i<13; i++){
		for(j=0; j<4; j++){
			if(look[i][j] == 1){
				a[k] = real[i][j];
				k++;
			}
		}
	}

	if(a[0] == a[1]){
		for(i=0; i<13; i++){
			for(j=0; j<4; j++){
				if(look[i][j] == 1){
					look[i][j] = 2;
				}
			}
		}
		printf("\nお見事！正解です。\nそろった文字は「%c」です！\n", a[0]);
		count--;
		point++;
	} else {
		for(i=0; i<13; i++){
			for(j=0; j<4; j++){
				if(look[i][j] == 1){
					look[i][j] = 0;
					printf("\n残念！はずれです。\n");
				}
			}
		}
	}

	return count;
}

int cpuopen(int look[13][4], char real[13][4], char know[13][4], int count, int point){
	//自分が開けたところは絶対覚えるマン
	int i, j, k, l;
	int x, y;
	int ans = 0;  //二つ選べた時のカウンタ

	while(ans != 2){
		for(i=0; i<13; i++){
			for(j=0; j<4; j++){
				for(k=i; k<13; k++){
					for(l=j+1; j<4; j++){
						if(know[i][j] != '0' || know[k][l] != '0'){
							if(know[i][j] == know[k][l]){
								look[i][j] == 1;
								look[k][l] == 1;
								ans = 2;
							}
						}
					}
				}
			}
		}

		//もし、for文で二つそろわなかったとき(knowの配列に一組もおなじカードがなかったとき)
		if(ans != 2){
			y = rand() % 13;
			x = rand() % 4;
			if(look[y][x] == 0){
				look[y][x] == 1;
				know[y][x] == real[y][x];
				ans++;
			}
		}
	}
	
	judge(look, real, count, point);
	return count;
}

int open(int look[13][4], char real[13][4], int count, int point){
	int i,j, k;
	for(k=1; k<3; k++){					//二か所選択されるまで続きます。ぶっちゃけwhile文でいいと思った。
		drow(look, real);

		printf("\n%dつ目を開けます。\n", k);
		printf("\n上から何番目を選択しますか?\nあなたの選択：");
		scanf("%d", &i);
		printf("\n左から何番目を選択しますか?\nあなたの選択：");
		scanf("%d", &j);
		if(i>0 && i<14 && j>0 && j<5){	//範囲内が選択されたら
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
	if(playerpoint > cpupoint){
		printf("プレイヤーの勝利！！おめでとう！！\n");
	} else if(playerpoint < cpupoint){
		printf("CPUの勝利...また挑戦してね！！\n");
	} else if(playerpoint == cpupoint){
		printf("引き分け！おしい！！\n");
	} else {
		printf("なんだかよくわかんないぞ...たまげたなぁ\n");
	}
}

void game(void){
	char x[] = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
    shuffle(x);

	int look[13][4] = { {0, 0, 0, 0}, 
						{0, 0, 0, 0}, 
						{0, 0, 0, 0}, 
						{0, 0, 0, 0},
						{0, 0, 0, 0}, 
						{0, 0, 0, 0}, 
						{0, 0, 0, 0}, 
						{0, 0, 0, 0},
						{0, 0, 0, 0}, 
						{0, 0, 0, 0}, 
						{0, 0, 0, 0}, 
						{0, 0, 0, 0},
						{0, 0, 0, 0} };		//0が伏せ状態、1が選択して開けた状態、2が取り除かれた状態


	//graphic(x);
	char real[13][4];
	int i,j, k=0;
	for(i=0; i<13; i++){
		for(j=0; i<4; j++){
			real[i][j] = x[k];
			k++;
		}
	}

	char know[13][4] = { {0, 0, 0, 0}, 
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0},
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0},
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0}, 
						 {0, 0, 0, 0},
						 {0, 0, 0, 0} };	//CPUのためのインチキ関数

	/*
	char playerword[26];	//揃えられた文字を保持する配列
	char computerword[26];	//揃えられた文字を保持する配列
	//今後のヴァージョンうｐのために残しておく。
	*/

	int playerpoint = 0;	//得点の管理
	int computerpoint = 0;	//得点の管理

	int count = 26;		//組み合わせのカウンタ
	int turn = rand() % 2;	//ターン管理


	printf("ゲームスタート");
	while(count != 0){
		turn = (turn + 1) % 2;
		
		if(turn == 0){
			printf("プレイヤーのターン\n");
			count = open(look, real, count, playerpoint);
		}else{
			printf("CPUのターン");
			count = cpuopen(look, real, know, count, computerpoint);
		}
	}

	printf("ゲーム終了！\n勝敗を判定します。\n");
	winner(playerpoint, computerpoint);
}


int main(void){
	game();

	return 0;
}

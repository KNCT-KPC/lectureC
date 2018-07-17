/*
*	左上から時計回りに渦巻き状に進んでいくすごろくゲーム
*	スタート位置を変えたいとか渦巻く向きを変えたいとかもいけるはず
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define R 7	// 盤面の大きさ(行)
#define C 7	// 盤面の大きさ(列)
#define SR 0	// スタート位置(行)
#define SC 0	// スタート位置(列)
#define GR 3	// ゴール位置(行)
#define GC 3	// ゴール位置(列)

void setField(char **field){
	int i,j;

	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			field[i][j] = '-';
		}
	}
}

void setGoal(char **field){
	field[GR][GC] = 'G';
}

void setChar(char **field, char c){
	field[SR][SC] = c;
}


void print(char **field){
	int i,j;


	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			printf("%c ", field[i][j]);
		}
		puts("");
	}
}

int saikoro(){
	int o = (rand() % 6) + 1;
	return o;
}

void susumu(char **field, char c, int me, int *row, int *col, int *rmax, int *rmin, int *cmax, int *cmin, int *muki){
	int i=0;
	int y = *row;
	int x = *col;
	int yx = *rmax;
	int yn = *rmin;
	int xx = *cmax;
	int xn = *cmin;
	int direction = *muki;


	field[y][x] = '-';
	
	printf("%d, %d, %d\n", y, x, direction);

	while((i != me) && (field[y][x] != field[GR][GC])){			// trueで{}内実行
		direction = direction % 12;	// 進む向き(時計の向き)

		if(direction == 3){
			if(x != xx){
				x++;
				i++;
			} else {
				direction += 3;	// 回れ右(足しあげてるのは後でルール追加するため)
				yn++;		// 端に到達したのでラインを狭める(不要になったら消す)
			}
		} else if(direction == 6){
			if(y != yx){
				y++;
				i++;
			} else {
				direction += 3;
				xx--;
			}
		} else if(direction == 9){
			if(x != xn){
				x--;
				i++;
			} else {
				direction += 3;
				yx--;
			}
		} else if(direction == 0){
			if(y != yn){
				y--;
				i++;
			} else {
				direction += 3;
				xn++;
			}
		}
	}

	printf("%d, %d, %d\n", y, x, direction);
	field[y][x] = c;	//　盤面を更新して終わり
	// print(field);
	*row = y;
	*col = x;
	*rmax = yx;
	*rmin = yn;
	*cmax = xx;
	*cmin = xn;
	*muki = direction;

}

int input(int q){
	rewind(stdin); // 入力バッファのクリア
	q = getchar();
	return q;
}

void game(char **field, char c, int row, int col, int rmax, int rmin, int cmax, int cmin, int muki){
	char *now[C];
	int i, me;
	int q = 0;

	for(i=0; i<C; i++) now[i] = field[i];


	

	while(field[GR][GC] != c){ // ゲームの継続条件
		print(now);
		printf("サイコロ振ります. [type y/n]\n");
		//q = input(q);
		q = 'y';
		printf("%c\n", q);
		
		if(q == 'y'){
			me = saikoro();
			printf("出た目は%dです.\n", me);
			susumu(now, c, me, &row, &col, &rmax, &rmin, &cmax, &cmin, &muki);
		} else if(q == 'n'){
			break;
		} else {
			break;
		}
		
	}

	print(now);
	printf("GOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOL\n");
}


int main()
{
	srand((unsigned)time(NULL));
	char field[R][C];

	int row = SR;	// 自キャラの居場所
	int col = SC;	// 自キャラの居場所
	char c = 'c';	// 自キャラ
	int rmax = R-1;
	int rmin = 0;
	int cmax = C-1;
	int cmin = 0;
	int muki = 3;	// 自キャラの向き
	int i;

	char *ban[C];
	for(i=0; i<C; i++) ban[i] = field[i];

	setField(ban);	
	setGoal(ban);
	setChar(ban, c);
	// print(ban);

	game(ban, c, row, col, rmax, rmin, cmax, cmin, muki);


	
	return 0;
}

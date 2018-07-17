#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main(void){
	int y, z, i, n;
	int x = 0;
	int turn;
	char a;

	while(x == 0){
		printf("カウントダウンゲームへようこそ！\nあなたは先攻でプレイしたいですか？　[y/n] ");
		scanf("%c", &a);
		if(a == 'y'){
			turn = 0;
		} else if(a == 'n'){
			printf("私が先攻でプレイします。\n");
			turn = 1;
		}
		printf("最初の数字を決めてください\n");
		scanf("%d", &x);
		if(x < 0){
			x = x*(-1);
			printf("その数字ですか…\n最初の数字は「%d」ですね？\n", x);
		} else {
			printf("それではゲーム開始！！\n\n");
		}
	}

	while(x > 1){
		printf("今の数字は%dだよ。\n", x);

		if(turn == 0){
		scanf("%d", &y);
		printf("%d引きますよ？\n", y);
	} else {
		n = 0;
		while(4*n+2 < x){
			n++;
			//printf("n = %d\n", n);
		}
		n--;
		if(x == 4*n+2){
			y = rand() % 3;
			//printf("aaa");
		}

		if((x-1) == 1){
			y = i;
		} else {
			for(i=1; i<=3; i++){
				if((x-i) == (4*n+2)){
					y = i;
				}
			}
		}
		printf("私は　-%d します。\n", y);
	}

	if(y >= 1 && y <= 3){
		z = x - y;
		//printf("%d - %d = %d\n\n", x, y, z);
		x = z;
		turn = (turn+1) % 2;
	} else {
		printf("その数字は使えないよ！１～３の範囲の数字を入力してね！\n\n");
	}

	if(x <= 1){
		if(turn -= 0){
			printf("おめでとう！あなたの勝ちです！。\n");
		} else {
			printf("残念！あなたの負けです…\n");
		}
	}

	}

}
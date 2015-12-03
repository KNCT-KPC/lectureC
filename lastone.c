#include<stdio.h>
#include<stdlib.h>

main(){
  int x, y, z, i, n;
  x = 0;
  int turn;
  char a;

  while(x == 0){
    printf("それでは始めましょう。\nあなたは先攻でプレイしたいですか？ [y/n] ");
    scanf("%c", &a);
    if(a == 'y'){
      turn = 0;
    } else if(a == 'n'){
      printf("それでは、私が先攻でゲームします。\n");
      turn = 1;
    } 
    printf("最初の数字はいくつにしますか？\n");
    scanf("%d", &x);
    if(x < 0){
      x = x*(-1);
      printf("あなたはおもしろい人ですね。\n最初の数字は「%d」ですね？\n", x);
    } else {
      printf("ゲーム開始です。\n\n");
    }
  }

  while(x > 1){
    printf("現在の値は%dです。\n", x);

    if(turn == 0){
      printf("あなたの番です。いくつ引きますか？(1~3)\n");
      scanf("%d", &y);
      printf("%d 引きますね？\n", y);
    } else {
      n = 0;
      while(4*n+2 < x){
	n++;
	printf("n = %d\n", n);
      }
      n--;
      if(x == 4*n+2){
	y = rand() % 3;
	printf("aaa");
      }
      //自分が2,6,10,...(4n+2)を言えば勝つ
      if((x-1) == 1){ //負け確だから仕方なく引く。
	y = 1;
      } else {
	for(i=1; i<=3; i++){
	  if((x-i) == (4*n+2)){
	    y = i;
	  }
	}
      }
      printf("私は -%d します。\n", y);
    }

    if(y >= 1 && y <= 3){
      z = x - y;
      printf("%d - %d = %d\n\n", x, y, z);
      x = z;
      turn = (turn+1) % 2;
    } else {
      printf("不正な値です。１～３の範囲の値で入力してください。\n\n");
    }

    if(x <= 1){
      if(turn == 0){
	printf("参りました。あなたの勝ちです。\n");
      } else {
	printf("やりました。あなたの負けです。\n");
      }
    }

  }

}

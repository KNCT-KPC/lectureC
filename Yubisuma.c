/*
  指スマげぇむ
  Coded by @nezumioffice
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//ファイルを導入します。


//masterなら直に書き換えられます。
int main(void){
	int x;  //終了前の入力状態のための無意味な変数
	int turn = 0;
	int myhand = 0,cpuhand = 0,cpuex;
	int mymax = 2,cpumax = 2;
	int n;

	printf("指スマ(諸説ある)しようよ！\n");
	printf("CPUはランダムです\n");
	srand((unsigned int)time(NULL));

	while(1){
		printf("指スマ！\nあなたは指を何本立てますか？(0~%d)\n",mymax);
		if(turn == 0){printf("あなたのたーん\n");}
		else printf("CPUのたーん\n");
		scanf("%d",&myhand);
		if(myhand < 0 || myhand > mymax){
			printf("正しい値を入れなさい\n再入力をしてください\n");
			continue;
		}
		if(turn == 0){
			printf("指スマなんぼですか?(0~%d)\n",mymax+cpumax);
			scanf("%d",&n);
			if(n < 0 || (mymax + cpumax) < n){
				printf("正しい値を入れなさい\n再入力をしてください\n");
				continue;
			}
			cpuhand = rand() % (cpumax + 1);
			printf("CPUの立てた指の数は%dでした\n",cpuhand);
			if((cpuhand + myhand)  == n){
				printf("あなたの予想が当たりました。片手が亡くなります。");
				mymax--;
			}
		}
		else if(turn == 1){
			cpuex = rand() % (cpumax + mymax  + 1) ;
			cpuhand = rand() % (cpumax + 1);
			printf("CPUの立てた指の数は%dでした\nCPUの予想した手は%dでした",cpuhand,cpuex);
			if((cpuhand + myhand) == cpuex){
				printf("CPUの予想が当たりました。片手がなくなります");
				cpumax--;
			}
		}
		if(cpumax == 0 || mymax == 0) break;
 		turn++;
		if(turn == 2) turn = 0;
	}


	if(turn == 1){
		printf("CPUの勝ちです");
	}
	else if(turn == 0){
		printf("あなたの勝ちです");
	}
	else 
	scanf("%d", &x);
	return 0;
}

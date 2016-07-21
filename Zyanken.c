#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// じゃんけんゲーム作りまーす。
int randum(void){
	int par;
	srand((unsigned)time(NULL));	
	par = (rand() % 3) + 1;
	printf("%d\n", par);
	return par;
}

int judge(int player, int computer){
	if((player == 1 || player == 2) && (player == computer-1)){
		printf("君の勝ち\n");
		return 1;
	}else if(player == 3 && computer == 1){
		printf("君の勝ち\n");
		return 1;
	}else if(player == 1 && computer == 3){
		printf("CPUの勝ち\n");
		return 2;
	}else if((player == 2 || player == 3) && (player == computer+1)){
		printf("CPUの勝ち\n");
		return 2;
	}else if(player == computer){
		printf("あいこ\n");
		return 0;
	}else{
		printf("不正な手です。\n");
		return 0;
	}
}

void hand(int somehand){
	switch(somehand){
		case 1: printf("ぐー");
				break;
		case 2: printf("ちょき");
				break;
		case 3: printf("ぱー");
				break;
	}
}

int main(void){
	int x;
	int myhand, cpuhand;
	int mywin, cpuwin;
	mywin = 0;
	cpuwin = 0;

	printf("じゃんけんしようよ！\n");
	printf("数字の1が[ぐー],2が[ちょき],3が[ぱー]だよ！\n");

	while(mywin < 3 && cpuwin < 3){
		printf("じゃん、けん、...\n");
		scanf("%d", &myhand);
		cpuhand = randum();

		hand(myhand);
		printf(" 対 ");
		hand(cpuhand);
		printf("\n");

		x = judge(myhand, cpuhand);
		switch(x){
			case 0: break;
			case 1: mywin++;
					break;
			case 2: cpuwin++;
					break;
		}
		printf("%d 対 %d\n", mywin, cpuwin);
	}

	if(mywin == 3){
		printf("あなたの勝ちです。\n");
	}else if(cpuwin == 3){
		printf("私の勝ちです。\n");
	}else{
		printf("ERROR\n");
	}

	scanf("%d", &x);
	return 0;
}

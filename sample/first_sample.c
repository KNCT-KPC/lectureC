#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void omikuzi(){
	int x,a;
	for(;;){
		printf("1~6の好きな数字を入力して、Enterキーを押すとおみくじを引くよ！\n");
		for(;;){
//			scanf("%d",&a);
			if(scanf("%d",&a) != 1){
				scanf("%*s");
				if(feof(stdin)) printf("Buffer Error!\n");
				printf("\n入力が間違っているよ\n");
				printf("もう一度入力してね\n\n");
				continue;
			}
			if(a==1 || a==2 || a==3 || a==4 || a==5 || a==6){
				break;
			} else if(a<=0 || a>= 7){
				printf("入力が間違っているよ\n");
				printf("もう一度入力してね\n\n");
				continue;
			}
		}
		srand((unsigned)time(NULL));
		printf("今日のあなたの運勢は...\n");
		x = rand()%6;
		if(x == 0){
			printf("  大吉だよ！！\n");
		} else if(x == 1){
			printf("  吉だよ！！\n");
		} else if(x == 2){
			printf("  中吉だよ！！\n");
		} else if(x == 3){
			printf("  小吉だよ！！\n");
		} else if(x == 4){
			printf("  凶だよ！！\n");
		} else if(x == 5){
			printf("  大凶だよ！！\n");
		}
//	printf("ゲームを終了します\n\n");
		break;
	}
}

void jannkenn(){
	int i,a,x;

	for(;;){
		printf("じゃんけんをするよ！\n");
		printf("1がグー,2がチョキ,3がパーだよ\n");
		printf("1,2,3のどれかを入力してね\n");
		printf("ジャンケン...\n");
		srand((unsigned)time(NULL));
		for(;;){
			if(scanf("%d", &a) != 1){
				scanf("%*s");
				if(feof(stdin)) printf("Buffer Error!\n");
				printf("\n入力が間違っているよ\n");
				printf("もう一度入力してね\n");
				continue;
			}
			//scanf("%d",&a);
			if(a==1 || a==2 || a==3){
				printf("ポン！！\n");
				x = rand()%3 +1;
				if(a==1){
					if(x==1){
						printf("あなたはグーで相手はグー\n");
					} else if(x==2){
						printf("あなたはグーで相手はチョキ\n");
					} else if(x==3){
						printf("あなたはグーで相手はパー\n");
					}
				} else if(a==2){
					if(x==1){
						printf("あなたはチョキで相手はグー\n");
					} else if(x==2){
						printf("あなたはチョキで相手はチョキ\n");
					} else if(x==3){
						printf("あなたはチョキで相手はパー\n");
					}
				}else if(a==3){
					if(x==1){
						printf("あなたはパーで相手はグー\n");
					} else if(x==2){
						printf("あなたはパーで相手はチョキ\n");
					} else if(x==3){
						printf("あなたはパーで相手はパー\n");
					}
				}
				if((a==1 && x==2) || (a==2 && x==3) || (a==3 && x==1)){
					printf("あなたの勝ち！！\n\n");
					break;
				} else if((a==1 && x==3) || (a==2 && x==1) || (a==3 && x==2)){
					printf("あなたの負け\n\n");
					break;
				} else if((a==1 && x==1) || (a==2 && x==2) || (a==3 && x==3)){
					printf("あいこで...\n");
					continue;
				}
			} else if(a<=0 || a>=4){
				printf("\n入力が間違っているよ\n");
				printf("もう一度入力してね\n\n");
				printf("ジャンケン...\n");
				continue;
			} else if(scanf("%d", &a) != 1){
				scanf("%*s");
				if(feof(stdin)) printf("Buffer Error!\n");
				printf("\n入力が間違っているよ\n");
				printf("もう一度入力してね\n");
				continue;
			}
			//printf("ゲームを終了します\n\n");
		}
		break;
	}
}

int main(){
	int a;
	char c;
	for(;;){
		printf("1.おみくじ,2.ジャンケン,0.終了\n");
		printf("好きなゲームの番号を入力してね");
		scanf("%d",&a);
		if(a==1){
			printf("おみくじを始めるよ\n\n");
			omikuzi();
			continue;
		} else if(a==2){
			printf("ジャンケンを始めるよ\n\n");
			jannkenn();
			continue;
		} else if(a==0){
			printf("終了します\n\n");
			break;
		}
		if(scanf("%d", &a) != 1){
			scanf("%*s");
			if(feof(stdin)) printf("Buffer Error!\n");
			printf("\n入力が間違っているよ\n");
			printf("もう一度入力してね\n\n");
			continue;
		}
	}
	return 0;
}

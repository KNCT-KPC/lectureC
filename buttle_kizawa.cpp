#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int game(int p1hp, int p1at, int p2hp, int p2at, int turn){
	int comand = 1;
	int damage = 0;
	int pragi = 100;
	int comagi;
	int a = 1;
	srand((unsigned)time(NULL));
	comagi = rand()%150;
	

	if(pragi > comagi){
		turn = 0;
		printf("P1の先攻\n");
	}else{
		turn = 1; 
		printf("P2の先攻\n");
	}

	while(p1hp > 0 && p2hp > 0){
		if(turn == 0){
			printf("なまえ\tLV\tHP\tMP\n1P\t1\t%d\t0\n",p1hp);
			printf("なにをしますか\n1: 攻撃 2:カウンター\n");
			scanf("%d",&comand);
			if(a == 1 && comand == 1){   
				damage = p1at;
				p2hp -= damage;
				printf("1Pの攻撃！2Pに %dのダメージ！\n", damage);
			}
			else if(a == 1 && comand == 2){
				damage = p1at - 5;
				p2hp -= damage;
				printf("1Pのカウンター！2Pに %dのダメージ！\n", damage);
			}
			else if(a == 2 && comand == 1){
				damage = p1at  - 10;
				p2hp -= damage;
				printf("1Pの攻撃！2Pに %dのダメージ！\n", damage);
			}
			else if(a == 2 && comand == 2) {
				damage = p1at  - 20;
				p2hp -= damage;
				printf("1Pのカウンター！2Pに %dのダメージ！\n", damage);
			}

			
		}else if(turn == 1){
			printf("2P\tLV\tHP\tMP\n2P\t1\t%d\t0\n",p2hp);
			a = rand()%2+1;
			if(a == 1 && comand == 1){   
				damage = p2at;
				p1hp -= damage;
				printf("2Pの　攻撃！1Pに %dのダメージ！\n", damage);
			}
			else if(a == 1 && comand == 2){ 
				damage = p2at - 10;
				p1hp -= damage;
				printf("2Pの　攻撃！1Pに %dのダメージ！\n", damage);
			}
			else if(a == 2 && comand == 1){
				damage = p2at  - 5;
				p1hp -= damage;
 				printf("2Pの　カウンター！1Pに %dのダメージ！\n", damage);
			}
			else if(a == 2 && comand == 2) {
				damage = p2at  - 20;
				p1hp -= damage;
 				printf("2Pの  カウンター！1Pに %dのダメージ！\n", damage);
			}
			
		}
		turn = (turn + 1) % 2;
	}
	/*どこに入れればいいのかわからないのでここでそれっぽそうなのを作っとく。
	やりたいことは出来れば相手にランダムで1か2を選んでほしいということ。
	int a;
	
	a = rand()%2+1;
	if(a == 1){
			damege = p2at;
	else if(a == 2)damege = p1at -5;
			p1hp -= damege;
	}

	。
	int p1agi;
	int cpuagi;
	srand((unsigned)time(NULL));
	p1agi = rand()%2+1;
	cpuagi = rand()%2+1;
	この後にp1agi>cpuagiのときp1からの攻撃になるとか、
	p1agi<cpuagiのときcpuからの攻撃になるみたいなことをかきたい。

	あとは次のターンに行く前に切りたい。
	出力待ちというのだろうか？
	一瞬でパッと自分の与えたダメージと与えられたダメージがすべて出てきたらなんか違うと思うんだ。

	*/
	turn--;
	return turn;
}

int main(void){
	int p1hp, p1at;
	int p2hp, p2at;
	int turn = 0;
	int make = 0;
	p1hp = 80;
	p1at = 20;

	p2hp = 80;
	p2at = 20;

	 make = game(p1hp, p1at, p2hp, p2at, turn);
	printf("%dP は　しんでしまった",make+2);
	scanf("%d",&turn);
}

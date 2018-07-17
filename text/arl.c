/*
講習会スレッド
>>61
問3
*/

#include<stdio.h>
#include<stdlib.h>

// タイの鉄道の一つ、スワンナプーム空港からバンコク市内を結ぶ
// AirportRailLink（ARL）の運賃計算を行う。
// 双方向に料金計算ができないといけません。
// 乗車駅と下車駅を聞きましょう。（何駅乗ったかでは簡単すぎますので,,,）

int BC(int on, int off){
	int s, g, count, fare;

	if(on < off){
		s = on;
		g = off;
	}else if(on > off){
		s = off;
		g = on;
	}else{
		printf("乗る駅と降りる駅が同じです。\n");
		s = 0;
		g = 0;
	}

	count = g - s;

	fare = 15 + 5 * (count - 1);

	return fare;
}

int Total(int fare, int x){
	return fare * x;
}

void main(){
	int pay;    //料金
	int parpay; //一人当たりの料金
	int geton;  //乗った駅
	int getoff; //降りた駅
	int man;    //乗った人数(人)

	int wait; //入力待ちにするためだけの無関係な変数

	/*ユーザに「何人でどこからどこまで乗ったか」を聞きます*/
	printf("何人で乗りましたか\n");
	scanf("%d", &man);

	printf("どの駅から乗りましたか（1～8）\n");
	scanf("%d", &geton);

	printf("どの駅で降りましたか(1～8)\n");
	scanf("%d", &getoff);


	/*ユーザから入力された値を元に計算していきます*/
	parpay = BC(geton, getoff); //Basic Calculation
	printf("一人当たりの運賃は %dバーツ です。\n", parpay);

	/*人数分の運賃の総額を求めます*/
	pay = Total(parpay, man);
	printf("支払金額は %dバーツです。\n", pay);


	scanf("%d", &wait);
}

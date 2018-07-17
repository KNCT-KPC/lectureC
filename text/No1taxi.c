#include<stdio.h>
#include<stdlib.h>

//タクシーの基本料金を計算するプログラム


/*基本料金の計算部分*/
int BC(int kyori){
	int kihon; //基本料金の変数
	int time = 0;  //値上げする回数のカウンタ

	if(kyori < 2000){ //距離が2000(m)未満なら...
		kihon = 560; //560円一律
	} else if(kyori >= 2000){ //距離が2000(m)以上なら...
		//2000m以上は130m毎に80円値上げするので...

		kyori = kyori - 2000; //値上げしない2000(m)を除いて...

		while(kyori >= 0){ //終了条件:kyoriが0以下
			time++; 
			kyori = kyori - 130;
			//何回値上げするか求めて...
		}

		kihon = 560 + 80 * time; //基本料金を求める
	}

	return kihon; //計算結果を返す
}


//距離割引を計算
int DS(int kihon, int kyori){
	int disc; //discount
	int price;

	if(kyori < 2000){ //2000m以下には適応されないので...
		kyori = 0;
	} else if(kyori > 11000){ //割引上限は10km分までなので...
		kyori = 10000;
	}

	disc = kyori / 1000; //割引は1km毎なので...

	price = kihon * (100 - disc) / 100; //n倍(%)に変換するため100で割る

	price = price + (10 - (price % 10)); //端数(1の位)切り上げ

	return price; //計算結果を返す
}


//深夜料金を計算
int MID(int ryokin, int time){
	int price;

	if(time <= 6 || time >= 20){ //もし、時間が6以下、または、時間が20以上なら...
		price = ryokin * 1.2; //二割増し（120%）の支払い

		price = price + (10 - (price % 10)); //端数(1の位)切り上げ

		printf("深夜料金です。");
	} else { //深夜料金でないなら
		price = ryokin; //割り増しはない
	}

	return price; //計算結果を返す
}

//必要なタクシーの台数を求める（一台に四人まで乗れる設定）
int CAR(int ryokin, int ninzu){ 
	int price;
	int taxi = 0;

	while(ninzu >= 0){ //終了条件:ninzuが0以下
		taxi++;
		ninzu = ninzu - 4; //（ninzu -= 4;）でもよい
	}

	price = ryokin * taxi;
	printf("必要なタクシーは %d台です。", taxi);

	return price;
}

//一人当たりの支払額を計算
int PP(int price, int ninzu){
	int onepay;

	onepay = price / ninzu;

	return onepay;
}

void main(){
	int pay; //料金
	int parpay; //一人当たりの料金
	int dis; //乗った距離(m)
	int tim; //乗った時間(0時～24時)
	int man; //乗った人数(人)

	int wait; //入力待ちにするためだけの無関係な変数

	/*ユーザに「何時に何人で何m乗ったか」を聞きます*/
	printf("何時に乗りましたか(0 ~ 24)\n");
	scanf("%d", &tim);

	printf("何人で乗りましたか\n");
	scanf("%d", &man);

	printf("何m乗りましたか\n");
	scanf("%d", &dis);


	/*ユーザから入力された値を元に計算していきます*/
	pay = BC(dis); //Basic Calculation

	printf("基本料金は %d円です。\n", pay);


	/*距離に応じた割引料金を計算します*/
	pay = DS(pay, dis); //Distance Sale
	
	printf("距離割適応後の料金は %d円です。\n", pay);


	/*時間に応じた料金計算（深夜割増）を行います*/
	pay = MID(pay, tim); //Midnight


	/*人数に応じたタクシーの台数を求め、台数分の料金を計算します*/
	pay = CAR(pay, man);

	printf("支払金額は %d円です。\n", pay);


	/*一人当たりの支払額を計算します*/
	parpay = PP(pay, man);

	printf("一人当たりの支払額は %d円です。\n", parpay);

	scanf("%d", &wait);
}

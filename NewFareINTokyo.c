/*
講習会スレッド
>>61
問4
*/

#include<stdio.h>
#include<stdlib.h>

// 首都圏のタクシーの新料金（2017/01/30より施行）に基づいた計算を行う。
// 既に挑戦したタクシーの計算方法を流用できるので、難しくはないはず。
// 以前のプログラムよりは計算を簡略化しています（その代わり理解力を求められます）
// タクシーの料金を計算するプログラム


/*
ここで、新たな手法を使います。
今後、また料金制度が変わったりすると値を書き換えたりするのが面倒なので、
可変的かつ複数回使用する変数をひとつにまとめます。
*/
#define hatsunorikyori 1059
#define hatsunoriryokin 410

#define neagarikyori 235
#define neagariryokin 80
/*
まじめなおはなし
ソース上に、意味のある定数（いわゆるマジックナンバー）
を直接に書くことは良いこととは言えません。
後でプログラムを読む人が、数値の意味を理解できないことになり得るし、
数値が変更になった時に、ソースの修正箇所が増えてしまいます。
これを避けるために、 #define をよく利用します。
*/



/*基本料金の計算部分*/
int BC(int kyori){
	int kihon; //基本料金の変数
	int time = 0;  //値上げする回数のカウンタ

	printf("計算開始\n");

	while(kyori >= 0){ // 終了条件:kyoriが0以下 " if(kyori >= 0) の値が false の時 "
		if(time == 0){
			kihon = hatsunoriryokin;
			kyori -= hatsunorikyori;
		} else {
			kihon += neagariryokin;
			kyori -= neagarikyori;
		}
		time++;
	}

	printf("計算完了\n");

	return kihon; //計算結果を返す
}


//必要なタクシーの台数を求める（一台に四人まで乗れる設定）
int CAR(int ryokin, int ninzu){ 
	int price;
	int taxi = 0;

	while(ninzu > 0){ //終了条件:ninzuが0以下
		taxi++;
		ninzu -= 4; 
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
	int man; //乗った人数(人)

	int wait; //入力待ちにするためだけの無関係な変数

	/*ユーザに「何人で何m乗ったか」を聞きます*/
	printf("何人で乗りましたか\n");
	scanf("%d", &man);

	printf("何m乗りましたか\n");
	scanf("%d", &dis);


	/*ユーザから入力された値を元に計算していきます*/
	pay = BC(dis); //Basic Calculation

	printf("基本料金は %d円です。\n", pay);


	/*人数に応じたタクシーの台数を求め、台数分の料金を計算します*/
	pay = CAR(pay, man);

	printf("支払金額は %d円です。\n", pay);


	/*一人当たりの支払額を計算します*/
	parpay = PP(pay, man);

	printf("一人当たりの支払額は %d円です。\n", parpay);

	scanf("%d", &wait);
}

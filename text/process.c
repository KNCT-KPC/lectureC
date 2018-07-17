#include<stdio.h>

int plus(){
	int a, b, rezult;
	
	printf("足す数 ... ");
	scanf("%d", &a);
	printf("\n足される数 ... ");
	scanf("%d", &b);

	rezult = a + b;
	return rezult;
}
int minus(){
	int rezult;
	//自作してみてください。

	rezult = 0; //ココは計算の結果が代入されます。
	return rezult;
}
int multi(){
	int a, b;
	int rezult = 0;
	int i;
	printf("かける数 ... ");
	scanf("%d", &a);
	printf("\nかけられる数 ... ");
	scanf("%d", &b);
	if(b >= 0){
		for(i=0; i<b; i++){ // 正の掛け算
			rezult += a;	// rezult = rezult + a; の省略形。
		}
	}else{
		for(i=0; i>b; i--){ // 負の掛け算
			rezult -= a;	// rezult = rezult - a; の省略形。
		}
	}
	return rezult;
}
int div(){
	int rezult = 0;
	int a, b;
	//ヒント : for文じゃbreakするための判定をしないとできないと思うよ。
	//ヒント : while(???) のやり方の方が簡単かも？（個人的に）
	while(a >= b){
		a -= b;		// a = a - b;
		rezult++;	// rezult = rezult + 1;
	}
	/* 足し算のみ
	int c = 0;
	while(c >= b){
		c += a;
		if(c >= b) rezult++;
	}
	*/
	return rezult;
}

/*
int division(){		
	int rezult = 0;
	int a, b;
	if(a => 0 && b > 0
	while(a > b){
		a -= b;		// a = a - b;
		rezult++;	// rezult = rezult + 1;
	}
	return rezult;
}
*/
int main(void){
	int kotae;
	
	int mode;
	printf("どの計算をしますか？\n足し算 ... 1\n引き算 ... 2\n掛け算 ... 3\n"); 
	scanf("%d", &mode);
	switch(mode){
		case 1: kotae = plus();
				break;	//ブレイク大事。
		case 2: kotae = minus();
				break;
		case 3: kotae = multi();
				break;
	}

	printf("答えは%dです。", kotae);
	
	scanf("%d", &kotae);
	return 0;		//この二行はプログラムには無関係です。
}

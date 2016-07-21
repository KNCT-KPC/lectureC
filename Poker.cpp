#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(){
	int card[52] = {0};										//トランプカード
	/*トランプカード1枚1枚に変数を割り振り、
	カードが引かれたかを表す。
	0or1で引かれたか否かを判別する。
	0-12	スペード
	13-25	クローバー
	26-38	ハート
	39-51	ダイヤ
	52		ジョーカー(めんどくさいので生成しないようにした)*/

	int onehand[5] = {0};									//手札
	int twohand[5] = {0};
	int hand[5] = {0};

	int onerank = 0;										//役の強さ
	int tworank = 0;
	int rank = 0;

	int buf[2] = {0};										//一時的なスペース
	//homo
	int i = 0;
	int j = 0;
	int k = 0;
	int copy = 0;

	int handle[5] = {0};	

	int pare = 0;

	srand((unsigned)time(NULL));
	int rnd = 0;

	while(i < 5){											//手札の生成(1P)
		rnd = rand() % 52;
		if(card[rnd] != 1){
			onehand[i] = rnd;
			i++;
			card[rnd] = 1;
		}
	}

	i = 0;

	while(i < 5){											//手札の生成(2P)
		rnd = rand() % 52;
		if(card[rnd] != 1){
			twohand[i] = rnd;
			i++;
			card[rnd] = 1;
		}
	}

	/*
	for(i=0;i<5;i++){
	printf("%d\n",onehand[i]);
	}
	printf("\n");

	for(i=0;i<5;i++){
	printf("%d\n",twohand[i]);
	}
	printf("\n");
	*/


	printf("1Pのターンです。\n");

	for(i=0;i<5;i++){										//手札の表示(1P)
		printf("%d ", i+1); 
		j = onehand[i] / 13;
		switch(j){
		case 0:printf("スペードの");
			break;
		case 1:printf("クローバーの");
			break;
		case 2:printf("ハートの");
			break;
		case 3:printf("ダイヤの");
			break;
			//case 4:printf("Joker\n");
		}
		//if(onehand[i] != 52){
		printf("%d\n", onehand[i] % 13 + 1);
		//}
	}
	printf("\n");

	printf("交換するカードの番号を入力してください\n");
	printf("例:1枚目と3枚目を交換する場合[13]\n");
	scanf("%d", &i);

	printf("\n");

	while(1){												//手札の交換(1P)
		

		//if(i == 0) break;
		j = i % 10;
		rnd = rand() % 52;
		if(card[rnd] != 1){
			printf("%d枚目を交換しました。\n", j);
			onehand[j-1] = rnd;
			if(i < 6) break;
			else i = i / 10;
		}
	}

	printf("\n");

	printf("2Pのターンです。\n");

	for(i=0;i<5;i++){										//手札の表示(2P)
		printf("%d ", i+1); 
		j = twohand[i] / 13;
		switch(j){
		case 0:printf("スペードの");
			break;
		case 1:printf("クローバーの");
			break;
		case 2:printf("ハートの");
			break;
		case 3:printf("ダイヤの");
			break;
			//case 4:printf("Joker\n");
		}
		//if(twohand[i] != 52){
		printf("%d\n", twohand[i] % 13 + 1);
		//}
	}
	printf("\n");

	printf("交換するカードの番号を入力してください\n");
	printf("例:1枚目と3枚目を交換する場合[13]\n");
	printf("交換しない場合は[0]を入力\n");
	scanf("%d", &i);

	printf("\n");

	while(1){													//手札の交換(2P)
		if(i == 0) break;
		j = i % 10;
		rnd = rand() % 52;
		if(card[rnd] != 1){
			printf("%d枚目を交換しました。\n", j);
			//onehand[j-1] = rnd;
			twohand[j-1] = rnd;
			if(i < 6) break;
			else i = i / 10;
		}
	}


	for(k = 0; k < 2; k++){
		if(k == 0){
			for(i = 0; i < 5; i++){
				hand[i] = onehand[i];
			}
		}else if(k == 1){
			for(i = 0; i < 5; i++){
				hand[i] = twohand[i];
			}
		}

		for(i = 0; i < 5; i++){										//手札のソート
			for(j = 0; j < 5; j++){
				if(hand[i] < hand[j]){
					copy = hand[i];
					hand[i] = hand[j];
					hand[j] = copy;
				}
			}
		}

		for(i = 0; i < 5; i++){										//カードの数字を代入
			handle[i] = hand[i] % 13;
		}


		for(i = 0; i < 5; i++){										//カードの数字ソート
			for(j = 0; j < 5; j++){
				if(handle[i] < handle[j]){
					copy = handle[i];
					handle[i] = handle[j];
					handle[j] = copy;
				}
			}
		}

		/*for(i = 0; i < 5; i++){
		printf("%d %d\n",i,handle[i]);
		}
		printf("\n");*/

		//ロイヤルストレートフラッシュか(済)
		if(hand[0] == 0 && hand[1] == 9 && hand[2] == 10 && hand[3] == 11 && hand[4] == 12){
			rank = 9;
		}else

			//ストレートフラッシュか(済)
			if(hand[0] / 13 == hand[1] / 13 && hand[1] / 13 == hand[2] / 13 &&
				hand[2] / 13 == hand[3] / 13 && hand[3] / 13 == hand[4] / 13 &&
				hand[1] % 13 == hand[0] % 13 + 1 && hand[2] % 13 == hand[1] % 13 + 1 &&
				hand[3] % 13 == hand[2] % 13 + 1 && hand[4] % 13 == hand[3] % 13 + 1){
					rank = 8;
			}else

				//フォーカードか(済)
				if(hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 ||
					hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[4] % 13 ||
					hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ||
					hand[0] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ||
					hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ){
						rank = 7;
				}else

					//フルハウスか(済)
					if(handle[0] == handle[1] && handle[1] == handle[2] && handle[3] == handle[4] ||
						handle[0] == handle[1] && handle[1] == handle[3] && handle[2] == handle[4] ||
						handle[0] == handle[1] && handle[1] == handle[4] && handle[2] == handle[4] ||
						handle[0] == handle[2] && handle[2] == handle[3] && handle[1] == handle[4] ||
						handle[0] == handle[2] && handle[2] == handle[4] && handle[1] == handle[3] ||
						handle[0] == handle[3] && handle[3] == handle[4] && handle[1] == handle[2] ||
						handle[1] == handle[2] && handle[2] == handle[3] && handle[0] == handle[4] ||
						handle[1] == handle[2] && handle[2] == handle[4] && handle[0] == handle[3] ||
						handle[1] == handle[3] && handle[3] == handle[4] && handle[0] == handle[2] ||
						handle[2] == handle[3] && handle[3] == handle[4] && handle[0] == handle[1] ){
							rank = 6;
					}else

						//フラッシュか(済)
						if(hand[0] / 13 == hand[1] / 13 && hand[1] / 13 == hand[2] / 13 &&
							hand[2] / 13 == hand[3] / 13 && hand[3] / 13 == hand[4] / 13 ){
								rank = 5;
						}else

							//ストレートか(済)
							if(handle[1] == handle[0] + 1 && handle[2] == handle[1] + 1 &&
								handle[3] == handle[2] + 1 && handle[4] == handle[3] + 1){
									rank = 4;
							}else

								//スリーカードか(済)
								if(hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[2] % 13 ||
									hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[3] % 13 ||
									hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[4] % 13 ||
									hand[0] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 ||
									hand[0] % 13 == hand[2] % 13 && hand[2] % 13 == hand[4] % 13 ||
									hand[0] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ||
									hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 ||
									hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[4] % 13 ||
									hand[1] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ||
									hand[2] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ){
										rank = 3;
								}else

									//ツーペアか
									for(i = 0; i < 5; i++){
										for(j = 0; j < 5; j++){
											if(i != j && handle[i] == handle[j] && buf[0] != j && buf[1] != i){
												//printf("%d", pare);
												buf[0] == i;
												buf[1] == j;
												pare++;
											}	
										}
									}
									rank = pare;

									if(k == 0) onerank = rank;
									else if(k == 1) tworank = rank;

									for(i=0;i<5;i++){										//手札の表示
										printf("%d ", i+1); 
										j = onehand[i] / 13;
										switch(j){
										case 0:printf("スペードの");
											break;
										case 1:printf("クローバーの");
											break;
										case 2:printf("ハートの");
											break;
										case 3:printf("ダイヤの");
											break;
											//case 4:printf("Joker\n");
										}
										//if(hand[i] != 52){
										printf("%d\n", onehand[i] % 13 + 1);
										//}
									}
									printf("\n");

	}
	switch(onerank){										//判定結果の表示
	case 9: printf("ロイヤルストレートフラッシュ");
		break;
	case 8: printf("ストレートフラッシュ");
		break;
	case 7: printf("フォーカード");
		break;
	case 6: printf("フルハウス");
		break;
	case 5: printf("フラッシュ");
		break;
	case 4: printf("ストレート");
		break;
	case 3: printf("スリーカード");
		break;
	case 2: printf("ツーペア");
		break;
	case 1: printf("ワンペア");
		break;
	case 0: printf("ハイカード");
		break;
	}

	printf("\n");

	for(i=0;i<5;i++){										//手札の表示
		printf("%d ", i+1); 
		j = twohand[i] / 13;
		switch(j){
		case 0:printf("スペードの");
			break;
		case 1:printf("クローバーの");
			break;
		case 2:printf("ハートの");
			break;
		case 3:printf("ダイヤの");
			break;
			//case 4:printf("Joker\n");
		}
		//if(hand[i] != 52){
		printf("%d\n", twohand[i] % 13 + 1);
		//}
	}
	printf("\n");

	switch(tworank){										//判定結果の表示
	case 9: printf("ロイヤルストレートフラッシュ");
		break;
	case 8: printf("ストレートフラッシュ");
		break;
	case 7: printf("フォーカード");
		break;
	case 6: printf("フルハウス");
		break;
	case 5: printf("フラッシュ");
		break;
	case 4: printf("ストレート");
		break;
	case 3: printf("スリーカード");
		break;
	case 2: printf("ツーペア");
		break;
	case 1: printf("ワンペア");
		break;
	case 0: printf("ハイカード");
		break;
	}

	printf("\n");

	if(onerank > tworank){
		printf("1Pの勝ち!");
	}else if(onerank < tworank){
		printf("2Pの勝ち!");
	}else printf("引き分け");
}

int main(void){

	int pause = 0;


	game();


	scanf("%d",&pause);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* hoge ペア かどうか調べます ( int hand[] -> 手札, int pairary[] -> 結果格納配列 ) */
void pair(int hand[], int pairary[]) {
/* pairary[0] = ワンペアの個数(2つならツーペア)
 * pairary[1] = スリーカードの個数
 * pairary[2] = フォーカードの個数
 * pairary[3] = ファイブカードの個数(ジョーカーの扱いを定義する必要あり)
 */

	int i, j;
	int count = 5; // 手札枚数
	int checkl; // チェックする手札の値1
	int checkr; // チェックする手札の値2
	int paircnt; // (2, 3, 4, 5)カード記録用
	int checked[5] = {}; // チェック済み手札を記録します
	for(i = 0; i < count; i++) {
		paircnt = 0; // 初期化
		checkl = hand[i] % 13 + 1; // カードの数字を算出
		for(j = i; j < count; j++) { // まだ見ていない組み合わせについて
			checkr = hand[j] % 13 + 1; // カードの(ry
			if(checkl == checkr && checked[j] == 0) { // カードの数字が同じ かつ まだ見ていない（結果に反映させていない）場合
				paircnt++; // (hoge)カードにする
				checked[j]++; // 結果反映済みにする
			}
		}
		if(paircnt >= 2) pairary[paircnt-2]++; // ワンペア以上なら反映
	}
	return;
}

/* qsort() 関数のソート方法を定義 */
int compare_int(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

/* ストレート かどうか調べます ( int hand[] -> 手札 ) */
int straight(int hand[]) {
/* 戻り値 :
 * 0 -> ストレートでない
 * 1-13 -> 最大の値がそれのストレート ( 戻り値が 7 なら、( 3, 4, 5, 6, 7 ) )
 * 14 -> 最大の値が A のストレート (10, 11, 12, 13, 1 の組み合わせ)
 */

	int stritary[5] = {}; // カードの数字情報のみを記録
	int num; // 戻り値格納用
	int i;
	for(i = 0; i < 5; i++) {
		stritary[i] = hand[i] % 13 + 1; // カードの数字を算出
		//printf("%d\n", stritary[i]);
	}

	qsort(stritary, 5, sizeof(int), compare_int); // ソート(整列)

	if(stritary[0] == 1 && stritary[1] == 10 && stritary[2] == 11 && stritary[3] == 12 && stritary[4] == 13) { // 最大値が A の場合の特殊ケース
		return 14;
	}

	num = stritary[0]; // 数値比較用
	for(i = 1; i < 5; i++) {
		if(stritary[i] != (num + 1)) { // 数値が1上昇していないなら
			return 0;
		}
		num = stritary[i]; // 値を更新
	}
	return num;
}

/* フラッシュ かどうか調べます ( int hand[] -> 手札 ) */
int flush(int hand[]) {
/* 戻り値 :
 * 0 -> フラッシュでない
 * 1 -> スペードのフラッシュ
 * 2 -> ハートのフラッシュ
 * 3 -> ダイヤのフラッシュ
 * 4 -> クローバーのフラッシュ
 */

	int flushary[5] = {}; // カードの柄情報のみを格納
	int num; // 戻り値格納用
	int i;
	for(i = 0; i < 5; i++) {
		flushary[i] = hand[i] / 13 + 1; // カードの柄を算出
		//printf("%d : %d\n", hand[i] % 13 + 1, flushary[i]);
	}
	num = flushary[0]; // 柄比較用
	for(i = 1; i < 5; i++) {
		if(flushary[i] != num) { // 柄が異なるなら、
			return 0;
		}
	}
// スペードのフラッシュが一番強く、ついでハート、ダイヤ、クラブの順。
	switch(num) {
	case 1:
		return 4;
	case 2:
		return 1;
	case 3:
		return 3;
	case 4:
		return 2;
	default:
		return 0;
	}
}

/* 役を決定します ( int pairhand[] -> ペア配列, int strit -> ストレート判定, int flush -> フラッシュ判定 ) */
int aryres(int pairary[], int strit, int flush) {
	if(pairary[3] != 0) {
		printf("5カード\n");
		return 10;
	}
	if(strit != 0 && flush != 0) {
		if(strit == 14) {
			printf("ロイヤルストレートフラッシュ\n");
			return 9;
		}
		printf("ストレートフラッシュ\n");
		return 8;
	}
	if(pairary[2] != 0) {
		printf("4カード\n");
		return 7;
	}
	if(pairary[1] != 0 && pairary[0] != 0) {
		printf("フルハウス\n");
		return 6;
	}
	if(flush != 0) {
		printf("フルハウス\n");
		return 5;
	}
	if(strit != 0) {
		printf("ストレート\n");
		return 4;
	}
	if(pairary[1] != 0) {
		printf("3カード\n");
		return 3;
	}
	if(pairary[0] == 2) {
		printf("ツーペア\n");
		return 2;
	}
	if(pairary[0] == 1) {
		printf("ワンペア\n");
		return 1;
	}
	printf("ハイカード\n");
	return 0;
}

/* 勝敗を決定します ( int onehand[] -> 1P手札, int twohand[] -> 2P手札 ) */
void match(int onehand[], int twohand[]) {
	int onepairary[4] = {};
	int twopairary[4] = {};
	int onestrit, twostrit;
	int oneflush, twoflush;
	int oneres, twores;
	int i, j;

// 1P手札表示 冗ちょ(ry
	printf("1P手札\n");
	for(i=0;i<5;i++){ //手札の表示
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
		printf("%d\n", twohand[i] % 13 + 1);
		//}
	}
	printf("\n");

	printf("2P手札\n");
// 2P手札表示 冗ちょ(ry
	for(i=0;i<5;i++){ //手札の表示
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

// ペア配列を求める
	pair(onehand, onepairary);
	pair(twohand, twopairary);

// ストレート判定を行う
	onestrit = straight(onehand);
	twostrit = straight(twohand);

// フラッシュ判定を行う
	oneflush = flush(onehand);
	twoflush = flush(twohand);

// 役を求める
	printf("1Pは...\n");
	oneres = aryres(onepairary, onestrit, oneflush);
	printf("2Pは...\n");
	twores = aryres(twopairary, twostrit, twoflush);



//勝敗判定
	if(oneres > twores) {
		printf("1Pの勝ち\n");
	}
	else if(oneres < twores) {
		printf("2Pの勝ち\n");
	}
	else {
		/* コーディングの手間を惜しんだ結果 */
		printf("引き分け\n");
	}
	return;
/*
// 表示用サンプル
for(i = 0; i < 4; i++) {
printf("%d カード : %d\n", i+2, pairary[i]);
}
printf("ストレート : %d\n", straight(onehand));
printf("フラッシュ : %d\n", flush(onehand));
*/
}

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
	printf("交換しない場合は[0]を入力\n");
	scanf("%d", &i);

	printf("\n");

	while(1){												//手札の交換(1P)
		

		if(i == 0) break;
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

	match(onehand, twohand);


/*
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

  //for(i = 0; i < 5; i++){
  printf("%d %d\n",i,handle[i]);
  }
  printf("\n");//

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
*/
}

int main(void){

	int pause = 0;


	game();


	scanf("%d",&pause);
	return 0;
}

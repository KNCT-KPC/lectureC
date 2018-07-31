#include <stdio.h>

/* 碁盤の縦横 */
#define ROW 16
#define COL 16

/* 何目並べか */
#define MOKU 5

/* debug (関数名と任意のメッセージを表示します．printf()関数と同様の使い方) */
/*C99
#define DEBUG(...)  DEBUG_2(__VA_ARGS__, "")
#define DEBUG_2(fmt, ...)			\
 printf("%s(): "fmt"%s", __func__, __VA_ARGS__)
*/

 /* GNU Only
#define DEBUG(fmt, ...)					\
 printf("%s(): "fmt, __func__, ## __VA_ARGS__)
 */
char printGo(int num)
{
/* 碁盤のマスの数値を文字に変換します */
    switch(num) {
    case 0:
	return '-';
    case 1:
	return 'o';
    case 2:
	return 'x';
    default:
	break;
    }
    return 'q'; // ここへは到達しない
}

void printField(int field[][COL])
{
/* 碁盤を表示します */
    int i, j; // 繰り返しのため
    printf("1Pの碁石 -> o, 2Pの碁石 -> x, まだ碁石がない -> -\n");
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("%2d ", i+1);
    }
    printf("\n     ");
    for(i = 0; i < COL; i++) {
	printf("---");
    }
    printf("\n");
    for(i = 0; i < ROW; i++) {
	printf("%2d | ",i+1);
	for(j = 0; j < COL; j++) {
	    printf(" %c ", printGo(field[i][j]));
	}
	printf("\n");
    }
    return;
}

int fieldCheck(int field[][COL], int row, int col)
{
/* 入力した指し手が不正な数値でないか確認します */

/* 入力値が範囲外でないか */
    if(row < 0 || ROW <= row) return -1;
    if(col < 0 || COL <= col) return -2;

/* 既に碁石が置かれていないか */
    if(field[row][col] != 0) return 1;
    return 0;
}

void fieldChange(int field[][COL], int row, int col, int turn)
{
/* 碁盤の配列に碁石を配置します */
    int result;

    if(turn == 1) result = 1;
    else result = 2;
    field[row][col] = result;
    return;
}

void Msg(int code)
{
/* メッセージを表示します */
    puts(""); // (= printf("\n");
    if(code > 0) {
	printf("このマスはすでに碁石があります。選択しなおしてください。\n");
    }
    else if(code < 0) {
	printf("このマスは範囲外です。選択しなおしてください。\n");
    }
    else {
	printf("碁石を置きました\n");
    }
    puts(""); // (= printf("\n");
    return;
}

void input(int field[][COL], int turn)
{
/* 指し手の入力を受付け，碁石を配置します */
    int row = 0;
    int col = 0;
    int status; // 入力値が不正かどうかの結果を保存するため
    while(1) {
	printField(field); // 碁盤の表示
	printf("%dP のターンです\n",turn);
	printf("あなたのマス目を選択してください\n");
	printf("縦(入力後に Enter キーを押してください) : ");

/* とりあえず文字入力時の無限ループ回避 */
	if(scanf("%d", &row) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n不正な値です．再入力してください．\n\n");
	    continue;
	}

	printf("横(入力後に Enter キーを押してください) : ");

/* とりあえず文字入力時の無限ループ回避 */
	if(scanf("%d", &col) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n不正な値です．再入力してください．\n\n");
	    continue;
	}

	row--;
	col--;
	status = fieldCheck(field, row, col); // 入力値のチェック
	Msg(status); // チェック結果のメッセージを表示
	if(status == 0) break; // 正常ならループを抜ける
    }
    fieldChange(field, row, col, turn); // 碁盤の配列の入力した場所に碁石を置く(=値を書き込む)
    return;
}

int rowDecision(int field[][COL], int turn)
{
/* 五目並べが揃っているか判定します．効率の悪い総当りです */
    int g, h, i, j, cnt1 = 0, cnt2 = 0;

/* 横並びの判定 */
    for(i = 0; i < ROW; i++) {
	for(g = 0; g <= COL-MOKU; g++) {
	    //DEBUG("g = %d\n", g);
	    for(j = g; j < g+MOKU; j++) {
		//DEBUG("i = %d, j = %d\n", i, j);
		if(field[i][j] == 1) cnt1++;
		if(field[i][j] == 2) cnt2++;
	    }
	    //DEBUG("cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
	    if(cnt1 == MOKU) return 1;
	    if(cnt2 == MOKU) return 2;
	    else {
		cnt1 = 0;
		cnt2 = 0;
	    }
	}
    }

/* 縦並びの判定 */
    for(j = 0; j < COL; j++) {
	for(h = 0; h <= ROW-MOKU; h++) {
	    //DEBUG("h = %d\n", h);
	    for(i = h; i < h+MOKU; i++) {
		//DEBUG("i = %d, j = %d\n", i, j);
		if(field[i][j] == 1) cnt1++;
		if(field[i][j] == 2) cnt2++;
	    }
	    //DEBUG("cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
	    if(cnt1 == MOKU) return 1;
	    if(cnt2 == MOKU) return 2;
	    else {
		cnt1 = 0;
		cnt2 = 0;
	    }
	}
    }

/* 斜め判定 */
/* 左上 -> 右下 */
    for(g = 0; g <= ROW-MOKU; g++) {
	for(h = 0; h <= COL-MOKU; h++) {
	    //DEBUG("g = %d, h = %d\n", g, h);
	    for(i = g,j = h; (i < ROW && j < h+MOKU); i++, j++) {
		//DEBUG("i = %d, j = %d\n", i, j);
		if(field[i][j] == 1) cnt1++;
		if(field[i][j] == 2) cnt2++;
	    }
	    //DEBUG("cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
	    if(cnt1 == MOKU) return 1;
	    if(cnt2 == MOKU) return 2;
	    else {
		cnt1 = 0;
		cnt2 = 0;
	    }
	}
    }

/* 右上 -> 左下 */
    for(g = 0; g <= ROW-MOKU; g++) {
	for(h = 4; h < COL; h++) {
	    //DEBUG("g = %d, h = %d\n", g, h);
	    for(i = g,j = h; (i < ROW && h-MOKU < j); i++, j--) {
		//DEBUG("i = %d, j = %d\n", i, j);
		if(field[i][j] == 1) cnt1++;
		if(field[i][j] == 2) cnt2++;
	    }
	    //DEBUG("cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
	    if(cnt1 == MOKU) return 1;
	    if(cnt2 == MOKU) return 2;
	    else {
		cnt1 = 0;
		cnt2 = 0;
	    }
	}
    }

    return 0;
}

int decision(int field[][COL], int turn)
{
/* 五目並べが揃っているか判定をし，メッセージを表示します */
    int res = rowDecision(field, turn); // 実際に判定し結果を代入
    if(res != 0) { // 勝敗がついたなら
	printField(field); // 碁盤を表示
	if(res == 1) printf("1Pの勝ち，終了です\n");
	if(res == 2) printf("2Pの勝ち，終了です\n");
	return 1;
    }
    return 0;
}

void game() {
/* 指し手を変更したり，入力させたり，判定をしたり... */

/* 初期化 */
    int field[ROW][COL] = {}; // 碁盤(なし = 0; 1P = 1; 2P = 2;)
    int turn = 1; // どちらのターンか(1p = 1; 2p = 2;)

    printf("%d目並べゲームを開始します。(端末サイズを80x24にしてください)。\n", MOKU);

    while(1) {
	input(field, turn); // 碁石の置く場所を入力，判定など
	if(decision(field,turn) == 1) break; // もし，勝敗がついたなら，ループから抜ける
/* 指し手の変更 */
	if(turn == 1) {
	    turn = 2;
	}
	else {
	    turn = 1;
	}
    }
    return;
}

int main(void)
{
/* ここが全ての始まり */
    game();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 碁盤の縦横 */
#define ROW 12
#define COL 16

/* debug (関数名と任意のメッセージを表示します．printf()関数と同様の使い方) */
/*C99
#define DEBUG(...)  DEBUG_2(__VA_ARGS__, "")
#define DEBUG_2(fmt, ...)			\
 printf("%s(): "fmt"%s", __func__, __VA_ARGS__)
*/

//GNU Only
//#define DEBUG(fmt, ...)					\
// printf("%s(): "fmt, __func__, ## __VA_ARGS__)
 

char printGo(int num);
void printField(int open[][COL], int number[][COL],int field[][COL],int flag);
void bomb( int field[][COL], int doukasen);
int fieldCheck(int open[][COL], int row, int col);
void fieldChange(int open[][COL], int number[][COL], int row, int col);
int win(int field[][COL], int open[][COL]);

void Msg(int code);
int input(int field[][COL], int open[][COL], int number[][COL]);
void defNumber(int field[][COL], int number[][COL]);
void game();
int main(void);

char printGo(int num)
{
    char str[2]; // 一文字分の文字列
/* 碁盤のマスの数値を文字に変換します */
    switch(num) {
    case 0:
	return ' ';
    default:
	break;
    }
    sprintf(str, "%d", num); // 数値から文字列に変換
    return str[0];
}

void printField(int open[][COL], int number[][COL],int field[][COL],int flag)
{
/* 碁盤を表示します */
    int i, j; // 繰り返しのため
    printf("開いていない -> o, 周囲の爆弾数 -> 数字, フラグ -> f\n");

// 列番号の表示
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("%2d ", i+1);
    }
    printf("\n");

// 列番号区切りの表示
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("---");
    }
    printf("\n");

// フィールドの表示
    for(i = 0; i < ROW; i++) {
// 行番号の表示
	printf("%2d | ",i+1);

// マス目の表示
	for(j = 0; j < COL; j++) {
		if(field[i][j]== 1 && flag == 1){
			printf(" b ");
		continue;
		}
	    if(open[i][j] == -1) {
		    printf(" f ");
		continue;
	    }
	    else if(open[i][j] == 1) {
			printf(" %c ", printGo(number[i][j]));
	    }
	    else {
			printf(" o ");
	    }
	}

// 行番号の表示
	printf("| %2d\n",i+1);
    }

// 列番号区切りの表示
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("---");
    }
    printf("\n");

// 列番号の表示
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("%2d ", i+1);
    }
    printf("\n");

    return;
}

/* 爆弾位置を書き込みします（ランダムでやる） */
void bomb( int field[][COL],int doukasen)
{
    int i, j, count=0;

// シード値
    srand((unsigned)time(NULL));

    while(count < doukasen) {
    i = rand()%ROW;
    j = rand()%COL;
    if(field[i][j] == 1) continue;
    field[i][j] = 1;
    count++;
    }
/*
    field[0][4] = 1;
    field[1][3] = 1;
    field[3][9] = 1;
    field[6][8] = 1;
    field[9][0] = 1;
    field[7][5] = 1;
    field[3][8] = 1;
*/
    return;
}

int fieldCheck(int open[][COL], int row, int col)
{
/* 入力した指し手が不正な数値でないか確認します */

/* 入力値が範囲外でないか */
    if(row < 0 || ROW <= row) return -1;
    if(col < 0 || COL <= col) return -2;

/* 既に穴が開いていないか */
    if(open[row][col] > 0) return 1;
    return 0;
}

void fieldChange(int open[][COL], int number[][COL], int row, int col)
{
/* マインスイーパの配列に適切な穴を開けます *
 * クイックソートのような再帰的なやり方です *
 */

    /* 自分自身が穴なら終了 */
    if(open[row][col] == 1) return;
    else if(number[row][col] > 0) {
	open[row][col] = 1;
	return;
    }
    else open[row][col] = 1;

    /* 再帰！！！（ただし配列の範囲外にならないように） */
    if(row-1 >= 0) fieldChange(open, number, row-1, col);
    if(row+1 < ROW) fieldChange(open, number, row+1, col);
    if(col-1 >= 0) fieldChange(open, number, row, col-1);
    if(col+1 < COL) fieldChange(open, number, row, col+1);

    return;
}

int win(int field[][COL], int open[][COL])
{
    int i, j;
    for(i = 0; i < ROW; i++) {
	for(j = 0; j < COL; j++) {
/* 全ての要素に対して実行 */
/* 爆弾位置以外は穴が開いているか判定 */
	    if(field[i][j] != 1) {
		if(open[i][j] == 0) return 1;
		if(open[i][j] == -1) return 1;

	    }
	}
    }
    return 0;
}

void Msg(int code)
{
/* メッセージを表示します */
    if(code > 0) {
	printf("このマスはすでに開いているか、フラグです。選択しなおしてください。\n");
    }
    else if(code < 0) {
	printf("このマスは範囲外です。選択しなおしてください。\n");
    }
    else {
	printf("選択が完了しました\n");
    }
    return;
}

int input(int field[][COL], int open[][COL], int number[][COL])
{
/* 指し手の入力を受付け，穴をあけます */
    int row = 0; // ユーザー指定の位置
    int col = 0; // ユーザー指定の位置
    int mode; // モード保持
    int status = 0; // 入力値が不正かどうかの結果を保存するため

    while(1) {
	printField(open, number,field,0); // 碁盤の表示

	printf("モードを選択してください(入力後に Enter キーを押してください)\n");
	printf("フラグを立てる・消す : 1, 穴を開ける : 2\n");

/* とりあえず文字入力時の無限ループ回避 */
	if(scanf("%d", &mode) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n不正な値です．再入力してください．(r)\n\n");
	    continue;
	}

/* 異なる文字の対策 */
	if(!(mode == 1 || mode == 2)) {
	    printf("\n不正な値です．再入力してください．(mfo)\n\n");
	    continue;
	}

	printf("あなたのマス目を選択してください\n");
	printf("縦(入力後に Enter キーを押してください) : ");

/* とりあえず文字入力時の無限ループ回避 */
	if(scanf("%d", &row) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n不正な値です．再入力してください．(r)\n\n");
	    continue;
	}

	printf("横(入力後に Enter キーを押してください) : ");

/* とりあえず文字入力時の無限ループ回避 */
	if(scanf("%d", &col) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n不正な値です．再入力してください．(c)\n\n");
	    continue;
	}

/* 入力番号から配列番号へ変換 */
	row--;
	col--;

	status = fieldCheck(open, row, col); // 入力値のチェック
	Msg(status); // チェック結果のメッセージを表示
	if(status == 0) break; // 正常ならループを抜ける
    }
    if(mode == 2) {
	if(field[row][col] == 1) { // 敗北判定
	    printField(open, number,field,1); // 碁盤の表示
	    printf("you lose!\n");
	    return -1;
	}
	fieldChange(open, number, row, col); // フィールドに穴を開ける
	if(win(field, open) == 0) { // 勝利判定
	    printField(open, number,field,1); // 碁盤の表示
	    printf("you win!\n");
	    return 1;
	}
    }
    else if(mode == 1) {
	/* フラグが立っていないなら、フラグを立てる */
	if(open[row][col] == 0) open[row][col] = -1;

	/* フラグが立っているなら、フラグを消す */
	else if(open[row][col] == -1) open[row][col] = 0;
    }
    return 0;
}

/* マインスイーパの 1, 2, 3 のような数値の算出（コードがとても見にくい） */
void defNumber(int field[][COL], int number[][COL])
{
    int i, j, num;
    int iflug;
    int jflug;
    for(i = 0; i < ROW; i++) {
	for(j = 0; j < COL; j++) {
/* 全ての要素に対して実行 */
	    num = 0;

/* 配列の要素が端にきているかどうかの判定 */
	    if(i == 0) iflug = -1;
	    else if(i == ROW - 1) iflug = 1;
	    else iflug = 0;

	    if(j == 0) jflug = -1;
	    else if(j == COL -1) jflug = 1;
	    else jflug = 0;

/* 自分の周りに爆弾が何個あるか判定。見にくい */
	    if(iflug != -1 && jflug != -1  && field[i-1][j-1] == 1) num++;
	    if(jflug != -1 && field[i][j-1] == 1) num++;
	    if(iflug != 1 && jflug != -1 && field[i+1][j-1] == 1) num++;
	    if(iflug != -1 && jflug != 1 && field[i-1][j+1] == 1) num++;
	    if(jflug != 1 && field[i][j+1] == 1) num++;
	    if(iflug != 1 && jflug != 1 && field[i+1][j+1] == 1) num++;
	    if(iflug != -1 && field[i-1][j] == 1) num++;
	    if(iflug != 1 && field[i+1][j] == 1) num++;

/* 自分の位置が爆弾なら 0 とし、そうでなければ爆弾数を代入 */
	    if(field[i][j] == 0) number[i][j] = num;
	    else number[i][j] = 0;
	}
}
    return;
}

void game()
{
/* 指し手を変更したり，入力させたり，判定をしたり... */

/* 初期化 */
    int field[ROW][COL] = {}; // フィールド(何もない = 0; 爆弾位置 = 1;)
    int open[ROW][COL] = {}; // マスがオープンされているか(フラグを立てた = -1, されてない = 0; されてる = 1;)
    int number[ROW][COL] = {}; // マスに表示する数値(爆弾 = -1, 何も表示しない = 0; 表示する = 1 以上;)
	int doukasen;
    int status = 0;
	printf("爆弾の数を決めてください\n");
	scanf("%d",&doukasen);
    bomb(field,doukasen); // 爆弾位置を決定
    defNumber(field, number); // 爆弾位置に応じて、1, 2, 3 みたいな数値を算出

    printf("マインスイーパを開始します。(端末サイズを80x24にしてください)。\n");

    while(1) {
	status = input(field, open, number); // 碁石の置く場所を入力，判定など
	if(status != 0) break; // もし，勝敗がついたなら，ループから抜ける
    }
	scanf("%d",&status);
    return;
}

int main(void)
{
/* ここが全ての始まり */
    game();

    return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*改善点:同じ人がプレイしても名前を変えなきゃいけない
特定行の特定の部分を書き換える必要がある
ファイル関係で駄目だった場合mainのio()とループ後のファイル操作関係を
コメントアウトしてください
*/


char io() {
	char str[9];
	char st[10];
	char get[500];
	char* end;
	int hant, i = 0, l = 0;
	char* p;
	char key = NULL;
	FILE * save;

	while (1) {
		puts("名前を8文字以内で入力してください");
		*str = '\0';
		fgets(str, sizeof(8), stdin);
		p = strchr(str, '\n');
		if (p != NULL) { *p = '\0'; }

		while (str[i] != '\0') {
			l = _ismbblead(str[i]);
			i++;
			if (l != 0)break;
		}

		if (l != 0) {
			puts("全角文字が含まれています。半角で入力してください");
			continue;
		}

		sprintf(st, "%s:", str);
		if ((save = fopen("save.txt", "r")) == NULL) {
			save = fopen("save.txt", "w");
			fprintf(save, "%s:", str);
			break;
		}
		else {
			save = fopen("save.txt", "a+");
			end = fgets(get, sizeof(get), save);
			while (end != NULL) {
				end = fgets(get, sizeof(get), save);
				if (_mbsstr(get, st) == NULL) {
					hant = 0;
				}
				else {
					hant = 1;
					break;
				}
			}
			if (hant == 0) {
				fprintf(save, "\n%s:", str);
				break;
			}
			else {
				puts("同じ名前の人がいます。もう一度入力してください\n");
			}
		}
	}
	fclose(save);

	printf("名前は%sです。Enterを押してね！\n", str);

	scanf("%c", &key);
	if (key != NULL) {
		system("cls");
		key = NULL;
	}
	return 0;
}


int rule() {
	char key = NULL;
	puts("石取りゲーム!!\n");
	puts("ルールの説明");
	puts("まず石の数を設定します");
	puts("あなたとコンピュータは1~3個までの石を順番に取れます");
	puts("最初に設定した石の数を取ったほうが負けです");
	puts("先攻後攻はランダムです");
	puts("理解したらEnterキーを押してね!");
	scanf("%c", &key);
	if (key != NULL) {
		system("cls");
		key = NULL;
	}
	return 0;
}

int RockSet() {

	int set = 0;

	while (1) {
		puts("石の数を設定します。");
		puts("12個(1)、24個(2)、32個(3)12~32のランダム(4)の中から選び、\n選んだら()の中の数字を入力してください");

		if (scanf("%d", &set) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("正しい値を入力してください");
			continue;
		}

		if (set == 1) {
			puts("\n石の数は12個に設定されました\n");
			set = 12;
			break;
		}
		else if (set == 2) {
			puts("\n石の数は24個に設定されました\n");
			set = 24;
			break;
		}
		else if (set == 3) {
			puts("\n石の数は32個に設定されました\n");
			set = 32;
			break;
		}
		else if (set == 4) {
			srand((unsigned)time(NULL));
			set = rand() % 21 + 12;
			printf("\n石の数は%d個に設定されました\n", set);
			break;
		}
		else {
			puts("正しい値を入力してください");
			RockSet();
			break;
		}
	}
	return set;
}

int first() {
	int rd;//Random

	srand((unsigned)time(NULL));
	rd = rand() % 2;
	if (rd == 0) {
		puts("あなたが先攻です");
	}
	else {
		puts("先攻はCPUです");
	}
	return rd;
}

int cpu(int rock) {
	int del, win;

	win = rock % 4;
	puts("CPUのターン");
	if (rock == 1 || rock == 2 || win == 2) {
		del = 1;

	}
	else if (rock == 3 || win == 3) {
		del = 2;
	}
	else if (rock == 4) {
		del = 3;
	}
	else {
		srand((unsigned)time(NULL));
		del = rand() % 3 + 1;
	}
	printf("CPUは%d個石をとりました。\n", del);
	return del;
}

int user(int rock) {
	int del;

	puts("あなたのターン");
	while (1) {
		if (rock == 1) {
			puts("残りの石は1個なので自動で取りました。");
			del = 1;
			break;
		}
		else if (rock == 2) {
			puts("何個石をとる?1~2個から選んでね");
			if (scanf("%d", &del) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("正しい値を入力してください");
				continue;
			}
			if (del == 1) {
				puts("\nあなたは石を1個取りました");
				break;
			}
			else if (del == 2) {
				puts("\nあなたは石を2個取りました");
				break;
			}
			else {
				puts("正しい値を入力してください");
			}
		}
		else {
			puts("何個石をとる?1~3個から選んでね");
			if (scanf("%d", &del) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("正しい値を入力してください");
				continue;
			}

			if (del == 1) {
				puts("\nあなたは石を1個取りました");
				break;
			}
			else if (del == 2) {
				puts("\nあなたは石を2個取りました");
				break;
			}
			else if (del == 3) {
				puts("\nあなたは石を3個取りました");
				break;
			}
			else {
				puts("正しい値を入力してください");
			}
		}
	}

	return del;
}

int game() {
	int rock = RockSet();
	int del = 0, rem = 0;
	int sk = first();

	while (rock != 0) {
		if (sk == 0) {
			del = user(rock);
			rem = rock - del;
			rock = rem;
			printf("残りの石は%dです\n\n", rock);
			if (rock == 0) {
				puts("最後の石を取ったのはあなたです。CPUの勝ち");
			}
			sk = 1;
			continue;
		}
		else if (sk == 1) {
			del = cpu(rock);
			rem = rock - del;
			rock = rem;
			printf("残りの石は%dです\n\n", rock);
			if (rock == 0) {
				puts("最後の石を取ったのはCPUです。あなたの勝ち");
			}
			sk = 0;
			continue;
		}
	}
	return sk;
}

int end() {
	int sten;//StartEnd
	while (1) {
		puts("\nゲームをまだ続けますか?");
		puts("続けるなら1をやめるなら2を入力してください");
		if (scanf("%d", &sten) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("正しい値を入力してください");
			continue;
		}
		if (sten == 1 || sten == 2)break;
		else {
			puts("正しい値を入力してください");
		}
	}
	return sten;
}

int main(void) {
	clock_t start, en;
	start = clock();
	int sten = 1, i = 0, l = 0, win = 0;
	FILE * save;

	rule();
	io();

	while (sten == 1) {
		i++;
		win = game();
		sten = end();
	}
	if (win == 0)l++;
	save = fopen("save.txt", "a");
	fprintf(save, "%d:", i);
	fprintf(save, "%d:", l);
	en = clock();
	fprintf(save, "%d[ms]:", en - start);
	fclose(save);
	//name:回数:勝利回数:時間
	return 0;
}


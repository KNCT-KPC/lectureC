#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int usernum[3], cpu[3], sk, i, tarn, cpucall[3], usrcall[3], cpumati[3] = {0};


	for (i = 1;i <= 3;i++) {
		srand((unsigned)time(NULL));
		if (i == 1) {
			cpu[0] = rand() % 10 + 1;
			if (cpu[0] >= 10)i--;
		}else if (i == 2) {
			cpu[1] = rand() % 10 + 1;
			if (cpu[1] == cpu[0] || cpu[1] >= 10)i--;
		}else if (i == 3) {
			cpu[2] = rand() % 10 + 1;
			if (cpu[2] == cpu[0] || cpu[2] == cpu[1] || cpu[2] >= 10)i--;
		}
	}

	//printf("CPUの設定した値は%d%d%dです\n\n", cpu[0], cpu[1], cpu[2]);
	i = 0;

	while (1) {
		puts("1の位の数を入力してください");
		if (scanf("%d", &usernum[0]) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("正しい値を入力してください");
			continue;
		}
		puts("10の位の数を入力してください");
		if (scanf("%d", &usernum[1]) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("正しい値を入力してください");
			continue;
		}
		puts("100の位の数を入力してください");
		if (scanf("%d", &usernum[2]) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("正しい値を入力してください");
			continue;
		}
		if (usernum[0] >= 10 || usernum[1] >= 10 || usernum[2] >= 10) {
			puts("値が9以上です\n正しい値を入力してください");
			continue;
		}
		else {
			printf("あなたの設定した値は%d%d%dです\n", usernum[0], usernum[1], usernum[2]);
			break;
		}
	}

	srand((unsigned)time(NULL));
	sk = rand() % 2;
	if (sk == 0) {
		puts("あなたが先攻です");
		tarn = 0;
		sk = NULL;
	}
	else {
		puts("先攻はCPUです");
		tarn = 1;
		sk = NULL;
	}

	while (1) {
		if (tarn == 0) {
			puts("\nCPUの1の位はなんだと思いますか?");
			if (scanf("%d", &usrcall[0]) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("正しい値を入力してください");
				continue;
			}
			puts("CPUの10の位はなんだと思いますか?");
			if (scanf("%d", &usrcall[1]) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("正しい値を入力してください");
				continue;
			}
			puts("CPUの100の位はなんだと思いますか?");
			if (scanf("%d", &usrcall[2]) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("正しい値を入力してください");
				continue;
			}
			if (usrcall[0] >= 10 || usrcall[1] >= 10 || usrcall[2] >= 10) {
				puts("値が9以上です\n正しい値を入力してください");
				continue;
			}
			else {
				printf("あなたのコールは%d%d%dです", usrcall[0], usrcall[1], usrcall[2]);
			}
			if (usrcall[0] == cpu[0] && usrcall[1] == cpu[1] && usrcall[2] == cpu[2]) {
				puts("3EAT");
				puts("あなたのコールした数とCPUの設定した\n値も位も数もすべて一致しました");
				puts("あなたの勝ちです");
				break;
			}
			else if ((usrcall[0] == cpu[0] && usrcall[1] == cpu[1]) || (usrcall[1] == cpu[1] && usrcall[2] == cpu[2]) || (usrcall[0] == cpu[0] && usrcall[2] == cpu[2])) {
				puts("2EAT");
				puts("あなたのコールした数とCPUの設定した\n値と位との一致が2つです。\n");
			}
			else if ((usrcall[0] == cpu[0] && (usrcall[1] == cpu[2] && usrcall[2] == cpu[1])) || usrcall[1] == cpu[1] && (usrcall[0] == cpu[2] && usrcall[2] == cpu[0]) || usrcall[2] == cpu[2] && (usrcall[0] == cpu[1] && usrcall[1] == cpu[0])) {
				puts("1EAT2BITE");
				puts("あなたのコールした数とCPUの設定した\n値と位が完全に一致しているものが1つ");
				puts("あなたのコールした数とCPUの設定した\n値だけ一致しており位が違うものが2つあります/n");
			}
			else if ((usrcall[0] == cpu[0] && (usrcall[1] == cpu[2] || usrcall[2] == cpu[1])) || usrcall[1] == cpu[1] && (usrcall[0] == cpu[2] || usrcall[2] == cpu[0]) || usrcall[2] == cpu[2] && (usrcall[0] == cpu[1] || usrcall[1] == cpu[0])) {
				puts("1EAT1BITE");
				puts("あなたのコールした数とCPUの設定した\n値と位が完全に一致しているものが1つ");
				puts("あなたのコールした数とCPUの設定した\n値だけ一致しており位が違うものが1つあります\n");
			}
			else if (usrcall[0] == cpu[0] || usrcall[1] == cpu[1] || usrcall[2] == cpu[2]) {
				puts("1EAT");
				puts("あなたのコールした数とCPUの設定した\n値と位との一致が1つです。\n");
			}
			else if ((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) && (usrcall[1] == cpu[0] || usrcall[1] == cpu[2]) && (usrcall[2] == cpu[0] || usrcall[2] == cpu[1])) {
				puts("3BITE");
				puts("あなたのコールした数とCPUの設定した値はすべて一致しています。\n位が違います\n");
			}
			else if (((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) && (usrcall[1] == cpu[0] || usrcall[1] == cpu[2])) || ((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) && (usrcall[2] == cpu[0] || usrcall[2] == cpu[1])) || ((usrcall[1] == cpu[0] || usrcall[1] == cpu[2]) && (usrcall[2] == cpu[0] || usrcall[2] == cpu[1]))) {
				puts("2BITE");
				puts("あなたのコールした数とCPUの設定した値が一致していて\n位が違うものが2つあります\n");
			}
			else if ((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) || (usrcall[1] == cpu[0] || usrcall[1] == cpu[2]) || (usrcall[2] == cpu[0] || usrcall[2] == cpu[1])) {
				puts("1BITE");
				puts("あなたのコールした数とCPUの設定した値が一致していて\n位が違うものが1つあります\n");
			}
			else {
				puts("一致していません\n");
			}
			tarn = 1;
		}else if (tarn == 1) {
			for (i = 1;i <= 3;i++) {
				srand((unsigned)time(NULL));
				if (i == 1 && cpumati[0] == 0) {
					cpucall[0] = rand() % 10 + 1;
					if (cpucall[0] >= 10)i--;
				}
				else if (i == 2 && cpumati[1] == 0) {
					cpucall[1] = rand() % 10 + 1;
					if (cpucall[1] >= 10)i--;
				}
				else if (i == 3 && cpumati[2] == 0) {
					cpucall[2] = rand() % 10 + 1;
					if (cpucall[2] >= 10)i--;
				}
			}
			printf("CPUのコールは%d%d%dです\n", cpucall[0], cpucall[1], cpucall[2]);

			if (cpucall[0] == usernum[0] && cpucall[1] == usernum[1] && cpucall[2] == usernum[2]) {
				puts("3EAT");
				puts("CPUのコールした数とあなたの設定した値の位も数もすべて一致しました");
				puts("CPUの勝ちです");
				break;
			}else if (cpucall[0] == usernum[0] && cpucall[1] == usernum[1]) {//2EATpt1
				puts("2EAT");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが2つ、\n値も位も違うものが1つあります");
				cpumati[0] = cpucall[0];
				cpumati[1] = cpucall[1];
			}else if (cpucall[0] == usernum[0] && cpucall[2] == usernum[3]) {//2EATpt2
				puts("2EAT");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが2つ、\n値も位も違うものが1つあります");
				cpumati[0] = cpucall[0];
				cpumati[2] = cpucall[2];
			}else if (cpucall[1] == usernum[1] && cpucall[2] == usernum[3]) {//2EATpt3
				puts("2EAT");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが2つ、\n値も位も違うものが1つあります");
				cpumati[1] = cpucall[1];
				cpumati[2] = cpucall[2];
			}else if (cpucall[0] == usernum[0] && cpucall[1] == usernum[2] && cpucall[2] == usernum[1]) {//1EAT2BITEpt1
				puts("1EAT2BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が2つあります");
				cpumati[0] = cpucall[0];
				cpumati[1] = cpucall[2];
				cpumati[2] = cpucall[1];
				cpucall[1] = cpumati[1];
				cpucall[2] = cpumati[2];
			}else if (cpucall[1] == usernum[1] && cpucall[0] == usernum[2] && cpucall[2] == usernum[0]) {//1EAT2BITEpt2
				puts("1EAT2BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が2つあります");
				cpumati[1] = cpucall[1];
				cpumati[0] = cpucall[2];
				cpumati[2] = cpucall[0];
				cpucall[0] = cpumati[0];
				cpucall[2] = cpumati[2];
			}else if (cpucall[2] == usernum[2] && cpucall[0] == usernum[1] && cpucall[1] == usernum[0]) {//1EAT2BITEpt3
				puts("1EAT2BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が2つあります");
				cpumati[2] = cpucall[2];
				cpumati[0] = cpucall[1];
				cpumati[1] = cpucall[0];
				cpucall[0] = cpumati[0];
				cpucall[1] = cpumati[1];
			}else if (cpucall[0] == usernum[0] && cpucall[1] == usernum[2]) {//1EAT1BITEpt1
				puts("1EAT1BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が1つあります");
				cpumati[0] = cpucall[0];
				cpumati[2] = cpucall[1];
				cpucall[2] = cpumati[2];
			}else if (cpucall[0] == usernum[0] && cpucall[2] == usernum[1]) {//1EAT1BITEpt2
				puts("1EAT1BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が1つあります");
				cpumati[0] = cpucall[0];
				cpumati[1] = cpucall[2];
				cpucall[1] = cpumati[1];
			}else if (cpucall[1] == usernum[1] && cpucall[0] == usernum[1]) {//1EAT1BITEpt3
				puts("1EAT1BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が1つあります");
				cpumati[1] = cpucall[1];
				cpumati[1] = cpucall[0];
				cpucall[1] = cpumati[1];
			}else if (cpucall[1] == usernum[1] && cpucall[1] == usernum[0]) {//1EAT1BITEpt4
				puts("1EAT1BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が1つあります");
				cpumati[1] = cpucall[1];
				cpumati[0] = cpucall[1];
				cpucall[0] = cpumati[0];
			}else if (cpucall[2] == usernum[2] && cpucall[0] == usernum[1]) {//1EAT1BITEpt5
				puts("1EAT1BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が1つあります");
				cpumati[2] = cpucall[2];
				cpumati[1] = cpucall[0];
				cpucall[1] = cpumati[1];
			}else if (cpucall[2] == usernum[2] && cpucall[1] == usernum[0]) {//1EAT1BITEpt6
				puts("1EAT1BITE");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n位が違う値が1つあります");
				cpumati[2] = cpucall[2];
				cpumati[0] = cpucall[1];
				cpucall[0] = cpumati[0];
			}else if (cpucall[0] == usernum[0]) {//1EATpt1
				puts("1EAT");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n値も位も違うものが2つあります");
				cpumati[0] = cpucall[0];
			}else if (cpucall[1] == usernum[1]) {//1EATpt2
				puts("1EAT");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n値も位も違うものが2つあります");
				cpumati[1] = cpucall[1];
			}else if (cpucall[2] == usernum[2]) {//1EATpt3
				puts("1EAT");
				puts("CPUのコールした数とあなたの設定した値と位が一致しているものが1つ、\n値も位も違うものが2つあります");
				cpumati[2] = cpucall[2];
			}
			else {
				puts("CPUのコールとあなたの設定した値は一致していません");
			}
			tarn = 0;
		}
	}

	return 0;
}


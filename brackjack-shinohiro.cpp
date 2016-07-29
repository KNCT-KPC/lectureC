#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int P = 0; /* P=player */
	int C = 0; /* C=com */
	int count = 0;
	int lost = 0;
	int win = 0;
	int r; /* r=乱数 */
	int n; /* n=乱数2 */
	char s = 0;

	srand((unsigned)time(NULL));

	printf("Ret's stert brack jack\n");

	printf("ルールは簡単、どれだけ得点を21にできるかです。\n");

	printf("最初のカードは自動的に引かれます。\n");

	printf("あなたの番です\n");

	while (P >= 0) {
		r = rand() % 13 + 1;
		P = P + r;
		count = count + 1;

		printf("あなたの引いたカードの得点は%dです\n", r);

		printf("あなたの %d 回目の得点は %d です\n", count, P);

		if (P > 22) {
			printf("%d\n22を越えました\nYouLost...\n", P);
			lost = 1;
			break;
		}
		else if (P == 22) {
			break;
		}

		printf("もう一枚引きますか？\ny/n\n");
		char a, str[20];
		scanf("%s", str);
		a = str[0];
		if (a == 'n') {
			break;
		}
	}

	if (lost != 1) {

		printf("\nあなたの最終得点です\n%d\n", P);


		count = 0;

		printf("\n\nあいての番です\n");

		while (C >= 0) {
			r = rand() % 13 + 1;
			C = C + r;
			count = count + 1;

			printf("\n相手の %d 回目の得点は %d です\n", count, C);

			if (C > 22) {
				printf("\n22を越えました\nYouWin!\n");
				win = 1;
				break;
			}

			if (9 <= C || C <= 13) {
				n = rand() % 10 + 1;
				if (n == 1)
					break;
			}
			else if (14 <= C || C <= 16) {
				n = rand() % 5 + 1;
				if (n == 1)
					break;
			}
			else if (17 <= C || C <= 19) {
				n = rand() % 2 + 1;
				if (n == 1)
					break;
			}
			else if (20 <= C || C <= 21) {
				n = rand() % 10 + 1;
				if (n != 1)
					break;
			}
			else if (C == 22) {
				break;
			}
		}

		if (win != 1) {

			printf("あいての最終得点です\n%d\n\n\n\n", C);

			if (P > C) {
				printf("%d VS %d !\nYouWin!\n", P, C);
			}
			else if (P < C) {
				printf("%d VS %d !\nYouLost...\n", P, C);
			}
			else {
				printf("%d VS %d !\nDraw\n", P, C);
			}

		}
	}
	scanf("%c",&s);
	scanf("%c",&r);

	return 0;
}
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
	int r; /* r=���� */
	int n; /* n=����2 */
	char s = 0;

	srand((unsigned)time(NULL));

	printf("Ret's stert brack jack\n");

	printf("���[���͊ȒP�A�ǂꂾ�����_��21�ɂł��邩�ł��B\n");

	printf("�ŏ��̃J�[�h�͎����I�Ɉ�����܂��B\n");

	printf("���Ȃ��̔Ԃł�\n");

	while (P >= 0) {
		r = rand() % 13 + 1;
		P = P + r;
		count = count + 1;

		printf("���Ȃ��̈������J�[�h�̓��_��%d�ł�\n", r);

		printf("���Ȃ��� %d ��ڂ̓��_�� %d �ł�\n", count, P);

		if (P > 22) {
			printf("%d\n22���z���܂���\nYouLost...\n", P);
			lost = 1;
			break;
		}
		else if (P == 22) {
			break;
		}

		printf("�����ꖇ�����܂����H\ny/n\n");
		char a, str[20];
		scanf("%s", str);
		a = str[0];
		if (a == 'n') {
			break;
		}
	}

	if (lost != 1) {

		printf("\n���Ȃ��̍ŏI���_�ł�\n%d\n", P);


		count = 0;

		printf("\n\n�����Ă̔Ԃł�\n");

		while (C >= 0) {
			r = rand() % 13 + 1;
			C = C + r;
			count = count + 1;

			printf("\n����� %d ��ڂ̓��_�� %d �ł�\n", count, C);

			if (C > 22) {
				printf("\n22���z���܂���\nYouWin!\n");
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

			printf("�����Ă̍ŏI���_�ł�\n%d\n\n\n\n", C);

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
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

	//printf("CPU�̐ݒ肵���l��%d%d%d�ł�\n\n", cpu[0], cpu[1], cpu[2]);
	i = 0;

	while (1) {
		puts("1�̈ʂ̐�����͂��Ă�������");
		if (scanf("%d", &usernum[0]) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("�������l����͂��Ă�������");
			continue;
		}
		puts("10�̈ʂ̐�����͂��Ă�������");
		if (scanf("%d", &usernum[1]) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("�������l����͂��Ă�������");
			continue;
		}
		puts("100�̈ʂ̐�����͂��Ă�������");
		if (scanf("%d", &usernum[2]) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("�������l����͂��Ă�������");
			continue;
		}
		if (usernum[0] >= 10 || usernum[1] >= 10 || usernum[2] >= 10) {
			puts("�l��9�ȏ�ł�\n�������l����͂��Ă�������");
			continue;
		}
		else {
			printf("���Ȃ��̐ݒ肵���l��%d%d%d�ł�\n", usernum[0], usernum[1], usernum[2]);
			break;
		}
	}

	srand((unsigned)time(NULL));
	sk = rand() % 2;
	if (sk == 0) {
		puts("���Ȃ�����U�ł�");
		tarn = 0;
		sk = NULL;
	}
	else {
		puts("��U��CPU�ł�");
		tarn = 1;
		sk = NULL;
	}

	while (1) {
		if (tarn == 0) {
			puts("\nCPU��1�̈ʂ͂Ȃ񂾂Ǝv���܂���?");
			if (scanf("%d", &usrcall[0]) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("�������l����͂��Ă�������");
				continue;
			}
			puts("CPU��10�̈ʂ͂Ȃ񂾂Ǝv���܂���?");
			if (scanf("%d", &usrcall[1]) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("�������l����͂��Ă�������");
				continue;
			}
			puts("CPU��100�̈ʂ͂Ȃ񂾂Ǝv���܂���?");
			if (scanf("%d", &usrcall[2]) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("�������l����͂��Ă�������");
				continue;
			}
			if (usrcall[0] >= 10 || usrcall[1] >= 10 || usrcall[2] >= 10) {
				puts("�l��9�ȏ�ł�\n�������l����͂��Ă�������");
				continue;
			}
			else {
				printf("���Ȃ��̃R�[����%d%d%d�ł�", usrcall[0], usrcall[1], usrcall[2]);
			}
			if (usrcall[0] == cpu[0] && usrcall[1] == cpu[1] && usrcall[2] == cpu[2]) {
				puts("3EAT");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l���ʂ��������ׂĈ�v���܂���");
				puts("���Ȃ��̏����ł�");
				break;
			}
			else if ((usrcall[0] == cpu[0] && usrcall[1] == cpu[1]) || (usrcall[1] == cpu[1] && usrcall[2] == cpu[2]) || (usrcall[0] == cpu[0] && usrcall[2] == cpu[2])) {
				puts("2EAT");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l�ƈʂƂ̈�v��2�ł��B\n");
			}
			else if ((usrcall[0] == cpu[0] && (usrcall[1] == cpu[2] && usrcall[2] == cpu[1])) || usrcall[1] == cpu[1] && (usrcall[0] == cpu[2] && usrcall[2] == cpu[0]) || usrcall[2] == cpu[2] && (usrcall[0] == cpu[1] && usrcall[1] == cpu[0])) {
				puts("1EAT2BITE");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l�ƈʂ����S�Ɉ�v���Ă�����̂�1��");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l������v���Ă���ʂ��Ⴄ���̂�2����܂�/n");
			}
			else if ((usrcall[0] == cpu[0] && (usrcall[1] == cpu[2] || usrcall[2] == cpu[1])) || usrcall[1] == cpu[1] && (usrcall[0] == cpu[2] || usrcall[2] == cpu[0]) || usrcall[2] == cpu[2] && (usrcall[0] == cpu[1] || usrcall[1] == cpu[0])) {
				puts("1EAT1BITE");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l�ƈʂ����S�Ɉ�v���Ă�����̂�1��");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l������v���Ă���ʂ��Ⴄ���̂�1����܂�\n");
			}
			else if (usrcall[0] == cpu[0] || usrcall[1] == cpu[1] || usrcall[2] == cpu[2]) {
				puts("1EAT");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵��\n�l�ƈʂƂ̈�v��1�ł��B\n");
			}
			else if ((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) && (usrcall[1] == cpu[0] || usrcall[1] == cpu[2]) && (usrcall[2] == cpu[0] || usrcall[2] == cpu[1])) {
				puts("3BITE");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵���l�͂��ׂĈ�v���Ă��܂��B\n�ʂ��Ⴂ�܂�\n");
			}
			else if (((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) && (usrcall[1] == cpu[0] || usrcall[1] == cpu[2])) || ((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) && (usrcall[2] == cpu[0] || usrcall[2] == cpu[1])) || ((usrcall[1] == cpu[0] || usrcall[1] == cpu[2]) && (usrcall[2] == cpu[0] || usrcall[2] == cpu[1]))) {
				puts("2BITE");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵���l����v���Ă���\n�ʂ��Ⴄ���̂�2����܂�\n");
			}
			else if ((usrcall[0] == cpu[1] || usrcall[0] == cpu[2]) || (usrcall[1] == cpu[0] || usrcall[1] == cpu[2]) || (usrcall[2] == cpu[0] || usrcall[2] == cpu[1])) {
				puts("1BITE");
				puts("���Ȃ��̃R�[����������CPU�̐ݒ肵���l����v���Ă���\n�ʂ��Ⴄ���̂�1����܂�\n");
			}
			else {
				puts("��v���Ă��܂���\n");
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
			printf("CPU�̃R�[����%d%d%d�ł�\n", cpucall[0], cpucall[1], cpucall[2]);

			if (cpucall[0] == usernum[0] && cpucall[1] == usernum[1] && cpucall[2] == usernum[2]) {
				puts("3EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�̈ʂ��������ׂĈ�v���܂���");
				puts("CPU�̏����ł�");
				break;
			}else if (cpucall[0] == usernum[0] && cpucall[1] == usernum[1]) {//2EATpt1
				puts("2EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�2�A\n�l���ʂ��Ⴄ���̂�1����܂�");
				cpumati[0] = cpucall[0];
				cpumati[1] = cpucall[1];
			}else if (cpucall[0] == usernum[0] && cpucall[2] == usernum[3]) {//2EATpt2
				puts("2EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�2�A\n�l���ʂ��Ⴄ���̂�1����܂�");
				cpumati[0] = cpucall[0];
				cpumati[2] = cpucall[2];
			}else if (cpucall[1] == usernum[1] && cpucall[2] == usernum[3]) {//2EATpt3
				puts("2EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�2�A\n�l���ʂ��Ⴄ���̂�1����܂�");
				cpumati[1] = cpucall[1];
				cpumati[2] = cpucall[2];
			}else if (cpucall[0] == usernum[0] && cpucall[1] == usernum[2] && cpucall[2] == usernum[1]) {//1EAT2BITEpt1
				puts("1EAT2BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��2����܂�");
				cpumati[0] = cpucall[0];
				cpumati[1] = cpucall[2];
				cpumati[2] = cpucall[1];
				cpucall[1] = cpumati[1];
				cpucall[2] = cpumati[2];
			}else if (cpucall[1] == usernum[1] && cpucall[0] == usernum[2] && cpucall[2] == usernum[0]) {//1EAT2BITEpt2
				puts("1EAT2BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��2����܂�");
				cpumati[1] = cpucall[1];
				cpumati[0] = cpucall[2];
				cpumati[2] = cpucall[0];
				cpucall[0] = cpumati[0];
				cpucall[2] = cpumati[2];
			}else if (cpucall[2] == usernum[2] && cpucall[0] == usernum[1] && cpucall[1] == usernum[0]) {//1EAT2BITEpt3
				puts("1EAT2BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��2����܂�");
				cpumati[2] = cpucall[2];
				cpumati[0] = cpucall[1];
				cpumati[1] = cpucall[0];
				cpucall[0] = cpumati[0];
				cpucall[1] = cpumati[1];
			}else if (cpucall[0] == usernum[0] && cpucall[1] == usernum[2]) {//1EAT1BITEpt1
				puts("1EAT1BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��1����܂�");
				cpumati[0] = cpucall[0];
				cpumati[2] = cpucall[1];
				cpucall[2] = cpumati[2];
			}else if (cpucall[0] == usernum[0] && cpucall[2] == usernum[1]) {//1EAT1BITEpt2
				puts("1EAT1BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��1����܂�");
				cpumati[0] = cpucall[0];
				cpumati[1] = cpucall[2];
				cpucall[1] = cpumati[1];
			}else if (cpucall[1] == usernum[1] && cpucall[0] == usernum[1]) {//1EAT1BITEpt3
				puts("1EAT1BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��1����܂�");
				cpumati[1] = cpucall[1];
				cpumati[1] = cpucall[0];
				cpucall[1] = cpumati[1];
			}else if (cpucall[1] == usernum[1] && cpucall[1] == usernum[0]) {//1EAT1BITEpt4
				puts("1EAT1BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��1����܂�");
				cpumati[1] = cpucall[1];
				cpumati[0] = cpucall[1];
				cpucall[0] = cpumati[0];
			}else if (cpucall[2] == usernum[2] && cpucall[0] == usernum[1]) {//1EAT1BITEpt5
				puts("1EAT1BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��1����܂�");
				cpumati[2] = cpucall[2];
				cpumati[1] = cpucall[0];
				cpucall[1] = cpumati[1];
			}else if (cpucall[2] == usernum[2] && cpucall[1] == usernum[0]) {//1EAT1BITEpt6
				puts("1EAT1BITE");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�ʂ��Ⴄ�l��1����܂�");
				cpumati[2] = cpucall[2];
				cpumati[0] = cpucall[1];
				cpucall[0] = cpumati[0];
			}else if (cpucall[0] == usernum[0]) {//1EATpt1
				puts("1EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�l���ʂ��Ⴄ���̂�2����܂�");
				cpumati[0] = cpucall[0];
			}else if (cpucall[1] == usernum[1]) {//1EATpt2
				puts("1EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�l���ʂ��Ⴄ���̂�2����܂�");
				cpumati[1] = cpucall[1];
			}else if (cpucall[2] == usernum[2]) {//1EATpt3
				puts("1EAT");
				puts("CPU�̃R�[���������Ƃ��Ȃ��̐ݒ肵���l�ƈʂ���v���Ă�����̂�1�A\n�l���ʂ��Ⴄ���̂�2����܂�");
				cpumati[2] = cpucall[2];
			}
			else {
				puts("CPU�̃R�[���Ƃ��Ȃ��̐ݒ肵���l�͈�v���Ă��܂���");
			}
			tarn = 0;
		}
	}

	return 0;
}


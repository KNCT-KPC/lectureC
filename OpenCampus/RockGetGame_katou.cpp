#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*���P�_:�����l���v���C���Ă����O��ς��Ȃ��Ⴂ���Ȃ�
����s�̓���̕���������������K�v������
�t�@�C���֌W�őʖڂ������ꍇmain��io()�ƃ��[�v��̃t�@�C������֌W��
�R�����g�A�E�g���Ă�������
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
		puts("���O��8�����ȓ��œ��͂��Ă�������");
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
			puts("�S�p�������܂܂�Ă��܂��B���p�œ��͂��Ă�������");
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
				puts("�������O�̐l�����܂��B������x���͂��Ă�������\n");
			}
		}
	}
	fclose(save);

	printf("���O��%s�ł��BEnter�������ĂˁI\n", str);

	scanf("%c", &key);
	if (key != NULL) {
		system("cls");
		key = NULL;
	}
	return 0;
}


int rule() {
	char key = NULL;
	puts("�Ύ��Q�[��!!\n");
	puts("���[���̐���");
	puts("�܂��΂̐���ݒ肵�܂�");
	puts("���Ȃ��ƃR���s���[�^��1~3�܂ł̐΂����ԂɎ��܂�");
	puts("�ŏ��ɐݒ肵���΂̐���������ق��������ł�");
	puts("��U��U�̓����_���ł�");
	puts("����������Enter�L�[�������Ă�!");
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
		puts("�΂̐���ݒ肵�܂��B");
		puts("12��(1)�A24��(2)�A32��(3)12~32�̃����_��(4)�̒�����I�сA\n�I�񂾂�()�̒��̐�������͂��Ă�������");

		if (scanf("%d", &set) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("�������l����͂��Ă�������");
			continue;
		}

		if (set == 1) {
			puts("\n�΂̐���12�ɐݒ肳��܂���\n");
			set = 12;
			break;
		}
		else if (set == 2) {
			puts("\n�΂̐���24�ɐݒ肳��܂���\n");
			set = 24;
			break;
		}
		else if (set == 3) {
			puts("\n�΂̐���32�ɐݒ肳��܂���\n");
			set = 32;
			break;
		}
		else if (set == 4) {
			srand((unsigned)time(NULL));
			set = rand() % 21 + 12;
			printf("\n�΂̐���%d�ɐݒ肳��܂���\n", set);
			break;
		}
		else {
			puts("�������l����͂��Ă�������");
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
		puts("���Ȃ�����U�ł�");
	}
	else {
		puts("��U��CPU�ł�");
	}
	return rd;
}

int cpu(int rock) {
	int del, win;

	win = rock % 4;
	puts("CPU�̃^�[��");
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
	printf("CPU��%d�΂��Ƃ�܂����B\n", del);
	return del;
}

int user(int rock) {
	int del;

	puts("���Ȃ��̃^�[��");
	while (1) {
		if (rock == 1) {
			puts("�c��̐΂�1�Ȃ̂Ŏ����Ŏ��܂����B");
			del = 1;
			break;
		}
		else if (rock == 2) {
			puts("���΂��Ƃ�?1~2����I��ł�");
			if (scanf("%d", &del) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("�������l����͂��Ă�������");
				continue;
			}
			if (del == 1) {
				puts("\n���Ȃ��͐΂�1���܂���");
				break;
			}
			else if (del == 2) {
				puts("\n���Ȃ��͐΂�2���܂���");
				break;
			}
			else {
				puts("�������l����͂��Ă�������");
			}
		}
		else {
			puts("���΂��Ƃ�?1~3����I��ł�");
			if (scanf("%d", &del) != 1) {
				scanf("%*s");
				if (feof(stdin)) return 1;
				puts("�������l����͂��Ă�������");
				continue;
			}

			if (del == 1) {
				puts("\n���Ȃ��͐΂�1���܂���");
				break;
			}
			else if (del == 2) {
				puts("\n���Ȃ��͐΂�2���܂���");
				break;
			}
			else if (del == 3) {
				puts("\n���Ȃ��͐΂�3���܂���");
				break;
			}
			else {
				puts("�������l����͂��Ă�������");
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
			printf("�c��̐΂�%d�ł�\n\n", rock);
			if (rock == 0) {
				puts("�Ō�̐΂�������̂͂��Ȃ��ł��BCPU�̏���");
			}
			sk = 1;
			continue;
		}
		else if (sk == 1) {
			del = cpu(rock);
			rem = rock - del;
			rock = rem;
			printf("�c��̐΂�%d�ł�\n\n", rock);
			if (rock == 0) {
				puts("�Ō�̐΂�������̂�CPU�ł��B���Ȃ��̏���");
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
		puts("\n�Q�[�����܂������܂���?");
		puts("������Ȃ�1����߂�Ȃ�2����͂��Ă�������");
		if (scanf("%d", &sten) != 1) {
			scanf("%*s");
			if (feof(stdin)) return 1;
			puts("�������l����͂��Ă�������");
			continue;
		}
		if (sten == 1 || sten == 2)break;
		else {
			puts("�������l����͂��Ă�������");
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
	//name:��:������:����
	return 0;
}


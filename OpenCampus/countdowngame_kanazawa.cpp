#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main(void){
	int y, z, i, n;
	int x = 0;
	int turn;
	char a;

	while(x == 0){
		printf("�J�E���g�_�E���Q�[���ւ悤�����I\n���Ȃ��͐�U�Ńv���C�������ł����H�@[y/n] ");
		scanf("%c", &a);
		if(a == 'y'){
			turn = 0;
		} else if(a == 'n'){
			printf("������U�Ńv���C���܂��B\n");
			turn = 1;
		}
		printf("�ŏ��̐��������߂Ă�������\n");
		scanf("%d", &x);
		if(x < 0){
			x = x*(-1);
			printf("���̐����ł����c\n�ŏ��̐����́u%d�v�ł��ˁH\n", x);
		} else {
			printf("����ł̓Q�[���J�n�I�I\n\n");
		}
	}

	while(x > 1){
		printf("���̐�����%d����B\n", x);

		if(turn == 0){
		scanf("%d", &y);
		printf("%d�����܂���H\n", y);
	} else {
		n = 0;
		while(4*n+2 < x){
			n++;
			//printf("n = %d\n", n);
		}
		n--;
		if(x == 4*n+2){
			y = rand() % 3;
			//printf("aaa");
		}

		if((x-1) == 1){
			y = i;
		} else {
			for(i=1; i<=3; i++){
				if((x-i) == (4*n+2)){
					y = i;
				}
			}
		}
		printf("���́@-%d ���܂��B\n", y);
	}

	if(y >= 1 && y <= 3){
		z = x - y;
		//printf("%d - %d = %d\n\n", x, y, z);
		x = z;
		turn = (turn+1) % 2;
	} else {
		printf("���̐����͎g���Ȃ���I�P�`�R�͈̔͂̐�������͂��ĂˁI\n\n");
	}

	if(x <= 1){
		if(turn -= 0){
			printf("���߂łƂ��I���Ȃ��̏����ł��I�B\n");
		} else {
			printf("�c�O�I���Ȃ��̕����ł��c\n");
		}
	}

	}

}
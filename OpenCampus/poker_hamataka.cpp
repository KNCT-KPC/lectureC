#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(){
	int card[52] = {0};										//�g�����v�J�[�h
	/*�g�����v�J�[�h1��1���ɕϐ�������U��A
	�J�[�h�������ꂽ����\���B
	0or1�ň����ꂽ���ۂ��𔻕ʂ���B
	0-12	�X�y�[�h
	13-25	�N���[�o�[
	26-38	�n�[�g
	39-51	�_�C��
	52		�W���[�J�[(�߂�ǂ������̂Ő������Ȃ��悤�ɂ���)*/

	int onehand[5] = {0};									//��D
	int twohand[5] = {0};
	int hand[5] = {0};

	int onerank = 0;										//���̋���
	int tworank = 0;
	int rank = 0;

	int buf[2] = {0};										//�ꎞ�I�ȃX�y�[�X

	int i = 0;
	int j = 0;
	int k = 0;
	int copy = 0;12
	int handle[5] = {0};	

	int pare = 0;

	srand((unsigned)time(NULL));
	int rnd = 0;

	while(i < 5){											//��D�̐���(1P)
		rnd = rand() % 52;
		if(card[rnd] != 1){
			onehand[i] = rnd;
			i++;5
			card[rnd] = 1;
		}
	}

	i = 0;

	while(i < 5){											//��D�̐���(2P)
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


	printf("1P�̃^�[���ł��B\n");
	printf("----------\n");

	for(i=0;i<5;i++){										//��D�̕\��(1P)
		printf("%d ", i+1); 
		j = onehand[i] / 13;
		switch(j){
		case 0:printf("�X�y�[�h��");
			break;
		case 1:printf("�N���[�o�[��");
			break;
		case 2:printf("�n�[�g��");
			break;
		case 3:printf("�_�C����");
			break;
			//case 4:printf("Joker\n");
		}
		//if(onehand[i] != 52){
		printf("%d\n", onehand[i] % 13 + 1);
		//}
	}
	printf("----------\n");

	printf("��������J�[�h�̔ԍ�����͂��Ă�������\n");
	printf("��:1���ڂ�3���ڂ���������ꍇ[13]\n");
	scanf("%d", &i);

	printf("----------\n");

	while(1){												//��D�̌���(1P)
		j = i % 10;
		rnd = rand() % 52;
		if(card[rnd] != 1){
			printf("%d���ڂ��������܂����B\n", j);
			onehand[j-1] = rnd;
			if(i < 6) break;
			else i = i / 10;
		}
	}

	printf("----------\n");

	printf("2P�̃^�[���ł��B\n");

	for(i=0;i<5;i++){										//��D�̕\��(2P)
		printf("%d ", i+1); 
		j = twohand[i] / 13;
		switch(j){
		case 0:printf("�X�y�[�h��");
			break;
		case 1:printf("�N���[�o�[��");
			break;
		case 2:printf("�n�[�g��");
			break;
		case 3:printf("�_�C����");
			break;
			//case 4:printf("Joker\n");
		}
		//if(twohand[i] != 52){
		printf("%d\n", twohand[i] % 13 + 1);
		//}
	}
	printf("----------\n");

	printf("��������J�[�h�̔ԍ�����͂��Ă�������\n");
	printf("��:1���ڂ�3���ڂ���������ꍇ[13]\n");
	printf("�������Ȃ��ꍇ��[0]�����\n");
	scanf("%d", &i);

	printf("----------\n");

	while(1){													//��D�̌���(2P)
		if(i == 0) break;
		j = i % 10;
		rnd = rand() % 52;
		if(card[rnd] != 1){
			printf("%d���ڂ��������܂����B\n", j);
			onehand[j-1] = rnd;
			if(i < 6) break;
			else i = i / 10;
		}
	}

	printf("----------\n");

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

		for(i = 0; i < 5; i++){										//��D�̃\�[�g
			for(j = 0; j < 5; j++){
				if(hand[i] < hand[j]){
					copy = hand[i];
					hand[i] = hand[j];
					hand[j] = copy;
				}
			}
		}

		for(i = 0; i < 5; i++){										//�J�[�h�̐�������
			handle[i] = hand[i] % 13;
		}


		for(i = 0; i < 5; i++){										//�J�[�h�̐����\�[�g
			for(j = 0; j < 5; j++){
				if(handle[i] < handle[j]){
					copy = handle[i];
					handle[i] = handle[j];
					handle[j] = copy;
				}
			}
		}

		/*for(i = 0; i < 5; i++){
		printf("%d %d\n",i,handle[i]);
		}
		printf("\n");*/

		//���C�����X�g���[�g�t���b�V����(��)
		if(hand[0] == 0 && hand[1] == 9 && hand[2] == 10 && hand[3] == 11 && hand[4] == 12){
			rank = 9;
		}else

			//�X�g���[�g�t���b�V����(��)
			if(hand[0] / 13 == hand[1] / 13 && hand[1] / 13 == hand[2] / 13 &&
				hand[2] / 13 == hand[3] / 13 && hand[3] / 13 == hand[4] / 13 &&
				hand[1] % 13 == hand[0] % 13 + 1 && hand[2] % 13 == hand[1] % 13 + 1 &&
				hand[3] % 13 == hand[2] % 13 + 1 && hand[4] % 13 == hand[3] % 13 + 1){
					rank = 8;
			}else

				//�t�H�[�J�[�h��(��)
				if(hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 ||
				hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[4] % 13 ||
				hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ||
				hand[0] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ||
				hand[1] % 13 == hand[2] % 13 && hand[2] % 13 == hand[3] % 13 && hand[3] % 13 == hand[4] % 13 ){
					rank = 7;
				}else

					//�t���n�E�X��(��)
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

						//�t���b�V����(��)
						if(hand[0] / 13 == hand[1] / 13 && hand[1] / 13 == hand[2] / 13 &&
							hand[2] / 13 == hand[3] / 13 && hand[3] / 13 == hand[4] / 13 ){
								rank = 5;
						}else

							//�X�g���[�g��(��)
							if(handle[1] == handle[0] + 1 && handle[2] == handle[1] + 1 &&
								handle[3] == handle[2] + 1 && handle[4] == handle[3] + 1){
									rank = 4;
							}else

								//�X���[�J�[�h��(��)
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

									//�c�[�y�A��
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
									
									}

									for(i=0;i<5;i++){										//��D�̕\��
										printf("%d ", i+1); 
										j = onehand[i] / 13;
										switch(j){
										case 0:printf("�X�y�[�h��");
											break;
										case 1:printf("�N���[�o�[��");
											break;
										case 2:printf("�n�[�g��");
											break;
										case 3:printf("�_�C����");
											break;
											//case 4:printf("Joker\n");
										}
										//if(hand[i] != 52){
										printf("%d\n", onehand[i] % 13 + 1);
										//}
									}
	
	switch(onerank){										//���茋�ʂ̕\��
	case 9: printf("���C�����X�g���[�g�t���b�V��");
		break;
	case 8: printf("�X�g���[�g�t���b�V��");
		break;
	case 7: printf("�t�H�[�J�[�h");
		break;
	case 6: printf("�t���n�E�X");
		break;
	case 5: printf("�t���b�V��");
		break;
	case 4: printf("�X�g���[�g");
		break;
	case 3: printf("�X���[�J�[�h");
		break;
	case 2: printf("�c�[�y�A");
		break;
	case 1: printf("�����y�A");
		break;
	case 0: printf("�m�[�y�A");
		break;
	}

	printf("\n");
	printf("----------\n");

	for(i=0;i<5;i++){										//��D�̕\��
		printf("%d ", i+1); 
		j = twohand[i] / 13;
		switch(j){
		case 0:printf("�X�y�[�h��");
			break;
		case 1:printf("�N���[�o�[��");
			break;
		case 2:printf("�n�[�g��");
			break;
		case 3:printf("�_�C����");
			break;
			//case 4:printf("Joker\n");
		}
		//if(hand[i] != 52){
		printf("%d\n", twohand[i] % 13 + 1);
		//}
	}

	switch(tworank){										//���茋�ʂ̕\��
	case 9: printf("���C�����X�g���[�g�t���b�V��");
		break;
	case 8: printf("�X�g���[�g�t���b�V��");
		break;
	case 7: printf("�t�H�[�J�[�h");
		break;
	case 6: printf("�t���n�E�X");
		break;
	case 5: printf("�t���b�V��");
		break;
	case 4: printf("�X�g���[�g");
		break;
	case 3: printf("�X���[�J�[�h");
		break;
	case 2: printf("�c�[�y�A");
		break;
	case 1: printf("�����y�A");
		break;
	case 0: printf("�m�[�y�A");
		break;
	}

	printf("\n");
	printf("----------\n");

	if(onerank > tworank){
		printf("1P�̏���!");
	}else if(onerank < tworank){
		printf("2P�̏���!");
	}else printf("��������");
}

int main(void){

	int pause = 0;


	game();


	scanf("%d",&pause);
	return 0;
}
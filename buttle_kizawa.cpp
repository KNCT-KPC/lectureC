#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int game(int p1hp, int p1at, int p2hp, int p2at, int turn){
	int comand = 1;
	int damage = 0;
	int pragi = 100;
	int comagi;
	int a = 1;
	srand((unsigned)time(NULL));
	comagi = rand()%150;
	

	if(pragi > comagi){
		turn = 0;
		printf("P1�̐�U\n");
	}else{
		turn = 1; 
		printf("P2�̐�U\n");
	}

	while(p1hp > 0 && p2hp > 0){
		if(turn == 0){
			printf("�Ȃ܂�\tLV\tHP\tMP\n1P\t1\t%d\t0\n",p1hp);
			printf("�Ȃɂ����܂���\n1: �U�� 2:�J�E���^�[\n");
			scanf("%d",&comand);
			if(a == 1 && comand == 1){   
				damage = p1at;
				p2hp -= damage;
				printf("1P�̍U���I2P�� %d�̃_���[�W�I\n", damage);
			}
			else if(a == 1 && comand == 2){
				damage = p1at - 5;
				p2hp -= damage;
				printf("1P�̃J�E���^�[�I2P�� %d�̃_���[�W�I\n", damage);
			}
			else if(a == 2 && comand == 1){
				damage = p1at  - 10;
				p2hp -= damage;
				printf("1P�̍U���I2P�� %d�̃_���[�W�I\n", damage);
			}
			else if(a == 2 && comand == 2) {
				damage = p1at  - 20;
				p2hp -= damage;
				printf("1P�̃J�E���^�[�I2P�� %d�̃_���[�W�I\n", damage);
			}

			
		}else if(turn == 1){
			printf("2P\tLV\tHP\tMP\n2P\t1\t%d\t0\n",p2hp);
			a = rand()%2+1;
			if(a == 1 && comand == 1){   
				damage = p2at;
				p1hp -= damage;
				printf("2P�́@�U���I1P�� %d�̃_���[�W�I\n", damage);
			}
			else if(a == 1 && comand == 2){ 
				damage = p2at - 10;
				p1hp -= damage;
				printf("2P�́@�U���I1P�� %d�̃_���[�W�I\n", damage);
			}
			else if(a == 2 && comand == 1){
				damage = p2at  - 5;
				p1hp -= damage;
 				printf("2P�́@�J�E���^�[�I1P�� %d�̃_���[�W�I\n", damage);
			}
			else if(a == 2 && comand == 2) {
				damage = p2at  - 20;
				p1hp -= damage;
 				printf("2P��  �J�E���^�[�I1P�� %d�̃_���[�W�I\n", damage);
			}
			
		}
		turn = (turn + 1) % 2;
	}
	/*�ǂ��ɓ����΂����̂��킩��Ȃ��̂ł����ł�����ۂ����Ȃ̂�����Ƃ��B
	��肽�����Ƃ͏o����Α���Ƀ����_����1��2��I��łق����Ƃ������ƁB
	int a;
	
	a = rand()%2+1;
	if(a == 1){
			damege = p2at;
	else if(a == 2)damege = p1at -5;
			p1hp -= damege;
	}

	�B
	int p1agi;
	int cpuagi;
	srand((unsigned)time(NULL));
	p1agi = rand()%2+1;
	cpuagi = rand()%2+1;
	���̌��p1agi>cpuagi�̂Ƃ�p1����̍U���ɂȂ�Ƃ��A
	p1agi<cpuagi�̂Ƃ�cpu����̍U���ɂȂ�݂����Ȃ��Ƃ����������B

	���Ƃ͎��̃^�[���ɍs���O�ɐ؂肽���B
	�o�͑҂��Ƃ����̂��낤���H
	��u�Ńp�b�Ǝ����̗^�����_���[�W�Ɨ^����ꂽ�_���[�W�����ׂďo�Ă�����Ȃ񂩈Ⴄ�Ǝv���񂾁B

	*/
	turn--;
	return turn;
}

int main(void){
	int p1hp, p1at;
	int p2hp, p2at;
	int turn = 0;
	int make = 0;
	p1hp = 80;
	p1at = 20;

	p2hp = 80;
	p2at = 20;

	 make = game(p1hp, p1at, p2hp, p2at, turn);
	printf("%dP �́@����ł��܂���",make+2);
	scanf("%d",&turn);
}

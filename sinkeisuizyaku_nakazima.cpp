#include<stdio.h>     
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define ROW 4
#define COL 13

void drow(int look[ROW][COL], char real[ROW][COL]){
	int i,j;
	printf("1       5       9       13\n");

	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			switch(look[i][j]){
			case 0: printf("��");
					break;
			case 1: printf(" %c", real[i][j]);
				    break;
			case 2: printf("  ");
				    break;
				}
		}
			printf(" %d", i+1);
			puts("");
	}
}


int judge(int look[ROW][COL], char real[ROW][COL], int count, int *point){
	char a[2];
	int i,j,k = 0;

	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			if(look[i][j] == 1){
				a[k] = real[i][j];
				k++;
			}
		}
	}
	drow(look,real);
		if(a[0] == a[1]){
			for(i=0; i<ROW; i++){
				for(j=0; j<COL; j++){
					if(look[i][j] ==1){
						look[i][j] = 2;
						
					}
				}
			}
			 printf("�����ł��I\n�����낽�����́u%c�v�ł��I\n",a[0]);
			count--;
			(*point)++;
	} else{
		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				if(look[i][j] == 1){
					look[i][j] = 0;					
				
				}
			}
		}
		printf("�c�O�I�͂���ł�\n");
	}


	printf("\n\n");
	return count;
}



int cpuopen(int look[ROW][COL], char real[ROW][COL], char know[ROW][COL], int count, int *point){
	int i, j, k, l;
	int x, y;
	int ans = 0;

	while(ans != 2){
		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				if(look[i][j] == 2){
					know[i][j] = '0';
				}
			}
		}
		for(i=0; i<ROW; i++){
			for(j=0; j<COL; j++){
				for(k=i; k<ROW; k++){
					for(l=j+1; l<COL; l++){
						if(know[i][j]  != '0'  || know[k][l]  != '0'){
							if(know[i][j] == know[k][l]){
								look[i][j] = 1;
								look[k][l] = 1;
								ans = 2;
							}
						}
					}
				}
			}
		}
					

		if(ans != 2){
			y = rand() % ROW;
			x = rand() % COL;
	
			if(look[y][x] == 0){
					look[y][x] = 1;
				know[y][x] = real[y][x];
				ans++;
			}

		}

	}


	count = judge(look, real, count,point);
	return count;


}


int open(int look[ROW][COL], char real[ROW][COL], int count, int *point){
	int i,j, k;
	for(k=1; k<3; k++){
		drow(look, real);

		printf("\n%d�ڂ��J���܂�\n ",k);
		printf("\n�ォ�牽�Ԗڂ�I�����܂����H\n���Ȃ��̑I��:");
		scanf("%d", &i);
		printf("\n�����牽�Ԗڂ�I�����܂����H\n���Ȃ��̑I��:");
		scanf("%d", &j);
		if(i>0 && i<=ROW && j>0 && j<=COL){
			if(look[i-1][j-1] == 0){
				look[i-1][j-1] = 1;
			}else if(look[i-1][j-1] == 1){
				printf("�����͂��łɃI�[�v�����Ă��܂�\n\n");
				k--;
			}else if(look[i-1][j-1] == 2){
				printf("�����͂��łɃJ�[�h������܂���\n\n");
				k--;
			}
		} else {
			printf("�����ɃJ�[�h�͂���܂���\n\n");
			k--;

		}
	
	}
	count = judge(look, real, count,point);
	return count;


}





/*char sort(char x[]){
	srand (unsigned(time(NULL)));
	int i, j, copy;

	for(i=0; i<52; i++){
		for(j=0; j<52; j++){
			if(x[i] < x[j]){
				copy = x[i];
				x[i] = x[j];
				x[j] = copy;
			}
		}
	}
	return *x;
}
*/



	
char shuffle(char x[]){
	srand(unsigned(time(NULL))); 

	int i, j, randum;
	char copy;

	for(i=0; i<52; i++){
		for(j=0; j<52; j++){
			randum = rand() %52;
			copy = x[i];
			x[i] = x[randum];
			x[randum] = copy;
		}
	}
			
	return *x;
	

	
}




void winner(int playerpoint, int cpupoint){
	printf("player vs cpu\n");
	printf("%d - %d\n", playerpoint, cpupoint);

	if(playerpoint > cpupoint){
		printf("�v���C���[�̏���!!���߂łƂ��I�I\n");
	} else if(playerpoint < cpupoint){
		printf("CPU�̏���....�܂�����ł�!\n");
	} else if(playerpoint == cpupoint){
		printf("���������ł��I�ɂ����I\n");
	} else {
		printf("�������...�悭�킩��Ȃ��Ȃ�...\n");
	}
		scanf("%*s");
}














/*int main(void){
	char x[] = "qazwsxedcrfvtgbyhnujmikolpqazwsxedcrfvtgbyhnujmikolp";
	int i;
	 
	for(i=0; i<52; i++){
		printf("%c\n", x[i]);
	}

	
}*/

void field(char x[]){
	char filed[4][13];
	int j, k, i =0;

	for(j=0; j<4; j++){
		for(k=0; k<13; k++){
			filed[j][k] = x[i];
			x++;
		}
	}
}





	

void game(void){
	char x[] = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz" ;
	shuffle(x);



	int look[ROW][COL] = {};

	char real[ROW][COL];
	int i, j, k=0;
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			real[i][j] = x[k];
			k++;
		}

	}


	char know[ROW][COL] = {};
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			know[i][j] = '0';
		}
	}

	int playerpoint = 0;
	int computerpoint = 0;

	int count = 26;
	int turn = rand() % 2;

	int diff;

	printf("�_�o����!!�@�Q�[���X�^�[�g!!\n");
	while(count != 0){
		 turn = (turn + 1) % 2;
		diff = count;

			printf("���݂̃X�R�A\n");
			printf("count  : %d\n", count);
			printf("player : %d\n", playerpoint);
			printf("cpu    : %d\n", computerpoint);
			puts("");

			if(turn == 0){
				printf("�v���C���[�̃^�[��\n");
				count = open(look, real, count, &playerpoint);
			}else{
				printf("CPU�̃^�[��\n");
				Sleep(3000);
				count = cpuopen(look, real, know, count, &computerpoint);
				
			}
			 if(diff != count) turn++;

	}

	printf("�Q�[���I���I\n���s�𔻒肵�܂�\n");
	winner(playerpoint, computerpoint);

}





int main(void){
	game();

	return 0;

}






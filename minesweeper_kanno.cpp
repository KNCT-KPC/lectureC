#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ��Ղ̏c�� */
#define ROW 12
#define COL 16

/* debug (�֐����ƔC�ӂ̃��b�Z�[�W��\�����܂��Dprintf()�֐��Ɠ��l�̎g����) */
/*C99
#define DEBUG(...)  DEBUG_2(__VA_ARGS__, "")
#define DEBUG_2(fmt, ...)			\
 printf("%s(): "fmt"%s", __func__, __VA_ARGS__)
*/

//GNU Only
//#define DEBUG(fmt, ...)					\
// printf("%s(): "fmt, __func__, ## __VA_ARGS__)
 

char printGo(int num);
void printField(int open[][COL], int number[][COL],int field[][COL],int flag);
void bomb( int field[][COL], int doukasen);
int fieldCheck(int open[][COL], int row, int col);
void fieldChange(int open[][COL], int number[][COL], int row, int col);
int win(int field[][COL], int open[][COL]);

void Msg(int code);
int input(int field[][COL], int open[][COL], int number[][COL]);
void defNumber(int field[][COL], int number[][COL]);
void game();
int main(void);

char printGo(int num)
{
    char str[2]; // �ꕶ�����̕�����
/* ��Ղ̃}�X�̐��l�𕶎��ɕϊ����܂� */
    switch(num) {
    case 0:
	return ' ';
    default:
	break;
    }
    sprintf(str, "%d", num); // ���l���當����ɕϊ�
    return str[0];
}

void printField(int open[][COL], int number[][COL],int field[][COL],int flag)
{
/* ��Ղ�\�����܂� */
    int i, j; // �J��Ԃ��̂���
    printf("�J���Ă��Ȃ� -> o, ���͂̔��e�� -> ����, �t���O -> f\n");

// ��ԍ��̕\��
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("%2d ", i+1);
    }
    printf("\n");

// ��ԍ���؂�̕\��
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("---");
    }
    printf("\n");

// �t�B�[���h�̕\��
    for(i = 0; i < ROW; i++) {
// �s�ԍ��̕\��
	printf("%2d | ",i+1);

// �}�X�ڂ̕\��
	for(j = 0; j < COL; j++) {
		if(field[i][j]== 1 && flag == 1){
			printf(" b ");
		continue;
		}
	    if(open[i][j] == -1) {
		    printf(" f ");
		continue;
	    }
	    else if(open[i][j] == 1) {
			printf(" %c ", printGo(number[i][j]));
	    }
	    else {
			printf(" o ");
	    }
	}

// �s�ԍ��̕\��
	printf("| %2d\n",i+1);
    }

// ��ԍ���؂�̕\��
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("---");
    }
    printf("\n");

// ��ԍ��̕\��
    printf("     ");
    for(i = 0; i < COL; i++) {
	printf("%2d ", i+1);
    }
    printf("\n");

    return;
}

/* ���e�ʒu���������݂��܂��i�����_���ł��j */
void bomb( int field[][COL],int doukasen)
{
    int i, j, count=0;

// �V�[�h�l
    srand((unsigned)time(NULL));

    while(count < doukasen) {
    i = rand()%ROW;
    j = rand()%COL;
    if(field[i][j] == 1) continue;
    field[i][j] = 1;
    count++;
    }
/*
    field[0][4] = 1;
    field[1][3] = 1;
    field[3][9] = 1;
    field[6][8] = 1;
    field[9][0] = 1;
    field[7][5] = 1;
    field[3][8] = 1;
*/
    return;
}

int fieldCheck(int open[][COL], int row, int col)
{
/* ���͂����w���肪�s���Ȑ��l�łȂ����m�F���܂� */

/* ���͒l���͈͊O�łȂ��� */
    if(row < 0 || ROW <= row) return -1;
    if(col < 0 || COL <= col) return -2;

/* ���Ɍ����J���Ă��Ȃ��� */
    if(open[row][col] > 0) return 1;
    return 0;
}

void fieldChange(int open[][COL], int number[][COL], int row, int col)
{
/* �}�C���X�C�[�p�̔z��ɓK�؂Ȍ����J���܂� *
 * �N�C�b�N�\�[�g�̂悤�ȍċA�I�Ȃ����ł� *
 */

    /* �������g�����Ȃ�I�� */
    if(open[row][col] == 1) return;
    else if(number[row][col] > 0) {
	open[row][col] = 1;
	return;
    }
    else open[row][col] = 1;

    /* �ċA�I�I�I�i�������z��͈̔͊O�ɂȂ�Ȃ��悤�Ɂj */
    if(row-1 >= 0) fieldChange(open, number, row-1, col);
    if(row+1 < ROW) fieldChange(open, number, row+1, col);
    if(col-1 >= 0) fieldChange(open, number, row, col-1);
    if(col+1 < COL) fieldChange(open, number, row, col+1);

    return;
}

int win(int field[][COL], int open[][COL])
{
    int i, j;
    for(i = 0; i < ROW; i++) {
	for(j = 0; j < COL; j++) {
/* �S�Ă̗v�f�ɑ΂��Ď��s */
/* ���e�ʒu�ȊO�͌����J���Ă��邩���� */
	    if(field[i][j] != 1) {
		if(open[i][j] == 0) return 1;
		if(open[i][j] == -1) return 1;

	    }
	}
    }
    return 0;
}

void Msg(int code)
{
/* ���b�Z�[�W��\�����܂� */
    if(code > 0) {
	printf("���̃}�X�͂��łɊJ���Ă��邩�A�t���O�ł��B�I�����Ȃ����Ă��������B\n");
    }
    else if(code < 0) {
	printf("���̃}�X�͔͈͊O�ł��B�I�����Ȃ����Ă��������B\n");
    }
    else {
	printf("�I�����������܂���\n");
    }
    return;
}

int input(int field[][COL], int open[][COL], int number[][COL])
{
/* �w����̓��͂���t���C���������܂� */
    int row = 0; // ���[�U�[�w��̈ʒu
    int col = 0; // ���[�U�[�w��̈ʒu
    int mode; // ���[�h�ێ�
    int status = 0; // ���͒l���s�����ǂ����̌��ʂ�ۑ����邽��

    while(1) {
	printField(open, number,field,0); // ��Ղ̕\��

	printf("���[�h��I�����Ă�������(���͌�� Enter �L�[�������Ă�������)\n");
	printf("�t���O�𗧂Ă�E���� : 1, �����J���� : 2\n");

/* �Ƃ肠�����������͎��̖������[�v��� */
	if(scanf("%d", &mode) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n�s���Ȓl�ł��D�ē��͂��Ă��������D(r)\n\n");
	    continue;
	}

/* �قȂ镶���̑΍� */
	if(!(mode == 1 || mode == 2)) {
	    printf("\n�s���Ȓl�ł��D�ē��͂��Ă��������D(mfo)\n\n");
	    continue;
	}

	printf("���Ȃ��̃}�X�ڂ�I�����Ă�������\n");
	printf("�c(���͌�� Enter �L�[�������Ă�������) : ");

/* �Ƃ肠�����������͎��̖������[�v��� */
	if(scanf("%d", &row) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n�s���Ȓl�ł��D�ē��͂��Ă��������D(r)\n\n");
	    continue;
	}

	printf("��(���͌�� Enter �L�[�������Ă�������) : ");

/* �Ƃ肠�����������͎��̖������[�v��� */
	if(scanf("%d", &col) != 1) {
	    scanf("%*s");
	    if(feof(stdin)) printf("Buffer Error!\n");
	    printf("\n�s���Ȓl�ł��D�ē��͂��Ă��������D(c)\n\n");
	    continue;
	}

/* ���͔ԍ�����z��ԍ��֕ϊ� */
	row--;
	col--;

	status = fieldCheck(open, row, col); // ���͒l�̃`�F�b�N
	Msg(status); // �`�F�b�N���ʂ̃��b�Z�[�W��\��
	if(status == 0) break; // ����Ȃ烋�[�v�𔲂���
    }
    if(mode == 2) {
	if(field[row][col] == 1) { // �s�k����
	    printField(open, number,field,1); // ��Ղ̕\��
	    printf("you lose!\n");
	    return -1;
	}
	fieldChange(open, number, row, col); // �t�B�[���h�Ɍ����J����
	if(win(field, open) == 0) { // ��������
	    printField(open, number,field,1); // ��Ղ̕\��
	    printf("you win!\n");
	    return 1;
	}
    }
    else if(mode == 1) {
	/* �t���O�������Ă��Ȃ��Ȃ�A�t���O�𗧂Ă� */
	if(open[row][col] == 0) open[row][col] = -1;

	/* �t���O�������Ă���Ȃ�A�t���O������ */
	else if(open[row][col] == -1) open[row][col] = 0;
    }
    return 0;
}

/* �}�C���X�C�[�p�� 1, 2, 3 �̂悤�Ȑ��l�̎Z�o�i�R�[�h���ƂĂ����ɂ����j */
void defNumber(int field[][COL], int number[][COL])
{
    int i, j, num;
    int iflug;
    int jflug;
    for(i = 0; i < ROW; i++) {
	for(j = 0; j < COL; j++) {
/* �S�Ă̗v�f�ɑ΂��Ď��s */
	    num = 0;

/* �z��̗v�f���[�ɂ��Ă��邩�ǂ����̔��� */
	    if(i == 0) iflug = -1;
	    else if(i == ROW - 1) iflug = 1;
	    else iflug = 0;

	    if(j == 0) jflug = -1;
	    else if(j == COL -1) jflug = 1;
	    else jflug = 0;

/* �����̎���ɔ��e�������邩����B���ɂ��� */
	    if(iflug != -1 && jflug != -1  && field[i-1][j-1] == 1) num++;
	    if(jflug != -1 && field[i][j-1] == 1) num++;
	    if(iflug != 1 && jflug != -1 && field[i+1][j-1] == 1) num++;
	    if(iflug != -1 && jflug != 1 && field[i-1][j+1] == 1) num++;
	    if(jflug != 1 && field[i][j+1] == 1) num++;
	    if(iflug != 1 && jflug != 1 && field[i+1][j+1] == 1) num++;
	    if(iflug != -1 && field[i-1][j] == 1) num++;
	    if(iflug != 1 && field[i+1][j] == 1) num++;

/* �����̈ʒu�����e�Ȃ� 0 �Ƃ��A�����łȂ���Δ��e������ */
	    if(field[i][j] == 0) number[i][j] = num;
	    else number[i][j] = 0;
	}
}
    return;
}

void game()
{
/* �w�����ύX������C���͂�������C�����������... */

/* ������ */
    int field[ROW][COL] = {}; // �t�B�[���h(�����Ȃ� = 0; ���e�ʒu = 1;)
    int open[ROW][COL] = {}; // �}�X���I�[�v������Ă��邩(�t���O�𗧂Ă� = -1, ����ĂȂ� = 0; ����Ă� = 1;)
    int number[ROW][COL] = {}; // �}�X�ɕ\�����鐔�l(���e = -1, �����\�����Ȃ� = 0; �\������ = 1 �ȏ�;)
	int doukasen;
    int status = 0;
	printf("���e�̐������߂Ă�������\n");
	scanf("%d",&doukasen);
    bomb(field,doukasen); // ���e�ʒu������
    defNumber(field, number); // ���e�ʒu�ɉ����āA1, 2, 3 �݂����Ȑ��l���Z�o

    printf("�}�C���X�C�[�p���J�n���܂��B(�[���T�C�Y��80x24�ɂ��Ă�������)�B\n");

    while(1) {
	status = input(field, open, number); // ��΂̒u���ꏊ����́C����Ȃ�
	if(status != 0) break; // �����C���s�������Ȃ�C���[�v���甲����
    }
	scanf("%d",&status);
    return;
}

int main(void)
{
/* �������S�Ă̎n�܂� */
    game();

    return 0;
}


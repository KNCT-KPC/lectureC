#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

DeclareTask(Task1);				/* Task1��錾 */

void ecrobot_device_initialize(){}		/* OSEK�N�����̏����i�������Ȃ��j*/

void ecrobot_device_terminate(){}		/* OSEK�I�����̏����i�������Ȃ��j*/


void user_1ms_isr_type2(void){}

TASK(Task1)
{

	ecrobot_sound_tone(440,10, 50);	/* ����炷 */
	systick_wait_ms(100);			/* 100ms�҂� */
   		
   	display_string("THAT'S ALL !");		/* ���b�Z�[�W��\������ */
	display_update();
	TerminateTask();					/* �����I�� */
}

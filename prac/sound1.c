#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

DeclareTask(Task1);				/* Task1を宣言 */

void ecrobot_device_initialize(){}		/* OSEK起動時の処理（何もしない）*/

void ecrobot_device_terminate(){}		/* OSEK終了時の処理（何もしない）*/


void user_1ms_isr_type2(void){}

TASK(Task1)
{

	ecrobot_sound_tone(440,10, 50);	/* 音を鳴らす */
	systick_wait_ms(100);			/* 100ms待つ */
   		
   	display_string("THAT'S ALL !");		/* メッセージを表示する */
	display_update();
	TerminateTask();					/* 処理終了 */
}

/*================================================================
  Copyright (c) 2021, Quectel Wireless Solutions Co., Ltd. All rights reserved.
  Quectel Wireless Solutions Proprietary and Confidential.
=================================================================*/
/**
 ******************************************************************************
 * @file    example_timer.c
 * @author  Juson.zhang
 * @version V1.0.0
 * @date    2020/04/02
 * @brief   This file tests timer's APIs
 ******************************************************************************
 */

#include <stdio.h>
#include "ql_rtos.h"
#include "ql_type.h"
#include "ql_application.h"
#include "ql_timer.h"
#include "uart_usb.h"
#include "ql_gpio.h"

#define test_log(fmt, args...) usb_log(fmt, ##args)
#define LED_STT GPIO_PIN_NO_6
static unsigned int g_timer_cnt = 0;
bool led=0;
void ql_Acctimer_test_cb(unsigned int param)
{
	g_timer_cnt++;

}

static void quec_timer_test(void * argv)
{
	ql_gpio_init(LED_STT, PIN_DIRECTION_OUT, PIN_PULL_DISABLE, PIN_LEVEL_LOW);
	int timer_id = 0;
	timer_id = ql_start_Acctimer(QL_TIMER_PERIOD, 1000, ql_Acctimer_test_cb, 0);
	test_log("timer_id=%d \n", timer_id);

	while (1) {
		bool level;
		test_log("g_timer_cnt=%d LEVEL:%d \n", g_timer_cnt,ql_gpio_get_level(LED_STT, &level));
		led^=1;
		ql_gpio_set_level(LED_STT, led == 0 ? PIN_LEVEL_LOW : PIN_LEVEL_HIGH);
		ql_rtos_task_sleep_ms(500);
	}
}

 //application_init(quec_timer_test, "quec_timer_test", 2, 0);



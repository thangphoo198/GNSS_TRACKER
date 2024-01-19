#include "ql_type.h"
#include "ql_func.h"
#include "ql_rtos.h"
#include "ql_application.h"
#include <stdio.h>
#include <string.h>
#include "ql_gpio.h"
#include "ql_boot.h"
#include "uart_usb.h"
extern void quec_timer_test(void * argv);
void main(void)
{
;
}
application_init(quec_timer_test, "MAIN", 1, 14);
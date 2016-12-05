#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "hmi_msg.h"
#include "print_helper.h"

#define BLINK_DELAY_MS 100

void main (void)
{
    /* Set pin 3 of PORTA for output */
    DDRA |= _BV(DDA3);
    /* Init error console as stderr in UART3 and print user code info */
    uart3_init();
    stderr = &uart3_out;
    fprintf(stderr, PROGRAM_VERSION,
            GIT_DESCR, __DATE__, __TIME__);
    fprintf(stderr, LIBC_VERSION, __AVR_LIBC_VERSION_STRING__);
    /* End UART3 init and info print */

    print_ascii_tbl(stderr);

    while (1) {
        /* Set pin 3 high to turn LED on */
        PORTA |= _BV(PORTA3);
        _delay_ms(BLINK_DELAY_MS);
        /* End test assert */
        /* Set pin 3 low to turn LED off */
        PORTA &= ~_BV(PORTA3);
        _delay_ms(BLINK_DELAY_MS);
    }
}
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "uart.h"
#include "hmi_msg.h"
#include "print_helper.h"

#define BLINK_DELAY_MS 100

void main (void)
{
    /*init*/
    DDRA |= _BV(DDA3);
    uart3_init();
    stderr = &uart3_out;
    uart0_init();
    stdout = stdin = &uart0_io;

    fprintf_P(stderr, PSTR(MSG_PROGRAM_VERSION), PSTR(GIT_DESCR), PSTR(__DATE__), PSTR(__TIME__));
    fprintf_P(stderr, PSTR(MSG_LIBC_VERSION), PSTR(__AVR_LIBC_VERSION_STRING__));
    fprintf_P(stdout, PSTR(MSG_STUD_NAME "\n"));
    print_ascii_tbl(stdout);

    unsigned char table[128];
    for (unsigned char a = 0; a < sizeof(table); a++) {
        table[a] = a;
    }
    print_for_human(stdout, table, sizeof(table));

    while (1) {
        /*cycle start led*/
        PORTA |= _BV(PORTA3);
        _delay_ms(BLINK_DELAY_MS);

        char input;
        fprintf_P(stdout, PSTR("\n" MSG_ENTER_MONTH));
        fscanf(stdin, "%c", &input);
        for (int i = 0 ; i < 6 ; i++){
            if (!strncmp_P(&input,  (PGM_P) pgm_read_word(&months[i]), 1)) {
                fputc('\n', stdout);
                fprintf_P(stdout, (PGM_P) pgm_read_word(&months[i]));
            }
        }
        
        /*cycle end led*/
        PORTA &= ~_BV(PORTA3);
        _delay_ms(BLINK_DELAY_MS);
    }
}
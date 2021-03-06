void uart0_init(void);
void uart3_init(void);
int uart0_putchar(char c, FILE *stream);
int uart0_getchar(FILE *stream);
int uart3_putchar(char c, FILE *stream);

/* http://www.ermicro.com/blog/?p=325 */
FILE uart0_io = FDEV_SETUP_STREAM(uart0_putchar, uart0_getchar, _FDEV_SETUP_RW);
FILE uart3_out = FDEV_SETUP_STREAM(uart3_putchar, NULL, _FDEV_SETUP_WRITE);
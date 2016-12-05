#include <avr/pgmspace.h>
#define MSG_PROGRAM_VERSION "Version: %S built on: %S %S\n"
#define MSG_LIBC_VERSION "avr-libc version: %S\n"
#define MSG_STUD_NAME "Marko Nõu"
#define MSG_ENTER_MONTH "Enter first letter of month name >"

const char january[] PROGMEM = "January";
const char february[] PROGMEM = "February";
const char march[] PROGMEM = "March";
const char april[] PROGMEM = "April";
const char may[] PROGMEM = "May";
const char june[] PROGMEM = "June";

PGM_P const months[] PROGMEM = {january, february, march, april, may, june};
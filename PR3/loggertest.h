#include "fsl_debug_console.h"
#include <stdio.h>


void Log_enable(void);
void Log_disbale(void);
void Log_data(uint32_t* pointer,uint8_t length);
int Log_status(uint8_t x);
void log_string(char *letter);
void log_integer(uint32_t integer);




#include<stdio.h>
//#include<board.h>
#include<stdlib.h>
#include<stdint.h>
typedef enum mem_status
{
SUCCESS = 0, // no error
FAILED // failure case
} mem_status;
uint32_t * allocate_words(size_t length);
void free_words(uint32_t* src);
uint8_t * display_memory(uint32_t * loc,size_t length);
mem_status write_memory(uint32_t * loc, uint16_t value);
mem_status invert_block(uint32_t*loc,size_t length);
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed);
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed);
uint32_t *get_address (uint32_t *base_addr, uint32_t offset);

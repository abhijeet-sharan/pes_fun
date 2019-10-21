#include "memory.h"
#include "pattern_gen.h"


uint32_t * allocate_words(size_t length)
{
uint32_t *p = NULL;
 p=malloc(length * sizeof(uint8_t));
if(NULL==p)
{
    printf("Memory not allocated\n\r");
}
else
{
    printf("Memory allocated = %p\n",p);
    // for now let the memory be
}
return p;
}
void free_words(uint32_t* src)
{
if(NULL==src)
    {
    printf("Error: Cannot free unallocated memory!\n");
    }
else
    {
free(src); src=NULL;
    }
}
uint8_t * display_memory(uint32_t *loc,size_t length)
{
    volatile uint8_t *ptr=NULL;
    		ptr=(uint8_t *)loc;
    static uint8_t *arr=NULL;
    arr=malloc(length*sizeof(uint8_t));
	for(int i=0;i<length;i++)
	{
		arr[i]=*ptr;
		ptr++;
	}
return arr;
//for(uint32_t count = 0;count<length;count++)
//{
//// problem in making a correct for loop
////content[0]=*loc;
////*(loc+1)=*(loc)+1;
//content[count]=*(loc++);
//}
//return content;
}
mem_status write_memory(uint32_t *loc,uint16_t value)
{
    uint8_t *ptr=NULL;
    ptr=(uint8_t *)loc;
    *ptr = value;
    return SUCCESS;
}

mem_status invert_block(uint32_t * loc, size_t length)
{
	uint8_t *ptr=NULL;
	ptr=(uint8_t*)loc;
	for(int i=0;i<length;i++)
	{
		ptr[i]^=0xFF; //toggling all bits in that specific byte
	}
	return SUCCESS;
}

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	uint8_t *patternwrite=NULL;
	patternwrite=(uint8_t *)loc;
	//printf("Address is%p\n",patternwrite);

	gen_pattern(patternwrite,length,seed);

	return SUCCESS;
	}

 uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	uint8_t storepattern[length];
	gen_pattern(storepattern,length,seed);
	uint8_t *testptr=NULL;
	testptr=(uint8_t *)loc;
	  uint32_t *errorlist=NULL;
	  errorlist=malloc(length*sizeof(uint32_t));

	for(int i=0;i<length;i++)
	{
		if((*(testptr+i))!=storepattern[i])
            errorlist[i]=(uint32_t)(testptr+i);
		else
			errorlist[i]=0;

	}
	return errorlist;
}
uint32_t *get_address (uint32_t *base_addr, uint32_t offset)
{
uint8_t *offset_address=NULL;
offset_address=(uint8_t *)base_addr;
while(offset!=0)
{
	offset_address++;offset--;
}
uint32_t * return_offset_address=NULL;
return_offset_address=(uint32_t *)offset_address;
return return_offset_address;
}



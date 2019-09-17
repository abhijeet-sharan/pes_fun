#include<stdio.h>

void dtob(int dec);
void testbit(int in);

int input=0xCAFE;
int a = 0;//a and b are helper variables
int b=0;
int output=0xffff;// output variable
int main()
{

printf("%X\n",input);//print input

//geeksforgeeks.org/bitwise-operators-in-c-cpp

testbit(input);//function to test last 4 bits

//reverse the byte order
a = input & 0xff;
b = (input >> 8) & 0xff;
output=(output&a)<<8;
output=(output+b);
printf("0x%x\n",output);  

testbit(output);

//rotate 4 bits left
a=((output<<4)&0xffff);
b=output>>12;
output=a+b;
printf("b0x%x\n",output);
testbit(output);

//rotate 8bits right
a=output>>8;
b=((output<<8)&0xffff);
output=b+a;
printf("0x%x\n",output);
testbit(output);
}


void dtob(int dec)
{
int decimal = dec;
int binary[16];
int n=16;
int x=n;

while(decimal!=0)
  {
   binary[x-1]=decimal%2;   
   decimal=decimal/2;
   x=x-1;
  }

while(x<n)
  {
   printf("%d",binary[x]);
   x++;
  }
}

void testbit(int a)
{
if((a&14)==14 | (a&11)==11 | (a&7)==7 | (a&13)==13)
  {
   printf("True\n");
   dtob(a);
   printf("\n");
  }
else
    {
     printf("False\n");
     dtob(a);
     printf("\n");
    }

}

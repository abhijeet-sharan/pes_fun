#include<led.h>
void LED_RUN_FBR(int x)// toggles led through predetermined pattern
{

if(x<=5||x==18||x==19)
LED_BLUE_TOGGLE();

if((x>5)&&(x<12))
	LED_RED_TOGGLE();
if((x>11)&&(x<18))
	LED_GREEN_TOGGLE();
}

void LED_RUN_FBD(int x)
{

if(x<=5||x==18||x==19)
{
	LED_BLUE_TOGGLE();
	printf("LED BLUE");
}

if((x>5)&&(x<12))
	{
	LED_RED_TOGGLE();printf("LED RED");
	}
if((x>11)&&(x<18))
{
LED_GREEN_TOGGLE();
printf("LED GREEN");
}
}

void LED_STATUS_FBD(int x)
{
    if(x%2==0)
        printf(" ON ");
    else
        printf(" OFF ");
}
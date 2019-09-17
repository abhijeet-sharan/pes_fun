#include<stdio.h>
#include<ctype.h>
int main()
{
int TestInput;
while(1)
    {
   scanf("%d",&TestInput);
 if(TestInput<9 || TestInput >13 && TestInput <32)
     {
     printf("Code:%d Type:Non printing character\n",TestInput);
         
     }
   if(isalpha(TestInput))
   {
       if(isupper(TestInput))
       {
           printf("Code:%d Type:Upper Case ASCII Char:%c\n",TestInput,TestInput,TestInput);
       }
       else
       {
           printf("Code:%d Type:Lower Case ASCII Char:%c\n",TestInput,TestInput,TestInput);
       }
   }
   if(isdigit(TestInput))
       printf("Code:%d Type:Digit ASCII Char:%c\n",TestInput,TestInput,TestInput);
  if(isspace(TestInput))
       printf("Code:%d Type:Space ASCII Char:%c\n",TestInput,TestInput,TestInput);
   if(ispunct(TestInput))
       printf("Code:%d Type:Special Character ASCII Char:%c\n",TestInput,TestInput,TestInput);
    }
return 0;
}

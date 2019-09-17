#include<stdio.h>

#include<stdlib.h>

#include<math.h>

void convertBin(long int Decimal, int BitNumber) //derived from https://www.includehelp.com/c-programs/c-program-get-binary-of-a-decimal-number.aspx
{
  int outputBin;

  //output index starts from 0; from 0 to operand -1
  for (outputBin = BitNumber - 1; outputBin >= 0; outputBin--) //dependent on operand value
  {
    if (((1 << outputBin & Decimal)))
      printf("1");
    else
      printf("0");
  }
}
int main()
{


radixerror: 
while(1)
{
  char convertstring[100];// string to store input values
  char inputnumber[10];//holds number value
  int radix;
  int operand;
  printf("\nEnter input as input number,radix,operand\n");
  scanf("%[^\n]%*c", convertstring); // www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/-To take input including whitespaces
  sscanf(convertstring, "%s %d %d", inputnumber, & radix, & operand);
  printf("Input Value: %s    Radix: %d    Operand: %d\n",inputnumber,radix,operand);
  //printf("%d ",radix);printf("%d",operand);

  long int actualvalue;//stores the input number as integer
  switch (radix) {     //to store input number according to its radix
  case 8:
    sscanf(inputnumber, "%lo", & actualvalue);
    break;
  case 16:
    sscanf(inputnumber, "%lx", & actualvalue);
    break;
  case 10:
    sscanf(inputnumber, "%ld", & actualvalue);
    break;
  default:
    printf("Error-Radix invalid\n");
    printf("Enter valid radix\n");
    goto radixerror;
    // exit(EXIT_FAILURE);
  }

  long int max_unsigned = pow(2, operand) - 1; // stores maximum unsigned value depending on operand
  long int max_signed = pow(2, operand - 1) - 1;// stores maximum unsigned value depending on operand
  short int OutSignedRep = 0; // indicates whether signed representation is possible, set to 1 if not possible and 0 if it can
  short int negative = 0;// indicates if number is negative, set to 1 if not possible and 0 if it can
  short int OutOneslimit = 0;//indicates if ones complement is possible, set to 1 if not possible and 0 if it can
  short int OutTwoslimit = 0;//indicates if twos complement is possible, set to 1 if not possible and 0 if it can
  if (actualvalue > max_signed) {

    OutSignedRep += 1;
  }
  if (actualvalue > (max_unsigned)) // checking if number is less than maximum of unsigned representation
    exit(EXIT_FAILURE); //error as value higher than maximum unsigned operand no. of bits maximum
  if (actualvalue < 0) { //checking if number is negative
    negative += 1;
  }
  switch (operand) { // checking based on operand limits
  case 4://when operand is 4

    if (actualvalue > (-8) && actualvalue < 8) //checking against maximum and minimum limits for ones complement. Limits depend on operand
      break;
    else {
      OutOneslimit += 1; //set to 1 if not possible
      if (actualvalue <= -8) { //checking against minimum limit for signed representation.

        OutSignedRep += 1;//set to 1 if not possible
      }
      if (actualvalue < -9) { //checking against minimum limit for twos complement.
        OutTwoslimit += 1;//set to 1 if not possible
      }
      break;
    }

  case 8://when operand is 8
    if (actualvalue > (-128) && actualvalue < 128)//checking against maximum and minimum limits for ones complement. Limits depend on operand
      break;
    else {
      OutOneslimit += 1;//set to 1 if not possible
      if (actualvalue <= -128) {//checking against minimum limit for signed representation.

        OutSignedRep += 1;//set to 1 if not possible
      }
      if (actualvalue < -129) {//checking against minimum limit for twos complement.
        OutTwoslimit += 1;//set to 1 if not possible
      }
      break;
    }
  case 16:// when operand is 16
    if (actualvalue > (-32768) && actualvalue < (32768))
      break;
    else {
      OutOneslimit += 1;//set to 1 if not possible
      if (actualvalue <= -32768) {//checking against minimum limit for signed representation.

        OutSignedRep += 1;//set to 1 if not possible
      }
      if (actualvalue < -32769) {//checking against minimum limit for twos complement.
        OutTwoslimit += 1;//set to 1 if not possible
      }
      break;
    }

  }
  //Output routine-Output operations and Table formatting
  printf("Output:\t\t\t\tValue\t\tMaximum\t\tMinimum\n");
  printf("Binary(abs)\t\t\t0b");
  convertBin(abs(actualvalue), operand);//prints binary representation of input number
  printf("\t\t0b");
  convertBin(max_unsigned, operand);//binary of max value that can be shown
  printf("\t\t0b0\n");

  printf("Octal(abs)\t\t\t");
  printf("0%o\t\t", abs(actualvalue));//prints octal absolute of input value
  printf("0%lo\t\t", max_unsigned);//prints octal rep. of max. possible value
  printf("0\n");

  printf("Decimal(abs)\t\t\t");
  printf("%d\t\t", abs(actualvalue));//prints decimal re. absolute of input value
  printf("%ld\t\t", max_unsigned);//prints decimal rep. of max. possible value
  printf("0\n");

  printf("Hexadecimal(abs)\t\t");
  printf("0x%X\t\t", abs(actualvalue));//prints hex rep. of absolute of input value
  printf("0x%lX\t\t", max_unsigned);//prints octal rep. of max. possible value
  printf("0x0\n");

  if (OutOneslimit != 1) {//verifying if ones complement is possible

    printf("Signed One's Complement\t\t0b");
    convertBin(~actualvalue, operand);//prints binary rep. of 1s complement
    printf("\t\t0b");
    convertBin(~0, operand);//prints maximum of 1s complement
    printf("\t\t0b");
    convertBin(~max_unsigned, operand);//prints minimum of ones complement
    printf("\n");
  } else
    printf("Signed One's Complement\t\tError can't be found due to operand limits\n");//if representation is not possible
  if (OutTwoslimit != 1) {//verifying if Twos complement is possible
    printf("Signed Two's Complement\t\t0b");
    convertBin(~actualvalue + 1, operand);//prints binary rep. of twos complement
    printf("\t\t0b");
    convertBin(~0, operand);//prints maximum of 2s complement
    printf("\t\t0b");
    convertBin(~max_unsigned, operand);//prints minimum of signed rep
    printf("\n");
  } else
    printf("Signed Two's Complement\t\tError can't be found due to operand limits\n");//when twos complement is out of range due to operand limit

  if (OutSignedRep != 1) {//verifying if signed rep. is possible
    printf("Signed Magnitude\t\t");
    if (negative)//routine to print signed bit: 1 if number is negative else 0
      printf("0b1");
    else
      printf("0b0");
    convertBin(abs(actualvalue), operand - 1);//prints binary rep. of number in reduced number of bits allowing for sign bit
    printf("\t\t0b");
    convertBin(~0, operand);//prints maximum of signed rep
    printf("\t\t0b");
    convertBin(~max_unsigned, operand);//prints minimum of signed rep
    printf("\n");
  } else
    printf("Signed Magnitude\t\tError can't be found due to operand limits\n");
    //when signed representation can not be made due to operand limit
}
  return 0;
}

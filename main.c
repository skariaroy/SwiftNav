#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include <string.h>
#define NO_TEST_CASES_PRIME 10
#define NO_TEST_CASES_PRINT_STRING 10

//Function prototypes
//! Check if a number is prime or not
/*!
      \param num The number.
      \return IS num prime or not
*/
bool isPrime(int num);
//! Output the string based on the number
/*!
      \param num The number.
      \param str pointer to the string to which the string should be stored
      \return void
*/
void Printstring(int num,char *str);
 //Unit test to test isPrime()
void primeUnitTest();
 //Unit test to test Printstring()
void PrintstringUnitTest();

int main()
{
 unsigned long int a=0; /*!< Variable for generating the fibonacii series */
 unsigned long int b=1; /*!< Variable for generating the fibonacii series */
 unsigned long int c;   /*!< Variable for generating the fibonacii series */
 int i;
 int n; /*!< Number of elements series */
 char str[10];

 //Call the unit test to test isPrime()
 primeUnitTest();
 //Call the unit test to test Printstring()
 PrintstringUnitTest();
 printf("\nEnter the number:");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
  c=a+b;
  Printstring(c,str);
  printf("%s(%li) ",str,c);
  a=b;
  b=c;
 }
 return 0;
}


void Printstring(int num,char *str)
{
    str[0]='\0';
    if(num == 0 )
    {
        strcat(str,"0");
        return;
    }
    if(!(num%5))
    {
        strcat(str,"Fizz");
    }
    if(!(num%3))
    {
        strcat(str,"Buzz");
    }
    // If the number is divisible by both 3 and 5 it will be divisible by 15. So no need for special case.
    if(str[0]=='\0')
    {
        if(isPrime(num))
        {
            strcpy(str,"BuzzFizz");
        }
        else
        {
            sprintf(str,"%d",num);
        }
    }

}

//Prime number is always in the form 6n+/-1. Except for 2 and 3.
bool isPrime(int num)
{
    if(num<=1) { return false;}
    if( (num==2) || (num ==3) ) { return true;}
    if( !((num-1)%6) || !((num+1)%6) ) {  return true; }
    return false;

}

void primeUnitTest()
{
    int i;
    bool expectedResult[NO_TEST_CASES_PRIME]= {false,false,true,true,false,true,false,true,false,false},flag=true;
 printf("\nGoing to Run the Unit Test for : isPrime (0  to 9)");
 for(i=0;i<NO_TEST_CASES_PRIME;i++)
 {
    if(!(isPrime(i) == expectedResult[i]))
    {
        printf("\nTest failed !!!Case:%d",i);
        flag=false;
    }

 }
 if(flag)
 {
    printf("\nTest passed\n\n");
 }
 else printf("\nTest failed!!!\n");

}

void PrintstringUnitTest()
{
 int i;
 char str[NO_TEST_CASES_PRINT_STRING];
 char expectedString[][10]= {"0","1","BuzzFizz","Buzz","4","Fizz","Buzz","BuzzFizz","8","Buzz","Fizz","BuzzFizz","Buzz","BuzzFizz","14","FizzBuzz"};
 bool flag=true;
 printf("\nGoing to Run the Unit Test for : isPrime (0  to 9)");
 for(i=0;i<NO_TEST_CASES_PRINT_STRING;i++)
 {
    Printstring(i,str);
    if(strcmp(str,expectedString[i]))
    {
        printf("\nTest failed !!!Case:%d : Actual=%s,Expected=%s",i,str,expectedString[i]);
        flag=false;
    }

 }
 if(flag)
 {
    printf("\nTest passed\n\n");
 }
 else printf("\nTest failed!!!\n");

}

#include <stdio.h>

int main(void) {
  // Write your code here
    int a1,a2,a3,a4,b1,b2,b3,b4;
    scanf("%d%d%d%d", &a1,&a2,&a3,&a4);
    scanf("%d%d%d%d", &b1,&b2,&b3,&b4);
    int num1=8*a1+4*a2+2*a3+a4;
    int num2=8*b1+4*b2+2*b3+b4;
    int sum=num1+num2;
    int d1,d2,d3,d4,d5;
    d1=sum/16;
    d2= (sum-(d1*16))/8;
    d3=(sum-(d1*16+d2*8))/4;
    d4=(sum-(d1*16+d2*8+d3*4))/2;
    d5= sum%2;
    if(d1==0)
    {}
    else
      printf("%d",d1);
    printf("%d%d%d%d\n",d2,d3,d4,d5);
  // for XOR
    // it gives 0 is both the respective digits of the two numbers are same, otherwise it gives 1
    if(a1==1)
  {
      if(b1==1)
        printf("0");
    else
      printf("1");
  }
    else if(a1==0)
    {
      if(b1==0)
        printf("0");
      else
        printf("1");
    }
    else
      printf("1");
    if(a2==1)
    {
      if(b2==1)
        printf("0");
      else
        printf("1");
    }
    else if(a2==0)
    {
      if(b2==0)
        printf("0");
      else
       printf("1");
    }
    else
      printf("1");
   if(a3==1)
   {
      if(b3==1)
        printf("0");
     else
      printf("1");
   }
    else if(a3==0)
    {
      if(b3==0)
        printf("0");
      else
        printf("1");
    }
    else
      printf("1");
    if(a4==1)
    {
      if(b4==1)
        printf("0\n");
      else
        printf("1\n");
    }
    else if(a4==0)
    {
      if(b4==0)
        printf("0\n");
      else
    printf("1\n");
    }
    else
      printf("1\n");
    // for AND
    // it gives 1 only when both the digits are 1, otherwise it gives zero
    if(a1==1)
  {
    if(b1==1)
      printf("1");
    else
      printf("0");
  }
  else
    printf("0");
  if(a2==1)
    {
      if(b2==1)
        printf("1");
      else
        printf("0");
    }
  else
    printf("0");
  if(a3==1)
    {
      if(b3==1)
        printf("1");
      else
        printf("0");
    }
  else
    printf("0");
  if(a4==1)
    {
      if(b4==1)
        printf("1\n");
      else
        printf("0\n");
    }
  else
      printf("0\n");
    
    
    // for OR
    //it gives 0 only when both the digits are zero, otherwise it gives 1
    if(a1==0)
    {
      
      if(b1==0)
        printf("0");
      else
      printf("1");
    }
    else
      printf("1");
    if(a2==0)
    {
      if(b2==0)
        printf("0");
      else
      printf("1");
    }
    else
      printf("1");
    if(a3==0)
    {
      if(b3==0)
        printf("0");
      else
      printf("1");
    }
    else
      printf("1");
    if(a4==0)
    {
      if(b4==0)
        printf("0\n");
      else
      printf("1\n");
    }
    else
      printf("1\n");
  
    
  return 0;
}
#include <stdio.h>
#include <math.h>
int d;
int main(void)
{
  
  // Write your code here
  for(int i=1;i>0;i++)
    {
      //Reading the number
      int a;
      scanf("%d",&a);
      // if the number entered is -1, program will stop
      if(a==-1)
        break;
      //Calling bits function which calculates the number of times 1 has come in the bits representation of the number
      printf("(%d,", bits(a));
      //num2 is used to store the number of coprime existing for the number
      int num2;
      d=0;
      if(a!=1)
      {
        for(int j=1;j<=a;j++)
          {
            //Calling gcd function which will check if the numbers are coprime or not
            num2=gcd(a,j);
          }
      }
      else
        num2=0;
      //For mersenne prime, the successor of the number must be a power of 2
      int num3=(a+1);
      int num4=prime(a);
      //Calling the mersenne_prime function to check if the number 
      int n;
      if(num4==1)
      n = mersenne_prime(num3);
      else
        n=0;
      printf("%d,",num2);
      printf("%d)\n", n);
    }
  return 0;
}
int bits(int e)
{
  int d=0;
  double c=  log2((double)e);
  int n = floor(c);
  for(int i=n;i>=0;i--)
    {
      int c=e/pow(2,i);
      e = e - (c*pow(2,i));
      if(c==1)
        d++;
    }
  return d;
}
int gcd(int a, int b)
{
   while((a%b)!=0)
     {
       int temp=a%b;
       a=b;
       b=temp;
     }
  if(b==1)
  d++;
  return d;
}
int prime(int f)
{
  int count=0;
  for(int i=1;i<=f;i++)
    {
      if(f%i==0)
        count++;
    }
  if(count==2)
    return 1;
  else
    return 0;
}
int mersenne_prime(int c)
{
  for(int i=1;i>0;i++)
    {
      if(c%2==1)
      {
        return 0;
        break;
      }
      else
      {
        c=c/2;
      }
      if(c==2)
        break;
    }
  return 1;
}
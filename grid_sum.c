#include <stdio.h>
#include <math.h>
int main(void) {
  
  int a,b,c,d;
  //Taking the cell address
  scanf("%d %d", &a,&b);
  scanf("%d %d", &c,&d);
  int max1,min1,max2,min2;
  int sum=0;
  //finding maximum and minimum of the two rows address input
  if(a>c)
  {
    max1=a;
    min1=c;
  }
  else
  {
    max1=c;
    min1=a;
  }
  //finding maximum and minimum of the two columns address input
  if(b>d)
  {
    max2=b;
    min2=d;
  }
  else
  {
    max2=d;
    min2=b;
  }
  //If the row address is greater than the column address, then in every even row, the first element is the square of the row number
  //And in every odd row, the first element is the successor of the square of the row number of the previous row
  for(int i=min1;i<=max1;i++)
    {
      for(int j=min2;j<=max2;j++)
        {
          if(j<=i)
          {
          if(i%2==0)
          {
            sum+=(i*i)-(j-1);
          }
          else
          {
            sum+=(i-1)*(i-1)+(j);
          }
          }
        }
    }
  //If the column address is greater than the row address, then in every even column, the first element is the successor of the square of the column number of the previous row
  //And in every odd row, the first element is the square of the row number
      for(int j=min2;j<=max2;j++)
    {
      for(int i=min1;i<=max1;i++)
        {
          if(i<j)
          {
          if(j%2!=0)
          {
            sum+=(j*j)-(i-1);
          }
          else
          {
            sum+=(j-1)*(j-1)+(i);
          }
          }
        }
    }
  int sum1=  sum%((int)(pow(10,9)+7));
  printf("%d\n",sum);
  return 0;
}
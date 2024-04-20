#include <stdio.h>
#include <math.h>

int main(void) {
  //Taking the number of queries
  int q;
  scanf("%d",&q);
  int r =sqrt(q);
  for(int i=1;i<=q;i++)
    {
      //Taking the query number
      int q1;
      scanf("%d",&q1);
      if(q1==1)
      {
        int a,b,c,n;
        scanf("%d %d %d", &a,&b,&c);
        for(n=0;n>=0;n++)
          {
            int d = (a*n*n)+(b*n)+c;
            //checking if the expression(d) is prime or not 
            int e=prime(d);
            if(e!=0)
            {
              break;
            }
          }
        printf("%d\n",n);
      }
      if(q1==2)
      {
        long long int a,b,count=0;
        scanf("%lld %lld",&a,&b);
        for(long long int i =floor(pow(2*a,0.5)-1);i<=(ceil(pow(2*b,0.5)));i++)
          {
            long long int j=i*(i+1)/2;
            if(j>=a&&j<=b)
            count++;
          }
        printf("%lld\n", count);
      }
      if(q1==3)
      {
        long long int a,b,count=0;
        scanf("%lld %lld",&a,&b);
        for(long long int i=a;i<=b;i++)
          {
            if(i%2==0||i%3==0||i%5==0)
            {
              count++;
            }
          }
        printf("%lld\n",count);
      }
      if(q1==4)
      {
        long long int a,b,count=0;
        scanf("%lld %lld",&a,&b);
        long long int n[b-a+1];
        for(long long int i=a;i<=b;i++)
          {
            n[i-a]=bits(i);
          }
        long long int max=n[0];
        long long int min=n[0];
        long long int s2=a,s1=a;
        for(long long int i=0;i<=(b-a);i++)
          {
            if(max<n[i])
            {
              max = n[i];
              s2=(i+a);
            }
            if(min>n[i])
            {
              min=n[i];
              s1=(i+a);
            }
          }
        printf("%lld  %lld\n", s1,s2);
      }
    }
  return 0;
}
//Created prime function to check for the number of factors
int prime(int d)
{
  int count=0;
  if(d<=1)
    count=2;
  else{
  for(int i=2;i<=ceil(sqrt(d));i++)
    {
      if(d%i==0)
        count++;
    }
  }
  return count;
}
//Created bits function to check for the number of 1s in the binary representation of the number
int bits(long long int e)
{
  long long int d=0;
  double c=  log2((double)e);
  long long int n = floor(c);
  for(long long int i=n;i>=0;i--)
    {
      long long int c=e/pow(2,i);
      e = e - (c*pow(2,i));
      if(c==1)
        d++;
    }
  return d;
}
#include <stdio.h>
#include <math.h>
int main(void) {
  //Taking the input of number of queries
  int q;
  scanf("%d",&q);
  for(int i=1;i<=q;i++)
    {
      int num;
      scanf("%d",&num);
      //Query 1
      if(num==1)
      {
        int n,k;
        scanf("%d %d",&n,&k);
        int arr[n];
        for(int i=0;i<n;i++)
          scanf("%d",&arr[i]);
        //Sorting the array in decreasing order
        for(int i=0;i<n;i++)
          {
            for(int j=i;j<n;j++)
              {
                if(arr[j]>arr[i])
                {
                  int temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
                }
              }
          }
        int sum=0;
        //adding up the first k elements
        for(int i=0;i<k;i++)
          {
            sum+=arr[i];
          }
        printf("%d\n",sum);
      }
      //Query 2
      if(num==2)
      {
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        int a1[n1],a2[n2],b1[n1],b2[n2];
        for(int i=0;i<n1;i++)
          scanf("%d",&a1[i]);
        for(int i=0;i<n2;i++)
          scanf("%d",&a2[i]);
        int k1=0,p1=0;
        //Finding the index where the smallest element exists
        for(int i=0;i<n1;i++)
          {
            if(a1[0]>a1[i])
            {
              k1=i;
              break;
            }
          }
        //Using another array to store the sorted array(incresing order)
        for(int i=0;i<n1;i++)
          {
            if(k1+i<n1)
            {
              b1[i]=a1[k1+i];
            }
            else
            {
              b1[i]=a1[p1];
              p1++;
            }
          }
        //Finding the index where the smallest element exists
        int k2=0,p2=0;
        for(int i=0;i<n2;i++)
          {
            if(a2[0]>a2[i])
            {
              k2=i;
              break;
            }
          }
        //Using another array to store the sorted array(incresing order)
        for(int i=0;i<n2;i++)
          {
            if(k2+i<n2)
            {
              b2[i]=a2[k2+i];
            }
            else
            {
              b2[i]=a2[p2];
              p2++;
            }
          }
        int count=0;
        int c[n1+n2];
        int m=0;
        //First, printing the values of 2nd array which are less than the 1st array elements and then the 1st array elements and if one of the array ends then print the remaining elements of the other array
        for(int i=0;i<n1;i++)
          {
            for(int j=count;j<n2;j++)
              {
                if(b1[i]>=b2[j])
                {
                  c[m]=b2[j];
                  m++;
                  count=j+1;
                  if(j==(n2-1)&&i<=(n1-1))
                  {
                    for(int k=i;k<n1;k++)
                      {
                        c[m]=b1[k];
                        m++;
                      }
                    j=n2;
                    i=n1;
                    break;
                  }
                }
                else
                {
                  c[m]=b1[i];
                  m++;
                  if(i==(n1-1)&&j<=(n2-1))
                  {
                    for(int k=j;k<n2;k++)
                      {
                      c[m]=b2[k];
                        m++;
                      }
                  }
                  break;
                }
              }
            if(i==n1)
            {
              break;
            }
          }
        for(int i=0;i<n1+n2;i++)
          printf("%d ",c[i]);
        printf("\n");
      }
      //Query 3
      if(num==3)
      {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
          {
            scanf("%d",&arr[i]);
          }
        int max=arr[0];
        for(int i=1;i<n;i++)
          {
            if(max<arr[i])
              max=arr[i];
          }
        //finding the binary representation of the largest number and finding its number of digits to find the number of rows needed
        int bits=binary(max);
        int digits=0;
        
        while(bits!=0)
          {
            bits=bits/10;
            digits++;
          }
        for(int i=0;i<n;i++)
          {
            arr[i]=binary(arr[i]);
          }
        int a[digits][n];
        // printing the corresponding 1st, 2nd, 3rd and so on digits of the binary representation of the elements
        for(int i=digits,m=0;i>0;i--)
          {
            for(int j=0;j<n;j++)
              {
                int n=arr[j]/pow(10,i-1);
                a[m][j]=n;
                arr[j]=arr[j]-(n)*pow(10,i-1);
              }
          m++;
          }
        for(int i=0;i<digits;i++)
          {
            for(int j=0;j<n;j++)
              printf("%d ",a[i][j]);
            printf("\n");
          }
      }
    }
  
  
  return 0;
}
int binary(int num)
{
  double n=(double)log2(num);
  int n1=floor(n);
  int n2=0;
  for(int i=n1;i>=0;i--)
    {
      int n3=num/pow(2,i);
      n2+=n3;
      n2=n2*10;
      num=num-n3*(pow(2,i));
    }
  return n2/10;
}
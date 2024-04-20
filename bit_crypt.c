#include <stdio.h>
#include <math.h>
// function encrypt 
// Input parameters: the number and the key
int Encrypt(int n,int key)
{
  if(n==0||key==0)
    return 0;
  int bit_n=bit(n)%10;
  int bit_key=bit(key)%10;
  //in the binary representation of n/2, the least significant digit of the binary representation of n will get removed
  return (Encrypt(floor(n/2),floor(key/2))*2 + XOR(bit_n,bit_key));
}
//For using XOR operator between the respective binary digits of n and key
int XOR(int a,int b)
{
  if(a==b)
    return 0;
  else
    return 1;
}
//For finding the binary representation of the decimal number
int bit(int e)
{
  int d=0;
  double c=  log2((double)e);
  int n = floor(c);
  for(int i=n;i>=0;i--)
    {
      int c=e/pow(2,i);
      e = e - (c*pow(2,i));
      d+=c;
      d=d*10;
    }
  return d/10;
}
int main() {
    // Take the number and key as input
  int n,key;
  scanf("%d",&n);
  scanf("%d",&key);
    // Encrypt the number
  int e_num=Encrypt(n,key);
    // Print the encrypted value
  printf("%d",e_num);
    return 0;
}

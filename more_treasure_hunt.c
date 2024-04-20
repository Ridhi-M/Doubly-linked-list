#include <stdio.h>

int main(void) {
  // Write your code here
  //Taking the pin and the number of instructions
  int pin,ins,d[4],db1=0,db2=0,d1=0,a,b;
  scanf("%d\n%d",&pin,&ins);
  //sum1[i] represents the distance moved in the y direction
  //sum2[i] represents the distance moved in the x direction
  int sum1[ins],sum2[ins];
  for(int k=0;k<4;k++)
    {
      d[k]=0;
      sum1[k]=0;
      sum2[k]=0;
    }
  d1=pin;
  for(int j=1;j<=4;j++)
    {
      d[0]+=pin%10;
      d[0]*=10;
      if(j<=2)
      {
        db1+=pin%10;
        db1*=10;
      }
      else if(j>2)
      {
        db2+=pin%10;
        db2*=10;
      }
       
      pin=pin/10;
    }
  pin = d1;
  d[0]=d[0]/10;
  d[1]=db2*10 + db1/10;
  d[2]=(pin%1000)*10 + pin/1000;
  d[3]=(pin%10)*1000 + pin/10;
  for(int i=0;i<ins;i++)
    {
      //taking direction and the distance
      int dir,dis;
      scanf("%d %d",&dir,&dis);
      //adding the value of the distance in the particular direction according to every pin(considering all damage types)
      for(int k=0;k<4;k++)
      {
        //n represents north, s represents south, e represents east and w represents west
        int n =d[k]/1000;
        int s =(d[k]%1000)/100;
        int e =(d[k]%100)/10;
        int w =d[k]%10;
        if(dir==n)
        {
            sum1[k]+=dis;
        }
        else if(dir==s)
        {
            sum1[k]-=dis;
        }
        else if(dir==e)
        {
            sum2[k]+=dis;
        }
        else if(dir==w)
        {
            sum2[k]-=dis;
        }
      }
    }
  scanf("%d %d",&a,&b);
  for(int j=0;j<4;j++)
    {
      if(sum1[j]==b&&sum2[j]==a)
      {
        printf("%d\n%d", d[j],j+1);
        break;
      }
    }
  return 0;
}
#include <stdio.h>
#include <math.h>
int main(void) {
  // Write your code here

    //Reading the pin
    int pin;
    scanf("%d", &pin);
    // reading the number of instructions
    int num;
    scanf("%d", &num);
    //n,s,e,w represent the number assigned to the directions
    int n =pin/1000;
    int s =(pin%1000)/100;
    int e =(pin%100)/10;
    int w =pin%10;
    int sum1=0,sum=0;
    int sum2=0;
    for(int i=1;i<=num;i++)
    {
        //Asking for the intruction
        int direc, dist;
        scanf("%d %d", &direc,&dist);
        //sum1 corresponds to displacement in y direction
        //sum2 corresponds to displacement in x direction
        //sum corresponds to total distance travelled
        if(direc==n)
        {
            sum1+=dist;
        }
        else if(direc==s)
        {
            sum1-=dist;
        }
        else if(direc==e)
        {
            sum2+=dist;
        }
        else if(direc==w)
        {
            sum2-=dist;
        }
        sum+=dist;
    }
    printf("%d\n",sum);
    printf("(%d,%d)\n",sum2,sum1);
    if(sum1==0||sum2==0)
    printf("-1\n");
    else
    {
        if(sum1>0&&sum2>0)
        printf("1\n");
        if(sum1>0&&sum2<0)
        printf("2\n");
        if(sum1<0&&sum2<0)
        printf("3\n");
        if(sum1<0&&sum2>0)
        printf("4\n");
    }
    return 0;
}
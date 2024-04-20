#include <stdio.h>

int analyseScore(int chessboard[8][8]){
  // Applying nested loops to print the add the values for white and black positions
  int sb=0,sw=0;
  for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
        {
          int c=chessboard[i][j]%10;
          int a =chessboard[i][j]/10;
          if(c==1)
          {
            if(a==1)
              sw+=1;
            else if(a==2)
              sw+=5;
            else if(a==3)
              sw+=3;
            else if(a==4)
              sw+=3;
            else if(a==5)
              sw+=9;
          }
          else if(c==2)
          {
            if(a==1)
              sb+=1;
            else if(a==2)
              sb+=5;
            else if(a==3)
              sb+=3;
            else if(a==4)
              sb+=3;
            else if(a==5)
              sb+=9;
          }
          
        }
    }
  return (sw-sb);
}
#include <stdio.h>

void printBoard(int chessboard[8][8]){
  // Applying nested loops to print the corresponding letters for white and black positions
  for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
        {
          int c=chessboard[i][j]%10;
          int a =chessboard[i][j]/10;
          if(a==0&&c==0)
            printf(". ");
          else if(c==2)
          {
            if(a==1)
              printf("p ");
            else if(a==2)
              printf("r ");
            else if(a==3)
              printf("n ");
            else if(a==4)
              printf("b ");
            else if(a==5)
              printf("q ");
            else if(a==6)
              printf("k ");
            else
              printf("?");
          }
          else if(c==1)
          {
            if(a==1)
              printf("P ");
            else if(a==2)
              printf("R ");
            else if(a==3)
              printf("N ");
            else if(a==4)
              printf("B ");
            else if(a==5)
              printf("Q ");
            else if(a==6)
              printf("K ");
            else
              printf("?");
          }
          
        }
      printf("\n");
    }
}
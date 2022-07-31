#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

int main(void)
{
	 ///loop
    int scores [TOTAL];
    for  (int i = o; i < TOTAL; i++)
     {
          scores [i} = get_int ("Score: ");
     }
     /// printf(("Average: %f\n", (scores[0) + scores[1] + scores[2] )/ TOTAL)
      printf("average: %f\n", average(toltal,scores) 
 }
  ///criar uma função personalizada para calcular a media
 float average(int length, int array[])
{
     int sum = 0;
     for (int i = 0; i < length; i++)
     {
          sum = sum + array[i]; 
     }
     return sum / (float) length;
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a=-2;

    while (a<0 || a>23)
    {
        printf("What's the height going to be: ");
        a=get_int();
    }
    printf("\n");
    int j=0;
      for (int i=0; i<a;i++)
    {
        j=0;
        while(j<(a-i-1))
        {
            printf(" ");
            j++;
        }
        for (int g=0;g<(a-j);g++)
        {
            printf("#");
        }
        printf("  ");
        for (int h=0;h<(i+1);h++)
        {
            printf("#");
        }


        printf("\n");
    }

}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes do you spend in the shower?: ");
    int minutes = get_int();
    printf("That's %i bottles of water! \n",minutes*12);
}
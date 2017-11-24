#include <cs50.h>
#include <stdio.h>

int CheckDigits(long long int b);
int CheckSubDigits(int b);
int main(void)
{
    printf("Input your credit card number: ");
    long long int a = get_long_long();
    printf("%llu\n",a);
    int dig=CheckDigits(a);
    printf("Digits: %i\n",dig);
    if(dig!=13 && dig!=15 && dig!=16)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        int digitList[dig];
        int idx=0;
        long long int temp=a;
        while (idx<dig)
        {
            digitList[dig-idx-1]=temp%10;
            temp/=10;
            idx++;
        }
        //printf("size: %lu",sizeof(digitList)/sizeof(digitList[0]));

        int underlinedDigitList[dig/2];
        int notUnderlinedDigitList[dig-(dig/2)];

        //wybieranie liczb do listy:
        int tempIdx=0;
        for (idx=dig-2;idx>=0;idx-=2)
        {
            underlinedDigitList[tempIdx]=digitList[idx];
            tempIdx++;
        }
        tempIdx=0;
        if(dig%2==0)
        {
            for(idx=1;idx<dig;idx+=2)
            {
                notUnderlinedDigitList[tempIdx]=digitList[idx];
                tempIdx++;
            }
        }
        else{
            for(idx=0;idx<dig;idx+=2)
            {
                notUnderlinedDigitList[tempIdx]=digitList[idx];
                tempIdx++;
            }
        }
        //multiplying by 2
        for (idx=0;idx<(dig/2);idx++)
        {
            underlinedDigitList[idx]*=2;
            //printf("%i: %i\n",idx,underlinedDigitList[idx]);
        }
        int sum=0;
        for (idx=0;idx<(dig/2);idx++)
        {
            int subDig=CheckSubDigits(underlinedDigitList[idx]);
            int i=0;
            while (i<subDig)
            {
                sum+=underlinedDigitList[idx]%10;
                underlinedDigitList[idx]/=10;
                i++;
            }
        }
        //printf("sum: %i\n",sum);
        for (idx=0;idx<(dig-(dig/2));idx++)
        {
            sum+=notUnderlinedDigitList[idx];
        }
        //printf("sum: %i\n",sum);

        if(dig==15 && digitList[0]==3 && (digitList[1]==4 || digitList[1]==7))
        {
            printf("AMEX\n");
        }
        else if(digitList[0]==4 && (dig==13 || dig==16))
        {
            printf("VISA\n");
        }
        else if(dig==16 && digitList[0]==5 && (digitList[1]==1 || digitList[1]==2 || digitList[1]==3 || digitList[1]==4 || digitList[1]==5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
        return 0;

    }


}


int CheckDigits(long long int b)
{
    int n=0;
    while (b!=0)
    {
        b/=10;
        n++;
    }
    return n;
}

int CheckSubDigits(int b)
{
    int n=0;
    while (b!=0)
    {
        b/=10;
        n++;
    }
    return n;
}
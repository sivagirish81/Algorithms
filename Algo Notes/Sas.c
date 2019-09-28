#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int SAS(char* Num,int l)
{
    if (l==0)
    {
        return 0;
        //printf("HI");
    }
    //printf("HI");
    return 2*SAS(Num,l-1)+atoi(Num[l-1]);
}

int main()
{
    char Num[100];
    scanf("%[^\n]%*c",Num);
    int lnum=strlen(Num);
    printf("%d",lnum);
    printf("Sum of all substring numbers is : %ld",SAS(Num,lnum));
}

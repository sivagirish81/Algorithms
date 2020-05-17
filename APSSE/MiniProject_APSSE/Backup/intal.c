#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intal_add(char* intal1, char* intal2)
{
    int l1 = strlen(intal1) - 1;
    int l2 = strlen(intal2) - 1;
    printf("Length of Intal1 = %d\n",l1);
    printf("Length of Intal2 = %d\n",l2);
    if (l1 == 0)
        return intal2;
    else if (l2 == 0)
        return intal1;
    int carry = 0;  
    int l = (l1 > l2)?l2:l1;                        // Find min of l1 and l2.(Number of digits to be added)
    int t = (l1 > l2)?l1:l2;                        // Size of result (+1)
    char intalSum[t + 2];                              // Fixing the result size
    int p1 = l1 - l;
    int p2 = l2 - l;
    int tsum = 0;
    while (l1 >= p1 && l2 >= p2)
    {
        tsum = (atoi(intal1[l1]) + atoi(intal2[l2]) + carry)%10;
        carry = (atoi(intal1[l1]) + atoi(intal2[l2]) + carry)/10;
        strcat(tsum,intalSum);
    }
    return intalSum;
}

int main()  // Test
{
    char intal1[100] = "1234512345123451234512345";
    char intal2[100] = "543215432154321543215432154321";
    printf("%s",intal_add(intal1,intal2));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap two elements using pointers
static void swap(char* intal1,char* intal2)
{
    char* temp = intal1;
    intal2 = intal1;
    intal1 = temp;
}

// Reverse a string
static char* reverse_string(char* intal)
{
    int intal_len = strlen(intal);
    for (int i = 0;i < intal_len;i++)
        swap(intal[i],intal[intal_len - i - 1]);
    return intal;
}

// Add 2 intals
char* intal_add(const char* intal1, const char* intal2)
{
    int l1 = strlen(intal1);                        // Length of 1st Intal
    int l2 = strlen(intal2);                        // Length of 2nd Intal
    int lmin = (l1 < l2)?l1:l2;
    int lmax = (l1 > l2)?l1:l2;
    if (l1 > l2)
        swap(l1,l2);
    int ldiff = lmax - lmin;
    int carry = 0;
    // Allocate memory to intal sum - maximum size of added result can be lmax + 1 only
    char * intal_sum = (char*)calloc((lmax + 1),sizeof(char));
    int sum = 0;
    char temp;
    int k = 0;
    for (int i = lmin - 1;i >= 0;i--)
    {
        sum = (intal1[i] - '0') + (intal2[i + ldiff] - '0') + carry;
        carry = sum/10;
        temp = (sum%10) + '0';
        intal_sum[k++] = temp;    
    }

    // Find the bigger length number - if it exists and add the remaining digits along with carry
    /*
    char *itemp;
    if (lmax == l1)
        itemp = intal1;
    else
        itemp = intal2;
    */
    for (int i = lmax - lmin - 1;i >= 0;i--)
    {
        sum = (intal2[i] - '0') + carry;
        carry = sum/10;
        temp = (sum%10) + '0';
        intal_sum[k++] = temp;
    }

    // Remaining Carry - If exists append to the end of string
    if (carry)
    {
        temp = carry + '0';
        intal_sum[k++] = temp;
    }

    // Reverse the result for proper storage
    return strrev(intal_sum);
}

int intal_compare(const char* intal1, const char* intal2)
{
    int l1 = strlen(intal1);
    int l2 = strlen(intal2);
    if (l1 > l2)
        return 1;
    else if (l1 < l2)
        return -1;
    for (int i = 0;i < l1;i++)
        if (intal1[i] > intal2[i])
            return 1;
        else if (intal1[i] < intal2[i])
            return -1;
    return 0;
}

static char* intal_differentiator(char* intal1,char* intal2)
{
    int diff = 0;
    int carry = 0;
    int l1 = strlen(intal1);
    int l2 = strlen(intal2);
    int lmin = (l1 < l2)?l1:l2;
    int lmax = (l1 > l2)?l1:l2;
    int ldiff = lmax - lmin;
    char * intal_diff = (char*)calloc((lmax),sizeof(char));
    char temp;
    int k = 0;
    for (int i = lmin - 1;i >= 0;i--)
    {
        diff = (intal1[i] - '0') + (intal2[i + diff] - '0') - carry;
        if (diff < 0)
        {
            diff+=10;
            carry = 1;
        }
        else
            carry = 0;
        temp = diff + '0';
        intal_diff[k++] = temp;
    }
    
    for (int i = lmax - lmin - 1;i >= 0;i--)
    {
        diff = (intal2[i] - '0') - carry;
        if (diff < 0)
        {
            diff+=10;
            carry = 1;
        }
        else
            carry = 0;
        temp = diff + '0';
        intal_diff[k++] = temp;
    }

    return strrev(intal_diff);
}

char* intal_diff(const char* intal1, const char* intal2)
{
    if (intal_compare(intal1,intal2) == 1)
        return intal_differentiator(intal2,intal1);
    else if (intal_compare(intal1,intal2) == -1)
        return intal_differentiator(intal1,intal2);
    else
        return "0";
}

int intal_max(char **arr, int n)
{
    int max_len_till_now = strlen(arr[0]);
    char* max_till_now = arr[0];
    for (int i = 1;i < n;i++)
    {
        if (strlen(arr[i] < max_len_till_now))
            continue;
        else if (strlen(arr[i] > max_len_till_now))
        {
            max_len_till_now = strlen(arr[i]);
            max_till_now = arr[i];
        }
        else
            max_till_now = (intal_compare(max_till_now,arr[i]) == 1)?max_till_now:arr[i];
    }
    return max_till_now;
}

int main()                                                              // Test
{
    char intal1[100] = "1234512345123451234512345";
    char intal2[100] = "543215432154321543215432154321";
    printf("%s\n",intal_add(intal1,intal2));
    printf("%d\n",intal_compare("1234512345123451234512345","1234512345123451234512345"));
    printf("%s\n",intal_diff(intal1,intal2));
}
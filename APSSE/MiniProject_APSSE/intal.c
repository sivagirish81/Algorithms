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

// Remove all leading Zeroes
static char* resize(char* intal)
{
    int l = strlen(intal);
    int zero_count = 0;
    for (int i = 0;i < l;i++)
        if (intal[i] != '0')
            break;
        else if (intal[i] == '0')
            zero_count++;
    if (zero_count == l)
        return "0";
    if (zero_count == 0)
        return intal;
    // printf("Zero_Count : %d\n",zero_count);
    char* res = (char*)calloc((l - zero_count + 1),sizeof(char));
    strncpy(res,intal + zero_count,l - zero_count);
    // res[strlen(res)] = '\0';
    free(intal);
    return res;
}
// Reverse a string
/*
static char* reverse_string(char* intal)
{
    int intal_len = strlen(intal);
    for (int i = 0;i < intal_len;i++)
        swap(intal[i],intal[intal_len - i - 1]);
    return intal;
}
*/
// Add 2 intals
static char* intal_adder(const char* intal1,int l1,const char* intal2,int l2)
{
    // printf("%s\n",intal1);
    // printf("%s\n",intal2);
    int lmin = (l1 < l2)?l1:l2;
    int lmax = (l1 > l2)?l1:l2;
    int ldiff = lmax - lmin;
    int carry = 0;
    // Allocate memory to intal sum - maximum size of added result can be lmax + 1 only
    char * intal_sum = (char*)calloc((lmax + 1),sizeof(char));
    int sum = 0;
    char temp;
    int k = 0;
    for (int i = lmin - 1;i >= 0;i--)
    {
        // printf("%c %c %d\n",intal1[i],intal2[i + ldiff],i + ldiff);
        sum = (intal1[i] - '0') + (intal2[i + ldiff] - '0') + carry;
        carry = sum/10;
        temp = (sum%10) + '0';
        intal_sum[k++] = temp;    
        // printf("%d %c\n",k,temp);
    }

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
    intal_sum[k] = '\0';
    // Debug
    // printf("\n***********************************************************\n");
    // Reverse the result for proper storage
    return resize(strrev(intal_sum));
}

char* intal_add(const char* intal1, const char* intal2)
{
    // Debug
    // printf("\n***********************************************************\n");
    int l1 = strlen(intal1);                        // Length of 1st Intal
    int l2 = strlen(intal2);                        // Length of 2nd Intal
    // printf("%d %d/n",l1,l2);
    if (l1 > l2)
        return intal_adder(intal2,l2,intal1,l1);
    return intal_adder(intal1,l1,intal2,l2);
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

static char* intal_differentiator(const char* intal1,const char* intal2)
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
    // printf("%s\n",intal1);
    // printf("%s\n",intal2);
    for (int i = lmin - 1;i >= 0;i--)
    {
        // printf("%c %c %d\n",intal1[i],intal2[i + ldiff],i + ldiff);
        diff = (intal2[i + ldiff] - '0') - (intal1[i] - '0') - carry;
        // printf("diff : %d\n",diff);
        if (diff < 0)
        {
            diff+=10;
            carry = 1;
        }
        else
            carry = 0;
        temp = diff + '0';
        // printf("Diff : %d\n",diff);
        // printf("temp : %c\n",temp);
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

char* intal_multiply(const char* intal1, const char* intal2)
{
    int l1 = strlen(intal1);
    int l2 = strlen(intal2);
    if (l1 == 0 || l2 == 0)
        return "0";
    char * intal_mul = (char*)calloc((l1 + l2 + 1),sizeof(char));
    int carry;
    int n_mul;
    int t_mul;
    int gpos = 0;
    int cpos;
    for (int i = l1 - 1;i >= 0;i--)
    {
        carry = 0;
        n_mul = intal1[i] - '0';
        cpos = 0;
        for (int j = l2 - 1;j >= 0;j--)
        {
            if (!(intal_mul[gpos + cpos]))
                intal_mul[gpos + cpos] = '0';
            t_mul = n_mul * (intal2[j] - '0') + (intal_mul[gpos + cpos] - '0') + carry;
            carry = t_mul/10;
            intal_mul[gpos + cpos] = (t_mul%10) + '0';
            cpos++;
        }
        if (!(intal_mul[gpos + cpos]))
                intal_mul[gpos + cpos] = '0';
        if (carry > 0)
            intal_mul[gpos + cpos] = ((intal_mul[gpos + cpos] - '0') + carry) + '0';
        gpos++;
    }
    return resize(strrev(intal_mul));
}

static char* intal_div(const char* intal1,const char* intal2)
{
    char* ans = (char*)calloc(strlen(intal1),sizeof(char));
    int i = 0;
    char * t_num = (char*)calloc(strlen(intal2),sizeof(char));
    t_num[i] = '0';
    while (intal_compare(t_num,intal2) < 0)
    {
        t_num[i] = intal1[i];
        i++;
    }
    t_num[i] = '\0';
    // printf("t_num : %s\n",t_num);
    // printf("HI %d\n",intal_diff(t_num,intal2));
    int q;
    int k = 0;
    int l = strlen(intal1);
    while (l > i)
    {
        q = 0;
        printf("Hello %s\n",t_num);
        while (intal_compare(t_num,intal2) > 0)
        {
            t_num = intal_diff(t_num,intal2);
            printf("%s\n",t_num);
            q++;
        }
        t_num[strlen(t_num)] = intal1[i];
        ans[k++] = q + '0';
        i++;
    }
    return ans;
}

// Have to complete
static char* Find_mod(const char* intal1, const char* intal2)
{
    return "1";
}

char* intal_mod(const char* intal1, const char* intal2)
{
    int test = intal_compare(intal1,intal2);
    if (test == -1)
        return intal1;
    else if (test == 0)
        return "0";
    return "1";
}

char* intal_pow(const char* intal1, unsigned int n)
{
    //printf("n = %d\n",n);
    if (n==0)
        return "1";
    char* res = intal_pow(intal1,n/2);
    if (n%2)
        return intal_multiply(intal1,intal_multiply(res,res));
    else
        return intal_multiply(res,res);
}

// Have to complete
char* intal_gcd(const char* intal1, const char* intal2)
{
    return "1";
}

char* intal_fibonacci(unsigned int n)
{
    if (n == 0)
        return "0";
    if (n == 1)
        return "1";
    char* f1 = "1";
    char* f2 = "1";
    char* fibb;
    for (int i = 0;i < n - 2;i++)
    {
        fibb = intal_add(f1,f2);
        //printf("F1 : %s F2 : %s Fibb : %s\n",f1,f2,fibb);
        f1 = f2;
        f2 = fibb;
    }
    return fibb;
}
static char* tostring(int n)
{
    int temp = n;
    int len = 0;
    while (temp)
    {
        temp/=10;
        len++;
    }
    char * str = (char*)calloc((len + 1),sizeof(char));
    int k = 0;
    while (n)
    {
        str[k++] = (n % 10) + '0';
        n = n / 10;
    }
    str[len] = '\0';
    return strrev(str);
}

char* intal_factorial(unsigned int n)
{
    char *res = (char*)calloc(1000,sizeof(char));
    res[0] = '1';
    // printf(res);
    char* num;
    for (int i = 2;i <= n;i++)
    {
        num = tostring(i);
        // printf("%s\n",num);
        strcpy(res,intal_multiply(res,num));
        // printf("%s\n",res);
    }
    realloc(res,strlen(res));
    return res;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    char** bincoeff = (char**)calloc(k + 1,sizeof(char*));
    bincoeff[0] = "1";
    for (int i = 1;i <= n;i++)
    {
        for (int j = (i < k)?i:k;j > 0;j--)
        {
            if (!(bincoeff[j]))
                bincoeff[j] = "0";
            bincoeff[j] = intal_add(bincoeff[j],bincoeff[j - 1]);
            // printf("%d %d Bincoeff : %s\n",i,j,bincoeff[j]);
        }
    }
    // printf("%s\n",bincoeff[k]);
    return bincoeff[k];
}

int intal_max(char **arr, int n)
{
    int max_len_till_now = strlen(arr[0]);
    char* max_till_now = arr[0];
    int maxindex = 0;
    for (int i = 1;i < n;i++)
    {
        if (strlen(arr[i]) < max_len_till_now)
            continue;
        else if (strlen(arr[i]) > max_len_till_now)
        {
            max_len_till_now = strlen(arr[i]);
            max_till_now = arr[i];
            maxindex = i;
        }
        else
            max_till_now = (intal_compare(max_till_now,arr[i]) == 1)?max_till_now:arr[i];
    }
    return maxindex;
}

int intal_min(char **arr, int n)
{
    int min_len_till_now = strlen(arr[0]);
    char* min_till_now = arr[0];
    int minindex = 0;
    for (int i = 1;i < n;i++)
    {
        if (strlen(arr[i]) > min_len_till_now)
            continue;
        else if (strlen(arr[i]) < min_len_till_now)
        {
            min_len_till_now = strlen(arr[i]);
            min_till_now = arr[i];
            minindex = i;
        }
        else
            min_till_now = (intal_compare(min_till_now,arr[i]) == 1)?min_till_now:arr[i];
    }
    return minindex;
}

int intal_search(char **arr, int n, const char* key)
{
    for (int i = 0;i < n;i++)
        if (intal_compare(arr[i],key) == 0)
            return i;
    return -1;
}

static void intal_merge(char **arr, int left,int mid,int right)
{
    int i,j,k;
    int l1 = mid - left + 1;
    int l2 = right - mid;
    // printf("L1 : %d L2 : %d\n",l1,l2);
    char **L1 = (char**) calloc(l1,sizeof(char*));
	for(i = 0; i < l1; i++) {
		L1[i] = arr[left + i];
        // printf("L1[%d] : %s\n",i,L1[i]);
	}
    char **L2 = (char**) calloc(l2,sizeof(char*));
	for(j = 0; j < l2; j++) {
		L2[j] = arr[mid + 1 + j];
        // printf("L2[%d] : %s\n",j,L2[j]);
	}
    i = 0;
    j = 0;
    k = left;
    int temp;
    while (i < l1 && j < l2)
    {
        temp = intal_compare(L1[i],L2[j]);
        if (temp == -1 || temp == 0)
        {
            arr[k++] = L1[i];
            i++;
        }
        else
        {
            arr[k++] = L2[j];
            j++;
        }
    }

     while (i < l1) 
    { 
        arr[k] = L1[i]; 
        i++; 
        k++; 
    } 

    while (j < l2) 
    { 
        arr[k] = L2[j]; 
        j++; 
        k++; 
    } 
}

static void intal_merge_sort(char **arr, int left,int right)
{
    if (left < right)
    {
        int mid = left + (right - left)/2;
        intal_merge_sort(arr,left,mid);
        intal_merge_sort(arr,mid + 1,right);
        intal_merge(arr,left,mid,right);
    }
}

void intal_sort(char **arr, int n)
{
    intal_merge_sort(arr,0,n - 1);
}

static int intal_binsearch_util(char **arr, int start,int end,const char* key)
{
    int mid;
    int temp;
    while (start < end)
    {
        mid = start + (end - start)/2;
        temp = intal_compare(arr[mid],key);
        if (temp == 0)
            return mid;
        else if (temp > 0)
            end = mid;
        else
            start = mid + 1;
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    return intal_binsearch_util(arr,0,n-1,key);
}

// Need to debug
char* coin_row_problem(char **arr, int n)
{
    if (n == 0)
        return "0";
    if (n == 1)
        return arr[0];
    char * DP0 = (char*)calloc(1000,sizeof(char));
    DP0[0] = '0';
    char * DP1 = (char*)calloc(1000,sizeof(char));
    strcpy(DP1,arr[0]);
    char * DPN = (char*)calloc(1000,sizeof(char));
    char * temp;
    for (int i = 2;i <= n;i++)
    {
        // printf("%s %s %s %s\n",DP0,DP1,DPN,arr[i - 1]);
        temp = intal_add(DP0,arr[i - 1]);
        // printf("temp : %s\n",temp);
        if (intal_compare(temp,DP1) == 1)
            DPN = temp;
        else
            DPN = DP1;
        strcpy(DP0,DP1);
        strcpy(DP1,DPN);
        
    }
    // printf(DPN);
    return DPN;
}

/*
int main()                                                              // Test
{
    char intal1[100] = "1234512345123451234512345";
    char intal2[100] = "543215432154321543215432154321";
    // printf("%s\n",intal_add("10","5"));
    // printf("%s\n",intal_add("233","377"));
    // printf("%d\n",intal_compare("1234512345123451234512345","1234512345123451234512345"));
    // printf("%s\n",intal_diff("35","7"));
    // printf("%s\n",intal_multiply("3","5432154321543215432154321"));
    // printf("%s\n",intal_fibonacci(1000));
    // printf("%s\n",resize("000398"));
    // printf("%s\n",intal_factorial(30));
    // printf("%s\n",intal_pow("2", 3000));

    int n = 12;
    char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");
	strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");

    // printf("%d\n",intal_max(a, n));
    // printf("%d\n",intal_min(a, n));
    // printf("%d\n",intal_search(a, n, a[7]));
    // intal_sort(a, 12);
	// printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	// for (int i = 0; i < n; i++) {
	// 	printf("%s\n", a[i]);
	// }
	// printf("\n");
    // printf("%d\n",intal_binsearch(a, n, "3"));
    // printf("%s\n",intal_diff("35","7"));
    // printf("%s\n",intal_div("35","7"));
    //char *b[7] = {"10", "2", "4", "6", "3", "9", "5"};
    //printf("%s\n",coin_row_problem(b, 7));
    //printf("%s\n",intal_bincoeff(10, 8));
    //printf("%s\n",intal_bincoeff(10, 2));
    // printf("%s\n",intal_bincoeff(1000,10));

}
*/
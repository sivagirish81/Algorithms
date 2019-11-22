#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std; 
  
// Structure to store information of a suffix 
struct suffix 
{ 
    int index; 
    char *suff; 
}; 
  
// A comparison function used by sort() to compare two suffixes 
int cmp(struct suffix a, struct suffix b) 
{ 
    int t= strcmp(a.suff, b.suff);
    cout << t <<endl;
    return strcmp(a.suff, b.suff) < 0? 1 : 0; 
} 
  
// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
int *buildSuffixArray(char *txt, int n) 
{ 
    // A structure to store suffixes and their indexes 
    struct suffix suffixes[n]; 
  
    // Store suffixes and their indexes in an array of structures. 
    // The structure is needed to sort the suffixes alphabatically 
    // and maintain their old indexes while sorting 
    for (int i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].suff = (txt+i);
        //cout << txt + i ; 
    } 
  
    // Sort the suffixes using the comparison function 
    // defined above. 
    sort(suffixes, suffixes+n, cmp); 
  
    // Store indexes of all sorted suffixes in the suffix array 
    int *suffixArr = new int[n]; 
    for (int i = 0; i < n; i++) 
        suffixArr[i] = suffixes[i].index; 
  
    // Return the suffix array 
    return  suffixArr; 
} 
  
// A utility function to print an array of given size 
void printArr(int arr[], int n) 
{ 
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void search(char *pat, char *txt, int *suffArr, int n) 
{ 
    int m = strlen(pat);  // get length of pattern, needed for strncmp() 
  
    // Do simple binary search for the pat in txt using the 
    // built suffix array 
    int l = 0, r = n-1;  // Initilize left and right indexes 
    while (l <= r) 
    { 
        // See if 'pat' is prefix of middle suffix in suffix array 
        int mid = l + (r - l)/2; 
        cout << mid <<endl;
        int res = strncmp(pat, txt+suffArr[mid], m); 
        cout <<"res = " << res;
  
        // If match found at the middle, print it and return 
        if (res == 0) 
        { 
            cout << "Pattern found at index " << suffArr[mid]; 
            return; 
        } 
  
        // Move to left half if pattern is alphabtically less than 
        // the mid suffix 
        if (res < 0) r = mid - 1; 
  
        // Otherwise move to right half 
        else l = mid + 1; 
    } 
  
    // We reach here if return statement in loop is not executed 
    cout << "Pattern not found"; 
}
// Driver program to test above functions 
int main() 
{ 
    char txt[] = "banana"; 
    int n = strlen(txt); 
    char pat[] = "nan";
    int *suffixArr = buildSuffixArray(txt,  n); 
    cout << "Following is suffix array for " << txt << endl; 
    printArr(suffixArr, n); 

    search(pat, txt, suffixArr, n);
    return 0; 
} 



  /*
   char string1[A.suffix.size()];
   char string2[B.suffix.size()];
   strcpy(string1, A.suffix.c_str());
   strcpy(string2, B.suffix.c_str());
   int t = strcmp(string1,string2);
   */
   //cout << string1 << string2 << "t =  " << t << endl;
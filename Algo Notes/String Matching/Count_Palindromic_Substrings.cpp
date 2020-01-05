#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {

ll t;
cin >> t;
while(t--)
{
   ll n;
   cin >> n;
   string s;
   cin >> s;
   
   ll count = 0;
   //odd palindromes
   
   for(ll i = 1; i < n-1; ++i)
   {
       ll left = i-1;
       ll right = i+1;
       while(left >= 0 && right < n && s[left]==s[right])
       {
           ++count;
           --left;
           ++right;
       }
   }
   
   //even palindromes
 
 
   for(ll i = 1; i < n; ++i)   //i-1 and i form a pair
   {
       
       ll left = i-1;
       ll right = i;
       while(left >= 0 && right < n && s[left]==s[right])
       {
           ++count;
           --left;
           ++right;
       }
   }
   
   cout << count << '\n';  
   
}

return 0;
}


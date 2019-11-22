#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAX_DOC_NO = 30;
const int MAX_DOC_SIZE = 3000;
const int MAX_QUERY_NO = 1000;
const int MAX_QUERY_SIZE = 300;

int cmpString(const void *str1, const void *str2)
{
    return strcmp((const char *)*(char **)str1, (const char *)*(char **)str2);
}


int findInDoc(char* document,char* pattern)
{
    int docLength = strlen(document);
    int patLength = strlen(pattern);

    if(docLength < patLength)
    {
        return -1;
    }

    for(int i=0;i<docLength-patLength+1;i++)
    {
        int count = 0;
        for(int j=0;j<patLength;j++)
        {
            if(document[i+j] != pattern[j])
            {
                break;
            }

            count += 1;
        }

        if(count == patLength)
        {
            return i;
        }
    }

    return -1;
}


void printAllFullMatches(char** documentArray,int docsNo,char* pattern)
{
    vector< pair <int,int> > vect;

    for(int i=0;i<docsNo;i++)
    {
        char* current = documentArray[i];
        int res = findInDoc(current,pattern);

        if(res != -1)
        {
            vect.push_back( make_pair(i,res));
        } 

    }

    printf("%s\n",pattern);
    for(int i=0;i<vect.size();i++)
    {
        cout << vect[i].first << " " << vect[i].second << "\n"; 
    }
}

int getNoMatched(char* str1,char* str2)
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    int index;
    for(index=0;(index < length1) && (index < length2);index++)
    {
        if(str1[index] != str2[index])
        {
            break;
        }
    }

    return index;
}

char* getLCS(char* document,char* pattern)
{
    int doclength = strlen(document);
    int patLength = strlen(pattern);

    char** combinedSuffix = (char**)malloc((doclength+patLength)*sizeof(char*));
    char* combinedText = (char*)malloc((doclength+patLength)*sizeof(char));

    // combinedText = strcat(document,pattern);


    // printf("-----Entered Here -------------\n");

    for(int i=0;i<doclength;i++)
    {
        combinedText[i] = document[i];
    }

    for(int i=0;i<(patLength);i++)
    {
        combinedText[doclength+i] = pattern[i];
    }

    // printf("The combined string is %s",combinedText);


    for(int i=0;i<(doclength+patLength);i++)
    {
        combinedSuffix[i] = &(combinedText[i]);
    }

    // for(int i=0;i<(doclength+patLength);i++)
    // {
    //     printf("%s\n",combinedSuffix[i]);
    // }

    qsort(combinedSuffix,doclength+patLength,sizeof(char *),cmpString);

    // printf("After sorting\n");
    // for(int i=0;i<(doclength+patLength);i++)
    // {
    //     printf("%s\n",combinedSuffix[i]);
    // }

    int maxLpsLen = 0;
    int maxIndex = -1;
    int currLength;

    for(int i=0;i<(doclength+patLength-1);i++)
    {
        if(( (combinedSuffix[i]-combinedText) < doclength) && ((combinedSuffix[i+1]-combinedText) < doclength) )
        {
            // Both belong to the document
            continue;
        }
        else if(((combinedSuffix[i]-combinedText) >= doclength) && ((combinedSuffix[i+1]-combinedText) >= doclength))
        {
            // Both belong to the pattern
            continue;
        }

        else
        {
            currLength = getNoMatched(combinedSuffix[i],combinedSuffix[i+1]);

            if(currLength > maxLpsLen)
            {
                maxLpsLen = currLength;
                maxIndex = i;
            }
        }
    }

    if(maxIndex == -1)
    {
        char* empty = (char*)malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    // printf("MaxIndex : %d   maxLpsLen : %d   String %s\n",maxIndex,maxLpsLen,combinedSuffix[maxIndex]);
    
    int index = 0;
    char* resString = (char*)malloc((maxLpsLen+1)*sizeof(char));
    for(int i=0;i<maxLpsLen;i++)
    {
        resString[i] = combinedSuffix[maxIndex][i];
        // printf("%c\n",resString[i]);
    }
    resString[maxLpsLen] = '\0';

    // printf("The LCS is %s %d",resString,strlen(resString));

    // free(combinedText);
    // free(combinedSuffix);

    return resString;



}

void printLongestMatch(char** documentArray,int docsNo,char* pattern)
{
    

    char* current;
    char* maxMatch;

    int maxlength = 0;
    int currentLength = 0;
    int maxDocIndex = -1;
    for(int i=0;i<docsNo;i++)
    {
        current  = getLCS(documentArray[i],pattern);
        currentLength = strlen(current); 
        if(maxlength < currentLength)
        {
            maxlength = currentLength;
            maxMatch = current;
            maxDocIndex = i;
        }
    }


    if(maxDocIndex != -1)
    {
        int index =  findInDoc(documentArray[maxDocIndex],maxMatch);
        printf("%s\n",maxMatch);
        printf("%d %d\n", maxDocIndex,index);
    }
    else
    {
        printf("%d\n",-1);
    }
       

}


void buildSuffixArray(char** documentArray,int docsNo,char** patternArray,int patNo)
{
    
    
    int outerFlag = 0;
    for(int i=0;i<patNo;i++)
    {
        int found = 0;
        int res;
        for(int j=0;j<docsNo;j++)
        {
            res = findInDoc(documentArray[j],patternArray[i]);

            if(res >= 0)
            {
                found = 1; 
                break;
            }
        }

        
        // complete match exists
        if(found == 1)
        {
            printAllFullMatches(documentArray,docsNo,patternArray[i]);
        }

        // Partial match or no match
        if(found == 0)
        {
            printLongestMatch(documentArray,docsNo,patternArray[i]);
        }

    }


    

    
}


void search(char *pat,int** suffixMatrix,int docsNo) 
{ 
    
    for(int i=0;i<docsNo;i++){}
 
}




int main()
{
    char *documentArray[MAX_DOC_NO];
    char *patternArray[MAX_QUERY_NO];
    int docsNo;
    int queryNo;
    scanf("%d",&docsNo);
    
    char str[20];
    
    
    // char** documentArray =(char**)malloc(sizeof(char*)*docsNo);

    for(int i=0;i<docsNo;i++)
    {
        documentArray[i] = (char*)malloc(sizeof(char)*(MAX_DOC_SIZE));
        scanf("%s", documentArray[i]);
    }
    

    scanf("%d",&queryNo);

    for(int i=0;i<queryNo;i++)
    {
        patternArray[i] = (char*)malloc(sizeof(char)*(MAX_QUERY_SIZE));
        scanf("%s", patternArray[i]);
    }

    // buildSuffixArray(documentArray,docsNo);

    // printf("The string is %s",str);
    char pat[10] = "kcd\0";
    

    // printf("%d",strlen(pat));

    // printLongestMatch(documentArray, docsNo,pat);
    // printf("%d",findInDoc(documentArray[0],documentArray[1]));
    buildSuffixArray(documentArray,docsNo,patternArray,queryNo);
    return 0;
}
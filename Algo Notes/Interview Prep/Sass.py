#code

def Sass(arr):
    arr.sort()
    c=0
    #print(arr[0],arr[1],sep=" ")
    for i in range(1,len(arr)):
        if (arr[i]!=arr[i-1]):
            print(arr[i-1],end=" ")
            c+=1
        if (c==2):
            return 
    print(-1,end=" ")

T=int(input())
for i in range(T):
    N=int(input())
    arr=[int(i) for i in input().split()]
    Sass(arr)
    print()
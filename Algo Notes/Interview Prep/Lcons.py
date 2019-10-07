def Lcons(arr,N):
    arr.sort()
    #print(arr)
    temp=[]
    for i in range(1,N):
        temp.append(arr[i]-arr[i-1])
    #print(temp)
    maxi=0
    c=0
    flag=0
    i=0
    while (i<(N-1)):
        if (temp[i]==0):
            i+=1
        elif (temp[i]!=1):
            c=0
            i+=1
        else:
            c+=1
            i+=1
            maxi=max(maxi,c)
    return maxi+1
        
T=int(input())
for i in range(T):
    N=int(input())
    arr=[int(i) for i in input().split()]
    print(Lcons(arr,N))
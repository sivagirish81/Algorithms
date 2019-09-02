
import math
def reducer(arr,K):
    diff=len(arr)%K
    if (diff>0):
        arr=[sum(arr[K*i:K*(i+1)]) for i in range(0,math.floor(len(arr)/K))]+arr[(len(arr)-diff):]
    else:
        arr=[sum(arr[K*i:K*(i+1)]) for i in range(0,math.floor(len(arr)/K))]
    #print(arr)
    if (len(arr)<K):
        return arr
    elif (len(arr)>K):
        return reducer(arr,K)
    else:
        return [].append(sum(arr))
    
def ksum(arr,N,k):
    if (N==K):
        return list(sum(arr))
    if (len(arr)<k):
        return arr
    ks=reducer(arr,K)
    return ks


T=int(input())
for i in range(T):
    NK=input().split()
    N=int(NK[0])
    K=int(NK[1])
    arr=[int(i) for i in input().split()]
    for i in ksum(arr,N,K):
        print(i,end=" ")

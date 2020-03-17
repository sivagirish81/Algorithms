
def hack(S):
    if (S=="+"):
        return "12"
    elif (S=="-"):
        return "21"
    arr=[i for i in range(1,len(S)+2)]
    #print(arr)
    sp=[]
    for i in range(len(S),-1,-1):
        #print(S[i-1])
        if (S[i-1]=='-'):
            #print("hi")
            arr[i]-=1
            arr[i-1]+=1
    return "".join([str(i) for i in arr])

T=int(input())
for i in range(T):
    S=input()
    #print(S)
    print(hack(S))
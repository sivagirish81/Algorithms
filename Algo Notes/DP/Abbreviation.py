
def NR(a,b,n,m):
    if (n<m):
        return "NO"
    if (m==-1):
        return "YES"
    if (a[n].upper()==b[m]):
        return NR(a,b,n-1,m-1)
    return NR(a,b,n-1,m)

q=int(input())
for i in range(q):
    a=input()
    b=input()
    print(NR(a,b,len(a)-1,len(b)-1))
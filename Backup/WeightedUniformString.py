

def computeWeight(s):
    s=s.lower()
    sum=0
    for i in s:
        sum+=ord(i)-65
    return sum

# Complete the weightedUniformStrings function below.
def weightedUniformStrings(s, queries):
    yesno=[]
    print(queries)
    for j in queries: 
        for i in range(len(s)-j):
            k=1
            r=computeWeight(s[i:i+k])
            while (computeWeight(s[i:i+k])!=j):
                print("SSSS",computeWeight(s[i:i+k]))
                k+=1
                if (computeWeight(s[i:i+k])==j):
                    break
            if (computeWeight(s[i:i+k])==j):
                yesno.append("Yes")
        yesno.append("No")
    return yesno


if __name__ == '__main__':

    s = input()

    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input())
        queries.append(queries_item)

    result = weightedUniformStrings(s, queries)

    print(result)

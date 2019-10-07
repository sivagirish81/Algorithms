
from collections import Counter

# Complete the pangrams function below.
def pangrams(s):
    s=s.lower()
    s.replace(" ","")
    for i in s:
        if (i.isalpha()==0):
            s.replace(i,"")

    p=Counter(s)
    print(p)
    print(len(p))
    if (len(p)==26):
        return "pangram"
    else:
        return "not pangram"


if __name__ == '__main__':

    s = input()

    result = pangrams(s)
    print(result)

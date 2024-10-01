n = int(input())


def even(k: int, i: int) -> str:
    if i % 2 == 1:
        if k % 4 == 1 or k % 4 == 2:
            return "NO"
        return "YES"
    if k % 4 == 0 or k % 4 == 1:
        return "YES"
    return "NO"


for i in range(n):
    i, k = input().split()
    print(even(int(k), int(i)))


"""
5
1 1
2 1
2 2
3 2
4 4

"""

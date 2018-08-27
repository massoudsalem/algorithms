# This insertion sort algorithm is written by Moh.Massoud in 25Jan18
# with help of CLRS book
def insertion_sort(A):
    for i in range(1, len(A)):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j-=1
        A[j + 1] = key


list = [2, 5, 3, 4, 1]
insertion_sort(list)
for x in list:
    print(x, end=' ')

print("hello world")

# =============================================
# Generate random list for sorting
# =============================================

import random

def generate_random_list(n):
    return [random.randint(1, 10000) for _ in range(n)]


# =============================================
# quicksort
# =============================================

def qsort(arr):
    less = []
    equal = []
    greater = []

    if len(arr) > 1:
        pivot = arr[0]
        for x in arr:
            if x < pivot:
                less.append(x)
            elif x == pivot:
                equal.append(x)
            elif x > pivot:
                greater.append(x)
        return qsort(less) + equal + qsort(greater)
    
    else:
        return arr

def partition(arr, low, high):
    pivot = arr[high]

    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            (arr[i], arr[j]) = (arr[j], arr[i])

    (arr[i+1], arr[high]) = (arr[high], arr[i+1])

    return i+1

def qsort2(arr, low, high):
    if low < high:
        p = partition(arr, low, high)

        qsort2(arr, low, p-1)
        qsort2(arr, p+1, high)


# ============================================
# Merge Sort
# ============================================

def merge(arr, l, m, r):
    # create left and right buckets
    lBucket = []
    rBucket = []

    for i in range(l, m):
        lBucket.append(i)
    for i in range(m+1, r):
        rBucket.append(i)

    while (lBucket and rBucket):
        if (lBucket[0] < rBucket[0]):
            



def mergeSort(arr, l, r):
    m = len(arr)/2

    mergeSort(arr, l, m)
    mergeSort(arr, m+1, r)
    merge(arr, l, m, r)

    return

    

# ============================================
# Driver code
# ============================================

x = generate_random_list(100)
y = x
x = sorted(x)

y = mergeSort(y)

print(x == y)
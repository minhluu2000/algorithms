import random as rd
import time


def generator(size):
    return [rd.randrange(0, 10) for i in range(size)]

def bubble_sort(A):
    for i in range(len(A)):
        for j in range(len(A) - i - 1):
            if (A[j] > A[j + 1]):
                A[j], A[j + 1] = A[j + 1], A[j]

def counting_sort(A):
    cat = [0]*10
    sorted = [0]*len(A)
    for num in A:
        cat[num] += 1
    for i in range(1, len(cat)):
        cat[i] += cat[i - 1]
    for i in range(len(A)):
        sorted[cat[A[i]] - 1] = A[i]
        cat[A[i]] -= 1
    return sorted


if __name__ == "__main__":
    A = generator(10000)
    # print(A)
    start_time = time.time()
    bubble_sort(A)
    print("Bubble sort: --- %s seconds ---" % (time.time() - start_time))
    start_time = time.time()
    A = counting_sort(A)
    print("Counting sort: --- %s seconds ---" % (time.time() - start_time))
    with open("sorted.txt", "w") as f:
        for i in A:
            f.write(str(i) + "\n")
    # print(A)
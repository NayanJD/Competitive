import heapq


class Solution:
    # Heapify function to maintain heap property.
    def heapify(self, arr, n, i):
        # code here
        lci = 2 * i + 1
        rci = 2 * i + 2

        if lci >= n and rci >= n:
            return

        largest_index = i
        if lci < n and arr[lci] > arr[largest_index]:
            largest_index = lci

        if rci < n and arr[rci] > arr[largest_index]:
            largest_index = rci

        if largest_index != i:
            arr[i], arr[largest_index] = arr[largest_index], arr[i]

            self.heapify(arr, n, largest_index)

    # Function to build a Heap from array.
    def buildHeap(self, arr, n):
        # code here
        for i in range(n // 2, -1, -1):
            self.heapify(arr, n, i)

    # Function to sort an array using Heap Sort.
    def HeapSort(self, arr, n):
        # code here
        self.buildHeap(arr, n)

        while n > 0:
            arr[0], arr[n - 1] = arr[n - 1], arr[0]

            self.heapify(arr, n - 1, 0)

            n -= 1


if __name__ == "__main__":
    arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

    # Solution().HeapSort(arr, 10)
    heapq.heapify(arr)

    print(arr)
import heapq
array = [1,4,8,2,5,3,11,9]

# heapq always implements MinHeaps
# To make MaxHeaps, Push a negated array (array = array*-1) and while popping
# Multiply by -1 again

minHeap = []
for num in array:
    heapq.heappush(minHeap, num)
print(f"Min Heap : {minHeap}")

# Implementing a MaxHeap
maxHeap = []
for num in array:
    heapq.heappush(maxHeap, -num)
print(f"Max Heap : {maxHeap}") #Ignore the '-' sign and you have a Max Heap

# To print without the '-' sign
import numpy as np
print(f"Max Heap : {list(np.array(maxHeap)*-1)}")



https://vjudge.net/problem/POJ-1456

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int profit;
  int deadline;
} Product;

typedef struct {
  Product *elements;
  size_t size;
} Heap;

void heapifyUp(Heap *heap, size_t index) {
  while (index > 0) {
    size_t parent = (index - 1) / 2;
    if (heap->elements[index].profit > heap->elements[parent].profit) {
      Product temp = heap->elements[index];
      heap->elements[index] = heap->elements[parent];
      heap->elements[parent] = temp;
      index = parent;
    } else {
      break;
    }
  }
}

void sort(Product *products, int n, int (*compare)(const void *, const void *)) {
  for (size_t i = 1; i < n; i++) {
    size_t j = i;
    while (j > 0 && compare(&products[j], &products[j - 1]) < 0) {
      Product temp = products[j];
      products[j] = products[j - 1];
      products[j - 1] = temp;
      j--;
    }
  }
}

void heapifyDown(Heap *heap, size_t index) {
  while (index < heap->size) {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    size_t largest = index;

    if (left < heap->size &&
        heap->elements[left].profit > heap->elements[largest].profit) {
      largest = left;
    }

    if (right < heap->size &&
        heap->elements[right].profit > heap->elements[largest].profit) {
      largest = right;
    }

    if (largest != index) {
      Product temp = heap->elements[index];
      heap->elements[index] = heap->elements[largest];
      heap->elements[largest] = temp;
      index = largest;
    } else {
      break;
    }
  }
}

Product extractMin(Heap *heap) {
  Product min = heap->elements[0];
  heap->elements[0] = heap->elements[heap->size - 1];
  heap->size--;
  heapifyDown(heap, 0);
  return min;
}

Heap *createHeap(size_t capacity) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->elements = (Product *)malloc(capacity * sizeof(Product));
  heap->size = 0;
  return heap;
}

int compare(const void *a, const void *b) {
  return ((Product *)a)->deadline - ((Product *)b)->deadline;
}

int optimalProfit(Product *products, size_t n) {
    // Create a min-heap
    Heap *minHeap = createHeap(n);
    
    sort(products, n, compare);

    int maxProfit = 0;
    int currentTime = 0;

    for (size_t i = 0; i < n; i++) {

        if (products[i].deadline == minHeap->size) {
            if (products[i].profit > minHeap->elements[0].profit) {
                minHeap->elements[0] = products[i];
                heapifyDown(minHeap, 0);
            }
        }
        if (products[i].deadline > minHeap->size) {
            minHeap->elements[minHeap->size] = products[i];
            heapifyUp(minHeap, minHeap->size);
            minHeap->size++;
        }
    }

    while (minHeap->size > 0) {
        Product currentProduct = extractMin(minHeap);
        // log currentProduct.profit
        // printf("%d\n", currentProduct.profit);
        maxProfit += currentProduct.profit;
    }

    free(minHeap->elements);
    free(minHeap);

    return maxProfit;
}

/**
Input
A set of products starts with an integer 0 <= n <= 10000, which is the number of products in the set, and continues with n pairs pi di of integers, 1 <= pi <= 10000 and 1 <= di <= 10000, that designate the profit and the selling deadline of the i-th product. White spaces can occur freely in input. Input data terminate with an end of file and are guaranteed correct.
Output
For each set of products, the program prints on the standard output the profit of an optimal selling schedule for the set. Each result is printed from the beginning of a separate line.

input example
4  50 2  10 1   20 2   30 1

7  20 1   2 1   10 3  100 2   8 2
   5 20  50 10

Output

80
185

*/
int main() {

    // Product *products = (Product *)malloc(4 * sizeof(Product));
    // Product p1 = {50, 2};
    // Product p2 = {10, 1};
    // Product p3 = {20, 2};
    // Product p4 = {30, 1};
    // products[0] = p1;
    // products[1] = p2;
    // products[2] = p3;
    // products[3] = p4;
    // printf("%d\n", optimalProfit(products, 4));


    int n;
    while (scanf("%d", &n) != EOF) {
        Product *products = (Product *)malloc(n * sizeof(Product));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &products[i].profit, &products[i].deadline);
        }
        printf("%d\n", optimalProfit(products, n));
        free(products);
    }
  return 0;
}


```


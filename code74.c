#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int heap[MAX];
int size = 0;
int k;

/* swap function */
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* heapify up */
void heapifyUp(int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(heap[parent] > heap[i])
        {
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

/* heapify down */
void heapifyDown(int i)
{
    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

/* add new value and return kth largest */
int add(int val)
{
    if(size < k)
    {
        heap[size] = val;
        heapifyUp(size);
        size++;
    }
    else if(val > heap[0])
    {
        heap[0] = val;
        heapifyDown(0);
    }

    return heap[0];
}

int main()
{
    int n, val;

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter number of initial elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &val);
        add(val);
    }

    int q;
    printf("Enter number of add operations: ");
    scanf("%d", &q);

    printf("Enter values to add:\n");
    for(int i=0;i<q;i++)
    {
        scanf("%d", &val);
        printf("%d\n", add(val));
    }

    return 0;
}
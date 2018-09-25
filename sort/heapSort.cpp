#include "heapSort.hpp"

#define PARENT(i) (i / 2)
#define LEFT(i) (2 * i)
#define RIGHT(i) ((2 * i) + 1)

static void maxHeapify(std::vector<int> &data, std::size_t i, std::size_t limit)
{
    std::size_t j = i - 1;
    bool check = true;
    while (check)
    {
        std::size_t left = LEFT(i) - 1;
        std::size_t right = RIGHT(i) - 1;
        std::size_t max = j;
        if (left < limit && data[left] > data[max])
        {
            max = left;
        }
        if (right < limit && data[right] > data[max])
        {
            max = right;
        }
        if (max != j)
        {
            int save = data[j];
            data[j] = data[max];
            data[max] = save;
            j = max;
            i = j + 1;
        }
        else
        {
            check = false;
        }
    }
}

static void buildMaxHeap(std::vector<int> &data)
{
    for (std::size_t i = data.size()/2; i > 0; --i)
    {
        maxHeapify(data, i, data.size());
    }
}

void heapSort(std::vector<int> &data)
{
    buildMaxHeap(data);
    for (std::size_t i = data.size(); i > 1; --i)
    {
        int save = data[i-1];
        data[i-1] = data[0];
        data[0] = save;
        maxHeapify(data, 1, i-1);
    }
}
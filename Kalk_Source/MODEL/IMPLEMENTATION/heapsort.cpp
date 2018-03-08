#include<vector>

void MaxHeapify(std::vector<int>& v, unsigned int i, unsigned int n)
{
    unsigned int j, temp;
    temp = v[i];
    j = 2*i;

    while (j <= v.size())
    {
        if (j < n && v[j+1] > v[j])
        j = j+1;
        // Break if parent value is already greater than child value.
        if (temp > v[j])
            break;
        // Switching value with the parent node if temp < a[j].
        else if (temp <= v[j])
        {
            v[j/2] = v[j];
            j = 2*j;
        }
    }
    v[j/2] = temp;
}
void HeapSort(std::vector<int>& v)
{
    unsigned int i, temp;
    for (i = v.size(); i >= 2; i--)
    {
        // Storing maximum value at the end.
        temp = v[i];
        v[i] = v[1];
        v[1] = temp;
        // Building max heap of remaining element.
        MaxHeapify(v, 1, i - 1);
    }
}
void Build_MaxHeap(std::vector<int>& v)
{
        for(unsigned int i = v.size()/2; i >= 1; i--)
        MaxHeapify(v, i, v.size());
}

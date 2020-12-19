#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>
#include <limits>
#include <chrono>
using namespace std;
void readInputFile(vector<long long> &data, string inputFileName)
{
    ifstream input_file(inputFileName);
    string line;
    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            stringstream number(line);
            long long temp = 0;
            number >> temp;
            data.push_back(temp);
        }
        input_file.close();
    }
}

void insertionSort(vector<long long> &data, long long start, long long end)
{
    for (long long i = start + 1; i <= end; i++)
    {
        long long key = data[i];
        long long j = i - 1;
        while (j >= start && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}
void merge(vector<long long> &data, long long start, long long mid, long long end)
{
    long long n1 = mid - start + 1;
    long long n2 = end - mid;
    vector<long long> l(n1 + 1), r(n2 + 1);
    for (long long i = 0; i < n1; i++)
        l[i] = data[start + i];
    for (long long j = 0; j < n2; j++)
        r[j] = data[mid + j + 1];
    l[n1] = std::numeric_limits<long long>::max();
    r[n2] = std::numeric_limits<long long>::max();
    long long i = 0, j = 0;
    for (long long k = start; k <= end; k++)
    {
        if (l[i] <= r[j])
        {
            data[k] = l[i];
            i++;
        }
        else
        {
            data[k] = r[j];
            j++;
        }
    }
}

void mergeSort(vector<long long> &data, long long start, long long end)
{
    if (start < end)
    {
        long long mid = start + (end - start) / 2;
        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

long long partition(vector<long long> &data, long long start, long long end)
{
    long long pivot = data[end];
    long long i = start - 1;
    for (long long j = start; j <= end - 1; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[end]);
    return i + 1;
}
long long randdomizedPartition(vector<long long> &data, long long start, long long end)
{
    long long random = start + rand() % (end - start);
    swap(data[random], data[end]);

    return partition(data, start, end);
}
void quickSort(vector<long long> &data, long long start, long long end)
{
    if (start < end)
    {
        long long pivotIndex = randdomizedPartition(data, start, end);
        quickSort(data, start, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, end);
    }
}

void selectionSort(vector<long long> &data, long long n)
{
    for (long long i = 0; i < n; i++)
    {
        long long min = i;
        for (long long j = i + 1; j < n; j++)
            if (data[min] > data[j])
                min = j;
        swap(data[min], data[i]);
    }
}
void hybirdSort(vector<long long> &data, long long start, long long end, long long minimumDataSize)
{
    if (start < end)
    {
        if (end - start <= minimumDataSize)
        {
            insertionSort(data, start, end);
        }
        else
        {
            long long pivotIndex = randdomizedPartition(data, start, end);
            hybirdSort(data, start, pivotIndex - 1, minimumDataSize);
            hybirdSort(data, pivotIndex + 1, end, minimumDataSize);
        }
    }
}
void sort(vector<long long> &data, long long n, int algorithm)
{
    switch (algorithm)
    {
    case 0:
        selectionSort(data, n);
        break;
    case 1:
        insertionSort(data, 0, n - 1);
        break;
    case 2:
        mergeSort(data, 0, n - 1);
        break;
    case 3:
        quickSort(data, 0, n - 1);
        break;
    case 4:
        hybirdSort(data, 0, n - 1, 16);
        break;
    }
}
int main(int argc, char **argv)
{
    srand(time(NULL));
    int algorithm = atoi(argv[1]);
    string inputFileName = argv[2];
    string outputFileName = argv[3];
    string runningTimeFileName = argv[4];
    vector<long long> data;
    readInputFile(data, inputFileName);
    auto start = std::chrono::steady_clock::now();
    sort(data, data.size(), algorithm);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    ofstream outputFile(outputFileName);
    ofstream runningTimeFile(runningTimeFileName);
    if (outputFile.is_open())
    {
        for (int i = 0; i < data.size(); i++)
            outputFile << data[i] << "\n";
        outputFile.close();
    }
    if (runningTimeFile.is_open())
    {

        runningTimeFile << std::chrono::duration<double, std::milli>(diff).count() << " milliseconds\n";
        runningTimeFile.close();
    }
    return 0;
}
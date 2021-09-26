#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <Windows.h> 
#include <vector>
#include<string>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
int n; // ������� �������� ������ 
void print(int* a);
int control();

void sort_bubble(int arr[], int n);

void insertionSort(int array[], int size);
void selectionSort(int array[], int size);

int partition(int array[], int low, int high);
void quickSort(int array[], int n);

void merge(int a[], int b[], int low, int mid, int high);
void mergeSort(int a[], int len);
void printArray(int array[], int size);

void mergeAsc(int A[], int p, int q, int r);
void merge_sortAsc(int A[], int p, int r);

void quick_sort1D(int* array, int first, int last);
void quick_sort2D(int** array, int first, int last, int h);


int main() {
    // 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream myfile;


    unsigned int start_time, end_time, search_time;
    cout << "\nBubble sort:" << endl;

    myfile.open("D:/�����������/���/1lab/results/bubble.txt");
    for (int n = 1000; n < 100000; n += 1000)
    {
        int* array = new int[n];
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 2001 - 1000;
        }
        start_time = clock(); // ���������� ��� 
        sort_bubble(array, n);
        end_time = clock(); // ������� ��� 
        search_time = end_time - start_time; // ������� ��� 
        myfile << std::to_string(search_time) + "\n";
        cout << n << " ��������:" << search_time << "ms" << endl;
    }
    myfile.close();

    /////////////// ����������  �������� /////////////// 
    myfile.open("D:/�����������/���/1lab/results/insertion.txt");
    cout << "\nInsertion sort:" << endl;
    for (int n = 1000; n < 100000; n += 1000)
    {
        int* array = new int[n];
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 2001 - 1000;
        }
        start_time = clock(); // ���������� ��� 
        insertionSort(array, n);
        end_time = clock(); // ������� ��� 
        search_time = end_time - start_time; // ������� ��� 
        myfile << std::to_string(search_time) + "\n";
        cout << n << " ��������:" << search_time << "ms" << endl;
    }
    myfile.close();

    /////////////// ����������  �������� /////////////// 
    cout << "\nSelection sort:" << endl;
    myfile.open("D:/�����������/���/1lab/results/selection.txt");
    for (int n = 1000; n < 100000; n += 1000)
    {
        int* array = new int[n];
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 2001 - 1000;
        }
        start_time = clock(); // ���������� ��� 
        selectionSort(array, n);
        end_time = clock(); // ������� ��� 
        search_time = end_time - start_time; // ������� ��� 
        myfile << std::to_string(search_time) + "\n";
        cout << n << " ��������:" << search_time << "ms" << endl;
    }
    myfile.close();

    /////////////// ����������  ������� /////////////// 
    cout << "\nMerge sort:" << endl;
    myfile.open("D:/�����������/���/1lab/results/merge.txt");
    for (int n = 1000; n < 100000; n += 1000)
    {
        int* array = new int[n];
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 2001 - 1000;
        }
        start_time = clock(); // ���������� ��� 
        merge_sortAsc(array, 0, n - 1);
        end_time = clock(); // ������� ��� 
        search_time = end_time - start_time; // ������� ��� 
        myfile << std::to_string(search_time) + "\n";
        cout << n << " ��������:" << search_time << "ms" << endl;
    }
    myfile.close();

    myfile.open("D:/�����������/���/1lab/results/quick_sort.txt");
    /////////////// ������ ���������� /////////////// 
    cout << "\Quick sort:" << endl;
    for (int n = 1000; n <= 100000; n += 1000)
    {
        int* array = new int[n];
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 2001 - 1000;
        }
        start_time = clock(); // ���������� ��� 
        quick_sort1D(array, 0, n - 1);
        end_time = clock(); // ������� ��� 
        search_time = end_time - start_time; // ������� ��� 
        myfile << std::to_string(search_time) + "\n";
        cout << n << " ��������:" << search_time << "ms" << endl;
    }

    myfile.close();
    system("pause");
    return 0;
}
// ���� �������� ������ 
void print(int* a) {
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
    cout << endl;
}
// �������� �������� 
int control() {
    while (true) {
        cout << "������ ����: ";
        cin >> n;
        if (cin.get() == '\n' && n > 0) break;
        else {
            cout << "��������� ���� �����!";
            cin.clear(); // ����� ������� ������� 
            cin.sync(); // ����������� �� ������� �� '\n' 
        }
    }
    return n;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort 
void sort_bubble(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}


int partition(int a[], int start, int end) {
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}

void quick_sort2D(int** array, int first, int last, int h) {
    int i = first, j = last, x = array[(first + last) / 2][h];
    int* tmp;
    do {
        while (array[i][h] < x) { i++; }
        while (array[j][h] > x) { j--; }
        if (i <= j) {
            if (i < j) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
            j--;

        }

    } while (i <= j);
    if (i < last) quick_sort2D(array, i, last, h);
    if (first < j) quick_sort2D(array, first, j, h);
}

void quick_sort1D(int* array, int first, int last) {
    int i = first, j = last, x = array[(first + last) / 2];
    int tmp;
    do {
        while (array[i] < x) { i++; }
        while (array[j] > x) { j--; }
        if (i <= j) {
            if (i < j) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
            j--;

        }

    } while (i <= j);
    if (i < last) quick_sort1D(array, i, last);
    if (first < j) quick_sort1D(array, first, j);
}

// Iterative Quicksort routine
void quickSort(int a[], int n)
{
    stack<pair<int, int>> s;
    int start = 0;
    int end = n - 1;
    s.push(make_pair(start, end));
    while (!s.empty())
    {
        start = s.top().first, end = s.top().second;
        s.pop();
        int pivot = partition(a, start, end);
        if (pivot - 1 > start) {
            s.push(make_pair(start, pivot - 1));
        }
        if (pivot + 1 < end) {
            s.push(make_pair(pivot + 1, end));
        }
    }
}

void merge(int a[], int b[], int low, int mid, int high)
{
    for (int i = low; i <= high; i++) {
        b[i] = a[i];
    }
    int left = low;
    int right = mid + 1;
    int index = low;
    while (left <= mid && right <= high) {
        if (b[left] >= b[right])
            a[index++] = b[left++];
        else
            a[index++] = b[right++];
    }
    int remainder = mid - left + 1;
    for (int i = 0; i < remainder; i++) {
        a[index + i] = b[left + i];
    }
}

void mergeSort(int a[], int b[], int low, int high)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a, b, low, mid);
    mergeSort(a, b, mid + 1, high);
    merge(a, b, low, mid, high);
}

void mergeSort(int a[], int len)
{
    int* b = new int[len];
    mergeSort(a, b, 0, len - 1);
    delete[] b;
}


void merge_sortAsc(int A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sortAsc(A, p, q);
        merge_sortAsc(A, q + 1, r);
        mergeAsc(A, p, q, r);
    }
}

// Merge sort 
void mergeAsc(int A[], int p, int q, int r)
{

    int n1, n2, i, j, k;
    //size of left array=n1
    //size of right array=n2       
    n1 = q - p + 1;
    n2 = r - q;
    int* L = new int[n1];
    int* R = new int[n2];
    //initializing the value of Left part to L[]
    for (i = 0;i < n1;i++)
    {
        L[i] = A[p + i];
    }
    //initializing the value of Right Part to R[]
    for (j = 0;j < n2;j++)
    {
        R[j] = A[q + j + 1];
    }
    i = 0, j = 0;
    //Comparing and merging them
    //into new array in sorted order 
    for (k = p;i < n1 && j < n2;k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
    //If Left Array L[] has more elements than Right Array R[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while (i < n1)
    {
        A[k++] = L[i++];
    }
    //If Right Array R[] has more elements than Left Array L[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while (j < n2)
    {
        A[k++] = R[j++];
    }
}
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << " " << array[i] << ",";
    cout << "\b \b" << endl;
}
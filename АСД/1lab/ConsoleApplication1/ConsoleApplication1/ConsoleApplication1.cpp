#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <Windows.h> 
#include <vector>
#include<string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int n; // кількість елементів масиву 
void print(int* a);
int control();
void sort_bubble(int* array);
void insertionSort(int array[], int size);
void selectionSort(int array[], int size);

int partition(int array[], int low, int high);
void quickSort(int array[], int n);

void merge(int a[], int b[], int low, int mid, int high);
void mergeSort(int a[], int len);
void printArray(int array[], int size);

int partitionDesc(int array[], int low, int high);
void quickSortDesc(int array[], int n);


int main() {
    // 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /////////////// Створення масиву /////////////// 
    // Оголошення змінних
    n = control();
    int value;
    int* array = new int[n];
    int* array1 = new int[n];
    int* array2 = new int[n];
    int* array3 = new int[n];
    int* array4 = new int[n];

    // заповнення масивів
    for (int i = 0; i < n; i++) {
        value = rand() % 2001 - 1000;
        array[i] = value;
        array1[i] = value;
        array2[i] = value;
        array3[i] = value;
        array4[i] = value;
    }

    printArray(array1, 10);
    unsigned int start_time, end_time, search_time;
    
    /////////////// Сортування  бульбашкою /////////////// 
    start_time = clock(); // початковий час 
    sort_bubble(array);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  вставкою /////////////// 
    start_time = clock(); // початковий час 
    insertionSort(array1, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  виборкою /////////////// 
    start_time = clock(); // початковий час 
    selectionSort(array2, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  злиттям /////////////// 
    start_time = clock(); // початковий час 
    mergeSort(array3, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /*cout << "Sorted array in ascending order:\n";
    printArray(data, size);*/
    /////////////// Швидке сортування /////////////// 
    start_time = clock(); // початковий час 
    quickSort(array4, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;
    
    printArray(array1, 10);
    /*
    * Сортування відсортованого масиву за спаданням
    */
    cout << "Сортування у зворотній бік" << endl;
    start_time = clock(); // початковий час 
    cout << "1" << endl;
    quickSortDesc(array1, n);
    cout << "2" << endl;
    quickSortDesc(array2, n);
    cout << "3" << endl;
    quickSortDesc(array3, n);
    cout << "4" << endl;
    quickSortDesc(array4, n);
    cout << "5" << endl;
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nQuick sort 5 arrays:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;
    printArray(array1, 10);
    
    /////////////// Сортування  бульбашкою /////////////// 
    start_time = clock(); // початковий час 
    sort_bubble(array);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  вставкою /////////////// 
    start_time = clock(); // початковий час 
    insertionSort(array1, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  виборкою /////////////// 
    start_time = clock(); // початковий час 
    selectionSort(array2, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  злиттям /////////////// 
    start_time = clock(); // початковий час 
    mergeSort(array3, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /*cout << "Sorted array in ascending order:\n";
    printArray(data, size);*/
    /////////////// Швидке сортування /////////////// 
    start_time = clock(); // початковий час 
    quickSort(array4, n);
    end_time = clock(); // кінцевий час 
    search_time = end_time - start_time; // шуканий час 
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;


    printArray(array1, 10);
    //printArray(data3, n);
    //printArray(data2, n);
    system("pause");
    return 0;
}
// Друк елементів масиву 
void print(int* a) {
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
    cout << endl;
}
// Контроль введення 
int control() {
    while (true) {
        cout << "Введіть чило: ";
        cin >> n;
        if (cin.get() == '\n' && n > 0) break;
        else {
            cout << "Очікується ціле число!";
            cin.clear(); // скидає прапори помилок 
            cin.sync(); // видаляються усі символи до '\n' 
        }
    }
    return n;
}
// Перестановка 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Сортування бульбашоковим методом 
void sort_bubble(int* array) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (array[i] < array[i + 1])
                swap(array[i], array[i + 1]);
        }
    }
}
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (key > array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
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
        int pivot = partitionDesc(a, start, end);
        if (pivot - 1 > start) {
            s.push(make_pair(start, pivot - 1));
        }
        if (pivot + 1 < end) {
            s.push(make_pair(pivot + 1, end));
        }
    }
}


int partitionDesc(int a[], int start, int end){
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

// Iterative Quicksort routine
void quickSortDesc(int a[], int n)
{
    stack<pair<int, int>> s;
    int start = 0;
    int end = n - 1;
    s.push(make_pair(start, end));
    while (!s.empty())
    {
        start = s.top().first, end = s.top().second;
        s.pop();
        int pivot = partitionDesc(a, start, end);
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
        if (b[left] <= b[right])
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

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << " " << array[i] << ",";
    cout << "\b \b" << endl;
}
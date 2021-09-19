#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <Windows.h> 
#include <vector>
#include<string>
#include <stack>
#include <vector>
#include <algorithm>
#define N 5
using namespace std;
int n; // кількість елементів масиву 
int control();

void sort_bubble(int* array);
void sort_bubble_by_first_item(int array[N][3], int n);

void insertionSort(int array[], int size);
void insertionSort_by_first_item(int arr[N][3], int n);

void selectionSort(int array[], int size);


int partition(int array[], int low, int high);
void quickSort(int arr[], int low, int high);
int partition_by_first_item(int arr[N][3], int low, int high);
void quickSort_by_first_item(int arr[N][3], int low, int high);

int partitionNonRecursion(int array[], int low, int high);
void quickSortNonRecursive(int array[], int n);

void merge(int a[], int b[], int low, int mid, int high);
void mergeSort(int a[], int len);



void printArray(int array[], int size);
void printArray2D(int array[N][3]);
void printArray2D(int array[][3], int a);

void mergeAsc(int A[], int p, int q, int r);
void merge_sortAsc(int A[], int p, int r);

void merge_sortAsc_by_first_item(int A[N][3], int p, int r);
void mergeAsc_by_first_item(int A[N][3], int p, int q, int r);

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

    //printArray(array1, 10);
    clock_t start_time, end_time;
    double search_time;
    cout<< "******************************************" << "\n";
    cout<< "Всі значення рандомні" << "\n";
    cout<< "******************************************" << "\n";
    cout << endl;
    /////////////// Сортування  бульбашкою /////////////// 
    start_time = clock(); // початковий час 
    sort_bubble(array);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms\n";

    /////////////// Сортування  вставкою /////////////// 
    start_time = clock(); // початковий час 
    insertionSort(array1, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms\n";

    /////////////// Сортування  виборкою /////////////// 
    start_time = clock(); // початковий час 
    selectionSort(array2, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms\n";
    
    /////////////// Сортування  злиттям /////////////// 
    start_time = clock(); // початковий час 
    merge_sortAsc(array3, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms\n";

    /////////////// Швидке сортування /////////////// 
    start_time = clock(); // початковий час 
    //quickSortNonRecursive(array4, n);
    quickSort(array4, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms\n";
    
    //printArray(array3, 10);
    /*
    * Сортування відсортованого масиву за спаданням
    */
    cout << "******************************************" << "\n";
    cout << "Сортування у зворотній бік" << "\n";
    cout << "******************************************" << "\n";
    cout << endl;
    start_time = clock(); // початковий час 
    //cout << "1" << endl;
    mergeSort(array, n);
    //cout << "2" << endl;
    mergeSort(array1, n);
    //cout << "2" << endl;
    mergeSort(array2, n);
    //cout << "3" << endl;
    mergeSort(array3, n);
    //cout << "4" << endl;
    mergeSort(array4, n);
    //cout << "5" << endl;
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\n Sorting backwards" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    //printArray(array3, 10);
    
    /////////////// Сортування  бульбашкою /////////////// 
    start_time = clock(); // початковий час 
    sort_bubble(array);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  вставкою /////////////// 
    start_time = clock(); // початковий час 
    insertionSort(array1, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  виборкою /////////////// 
    start_time = clock(); // початковий час 
    selectionSort(array2, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  злиттям /////////////// 
    start_time = clock(); // початковий час 
    merge_sortAsc(array3, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Швидке сортування /////////////// 
    start_time = clock(); // початковий час 
    //quickSortNonRecursive(array4, n);
    quickSort(array4, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    cout << "******************************************" << "\n";
    cout << "Сортування коли всього 2 унікальні значення" << "\n";
    cout << "******************************************" << "\n";
    cout << endl;

    for (int i = 0; i < n; i++) {
        value = rand() % 2;
        array[i] = value;
        array1[i] = value;
        array2[i] = value;
        array3[i] = value;
        array4[i] = value;
    }

    /////////////// Сортування  бульбашкою /////////////// 
    start_time = clock(); // початковий час 
    sort_bubble(array);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  вставкою /////////////// 
    start_time = clock(); // початковий час 
    insertionSort(array1, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  виборкою /////////////// 
    start_time = clock(); // початковий час 
    selectionSort(array2, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  злиттям /////////////// 
    start_time = clock(); // початковий час 
    merge_sortAsc(array3, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Швидке сортування /////////////// 
    start_time = clock(); // початковий час 
    //quickSortNonRecursive(array4, n);
    quickSort(array4, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    cout << "******************************************" << "\n";
    cout << "Сортування коли всього 1 значення" << "\n";
    cout << "******************************************" << "\n";
    cout << endl;

    for (int i = 0; i < n; i++) {
        value = 1;
        array[i] = value;
        array1[i] = value;
        array2[i] = value;
        array3[i] = value;
        array4[i] = value;
    }

    /////////////// Сортування  бульбашкою /////////////// 
    start_time = clock(); // початковий час 
    sort_bubble(array);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nBubble sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  вставкою /////////////// 
    start_time = clock(); // початковий час 
    insertionSort(array1, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nInsertion sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  виборкою /////////////// 
    start_time = clock(); // початковий час 
    selectionSort(array2, n);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nSelection sort:" << endl;
    cout << "" << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Сортування  злиттям /////////////// 
    start_time = clock(); // початковий час 
    merge_sortAsc(array3, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nMerge sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;

    /////////////// Швидке сортування /////////////// 
    start_time = clock(); // початковий час 
    //quickSortNonRecursive(array4, n);
    quickSort(array4, 0, n - 1);
    end_time = clock(); // кінцевий час 
    search_time = double(end_time - start_time) ; // шуканий час 
    cout << "\nQuick sort:" << endl;
    cout << "Час роботи програми:" << search_time << "ms" << endl;


    int arr[N][3] = { {1,2,3}, {5,4,6}, {1,5,3}, {6,3,2}, {1,4,3} };
    printArray2D(arr);
    sort_bubble_by_first_item(arr, N);
    printArray2D(arr);

    int arr2[N][3] = { {1,2,3}, {5,4,6}, {1,5,3}, {6,3,2}, {1,4,3} };
    insertionSort_by_first_item(arr2, N);
    printArray2D(arr2);

    int arr3[N][3] = { {1,2,3}, {5,4,6}, {1,5,3}, {6,3,2}, {1,4,3} };
    quickSort_by_first_item(arr3, 0, N-1);
    printArray2D(arr3);
    cout<< "Cgeck" << "\n";
    int arr4[N][3] = { {1,2,3}, {5,4,6}, {1,5,3}, {6,3,2}, {1,4,3} };
    merge_sortAsc_by_first_item(arr4, 0, N - 1);
    printArray2D(arr4);

    system("pause");
    return 0;
}

void interchange(int array[N][3], int a, int b){
    for (int i = 0; i < 3; i++) {
        int tmp = array[a][i];
        array[a][i] = array[b][i];
        array[b][i] = tmp;
    }
}

void sort_bubble_by_first_item(int array[N][3], int n) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (array[i][0] > array[i + 1][0])
                interchange(array, i, i+1);
        }
    }
}

void insertionSort_by_first_item(int array[N][3], int n){
    for (int step = 1; step < n; step++) {
        int tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = array[step][i];
        int key = array[step][0];
        int j = step - 1;
        while (key < array[j][0] && j >= 0) {
            interchange(array, j + 1, j);
            --j;
        }
        for (int i = 0; i < 3; i++) array[j + 1][i] = tmp[i];
    }
}
int partition_by_first_item(int arr[N][3], int low, int high) {
    int pivot = arr[high][0]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] <= pivot) {
            i++;
            interchange(arr, i, j);
        }
    }
    interchange(arr, i+1, high);
    return (i + 1);
}

void quickSort_by_first_item(int arr[N][3], int low, int high) {
    if (low < high) {
        int pi = partition_by_first_item(arr, low, high);
        quickSort_by_first_item(arr, low, pi - 1);
        quickSort_by_first_item(arr, pi + 1, high);
    }
}


void merge_sortAsc_by_first_item(int A[N][3], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sortAsc_by_first_item(A, p, q);
        merge_sortAsc_by_first_item(A, q + 1, r);
        mergeAsc_by_first_item(A, p, q, r);
    }
}

void mergeAsc_by_first_item(int A[N][3], int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    auto L = new int[n1][3];
    auto R = new int[n2][3];
    for (i = 0;i < n1;i++) {
        for (int t = 0; t < 3; t++) L[i][t] = (int)A[p + i][t];
    }
    
    for (j = 0;j < n2;j++) {
        for (int t = 0; t < 3; t++) R[j][t] = (int)A[q + j + 1][t];
    }
    
    i = 0, j = 0;
    for (k = p;i < n1 && j < n2;k++) {
        if (L[i][0] < R[j][0]) {
            
            for (int t = 0; t < 3; t++) A[k][t] = L[i][t]; 
            i++;
        }
        else {
            
            for (int t = 0; t < 3; t++) A[k][t] = R[j][t];
            j++;
        }
    }
    
    while (i < n1) {
        for (int t = 0; t < 3; t++) A[k][t] = L[i][t];
        k++;
        i++;
        
    }
    while (j < n2) {
        for (int t = 0; t < 3; t++) A[k][t] = R[j][t];
        k++;
        j++;
        
    }
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
// Сортування бульбашковим методом 
void sort_bubble(int* array) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (array[i] > array[i + 1])
                swap(array[i], array[i + 1]);
        }
    }
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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int partitionNonRecursion(int a[], int start, int end) {
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

void quickSortNonRecursive(int a[], int n)
{
    stack<pair<int, int>> s;
    int start = 0;
    int end = n - 1;
    s.push(make_pair(start, end));
    while (!s.empty())
    {
        start = s.top().first, end = s.top().second;
        s.pop();
        int pivot = partitionNonRecursion(a, start, end);
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

void mergeAsc(int A[], int p, int q, int r)
{

    int n1, n2, i, j, k;   
    n1 = q - p + 1;
    n2 = r - q;
    int *L = new int[n1];
    int *R = new int[n2];
    for (i = 0;i < n1;i++)
    {
        L[i] = A[p + i];
    }
    for (j = 0;j < n2;j++)
    {
        R[j] = A[q + j + 1];
    }
    i = 0, j = 0;
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
    while (i < n1)
    {
        A[k++] = L[i++];
    }
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
void printArray2D(int array[N][3]) {
    int i, j;
    cout << "{" << "\n";
    for (i = 0; i < N;i++) {
        cout << "  [";
        for (j = 0; j < 3; j++){
            cout << " " << array[i][j] << ",";
        }
        cout << "\b \b ]" << "\n";
    }
    cout << "}" << "\n";
}

void printArray2D(int array[][3], int a) {
    int i, j;
    cout << "{" << "\n";
    for (i = 0; i < a;i++) {
        cout << "  [";
        for (j = 0; j < 3; j++) {
            cout << " " << array[i][j] << ",";
        }
        cout << "\b \b ]" << "\n";
    }
    cout << "}" << "\n";
}
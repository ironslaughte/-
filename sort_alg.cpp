#include <iostream>
using namespace std;


void init_arr(int*& arr, size_t size) {
    arr = new int[size];
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

void swap(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}


// InsertionSort block
void InsertionSort(int*& arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Quick sort block
int partition(int*& arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1); // индекс меньшего элемента
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


/* low  --> индекс начала,
  high  --> Индекс последнего */
void Qsort(int*& arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        Qsort(arr, low, pi - 1);
        Qsort(arr, pi + 1, high);
    }
}


// CountingSort block
void CountingSort(char*& arr, size_t size) {
    char max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    char* count = new char[max - '0' + 1]; // махинации с '0' происходят, тк max будет равно,например, 57
    // но на самом деле это число 9, поэтому отнимаем '0', чтобы действительно получить 9. Ну и дальше по тому же принципу.
    for (size_t i = 0; i < (max - '0') + 1; i++) {
        count[i] = '0';
    }

    for (size_t i = 0; i < size; i++) {
        count[arr[i] - '0'] += 1;
    }
    int k = 0;
    for (size_t i = 0; i < (max - '0') + 1; i++) {
        for (size_t j = 0; j < count[i] - '0'; j++) {
            arr[k] = i + '0';
            k++;
        }
    }
    delete[] count;
}



int binary_search(int*& arr, int low, int high, int elem) {
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == elem) {
            return mid;
        }
        if (arr[mid] > elem) {
            high = mid - 1;
        }
        if (arr[mid] < elem) {
            low = mid + 1;
        }
    }
    return -1;
}


// BogoSort block
bool isSorted(int*& arr, size_t size){
    while (--size > 0)
        if (arr[size] < arr[size - 1])
            return false;
    return true;
}


void shuffle(int*& arr, size_t size){
    for (int i = 0; i < size; i++) {
        swap(arr[i], arr[rand() % size]);
    }
}

void bogosort(int*& arr, size_t size){
    while (!isSorted(arr, size))
        shuffle(arr, size);
}


#include <iostream>
#include <cstdlib> 
#include <ctime>   

template <typename T> //шаблон
void swap(T* a, T* b) { //функция меняющая местами элементы
    T t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
int split(T arr[], int low, int high) { //функция разделяющая массив
    srand(time(NULL)); 
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]);

    T pivot = arr[high]; 
    int i = (low - 1); // индекс меньшего элемента
    for (int j = low; j <= high - 1; j++) { 
        if (arr[j] <= pivot) { 
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int piv = split(arr, low, high);
        quickSort(arr, low, piv - 1); //сортировка элементов до разделения 
        quickSort(arr, piv + 1, high); //сортировка элементов после разделения 
    }
}

template <typename T>
void print_array(T arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = { 220, 56, 8, 77, 1, 899, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    print_array(arr, n);
    quickSort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}

/*Original array: 220 56 8 77 1 899 5 8
Sorted array: 1 5 8 8 56 77 220 899*/
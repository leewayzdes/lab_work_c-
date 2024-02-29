#include <iostream>

template <typename T>
void swap(T& a, T& b) { //функция меняющая местами элементы
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void selectionSort(T arr[], int n) {
    int min_i = 0;
    for (int i = 0; i < n - 1; i++) {  // смещение границы неотсортированного массива
        min_i = i; //минимальный неотсортированный элемент
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_i])
                min_i = j;
        swap(arr[min_i], arr[i]); //замена минимального первым
    }
}

template <typename T>
void print_array(T arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = { 4, 8, 1, 777, 57, 48, 45, 909, 32, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    print_array(arr, n);
    selectionSort(arr, n);
    std::cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}

/*Original array: 4 8 1 777 57 48 45 909 32 16
Sorted array: 1 4 8 16 32 45 48 57 777 909*/
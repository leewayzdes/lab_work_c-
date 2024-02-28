#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { //ограничиваем количество проходов по массиву
        for (int j = 0; j < n - i - 1; j++) { //перебор неотсортированных значений
            if (arr[j] > arr[j + 1]) { // меняем местами если значение больше следующего
                int time_j = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = time_j; 
            }
        }
    }
}

int main() {
    //инициализация массива
    const int size = 7;
    int array[size] = { 4, 25, 829, 0, 91, 6, 25 };

    //вывод исходного массива
    std::cout << "Input: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    bubbleSort(array, size);

    //вывод отсортированного массива
    std::cout << "Output: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    return 0;
}

//Input: 4 25 829 0 91 6 25
//Output : 0 4 6 25 25 91 829
#include  <iostream>
using namespace std;

// метод сортировки, основанный на shell sort
int shellSort(int arr[], int n)
{
    // начинаем с самого большого промежутка, доходя до наименьшего
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Делаем сортировку вставками для промежутка
        // Элементы меняются местами по своим промежуткам
        // Продолжаем добавлять элементы в промежутки
        // Пока весь промежуток не отсортируется
        for (int i = gap; i < n; i += 1)
        {
            // добавляем a[i] и сохраняем его, потом
            int temp = arr[i];

            // двигаем элемент до тех пор пока он не будет в нужной позиции
            // находим локацию для a[i]
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // вставим a[i] на нужную позицию
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = { 12, 34, 54, 2, 3 }, i;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

    return 0;
}
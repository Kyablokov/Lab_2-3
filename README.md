# Lab_2-3
Лабораторная работа 2-3
ФИО: Яблоков Николай Дмитриевич
Группа: СКБ251

1. Задание:
Считать входные значения в динамический массив, проанализировать данные (среднее, минимум, максимум, выбросы), создаёт новый динамический массив, содержащий только значения, превышающие среднее.







2. Описание алгоритма:

Функция inputData(float* p, int n)
Считывание данных с потока ввода;
Проверка на вхождение в отрезок [-50;50]

Функция average(const float* p, int n)
Находит среднее значение в массиве, считая сумму всех значений и деля её на количество измерений.

Функция minValue(const float *p, int n)
Находит минимальное значение, проходя по всему массиву.

Функция maxValue(const float *p, int n)
Находит максимальное значение, проходя по всему массиву.

Функция filterAboveAverage(float* p, int n, int& newCount)
Считает количество значений, превышающих среднее;
Создаёт новый массив с таким количеством ячеек;
Проходит по первоначальному массиву ещё раз и записывает в новый массив числа, превышающее среднее.

Функция main()
Предлагает пользовтаелю ввести измерения;
Анализирует данные (через функции, описанные выше) и выводит их;
Освобождает память, выделенную на динамические массивы.

3. Код:
#include <iostream>
using namespace std;

void inputData(float* p, int n){
    cout<<"Введите значения температуры:";
    for (int i= 0; i<n; i++){
        cin>> *(p+i);
        if( *(p+i) < -50 || *(p+i) > 50) {
            cout << "Введите значение от -50 до 50" << endl;
            i -= 1;
        }
    }
}

float average(const float* p, int n){    
    float sum = 0;
    for (int i=0; i<n;i++){ 
        sum += *(p+i);
    }
    return sum/n;
}

float minValue(const float *p, int n){
    float min = 100000;
    for (int i = 0; i<n;i++){
        if (*(p+i) < min){
            min = *(p + i);
        }
    }
    return min;
}

float maxValue(const float *p, int n){
    float max = -100000;
    for (int i = 0; i<n;i++){
        if (*(p+i) > max){
            max = *(p + i);
        }
    }
    return max;
}

float* filterAboveAverage(float* p, int n, int& newCount){
    float averag = average(p,n);
    newCount = 0;

    for (int i = 0; i<n; i++){
        if (*(p+i) > averag){
            newCount++;
        }
    }

    float* newmass = new float[newCount];
    int ind = 0;

    for (int i = 0; i<n;i++){
        if (*(p+i) > averag){
            *(newmass + ind) = *(p+i);
            ind++;
        }
    }
    return newmass;
}



int main() {
    cout << "=== Анализ сенсора ===" << endl;
    int n;

    cout << "Введите количсество измерений:";
    cin >>n;

    float* data = new float[n];

    inputData(data,n);
    
    float averag = average(data,n);
    cout << "\nСреднее значение:" << averag << endl;

    float min = minValue(data,n);
    cout << "Минимальное значение:" << min << endl;

    float max = maxValue(data,n);
    cout << "Максимальное значение:" << max << endl;


    int newCount;
    float* newmass = filterAboveAverage(data, n, newCount);

    cout << "\nЗначения выше среднего: " << endl;
    for (int i = 0; i< newCount;i++){
        cout<< *(newmass + i) << " ";
    }
    cout << endl;

    delete[] data;
    delete[] newmass;

    return 0;
}

4. Cсылка на репризиторий: https://github.com/Kyablokov/Lab_2-3.git
5. Вывод:
Научился работать с динамическими массивами;
Освоил передачу массивов по указателю в функции;
Научился обрабатывать массивы через арифметику указателей (*(p+i));
Осознал, как управлять памятью вручную без STL.
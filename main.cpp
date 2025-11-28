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

    cout << "Введите количество измерений:";
    cin >>n;
    
    if (n < 1){
        cout << "Количество измерений должно быть положительно. Попробуйте ещё раз.";
        return 0;
    }

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

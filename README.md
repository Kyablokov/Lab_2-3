# Lab_2-3
Лабораторная работа 2-3
ФИО: Яблоков Николай Дмитриевич
Группа: СКБ251

1. Задание:
	•	Получить по заданному числу y следующее значение



, где










2. Описание алгоритма:
	•	Функция для нахождения двойного факториала
	◦	принимает число n
	◦	цикл от n до 0 (не включительно) с шагом 2, умножая результат = 1 на переменную цикла на каждом шаге
	◦	возвращает результат
	•	Функция t(n)
	◦	принимает число n
	◦	вычисление значения числителя
	◦	вычисление значения знаменателя
	◦	деление числителя на знаменатель
	◦	возвращает результат деления
	•	Функция для вычисления выражения
	◦	принимает заданное число y
	◦	подсчёт выражения
	◦	возвращает ответ на задачу
3. Код:
#include <iostream>
#include <cmath>

using namespace std;

long long int double_fact(int n)
{
    long long int res = 1;

    for (int i = n; i > 0; i-=2)
        res *= i;

    return res;
}
   
long double t(long double n)
{
    long double s1 = 0;
    long double s2 = 0;
    for (int k = 0; k < 11; k++){
        long double num1 = pow(n, (2 * k + 1));
        long double num2 = double_fact(2 * k + 1);
        s1 += (num1 / num2);
    }
       
    for (int k = 0; k < 11; k++){
        long double num1 = pow(n, (2 * k));
        long double num2 = double_fact(2 * k);
        s2 += (num1 / num2);
    }

    long double res = s1 / s2;
    return res;
}
   
long double final(long double y){
    long double n1 = 7 * t(0.25) + 2 * t(1 + y);
    long double n2 = 6 - t(pow(y, 2) - 1);
    // cout << n1 << " " << n2 << endl;
    return (n1 / n2);
}
   

int main()
{
    long double y;
    cin >> y;

    cout << final(y) << endl;

    return 0;
}

4. Cсылка на репризиторий: https://github.com/...
5. Вывод:
   написал программу на C++, вспомнил синтаксис C++, использовал cmath

/*
    Площадь треугольника
    https://acmp.ru/index.asp?main=task&id_task=822
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){

    long double x1,y1,x2,y2,x3,y3;
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &x1, &y1, &x2, &y2, &x3, &y3);

    long double l1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    long double l2 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    long double l3 = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));

    long double p = (l1 + l2 + l3)/2;

    long double s = sqrt(p*(p-l1)*(p-l2)*(p-l3));
    
    printf("%4.6Lf\n", s);

    return 0;
}
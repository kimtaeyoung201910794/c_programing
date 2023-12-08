#pragma once

//아래에 avg()를 정의하세요.

double avg(int a[], int size) {
    double sum = 0;
    for (int i=0; i<size; i++)
        sum += a[i];
    return sum /size;
}
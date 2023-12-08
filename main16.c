
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

	//1번
	//avg.h 파일에서 avg()를 완성하시오.
    //아래에 avg()가 정의된헤더 파일을 포함하세요.
#include "avg.h"

int main(void)
{
	int a = 10, b = 20;

	//2번
    //아래에 #ifndef 문을 사용하여 매크로 함수를 정의하시오.
#ifndef ADD
#define ADD(a,b) ((a) + (b))
#endif

	printf("실행 결과 : %d + %d = %d \n", a, b, ADD(a, b));

	int arr[] = { 2, 4, 6, 3, 1, 8 };
	printf("평균 : %.2f\n", avg(arr, sizeof(arr) / sizeof(int)));

	int sum;
#define SIZE 10
	sum = 0;
	for (int i = 1; i < SIZE; i++)
		sum += i;
	printf("1부터 %d까지의 합: %d\n", SIZE, sum);

	//3번
	//아래에SIZE가 100이 되도록 전처리기를 재정의하시오.
#undef SIZE
#define SIZE 100

	sum = 0;
	for (int i = 1; i < SIZE; i++)
		sum += i;
	printf("1부터 %d까지의 합: %d\n", SIZE, sum);

#define MULTI_5
	int n;

	//4번
    //아래에 MULTI_5가 정의되어 있으면 n=5;로 아니면 n=3; 으로 전처리기를 완성하시오.
#ifdef MULTI_5
	n=5;
#else
	n=3
#endif


	sum = 0;
	for (int i = 1; i < SIZE; i++) {
		if (i % n == 0)
			sum += i;
	}
	printf("1부터 %d까지의 %d의 배수의 합: %d\n", SIZE, n, sum);

	return 0;
}


/*예시 출력결과
실행 결과 : 10 + 20 = 30
평균 : 4.00
1부터 10까지의 합: 45
1부터 100까지의 합: 4950
1부터 100까지의 5의 배수의 합: 950
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
실행 결과 : 10 + 20 = 30 
평균 : 4.00
1부터 10까지의 합: 45
1부터 100까지의 합: 4950
1부터 100까지의 5의 배수의 합: 950

*/

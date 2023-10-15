#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLS 4
//1번 함수를 완성하시오
void prob_1(int* p1, int* p2, int* p3) {
	int tmp;

	//아래를 완성하시오. 미리 선언된 변수 이외에 새로운 변수를 선언하지 마시오.
	tmp = *p3;
	*p3 = *p1;
	*p1 = *p2;
	*p2 = tmp;


}

void prob_2(int a[][COLS], double row_arr[], double col_arr[], int rows, int cols) {
	int i, j;
	//2번함수를 완성하시오. 미리 선언된 변수 이외에 새로운 변수를 선언하지 마시오.
	for( i =0; i< rows; i++) {
		row_arr[i] = 0.0;
		for(j=0; j<cols; j++)
			row_arr[i] += a[i][j];
		row_arr[i] /= cols;
	}

	for(j=0; j<cols; j++) {
		col_arr[j] = 0.0;
		for(i=0; i<rows; i++)
			col_arr[j] += a[i][j];
		col_arr[j] /= rows;
	}


}
void prob_3(int *p, double *rp, double *cp, int rows, int cols) {
	int i, j;
	//3번 함수를 완성하시오. 미리 선언된 변수 이외에 새로운 변수를 선언하지 마시오.
	
	for(i=0; i<rows; i++) {
		rp[i] = 0.0;
		for(j=0; j<cols; j++)
			rp[i] += *(p+i *cols+j);
		rp[i] /= cols;
	}

	for(j=0; j<cols; j++) {
		cp[j] = 0.0;
		for(i=0; i<rows; i++)
			cp[j] += *(p+i *cols+j);
		cp[j] /= rows;
	}
	



}
int main(void){
	//1번
	int n1 = 3, n2 = 6, n3 = 9;
	printf("1번 전: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	prob_1(&n1, &n2, &n3);
	printf("1번 후: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);

	int k = 1, a[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			a[i][j] = k++;
		}
	}
	double avg_rows[ROWS], avg_cols[COLS];
	//2번
	prob_2(a, avg_rows, avg_cols, ROWS, COLS);
	printf("2. 행평균: ");
	for (int i = 0; i < ROWS; i++)
		printf("%.1f ",avg_rows[i]);
	printf("\n2. 열평균: ");
	for (int i = 0; i < COLS; i++) 
		printf("%.1f ", avg_cols[i]);

	//3번
	prob_3((int*)a, avg_rows, avg_cols, ROWS, COLS);
	printf("\n3. 행평균: ");
	for (int i = 0; i < ROWS; i++)
		printf("%.1f ", avg_rows[i]);
	printf("\n3. 열평균: ");
	for (int i = 0; i < COLS; i++)
		printf("%.1f ", avg_cols[i]);
	printf("\n");

	return 0;
}

/*실제 출력결과
1번 전: n1:3, n2:6, n3:9
1번 후: n1:6, n2:9, n3:3
2. 행평균: 7.0 8.0 9.0 10.0 
3. 행평균: 2.5 6.5 10.5 14.5 
3. 열평균: 7.0 8.0 9.0 10.0 
*/
/*예시 출력결과
1번 전: n1:3, n2:6, n3:9
1번 후: n1:6, n2:9, n3:3
2. 행평균: 2.5 6.5 10.5 14.5 
2. 열평균: 7.0 8.0 9.0 10.0 
3. 행평균: 2.5 6.5 10.5 14.5 
3. 열평균: 7.0 8.0 9.0 10.0 
계속하려면 아무 키나 누르십시오 . . .
*/
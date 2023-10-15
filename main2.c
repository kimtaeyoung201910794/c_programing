#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 3
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void print_arr(int arr[][COL]) 
{
   printf("arr[]:\n");
   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++)
         printf("%d ", arr[i][j]);
      printf("\n");
   }
}

void prob_1(int *ptr, int size) {
   //아래를 완성하시오. 다른 변수를 선언하지 마시오.
   for (int i = 0; i< size; i++) {
    (*ptr)++;
    ptr++;
   }

}
void prob_2(int* ptr, int size) {
  //아래를 완성하시오. 다른 변수를 선언하지 마시오.
  for (int i =0; i<size+1; i++) {
    *(ptr +i-1) += 1;
  }

}
void prob_3(int* ptr, int size) {
  //아래를 완성하시오. 다른 변수를 선언하지 마시오.
  for(int i=0; i<size+1; i++) {
        ptr[i] +=1;
  }

}
void prob_4(int* p, int *q) {
  int tmp;
  //아래를 완성하시오. 다른 변수를 선언하지 마시오.
  while(p < q) {
    SWAP(*p, *q, tmp);
    p++;
    q--;
  }

}
int main(void)
{
   int arr[][COL] = { {1, 2, 3,}, {4, 5, 6} };
   int size = ROW * COL;

   prob_1((int*)arr, size);
  prob_2((int*)arr+1, size);
  prob_3((int*)arr-1, size);
  prob_4((int*)arr, (int*)arr+size);

   print_arr(arr);

   return 0;
}

/*실제 출력결과
실제 출력결과가 예시 출력결과와 다르게 나왔는데
어떠한 문제로 저렇게 나오는지 모르겠습니다 
좀 더 공부해보도록 하겠습니다 감사합니다.

arr[]:
-1545821015 1018045697 9 
8 7 6 
*/
/*예시 출력결과
arr[]:
9 8 7
6 5 4
계속하려면 아무 키나 누르십시오 . . .
*/
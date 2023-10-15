#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void prob_1(char str[], char* find, char* replace, char target[])
{
   char* seps = " ,\t\n";
   char* token;

   token = strtok(str, seps);

   //아래를 완성하시오. 새로운 변수를 선언하지 마시오.

   target[0] = '\0';
   while (token != NULL)
   {
      if (strcmp(token, find) == 0)
         strcat(target, replace);
      else
         strcat(target, token);
      strcat(target, " ");

      token = strtok(NULL, seps);
   }
}

double prob_2(char s1[], char s2[], char s3[])
{
   char* s;
   int sum = 0, cnt = 0;

   //아래를 완성하시오. 새로운 변수를 선언하지 마시오.

   sprintf(s3, "%s, %s", s1, s2);
   s = s3;
   while (*s != '\0') {
      if (isdigit(*s)) {
         sum += *s - '0';
         cnt++;
      }
      s++;
   }
   return (double)sum / cnt;
}

int prob_3(char name[][2][20], int size)
{
   int i, age, max_idx, max_age;

   max_idx = 0;
   sscanf(name[0][1], "%d", &max_age);

   //아래를 완성하시오. 새로운 변수를 선언하지 마시오.

   for (i = 1; i < size; i++) {
      sscanf(name[i][1], "%d", &age);
      if (age > max_age) {
         max_idx = i;
         max_age = age;
      }
   }

   return max_idx;
}
int main(void)
{
   //1번
   char str[SIZE];
   char find[SIZE], replace[SIZE], target[SIZE];

   printf("영문자열을 입력하시오: ");
   gets_s(str, sizeof(str));
   printf("찾을 문자열: ");
   scanf("%s", find);
   printf("바꿀 문자열: ");
   scanf("%s", replace);
   prob_1(str, find, replace, target);
   printf("바뀐 문자열은 %s\n", target);
   getchar();

   //2번
   char str1[20], str2[20], str3[40];
   double avg;

   printf("str1 문자열 입력: ");
   gets_s(str1, sizeof(str1));
   printf("str2 문자열 입력: ");
   gets_s(str2, sizeof(str2));
   avg = prob_2(str1, str2, str3);
   printf("%s: 숫자의 평균: %.2f\n", str3, avg);

   //3번
   char name[3][2][20];

   for (int i = 0; i < 3; i++) {
      printf("%d. 이름 나이: ", i);
      scanf("%s %s", name[i][0], name[i][1]);
   }
   int idx = prob_3(name, 3);
   printf("최고령자: %s, %s\n", name[idx][0], name[idx][1]);

   return 0;
}
/*실제 출력결과
* 영문자열을 입력하시오: I love c program
찾을 문자열: love
바꿀 문자열: like
바뀐 문자열은 I like c program
str1 문자열 입력: 1, c 25
str2 문자열 입력: 2, c++ 30
1, c 25, 2, c++ 30: 숫자의 평균: 2.17
0. 이름 나이: 강감찬 45
1. 이름 나이: 김유신 30
2. 이름 나이: 이순신 35
최고령자: 강감찬, 45
*/

/*예시 출력결과
영문자열을 입력하시오: I love c program
찾을 문자열: love
바꿀 문자열: like
바뀐 문자열은 I like c program
str1 문자열 입력: 1. c 25
str2 문자열 입력: 2. c++ 30
1. c 25, 2. c++ 30: 숫자의 평균: 2.17
0. 이름 나이: 강감찬 45
1. 이름 나이: 김유신 30
2. 이름 나이: 이순신 35
최고령자: 강감찬, 45
계속하려면 아무 키나 누르십시오 . . .
*/
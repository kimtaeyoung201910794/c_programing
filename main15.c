#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 3
struct student {
	int number;	// 학번
	char name[20];	// 이름
	double gpa;	// 평점
};

void f1(FILE* fp, char* find) {
	int linenumber = 0;
	char line[256];

	printf("검색내용출력\n");
	//아래를 완성하시오. fgets(), fputs(), feof(), strstr()를 사용하시오.
    while (fgets(line, sizeof(line), fp) != NULL) {
        linenumber++;
        if (strstr(line, find) != NULL) {
            printf("%d : %s", linenumber, line);
        }
    }

}
void f2(FILE* fp) {
	int line_no = 0, word_no = 0;
	char line[256], *token;
	char* delim = " \n\t\r";

	//아래를 완성하시오. fgets(), feof(), strtok()를 사용하시오.
    printf("단어와 줄 수 출력\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_no++;
        token = strtok(line, delim);
        while (token != NULL) {
            word_no++;
            token = strtok(NULL, delim);
        }
    }

	printf("\n");
	printf("단어 수 : %5d\n", word_no);
	printf("줄 수   : %5d\n", line_no);
	printf("\n");

}
void f3() {
	FILE* fp;
	//아래를 완성하시오. "#취미: 축구" 를 추가하시오.
    printf("파일에 내용 추가\n");
    if ((fp = fopen("student.txt", "a")) == NULL) {
        fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }
    fputs("##취미: 축구\n", fp);

	fclose(fp);
}

void f4(FILE* fp, int stu_no, double stu_gpa) {
	struct student s;

	printf("수정된 학생 레코드\n");
	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		if (s.number == stu_no) {
			//아래를 완성하시오
            s.gpa = stu_gpa;
            fseek(fp, -sizeof(struct student), SEEK_CUR);
            fwrite(&s, sizeof(struct student), 1, fp);

		}
	}
}
int main(void)
{
	FILE* fp = NULL;
	char buf[100];

	//1번
	char filename[80], find[80];

	printf("찾을 파일명: ");
	scanf("%s",filename);
	printf("찾을 문자열: ");
	scanf("%s", find);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("can't open the file [%s]\n", filename);
		exit(1);
	}

	f1(fp, find);
	rewind(fp);

	//2번
	f2(fp);
	fclose(fp);

	//3번
	if ((fp = fopen("student.txt", "wt")) == NULL)
	{
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	fputs("#이름: 홍길동\n", fp);
	fclose(fp);

	f3();

	//student.txt 를 메모장으로 열어 내용이 아래와 같은지 확인해 보세요.
	//#이름: 홍길동
	//##취미: 축구
	if ((fp = fopen("student.txt", "rt")) == NULL)
	{
		fprintf(stderr, "읽기를 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	while (fgets(buf, 100, fp)) {
		printf("%s", buf);
	}

	//4번
	struct student table[SIZE] = {
		{ 1, "Kim", 3.99 },
		{ 2, "Min", 2.68 },
		{ 3, "Lee", 4.01 }
	}; 
	struct student s;
	int stu_no;
	double stu_gpa;

	// 이진 파일을 쓰기 모드로 연다.
	if ((fp = fopen("student.dat", "wb+")) == NULL)
	{
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	// 배열을 파일에 저장한다.
	fwrite(table, sizeof(struct student), SIZE, fp);

	printf("원본 학생 레코드\n");
	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}
	printf("수정할 학번: ");
	scanf("%d", &stu_no);
	printf("수정할 평점: ");
	scanf("%lf", &stu_gpa);

	f4(fp, stu_no, stu_gpa);

	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}

	fclose(fp);

	return 0;
}

/*실제 출력결과
찾을 파일명: main.c
찾을 문자열: seek
검색내용출력
68 :    fseek(fp, 0, SEEK_SET);
73 :             fseek(fp, -sizeof(struct student), SEEK_CUR);
148 :   fseek(fp, 0, SEEK_SET);
159 :   fseek(fp, 0, SEEK_SET);
174 : 찾을 문자열: seek
176 : 75 :    fseek(fp, 0, SEEK_SET);
177 : 80 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
178 : 155 :   fseek(fp, 0, SEEK_SET);
179 : 166 :   fseek(fp, 0, SEEK_SET);
180 : 181 : 찾을 문자열: seek
181 : 185 : 76 :    fseek(fp, 0, SEEK_SET);
182 : 186 : 81 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
184 : 187 : 156 :   fseek(fp, 0, SEEK_SET);
185 : 188 : 167 :   fseek(fp, 0, SEEK_SET);
단어와 줄 수 출력

단어 수 :   562
줄 수   :   203

파일에 내용 추가
#이름: 홍길동
##취미: 축구
원본 학생 레코��
1, Kim, 3.99
2, Min, 2.68
3, Lee, 4.01
수정할 학번: 2
수정할 평점: 1.5
수정된 학생 레코드
1, Kim, 3.99
2, Min, 1.50
3, Lee, 4.01
*/
/*예시 출력결과
찾을 파일명: main.c
찾을 문자열: seek
검색내용출력
75 :    fseek(fp, 0, SEEK_SET);
80 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
155 :   fseek(fp, 0, SEEK_SET);
166 :   fseek(fp, 0, SEEK_SET);
181 : 찾을 문자열: seek
185 : 76 :    fseek(fp, 0, SEEK_SET);
186 : 81 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);

187 : 156 :   fseek(fp, 0, SEEK_SET);
188 : 167 :   fseek(fp, 0, SEEK_SET);

단어 수 :   531
줄 수   :   206

#이름: 홍길동
##취미: 축구
원본 학생 레코드
1, Kim, 3.99
2, Min, 2.68
3, Lee, 4.01
수정할 학번: 2
수정할 평점: 1.5
수정된 학생 레코드
1, Kim, 3.99
2, Min, 1.50
3, Lee, 4.01
계속하려면 아무 키나 누르십시오 . . .
*/

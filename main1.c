#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 20
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
void exchange1(int arr[][COL]);
void exchange2(int idx1, int idx2, int arr[][COL]);
void min_frq(int arr[][COL]);
void print_arr(int arr[][COL])
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int i, j, arr[ROW][COL];

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			arr[i][j] = rand() % 50 + 50;
		}
	}
	printf("ÃÖÃÊ ¹è¿­ : \n");
	print_arr(arr);

	//1) ÃÖ´ë ¹× ÃÖ¼Ò°ª ±³È¯
	exchange1(arr);

	//2)ÀÎµ¦½º 10°ú ÀÎµ¦½º 90ÀÇ °ªÀ» ±³È¯
	exchange2(10, 90, arr);

	//3)ºóµµ¼ö°¡ °¡Àå ÀÛÀº °ªÀ» Ã£¾Æ Ãâ·Â
	min_frq(arr);

	printf("\nÃÖÁ¾ ¹è¿­ : \n");
	print_arr(arr);

	return 0;
}

int get_min(int arr[])
{
	int idx = 0;
	//¾Æ·¡¸¦ ¿Ï¼ºÇÏ½Ã¿À
	int minimmun = arr[0];
	for (int i = 0; i < ROW * COL; i++) {
		if (arr[i] < minimmun) {
			minimmun = arr[i];
			idx = i;
		}
	}

	return idx;
}
void get_max(int arr[][COL], int* pi, int* pj)
{
	*pi = *pj = 0;
	//¾Æ·¡¸¦ ¿Ï¼ºÇÏ½Ã¿À
	int maximun = arr[0][0];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (arr[i][j] > maximun) {
				maximun = arr[i][j];
				*pi = i;
				*pj = j;
			}
		}
	}

}
void exchange1(int arr[][COL])
{
	int min_idx, min_i, min_j, max_i, max_j;
	int tmp;

	min_idx = get_min((int*)arr);
	min_i = min_idx / COL;
	min_j = min_idx % COL;

	get_max(arr, &max_i, &max_j);

	printf("\n1) ±³È¯Àü ÃÖ¼Ò: arr[%d][%d]=%d, ÃÖ´ë:arr[%d][%d]=%d\n",
		min_i, min_j, arr[min_i][min_j], max_i, max_j, arr[max_i][max_j]);
	SWAP(arr[min_i][min_j], arr[max_i][max_j], tmp);
	printf("\n1) ±³È¯ÈÄ ÃÖ¼Ò: arr[%d][%d]=%d, ÃÖ´ë:arr[%d][%d]=%d\n",
		max_i, max_j, arr[max_i][max_j], min_i, min_j, arr[min_i][min_j]);
}

void exchange2(int idx1, int idx2, int arr[][COL])
{
	int i1, j1, i2, j2, tmp;
	//i1: idx1ÀÇ Çà ÀÎµ¦½º, j1: idx1ÀÇ ¿­ ÀÎµ¦½º
	//i2: idx2ÀÇ Çà ÀÎµ¦½º, j2: idx21ÀÇ ¿­ ÀÎµ¦½º

	//¾Æ·¡¸¦ ¿Ï¼ºÇÏ½Ã¿À
	i1 = idx1 / COL;
	j1 = idx1 % COL;
	i2 = idx2 / COL;
	j2 = idx2 % COL;


	SWAP(arr[i1][j1], arr[i2][j2], tmp);
	printf("\n2) ±³È¯ÈÄ ÀÎµ¦½º 10:arr[%d][%d]=%d, ÀÎµ¦½º 90:arr[%d][%d]=%d\n",
		i1, j1, arr[i1][j1], i2, j2, arr[i2][j2]);
}

void min_frq(int arr[][COL])
{
	int i, j, freq_min;//frea_min: ºóµµ¼ö ÃÖ¼Ò°ªÀÌ À§Ä¡ÇÑ freq ¹è¿­¿¡¼­ÀÇ ÀÎµ¦½ºÀÌ¸ç arr¹è¿­¿¡¼­ÀÇ ¿ø¼ÒÀÌ´Ù
	int freq[100] = { 0 }; //ÃÖ´ë Å©±â 100·Î ¼±¾ð
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			freq[arr[i][j]]++;

	//¾Æ·¡¸¦ ¿Ï¼ºÇÏ½Ã¿À
	int mini = 0;
	for (i = 0; i < 100; i++) {
		if (freq[i] <= mini) {
			freq_min = freq[i];
		}

	}


	printf("\n3) ÃÖ¼Ò ºóµµ¼ö:%d, ¿ä¼Ò: ", freq_min);
	for (i = 50; i < 100; i++)
		if (freq[i] == freq_min)
			printf("%d ", i);
	printf("\n");
}
/*½ÇÁ¦ Ãâ·Â°á°ú
ÃÖÃÊ ¹è¿­ :
91 67 84 50 69 74 78 58 62 64 55 95 81 77 61 91 95 92 77 86
91 54 52 53 92 82 71 66 68 95 97 76 71 88 69 62 67 99 85 94
53 61 72 83 73 64 91 61 53 68 97 94 62 57 87 59 73 91 79 78
66 85 90 92 88 56 90 92 64 98 96 55 90 79 70 50 56 51 93 98
79 73 84 54 56 90 66 76 81 58 94 89 76 73 87 88 68 82 79 91

1) ±³È¯Àü ÃÖ¼Ò: arr[0][3]=50, ÃÖ´ë:arr[1][17]=99

1) ±³È¯ÈÄ ÃÖ¼Ò: arr[1][17]=50, ÃÖ´ë:arr[0][3]=99

2) ±³È¯ÈÄ ÀÎµ¦½º 10:arr[0][10]=94, ÀÎµ¦½º 90:arr[4][10]=55

3) ÃÖ¼Ò ºóµµ¼ö:0, ¿ä¼Ò: 60 63 65 75 80

ÃÖÁ¾ ¹è¿­ :
91 67 84 99 69 74 78 58 62 64 94 95 81 77 61 91 95 92 77 86
91 54 52 53 92 82 71 66 68 95 97 76 71 88 69 62 67 50 85 94
53 61 72 83 73 64 91 61 53 68 97 94 62 57 87 59 73 91 79 78
66 85 90 92 88 56 90 92 64 98 96 55 90 79 70 50 56 51 93 98
79 73 84 54 56 90 66 76 81 58 55 89 76 73 87 88 68 82 79 91
°è¼ÓÇÏ·Á¸é ¾Æ¹« Å°³ª ´©¸£½Ê½Ã¿À . . .

*/
/*¿¹½Ã Ãâ·Â°á°ú
ÃÖÃÊ ¹è¿­ :
91 67 84 50 69 74 78 58 62 64 55 95 81 77 61 91 95 92 77 86
91 54 52 53 92 82 71 66 68 95 97 76 71 88 69 62 67 99 85 94
53 61 72 83 73 64 91 61 53 68 97 94 62 57 87 59 73 91 79 78
66 85 90 92 88 56 90 92 64 98 96 55 90 79 70 50 56 51 93 98
79 73 84 54 56 90 66 76 81 58 94 89 76 73 87 88 68 82 79 91

1) ±³È¯Àü ÃÖ¼Ò: arr[0][3]=50, ÃÖ´ë:arr[1][17]=99

1) ±³È¯ÈÄ ÃÖ¼Ò: arr[1][17]=50, ÃÖ´ë:arr[0][3]=99

2) ±³È¯ÈÄ ÀÎµ¦½º 10:arr[0][10]=94, ÀÎµ¦½º 90:arr[4][10]=55

3) ÃÖ¼Ò ºóµµ¼ö:0, ¿ä¼Ò: 60 63 65 75 80

ÃÖÁ¾ ¹è¿­ :
91 67 84 99 69 74 78 58 62 64 94 95 81 77 61 91 95 92 77 86
91 54 52 53 92 82 71 66 68 95 97 76 71 88 69 62 67 50 85 94
53 61 72 83 73 64 91 61 53 68 97 94 62 57 87 59 73 91 79 78
66 85 90 92 88 56 90 92 64 98 96 55 90 79 70 50 56 51 93 98
79 73 84 54 56 90 66 76 81 58 55 89 76 73 87 88 68 82 79 91
°è¼ÓÇÏ·Á¸é ¾Æ¹« Å°³ª ´©¸£½Ê½Ã¿À . . .
*/

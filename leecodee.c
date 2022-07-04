/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-02 17:05:02
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-02 18:11:26
 * @FilePath: \try2\leecodee.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

int i_cmp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), i_cmp);
	print(arr, sz);
	return 0;
}
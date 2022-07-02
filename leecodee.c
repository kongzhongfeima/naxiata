/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-02 17:05:02
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-02 18:07:06
 * @FilePath: \try2\leecodee.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

int i_cmp (const void* e1, const void* e2)          //qsort默认升序排序，想要降序排序只需要调                                   
{
	return *((int*)e2) - *((int*)e1);     //void*指针不能解引用，需要强制类型转换为int*型
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
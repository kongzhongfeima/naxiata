/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-11 22:14:51
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-11 23:31:23
 * @FilePath: \try2\findKthLargest_215.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//215. 数组中的第K个最大元素

#include "stdio.h"
int *findKthLargest(int* nums, int numsSize, int k)
{
    for(int i = 0; i < numsSize -1;  i++)
    {
        for(int j = i + 1; j < numsSize;  j++)
        {
            if(nums[i] >nums[j] )
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
    return nums;
}   

void main(void)
{
    int b[6] = {0};
    int a[6] = {3,2,1,5,6,4};
    int *p = b;
    p = findKthLargest(a, 6, 1);
    for(int i = 0; i < 6; i++)
    {
        printf("i = %d\r\n", p[i]);
    }
}
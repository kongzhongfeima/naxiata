/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-02 22:14:48
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-02 23:48:44
 * @FilePath: \try2\threeNum.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//参考解题方法：https://leetcode.cn/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
 #include "stdio.h"
 #include "stdlib.h"
 int comp(const void* a,const void* b)
 {
     return *((int*)a) - *((int*)b);
 }
int* threeSum(int* nums, int numsSize, int* returnSize, int* returnColumnSizes)
{
    if(numsSize < 3)
    {
        return ;
    }
    qsort(nums, numsSize, sizeof(int), comp);//升序排列
    for(int p = 0; p < numsSize; p++)
    {
        printf("nums[%d] = %d\r\n", p, nums[p]);
    }
    for(int i = 0; i<numsSize; i++)
    {
        if(nums[i] > 0)
            break;
        if(i > 0 && (nums[i] == nums[i-1]))
        {   
            printf("重复了！\r\n");
            continue;//去除重复
        }
        printf("i is %d\r\n", i);
        int m = i +1;
        int n = numsSize - 1;
        int returnSize = 0;
        while(m < n)
        {
            int mysum = nums[i] + nums[m] + nums[n];
            if(mysum == 0)
            {
                int *returnSuit = malloc(sizeof(int) * 3);
                returnSuit[returnSize] = i;
                returnSuit[returnSize+1] = m;
                returnSuit[returnSize+2] = n;
                printf("returnSuit[%d] = %d\r\n;" , returnSize , i);
                printf("returnSuit[%d] = %d\r\n;" , returnSize +1 , m);
                printf("returnSuit[%d] = %d\r\n;" ,returnSize + 2, n);
                returnSize += 3;
                while(nums[m] ==nums[m+1] )
                {
                    m++;
                }
                while(nums[n] == nums[n-1])
                {
                    n++;
                }
                m++;
                n--;
            }
            else if(mysum < 0)
            {
                m++;
            }
            else if(mysum > 0)
            {
                n--;
            }
        }
    }
}
void main(void)
{
    int nums[6] = {-1,0,1,2,-1,-4};
    int numsSize = 6;
    int *returnSize = NULL;
    int *returnColumnSizes = NULL;
    int *returnSuit = malloc(sizeof(int) * 3);

    returnSize, returnSuit = threeSum( nums,  numsSize,  returnSize,  returnColumnSizes);
}
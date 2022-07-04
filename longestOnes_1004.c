/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-04 21:22:40
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-04 22:11:15
 * @FilePath: \try2\longestOnes_1004.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//滑动窗口模板   参考文章：
//https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/

#include <stdio.h>
int max(int x, int y)
{
    return(x > y ? x :y);
}
int longestOnes(int* array, int k, int size)
{
    int res = 0, zeros = 0, left = 0;
    printf("array size is %d \r\n", size);
    for(int right = 0; right < size; right ++)//right需要主动移动一次
    {
        printf("right is %d \r\n", right);
        if(array[right] == 0)
        {
            zeros++;
            printf("zeros is %d\r\n", zeros);
        }
        while(zeros > k)//left需要被动移动不止一次
        {
            if(array[left++] == 0)
            {
                zeros--;                
                printf("left is %d\r\n", left);
            }
        }
        res = max(res , right - left + 1);
        printf("res is %d\r\n", res);
    }
    printf("its time to return !\r\n");
    return res;
}

void main(void)
{
    int a[11] = {1,1,1,0,0,0,1,1,1,1,0};
    int size = sizeof(a)/sizeof(int);
    int res = longestOnes(a, 2, size);
    printf("res is %d \r\n", res);
}

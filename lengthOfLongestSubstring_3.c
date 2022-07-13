/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-07 21:47:39
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-07 22:24:35
 * @FilePath: \try2\lengthOfLongestSubstring_3.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "stdio.h"
#include "string.h"
int lengthOfLongestSubstring(char * s){
    int left = 0, size = 0, final_size = 0;
    int len = strlen(s);
    printf("len is %d \r\n", len);
    for(int right = 1 ; right < len; right++)
    {
        if(s[right] != s[left])
        {
            size++;
            printf("s[%d] != s[%d] \r\n", right, left);
            printf("size is %d \r\n", size);
            final_size = (final_size > size ? final_size : size);
            printf("final_size is %d \r\n", final_size);
        }
        else
        {
            while (s[right] == s[left])
            {
                left++;
            }            
            size = 0;
        }
        printf("right is %d \r\n", right);
    }
    return (final_size + 1);
}

void main(void)
{
    //char s[20] = "abcabcbb";
    char s[20] = "bbbbb";
    int size = lengthOfLongestSubstring(s);
    printf("size is %d \r\n", size);
}
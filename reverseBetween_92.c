/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-13 10:45:48
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-13 11:05:43
 * @FilePath: \try2\wuliao.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//92. 反转链表 II
//https://leetcode.cn/problems/reverse-linked-list-ii/
#include "stdio.h"
struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
	if(head->next == NULL)
		return head;
    struct ListNode *dummyhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyhead->next =  head;
    struct ListNode *rightbianjie = head, *leftbianjie = dummyhead ;
    for(int i = 0; i < left - 1; i++) //得到left前一个节点
    {
        leftbianjie = leftbianjie->next;
    }
    struct ListNode *cur = leftbianjie->next; //cur为left边界节点 也是开始反转的节点
   for(int i = 1; i < right; i++)//得到right边界节点
   {
       rightbianjie = rightbianjie->next;
   }
   struct ListNode *pre = rightbianjie->next; //保存rightbianjie之后的链表;
   while(pre != rightbianjie)
   {
       struct ListNode *temp = cur->next;
       cur->next = pre;
       pre = cur;
       cur = temp;
   }
    leftbianjie->next = pre;
    return dummyhead->next;
}
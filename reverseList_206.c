/*
 * @Author: beicunxun 2929121301@qq.com
 * @Date: 2022-07-11 11:43:46
 * @LastEditors: beicunxun 2929121301@qq.com
 * @LastEditTime: 2022-07-11 16:05:46
 * @FilePath: \try2\reverseList_206.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//反转链表
// easy
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct student
{
    int val;
    struct student *next;
} ListNode;
//初始化链表
ListNode *creat(int n)
{
    ListNode *head, *end;
    head = (ListNode *)malloc(sizeof(ListNode));
    end = head;
    for (int i = 0; i < n; i++)
    {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->val = i;
        end->next = node;
        end = node;
    }
    end->next = NULL;
    //
    ListNode *cur = head->next;
    while (cur != NULL)
    {
        printf("cur->val is %d \r\n", cur->val);
        cur = cur->next;
    }
    //
    return head;
}
//遍历输出链表
void PutsListNode(ListNode *head)
{
    ListNode *cur = head->next;
    while (cur != NULL)
    {
        printf("cur->val is %d \r\n", cur->val);
        cur = cur->next;
    }
}
//在第N位添加节点
ListNode *head()
{
}
ListNode *reverseList(ListNode *head)
{
    if(head == NULL || head->next ==NULL)
        return head;
    ListNode *pre = NULL;
    ListNode *cur = head->next;
    while (cur)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    ListNode *newhead = (ListNode*)malloc(sizeof(ListNode));
    newhead->next = pre;
    return newhead;
}
void main(void)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head = creat(5);
    PutsListNode(head);

    head = reverseList(head);
    PutsListNode(head);
}
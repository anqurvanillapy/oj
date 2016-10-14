/**
 *  141. Linked List Cycle
 *
 *  Given a linked list, determine if it has a cycle in it.
 *
 *  - Follow up:
 *      + Can you solve it withou using extra space?
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head);

int
main(int argc, const char *argv[])
{
    struct ListNode *node0 = NULL;
    struct ListNode *node1 = NULL;
    struct ListNode *node2 = NULL;

    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;

    node0 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    node0->next = node1;
    node0->val = 0;

    node1->next = node2;
    node1->val = 1;

    node2->next = node0;
    node2->val = 2;

    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = node0;

    bool has_cycle = hasCycle(head);
    printf("has cycle? [0:false/1:true] %d\n", has_cycle);

    return 0;
}

/* === solution === */

bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

/* === EOS === */

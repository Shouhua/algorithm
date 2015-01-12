/*
This file is implemented func of singly list, some of algorithm are refer to website and some of them i can't agree with.
Author: Shouhua Peng
Date: 1/12/2014
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

int insert(Node **phead, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
    {
        fprintf(stderr, "allocate memory failed.\n");
        return -1;
    }
    node->data = data;
    node->next = *phead;
    *phead = node;
    return 0;
}

int delete(Node **phead, int data)
{
    Node **cur = phead;
    while(*cur != NULL)
    {
        Node *tmp = *cur;
        if(tmp->data == data)
        {
            *cur = tmp->next;
            free(tmp);
        }
        else
            cur = &tmp->next;
    }
    return 0;    
}

int reverse(Node **phead)
{
    Node *prev = *phead;
    Node *cur = prev->next;
    Node *tmp = NULL;
    prev->next = NULL;
    while(cur)
    {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    *phead = prev;
    return 0;
}

int count(Node **phead)
{
    Node *cur = *phead;
    int c = 0;
    while(cur)
    {
        cur = cur->next;
        ++c;
    }
    return c;
}

int sort(Node **phead)
{
    int i, j, tmp;
    int n = count(phead);
    Node *prev, *cur, *tmp_node;
    for(i=0;i<n-1;i++)
    {
        prev = *phead;
        cur = prev->next;
        for(j=0;j<n-i-1;j++)
        {
            if(prev->data > cur->data)
            {
                tmp = prev->data;
                prev->data = cur->data;
                cur->data = tmp;
            }
            tmp_node = cur->next;
            prev = cur;
            cur = tmp_node;
        }
    }
    return 0;
}

int remove_head(Node **phead)
{
    Node *head = *phead;
    if(head && head->next)
        head = head->next;
    *phead = head;
    return 0;
}

Node *search_mid(Node **phead)
{
    Node *mid = *phead;
    Node *tmp = *phead;
    while(tmp->next !=NULL && tmp->next->next != NULL)
    {
        mid = mid->next;
        tmp = tmp->next->next;
    }
    return mid;
}

void print(Node **phead)
{
    Node *tmp = *phead;
    for(;tmp;tmp=tmp->next)
    {
        printf("%d ", tmp->data);
    }
    printf("\n");
}

int main()
{
    int i;
    Node *node = NULL;
    for(i=0; i<5; i++)
    {
        insert(&node, rand() % 100);    
    }
    print(&node);
    delete(&node, 3);
    print(&node);
    printf("begin reverse node....\n");
    reverse(&node);
    print(&node);
    int c = count(&node);
    printf("the singly list length is: %d\n", c);
    sort(&node);
    print(&node);
    printf("mid value is: %d\n", search_mid(&node)->data);
    remove_head(&node);
    print(&node);
    exit(0);
}

/******************/
/* Leroy Valencia */
/*    05/7/20    */
/*   CS-241-006   */
/******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"

struct ListNode* createNode(int data)
{
  struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode*));
  list->next = NULL;
  return list;
}

struct ListNode* insertSorted(struct ListNode* head, int data)
{
  struct ListNode* current; 
  struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
  newNode->data = data; 
  if (head == NULL || (head)->data >= newNode->data) 
  { 
      newNode->next = head; 
      head = newNode; 
  } 
  else
  { 
      current = head; 
      while (current->next != NULL && current->next->data < newNode->data) 
      { 
          current = current->next; 
      } 
      newNode->next = current->next; 
      current->next = newNode; 
  } 
return head;


}

int removeItem(struct ListNode** headRef, int data)
{
  struct ListNode* temp = *headRef, *prev;

  if(temp != NULL && temp->data == data)
  {
    *headRef = temp->next;
    free(temp);
    return 1;
  }

  while(temp != NULL && temp->data != data)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) return 0;

  prev->next = temp->next;
  free(temp);
  return 1;
}

struct ListNode* pushStack(struct ListNode* head, int data)
{
  struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode*));

  if(temp == NULL) return head;

  temp->data = data;
  temp->next = head;

  head = temp;
  return head;
}

int popStack(struct ListNode** headRef)
{
  
  if(*headRef != NULL)
  {
    struct ListNode* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
  }
  return (*headRef)->data;
}

int listLength(struct ListNode* head)
{
  int count;
  struct ListNode* temp;
  count = 0;
  temp = head;
  while(temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

void printList(struct ListNode* head)
{
  printListHelper(head);
  printf("\n");
}
void printListHelper(struct ListNode* head)
{
  int count;
  count = 0;
  while(head != NULL)
  {
    if (count > 0)
    {
      printf(", %d", head->data);
    }
    else
    {
      printf("%d", head->data); 
    }
    head = head->next;
    count++;
  }
}

void freeList(struct ListNode* head)
{
  struct ListNode* temp;

  while(head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void reverseList(struct ListNode** headRef)
{
  struct ListNode* previous = NULL;
  struct ListNode* next = NULL;
  struct ListNode* current = *headRef;

  while(current != NULL)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *headRef = previous;
}
/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1 == NULL || *head2 == NULL)
	{
		return -1;
	}
	struct node *temp11, *temp22,*temp1,*temp2,*head;
	temp1 = *head1;
	temp2 = *head2;
	temp11 = *head1;
	temp22 = *head2;
	while (temp1->next != *head1)
	{
		temp11 = temp11->next;
		temp1 = temp1->next;
	}
	while (temp2->next != *head2)
	{
		temp22 = temp22->next;
		temp2 = temp2->next;
	}
	temp1 = *head1;
	temp2 = *head2;
	if (temp1->data < temp2->data)
	{
		head = *head1;
	}
	else
	{
		head = *head2;
	}
	if (temp1->data < temp2->data)
	{
		temp22->next = (temp22->next)->next;
		temp2->next = temp1->next;
		temp1->next = temp2;
		temp1 = temp2->next;
		temp2 = temp22->next;
	}
	else
	{
		temp11->next = (temp11->next)->next;
		temp1->next = temp2->next;
		temp2->next = temp1;
		temp2 = temp1->next;
		temp1 = temp11->next;
	}
	while (temp1 != temp11->next||temp2!=temp22->next)
	{
		if (temp1->data < temp2->data)
		{
			temp22->next = (temp22->next)->next;
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp1 = temp2->next;
			temp2 = temp22->next;
		}
		else
		{
			temp11->next = (temp11->next)->next;
			temp1->next = temp2->next;
			temp2->next = temp1;
			temp2 = temp1->next;
			temp1 = temp11->next;
		}
		if (temp1 == temp11->next&&temp2 != temp22->next)
		{
			temp1->next = temp2;
			temp22->next = head;
			break;

		}
		if (temp1 != temp11->next&&temp2 == temp22->next)
		{
			temp2->next = temp1;
			temp11->next = head;
			break;
		}

	}
	int count = 1;
	*head1 = head;
	temp1 = head->next;
	while (temp1 != head)
	{
		count++;
		temp1 = temp1->next;
	}
	return count;
}
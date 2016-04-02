/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
	{
		return -1;
	}
	int dob1[8], dob2[8],i=0,da1,da2,m1,m2,y1,y2,diff=0,mon;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	struct node *temp1,*temp2;
	temp1 = date1head;
	temp2 = date2head;
	while (i<8)
	{
		dob1[i] =temp1->data;
		dob2[i] = temp2->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
		i++;
	}
	da1 = (dob1[0] ) * 10 + (dob1[1]);
	da2 = (dob2[0]  ) * 10 + (dob2[1]);
	m1 = (dob1[2] ) * 10 + (dob1[3] );
	m2 = (dob2[2] ) * 10 + (dob2[3] );
	y1 = (dob1[4] ) * 1000 + (dob1[5] ) * 100 + (dob1[6]) * 10 + (dob1[7]);
	y2 = (dob2[4] ) * 1000 + (dob2[5] ) * 100 + (dob2[6]) * 10 + (dob2[7]);
	if (y2 == y1)
	{
		if (m2 == m1)
		{
			if (da2 > da1)
			{

				diff = da2 - da1-1;
				return diff;
			}
			else
			{
				diff = da1 - da2-1;
				return diff;
			}
		}
		else
		{
			if (m1 > m2)
			{
				while (m1!= m2)
				{
					 mon = month[m2];
					m2++;	
				}
				diff = mon  + (da1 - da2-1);
				return diff;
			}
			else
			{
				while (m2 != m1)
				{
					mon = month[m1];
					m1++;
				}
				diff = mon + (da2 - da1 - 1);
				return diff;
			}
		}
	}
	else
	{
		if (y1 > y2)
		{
			diff = ((y1 - y2) * 365) + ((m1 - m2) * 30) + da1 - da2-1;
			while (y2 != y1)
			{
				if (y1 % 4 ==0)
				{
					diff = diff + 1;
				}
				y1++;
			}
			if (y2 % 4 == 0 && m2 > 2)
			{
				diff = diff + 1;
			}
			return diff;
		}
		else
		{
			diff = ((y2 - y1) * 365) + ((m2 - m1) * 30) + da2 - da1-1;
			while (y1 != y2)
			{
				if (y2 % 4 == 0)
				{
					diff = diff + 1;
				}
				y2++;
			}
			if (y1 % 4 == 0 && m1 > 2)
			{
				diff = diff + 1;
			}
			return diff;
		}
	}
}
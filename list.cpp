#include<iostream>
#include "list.h"
List::List()
{
	head = prev = cursor = NULL;
}

bool List::listIsEmpty()
{
	return (head == NULL);
}
bool List::cursIsEmpty()
{
	return (cursor == NULL);
}
void List::toFirst()
{
	cursor = head;
	prev = NULL;
}
bool List::atFirst()
{
	return(cursor == head);
}
void List::advance()
{
	prev = cursor;
	cursor = cursor->next;
}
void List::toEnd()
{
	toFirst();
	if(!listIsEmpty())
	while(cursor->next !=NULL)
	advance();
}
bool List::atEnd()
{
	if(listIsEmpty())
	return true;
	else if (cursIsEmpty())
	return false;
	else
	return (cursor-> next == NULL);
}
int List::listSize()
{
	int counter = 0;
	Student* temp;
	temp = head;
	while(temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}
void List::updateData(const string &n)
{
	cursor->name = n;
}
string List::retreiveName()
{
	return cursor->name;
}
int List::retreiveId()
{
	return cursor->id;
}
void List::insertFirst(int i, string n)
{
	Student* s = new Student;
	s->id = i;
	s->name = n;
	s->next = head;
	head = s;
	cursor = s;
	prev = NULL;
}
void List::insertAfter(int i, string n)
{
	Student* s = new Student;
	s->id = i;
	s->name = n;
	s->next = cursor->next;
	cursor->next = s;
	prev= cursor;
	cursor = s;
}
void List::insertBefore(int i, string n)
{
	Student* s = new Student;
	s->id = i;
	s->name = n;
	s->next = cursor;
	prev->next = s;
	cursor = s;
}
void List::insertEnd(int i, string n)
{
	if(listIsEmpty())
	insertFirst(i,n);
	else
	{
		toEnd();
		insertAfter(i,n);
	}
}
void List::deleteStudent()
{
	Student* delptr;
	delptr = cursor;
	if(!cursIsEmpty())
	{
		if(atFirst())
		{
			head = cursor->next;
			prev = cursor;
			delete delptr;
		}
		else
		{
			cursor = cursor->next;
			prev->next = cursor;
			delete delptr;
		}
	}
		
}
void List::deleteFirst()
{
	if(!listIsEmpty())
	{
		toFirst();
		deleteStudent();
	}
}
void List::deleteEnd()
{
	if(!listIsEmpty())
	{
		toEnd();
		deleteStudent();
	}
}
void List::makeListEmpty()
{
	if(!listIsEmpty())
	{
		toFirst();
		while(cursor!=NULL)
		{
			deleteStudent();
		}
	}
}
bool List::searchStudent(const int i)
{
	bool found = false;
	toFirst();
	while((!found)&&(cursor !=NULL))
	{
		if(i == cursor->id )
		found = true;
		else
		advance();
	}
	return found;
}
void List::orderInsert(const int &i, const string &n)
{
	toFirst();
	while((cursor!=NULL)&&(i>cursor->id))
	advance();
	if(prev == NULL)
	insertFirst(i,n);
	else
	insertBefore(i,n);
}
void List::traverse()
{
	if(!listIsEmpty())
	{
		toFirst();
		while(cursor!=NULL)
		{
		cout<<"Id is "<<cursor->id<<" The name is "<<cursor->name<<endl;
		advance();	
		}
		
	}
}

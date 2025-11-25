#include<iostream>
#include "list.h"
#include<string>
using namespace std;

int main()
{
	List L;
	L.insertFirst(1, "Medhat");
	L.insertAfter(5, "Mohamed");
	L.traverse();
	if(L.searchStudent(5))
	cout <<"The student you searched for is Found"<<endl;
	L.orderInsert(3, "Mariam");
	L.traverse();
	return 0;
}

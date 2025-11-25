#include<iostream>
#include<string>
using namespace std;
class List{
	class Student{
		public:
			int id;
			string name;
			Student* next;
	};
	public:
		Student* head, *cursor, *prev;
		List();
		bool listIsEmpty();
		bool cursIsEmpty();
		void toFirst();
		bool atFirst();
		void advance();
		void toEnd();
		bool atEnd();
		int listSize();
		void updateData(const string &n);
		string retreiveName();
		int retreiveId();
		void insertFirst(int i, string n);
		void insertAfter(int i, string n);
		void insertBefore(int i, string n);
		void insertEnd(int i, string n);
		void deleteStudent();
		void deleteFirst();
		void deleteEnd();
		void makeListEmpty();
		bool searchStudent(const int i);
		void orderInsert(const int &i, const string &n);
		void traverse();
};

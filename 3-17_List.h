#ifndef LIST_H_
#define LIST_H_
#include <iostream>

class List{
	typedef struct strnode{
		char str[20];
		struct strnode * next;
	} node;
	node * head;
	int count;
public:
	List();
	List(const List & L);
	~List();
	void Insert(int pos, char* item);
	void Delete(int pos);
	void search(int pos, char* item) const;
	void show() const;
	bool isEmpty() {return (count == 0);}
	int length() const {return count;}
};

#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {

private:
	struct node {
		int data;
		node* next;
	};
	
	typedef struct node* nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	LinkedList();

	void AddNode(int addData);
	void DeleteNode(int delData); 
	/*** This deleteNode function goes through the data until it finds the data 
	that matches the delData parameter's argument, and deletes that NODE	***/
	void PrintList();
};

#endif // !LIST_H


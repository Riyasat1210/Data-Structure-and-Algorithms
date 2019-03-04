#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void LinkedList::AddNode(int addData) {
	nodePtr n = new node;
	n->next = NULL;					// These 3 lines, creates a new node, sets the data and sets Next as Null considering end case
	n->data = addData;				// The if block inserts this newly created node at the end of the list after traversing curr through it.

	if (head != NULL) {				// If we already have a list with at least one element
		curr = head;
		while (curr->next != NULL) {  // While we are not at the end of the list (curr->next = NULL only at list end)
			curr = curr->next;        // The curr now goes through the list, and when at end, 
			                          //the loop ends, leaving curr pointing to the last node.
		}
		curr->next = n;  // Here curr points to the last node of the already existing list. it now sets last node's NEXT pointer
						 // to the newly created "n" node.
	}

	else {							// If there is no list, then we just make the new node as the first/head node.
		head = n;
	}

}

void LinkedList::DeleteNode(int delData) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->data != delData) {    //run the while loop till the end (we hit NULL), and till the data is not equal to the
		temp = curr;								   // one we are looking for. If it is, then we already got where we want to be, no need for more.
		curr = curr->next; 
	}
	if (curr == NULL) {   //Means we went through the entire list, didnt get the data
		std::cout << delData << " was not in the list \n";
		delete delPtr;                // For deleting the floating pointer.
	}
	else {			// we found the node with the matching data
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}

		delete delPtr;
		std::cout << "The value" << delData << " was deleted\n";
	}
}

void LinkedList::PrintList() {
	curr = head;
	while (curr != NULL) {
		std::cout << curr->data << "\n";
		curr = curr->next;
	}
}
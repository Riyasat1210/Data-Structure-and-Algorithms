#include <cstdlib>
#include "LinkedList.h"
#include <iostream>


int main(int argc, char** argv) {
	
	LinkedList Rio;

	Rio.AddNode(3);
	Rio.AddNode(5);
	Rio.AddNode(7);
	Rio.PrintList();
	
	Rio.DeleteNode(3);
	Rio.PrintList();


	std::cin.get();
	return 0;
}
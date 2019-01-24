/*
	Jared Westmoreland
	CSCE 2110: Foundations 2 section 2
	March 3, 2017
*/
//header
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <stdio.h>
using namespace std;

/*Creates the linked list for the Set.C function*/
class node{
        public:
        int number;	//the value, i, then stores it into the linked list
	int id;		//this is nothing, but this was just in case if I need an ID for the linked list
        node *next;	//moves the linked list to next 
	node *prev;
};


//A new class for Sets
class Set
{
	public :
	//All the node that I shall need
	node* head=NULL;
	node* end=NULL;
	node* current=NULL;
	node* current1=NULL;
	node* prev = NULL;

	//all the overloaded operators and etc
	void clear();			//clears
	void addToSet(int i);		//adds
	void removeFromSet(int i);	//removes
	int cardinality();		//counts how many
	void operator=(const Set& s);   // copy a set	--Prof. Sweany
	Set operator&(const Set& s);	// intersection		^^
	Set operator|(const Set& s);	// union		^^
	Set operator^(const Set& s);	// exclusive OR		^^
	Set operator-(const Set& s);	// set difference	^^
	void printSet();		// prints
};


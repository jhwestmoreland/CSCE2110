#include "Set.h"

/*
	Each value, i,  from main.C is then put into a Link List with this function, addToSet.
	was able to find this information "stackoverflow.com/questions/11328162/stdset-for-each-element-in-an-array"
*/
void Set::addToSet (int i)
{
	//I know it's no organized like your set example, but it does put them in order of placement
	//If no head for the linked list/ set
	if (!head)
	{
		head = (struct node*) malloc (sizeof(class Set));
		head->next = NULL;
		end = head;
	}
	//If had a head than stores it after
	else
	{
		end->next = (struct node*) malloc (sizeof(class Set));
		end = end->next;
		end->next = NULL;
	}
	end->number = i;
}

//Removes any value, i, given
void Set::removeFromSet (int i)
{
	//creates a new node
	current = head;
	//If value is the same as the head
	if(!current)
	{
		cout<<"Error: Not found fo Removal: "<<i <<endl;
		return;
	}
	else if (current->number == i)
	{
		//deletes head
		while(current->number == i)
		{
			current = head->next;
			delete head;
			head = current;
		}
	}
	//if the value does not match the head
	else
	{
		//goes through the linked list
		while (current)
		{
			//if finds value that matchs I
			if (current->number == i)
			{
				//delete value
				prev->next = current->next;
				delete current;
				current = prev->next;
			}
			//if not move it down
			else if(current->number != i && current != head)
			{
				 cout<<"what"<<endl;
				prev = current;
				current = current->next;
			}
			else
			{
				cout<<"Unable to located therefore unable to remove from set"<<endl;
				return;
			}
		}
	}

}
//print the set, linked list.
void Set::printSet()
{
	current = head;
	//if  does not have a head than it makes this bracket indicating there is no set
	if(!current)
	{
		cout<<"{}"<<endl;
		return;
	}
	//If there is a head print
	else{
		cout << "{" << current->number;
        	current = current->next;
		//goes through the copied linked list until the end
		while (current)
		{
			cout <<	", " << current->number;
			current = current->next;
		}
		cout << "}" << endl;
	}
}
//clear the actual linked list
void Set::clear()
{
	//goes until head is empty
	while(head)
	{
		head = head->next;
	}
}
//counts the amount of links in the linked list
int Set::cardinality()
{
	int i = 0;
	current = head;
	//goes until the copy head is done
	while (current)
	{
		//this counts how many
		i++;
		//deletes the tail to the head
		current = current->next;
	}
	return i;
}

//the equal operator
/*
	I basically toyed with this until I got the results I needed
	I used these websites for help
	-http://users.cms.caltech.edu/~donnie/cs11/cpp/cpp-ops.html	(this one kinda helped)
	-http://www.geeksforgeeks.org/this-pointer-in-c/
	-https://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm  (this one really helped)
*/
void Set::operator=(const Set& s)
{
	node *current = s.head;

	//points to clear
	this->clear();

	//goes to until copy head
	while(current)
	{
		//then points to addToSet
		this->addToSet(current->number);
		current = current->next;
	}
}

/*
	This is interection and compares each value
	For the result.addToSet(current->number)
	I looked at many places for help, but this website helped the most with my program
	with the understanding of Data Structures using Linked list
	-http://stackoverflow.com/questions/9758922/c-set-data-structure-using-linked-list
*/
Set Set::operator&(const Set& s)
{
	Set result;
	//this allows me to have two linked list and be able to compare or basically do whatever I want
	current = head;
        current1 =s.head;
	//No head
	if(!head)
        {
                cout<<"{}"<<endl;
        }
	//if head
        else
	{
                while (current)
                {
			while(current1)
			{
				//Goes through each value and compares them both, if they equal
				if(current->number == current1->number)
				{
					//add to the linked list of set[x]
					result.addToSet(current->number);
				}
				//if goes to the end of current and current1
				else if(current->next == NULL && current1->next == NULL)
				{
					//return to results
					return result;
				}
				//keeps current1 moving to next
				current1 = current1->next;
			}
			//keep current moving to next
			current = current->next;
			//resets current1's head
			current1 = s.head;
		}
	}
}
/*
	This operator basically combines sets
*/

//This is the union operator and I used my knowledged I gained from the interection
Set Set::operator|(const Set& s)
{
	Set result;
	//copy of heads
	current = head;
	current1 = s.head;
	//makes a new node
	node *prev = NULL;

	while (current)
        {
                while(current1)
                {
			//compares each value and deletes them from the linked list
			if(current->number == current1->number)
			{
				prev->next = current1->next;
				delete current1;
				current1 = prev->next;
			}
			else
                        {
                                prev = current1;
				//goes to the linked list because they are not the same
				result.addToSet(prev->number);
                                //keeps current1 moving to next
				current1 = current1->next;
                        	if(current->next == NULL){break;}
			}
		}
		current1 = head;
		//keeps current moving to next
		current = current->next;
	}
	//resets current
	current = head;
	//until current is gone
	while(current)
	{
		//puts value into results
		result.addToSet(current->number);
		current = current->next;
	}
	return result;
}

/*
	This basically does the opposite of UNION, &.
	If they have he same values kick them out until you have no
	similar values
*/

//Difference operator
Set Set::operator-(const Set& s)
{
	Set result;
        current = head;	//copies head
        current1 = s.head;//copies head
	node *prev = NULL;//makes new list
	int i= 0;

	//goes unil head
	while(current)
	{
		//same
		while(current1)
		{
			i++;
			//if head of value = head of value
			if(current->number == current1->number && i ==1)
			{
				//delete head
				current = head->next;
                		delete head;
		                head = current;
			}
			//if current->next equals something in current1
			else if(current->number == current1->number && i != 1)
			{
				//delete it
				prev = current->next;
				delete current;
                        	current = prev;
			}
			//if not record
			else
			{
				prev = current1;
                                //goes to the linked list because they are not the same
                                result.addToSet(current->number);
                                //keeps current1 moving to next
                                current1 = current1->next;
			}
			//move
			current1 = current1->next;
		}
		//move
		current = current->next;
		//reset
		current1 = s.head;
	}
	return result;
}



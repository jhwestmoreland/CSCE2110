/*
	Jared Westmoreland	-jaredwestmoreland@my.unt.edu-	-11022685-
	Computer Foundations 2	-Doctor Sweany-
	Description:	Creates an array and finds the optimal path and records the path and the cost
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int distanceS = 99999999;	//doubt you'll get past this amount
string distL;			//This will go through its matrix and will find required stuff
int Count = 0;			//This will keep track of all the amount
int distanceA[15][15];		//This will acquire the distance

int replace(string position, int i);	//replace
void swap(string &str, string &str2);	//swap
void rearrage(string np, int i, int k); //rearrage

int main()
{
	//These will record all the values within the redirected input
	string str;
	string str2;
	string str3;
	string str4;

	//goes through the file to get the input and stores it in the first string
	while(cin >> str)
	{
		//if able to find c than record the value
		if(str == "c")
		{
			cin >> str2;	//store the columns and the rows
			Count++;	//starts the count
		}
		else if(str == "a")	//if finds a
		{
			cin >> str2 >> str3 >> str4;	//records all the inputs
			//converts all the string values into int values
			int found = atoi(str2.c_str());
			int found1 = atoi(str3.c_str());
			int found2 = atoi(str4.c_str());
			//puts it into array
			distanceA[found - 1][found1 - 1] = found2;
			distanceA[found1 - 1][found - 1] = found2;
		}
	}

	//I had to look this up
	string permuteFull = "123456789ABCD"; //Easier to use Hexidemical than decimal
	string np;
	np = permuteFull.substr(1, Count - 1);
	rearrage(np, 0, Count - 1);

	cout << "The tour ";
	//this will go through the matrix that was spit out the recorded input
	for(int i = 0; i <= Count; i++)
	{
		//if A, B, C, D(because I used Hexadecimal) cout 10, 11, 12, 13
		if(distL[i] == 'A')
		{
			cout << "10 ";
			i++;
		}
		else if(distL[i] == 'B')
		{
                        cout << "11 ";
                        i++;
              	}
		else if(distL[i] == 'C')
              	{
                        cout << "12 ";
                        i++;
              	}
		else if(distL[i] == 'D')
              	{
                        cout << "13 ";
                        i++;
              	}
		//if an actual # spit it out
		cout << distL[i] << " ";
	}
	//displays the cost
	cout << "costs " << distanceS << endl;
	return 0;
}

//This is where it will record the cost
int replace(string position, int i)
{
	//compares
	if(position[i] == '1')
	{
		return(1);
	}
	else if(position[i] == '2')
	{
		return(2);
	}
	else if(position[i] == '3')
	{
		return(3);
	}
	else if(position[i] == '4')
	{
		return(4);
	}
	else if(position[i] == '5')
	{
		return(5);
	}
	else if(position[i] == '6')
	{
		return(6);
	}
	else if(position[i] == '7')
	{
		return(7);
	}
	else if(position[i] == '8')
	{
		return(8);
	}
	else if(position[i] == '9')
	{
		return(9);
	}
	else if(position[i] == 'A')
	{
		return(10);
	}
	else if(position[i] == 'B')
	{
		return(11);
	}
	else if(position[i] == 'C')
	{
		return(12);
	}
	else if(position[i] == 'D')
	{
		return(13);
	}
	else
	{
		return(0);
	}
}

//swaps
void swap(string &str, string &str2)
{
	string temporay;
	temporay = str;
	str = str2;
	str2 = temporay;
}

//This replaces and swaps everything linking everything up
void rearrage(string np, int i, int k)
{
	int j=0;
	if(i == k)
	{
		string npp = '1' + np + '1';
		int temp = 0;

		int startCarryOver = 1;
		int destCarryOver = replace(npp, k + 1);
		for(int m = 0; m < Count; m++)
		{
			int start = replace(npp, m) - 1;
			int dest = replace(npp, m + 1) - 1;
			temp += distanceA[start][dest];
		}
		//compares the values
		if(temp < distanceS)
		{
			distanceS = temp;
			distL = npp;
		}

	}
	else
	{
		//this swaps and uses recurtion to reorganize
		for(j = i; j < np.length(); j++)
		{
			swap(np[i], np[j]);
			rearrage(np, i + 1, k);
			swap(np[i], np[j]);
		}
	}
}

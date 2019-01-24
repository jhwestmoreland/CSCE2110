
/*
	Jared Westmoreland
	CSCE 2110 Computer Foundations II- Section 001 (Spring 2017 1)
	ID: 11022685
	Program 3
	Easier Program

	Description:
	-Organizes the classes
*/
#include <iostream>
using namespace std;

int main()
{
	//All my childish variables
	string matrix[800][800]; //my main matrix
	int o=0;
	int a=0;
	int k= 0;
	string str;
	string classes[800];
	int students[800];
	int space[800];
	string rooms[800];

	//makes it look "pretty"
	cout<<endl;

	//redirected input
	while(cin>>str)
	{
		//will look for classes and k==0, which is default
		if(str != "Classes" && k == 0 && str != "Rooms")
		{
			o++;
			classes[o] = str;	//gets the Course
			cin>>students[o];	//gets the amount in the course
		}
		//If it finds "Rooms" the if statement above no longer wants it
		else if(str == "Rooms")
		{
			k = 1;
		}
		else if(str != "Classes" && k == 1 && str != "Rooms")
		{
			a++;
			rooms[a] = str;		//gets Room number
			cin>>space[a];		//gets the space in the room
		}
	}
	//makes it pretty
	cout<<endl;

	//More variables
	int temp;
	string temp1;

	//Organizes the class size from greatest to least and also reorganizes the class
	for(int i=1; i<=o; i++)
	{
		for(int j=1; j<= o; j++)
		{
			if(space[i] <= space[i+j] && space[i+j] != 0)
			{
				temp = space[i];
				space[i] = space[i+j];
				space[i+j]= temp;

				temp1= rooms[i];
				rooms[i] = rooms[i+j];
				rooms[i+j] = temp1;
			}
		}
	}

	//organizes the amount of students in the class from least to greatest and also reorganizes the Class
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<= a; j++)
		{
			if(students[i] >= students[i+j] && students[i+j] != 0)
			{
                	        temp = students[i];
                	        students[i] = students[i+j];
                	        students[i+j]= temp;

				temp1= classes[i];
				classes[i] = classes[i+j];
				classes[i+j] = temp1;
			}
		}
	}

	//this compares it and puts everything into the matrix
	for(int j=0; j<=5; j++)
	{
		for(int i=1; i<=7; i++)
		{
			if(students[i] > 0)
			{
				matrix[j][i] = classes[i] + " / " + rooms[i];
				students[i] = students[i] - space[i];
			}
			//shifts the largest amount down and removes the smallest
			else if(students[i] <= 0 && j>=0)
                        {
                        	space[i+1] = space[i];
                        }

		}
	}

	//Display all the way down
	cout<<"Monday's Final   | 08:00am-       10:00am-       12:00pm-       02:00pm-       04:00pm-       06:00pm-       08:00pm-"<<endl
            <<"Schedule         | 09:50am        11:50am        01:50pm        03:50pm        05:50pm        07:50pm        10:00pm"<<endl
	    <<"---------------- | ---------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=1; i<= o; i++)
        {
		cout<<"Course / Room    | ";
		for(int j=0;  j<= 7; j++)
		{
       		        cout<<matrix[j][i]<<"    ";
		}
		cout<<endl;
        }

	cout<<"\n\n"
	    <<"Tuesday's Final  | 08:00am-       10:00am-       12:00pm-       02:00pm-       04:00pm-       06:00pm-       08:00pm-"<<endl
            <<"Schedule         | 09:50am        11:50am        01:50pm        03:50pm        05:50pm        07:50pm        10:00pm"<<endl
            <<"---------------- | ----------------------------------------------------------------------------------------------------------"<<endl;

	for(int i=1; i<= o; i++)
        {
                cout<<"Course / Room    |  ";
                for(int j=8;  j<= 15; j++)
                {
                        cout<<matrix[j][i]<<"    ";
                }
                cout<<endl;
        }

	cout<<"\n\n"
	    <<"Wednesday's Final| 08:00am-       10:00am-       12:00pm-       02:00pm-       04:00pm-       06:00pm-       08:00pm-"<<endl
            <<"Schedule         | 09:50am        11:50am        01:50pm        03:50pm        05:50pm        07:50pm        10:00pm"<<endl
            <<"---------------- | ----------------------------------------------------------------------------------------------------------"<<endl;

	for(int i=1; i<= o; i++)
        {
                cout<<"Course / Room    |  ";
                for(int j=16;  j<= 23; j++)
                {
                        cout<<matrix[j][i]<<"   ";
                }
                cout<<endl;
        }


	cout<<"\n\n"
	    <<"Thursday's Final | 08:00am-       10:00am-       12:00pm-       02:00pm-       04:00pm-       06:00pm-       08:00pm-"<<endl
            <<"Schedule         | 09:50am        11:50am        01:50pm        03:50pm        05:50pm        07:50pm        10:00pm"<<endl
            <<"---------------- | ----------------------------------------------------------------------------------------------------------"<<endl;

	for(int i=1; i<= o; i++)
        {
                cout<<"Course / Room    |  ";
                for(int j=24;  j<= 31; j++)
                {
                        cout<<matrix[j][i]<<"   ";
                }
                cout<<endl;
        }

	cout<<"\n\n"
            <<"Friday's Final   | 8:00am-        10:00am-       12:00pm-       02:00pm-       04:00pm-       06:00pm-       08:00pm-"<<endl
	    <<"Schedule         | 09:50am        11:50am        01:50pm        03:50pm        05:50pm        07:50pm        10:00pm"<<endl
            <<"---------------- | ----------------------------------------------------------------------------------------------------------"<<endl;

	for(int i=1; i<= o; i++)
        {
                cout<<"Course / Room    |  ";
                for(int j=32;  j<= 39; j++)
                {
                        cout<<matrix[j][i]<<"   ";
                }
                cout<<endl;
        }



	cout<<endl<<endl;
}


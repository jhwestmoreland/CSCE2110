#include "Set.h"
#include "number.h"

int main()
{
    // *******************************************
    //
    //  THIS main, which is what you'll be responsible
    //  for completing for both the characteristic vector
    //  AND List approach.
    //
    // *******************************************

    Set sets[NUM_OF_SETS];

    sets[1].addToSet(27);
    sets[1].addToSet(0);
    sets[1].addToSet(109);
cout << "Checking set sets[1]" << endl;
    sets[1].printSet();

    sets[2].addToSet(43);
    sets[2].addToSet(34);
    sets[2].addToSet(27);
cout << "Checking set sets[2]" << endl;
    sets[2].printSet();

    sets[3].clear();
cout << "Checking set sets[3] before intersection" << endl;
    sets[3].printSet();
cout << "Performing sets[3] = sets[1] & sets[2] " << endl;
    sets[3] = sets[1] & sets[2];
    sets[3].printSet();
    cout << "The intersection of sets[1] and sets[2] is " << endl;
    sets[3].printSet();
    sets[3].clear();
cout << "Checking set sets[3] before union" << endl;
cout << "Performing sets[3] = sets[1] | sets[2] " << endl;
    sets[3] = sets[1] | sets[2];
    cout << endl << "The union of sets[1] and sets[2] is " << endl;
    sets[3].printSet();
cout << "About to test cardinality" << endl << endl;
cout << "The cardinality of S3 = " << sets[3].cardinality() << endl << endl;

cout<<"Difference sets[4] = sets[3] - sets[2]"<<endl;
   sets[4] = sets[3] - sets[2];
    sets[4].printSet();
cout << "About to test removeFromSet" << endl << endl;
cout << "S14 after 109 is removed = " << endl;
    sets[4].removeFromSet(109);

	sets[4].printSet();

  return 0;

}

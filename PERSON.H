#include "string.h"

class person {
public:
	string lastname;
	string firstname;
	string street;
	string zipCode;
	string phoneNumber;
	string filename;

	//Constructors

    person();
    //Default constructor.  Nullifies all fields
	
    person(string l,string f, string s, string z, string p, string fi);
	//Constructor.  Sets the fields l=lastname, f=firstname, ...
    //fi=filename
    
    //Miscellaneous functions
    
    string Key();
    //Returns the search key
};

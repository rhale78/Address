#include "person.h"

//Default Constructor
//Make a null person
person::person()
{
	//nullify all fields
    lastname="";
	firstname="";
	street="";
	zipCode="";
	phoneNumber="";
	filename="";
}

//Constructor
//Create a person based on the fields
person::person(string l,string f, string s, string z, string p, string fi)
{
	//set the fields to whatever they need to be
    lastname=l;
	firstname=f;
	street=s;
	zipCode=z;
	phoneNumber=p;
	filename=fi;
}

//Miscellaneous function
//Return the search key
string person::Key()
{
	//return the uppercase of the last name a comma and the 
    //uppercase of the firstname
    return lastname.ucase()+", "+firstname.ucase();
}
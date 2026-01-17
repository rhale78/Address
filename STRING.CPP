#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include "string.h"

struct stringNode {
    char Item;
    ptrType Next;
};

//Default constructor
string::string()
{
    tail=NULL;
    strptr=NULL;
    
    len=0;
}

//Constructor
//assigns a single character to a string
string::string(char c)
{
    len=0;
    
    appendchar(c);
}

//Constructor
//assigns a array of characters to a string
string::string(char *s)
{
    len=0;

    assignstring(s);    
}

//Constructor
//assigns a string to another string
string::string(const string &x)
{
    len=0;

    copystring(x);
}

//Destructor
//deletes a string
string::~string()
{
    deletestring();
}

//Private function
//adds characters to the end of the string
void string::appendstring(char *s)
{
    //*(s+j) is the same thing as s[j]
    for(int j=0;*(s+j)!='\0';j++)
    {
        appendchar(*(s+j));
    }
}

//Private function
//deletes a string and then reassigns it
void string::assignstring(char *s)
{
    deletestring();
    
    //make sure length is = 0
    len=0;

    //since len=0, add stuff to the end of the string
    //since nothing is there anyway
    appendstring(s);
}


//Private function
//adds a character to the end of the string
void string::appendchar(char c)
{
    ptrType newPtr;

    //create a new node and set up its fields
    newPtr=new stringNode;
    assert(newPtr!=NULL);
    newPtr->Item=c;
    newPtr->Next=NULL;
    
    //check if special case, if so set "head" of string to newptr
    if (len==0)
    {
        tail=newPtr;
        strptr=newPtr;
    }
    //if not then set tail to end of string
    else
    {
        tail->Next=newPtr;
        tail=newPtr;
    }
    
    //don't forget to increment len
    len=len+1;
}

//Private function
//deletes a single character from the beginning of the list
void string::deletechar()
{
    ptrType curr;
    
    curr=strptr;
    //is the string already null?  if so, make sure len=0 and return
    if (curr==NULL)
    {
        len=0;
        return;
    }
    
    //is the string almost empty [one character?]?
    //if not, delete first character
    if (strptr->Next!=NULL)
    {
        strptr=curr->Next;
        curr->Next=NULL;
        delete curr;
        curr=NULL;
    }
    //if so, nullify and delete everything
    else
    {
        delete curr;
        curr=NULL;
        strptr=NULL;
        tail=NULL;
    }
    
    //make sure len is decremented
    len=len-1;
}

//Private function
//deletes entire string
void string::deletestring()
{
    if (len<=0)
        len=0;
    
    while(len!=0)
    {
        deletechar();
    }
}

//Miscellaneous public function
//returns the length of the string
int string::length() const
{
    return len;
}

//Miscellaneous public function
//checks to see if length is = 0
int string::isempty() const
{
    if (len==0)
        return 1;

    return 0;
}

//Assignment operator
//assigns a character to a string
string & string::operator = (char c)
{
    //keep memory leaks from happening by deleting the current string
    deletestring();
    
    //add a single character to the end of the string
    appendchar(c);
    
    return *this;
}

//Assignment operator
//assigns a array of characters to a string
string & string::operator = (char *s)
{
    //use assignstring because it automatically deallocates memory
    assignstring(s);

    return *this;
}

//Assignment operator
//assigns one string to another string
string & string::operator = (const string & x)
{
    //prevent memory leaks by deleting current string
    deletestring();

    //string is just copied to where *this is located in memory
    copystring(x);
    
    //make sure length is equal
    len=x.length();

    return *this;
}

//Private function
//copy constructor
//makes a copy of the string and places its contents in *this
//***This code is "copied" from the book Data Abstraction and
//   problem solving with C++ page #173-174.  Variable names
//   have been changed to protect the innocent :)
void string::copystring(const string &x)
{
    if (x.strptr==NULL)
        strptr=NULL;
    else
    {
        strptr=new stringNode;
        assert(strptr!=NULL);
        strptr->Item=x.strptr->Item;
        ptrType newPtr=strptr;
        
        for(ptrType origPtr=x.strptr->Next;
            origPtr!=NULL;
            origPtr=origPtr->Next)
        {
            newPtr->Next=new stringNode;
            assert(newPtr!=NULL);
            newPtr=newPtr->Next;
            newPtr->Item=origPtr->Item;
        }
        newPtr->Next=NULL;
    }
    
    //make sure length is the same
    len=x.length();
}

//Equality operator
//checks to see if two strings are equal
int string::operator == (const string & x) const
{
    //if the lengths are different they are not equal
    if (len!=x.length())
        return 0;
    else
    {
        //if lengths are 0 then they are the same
        if (len==0)
            return 1;
        //start checking to see if each character is equal and 
        //keep going until they differ or end of strings
        else
        {
            ptrType head1=strptr;
            ptrType head2=x.strptr;

            //curr can probably be replaced with head1 without 
            //problems
            for(ptrType curr=strptr;
                curr!=NULL;
                curr=curr->Next, head1=curr, head2=head2->Next)
            {
                if (head1->Item!=head2->Item)
                    return 0;
            }

        }
    }
    
    //if we've made it this far, they must be equal
    return 1;
}

//Equality operator
//checks to see if two strings are not equal
int string::operator != (const string & x) const
{
    //equal is done, and this is the reverse of ==, so why not
    //negate the value of ==?
    return !(*this==x);
}

//Equality operator
//checks to see if a string and char are equal
int operator == (const string &x, char y)
{
    //we already have a string to string so why not convert the 
    //char into a string and then compare them?
    string temp=y;
    return (x==temp);
}

//Equality operator
//checks to see if a char is equal to a string
int operator == (char x, const string &y)
{
    //this is getting redundant...same old stuff for the next
    //several routines...just converting stuff to string and checking
    //against ==
    return (y==x);
}

//Equality operator
int operator == (const string &x, char *y)
{
    string temp=y;
    return (x==temp);
}

//Equality operator
int operator == (char *x, const string &y)
{
    return (y==x);
}

//Inequality operator
int operator != (const string &x, char y)
{
    return !(x==y);
}

//Inequality operator
int operator != (char x, const string &y)
{
    return !(y==x);
}

//Inequality operator
int operator != (const string &x, char *y)
{
    return !(x==y);
}

//Inequality operator
int operator != (char *x, const string &y)
{
    return !(y==x);
}

//Inequality operator
int string::operator < (const string &x) const
{
    //Initialize variables
    
    int min=0;      //may not be needed if code were optimized
	int value=0;    //may not be needed if code were optimized
	
    //initialize string pointers to allow
    //moving through string data
    ptrType head1=strptr;   
	ptrType head2=x.strptr; 

	//***this section of code may not be needed if code were optimized***
    
    //find the minimum length
    if (len<x.length())
	{
		//check to see if length of *this is >0, if so set min to len
        //otherwise we have an empty string so *this is less than
        //x
        if (len>0)
		{
			min=len;
		}
		else
			return 1;
	}
	//check to see if *this is greater than x
    else if (len>=x.length())
	{
		if (x.length()>0)
		{
			//if so, set the min length to x's length
            min=x.length();
		}
		else
			//if it's an empty string though, *this is greater
            //so leave
            return 0;
   	}

	//start looping through both strings and check to see which
    //is < or >
    for (int j=0;
		head1!=NULL&&head2!=NULL,j<min;
		head1=head1->Next, head2=head2->Next,j++)
	{
		//if *this's item is < x's item then *this is less, so exit
        //[does this always work right?] *unchecked optimization*
        if (head1->Item<head2->Item)
			return 1;
		
        //if *this's item is > x's item then exit because x is > *this
        if (head1->Item>head2->Item&&value!=-1)
		{
			return 0;
		}
		//if *this is equal to x's item then set value to 0 if
        //value!=-1
        if (head1->Item==head2->Item)
		{
			if (value!=-1)
				value=0;
		}
	}

	//if the value is -1 or 0
    if (value==-1||value==0)
	{
		//if the length if *this is < x then return true
        if (len<x.length())
		{
			return 1;
		}
		//if value=-1 [less than {removed from optimization}]
        //and if *this's length is equal to x's length return 1
        //otherwise return false
        else if (value==-1&&len==x.length())
			return 1;
		else
			return 0;
	}
	else
		//we shouldn't have made it here but if we did then
        //return false
        return 0;
}

//Inequality operator
int string::operator <=(const string &x) const
{
	//check to see if *this<x or if *this==x
    return (*this<x)||(*this==x);
}

//Inequality operator
int string::operator > (const string &x) const
{
	//since > is the opposite of <=, return the not of *this<=x
    return !(*this<=x);
}

//Inequality operator
int string::operator >=(const string &x) const
{
	//since >= is the opposite of < return the not of *this<x
    return !(*this<x);
}

//Concatenation operator
//adds a character to the end of a string
string & string::operator += (char x)
{
    //we already have + operator working so since
    //this+=x is equal to this=this+x this code works
    *this=*this+x;
    
    return *this;
}

//String manipulation routine
//takes a part of the string and returns it
string string::substr(int pos, int num)
{
    ptrType curr=strptr;

    string temp;

    //if the user entered a value too large or too small
    //return null string
    if (pos>len||pos<0)
        return temp;

    //position the pointers over the correct position
    for (int j=1;j<pos;j++,curr=curr->Next);
    
    //loop until number of characters requested has been retrieved
    for (int i=1;i<num+1;i++,curr=curr->Next)
    {
        //make sure we haven't gone over the max length of the string
        if (i<=len+pos && curr!=NULL)
        {
            temp+=curr->Item;
        }
        //if we have, time to leave this loop to prevent pointer
        //problems
        else
            break;
    }
    return temp;
}
    
//Concatenation operator
//adds a character array to the end of a string
string & string::operator += (char *x)
{
    //we already have + operator working so since
    //this+=x is equal to this=this+x this code works
    *this=*this+x;
    
    return *this;
}

//Concatenation operator
//adds one string to another string
string & string::operator += (const string &x)
{
    //we already have + operator working so since
    //this+=x is equal to this=this+x this code works
    *this=*this+x;
    
    return *this;
}

//String manipulation routine
//finds a string in another string and returns its location
int string::find(const string & s)
{
    int slen=s.length();
    string temp;

    //if the length of the incoming string is larger than this's
    //length, exit because the string can't be here
    if (slen>len)
        return 0;
    else
    {
        //loop through the string taking the substr with the length
        //equal to s's incoming length
        int j=1;
        for (j=1;j<len;j++)
        {
            temp=substr(j,slen);
            
            //check the substr against s
            if (s==temp)
                return j;
        }
        //if made it here, it's not here
        return 0;
    }
}

//String manipulation routine
//finds a character array within a string
int string::find(char *s)
{
    //we already have string find(string) so why not convert
    //the character array to a string and find the newly created
    //string
    string s1=s;
    return find(s1);
}

//String manipulation routine
//finds a single character within a string
int string::find(char s)
{
    //this is redundant...convert to string, find string
    string s1=s;
    return find(s1);
}

//Concatenation operator
//adds a character to a string
string operator + (const string & x,       char     y) 
{
    string temp;
    string y1=y;

    temp=x+y1;

    return temp;
}

//Concatenation operator
string operator + (      char     x, const string & y) 
{
    string temp;
    string x1=x;

    temp=x1+y;

    return temp;
}

//Concatenation operator
string operator + (const string & x,       char *   y) 
{
    string temp;
    string y1=y;

    temp=x+y1;

    return temp;
}

//Concatenation operator
string operator + (      char *   x, const string & y) 
{
    string temp;
    string x1=x;

    temp=x1+y;

    return temp;
}

//Concatenation operator
//adds one string to the end of the other string
string operator + (const string & x, const string & y) 
{
    string temp;
    
    //for some odd reason appendstring/appendchar kept on
    //creating pointer errors...had to find a way around it.

    //assign the string as usual
    
	for (ptrType curr=x.strptr;curr!=NULL;curr=curr->Next)
    {
        temp.appendchar(curr->Item);
    }
    
    //append the string to the newly created string
    for (ptrType curr1=y.strptr;curr1!=NULL;curr1=curr1->Next)
    {
        temp.appendchar(curr1->Item);
    }
    
    return temp;
}

//Output operator
//allows output via file or cout
ostream& operator <<(ostream& os, const string& str) 
{
    for (ptrType current=str.strptr; 
        current != NULL; 
        current = current->Next)
    {
        os << current->Item;
    }

    return os;
}

//Input operator
//allows input via file or cin
//only takes what comes before the whitespace in the input stream.
istream & operator >> (istream& is, string & str) 
{
    //create a temp character to allow the get operator to be
    //used
    char temp=0;

    do
    {
        //istream operator has a useful function...get
        is.get(temp);

        //check to see if this character is a space
        //characters from space [ascii code 32] down are 
        //space and ascii code 255 is also a space character
        
        //***Linux reports this as a warning because it is "rare"
        //that a character is below 33 or above 254 when using a 
        //get.  I don't feel this warning is valid!***
        //if (temp>32&&temp<254)
        if (temp>' ')
        {
            str+=temp;
        }
    }
    //keep on going until we encounter a non-space character
    //while(temp>32&&temp<254);
    while (temp>' ');
    
    return is;
}

//Input operator
//gets an entire line from keyboard or where ever
istream & getline(istream & is, string & str, char sentinel)
{
    char temp;
    int found=0;
	str="";			//bug?  Shouldn't this be cheared?

    //couldn't use get because we needed spaces and so forth in
    //this routine..peek works fine and then later "eat" the input
    //using get.  Keep on going until we hit the sentinel
    do
    {
        temp=is.peek();
        //is peek the sentinel..if so we've found it so we need
        //to exit later
        if (temp!=sentinel)
        {
            //if not sentinel, add the peeked character to the string
            str+=temp;
            //eat the input so we can get the next character
            is.get(temp);
        }
        else
            found=-1;
    }
    //if we found the sentinel, go ahead and exit else keep on 
    //getting charaters
    while (found==0);

    return is;
}

//Conversion routine
//converts a string to a int
int string::cint()
{
    int number=0;
    //n is equal to the "units" position...set it to one so that the
    //first digit is in the one's position
    int n=1;
    bool neg=0;

    //loop through the entire length of the string
    for(int j=1;j<=len;j++)
    {
        //set temp to be the actual number of the character
        //at position j
        int temp=getnumber(substr(j,1));
        
        //special code...if a negative sign has been found as a 
        //character in the string, then set the bool flag to neg and
        //deal with it later...
        if (temp==-5)
        {
            //if the negative flag has already been set, then we have
            //a minor problem..end getting any more characters and
            //treat this second negative like an illegal character.
            if(neg==1)
            {
                //if number was positive, set it to negative because
                //that's what a negative sign does
                number=-number;
                //return the number to keep from getting any deeper
                //into trouble
                return number;
            }
            //set the negative bool flag to true and go back to the 
            //top of the loop
            neg=1;
            continue;
        }
        //if we actually have a digit from 0-9, deal with it
        if (temp>=0)
        {
            //the number should equal what it was times n plus
            //the value of the number
            //why didn't I use temp here instead of getnumber?
            number=number*n+getnumber(substr(j,1));
            //if the number was a single digit, then set n=10
            //so that more digits can be added
            n=10;
        }
        //if the number is not -5 nor 0-9 then it could be a decimal
        //or an illegal character..break anyway because we don't want 
        //to deal with those
        else
            break;
    }
    
    //if the negative flag was set
    if (neg==1)
    {
        //negate the number
        number=-number;
    }
    
    //return the number back to the caller
    return number;
}

//Conversion routine
//Converts a string into a double
double string::cdbl()
{
    //initialize all the variables so we don't get into trouble later
    double number=0.0;
    
    //n has the same reason here as it does in cint
    int n=1;
    bool decimal=0;
    int k=0;
    double temp1=0.0;
    bool neg=0;

    //loop through the entire string character by character
    for(int j=1;j<=len;j++)
    {
        //get a single digit from the string
        int temp=getnumber(substr(j,1));
        
        //if the character is a negative sign
        if (temp==-5)
        {
            //if the number is already negative, don't negate it again
            //but return the current number to the caller since
            //the second - is an illegal character
            if (neg==1)
            {
                //negate the number
                number=-number;
                return number;
            }
            //set the negative flag
            neg=1;
            continue;
        }
        
        //if the number is >0 then
        if (temp>=0)
        {
            //if the decimal flag is not set then treat the number
            //as if it were an integer
            if (decimal==0)
            {
                number=number*n+getnumber(substr(j,1));
                n=10;
            }
            //if the number is a decimal
            else
            {
                //[this is fun]  divide the number by a power of 10.
                //since these strings are taken from left to right,
                //the further right they go the more powers of ten
                //they go down...
                
                //increment the power
                k=k+1;
                //get the number
                temp1=getnumber(substr(j,1));
                //since math.h isn't included, let's do our
                //own power function.
                for(int l=1;l<=k;l++)
                {
                    //divide by 10 since these powers of 10 are actually
                    //negative powers of ten
                    temp1=temp1/10;
                }
                //add the result to the number
                number=number+temp1;
            }
        }
        
        //if the return value is not >0 and not -5 then it could be
        //-2 [decimal]
        else
        {
            //if it's a -2 return then
            if (temp==-2)
            {
                //if there's already a decimal
                if (decimal==1)
                {
                    //I did have an assert here, but it is possible
                    //that a value come into this function that does
                    //have 2 decimal points in it...the second
                    //decimal should be treated as an illegal character
                    //and the number returned to the caller
                    //assert(temp!=-2&&decimal!=1);
                    break;
                }
                //set the decimal flag
                decimal=1;
            }
            //if it's not a -5, -2, or >0 then we have an illegal
            //character
            else
                break;
        }
    }
    
    //if negative then negate the current number
    if (neg==1)
    {
        number=-number;
    }
    return number;
}

//Miscellaneous conversion routine
//Changes a single character into a integer number
int string::getnumber(string x)
{
    if (x=='0')
        return 0;
    
    if (x=='1')
        return 1;
    
    if (x=='2')
        return 2;
    
    if (x=='3')
        return 3;
    
    if (x=='4')
        return 4;
    
    if (x=='5')
        return 5;
    
    if (x=='6')
        return 6;
    
    if (x=='7')
        return 7;
    
    if (x=='8')
        return 8;
    
    if (x=='9')
        return 9;
 
    //if there's a ., return -2
    if (x=='.')
        return -2;

    //if there's a -, return -5
    if (x=='-')
        return -5;

    //if we've made it this far, the string is not a number, return
    //-1
    return -1;
}

//Miscellaneous conversion routine
//Converts a double into a string 
string string::str(double x)
{
    string temp;
    int t=0;
    int a=0;
    int y=(int)x;
    double temp1=0.0;

    //check to see if the integer of x is equal to x
    if(y==x)
    {
        //if 9=<y>=0
        if (y>=0&&y<=9)
        {
            //this is just a single digit, return the string
            //value of it
            return getstring(y);
        }
        
        //take the remainder of y divided by 10 and then divide y by
        //10.  The remainder is the rightmost digit and the quotient
        //is the rest of the digits
        t=y%10;
        a=y/10;
        //if the quotient is 0, then there are no more digits to process
        if (a==0)
        {
            //just get the string value of the number
            return getstring(t);
        }
        else
        {
            //otherwise, call str recursively and add the two strings
            //together using contatenation
            return str(a)+getstring(t);
        }
    }
    
    //if we've made it here, our public interface was ignored and
    //the number has a decimal in it
    return "";
}

//Miscellaneous conversion routine
//Converts a single digit into a string
string string::getstring(int x)
{
    if (x==0)
        return "0";
    if (x==1)
        return "1";
    if (x==2)
        return "2";
    if (x==3)
        return "3";
    if (x==4)
        return "4";
    if (x==5)
        return "5";
    if (x==6)
        return "6";
    if (x==7)
        return "7";
    if (x==8)
        return "8";
    if (x==9)
        return "9";
    
    //if we're here, then the value is not a number
    //it should never make it here unless x is a multidigit number
    return "";
}

//Conversion routine
//Converts a double into a string
string string::cstr(double x)
{
    string temp;
    double t=0.0;

    //check the sign of x..if it's negative then make it positive
    //but add the negative sign to the string and then call cstr 
    //recursively
    if (x<0)
    {
        //negate x
        x=-x;
        //add a - to the front of the string and then call cstr with
        //the non-negative value of x
        return "-"+cstr(x);
    }
    //if x=0 then return a 0
    else if (x==0)
    {
        return "0";
    }
    //otherwise we have a number >0
    else
    {
        //if we're lucky enough to get an integer value, just call
        //str and convert it
        if ((int)x==x)
            return str(x);
        //guess we were unlucky....
        else
        {
            //inialize all variables
            temp="";
            int y=0;
            t=x;
            
            //if the integer of x is not equal to zero then
            if (((int)t)!=0)
                //make the temp variable equal to the str of the int
                //of t
                temp=str((double)(int)t);

            //after that's done, add a decimal to the end of the string
            temp=temp+".";
            //get the integer part of t
            y=(int)t;
            //subtract the integer part of t from t to get the decimal
            //part only
            t=double(t-y);

            //this is where things get crazy...aritmetic errors abound
            //in this section of code!!!  They are rounded somehow when
            //cint or cdbl take care of them
            
            //since we don't have an integer part of the number right
            //now, let's make one and let str take care of the integer
            //part for us
            do
            {
                //get a single number from the decimal and convert it
                //to a mixed number
                t=t*10;
                //convert that mixed number into an integer
                y=(int)t;
                //the integer part is converted over to a string
                //and added to our existing "number"
                temp=temp+temp.str(y);
                //subtract the new integer from the decimal to get
                //back to a decimal
                t=t-y;
                //keep on doing this until we're lucky enough to get
                //the number equal to 0 [which usualy happens around
                //60 places out even when the original double was only
                //to the tenth's place] or until the length of our
                //string is equal to 16 [to keep overflow and to keep
                //all these erroneous numbers from showing up in
                //our calculations
            }while(t!=0.0&&temp.length()<=16);

            
            //now that we have a number converted, let's get rid of any
            //trailing zeros [if any]
            string t;

            do
            {
                t=temp.substr(temp.length(),1);

                //if the character is a 0 or . then
                if (t=="0"||t==".")
                {
                    //make sure we don't go below length
                    if (temp.length()-1>0)
                        //make the string one less character, with the
                        //rightmost character being removed
                        temp=temp.substr(1,temp.length()-1);
                    else
                    {
                        //if we have gone below length [len 1 or 0]
                        //then there's nothing here at all
                        temp="0";
                    }
                }
                //keep on going while the character is = to 0
            }while(t=="0");
        }
    }
    
    //now that all that mess is taken care of, return the string
    //[finally!]
    return temp;
}

//Miscellaneous string manipulation routines
//Centers a string
string string::Center(int columns=80)
{
    //defaults to an 80 column screen since most text based systems
    //use 80 columns [0-79] to display text

    //standard "typer's center" formula.
    //take the length of the string to be centered and divide it by 2
    double temp=len/2;
    //divide the number of columns by 2 also
    double col=columns/2;
    int left;
    int right;
    
    //the amount of spaces on the left is equal to the columns/2
    //and the length of string/2 [rounded up to the nearest character]
    left=(int)(col-(temp+.5));
    //calculate the # of spaces on the right of the string [round down
    //to the nearest character]
    right=(int)(col-(temp-.5));

    //return the string with the padding
    return LPadd(left)+Padd(right);
}

//Miscellaneous string manipulation routines
//Adds spaces to the left of a string
string string::LPadd(int amount)
{
    //add spaces to the left of the string and return it
    return Padd(amount)+*this;
}

//Miscellaneous string manipulation routines
//Appends spaces to the right of a string
string string::RPadd(int amount)
{
    //add spaces to the right of the string and return it
    return *this+Padd(amount);
}

//Miscellaneous string manipulation routines
//Creates a string with amount of spaces
string string::Padd(int amount)
{
    string t;
    //create a string with a length of amount of spaces
    for(int j=0;j<amount;j++)
        t=t+" ";

    //return it
    return t;
}

//Conversion routine
//Converts a string to a regular pointer or array
void string::cptr(char* s)
{
	//if the length is 0, return s as a null string
    if (len==0)
	{
		s[0]='\0';
	
		return;
	}
	
	//set a pointer to the head of the string
    ptrType head1=strptr;
	
	//loop through the string up to the length
    for(int j=1;j<=len;j++,head1=head1->Next)
	{
		//set the location at j-1 [since arrays are 0 based] of s to
        //what is at location j of the string
        s[j-1]=head1->Item;	
	}
	
    //set the last character to a null zero
    //[should this be len-1 since arrays are 0 based?]
	s[len]='\0';

	return;
}

//Miscellaneous string manipulation routines
//Centers a string with padding on left only
string string::CenterL(int columns)
{
	//do everything Center does
    double temp=len/2;
    double col=columns/2;
    int left;
        
    left=(int)(col-(temp+.5));
    
    //except ignore the right side completely
    return LPadd(left);
}

//Miscellaneous string manipulation routines
//Make a string uppercase
string string::ucase()
{
	string tmp;
	//loop through the string
    for(int j=1;j<=len;j++)
	{
		//get a single character and get the uppercase of that character
        tmp=tmp+substr(j,1).uchar();
	}
	//return the uppercase string
    return tmp;
}

//Miscellaneous string manipulation routines [private]
//Return a single uppercase character
string string::uchar()
{
	//there has to be an easier way to do this, isn't there?
    string x=*this;
	if (x=="a")
		return "A";
	if (x=="b")
		return "B";
	if (x=="c")
		return "C";
	if (x=="d")
		return "D";
	if (x=="e")
		return "E";
	if (x=="f")
		return "F";
	if (x=="g")
		return "G";
	if (x=="h")
		return "H";
	if (x=="i")
		return "I";
	if (x=="j")
		return "J";
	if (x=="k")
		return "K";
	if (x=="l")
		return "L";
	if (x=="m")
		return "M";
	if (x=="n")
		return "N";
	if (x=="o")
		return "O";
	if (x=="p")
		return "P";
	if (x=="q")
		return "Q";
	if (x=="r")
		return "R";
	if (x=="s")
		return "S";
	if (x=="t")
		return "T";
	if (x=="u")
		return "U";
	if (x=="v")
		return "V";
	if (x=="w")
		return "W";
	if (x=="x")
		return "X";
	if (x=="y")
		return "Y";
	if (x=="z")
		return "Z";

	//if we've made it this far, just return the character because
    //it's probably a space or some other character that doesn't need
    //to be converted
    return x;
}

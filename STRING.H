#include <iostream.h>

// string.h - Linked list implementation of strings

struct stringNode;
typedef stringNode* ptrType;

class string {
    public:

    // Constructors

    string();
    // purpose: creates a null string, length 0
    // precondition: none
    // postcondition: null string constructed, length 0

    string(char c);                      
    // purpose: make a string from a single character
    // precondition: none
    // postcondition: string object constructed with one character c
    // assertion: fails if memory can't be allocated

    string(char * s);
    // purpose: make a string from a C-style '\0'-terminated string
    //          will work for character arrays and literals too
    // precondition: s is '\0'-terminated C-style string
    // postcondition: string object constructed to have same value as s
    // assertion: fails if memory can't be allocated


    // Copy constructor

    string(const string & x);
    // purpose: copy constructor - make a string from another string object
    // precondition: none
    // postcondition: string object constructed has same value as x
    // assertion: fails if memory can't be allocated


    // Destructor

    ~string(); 
    // purpose: frees memory associated with string and sets length to 0
    // precondition: none
    // postcondition: dynamically allocated memory freed


    // Status operators
     
    int length() const;  
    // purpose: returns # of characters in string
    // precondition: none
    // postcondition: return the length of the string

    int isempty() const;
    // purpose: checks for empty string
    // precondition: none
    // postcondition: returns 1 if string is empty, 0 otherwise

    //converting operators
    
    int cint();
    // purpose: converts a string to int
    // precondition: none
    // postcondition: returns the integer value of the string, otherwise
    // returns 0

    double cdbl();
    // purpose: converts a string to double
    // precondition: none
    // postcondition: returns the double value of the string, otherwise
    // returns 0.0

    string cstr(double x);    
    // purpose: converts a double to string
    // precondition: none
    // postcondition: returns the string of the double

    void cptr(char* s);
    //Convert a string to a pointer or char array

    // Assignment operators

    string & operator = (char x);
    // purpose: assign a character. If the string already has
    //          a value, it is properly deallocated beforehand
    // precondition: none  
    // postcondition: string object will contain one character c
    // assertion: fails if memory can't be allocated

    string & operator = (char * x);  
    // purpose: assign a literal, C-style string. If the string already has
    //          a value, it is properly deallocated beforehand (or reused)
    // precondition: s is '\0'-terminated C-style string
    // postcondition: string object will contain the values of C-style string s
    // assertion: fails if memory can't be allocated

    string & operator = (const string & x); 
    // purpose: assign one string to another
    // precondition: none
    // postcondition: a string x.  If the  string already has
    //          a value, it is properly deallocated beforehand (or reused)
    // assertion: fails if memory can't be allocated


    // equality/inequality operators

    int operator == (const string & x) const;    
    // purpose: checks equality with x
    // precondition: none
    // postcondition: returns 1 if strings match, 0 otherwise

    int operator != (const string & x) const;    
    // purpose: checks equality with x
    // precondition: none
    // postcondition: returns 1 if strings match, 0 otherwise
    
    int operator < (const string &x) const;
    // purpose: checks to see if string is < x
    // precondition: none
    // postcondition: returns 1 if less than, 0 otherwise

    int operator <=(const string &x) const;
    // purpose: checks to see if string is <= x
    // precondition: none
    // postcondition: returns 1 if <=, 0 otherwise

    int operator >(const string &x) const;
    // purpose: checks to see if string is > x
    // precondition: none
    // postcondition: returns 1 if >, 0 otherwise

    int operator >=(const string &x) const;
    // purpose: checks to see if string is >= x
    // precondition: none
    // postcondition: returns 1 if >=, 0 otherwise

    // substr operation

    string substr(int pos, int num);
    // purpose: substring extraction. Returns string object of num chars
    //          starting at position pos. Truncates if num too big, returns 
    //          empty string if pos too big
    // precondition: none
    // postcondition: returns substring starting at char pos of num chars
    //                if num too large, takes all characters up to end of string

    // find operations

    int find(char s);
    // purpose: find s in the string
    // precondition: none
    // postcondition: returns position of s in string, or zero if not found

    int find(char *s);
    // purpose: find s in the string
    // precondition: none
    // postcondition: returns position of s in string, or zero if not found

    int find(const string & s);
    // purpose: find s in the string
    // precondition: none
    // postcondition: returns position of s in string, or zero if not found

    // concatenation operators

    string & operator += (char x);
    // purpose: catenates x to the right of the string
    // precondition: none
    // postcondition: concatenates x onto string
    // assertion: fails if memory can't be allocated

    string & operator += (char * x);
    // purpose: catenates x to the right of the string
    // precondition: none
    // postcondition: concatenates x onto string
    // assertion: fails if memory can't be allocated

    string & operator += (const string & x);
    // purpose: catenates x to the right of the string
    // precondition: none
    // postcondition: concatenates x onto string
    // assertion: fails if memory can't be allocated


    // friend operators - equality and inequality
    // Note that these two simply reverse the order of the operands

    friend int operator == (const string & x,       char     y);
    // purpose: checks equality of string x and character y
    // precondition: none
    // postcondition: returns 1 if strings match, 0 otherwise

    friend int operator == (      char     x, const string & y);
    // purpose: checks equality of character x and string y
    // precondition: none
    // postcondition: returns 1 if strings match, 0 otherwise

    // Similarly here - operands simply reversed in these two versions

    friend int operator == (const string & x,       char   * y);    
    // purpose: checks equality of string x and character array y
    // precondition: none
    // postcondition: returns 1 if strings match, 0 otherwise

    friend int operator == (      char   * x, const string & y);    
    // purpose: checks equality of character array x and string y
    // precondition: none
    // postcondition: returns 1 if strings match, 0 otherwise

    // And here - operands simply reversed in these two versions

    friend int operator != (const string & x,       char     y);
    // purpose: checks inequality of string x and character y
    // precondition: none
    // postcondition: returns 1 if strings don't match, 0 otherwise

    friend int operator != (      char     x, const string & y);
    // purpose: checks inequality of character x and string y
    // precondition: none
    // postcondition: returns 1 if strings don't match, 0 otherwise

    // And here - operands simply reversed in these two versions

    friend int operator != (const string & x,       char   * y);    
    // purpose: checks inequality of string x and character array y
    // precondition: none
    // postcondition: returns 1 if strings don't match, 0 otherwise

    friend int operator != (      char   * x, const string & y);    
    // purpose: checks inequality of character array x and string y
    // precondition: none
    // postcondition: returns 1 if strings don't match, 0 otherwise

    // friend operators - concatenation
    // Note that these two functions simply reverse the order of the parameters
    friend string operator + (const string & x,       char     y);
    // purpose: concatenation. Returns a new string object with the character y
    //          catenated to characters of x.
    // precondition: none
    // postcondition: string object returned containing concatenated x and y
    // assertion: fails if memory can't be allocated

    friend string operator + (      char     x, const string & y);
    // purpose: concatenation. Returns a new string object with the characters of y
    //          catenated to the character x.
    // precondition: none
    // postcondition: string object returned containing concatenated x and y
    // assertion: fails if memory can't be allocated

    // This is similar - the second function simply reverses the parameters
    friend string operator + (const string & x,       char *   y);
    // purpose: concatenation. Returns a new string object with characters of
    //          y catenated to characters of x.
    // precondition: y is '\0'-terminated C-style string
    // postcondition: string object returned containing concatenated x and y
    // assertion: fails if memory can't be allocated

    friend string operator + (      char *   x, const string & y);
    // purpose: concatenation. Returns a new string object with characters of
    //          y catenated to characters of x.
    // precondition: x is '\0'-terminated C-style string
    // postcondition: string object returned containing concatenated x and y
    // assertion: fails if memory can't be allocated

    // And this concatenation operator is for two strings

    friend string operator + (const string & x, const string & y);
    // purpose: concatenation. Returns a new string object with characters of
    //          y catenated to characters of x.
    // precondition: none
    // postcondition: string object returned containing concatenated x and y
    // assertion: fails if memory can't be allocated


    // I/O operators - << is implemented in string.cc so you can use cout with your
    // strings!
    // purpose: mimics iostream.h for istreams and strings
    friend ostream& operator <<(ostream & os, const string & str);

    // For completeness, you may want to implement these... 
    friend istream& operator >>(istream & is, string & str);
    friend istream& getline(istream & is, string & str, char sentinel = '\n');

    //Miscellaneous string manipulation routines
    
    string ucase();
    //Converts a string to uppercase

    string CenterL(int col);
    //Centers a string on a screen with a width of col.  This version
    //does not put spaces on the right side of the string so it can
    //be used for input
    
    string RPadd(int amount);
    //Adds spaces to the right of a string with amount of spaces added
    
    string LPadd(int amount);
    //Adds spaces to the left of a string with amount of spaces added
    
    string Center(int columns);
    //Centers a string on the screen with a width of col.  Adds spaces
    //on both sides of the string
    
    string Padd(int amount);
    //Returns amount of spaces
       
    private:

    string uchar();
    // purpose: converts a string to uppercase 
    // precondition: string is a single character string
    // postcondition: returns the uppercase character

    string str(double x);
    // purpose: converts a double to a string (helper to cstr)
    // precondition: x is not negative, x is not a decimal
    // postcondition: returns the string of the double

    string getstring(int x);
    // purpose: converts a int to a string
    // precondition: x is a single character and is a number
    // postcondition: returns the string of the int

    int getnumber(string x);    
    // purpose: converts a string to an int
    // precondition: x is a string that contains a number, decimal, or
    // negative sign
    // postcondition: returns the value of the string

    void string::assignchar(char c);
    // purpose: assigns a character to a string.
    // precondition: none
    // postcondition: string object returned containing character c
    // assertion: fails if memory can't be allocated

    void string::assignstring(char *s);
    // purpose: assigns a array/pointer string to a string
    // precondition: none
    // postcondition: string object returned containing array s
    // assertion: fails if memory can't be allocated

    void string::appendchar(char c);
    // purpose: adds a character to the end of a string
    // precondition: none
    // postcondition: string object returned with c added to the 
    // end of the string
    // assertion: fails if memory can't be allocated

    void string::appendstring(char *s);    
    // purpose: adds a array/pointer string to the end of a string
    // precondition: none
    // postcondition: string object returned with s added to the 
    // end of the string
    // assertion: fails if memory can't be allocated

    void string::deletechar();
    // purpose: removes the first char of a string
    // precondition: none
    // postcondition: string object returned with the first character
    // of the string deleted
        
    void string::deletestring();
    // purpose: deletes entire string
    // precondition: none
    // postcondition: deletes entire string
        
    void string::copystring(const string & x);
    // purpose: copies one string to another string
    // precondition: none
    // postcondition: creates a copy of x

 
    ptrType strptr;
    ptrType tail;
    int len;
};


#include "BST.h"

class addressBook {
public:
	//Constructors

    addressBook();
    //Default constructor.  Resets all the fields and sets the
    //filename to address.csv

    addressBook(string filename1);
    //Resets all the fields and sets the filename to filename1

    //Destructor
    
    ~addressBook();
    //Destroys the address book from memory

    //General public interface
    
    virtual void DoMainMenu();
    //Starts the main menu for the address book.  Declared virtual
    //to allow rewrite through a derived class.
    
protected:
	
    //Miscellaneous functions
    
    void AddAddress();
	//Adds an address to the BST

    int DoesAddressExist(string t);
	//Checks to see if the address exists.  If it does, returns 1
    //otherwise 0

    virtual void SaveAddresses();
	//Saves the addresses to the file specifiec by the filename field
    //in the person object

    virtual void LoadAddresses();
	//Loads people from the file specified by the address book filename
    //field and adds them to the BST.  Deletes the BST before load
    //to prevent merging of filenames

    virtual void ViewAddressMenu();
	//Allows viewing of people in the address book.  The last person
    //viewed is kept into memory for editing by the add address menu

    virtual void DeleteAddressMenu();
	//Deletes an address, clears the address book, or clears the
    //current person from memory

    virtual void AddAddressMenu();
    //Allows adding or editing of a person

    virtual void DoMenu();
    //Displays the "title" for the address book

    virtual void Wait(int prompt=1);
	//Waits for the user to press the enter key.  If prompt is 0, no
    //user prompt will be used but if it's 1 then a message will be 
    //displayed 
    
    virtual string Input(string prompt);
    //Mimics the QuickBasic INPUT statement.  Prompts the user for input
    //and returns what is inputed

    virtual void ClearCurrent();
    //Clears the current person from memory

    //Variables

    string filename;
    //Create a filename string so we know which file to open under
    //load conditions

    bstClass Addresses;
    //Create a Binary search tree and allow other derived classes
    //access to it
    
    person Current;
    //Create a person so we don't have to pass parameters all over 
    //the program.  Make it protected so derived classes can access it

    //Variables not implemented in this version

    int loaded;
    //Is the file loaded or in the process of loading

    int mode;
    //What is the current mode [adding, deleting, changing, etc]
    
    int maxrecord;
    //How many people are in the address book total?

    int currentrecord;
    //Which record out of how many are we working with?

    int changed;
    //Has the information changed since last save?

    int saved;
    //Has the file been saved or is now being saved?
};

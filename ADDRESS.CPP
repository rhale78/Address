#include "address.h"
#include <stdio.h>
#include <fstream.h>
	
//Declare the Visit functions
//I hate doing these within the class and they not being a part of 
//the actual class itself
void ViewPerson(treeItemType& AnItem);
void SavePerson(treeItemType& AnItem);
void ViewKeys(treeItemType& AnItem);

//Default Constructor
addressBook::addressBook()
{
    //set the filename to address.csv
    filename="address.csv";
}

//Constructor
//Allows setting of the filename
addressBook::addressBook(string filename1)
{
    //make sure the user knows what he's doing and make sure they
    //haven't sent in a null filename string
    if (filename1!="")
        //if not null, set it 
        filename=filename1;
    else
        //if it is null, to keep the program happy, set it to the
        //default of address.csv.
        //Maybe this should create an error
        filename="address.csv";
}

//Destructor
addressBook::~addressBook()
{
	//destroy the address book by deleting the entire tree
    Addresses.DestroyEntireTree();
}

//Miscellaneous function
//Print the header for the menus
void addressBook::DoMenu()
{
    //create a blank string and center it on the screen
    string title="ADDRESS BOOK PROGRAM";
    cout<<title.Center(80)<<endl;

    //make things "pretty"
    title="____________________";
    cout<<title.Center(80)<<endl<<endl;
}

//Public interface
//Allows the user to select the options they want to do
void addressBook::DoMainMenu()
{
    //loop until we specify we want to exit the program
    do
	{
        //since this is a menu, do the header
        DoMenu();

        //print the menu on the screen
        string title="Main Menu";
        cout<<title.Center(80);
	    
	    title="_________";
	    cout<<title.Center(80)<<endl<<endl;

	    title="1.  Add address   ";
	    cout<<title.Center(80)<<endl;
	    bool empty=Addresses.SearchTreeIsEmpty();

		//if there's nothing in the address book, don't print
        //these since they won't work with no data available
        if (!empty)
		{
			title="2.  Delete address";
			cout<<title.Center(80)<<endl;
			title="3.  View address  ";
			cout<<title.Center(80)<<endl;
			cout<<endl;
			title="L.  Load Addresses";
			cout<<title.Center(80)<<endl;
			title="S.  Save Addresses";
			cout<<title.Center(80)<<endl;
        }
		else
		{	
			cout<<endl;
			cout<<endl;
			cout<<endl;
			title="L.  Load Addresses";
			cout<<title.Center(80)<<endl;
			cout<<endl;
        }
		cout<<endl;
        title="E.  Exit          ";
	    cout<<title.Center(80)<<endl;

        //make things pretty by adding lines
        //this in effect clears the screen :)
        for (int j=1;j<10;j++)
            cout<<endl;

	    string c;
		
		c=Input("Enter choice:");
	    
		//get a choice from the user and see if it's one of these
        //choices
        //be "smart" about the menu, if it's not on the menu at the
        //time, don't allow the user to choose it
        if (c=="1")
			AddAddressMenu();
		else if (c=="2"&&!empty)    
			DeleteAddressMenu();
		else if (c=="3"&&!empty)
			ViewAddressMenu();
		else if (c=="L"||c=="l")
            LoadAddresses();
        else if ((c=="S"||c=="s")&&!empty)
            SaveAddresses();
        else if (c=="E"||c=="e")
			//in a sense, exit the program
            return;
	}while(1);
}

//Miscellaneous address book function
//Add addressbook menu
void addressBook::AddAddressMenu()
{
    //these menus are pretty much the same
    do
	{
        DoMenu();

        string title="Add Address Menu";
        cout<<title.Center(80)<<endl;
	    
	    title="________________";
	    cout<<title.Center(80)<<endl<<endl;

	    //this is a little different...display the inputed data on the 
        //right of the screen and the choice on the left
        title="1.  Last Name "+Current.lastname.LPadd(51-Current.lastname.length());
	    cout<<title.Center(80);
	    title="2.  First Name "+Current.firstname.LPadd(50-Current.firstname.length());
	    cout<<title.Center(80);
	    title="3.  Street "+Current.street.LPadd(54-Current.street.length());
	    cout<<title.Center(80);
	    title="4.  Zip code "+Current.zipCode.LPadd(52-Current.zipCode.length());
        cout<<title.Center(80);
        title="5.  Phone Number "+Current.phoneNumber.LPadd(48-Current.phoneNumber.length());
        cout<<title.Center(80);
        cout<<endl<<endl;
        title="S.  Save and return ";
	    cout<<title.Center(80);
        title="R.  Return         ";
	    cout<<title.Center(80)<<endl;

        for (int j=1;j<10;j++)
            cout<<endl;

	    string c;
		
		c=Input("Enter choice:");
	    
        if (c=="1")
        {
            //this could be replaced with the input routine
            //if I had more time
            cout<<"Enter last name:";
            //this could be removed since the data should be cleared
            //by the cin/getline/input routines
            Current.lastname="";
            cin>>Current.lastname;
		}
		else if (c=="2")
		{
            cout<<"Enter first name:";
            Current.firstname="";
            cin>>Current.firstname;
        }
        else if (c=="3")
	    {
            cout<<"Enter street address:";
            Current.street="";
			//since streets are normally more than 1 word,
            //we must use a getline because cin doesn't
            //accept spaces
            getline(cin, Current.street,'\n');
		}
		else if (c=="4")
        {
            cout<<"Enter zip code:";
            Current.zipCode="";
			cin>>Current.zipCode;
        }
        else if (c=="5")
        {
            cout<<"Enter phone number:";
            Current.phoneNumber="";
			getline(cin, Current.phoneNumber,'\n');
		}
        else if (c=="R"||c=="r")
        {
            return;
        }
        else if (c=="S"||c=="s")
        {	
            //if we want to save the person,
            //set their filename field to the current
            //addressbook filename.
            //this also allows us to have multiple
            //files associated with the address book if
            //we ever need this feature
            Current.filename=filename;
			//make sure the user isn't trying to get out of typing
            //in all the information
            if (Current.lastname!=""&&Current.firstname!=""
                &&Current.phoneNumber!=""&&Current.street!=""
                &&Current.zipCode!="")
            {
                //check to see if the address exists
                if (DoesAddressExist(Current.Key())==0)
                {
                    //if it doesn't, add it and show that it has been
                    //added
                    AddAddress();
                    title="Address Saved.";
					cout<<title.Center(80)<<endl;
					//we want the user to see that it has been added
                    //so wait for the user to press the enter key
                    Wait();					
					return;
                }
                else
                {
                    //if the address already exists, say so
                    title="Address already exists.";
                    cout<<title.Center(80)<<endl;
                    //and ask if the user wants to overwrite the
                    //entry...if so, then we're actually
                    //doing an edit
                    title="Overwrite (Y/N):";
                    cout<<endl<<title.CenterL(80);
                    string tmp;
                    cin>>tmp;
                    if (tmp=="Y"||tmp=="y")
                    {
                        bool success;
                        string tmp1=Current.Key().ucase();
						//delete the entry and add in the new
                        //entry
                        Addresses.SearchTreeDelete(tmp1,success);
                        AddAddress();
						return;
                    }
                }
            }        
            else
            {
                //if the user didn't put in all the fields
                //tell them the address isn't complete but
                //don't do anything with it just in case they
                //need to do something else
                title="Address not complete.  Address not saved.";
                cout<<title.Center(80)<<endl;
				Wait();
				return;
            }
        }
		else
			cout<<endl;
	}while(1);
}

//Miscellaneous address book function
//Add addressbook menu
void addressBook::DeleteAddressMenu()
{
	//this part of the code can probably be removed since there's
    //no real way to get in here other than the main menu
    if (Addresses.SearchTreeIsEmpty())
	{
		DoMenu();
		
		string title="Delete Address Menu";
        cout<<title.Center(80);
	    
	    title="___________________";
	    cout<<title.Center(80)<<endl<<endl;
		
		title="Nothing to delete";
		cout<<title.Center(80)<<endl<<endl;

		for (int j=1;j<12;j++)
            cout<<endl;
		
		Wait();
		
		return;
	}

	do
	{
		DoMenu();

        string title="Delete Address Menu";
        cout<<title.Center(80);
	    
	    title="___________________";
	    cout<<title.Center(80)<<endl<<endl;

	    title="1.  Delete one address         ";
		cout<<title.Center(80);
		title="2.  Delete entire address book ";
		cout<<title.Center(80);
		title="3.  Clear current address     ";
		cout<<title.Center(80);
		cout<<endl<<endl;
		title="R.  Return                    ";
		cout<<title.Center(80);
		
        for (int j=1;j<14;j++)
            cout<<endl;
	    
	    string c;
		
		c=Input("Enter choice:");
        
		if (c=="1")
        {
            string key1;
			//ask the user to input the search key
            cout<<"Enter lastname, firstname:";
            getline(cin,key1,'\n');
        	
			bool success;
			//make it uppercase to keep the search routine happy
            key1=key1.ucase();
			//try to delete the key
            Addresses.SearchTreeDelete(key1,success);
			if (!success)
			{
				//if the name doesn't exist, tell the user
                title="Name not found.";
				cout<<title.Center(80)<<endl;
				//problem with the input stream leaving returns
                //in the buffer...wait twice
                Wait(0);
				Wait(1);
				continue;
			}
			else
			{
				//if the name was found, tell the user
                title="Address Deleted";
				cout<<title.Center(80)<<endl;
				//same problem here...does cin.ignore have to be
                //used after all getlines?
                Wait(0);
				Wait(1);
				continue;
			}
		}
		else if (c=="2"||c=="3")
		{
            //since this routine can be "dangerous", ask the user
            //to make sure they want to do this
            string p;
			cout<<"Are you sure(Y/N)?";
            cin>>p;
			if (p=="y"||p=="Y")
			{
				if(c=="2")
				{
					//if they choose choice #2, destroy the entire
                    //tree
                    Addresses.DestroyEntireTree();
				}
				else
					//if #3 then clear the current person
                    ClearCurrent();
			}
		}
        else if (c=="R"||c=="r")
        {
            return;
        }
	}while(1);
}

//Miscellaneous address book function
//View addressbook menu
void addressBook::ViewAddressMenu()
{
	//This section of code can probably be removed
    if (Addresses.SearchTreeIsEmpty())
	{
		DoMenu();
		
		string title="View Address Menu";
        cout<<title.Center(80);
	    
	    title="_________________";
	    cout<<title.Center(80)<<endl<<endl;
		
		title="Nothing to view";
		cout<<title.Center(80)<<endl<<endl;

		for (int j=1;j<12;j++)
            cout<<endl;
		
		Wait();
		
		return;
	}

	do
	{
		//the person who is viewed from this menu will be the one
        //that will show up in the add menu...this allows editing of
        //data in the tree

        DoMenu();

        string title="View Address Menu";
        cout<<title.Center(80);
	    
	    title="_________________";
	    cout<<title.Center(80)<<endl<<endl;

	    title="1.  View one address                ";
		cout<<title.Center(80);
		title="2.  View entire address book       ";
		cout<<title.Center(80);
        title="3.  View address book search keys ";
		cout<<title.Center(80);
        cout<<endl<<endl;
		title="R.  Return                          ";
		cout<<title.Center(80);
		
        for (int j=1;j<14;j++)
            cout<<endl;

	    string c;
		
		c=Input("Enter choice:");
	    
        if (c=="1")
        {
            string key1;
			cout<<"Enter lastname, firstname:";
            getline(cin,key1,'\n');
        	
			key1=key1.ucase();
			
			bool success;
			//do pretty much the same thing delete option 1 does...
            Addresses.SearchTreeRetrieve(key1,Current,success);
			if (success==0)
			{
				title="Name not found.";
				cout<<title.Center(80)<<endl;
				Wait();
				continue;
			}
            else
            {
                ViewPerson(Current);
            	Wait(0);
				Wait(1);
				continue;
            }
		}
		else if (c=="2")
		{
            //do an inorder transverse of the BST and view the people
            //in the tree
            Addresses.InorderTraverse(ViewPerson);
			Wait();
			continue;
        }
        else if (c=="3")
        {
            //do an inorder transverse of the BST and view the keys
            //of the people in the tree
            Addresses.InorderTraverse(ViewKeys);
            Wait();
			continue;
        }
        else if (c=="R"||c=="r")
            return;
	}while(1);
}

//Miscellaneous address book function
//Load addressbook
void addressBook::LoadAddresses()
{
    DoMenu();

	string title;
	
    //a filename shouldn't be more than 255 characters
    char s[255];

	//since the file routines of C++ don't know what a string is,
    //convert the string to a pointer
    filename.cptr(s);

	//open the file stream for input
    ifstream f(s);

	//if a pointer can't be created for f then the file probably
    //doesn't exist or there is some other problem...since there are
    //too many variables, let's assume the file doesn't exist
    if (!f)
	{
		title="File doesn't exist";
		cout<<title.Center(80);
		cout<<endl;
		for(int j=1;j<18;j++)
			cout<<endl;

		Wait();
		return;
	}

    //get rid of any data in the tree since we don't want to merge
    //data that's already in the tree with data that will be loaded
    //from the file
    Addresses.DestroyEntireTree();

	//while we haven't hit the end of the file
    while(f.peek()!=EOF)
	{
		//get all the data from a csv or comma delimited file
        //get everything up to the comma
        getline(f,Current.lastname,',');    
		//for some strange reason, getline does not
        //kill the comma, so ignore will
        f.ignore(1,EOF);
		getline(f,Current.firstname,',');
		f.ignore(1,EOF);
		getline(f,Current.street,',');
		f.ignore(1,EOF);
		getline(f,Current.zipCode,',');
		f.ignore(1,EOF);
		getline(f,Current.phoneNumber,',');
		f.ignore(1,EOF);
		//since this is the last field, there should be a return
        //after it...get everything up to the return
        getline(f,Current.filename,'\n');
		f.ignore(1,EOF);
		//since we have a complete [or at least should have a complete]
        //address at this point, let's add it to the BST
        AddAddress();
	}

	//close the file to keep the file system happy
    f.close();

    //let the user know that the file was loaded
    title="Addresses loaded";
	cout<<title.Center(80);
	cout<<endl;
	for(int j=1;j<18;j++)
		cout<<endl;

	Wait();
}

//Miscellaneous address book function
//Save addressbook
void addressBook::SaveAddresses()
{
    DoMenu();
	
	string title;
	//if the address book is empty there is no reason to save anything
    if (Addresses.SearchTreeIsEmpty())
	{
		title="Nothing to save";
		cout<<title.Center(80);
		cout<<endl;
		for(int j=1;j<17;j++)
			cout<<endl;

		Wait();
		return;
	}

	char s[255];
	
    //convert the string to a pointer
    filename.cptr(s);
	
    //kill the file so we don't append to it or any odd thing like that
    remove(s);

    //do an inorder transverse and save the file
	Addresses.InorderTraverse(SavePerson);

	//let the user know the addresses were saved
    title="Addresses saved";
	cout<<title.Center(80);
	cout<<endl;
	for(int j=1;j<17;j++)
		cout<<endl;

	Wait();
	return;
}

//Miscellaneous address book function
//Checks to see if an address exists or not
int addressBook::DoesAddressExist(string t)
{
    bool success;
    string tmp;
	tmp=t.ucase();
	//create a temporary person so we don't overwrite the current
    //person
    person tmp1;
	//try to retrieve the person...if it exists, success will be 
    //1 else 0
    Addresses.SearchTreeRetrieve(tmp,tmp1,success);
    return success;
}

//Miscellaneous address book function
//Add address
void addressBook::AddAddress()
{
    bool success;   
	//add the current person to the BST [and sort it]
    Addresses.SearchTreeInsert(Current,success);
}

//Miscellaneous address book function
//Clear the current person
void addressBook::ClearCurrent()
{
	//reset all fields to null
    Current.firstname="";
	Current.lastname="";
	Current.phoneNumber="";
	Current.street="";
	Current.zipCode="";
	Current.filename="";
}

//Visit functions
//View a single person
void ViewPerson(person &p)
{
    //I hate the way this works...not having the ability to bring
    //in 2 or more parameters to the function and not having the 
    //fucntion a member of the class [even though it must be
    //in this file]
    
    //between each call, keep mode and lines in memory
    static int mode;
	static int lines;

	//check to see if this function has been called before
    //if it hasn't reset all the variables
    if (mode<0||mode>1)
	{
		mode=0;
		lines=0;
	}
	//set the mode to 1 to let us know the function has been
    //visited
    mode=1;

	//display the person in normal "address" format
    cout<<p.firstname<<" "<<p.lastname<<endl;
    cout<<p.street<<endl;
    cout<<p.zipCode<<endl;
    cout<<p.phoneNumber<<endl<<endl;
	
    //since there are 5 lines [4 lines of data and 1 blank line]
    //increment lines by 5
    lines=lines+5;

	//if we have more than 20 lines 
    if(lines>=20)
	{
		//pause the screen and let the user read the info on the
        //screen
        
        //if this function were in the class we would have access to
        //the wait function...oh well
        string title="Press enter to continue";
		cout<<endl<<title.Center(80)<<endl;
	    
		getline(cin,title,'\n');	
		cin.ignore(1,EOF);
	
        //since we've paused, set the lines back to 0
		lines=0;
	}
}

//Visit function
//Save address
void SavePerson(person& p)
{
	char s[255];
	
	p.filename.cptr(s);
	
    //open the file stream for append mode so we can add stuff to
    //the end of the file
    ofstream f(s,ios::app);

    //convert everything to pointers [just in case] and then
    //output it to the file in a comma delited format
    p.lastname.cptr(s);
    f<<s<<",";
    p.firstname.cptr(s);
    f<<s<<",";
    p.street.cptr(s);
	f<<s<<",";
	p.zipCode.cptr(s);
	f<<s<<",";
	p.phoneNumber.cptr(s);
	f<<s<<",";
	p.filename.cptr(s);
	f<<s<<endl;

    //make sure we close the file and flush the buffer out
	f.close();
}

//Visit function
//Displays a person's key
void ViewKeys(person &p)
{
    //just output the key
    cout<<p.Key()<<endl;
}

//Miscellaneous address book function
//Input function
string addressBook::Input(string prompt)
{
	//this routine is similar to QuickBasic's input routine
    //except that it centers the prompt
    cout<<prompt.CenterL(80);
	string temp;
	getline(cin,temp,'\n');
	//this is aggrevating...having to ignore the last character!
    cin.ignore(1,EOF);
	return temp;
}

//Miscellaneous address book function
//Wait function
void addressBook::Wait(int prompt)
{
	//this routine simply waits for the user to press enter
    string title;
	if (prompt==1)
	{
		//if prompt is set to 1 then pring the prompt
        title="Press enter to continue";
		cout<<endl<<title.Center(80)<<endl;
	}
	getline(cin,title,'\n');	
    cin.ignore(1,EOF);
}

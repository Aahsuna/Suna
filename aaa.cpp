

#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
 
char un[20];
class Admin
{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[20], mail[50], fname[20];
    char password[20], rpassword[20];
    public:
    char rollno[15];
    void getstdata ()
    {
        cout << "\nEnter the student name: ";
        gets (name);
        cout << "\nEnter the student ID/Roll no: ";
        cin >> rollno;
        cout << "\nEnter the student Father Name: ";
        gets (fname);
        cout << "\nEnter the mobile number: ";
        gets (mobile);
        cout << "\nEnter the E-mail ID: ";
        gets (mail);
        cout << "\nEnter the Total Subject: ";
        cin >> totsub;
        for (int i = 0; i < totsub; i++)
        {
	        cout << "\nEnter the subject:" << i + 1 << name;
	        cin >> subject[i];
        }
        cout << "\nCreate your login Password: ";
        cin >> password;
        cout << "\nEnter unique keyword to recover password: ";
        cin >> rpassword;
        cout << "\nYOUR STUDENT ID/ROLL NO IS YOUR PASSSWORD";
    }
    int login ()
    {
        int i;
        if ((strcmp (::un, rollno)) == 0)
        {
	        cout << "\nEnter the Login Password: ";
	        int len = 0;
	        len = strlen (password);
	        char inputpassword[20];
	        for (int i = 0; i < len; i++)
	        {
	            inputpassword[i] = getch ();
	            cout << "#";
	        }
	        inputpassword[i] = NULL;
	        if (((strcmp (::un, rollno)) == 0)&& (strcmp (password, inputpassword) == 0))
	        return 1;
	        else
	        return 0;
        }
        else
        return 0;
    }//this function helps both student and faculties to recover the password with the help of unique key provided by Admin.
    int recover ()
    {
        cout << "\nEnter the Input Username: " <<::un;
        char key[20];
        if (strcmp (::un, rollno) == 0)
        {
	        cout << "\nEnter the Unique Keyword(Provided by the adminin): ";
	        cin >> key;
	        if ((strcmp (key, rpassword) == 0))
	        {
	            cout << "\nYou are valid user.";
	            cout << "\nYour Password is " << password;
	            cout << "\n Please exit the login area.";
	            return 1;
	        }
	        else
	        return 0;
        }
        else
        return 0;
    }
    int faprofile ()
    {
        if ((strcmp (::un, rollno) == 0))
        {
	        cout << "\nFaculty Name           : " << name;
	        cout << "\nFaculty Father Name    : " << fname;
	        cout << "\nFaculty Mobile No.     : " << mobile;
	        cout << "\nFaculty E-Mail ID      : " << mail;
        }
        else
        return 0;
    }
    int knowfasub ()
    {
        if (strcmp (::un, rollno) == 0)
        {
	        cout << "\nFaculty Total Subject :-" << totsub;
	        for (int i = 0; i < totsub; i++)
	        {
	            cout << "\n\tSubject " << i + 1 << " : " << subject[i];
	        }
	        return 1;
        }
        else
        return 0;
    }
    void addfasub ()
    {
        if (strcmp (::un, rollno) == 0)
        {
	        cout << "\nEnter the New Subject : ";
	        cin >> subject[totsub];
	        totsub++;
	        cout << "\n\nNew Subject Added successfully....";
        }
    }
    void delfasub ()
    {
        knowfasub ();
        int de = 0;
        if (strcmp (::un, rollno) == 0)
        {
	        if (totsub == 0 || totsub < 0)
	        {
	            totsub = 0;
	            cout << "\nNo subject exist...";
	            getch ();
	            exit (0);
	        }
	        cout << "\nEnter the subject No. to be deleted : ";
	        cin >> de;
	        if (de == totsub)
	        {
	            totsub--;
	            strcpy (subject[totsub], " ");
	        }
	        else if (totsub == 1)
	        { 
	            totsub = 0;
	            strcpy (subject[totsub], " ");
	        }
	        else
	        {
	            de--;
	            strcpy (subject[totsub], " ");
	            for (int p = de; p < totsub; p++)
	            {
		            strcpy (subject[p], subject[p + 1]);
	            }
	            totsub--;
	        }
	        cout << "\nRecords Updated successfully...";
        }
    }
    void modfaprfile ()
    {
        if ((strcmp (::un, rollno) == 0))
        {
	        cout << "\nThe profile Details are : ";
	        cout << "\n1. Faculty E-Mail : " << mail;
	        cout << "\n2. Faculty Mobile : " << mobile;
	        int g = -1;
	        cout << "\n\nEnter the Detail No. to be modified : ";
	        cin >> g;
	        if (g == 1)
	        {
	            char nmail[50];
	            cout << "\nEnter the New Mail address : ";
	            strcpy (mail, nmail);
	            cout << "\nRecord Updated successfully...";
	        }
	        else if (g == 2)
	        {
	            char nmobile[15];
	            cout << "\nEnter the New Mobile NO. : ";
	            gets (nmobile);
	            strcpy (mobile, nmobile);
	            cout << "\nRecord Updated successfully...";
	        }
	        else
	        cout << "\nInvalid Information provided...";
        }
    }
  //to display the student profile in student portal
    int stprofile ()
    {
        if (strcmp (::un, rollno) == 0)
        {
	        cout << "\nStudent Name            :" << name;
	        cout << "\NStudent father name     :" << fname;
	        cout << "\nStudent Mobile No.      :" << mobile;
	        cout << "\nStudent E-mail          :" << mail;
	        return 1;
        }
        else
        return 0;
    }
    int knowstsub ()
    {
        if (strcmp (::un, rollno) == 0)
        {
	        cout << "\nStudent Total Subject :-" << totsub;
	        for (int i = 0; i < totsub; i++)
	        {
	            cout << "\n\tSubject " << i + 1 << " : " << subject[i];
	        }
	        return 1;
        }
        else
        return 0;
    }
    void addstsub ()
    {
        if (strcmp (::un, rollno) == 0)
        {
	        cout << "\nEnter the New Subject : ";
	        cin >> subject[totsub];
	        totsub++;
	        cout << "\n\nNew Subject Added successfully....";
        }
    }
    void delstsub ()
    {
        knowstsub ();
        int de = 0;
        if (strcmp (::un, rollno) == 0)
        {
	        if (totsub == 0 || totsub < 0)
	        {
	            totsub = 0;
	            cout << "\nNo subject exist...";
	            getch ();
	            exit (0);
	        }
	        cout << "\nEnter the subject No. to be deleted : ";
	        cin >> de;
	        if (de == totsub)
	        {
	            totsub--;
	            strcpy (subject[totsub], " ");
	        }
	        else if (totsub == 1)
	        {
	            totsub = 0;
	            strcpy (subject[totsub], " ");
	        }
	        else
	        {
	            de--;
	            strcpy (subject[totsub], " ");
	            for (int p = de; p < totsub; p++)
	            {
		            strcpy (subject[p], subject[p + 1]);
	            }
	            totsub--;
	        }
	        cout << "\nRecords Updated successfully...";
        }
    }
    void modstprfile ()
    {
        if ((strcmp (::un, rollno) == 0))
        {
	        cout << "\nThe profile Details are : ";
	        cout << "\n1. Student E-Mail : " << mail;
	        cout << "\n2. Student Mobile : " << mobile;
	        int g = -1;
	        cout << "\n\nEnter the Detail No. to be modified : ";
	        cin >> g;
	        if (g == 1)
	        {
	            char nmail[50];
	            cout << "\nEnter the New Mail address : ";
	            strcpy (mail, nmail);
	            cout << "\nRecord Updated successfully...";
	        }
	        else if (g == 2)
	        {
	            char nmobile[15];
	            cout << "\nEnter the New Mobile NO. : ";
	            gets (nmobile);
	            strcpy (mobile, nmobile);
	            cout << "\nRecord Updated successfully...";
	        }
	        else
	        cout << "\nInvalid Information provided...";
        }
    }				//function allow Admin to make a new record entry for different new faculties 
    void getfadata ()
    {
        cout << "\nEnter the Faculty Name : ";
        gets (name);
        cout << "\nEnter the Faculty ID/Roll no. : ";
        cin >> rollno;
        cout << "\nEmter the Faculty Father Name : ";
        gets (fname);
        cout << "\nEnter the Faculty Mobile No. : ";
        gets (mobile);
        cout << "\nEnter the Faculty E-mail ID : ";
        gets (mail);
        cout << "\nEnter the total subject : ";
        cin >> totsub;
        for (int i = 0; i < totsub; i++)
        {
	        cout << "\nEnter the Subject " << i + 1 << "Name : ";
	        cin >> subject[i];
        }
        cout << "\nCreate your login password : ";
        cin >> password;
        cout << "\nEnter the unique keyword to recover password : ";
        cin >> rpassword;
        cout << "\n\nPLEASE NOTE YOUR USERNAME IS ID/ROLL NO. \n";
    }
    void stdisplay ()
    {
        cout << "\nStudent Name : " << name;
        cout << "\nStudent ID/Roll no. n  : " << rollno;
        cout << "\nStudent Father Name    : " << fname;
        cout << "\nStudent E-mail ID      : " << mail;
        cout << "\nStudent Mobile No.     : " << mobile;
        cout << "\nStudent Subject        : " << totsub;
        for (int i = 0; i < totsub; i++)
        {
	    cout << "\n Subject " << i + 1 << " : " << subject[i];
        }
        if (totsub == 0)
        cout << "(None Subjects Specified.....)";
    }
    void fadisplay ()
    {
        cout << "\nFaculty Name           : " << name;
        cout << "Faculty ID/Roll no.      : " << rollno;
        cout << "\nFaculty father name    :" << fname;
        cout << "\nFaculty E-mail ID      :" << mail;
        cout << "\nFaculty Mobile No.     :" << mobile;
        cout << "\nFaculty subjects       :" << totsub;
        for (int i = 0; i < totsub; i++)
        {
            cout << "\n Subjects " << i + 1 << " : " << subject[i];
        }
        if (totsub == 0)
        cout << "None subject Specified.....";
    }
}

a;
Admin f;
#define admin "Admin";
int main ()
{
    int ch, k;
    system("CLS");
    cout << "\n\n\nWELCOME TO AAAAA.. DATABASE PORTAL ";
    cout << "\n\n\nEnter to continue ";
    getch ();
    system("CLS");
    cout << "\n\n\n\tPress 1 for Admin Portal";
    cout << "\n\tPress 2 for Faculty Portal ";
    cout << "\n\tPress 3 For Student Portal ";
    cout << "\n\n\tEnter your choice ";
    cin >> ch;
    system("CLS");
    if (ch == 1)
    {
        char adminuser[20], adminpass[20];
        cout << "\n\n\n\tWelcome to Admin Login Portal ";
        cout << "\nEnter the username ";
        cin >> adminuser;
        cout << "\nEnter the Password ";
        for (k = 0; k < 8; k++)
        {
            adminpass[k] = getch ();
            cout << "*";
        }
        getch ();
        adminpass[k] = NULL;
        if ((strcmp ((adminuser, "admin") == 0)&& (strcmp (adminpass, "password") == 0)))
	    {
	        system("CLS");
        }
	    else
	    {
	        cout << "\n\n\t\t Invalid access to Portal ";
	        cout << "\n\n\t\t Thank You!!! "; getch (); exit (0);
        }
	    char opera = 'y';
	    do
	    {
	        int tmp; 
            cout << "\n\n\t\t Welcime to Admin Panel"; 
            cout << "\n\n Press 1 to Add a Faculty Record"; 
            cout << "\n\n Press 2 to Add Multiple Record of Faculty"; 
            cout << "\n\n Press 3 to View All Record of Faculty"; 
            cout << "\n\n Press 4 to Delete a Faculty Record"; 
            cout << "\n\n Press 5 to Add a Student Record"; 
            cout << "\n\n Press 6 to Add Multiple Record of Student"; 
            cout << "\n\n Press 7 to View All Record of Student"; 
            cout << "\n\n Press 8 to Delete a Student Record"; 
            cout << "\n\n Press 9 to Exit"; 
            cout << "\n Enter your choice:"; 
            cin >> tmp; 
            system("CLS");
            if (tmp == 1)	//to enter the single faculty records.
	        {
	            cout << "\n Enter the details:-";
                fstream fs;
                fs.open ("fainfo.txt", ios::in | ios::out | ios::ate);
                a.getfadata ();
                fs.write ((char *) &a, sizeof (Admin));
                fs.close (); cout << "\n Record Entered Successfully...... ";
            }
            if (tmp == 2)		//to enter multiple record.
            {
                int m = 0;
                fstream fs; fs.open ("fainfo.txt", ios::in | ios::out | ios::ate);
                do
                {
                    cout << "\n Enter the details:-";
                    a.getfadata ();
                    fs.write ((char *) &a, sizeof (Admin));
                    cout << "\n\n Press 0 to enter more details:"; 
                    cin >> m;
                }
                while (m == 0);
                fs.close (); cout << "\n\n Record Entered Successfully......";  
            }
	        if (tmp == 3)		//to view faculty record
	        {
                fstream fs;
                fs.open ("fainfo.txt", ios::in); 
                fs.seekg (0); 
                while (!fs.eof ())
                {
                    fs.read ((char *) &a, sizeof (Admin));  
                    a.fadisplay ();
                }
                fs.close ();
            }
            if (tmp == 4)		//for deleting a faculty result
            {
                char tmpfaid[15];
                int de = 0, result = -1;
                cout << "\n\nEnter the Faculty ID/Roll no: ";
                cin >> tmpfaid;
                fstream fs;
                fs.open ("fainfo.txt", ios::in);
                fstream fs1;
                fs1.open ("fanewinfo.txt", ios::out | ios::ate); 
                while (!fs.eof ())
                {
	                fs.read ((char *) &a, sizeof (Admin));
	                result = strcmp (tmpfaid, a.rollno);    
                    if (result == 0)
	                {
                        de = 1;
                    }
                    else
                    {
                        fs1.write ((char *) &a, sizeof (Admin));
                    }
                }
                if (de == 1)
                {
                    cout << "\n\nRecord deleted successfully......";
                }
                else
                {
                    cout << "\n\nRecord Not Found...";
                }
                fs.close ();
                fs1.close ();
                remove ("fainfo.txt"); 
                rename ("fanewinfo.txt", "fainfo.txt");
            }
            if (tmp == 5)		//for student record
	        {
	            cout << "\n Enter the details:-";
                fstream fs;
                fs.open ("stinfo.txt", ios::in | ios::out | ios::ate);
                a.getstdata ();
                fs.write ((char *) &a, sizeof (Admin));
                 fs.close (); cout << "\n Record Entered Successfully...... ";
            }
            if (tmp == 6)		//to enter multiple record.
            {
                int m = 0;
                fstream fs; fs.open ("stinfo.txt", ios::in | ios::out | ios::ate);
                do
                {
                    cout << "\n Enter the details:-";
                    a.getstdata ();
                    fs.write ((char *) &a, sizeof (Admin));
                    cout << "\n\n Press 0 to enter more details:"; 
                    cin >> m;
                }while (m == 0);
                fs.close (); 
                cout << "\n\n Record Entered Successfully......";
            } 
            if (tmp == 7)		//to view student record
            {
                fstream fs;
                fs.open ("stinfo.txt", ios::in); 
                fs.seekg (0); 
                while (!fs.eof ())
                {
                    fs.read ((char *) &a, sizeof (Admin)); a.stdisplay ();
                }
                fs.close ();
            }
            if (tmp == 8)		//for deleting a student result
            {
                char tmpstid[15];
                int de = 0, result = -1;
                cout << "\n\nEnter the student ID/Roll no: ";
                cin >> tmpstid;
                fstream fs;
                fs.open ("stinfo.txt", ios::in);
                fstream fs1;
                fs1.open ("stnewinfo.txt", ios::out | ios::ate); 
                while (!fs.eof ())
                {
                    fs.read ((char *) &a, sizeof (Admin));
                    result = strcmp (tmpstid, a.rollno); 
                    if (result == 0)
                    {
                        de = 1;
                    }
                    else
                    {
                        fs1.write ((char *) &a, sizeof (Admin));
                    }
                }
                if (de == 1)
                {
                    cout << "\n\nRecord deleted successfully......";
                }
                else
                {
                    cout << "\n\nRecord Not Found...";
                }
            fs.close ();
            fs1.close ();
            remove ("stinfo.txt"); rename ("stnewinfo.txt", "stinfo.txt");
            }
            if (tmp == 9)
            {
            cout << "\n\n\n\n\t\t\tThank You!!!"; getch (); exit (0);}
            if (tmp < 1 || tmp > 9)
            {
                system("CLS"); 
                cout << "\n\n\n\t\tInvalid Input...";
            }
            getch ();
            cout << "\n\n\nPress y; For more Operation Otherwise n: ";
            cin >> opera; 
            if (opera != 'y')
            {
                getch ();
                system("CLS"); 
                cout << "\n\n\n\n\n\n\t\t\t\tThank You!!!!"; getch ();
            }        
        }while (opera == 'y' || opera == 'Y');
    }	//closing of admin login portal
	if (ch == 2)		//begin of faculty view portal
	{
	    system("CLS");;
	    char un[20];
	    int val, s = 0;
	    cout << "\n\t\tWelcome to Faculty Login Page";
	    cout << "\n\nEnter the Username  : ";
	    cin >>::un;
	    fstream fs;
	    fs.open ("fainfo.txt", ios::in | ios::binary);
	    fs.seekg (0); 
        while (!fs.eof ())
	    {
            val = -1;
            fs.read ((char *) &f, sizeof (Admin));
            val = f.login (); 
            if (val == 1)
            {
	            s = 1; 
                break;
            }
	    }
	    fs.close (); 
        if (s == 1)
	    {
	        system("CLS");;
        }
	    if (s != 1)		//if first login is invalid then.
	    {
	        system("CLS");
			int ho = 0; 
            cout << "\n\n\tYour login information is incorrect."; 
            cout << "\n\nThe Username is Your ID/Rollno."; 
            cout << "\nThe Password is case sensitive."; 
            cout << "\nPress 1 to Re-cover Password and 2 to Re-Attempt the login."; 
            cout << "\nEnter the Choice : "; 
            cin >> ho; 
            if (ho == 1)	//to recover password
	        {
				cout << "\nEnter the Username :- ";
				cin >>::un;
				fstream fs;
				fs.open ("fainfo.txt", ios::in | ios::binary);
				fs.seekg (0); int re, su = -1; 
				while (!fs.eof ())
				{
					re = -1;
					fs.read ((char *) &fs, sizeof (Admin));
					re = f.recover (); 
					if (re == 1)
					{
						su = 1; 
						break;
					}
				}
				fs.close (); 
				if (su == 1)
				{
					getch ();
					system("CLS"); 
					cout << "\n\n\n\tThank You !! "; 
					getch (); 
					exit (0);
				}
				else
				{
					cout << "\n\nInvalid user."; 
					getch (); 
					exit (0);
				}
			}//recover Password
			if (ho == 2)		//re-attempt login
			{
				cout << "\n\n\tEnter the Username : "; 
				cin >>::un; 
				fstream fs; 
				fs.open ("fainfo.txt", ios::in | ios::binary); 
				fs.seekg (0); 
				int suc = -1, valu;	//valu for storing login() return value suc for success login.
				while (!fs.eof ())
				{
					valu = -1;
					fs.read ((char *) &f, sizeof (Admin));
					valu = f.login (); 
					if (valu == 1)
					{
						suc = 1; 
						break;
					}
				}
				fs.close (); 
				if (suc == 1)
				{
					system("CLS");
				}
				else
				{
					getch ();
					cout << "\nInvalid User....";
					cout << "\n\n\t\t Thank You !!!"; 
					getch (); 
					exit (0); 
					exit (0);
				}
			}
			if (ho != 1 && ho != 2)
			{
				cout << "\nInvalid Input Provided.";
				cout << "\n\n\t\t Thank You !!!"; 
				getch (); 
				exit (0);
			}
		}			//closing of Invalid Login(forgotten or recover password)    
		char con = 'y';
		do
		{
			system("CLS");;
			cout << "\n\n\t\tWelcome to The Faculty Pannel ";
			cout << "\n\n\n\n\t\t\tYour Uername : " <<::un;
			cout << "\n\nPress 1 to View Your Profile.";
			cout << "\n\nPress 2 to Know Your subject.";
			cout << "\n\nPress 3 to Add a Subject.";
			cout << "\n\nPress 4 to Delete a Subject.";
			cout << "\n\nPress 5 to Modify your profile.";
			int choice;
			cout << "\nEnter your Choice : "; 
			cin >> choice; 
			if (choice == 1)
			{
				fstream fs;
				fs.open ("fainfo.txt", ios::in);
				fs.seekg (0); 
				int x; 
				while (!fs.eof ())
				{
					x = 0;
					fs.read ((char *) &f, sizeof (Admin));
					x = f.faprofile (); 
					if (x == 1)
					{
						break;
					}
				}
				fs.close ();
			}		//closing of choice 1
			if (choice == 2)
			{
			fstream fs;
			fs.open ("fainfo.txt", ios::in);
			fs.seekg (0); 
			int y; 
			while (!fs.eof ())
			{
				y = 0;
				fs.read ((char *) &f, sizeof (Admin));
				int y = f.knowfasub (); 
				if (y == 1)
				{
					break;
				}
			}
			fs.close ();}		//closing of choice 2.
			if (choice == 3)
			{
				fstream fs;
				fstream fs1;
				fs.open ("fainfo.txt", ios::in | ios::binary);
				fs1.open ("tmpfainfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				while (!fs.eof ())
				{
					fs.read ((char *) &f, sizeof (Admin));
					f.addfasub (); fs1.write ((char *) &f, sizeof (Admin));
				}
				fs.close (); 
				fs1.close (); 
				remove ("fainfo.txt"); 
				rename ("tmpfainfo.txt", "fainfo.txt");
			}	//closinjg of choice 3.
			if (choice == 4)
			{
				fstream fs;
				fstream fs1;
				fs.open ("fainfo.txt", ios::in | ios::binary);
				fs1.open ("delfainfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				while (!fs.eof ())
				{
					fs.read ((char *) &f, sizeof (Admin));
					f.delfasub (); 
					fs1.write ((char *) &f, sizeof (Admin));
				}
				fs.close (); 
				fs1.close (); 
				remove ("fainfo.txt"); 
				rename ("delfainfo.txt", "fainfo.txt");
			}	//closing of choice 4.
			if (choice == 5)
			{
				fstream fs;
				fstream fs1;
				fs.open ("fainfo.txt", ios::in | ios::binary);
				fs1.open ("modfainfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				while (!fs.eof ())
				{
					fs.read ((char *) &f, sizeof (Admin));
					f.modfaprfile (); 
					fs1.write ((char *) &f, sizeof (Admin));
				}
				fs.close (); 
				fs1.close ();
				remove ("fainfo.txt"); 
				rename ("modfainfo.txt", "fainfo.txt");
			}	//closing of choice 5.
			if (choice < 1 || choice > 5)
			{
				cout << "\n\n\t\tInvalid Input Provided!!";
				cout << "\n\n\t\tEnter to Continue."; 
				getch ();
			}
			cout << "\n\nPress y to Continue; Othewise n :";
			cin >> con;
			if (con != 'y' && con != 'y')
			{
				system("CLS");
				cout << "\n\n\n\n\t\t\t\tThank You!!"; 
				getch (); 
				exit (0);
			}
		}
		while (con == 'y' || con == 'y');
	}	//close of Faculty View.
	if (ch == 3)		//begin of Student view portal
	{
		system("CLS");
		char un[20];
		int value, s1 = 0;
		cout << "\n\t\tWelcome to Faculty Login Page";
		cout << "\n\nEnter the Username  : ";
		cin >>::un;
		fstream fs;
		fs.open ("fainfo.txt", ios::in | ios::binary);
		fs.seekg (0); while (!fs.eof ())
		{
		value = -1;
		fs.read ((char *) &f, sizeof (Admin));
		value = f.login (); 
		if (value == 1)
		{
			s1 = 1; 
			break;
		}
		}
		fs.close (); 
		if (s1 == 1)
		{
			system("CLS");
		}
		if (s1 != 1)		//if first login is invalid then.
		{
			system("CLS"); 
			int sho = 0; 
			cout << "\n\n\tYour login information is incorrect."; 
			cout << "\n\nThe Username is Your ID/Rollno."; 
			cout << "\nThe Password is case sensitive."; 
			cout << "\nPress 1 to Re-cover Password and 2 to Re-Attempt the login."; 
			cout << "\nEnter the Choice : "; 
			cin >> sho; 
			if (sho == 1)	//to recover password
			{
				cout << "\nEnter the Username :- ";
				cin >>::un;
				fstream fs;
				fs.open ("fainfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				int re, su = -1; 
				while (!fs.eof ())
				{
					re = -1;
					fs.read ((char *) &fs, sizeof (Admin));
					re = f.recover ();
					if (re == 1)
					{
						su = 1; 
						break;
					}
				}
				fs.close ();
				if (su == 1)
				{
					getch ();
					system("CLS");
					cout << "\n\n\n\tThank You !! "; 
					getch ();
					exit (0);
				}
				else
				{
				cout << "\n\nInvalid user."; 
				getch (); 
				exit (0);
				}
			}			//recover Password
			if (sho == 2)		//re-attempt login
			{
				cout << "\n\n\tEnter the Username : "; 
				cin >>::un; 
				fstream fs; 
				fs.open ("fainfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				int suc = -1, valu;	//valu for storing login() return value suc for success login.
				while (!fs.eof ())
				{
					valu = -1;
					fs.read ((char *) &f, sizeof (Admin));
					valu = f.login (); 
					if (valu == 1)
					{
						suc = 1; 
						break;
					}
				}
				fs.close ();
				if (suc == 1)
				{
					system("CLS");
				}
				else
				{
					getch ();
					cout << "\nInvalid User....";
					cout << "\n\n\t\t Thank You !!!";
					getch (); 
					exit (0); 
					exit (0);
				}
			}
			if (sho != 1 && sho != 2)
			{
				cout << "\nInvalid Input Provided.";
				cout << "\n\n\t\t Thank You !!!"; 
				getch (); 
				exit (0);
			}
		}			//closing of Invalid Login(forgotten or recover password)
		//begging of Student panel.    
		char moreop = 'y';
		do
		{
			system("CLS");
			cout << "\n\n\t\tWelcome to The Student Pannel ";
			cout << "\n\n\n\n\t\t\tYour Uername : " <<::un;
			cout << "\n\nPress 1 to View Your Profile.";
			cout << "\n\nPress 2 to Know Your subject.";
			cout << "\n\nPress 3 to Add a Subject.";
			cout << "\n\nPress 4 to Delete a Subject.";
			cout << "\n\nPress 5 to Modify your profile.";
			int inchoice;
			cout << "\nEnter your Choice : ";
			cin >> inchoice; 
			if (inchoice == 1)
			{
				fstream fs;
				fs.open ("stinfo.txt", ios::in);
				fs.seekg (0); 
				int x; 
				while (!fs.eof ())
				{
					x = 0;
					fs.read ((char *) &f, sizeof (Admin));
					x = f.stprofile ();
					if (x == 1)
					{
						break;
					}
				}
				fs.close ();
			}		//closing of choice 1
			if (inchoice == 2)
			{
				fstream fs;
				fs.open ("stinfo.txt", ios::in);
				fs.seekg (0);
				int y; 
				while (!fs.eof ())
				{
					y = 0;
					fs.read ((char *) &f, sizeof (Admin));
					int y = f.knowstsub ();
					if (y == 1)
					{
						break;
					}
				}
				fs.close ();
			}		//closing of choice 2.
			if (inchoice == 3)
			{
				fstream fs;
				fstream fs1;
				fs.open ("stinfo.txt", ios::in | ios::binary);
				fs1.open ("tmpstinfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				while (!fs.eof ())
				{
					fs.read ((char *) &f, sizeof (Admin));
					f.addstsub (); 
					fs1.write ((char *) &f, sizeof (Admin));
				}
				fs.close (); 
				fs1.close ();
				remove ("stinfo.txt");
				rename ("tmpstinfo.txt", "stinfo.txt");
			}	//closinjg of choice 3.
			if (inchoice == 4)
			{
			fstream fs;
			fstream fs1;
			fs.open ("stinfo.txt", ios::in | ios::binary);
			fs1.open ("delstinfo.txt", ios::in | ios::binary);
			fs.seekg (0);
			while (!fs.eof ())
			{
				fs.read ((char *) &f, sizeof (Admin));
				f.delstsub (); 
				fs1.write ((char *) &f, sizeof (Admin));
			}
			fs.close ();
			fs1.close ();
			remove ("stinfo.txt");
			rename ("delstinfo.txt", "stinfo.txt");
			}	//closing of choice 4.
			if (inchoice == 5)
			{
				fstream fs;
				fstream fs1;
				fs.open ("stinfo.txt", ios::in | ios::binary);
				fs1.open ("modstinfo.txt", ios::in | ios::binary);
				fs.seekg (0); 
				while (!fs.eof ())
				{
					fs.read ((char *) &f, sizeof (Admin));
					f.modstprfile ();
					fs1.write ((char *) &f, sizeof (Admin));
				}
				fs.close ();
				fs1.close ();
				remove ("stinfo.txt");
				rename ("modstinfo.txt", "stinfo.txt");
			}	//closing of choice 5.
			if (inchoice < 1 || inchoice > 5)
			{
				cout << "\n\n\t\tInvalid Input Provided!!";
				cout << "\n\n\t\tEnter to Continue."; 
				getch ();
			}
			cout << "\n\nPress y to Continue; Othewise n :";
			cin >> moreop;
			if (moreop != 'y' && moreop != 'y')
			{
				system("CLS");
				cout << "\n\n\n\n\t\t\t\tThank You!!"; 
				getch (); 
				exit (0);
			}
		}while (moreop == 'y' || moreop == 'y');
	}	//close of student View.
	if (ch < 1 || ch > 3)
	{
		cout << "\nInvalid Input Provided!!! ";
		getch (); 
		system("CLS");
		cout << "\n\n\n\n\t\t\tThank You!!!";
	}
	return 0; 
	getch ();
}

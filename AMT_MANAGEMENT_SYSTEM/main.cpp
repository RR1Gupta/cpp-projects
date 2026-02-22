// ATM MANAGEMENT SYSTEM USING C++
// FEATURES- LOGIN SIGNUP CHECKABALCE CHAGNEPIN WITHDRAW 
// FILE USED- "ATM.TXT"
// TEMPORARY FILE USED- "TEMP.TXT"

#include<iostream> //for cin cout
#include<conio.h> // for getch
#include<fstream>  //for file  atm.txt and temp.txt
#include<cctype> // for cin clear and ignore
#include<string> // string functions and datatypes
#include<cstdlib> // for system .clear
#include<sstream> // for string varibles to convert into int, because getline accepts string only
using namespace std;

class A
{
	public:
	string accountnumber, pin,withdrawstring;
	string fileaccountno,filepin,filebalancestring;
	int withdrawint,filebalanceint;
	void signup();
	void login();
	void check_balance();
	void withdraw();
	void changepin();
	void deposit();
	string pinfun(); //for pin to mask
	string accountfun(); // for right account number to take , correct 9 digits and digits only
	string wdfun();  // for valid withdraw amount to take , means not 0 or not alphabets
}object;//class 

int main()
{ 
/*file 
ofstream myfile("atm.txt");
myfile<<123456789<<"*"<<1234<<"*"<<450<<"*"<<endl;
myfile.close();*/ //let sign up handle this part
int choice;
	do{
		cout<<"1) SIGN UP  2) LOGIN  3) WITHDRAW 4) CHECK_BALANCE  5) CHANGE_PIN  6)DEPOSIT 7) CLEAR  8) EXIT"<<endl;
		cout<<"ENTER CHOICE"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:	cin.clear();
			        cin.ignore(1000,'\n');
			 	object.signup();
			 	break;
			case 2:	cin.clear();
			cin.ignore(1000,'\n');
			    object.login(); break;
		case 3:
			cin.clear();
			cin.ignore(1000,'\n');
				object.withdraw();
				break;
		case 4:
			cin.clear();
			cin.ignore(1000,'\n');
				object.check_balance();
				break;
			case 5:
				cin.clear();
			cin.ignore(1000,'\n');
				object.changepin();
				break;
				case 6:
					cin.clear();
			cin.ignore(1000,'\n');
					object.deposit();
					break;
			case 7:
				cin.clear();
			cin.ignore(1000,'\n');
				system("cls");
				break;
			case 8:
				cout<<"THANKYOU FOR USING OUR SYSTEM "<<endl;
			break;
			 default:
			 	cout<<"INVALID CHOICE"<<endl;
		}//switch
	}while(choice!=8); //do while
}//int main

string A::accountfun()
{ string accno;
	while(cin>>accno)
	   { bool check=true;
	           if(accno.length()!=9 )
	            {
	            	cin.clear();
	            	cin.ignore(1000,'\n');
		      cout<<"ACCOUNT NUMBER MUST BE EXACTLY 9 DIGTIS, ENTER AGAIN ";
		      continue;
	         	}
	        for(int i=0;i<accno.length();i++)
	        {
	        	if(!isdigit(accno[i]))
	        	{
				cout<<"ACCOUT NUMBER SHOULD BE NUMBER ONLY NO ALPHABETS "<<endl;
              check=false;
              break;
			  } 
			}
		if(check==false)
	{
		cin.clear();
		cin.ignore(1000,'\n');
		continue;
		}
		break;
	}
return accno;
} // void account fun 


string A::pinfun()
{
	string pin="";
	char c;
	while(pin.length()<4)
	{
		c=_getch();
		if(isdigit(c))
		{
		pin+=c;
		cout<<"*";
		}
	}return pin;
} //pinfun


string A::wdfun()
{ string withdrawstring;
	while(cin>>withdrawstring)
	{
		bool check1=true,check=true;
		for(int i=0;i<withdrawstring.length();i++)
		{
			if(!(isdigit(withdrawstring[i])))
			{
			cout<<"ENTER DIGITS ONLY "<<endl;
			check=false;
			break;
			}
		} if(check==false) continue;
		stringstream ss(withdrawstring); // convert into int after 1 st validation that all are digits
ss>>withdrawint;
		if(withdrawint<=0)
			{ cout<<"AMOUNT SHOULD BE GREATER THAN 0"<<endl;
			check1=false;
		continue;
			}
	if(check1==true)break;
	} return withdrawstring;
}


void A::signup()
{
cout<<"ENTER ACCOUNT NUMBER"<<endl;
accountnumber=accountfun();
bool signup=true;
ifstream myfile("atm.txt");
while(getline(myfile,fileaccountno,'*')&&getline(myfile,filepin,'*') &&getline(myfile,filebalancestring))
{
	if(accountnumber==fileaccountno)
	{
		signup=false;
		break;
}}
if(signup==false) {
cout<<"ACCOUNT ALREADY EXISTS " <<endl;
myfile.close();
return;
}
cout<<"ENTER PIN"<<endl;
pin=pinfun();

cout<<endl<<"ENTER STARTING AMOUNT"<<endl;
withdrawstring=wdfun();
myfile.close();
	ofstream myfile1("atm.txt",ios::app);
	myfile1<<accountnumber<<"*"<<pin<<"*"<<withdrawstring<<endl;
	myfile1.close();
	cout<<"ACCOUNT SUCCESSFULLY CREATED WITH STARTING AMOUNT - "<<withdrawstring<<endl;	
}//signup

void A :: login()
{ 
    bool check=false,check1=false;
	cout<<"ENTER ACCOUNT NUMBER "<<endl;
	accountnumber=accountfun();
	ifstream myfile("atm.txt");
    while(getline(myfile,fileaccountno,'*')&& getline(myfile,filepin,'*')&&getline(myfile,filebalancestring))
{
	if(accountnumber==fileaccountno)
	{
		check=true;
		break;
	}
}
if(check==false){
	cout<<"ACCOUNT DOES NOT EXIST "<<endl;
myfile.close();
	return;
} myfile.close();
	cout<<"ENTER PIN"<<endl;
	pin=pinfun(); 
	ifstream myfile1("atm.txt");
	while(getline(myfile1,fileaccountno,'*')&& getline(myfile1,filepin,'*')&&getline(myfile1,filebalancestring))
	{
		if(accountnumber==fileaccountno && pin==filepin)
		{
			check1=true;
			break;
		}//if
	}//while
	if(check1==false)
	{
		cout<<"INVALID PIN"<<endl;
		myfile1.close();
		return;
	}
	myfile1.close();
		if(check1==true && check==true)
		{
			cout<<endl<<"LOGIN SUCCESSFUL"<<endl;
		}
}// login function
/*checking accountnumber first if exits than ask for pin if not ,exit the loop immediately without asking for pin
better logic to check both at once
we have to check both pin and acoountnumber together when validating pin because pins can repeat meaning
multiple accounts can have same pin , we want same account same pin
we have to open the file again because at first reading pointer comes to end of file reading again will create error
so creating opening file and reading from start*/

void A::withdraw()
{
bool accountcheck=false;
bool pincheck=false;
bool withdrawdone=false;
	cout<<"ENTER ACCOUNT NUMBER"<<endl;
	accountnumber=accountfun();
	ifstream myfile("atm.txt");
while(getline(myfile,fileaccountno,'*')&& getline(myfile,filepin,'*')&&getline(myfile,filebalancestring))
{
	if(accountnumber==fileaccountno)
	{
		accountcheck=true;
		break;
	}
}myfile.close();
if(accountcheck==false)
{cout<<"INVALID ACCOUNT NUMBER "<<endl;
return;}
	cout<<"ENTER PIN"<<endl;
	pin=pinfun();
	ifstream myfile1("atm.txt");
while(getline(myfile1,fileaccountno,'*')&& getline(myfile1,filepin,'*')&&getline(myfile1,filebalancestring))
{
	if(accountnumber==fileaccountno &&pin==filepin)
	{
		pincheck=true;
		break;
	}
}
myfile1.close();
if(pincheck==false)
{cout<<"INVALID PIN NUMBER "<<endl;
return;}
cout<<endl;
    ifstream myfile2("atm.txt");
	ofstream temp("temp.txt");
	while(getline(myfile2,fileaccountno,'*')&& getline(myfile2,filepin,'*')&&getline(myfile2,filebalancestring))
	{ 
	stringstream ss(filebalancestring);
	ss>>filebalanceint;
		 if(accountnumber==fileaccountno && filepin==pin && withdrawdone==false)
		{ 
			cout<<"ACCOUNT BALANCE IS "<<filebalanceint<<endl;
			cout<<"ENTER HOW MUCH AMOUNT U WANT TO WITHDRAW"<<endl;
			withdrawstring=wdfun(); //bcoz wdfun is string function so need to store in withdrawstring 
			stringstream ss1(withdrawstring);
			ss1>>withdrawint;
		//	withdrawint=wdfun();
			if(withdrawint<=filebalanceint)
			{   filebalanceint=filebalanceint-withdrawint;
				cout<<"CONGRATS, SUCCESSFULL WITHDRAW DONE "<<endl;
				withdrawdone=true;
			//	temp<<fileaccountno<<"*"<<filepin<<"*"<<filebalanceint<<endl;
		
			}else cout<<"INSUFFICIENT BALANCE"<<endl;	
	}temp<<fileaccountno<<"*"<<filepin<<"*"<<filebalanceint<<endl;	
	}
	temp.close();
	myfile2.close();
	remove("atm.txt");
	rename("temp.txt","atm.txt");
}//withdraw function
/* fist accouncheck if exits than great no than return immediatley same for pin 
  if both okay great open file again check for how much amount is there 
  ask user to enter withdrawal amount, check if it is less than or equal to amount present
  than suuceeful else insufficiecnt 
  if suucessufl withdraw done , than dont run if coinditon again only while till end of file for temp file
  to store data 
  once finsihsed replace temp file
*/

void A:: changepin()
{ bool pindone=false;
bool accountnumberexist=false ,pinexist=false,oldpincheck=true;
	 cout<<"ENTER ACCOUNT NUMBER "<<endl;
	 accountnumber=accountfun();
	 ifstream myfile("atm.txt");
	 while(getline(myfile,fileaccountno,'*')&& getline(myfile,filepin,'*') && getline(myfile,filebalancestring))
	 {
	 	if(accountnumber==fileaccountno)
	 	{
	 		accountnumberexist=true;
	 		break;
		 }
	 } myfile.close();
	 if(accountnumberexist==false)
	 {
	 	cout<<"INVALID ACCOUNT NUMBER "<<endl;
	 	return;
	 }
	 cout<<"ENTER OLD PIN "<<endl;
	 pin=pinfun();
	 ifstream myfile1("atm.txt");
	  while(getline(myfile1,fileaccountno,'*')&&getline(myfile1,filepin,'*') && getline(myfile1,filebalancestring))
	 {
	 	if(pin==filepin && accountnumber==fileaccountno) //pin should match acoutn number
	 	{
	 		pinexist=true;
	 		break;
		 }
	 }myfile1.close();
	 if(pinexist==false)
	 {
	 	cout<<"INVALID PIN "<<endl;
	 	return;
	 }
	 cout<<endl;
	 ifstream myfile2("atm.txt");
	 ofstream temp("temp.txt");
	 while(getline(myfile2,fileaccountno,'*')&& getline(myfile2,filepin,'*')&&getline(myfile2,filebalancestring))
	{ stringstream ss(filebalancestring);
        ss >> filebalanceint;
		if(accountnumber==fileaccountno && filepin==pin &&pindone==false)
		{
			cout<<"ENTER NEW PIN "<<endl;
		    pin=pinfun();
			cout<<endl;
			if(pin==filepin){
				cout<<"OLD PIN IS SAME AS NEW PIN , NOTHING UPDATED "<<endl;
				oldpincheck=false;
				pindone=true;
			}
			else
			{
				filepin=pin;
				pindone=true;
			}
		} 
		temp<<fileaccountno<<"*"<<filepin<<"*"<<filebalanceint<<endl;	
}//while
if(oldpincheck==true && pindone==true) cout<<"PIN SUCCESFULY UPDATED "<<endl;
temp.close();
myfile2.close();
remove("atm.txt");
rename("temp.txt","atm.txt");
}//changepin function


void A::check_balance()
{ bool pinexist=false,accountnumberexist=false;
cout<<"ENTER ACCOUNT NUMBER "<<endl;
	 accountnumber=accountfun();
	 ifstream myfile("atm.txt");
	 while(getline(myfile,fileaccountno,'*')&& getline(myfile,filepin,'*') && getline(myfile,filebalancestring))
	 {
	 	if(accountnumber==fileaccountno)
	 	{
	 		accountnumberexist=true;
	 		break;
		 }
	 } myfile.close();
	 if(accountnumberexist==false)
	 {
	 	cout<<"INVALID ACCOUNT NUMBER "<<endl;
	 	return;
	 }
	 cout<<"ENTER PIN "<<endl;
	 pin=pinfun();
	 ifstream myfile1("atm.txt");
	  while(getline(myfile1,fileaccountno,'*')&&getline(myfile1,filepin,'*') && getline(myfile1,filebalancestring))
	 {
	 	if(pin==filepin && accountnumber==fileaccountno) //pin should match acoutn number
	 	{
	 		pinexist=true;
	 		break;
		 }
	 }myfile1.close();
	 if(pinexist==false)
	 {
	 	cout<<"INVALID PIN "<<endl;
	 	return;
	 }
	 cout<<endl;
	ifstream myfile2("atm.txt");
	while(getline(myfile2,fileaccountno,'*')&& getline(myfile2,filepin,'*')&&getline(myfile2,filebalancestring))
	{ 
	stringstream ss(filebalancestring);
	ss>>filebalanceint;
		if(accountnumber==fileaccountno && filepin==pin)
		{ 
			cout<<"ACCOUNT BALANCE IS "<<filebalanceint<<endl;
			break;	
		}
}
myfile2.close();
}// check balance function


void A::deposit()
{
bool accountcheck=false;
bool pincheck=false;
bool withdrawdone=false;
	cout<<"ENTER ACCOUNT NUMBER"<<endl;
	accountnumber=accountfun();
	ifstream myfile("atm.txt");
while(getline(myfile,fileaccountno,'*')&& getline(myfile,filepin,'*')&&getline(myfile,filebalancestring))
{
	if(accountnumber==fileaccountno)
	{
		accountcheck=true;
		break;
	}
}myfile.close();
if(accountcheck==false)
{cout<<"INVALID ACCOUNT NUMBER "<<endl;
return;}
	cout<<"ENTER PIN"<<endl;
	pin=pinfun();
	ifstream myfile1("atm.txt");
while(getline(myfile1,fileaccountno,'*')&& getline(myfile1,filepin,'*')&&getline(myfile1,filebalancestring))
{
	if(accountnumber==fileaccountno &&pin==filepin)
	{
		pincheck=true;
		break;
	}
}
myfile1.close();
if(pincheck==false)
{cout<<"INVALID PIN NUMBER "<<endl;
return;}
cout<<endl;
    ifstream myfile2("atm.txt");
	ofstream temp("temp.txt");
	while(getline(myfile2,fileaccountno,'*')&& getline(myfile2,filepin,'*')&&getline(myfile2,filebalancestring))
	{ 
	stringstream ss(filebalancestring);
	ss>>filebalanceint;
		 if(accountnumber==fileaccountno && filepin==pin && withdrawdone==false)
		{ 
			cout<<"ACCOUNT BALANCE IS "<<filebalanceint<<endl;
			cout<<"ENTER HOW MUCH AMOUNT U WANT TO DEPOSIT"<<endl;
			withdrawstring=wdfun(); //bcoz wdfun is string function so need to store in withdrawstring 
			stringstream ss1(withdrawstring);
			ss1>>withdrawint;
		//	withdrawint=wdfun();
		
			filebalanceint=filebalanceint+withdrawint;
				cout<<"CONGRATS, SUCCESSFUL DEPOSIT DONE "<<endl;
				withdrawdone=true;
			//	temp<<fileaccountno<<"*"<<filepin<<"*"<<filebalanceint<<endl;
		
			
	}temp<<fileaccountno<<"*"<<filepin<<"*"<<filebalanceint<<endl;	
	}
	temp.close();
	myfile2.close();
	remove("atm.txt");
	rename("temp.txt","atm.txt");
}//deposit function


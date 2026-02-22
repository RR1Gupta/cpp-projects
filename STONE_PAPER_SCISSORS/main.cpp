#include<iostream>
#include<ctime>  // for time
#include<cstdlib> // for rand and cin clear and ignore
#include<string> // for some versions
using namespace std;

class A
{public:
	int userchoice,computerchoice,userscores=0,computerscores=0;
	//initialized scores varibles otherwise it stores garbage value;
void play();
int userinputvalidation();
int switchchoicevalidation();
};
int A::switchchoicevalidation()
{
 int c;
 while(true)
 {
 	if(!(cin>>c))
 	{
 		cout<<"ENTER NUMBERS ONLY "<<endl;
 		cin.clear();
 		cin.ignore(1000,'\n');
 		continue;
	 }
	 if(c<=0 || c>3)
	 {
	 	cout<<"ENTER NUMBER IN THE RANGE OF 1 TO 3 "<<endl;
	 	continue;
	 }
	 break;
	 }	return c;
}
int main()
{  A object;
srand(time(0));
/*srand means fucntion of rand it gives seqences to rand and form that rand picks number
means like many boxes box1 box2 srand will tell rand which box, than rand will pick from that box
now once wrote that sentence whatver current time seconds value is there that will go and store as seed/sequnce
now from this sequnce only rand keeps picking values
like playlist decided rand will keep picking songs from that playlist keep playng songs
declared in main so squnce dosent needs to be updated again and again 
*/
	int choice;
do{
	cout<<"1) PLAY 2) CLEAR 3) EXIT "<<endl;
	cout<<"ENTER CHOICE "<<endl;
choice=object.switchchoicevalidation();
//cin>>choice;
	switch(choice)
	{
		case 1:
			object.play();
			break;
		case 2:
			system("cls");
			break;
		case 3:
			cout<<"THANKS FOR PLAYING , HAVE A GOOD DAY "<<endl;
			break;
		default:
			cout<<"INVALID CHOICE "<<endl;
	}//switch
}while(choice!=3); //do while
}//int main

int A::userinputvalidation()
{
	int n;
    while(true)
    {
    	if(!(cin>>n) )//isdigit takes char datatype variables 
    	{
    		cout<<"ENTER DIGITS ONLY "<<endl;
    		cin.clear();
    		cin.ignore(1000,'\n');
    		continue;
		}
		if(n<=0 || n>3)
		{  cin.clear();
		cin.ignore(1000,'\n');
			cout<<"ENTER NUMBER IN THE RANGE OF 1 TO 3 "<<endl;
			continue;
		}
		break;
	} return n;
}


void A :: play()
{   //srand(time(0));
const string choices[]={"","STONE ","PAPER ","SCISSORS "}; 
//constant means making array contant so later in program values inside it cannot be changed
/*
so index from 0 to 3 beacuse user give 1 2 3 
user will not enter 0 so emoty string ownt come , options will come from 1 2 3 only
if not give empty brakctes then array index outof range error will come and crash the prorgam 
*/
	cout<<"1) STONE 2) PAPER 3) SCISSORS "<<endl;
	cout<<"ENTER YOUR CHOICE "<<endl;
	userchoice=userinputvalidation();
	
	//cout<<"USER'S CHOICE = "<<choices[userchoice]<<endl;
	//suggested writing both at once 
	computerchoice=rand()%3+1;
	//%3 will give remiander 0,1,2 so +1
	//if we use %4 than remainders will be 0,1,2,3
	//rand gives biger number we want smaller numbers
	cout<<"USERS CHOICE "<<choices[userchoice]<<endl;
	cout<<"COMPUTERS CHOICE "<<choices[computerchoice]<<endl;
	
	if(userchoice==computerchoice)
	{
	cout<<"IT'S A TIE "<<endl;}
	else if((userchoice==1 && computerchoice==3) ||
	       (userchoice==2 && computerchoice==1) ||
	       (userchoice==3 && computerchoice==2))
	{
	cout<<"USER WINS! "<<endl;
userscores=userscores+1; //userscores++ (shorter version)
}
	else
{
cout<<"COMPUTER WINS! "<<endl;
	computerscores=computerscores+1;
	}
	
cout<<"COMPUTER SCORES "<<computerscores<<" USERS SCORES "<<userscores<<endl;	
}


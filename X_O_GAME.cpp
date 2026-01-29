#include<iostream>
#include<cstdlib>
using namespace std;
class A{public:
char a[9]={'1','2','3','4','5','6','7','8','9'};
    void play();
	void displayboard();
	int checkwin()
	{    
	     //row
		if(a[0]==a[1] &&a[1]==a[2]) return 1;
		if(a[3]==a[4] &&a[4]==a[5]) return 1;
		if(a[6]==a[7]&& a[7]==a[8]) return 1;
		
		//column
		if(a[0]==a[3] &&a[3]==a[6]) return 1;
		if(a[1]==a[4] &&a[4]==a[7]) return 1;
		if(a[2]==a[5]&& a[5]==a[8]) return 1;
		
		//diagonal
		if(a[0]==a[4] &&a[4]==a[8]) return 1;
		if(a[2]==a[4] &&a[4]==a[6]) return 1;
	 return 0 ; // if function didnt return anything it may cause garbage value	
	}
	
	int checkdraw()
	{
		for(int i=0;i<9;i++)
		{
			if(a[i]!='X' && a[i]!='O')
			// we will check each box till 9
			// no box should have x or o
		{
			return 0;
			// means even if one time if funtion exceutes than 1 box is empty and exit the function
		}
		}return 1;
	}
}; 
int main()
{
	A object;
	int choice;
do{  
	cout<<"1) PLAY 2) EXIT "<<endl;
	cout<<"ENTER CHOICE "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cin.clear();
			cin.ignore(1000,'\n');
			object.play();
			break;
		/*case 2:
			system("cls");
			break;*/ //clearning after every value makes it look clean 
		case 2:
			cout<<"THANKS FOR PLAYING , HAVE A GOOD DAY "<<endl;
			break;
	}//switch
}while(choice!=2);
} //int main


void A:: displayboard()
	{
	cout<<a[0]<<"     |     "<<a[1]<<"    |    "<<a[2]<<endl;
	cout<<"------|----------|----------"<<endl;
	cout<<a[3]<<"     |     "<<a[4]<<"    |    "<<a[5]<<endl;
	cout<<"------|----------|----------"<<endl;
	cout<<a[6]<<"     |     "<<a[7]<<"    |    "<<a[8]<<endl;
	} //end of display board function


void A::play()
{
	for(int i=0;i<9;i++)
	a[i]='1'+i; // reseting the board every time play is called 
	//calling for looptill 9
	// for every number a[i] wll get numbers from i (0 to 9)
	while(true)
{
displayboard();
int xpos=0,ypos=0;

cout<<"PLAYER X ,ENTER POSITION 1-9 "<<endl;
while(true){
if(!(cin>>xpos))
{ cout<<"ENTER NUMBERS ONLY NO ALPHABETS "<<endl;
	cin.clear();
	cin.ignore(1000,'\n');
	continue;
}
if(xpos<=0 || xpos>9)
{
	cout<<"ENTER IN RANGE "<<endl;
	continue;
}   // first check range than value , otherwise accessing out of range index with crash program

if(a[xpos-1]=='X' || a[xpos-1]=='O')
{
	cout<<"POSTION ALREADY TAKEN, ENTER AGAIN "<<endl;
	continue;	
}

break;
}
a[xpos-1]='X';
displayboard();
if(checkwin()==1)
{ cout<<"PLAYER X WINS "<<endl;
	break;
}
if(checkdraw()==1)
{
	cout<<"ITS A DRAW "<<endl;
	break;
	}
cout<<"PLAYER O , ENTER POSTION 1-9 "<<endl;
while(true){
if(!(cin>>ypos))
{ cout<<"ENTER NUMBERS ONLY NO ALPHABETS "<<endl;
	cin.clear();
	cin.ignore(1000,'\n');
	continue;
}
	if(ypos<=0 || ypos>9)
{
	cout<<"ENTER IN RANGE OF 1-9"<<endl;
	continue;
}
if(a[ypos-1]=='X' || a[ypos-1]=='O')
{
cout<<"POSITION ALREADY TAKEN , ENTER AGAIN "<<endl;
	continue;
}
break;
}	
a[ypos-1]='O';	
displayboard();
if(checkwin()==1)
{ cout<<"PLAYER  O WINS "<<endl;
	break;
}
if(checkdraw()==1)
{
	cout<<"ITS A DRAW "<<endl;
	break;
	} system("cls");// to keep ouput clean
}


}// void play


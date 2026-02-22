#include<iostream>
#include<cstdlib>
using namespace std;
class Convertor
{    
    public:
	int decimal , binary;
	void decimaltobinary();
	void binarytodecimal();
	int decimalvalidation();
	int binaryvalidation();
	int choicevalidation();
    string onlydigits();
};
int main()
{
   Convertor object;
   int choice;
do{
   cout<<"1) BINARY_TO_DECIMAL 2) DECIMAL_TO_BINARY 3) CLEAR 4) EXIT"<<endl;
   cout<<"ENTER CHOICE"<<endl;
   choice=object.choicevalidation();
   switch(choice)
   {
   	case 1:object.binarytodecimal();
   	break;
   	case 2:object.decimaltobinary();
   	break;
   	case 3:system("cls");
   	break;
   	case 4:cout<<"THANKS FOR USING OUR SYSTEM"<<endl;
   	break;
   	default:
   		cout<<"INAVLID CHOICE"<<endl;
   }//switch
}while(choice!=4);
}//int main

string Convertor::onlydigits()
{
	string n;
	while(true)
	{   bool check=true;
		cin>>n;
		for(char c:n)
		{
			if(!(isdigit(c)))
			{
				cout<<"ENTER ONLY DIGITS"<<endl;
				check=false;
				break;
			}
		}if(check==true)return n;
		else continue;
	}
}

int Convertor::choicevalidation()
{
	string n;
	while(true)
	{   
	    bool check=true;
		n=onlydigits();
		if(n.length()>1)
		{
			cout<<"ENTER 1 DIGIT CHOICE VALUE "<<endl;
			continue;
		}
		for(char c:n)
		{
			if(c!='1' && c!='2' &&c!='3' && c!='4')
			{
				cout<<"ENTER IS RANGE OF 1 TO 4"<<endl;
				check=false;
				break;
			}
		}if(check==true)return stoi(n);
		else {
			continue;
		}
	}
}

int Convertor::decimalvalidation()
{       
         string n;
         while(true)
	   {
	n=onlydigits();
		if(n.length()<=8)
		{
		return stoi(n);
}
		else
		{
			cout<<"ENTER MAX 8 DIGITS"<<endl;
			continue;
		}}	
}


int Convertor::binaryvalidation()
{
	 string n;
	 while(true)
{    
    bool check=true;
	 n=onlydigits();
	 if(n.length()>8) // instead of (!(n.length()<=8))
	 {
	 	cout<<"ENTER IN THE RANGE OF 1-8"<<endl;
	 	continue;
	 }
	 for(char c:n)
	 {
	 	if(c!='1' && c!='0')
	 	{
	 		cout<<"ENTER 1 OR 0 ONLY"<<endl;
	 		check=false;
	 		break;
		}
	 }if(check==false)continue;
	 else return stoi(n);
	 }	 
}

void Convertor::binarytodecimal()
{
	cout<<"ENTER NUMBER"<<endl;
	binary=binaryvalidation();
		if(binary==0)
	{
		cout<<"DECIMAL FORM = 0 "<<endl;
		return;
	}
	int i=0;
	int ans=0;
	while(binary>0)
	{
		int lastdigit=binary%10;
		//ans+=lastdigit*(pow(2,i));
		ans+=lastdigit*(1<<i); //shifting i binary by 1 everytime
		binary/=10;
		i++;
	}
	cout<<"DECIMAL FORM = "<<ans<<endl;
}

void Convertor::decimaltobinary()
{
	cout<<"ENTER NUMBER"<<endl;
    decimal =decimalvalidation();
    	if(decimal==0)
	{
		cout<<"BINARY FORM = 0 "<<endl;
		return;
	}
	int res[32];
	int i=0;
	while(decimal>0)
	{
		res[i]=decimal%2;
		decimal/=2;
		i++;
	}
	cout<<"BINARY FORM = ";
	for(int j=i-1;j>=0;j--)
	cout<<res[j];	
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct agent{
	
	
}data;

string raw_str_login[61][2];

void header()
{
	cout<<"+------------------------+"<<endl;
	cout<<"| T r a v e l  A g e n t |"<<endl;
	cout<<"|  Booking Hotel Tanpa   |"<<endl;
	cout<<"|         Ribet          |"<<endl;
	cout<<"+------------------------+"<<endl;
}

void raw_login_data()
{
	ifstream log("Data/user.txt");
	ifstream log1("Data/pass.txt");
	for(int k=0;k<60;k++)
	{
		getline(log, raw_str_login[k][0]);
		getline(log1, raw_str_login[k][1]);
	}
	log.close();
	log1.close();
}

bool slogin(string username, string password)
{		
	int ctr=0;
	
	for(int i=0;i<60;i++)
	{
		if(username==raw_str_login[i][0] and password==raw_str_login[i][1])
		{
			return true;
			ctr+=1;
		}
	}
	
	if(ctr==0)
	{
		return false;
	}
}

void menu_utama(string user)
{
	cout<<"Username : "<<user<<".travel";
}

void login()
{
	string a,b;
	cout<<"User : ";cin>>a;
	cout<<"Pass : ";cin>>b;
	
	if(slogin(a,b)==true)
	{
		menu_utama(a);
	}else{
		cout<<"Login gagal";
	}
}

void menu()
{
	header();
	cout<<"| 1. Login - 2. Register |"<<endl;
	cout<<"+------------------------+"<<endl;
}

int main()
{
	menu();
	raw_login_data();
	
}

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int pilihan;

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

void menu();

void logout()
{
	system("cls");
	menu();
}

void ordermenu(int pil)
{
	switch(pil)
	{
		
	}
}

void dashboard(string usr)
{
	system("cls");
	cout<<"+------------------------+"<<endl;
	cout<<"  Username : "<<usr<<".travel"<<endl;
	header();
	cout<<"| 1. Hotel - 2. Flight   |"<<endl;
	cout<<"| 3. Logout              |"<<endl;
	cout<<"+------------------------+"<<endl;
	cout<<"  Pilihan : ";cin>>pilihan;
	ordermenu(pilihan);
}

void menu_utama(string user)
{
	pilihan=3;
	while(true)
	{
		dashboard(user);
		if(pilihan==3) break;
	}
}

void login()
{
	string a,b;
	cout<<"  User : ";cin>>a;
	cout<<"  Pass : ";cin>>b;
	
	if(slogin(a,b)==true)
	{
		system("cls");
		menu_utama(a);
	}else{
		cout<<"  Login gagal"<<endl<<"  ";
		system("pause");
		system("cls");
	}
}

void regist()
{
	string a,b;
	ofstream log("Data/user.txt", ios::app);
	ofstream log1("Data/pass.txt", ios::app);
	
	a:
	cout<<"  Username : ";cin>>a;
	cout<<"  Password : ";cin>>b;
	
	for(int i=0;i<60;i++)
	{
		if(a==raw_str_login[i][0])
		{
			cout<<"Data Sudah ada "<<endl;
			system("cls");
			goto a;
		}
	}
	
	log << endl << a;
	log1 << endl << b;
	
	log.close();
	log1.close();
}

void order(int pil)
{
	switch(pil)
	{
		case 1: login();break;
		case 2: regist();break;
	}
}

void menu()
{
	header();
	cout<<"| 1. Login - 2. Register |"<<endl;
	cout<<"| 3. Exit                |"<<endl;
	cout<<"+------------------------+"<<endl;
	cout<<"  Pilihan : ";cin>>pilihan;
	order(pilihan);
}

int main()
{
	while(true)
	{
		raw_login_data();
		menu();
		if(pilihan==3) break;
	}
	
}

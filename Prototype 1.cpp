#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ctr=0;

struct perpustakaan
{
	int id;
	string nim, nama, judul;
}peminjaman[11];

string nim, nama, judul;

int raw_int[10];
string raw_str[61];

void input()
{
	ofstream on("perpustakaan.txt", ios::app);
	
	int batas;
	cout<<"Masukan Batas : ";
	cin>>batas;
	
	for(int i=0;i<batas;i++)
	{
		cout<<"NIM  : ";cin>>nim;
		on<<"1"<<endl;
		on<<nim<<endl;
		cout<<"Nama : ";cin>>nama;
		on<<"2"<<endl;
		on<<nama<<endl;
		cout<<"Judul : ";cin>>judul;
		on<<"3"<<endl;
		on<<judul<<endl;
	}
	
	on.close();
}

void raw_data()
{
	ifstream in("perpustakaan.txt");
	
	for(int k=0;k<60;k++)
	{
		getline(in, raw_str[k]);
	}
	
	for(int k=0;k<60;k=k+6)
	{			
		for(int j=k;j<k+6;j++)			
		{
			if(raw_str[j]=="1")
			{
				peminjaman[ctr].nim = raw_str[j+1];
			}
			if(raw_str[j]=="2")
			{
				peminjaman[ctr].nama = raw_str[j+1];
			}
			if(raw_str[j]=="3")
			{
				peminjaman[ctr].judul = raw_str[j+1];
			}
		}
		ctr = ctr+1;
	}
	
	in.close();
	ctr=0;
}

void output()
{
	raw_data();
	
	for(int i=0;i<10;i++)
	{
		if(peminjaman[i].nim != "")
		{
		cout<<"Nim : "<<peminjaman[i].nim<<endl;
		cout<<"Nama : "<<peminjaman[i].nama<<endl;
		cout<<"Judul : "<<peminjaman[i].judul<<endl<<endl;
		}
	}
}

void cari()
{
	cout<<"";
}

void tulis_raw()
{
	ofstream tmp("tmp.txt");
	
	for(int i=0;i<10;i++)
	{
		if(peminjaman[i].nim!="")
		{
			tmp<<"1"<<endl;
			tmp<<peminjaman[i].nim<<endl;
			tmp<<"2"<<endl;
			tmp<<peminjaman[i].nama<<endl;
			tmp<<"3"<<endl;
			tmp<<peminjaman[i].judul<<endl;
		}
	}
	tmp.close();
}

void dlt()
{
	raw_data();
	cout<<"masukan nim : ";cin>>nim;
	for(int i=0;i<10;i++)
	{
		if(peminjaman[i].nim == nim)
		{
			for(int j=i;j<10-i;j++)
			{
				if(peminjaman[j].nim != "")
				{
					peminjaman[j].nim = peminjaman[j+1].nim;
					peminjaman[j].nama = peminjaman[j+1].nama;
					peminjaman[j].judul = peminjaman[j+1].judul;
				}else break;
			}
		}
	}
	
	tulis_raw();
	
	remove("perpustakaan.txt");
	rename("tmp.txt", "perpustakaan.txt");
}

void menu()
{
	cout<<"1. Input data"<<endl;
	cout<<"2. Lihat data"<<endl;
	cout<<"3. Urutkan data"<<endl;
	cout<<"4. Cari data"<<endl;
}

int pilih;

void pl()
{
	switch (pilih)
	{
		case 1: input();break;
		case 2: output();break;
		case 4: dlt();break;
		default: cout<<"Input Salah";break;
	}
}

int main()
{
	a:
	menu();
	cout<<"Pilihan : ";cin>>pilih;
	pl();
	goto a;
}

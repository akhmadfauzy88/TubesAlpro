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
	system("cls");
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

void hotel()
{
	string kota,tamu,bulan;
	int cekin,cekot,pilhot,bayar;
	
	cout<<"====================================="<<endl;
	cout<<"Selamat Datang di Paket Booking Hotel"<<endl;
	cout<<"====================================="<<endl;
	cout<<endl;
	cout<<"Masukkan Kota Tempat Anda Menginap :";cin>>kota;
	cout<<"....................................."<<endl;
	cout<<"1. Nusa Indah "<<kota<<"       Rp.1.000.000/nett"<<endl;
	cout<<"2. Wisma Nyaman "<<kota<<"     Rp.1.500.000/nett"<<endl;
	cout<<endl;
	cout<<"...................................."<<endl;
	cout<<"Masukkan pilihan anda : ";cin>>pilhot;
	if (pilhot==1)
	{
		cout<<"Booking Nusa Indah "<<kota<<endl;
		cout<<"Masukkan Nama Tamu : ";cin>>tamu;
		cout<<"Masukkan Tanggal Check In Hotel : ";cin>>cekin;
		cout<<"Masukkan Tanggal Check Out Hotel : ";cin>>cekot;
		cout<<"Masukkan Bulan Check In : ";cin>>bulan;
		cout<<"================================================"<<endl;
		cout<<"Total Biaya Anda (diluar pajak) : Rp. "<<((cekot-cekin)*1000000)+50000<<endl;
		cout<<"Masukkan Nominal yang ingin anda bayar = Rp. ";cin>>bayar;
		if (bayar==((cekot-cekin)*1000000)+50000)
		{
			cout<<"Pesanan anda akan segera kami proses . Silahkan Tunggu !"<<endl;
		}
		if (bayar>((cekot-cekin)*1000000)+50000)
		{
			cout<<"Cashback Sebesar Rp. "<<bayar-((cekot-cekin)*1000000)+50000 <<" dikembalikan ke rekeing anda"<<endl;
		}
	}
	if (pilhot==2)
	{
		cout<<"Booking Wisma Nyaman "<<kota<<endl;
		cout<<"Masukkan Nama Tamu : ";cin>>tamu;
		cout<<"Masukkan Tanggal Check In Hotel : ";cin>>cekin;
		cout<<"Masukkan Tanggal Check Out Hotel : ";cin>>cekot;
		cout<<"Masukkan Bulan Check In : ";cin>>bulan;
		cout<<"================================================"<<endl;
		cout<<"Total Biaya Anda (termasuk pajak) : Rp. "<<((cekot-cekin)*1500000)+50000<<endl;
		cout<<"Masukkan Nominal yang ingin anda bayar = Rp. ";cin>>bayar;
		
		int apem=((cekot-cekin)*1500000)+50000;
		if (bayar==apem)
		{
			cout<<"Pesanan anda akan segera kami proses . Silahkan Tunggu !"<<endl;
		}
		if (bayar>apem)
		{
			cout<<"Cashback Sebesar Rp. "<<bayar-((cekot-cekin)*1500000)+50000 <<" dikembalikan ke rekeing anda"<<endl;
		}
	}
	system("pause");
}

void flight()
{
	string asal, tujuan,nama;
	int pil,a,b;
	int pax,tgl1,bul;
	cout<<"==========================================="<<endl;
	cout<<"Selamat datang di Paket Booking Penerbangan"<<endl;
	cout<<"==========================================="<<endl;
	cout<<endl;
	cout<<"Masukkan Kota Asal: ";cin>>asal;cout<<endl;
	cout<<"Masukkan Kota Tujuan: ";cin>>tujuan;
	cout<<"--------------------------------------------------------------------------";cout<<endl;
	cout<<"1. "<<asal<<"-"<<tujuan<<" LA211QZ "<<" 00.30 WIB-03.30WIB "<<" Rp.450.000"<<endl;
	cout<<"2. "<<asal<<"-"<<tujuan<<" GIA2312 "<<" 14.30 WIB-17.30WIB "<<" Rp.1.250.000"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<endl;
	cout<<"Masukkan pilihan anda : ";cin>>pil;
	cout<<"Pax (maksimal 2 penumpang dalam sekali pembelian): ";cin>>pax;
	
	if(pax==1)
	{
		cout<<"Nama Penumpang : ";cin>>nama;
		cout<<"Tanggal Keberangkatan : ";cin>>tgl1;
		cout<<"Bulan Keberangkatan : ";cin>>bul;
		cout<<endl;
		cout<<"================================"<<endl;
	
		if(pil==1)
		{
			a=450000;
			b=a*pax;
			cout<<endl;
			cout<<nama<<endl;
			cout<<"Melakukan Pemesanan pada Tanggal : "<<tgl1<<" "<<bul<<endl;
			cout<<"Melakukan Pemesanan sebanyak : "<<pax<<" kursi"<<endl;
			cout<<"Total Pembayaran : Rp. "<<b<<endl;
		}
		if(pil==2)
		{
			a=1250000;
			b=a*pax;
			cout<<nama<<endl;
			cout<<"Melakukan Pemesanan pada Tanggal : "<<tgl1<<endl;
			cout<<"Melakukan Pemesanan sebanyak : "<<pax<<" kursi"<<endl;
			cout<<"Total Pembayaran : Rp. "<<b<<endl;
		}	
	}
	if(pax==2)
	{
		cout<<"Nama Penumpang : ";cin>>nama;
		cout<<"Tanggal Keberangkatan : ";cin>>tgl1;
		cout<<"Bulan Keberangkatan : ";cin>>bul;
		cout<<endl;
		cout<<"================================";
	
		if(pil==1)
		{
			a=450000;
			b=a*pax;
			cout<<endl;
			cout<<nama<<endl;
			cout<<"Melakukan Pemesanan pada Tanggal : "<<tgl1<<" "<<bul<<endl;
			cout<<"Melakukan Pemesanan sebanyak : "<<pax<<" kursi"<<endl;
			cout<<"Total Pembayaran : Rp. "<<b<<endl;
		}
		if(pil==2)
		{
			a=1250000;
			b=a*pax;
			cout<<nama<<endl;
			cout<<"Melakukan Pemesanan pada Tanggal : "<<tgl1<<endl;
			cout<<"Melakukan Pemesanan sebanyak : "<<pax<<" kursi"<<endl;
			cout<<"Total Pembayaran : Rp. "<<b<<endl;
		}	
	}
	system("pause");
}

void ordermenu(int pil)
{
	switch(pil)
	{
		case 1: hotel();break;
		case 2: flight();break;
	}
}

void dashboard(string usr)
{
	system("cls");
	cout<<"+------------------------+"<<endl;
	cout<<"  Username : "<<usr<<".travel"<<endl;
	header();
	cout<<"| 1. Hotel - 2. Flight   |"<<endl;
	cout<<"| 3. Exit                |"<<endl;
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
			cout<<"  Data Sudah ada "<<endl;
			system("pause");
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

#include <iostream> // Base C++
#include <string> // Getline
#include <fstream> // File Operation
#include <cstdio> // Base C
#include <sstream> // Convert String to Int
#include <string.h> // Strcpy
#include <windows.h> // Color

using namespace std;

int pilihan;

struct agent
{
	string hotel[300][2];
	string flight[300][3];
}data;

struct agent2
{
	string resi_hotel[300][7];
}resi;

string raw_str_login[61][2];

void asc()
{
	
}

void desc()
{
	
}

void sec()
{
	
}

void bin()
{
	
}

void sorting()
{
	cout<<"Sorting Berdasarkan : ";
	cout<<"1. Ascending"<<endl;
	cout<<"2. Descending"<<endl;
	cout<<"Pilihan : ";cin>>pilihan;
	switch(pilihan)
	{
		case 1: asc(); break;
		case 2: desc(); break;
	}
}

void searching()
{
	
}

void header()
{
	//system("cls");
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

void data_hotel()
{
	ifstream hot("Data/Hotel/wilayah.txt");
	ifstream hot1("Data/Hotel/harga.txt");
	for(int k=0;k<60;k++)
	{
		getline(hot, data.hotel[k][0]);
		getline(hot1, data.hotel[k][1]);
	}
	hot.close();
	hot1.close();
}

void resi_h(string nama, string bulan, int ckn, int cko, int tot, string usr, string kota)
{
	string resi1 = "Data/Hotel/Log/"+usr+"-nama.log";
	string resi2 = "Data/Hotel/Log/"+usr+"-ckn.log";
	string resi3 = "Data/Hotel/Log/"+usr+"-cko.log";
	string resi4 = "Data/Hotel/Log/"+usr+"-lama.log";
	string resi5 = "Data/Hotel/Log/"+usr+"-total.log";
	string resi6 = "Data/Hotel/Log/"+usr+"-kota.log";
	
	char nm[100], ck[100], co[100], lm[100], ttl[100], kt[100];
	
	strcpy(nm, resi1.c_str());
	strcpy(ck, resi2.c_str());
	strcpy(co, resi3.c_str());
	strcpy(lm, resi4.c_str());
	strcpy(ttl, resi5.c_str());
	strcpy(kt, resi6.c_str());
	
	ofstream tm(nm, ios::app);
	ofstream tm1(ck, ios::app);
	ofstream tm2(co, ios::app);
	ofstream tm3(lm, ios::app);
	ofstream tm4(ttl, ios::app);
	ofstream tm5(kt, ios::app);
	
	tm<<nama<<endl;
	tm1<<ckn<<endl;
	tm2<<cko<<endl;
	tm3<<cko-ckn<<endl;
	tm4<<tot<<endl;
	tm5<<kota<<endl;
	
	tm.close();
	tm1.close();
	tm2.close();
	tm3.close();
	tm4.close();
	tm5.close();
}

void riwayat_h(string usr)
{
	string resi1 = "Data/Hotel/Log/"+usr+"-nama.log";
	string resi2 = "Data/Hotel/Log/"+usr+"-ckn.log";
	string resi3 = "Data/Hotel/Log/"+usr+"-cko.log";
	string resi4 = "Data/Hotel/Log/"+usr+"-lama.log";
	string resi5 = "Data/Hotel/Log/"+usr+"-total.log";
	string resi6 = "Data/Hotel/Log/"+usr+"-kota.log";
	
	char nm[100], ck[100], co[100], lm[100], ttl[100], kt[100];
	
	strcpy(nm, resi1.c_str());
	strcpy(ck, resi2.c_str());
	strcpy(co, resi3.c_str());
	strcpy(lm, resi4.c_str());
	strcpy(ttl, resi5.c_str());
	strcpy(kt, resi6.c_str());
	
	ifstream tm(nm);
	ifstream tm1(ck);
	ifstream tm2(co);
	ifstream tm3(lm);
	ifstream tm4(ttl);
	ifstream tm5(kt);
	
	if(tm==NULL)
	{
		cout<<"Tidak ada data tranksasi"<<endl;
		system("pause");
		return;
	}
	
	for(int i=1; i<=299; i++)
	{
		getline(tm, resi.resi_hotel[i][0]);
		getline(tm1, resi.resi_hotel[i][1]);
		getline(tm2, resi.resi_hotel[i][2]);
		getline(tm3, resi.resi_hotel[i][3]);
		getline(tm4, resi.resi_hotel[i][4]);
		getline(tm5, resi.resi_hotel[i][5]);
	}
	
	tm.close();
	tm1.close();
	tm2.close();
	tm3.close();
	tm4.close();
	tm5.close();
	
	int ctr=0;
	
	for(int i=1;i<=299;i++)
	{
		if(resi.resi_hotel[i][0] != "")
		{
			cout<<"Nama Tamu         : "<<resi.resi_hotel[i][0]<<endl;
			cout<<"Tanggal Check In  : "<<resi.resi_hotel[i][1]<<endl;
			cout<<"Tanggal Check Out : "<<resi.resi_hotel[i][2]<<endl;
			cout<<"Lama menginap     : "<<resi.resi_hotel[i][3]<<" Hari"<<endl;
			cout<<"Total Biaya       : Rp."<<resi.resi_hotel[i][4]<<endl;
			cout<<"Lokasi Hotel      : "<<resi.resi_hotel[i][5]<<endl<<endl;
			ctr=+1;
		}
	}
		
	system("pause");
}

void riwayat (string usr)
{
	cout<<"Riwayat Tranksasi"<<endl;
	cout<<"1. Hotel "<<endl<<"2. Flight"<<endl;
	cout<<"Pilihan : ";cin>>pilihan;
	switch(pilihan)
	{
		case 1: riwayat_h(usr);break;
	}
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

void hotel(string usr)
{
	data_hotel();
	string kota,tamu,bulan;
	int cekin,cekot,pilhot,bayar, indah, nyaman,apem;
	
	cout<<"====================================="<<endl;
	cout<<"Selamat Datang di Paket Booking Hotel"<<endl;
	cout<<"====================================="<<endl;
	cout<<endl;
	cout<<"Masukkan Kota Tempat Anda Menginap :";cin>>kota;
	
	for(int i=0;i<60;i++)
	{
		if(kota==data.hotel[i][0])
		{
			cout<<"....................................."<<endl;
			cout<<"1. Nusa Indah "<<kota<<"       Rp."<<data.hotel[i][1]<<endl;
			cout<<"2. Wisma Nyaman "<<kota<<"     Rp."<<data.hotel[i+1][1]<<endl;
			cout<<endl;
			cout<<"...................................."<<endl;
			stringstream nusa(data.hotel[i][1]);
			stringstream wisma(data.hotel[i+1][1]);
			
			nusa>>indah;
			wisma>>nyaman;
			break;
		}
	}
	
	cout<<"Masukkan pilihan anda : ";cin>>pilhot;
	if (pilhot==1)
	{
		cout<<"Booking Nusa Indah "<<kota<<endl;
		cout<<"Masukkan Nama Tamu : ";cin>>tamu;
		cout<<"Masukkan Tanggal Check In Hotel : ";cin>>cekin;
		cout<<"Masukkan Tanggal Check Out Hotel : ";cin>>cekot;
		cout<<"Masukkan Bulan Check In : ";cin>>bulan;
		cout<<"================================================"<<endl;
		cout<<"Total Biaya Anda (termasuk pajak) : Rp. "<<((cekot-cekin)*indah)+50000<<endl;
		cout<<"Masukkan Nominal yang ingin anda bayar = Rp. ";cin>>bayar;
		
		apem=((cekot-cekin)*indah)+50000;
		if (bayar==((cekot-cekin)*indah)+50000)
		{
			cout<<"Pesanan anda akan segera kami proses . Silahkan Tunggu !"<<endl;
		}
		if (bayar>((cekot-cekin)*indah)+50000)
		{
			cout<<"Cashback Sebesar Rp. "<<bayar-(((cekot-cekin)*indah)+50000) <<" dikembalikan ke rekeing anda"<<endl;
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
		cout<<"Total Biaya Anda (termasuk pajak) : Rp. "<<((cekot-cekin)*nyaman)+50000<<endl;
		cout<<"Masukkan Nominal yang ingin anda bayar = Rp. ";cin>>bayar;
		
		apem=((cekot-cekin)*nyaman)+50000;
		if (bayar==apem)
		{
			cout<<"Pesanan anda akan segera kami proses . Silahkan Tunggu !"<<endl;
		}
		if (bayar>apem)
		{
			cout<<"Cashback Sebesar Rp. "<<bayar-(((cekot-cekin)*nyaman)+50000) <<" dikembalikan ke rekeing anda"<<endl;
		}
	}
	cout<<endl;
	cout<<"================================================"<<endl;
	cout<<"Resi Anda"<<endl;
	cout<<"================================================"<<endl;
	cout<<"Nama Tamu     : "<<tamu<<endl;
	cout<<"Kota          : "<<kota<<endl;
	cout<<"Check In      : "<<cekin<<" "<<bulan<<endl;
	cout<<"Check Out     : "<<cekot<<" "<<bulan<<endl;
	cout<<"Lama Menginap : "<<cekot-cekin<<" hari"<<endl;
	cout<<"Total Biaya   : "<<"Rp."<<apem<<endl;
	cout<<"Pembayaran    : "<<"Debet"<<endl;
	resi_h(tamu, bulan, cekin, cekot, apem, usr, kota);
	cout<<"================================================"<<endl;
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

void ordermenu(int pil, string usr)
{
	switch(pil)
	{
		case 1: hotel(usr);break;
		case 2: flight();break;
		case 3: riwayat(usr);break;
	}
}

void dashboard(string usr)
{
	system("cls");
	cout<<"+------------------------+"<<endl;
	cout<<"  Username : "<<usr<<".travel"<<endl;
	header();
	cout<<"| 1. Hotel   2. Flight   |"<<endl;
	cout<<"| 3. Riwayat 4. Logout   |"<<endl;
	cout<<"+------------------------+"<<endl;
	cout<<"  Pilihan : ";cin>>pilihan;
	ordermenu(pilihan, usr);
}

void menu_utama(string user)
{
	while(true)
	{
		dashboard(user);
		if(pilihan==4) break;
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
			cout<<"  Username telah terdaftar "<<endl;
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
	a:
	header();
	cout<<"| 1. Login - 2. Register |"<<endl;
	cout<<"| 3. Exit                |"<<endl;
	cout<<"+------------------------+"<<endl;
	cout<<"  Pilihan : ";cin>>pilihan;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"Masukan salah !!"<<endl;
		system("pause");
		system("cls");
		goto a;
	}
	
	order(pilihan);
}

int main()
{
	system("Title Travel Agent v2 By Kelompok 1");
	while(true)
	{
		system("cls");
		raw_login_data();
		menu();
		if(pilihan==3) break;
	}
	
}


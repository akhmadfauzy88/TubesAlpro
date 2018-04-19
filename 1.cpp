#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

struct login
{
	string log_data[100][2];
}log;

struct hotel
{
	string wilayah[100][2];
	int harga[100];
}data_h;

struct flight
{
	string wilayah[100][3];
	string waktu[100][3];
	int harga[100];
}data_f;

// Flight

void sort_f()
{
	string tmp;
	int temp;
	for(int i=0;i<=6;i++)
	{
		int k = i;
		while((k>0) and (data_f.wilayah[k][0]<data_f.wilayah[k-1][0]))
		{
			tmp = data_f.wilayah[k][0];
			data_f.wilayah[k][0] = data_f.wilayah[k-1][0];
			data_f.wilayah[k-1][0] = tmp;
			
			tmp = data_f.wilayah[k][1];
			data_f.wilayah[k][1] = data_f.wilayah[k-1][1];
			data_f.wilayah[k-1][1] = tmp;
			
			tmp = data_f.waktu[k][0];
			data_f.waktu[k][0] = data_f.waktu[k-1][0];
			data_f.waktu[k-1][0] = tmp;
			
			tmp = data_f.waktu[k][1];
			data_f.waktu[k][1] = data_f.waktu[k-1][1];
			data_f.waktu[k-1][1] = tmp;
			
			temp = data_f.harga[k];
			data_f.harga[k] = data_f.harga[k-1];
			data_f.harga[k-1] = temp;
			
			k = k-1;
		}
	}
}

void data_flight()
{
	ifstream asal("Data/Flight/asal.txt");
	ifstream tujuan("Data/Flight/tujuan.txt");
	ifstream waktu_berangkat("Data/Flight/waktu_berangkat.txt");
	ifstream waktu_sampai("Data/Flight/waktu_sampai.txt");
	ifstream harga("Data/Flight/harga.txt");
	
	for(int k=1;k<100;k++)
	{
		getline(asal, data_f.wilayah[k][0]);
		getline(tujuan, data_f.wilayah[k][1]);
		getline(waktu_berangkat, data_f.waktu[k][0]);
		getline(waktu_sampai, data_f.waktu[k][1]);
		getline(harga, data_f.wilayah[k][2]);
	}
	
	for(int i=1;i<100;i++)
	{
		stringstream price(data_f.wilayah[i][2]);
		price>>data_f.harga[i];
	}
	
	harga.close();
	asal.close();
	tujuan.close();
	waktu_berangkat.close();
	waktu_sampai.close();
}

void list_f()
{
	a:
	int pilihan;
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Daftar Penerbangan yang tersedia      |"<<endl;
	cout<<"+======================================+"<<endl;
	
	for(int i=1;i<100;i=i+2)
	{
		if(data_f.wilayah[i][0]!="" and data_f.wilayah[i][1]!="")
		{
			cout<<i<<". "<<data_f.wilayah[i][0]<<" - "<<data_f.wilayah[i][1]<<" LA211QZ "<<data_f.waktu[i][0]<<" WIB - "<<data_f.waktu[i][1]<<" WIB "<<"Rp."<<data_f.harga[i]<<endl;
			cout<<i+1<<". "<<data_f.wilayah[i+1][0]<<" - "<<data_f.wilayah[i+1][1]<<" GIA2312 "<<data_f.waktu[i+1][0]<<" WIB - "<<data_f.waktu[i+1][1]<<" WIB "<<"Rp."<<data_f.harga[i+1]<<endl;
		}
	}
	cout<<"+======================================+"<<endl;
	cout<<"|1. Urutkan Berdasarkan asal           |"<<endl;
	cout<<"|2. Kembali                            |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"Pilihan : ";cin>>pilihan;
	
	switch(pilihan)
	{
		case 1 : sort_f();goto a;break;
		case 2 : return;break;
		default : cout<<"Masukan Salah !!";getch();system("cls");break;
	}
}

void cari_f()
{
	string asal, tujuan;
	
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Menu pemesanan tiket                  |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"Masukan kota asal   : ";cin>>asal;
	cout<<"Masukan kota tujuan : ";cin>>tujuan;
	
	for(int i=1;i<100;i++)
	{
		if(asal == data_f.wilayah[i][0] and tujuan == data_f.wilayah[i][1])
		{
			cout<<i<<". "<<data_f.wilayah[i][0]<<" - "<<data_f.wilayah[i][1]<<" LA211QZ "<<data_f.waktu[i][0]<<" WIB - "<<data_f.waktu[i][1]<<" WIB "<<"Rp."<<data_f.harga[i]<<endl;
			cout<<i+1<<". "<<data_f.wilayah[i+1][0]<<" - "<<data_f.wilayah[i+1][1]<<" GIA2312 "<<data_f.waktu[i+1][0]<<" WIB - "<<data_f.waktu[i+1][1]<<" WIB "<<"Rp."<<data_f.harga[i+1]<<endl;
		}
	}
	
	system("pause");
}

void flight()
{
	int pilihan;
	data_flight();
	
	a:
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Selamat datang di Menu Flight         |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"|1. Lihat semua Penerbangan yang       |"<<endl;
	cout<<"|   tersedia                           |"<<endl;
	cout<<"|2. Pesan tiket pesawat                |"<<endl;
	cout<<"|3. Kembali                            |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"Pilihan : ";cin>>pilihan;
	
	switch(pilihan)
	{
		case 1 : list_f();break;
		case 2 : cari_f();break;
		case 3 : return;break;
		default : cout<<"Masukan Salah !!";getch();system("cls");break;
	}
	goto a;
}

// End Flight

// Hotel

void sort_h()
{
	string tmp;
	int temp;
	
	for (int i=1;i<58;i++)
	{
		for (int k=58;k>=1+i;k--)
		{
			if (data_h.wilayah[k][0] < data_h.wilayah[k-1][0])
			{
				tmp=data_h.wilayah[k][0];
				data_h.wilayah[k][0]=data_h.wilayah[k-1][0];
				data_h.wilayah[k-1][0]=tmp;
				
				temp=data_h.harga[k];
				data_h.harga[k] = data_h.harga[k-1];
				data_h.harga[k-1] = temp;
			}
		}
	}
}

void data_hotel()
{
	ifstream wilayah("Data/Hotel/wilayah.txt");
	ifstream harga("Data/Hotel/harga.txt");
	
	for(int k=1;k<100;k++)
	{
		getline(wilayah, data_h.wilayah[k][0]);
		getline(harga, data_h.wilayah[k][1]);
	}
	
	for(int i=1;i<100;i++)
	{
		stringstream price(data_h.wilayah[i][1]);
		price>>data_h.harga[i];
	}
	
	harga.close();
	wilayah.close();
}

void list_h()
{
	a:
	int pilihan;
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Daftar Hotel yang tersedia            |"<<endl;
	cout<<"+======================================+"<<endl;
	
	for(int i=1;i<100;i=i+2)
	{
		if(data_h.wilayah[i][0]!="")
		{
			cout<<i<<". Nusa Indah kota   "<<data_h.wilayah[i][0]<<"        "<<"Rp."<<data_h.harga[i]<<endl;
			cout<<i+1<<". Wisma Nyaman kota "<<data_h.wilayah[i+1][0]<<"        "<<"Rp."<<data_h.harga[i+1]<<endl;
		}
	}
	cout<<"+======================================+"<<endl;
	cout<<"|1. Urutkan Berdasarkan Kota           |"<<endl;
	cout<<"|2. Kembali                            |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"Pilihan : ";cin>>pilihan;
	
	switch(pilihan)
	{
		case 1 : sort_h();goto a;break;
		case 2 : return;break;
		default : cout<<"Masukan Salah !!";getch();system("cls");break;
	}
}

void pay(int &total, int cekin, int cekot, int harga)
{
	total = ((cekot-cekin) * harga)+50000;
}

void cari_h()
{
	string kota, bulan, tamu;
	int cekin, cekot;
	
	int total, bayar;
	
	a:
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Silahkan masukan kota                 |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"Kota : ";cin>>kota;
	
	sort_h();
	
	int awal=1, akhir=58, tengah=(awal+akhir)/2;
	while (awal <= akhir)
	{
		if(data_h.wilayah[tengah][0] < kota)
		{
			awal = tengah + 1;

		}
		else if(data_h.wilayah[tengah][0] == kota)
		{
			cout<<"........................................."<<endl;
			cout<<"1. Nusa Indah "<<kota<<"       Rp."<<data_h.harga[tengah]<<endl;
			cout<<"2. Wisma Nyaman "<<kota<<"     Rp."<<data_h.harga[tengah+1]<<endl;
			cout<<endl;
			cout<<"........................................."<<endl;
			break;
		}
		else
		{
			 akhir = tengah - 1;
		}
		tengah = (awal + akhir)/2;
	}
	
	if(awal>akhir)
	{
		cout<<"Maaf, belum ada hotel terdaftar di kota yang anda tuju";getch();
		goto a;
	}
	
	int pilhot;
	cout<<"Masukkan pilihan anda : ";cin>>pilhot;
	
	if(pilhot==1)
	{
		cout<<"================================================"<<endl;
		cout<<"Booking Nusa Indah "<<kota<<endl;
		cout<<"Masukkan Nama Tamu : ";cin>>tamu;
		cout<<"Masukkan Tanggal Check In Hotel : ";cin>>cekin;
		cout<<"Masukkan Tanggal Check Out Hotel : ";cin>>cekot;
		cout<<"Masukkan Bulan Check In : ";cin>>bulan;
		cout<<"================================================"<<endl;
		
		pay(total,cekin,cekot,data_h.harga[tengah]);
		cout<<"Total Pembayaran : Rp."<<total<<endl;
		cout<<"Masukkan Nominal yang ingin anda bayar = Rp. ";cin>>bayar;
		
		if (bayar==total)
		{
			cout<<"Pesanan anda akan segera kami proses . Silahkan Tunggu !"<<endl;
		}
		if (bayar>total)
		{
			cout<<"Cashback Sebesar Rp. "<<bayar-total <<" dikembalikan ke rekeing anda"<<endl;
		}
	}
	else if(pilhot==2)
	{
		cout<<"================================================"<<endl;
		cout<<"Booking Wisma Nyaman "<<kota<<endl;
		cout<<"Masukkan Nama Tamu : ";cin>>tamu;
		cout<<"Masukkan Tanggal Check In Hotel : ";cin>>cekin;
		cout<<"Masukkan Tanggal Check Out Hotel : ";cin>>cekot;
		cout<<"Masukkan Bulan Check In : ";cin>>bulan;
		cout<<"================================================"<<endl;
		
		pay(total,cekin,cekot,data_h.harga[tengah+1]);
		cout<<"Total Pembayaran : Rp."<<total<<endl;
		cout<<"Masukkan Nominal yang ingin anda bayar = Rp. ";cin>>bayar;
		
		if (bayar==total)
		{
			cout<<"Pesanan anda akan segera kami proses . Silahkan Tunggu !"<<endl;
		}
		if (bayar>total)
		{
			cout<<"Cashback Sebesar Rp. "<<bayar-total <<" dikembalikan ke rekeing anda"<<endl;
		}
	}
	
	getch();
}

void hotel()
{
	int pilihan;
	data_hotel();
	
	a:
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Selamat datang di Menu Hotel          |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"|1. Lihat semua Hotel yang tersedia    |"<<endl;
	cout<<"|2. Check In Hotel                     |"<<endl;
	cout<<"|3. Kembali                            |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"Pilihan : ";cin>>pilihan;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"Masukan salah !!";
		getch();
		system("cls");
		goto a;
	}
		
	switch(pilihan)
	{
		case 1 : list_h();break;
		case 2 : cari_h();break;
		case 3 : return;break;
		default : cout<<"Masukan Salah !!";getch();system("cls");break;
	}
	goto a;
}

// End Hotel



// Statement Main Menu

void main_order(int pilihan)
{
	switch(pilihan)
	{
		case 1 : hotel();break;
		case 2 : flight();break;
		case 3 : break;
		default : cout<<"Masukan Salah !!";getch();system("cls");break;
	}
}

void main_menu(string username)
{
	int pilihan;
	a:
		system("cls");
		cout<<"+======================================+"<<endl;
		cout<<" Hello "<<username<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"|Main Menu Travel Agent                |"<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"|1. Hotel - 2. Flight - 3. Riwayat     |"<<endl;
		cout<<"|4. Logout                             |"<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"Pilihan : ";cin>>pilihan;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"Masukan salah !!";
			getch();
			system("cls");
			goto a;
		}
		
		if(pilihan==4) return;
		
		main_order(pilihan);
	goto a;
}

// End Statment Main Menu

// Baris Statement Login

void transfer_data_login()
{
	ifstream user("Data/Login/user.txt");
	ifstream pass("Data/Login/pass.txt");
	
	for(int k=1;k<100;k++)
	{
		getline(user, log.log_data[k][0]);
		getline(pass, log.log_data[k][1]);
	}
	
	user.close();
	pass.close();
}

bool check_login(string username, string password)
{	
	transfer_data_login();
	int ctr=0;
	
	for(int i=1;i<100;i++)
	{
		if(username==log.log_data[i][0] and password==log.log_data[i][1])
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

void login()
{
	string username, password;
	
	system("cls");
	cout<<"+======================================+"<<endl;
	cout<<"|Masukan Username dan Password Anda    |"<<endl;
	cout<<"+======================================+"<<endl;
	a:
	cout<<"Username : ";cin>>username;
	cout<<"Password : ";cin>>password;
	
	bool status = check_login(username, password);
	
	if(status==true)
	{
		main_menu(username);
	}
	else
	{
		cout<<"Username / Password salah !!"<<endl;getch();
		goto a;
	}
}

// End Baris Statement Login

// Register

void regist()
{
	string username, password;
	ofstream user("Data/Login/user.txt", ios::app);
	ofstream pass("Data/Login/pass.txt", ios::app);
	
	b:
		system("cls");
		cout<<"+======================================+"<<endl;
		cout<<"|Menu Registrasi                       |"<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"|Isikan Username dan Password untuk    |"<<endl;
		cout<<"|Mendaftar                             |"<<endl;
		cout<<"+======================================+"<<endl;
		cout<<"Username : ";cin>>username;
		cout<<"Password : ";cin>>password;
	
		for(int i=1;i<100;i++)
		{
			if(username==log.log_data[i][0])
			{
				cout<<"Username telah terdaftar "<<endl;
				getch();
				cout<<"+======================================+"<<endl;
				goto b;
			}
		}
	
	user << endl << username;
	pass << endl << password;
	
	user.close();
	pass.close();
}

//End Register

void header()
{
	cout<<"+======================================+"<<endl;
	cout<<"|Travel Agent v2 By Kelompok 1 Alpro   |"<<endl;
	cout<<"+======================================+"<<endl;
}

void menu()
{
	cout<<"+======================================+"<<endl;
	cout<<"|Silahkan Login / Register             |"<<endl;
	cout<<"+======================================+"<<endl;
	cout<<"|1. Login - 2. Register - 3. Exit      |"<<endl;
	cout<<"+======================================+"<<endl;
}

void order(int pilihan)
{
	switch(pilihan)
	{
		case 1 : login();break;
		case 2 : regist();break;
		default : cout<<"Masukan Salah !!";getch();system("cls");break;
	}
}

int main()
{
	system("Title Travel Agent v2 By Kelompok 1");
	system("Color 17");
	
	transfer_data_login();
	
	int pilihan;
	
	a:
		system("cls");
		header();
		menu();
		cout<<"Pilihan : ";cin>>pilihan;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"Masukan salah !!";
			getch();
			system("cls");
			goto a;
		}
		
		if(pilihan==3) return 0;
		
		order(pilihan);
	goto a;
}

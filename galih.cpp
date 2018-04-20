#include <iostream>
#include <string.h>

using namespace std;

struct xxx{
	char data[100];// = "Aqua Gelas";
}datax[10];

int main()
{
	datax[1].data = "Aqua Gelas";
	datax[2].data = "Liquor AP";
	
	char cari[100];
	
	cout<<"Cari data : ";cin.getline(cari,100);
	int sz = strlen(cari);
	
	int ctr, index;
	
	for(int k=1;k<10;k++)
	{
		ctr= 0;
		for(int i=0;i<sz;i++)
		{
			if(cari[i]==datax[k].data[i])
			{
				ctr++;
				index = k;
				break;
			}
		}
	}
	
	if(ctr==sz)
	{
		cout<<"Data ketemu";
		datax[index].data;
	}
	else
	{
		cout<<"Data Hilang";
	}
}

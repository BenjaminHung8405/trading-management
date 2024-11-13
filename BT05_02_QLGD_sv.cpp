#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class Date{
	protected:
		int day;
		int month;
		int year;
	public:
		Date();
		void setDay();
		int getDay();
		void setMonth();
		int getMonth();
		void setYear();
		int getYear();
};

class QLGD
{
	protected:
		char mgd[6];
		float thanhtien;
		Date date;
	public:
		QLGD();
		virtual void nhap();
		virtual void xuat();
		virtual void tinhTien()=0;
		bool checkNgayGD();
};

class GDVang : public QLGD
{
	protected:
		float soluong;
		float dongia;
		char loai[8];
	public:
		GDVang();
		void nhap();
		void xuat();
		void tinhTien();
};

class GDTTe : public QLGD
{
	protected:
		float sotien;
		float tygia;
		char loai[8];
	public:
		GDTTe();
		void nhap();
		void xuat();
		void tinhTien();
};

int main(){
	QLGD *GD[100];
	int i=0,n=0;
	char Chon,Loai;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Nhap thong tin cho cac giao dich"<<endl;
	do
	{
		cout<<"\nGiao dich vang hay Giao dich tien te (V/T)? ";
		cin>>Loai;
		Loai=toupper(Loai);
		if (Loai=='V')
		{
			GD[n] = new GDVang();
			GD[n]->nhap();
		}

		else
		{
			GD[n] = new GDTTe();
			GD[n]->nhap();
		}
		n++; //tang len so luong sach
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((n==100)||(Chon=='K'))
			break;
	}
	while (1);
	
	cout<<"Danh sach cac giao dich\n";
	for(i=0; i<n; i++)
	{
		GD[i]->xuat();
	}

	cout<<"Danh sach cac giao dich tu ngay 10-20/9/2024\n";
	for(i=0; i<n; i++)
	{
		if(GD[i]->checkNgayGD()) GD[i]->xuat(); 
	}
	
	getch();
	return 1;
}


// HAM QUAN LY GIAO DICH
QLGD::QLGD()
{
	strcpy(mgd,"");
	Date();
	thanhtien=0;
}

void QLGD::nhap(){
	cin.ignore();
	cout<<"\nMa giao dich: ";
	gets(mgd);
	cout<<"Ngay giao dich: ";
	date.setDay();
	date.setMonth();
	date.setYear();
}

void QLGD::xuat(){
	cout<<"[MGD: "<<mgd<<", NgayGD: "<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear();
}

bool QLGD::checkNgayGD(){
	return (date.getDay()>=10 && date.getDay()<=20 && date.getMonth()==9 && date.getYear()==2024);
}


// HAM GIAO DICH VANG
GDVang::GDVang() : QLGD()
{
	soluong = 0;
	strcpy(loai,"");
}

void GDVang::nhap(){
	QLGD::nhap();
	cout<<"So luong: ";
	cin>>soluong;
	cin.ignore();
	cout<<"Loai vang: ";
	gets(loai);
	
	if(stricmp(loai,"SJC") == 0 || stricmp(loai,"PNJ") == 0) dongia=9000000;
	else dongia=8200000;
	
	tinhTien();
}

void GDVang::xuat(){
	QLGD::xuat();
	cout<<", SL: "<<soluong<<", Don gia: "<<dongia<<", Loai vang: "<<loai<<", Thanh tien: "<<thanhtien<<"]\n";
}

void GDVang::tinhTien(){
	thanhtien=soluong*dongia;
}


// HAM GIAO DICH TIEN TE
GDTTe::GDTTe() : QLGD()
{
	sotien = 0;
	strcpy(loai,"");
}

void GDTTe::nhap(){
	QLGD::nhap();
	cout<<"So tien(ngan): ";
	cin>>sotien;
	sotien*=1000;
	cin.ignore();
	do{
		cout<<"Loai tien te (VND/USD/Euro): ";
		gets(loai);	
	}while(stricmp(loai,"VND") != 0 && stricmp(loai,"USD") != 0 && stricmp(loai,"Euro") != 0);
	
	if(stricmp(loai,"USD") == 0) tygia=1/(float)23000;
	else if(stricmp(loai,"Euro") == 0) tygia=1/(float)25000;
	
	tinhTien();
}

void GDTTe::xuat(){
	QLGD::xuat();
	cout<<", So tien: "<<sotien<<", Ty gia: "<<tygia<<", Loai tien te: "<<loai<<", Thanh tien: "<<thanhtien<<"]\n";
}

void GDTTe::tinhTien(){
	if(stricmp(loai,"VND") == 0) thanhtien=sotien;
	else thanhtien=sotien*tygia;
}


// HAM DATE
Date::Date(){
	day=0;
	month=0;
	year=0;
}

void Date::setDay(){
	int ngay;
	do{
		cout<<"\nNgay: ";
		cin>>ngay;
	}while(ngay>31 || ngay<1);
	day=ngay;
}

int Date::getDay(){
	return day;
}

void Date::setMonth(){
	int thang;
	do{
		cout<<"Thang: ";
		cin>>thang;
	}while(thang<1 || thang>12);
	month=thang;
}

int Date::getMonth(){
	return month;
}

void Date::setYear(){
	int nam;
	cout<<"Nam: ";
	cin>>nam;
	year=nam;
}

int Date::getYear(){
	return year;
}

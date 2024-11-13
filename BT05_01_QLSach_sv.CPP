#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_NXB		50
//Class Nhanvien
class QLSach
{
	protected:
		char MaSach[12];
		char NgayNhap[12];
		float DonGia;
		int SoLuong;
		char NXB[50];
		float ThanhTien;
	public:
		QLSach();
		virtual void Nhap();
		virtual void Xuat();
		virtual void TinhTien()=0; //Ham thuan ao
		float getTTien();
		void timSGK(char* X);
};


//Class Bien che
class SachGK: public QLSach
{
	protected:
		int TinhTrang; //1-Moi; 0-Cu
	public:
		SachGK();
		void TinhTien();
		void Nhap();
		void Xuat();
		//...bo sung code
};

//Dinh nghia lop SachTK

class SachTK : public QLSach
{
	protected:
		float Thue;
	public:
		SachTK();
		void Nhap();
		void TinhTien();
		void Xuat();
		//...bo sung code
};

int main()
{
	QLSach *MSach[100];
	int i=0,n=0;
	float sumSGK=0, sumSTK=0, tbcSTK=0;
	char Chon,Loai, nxb_ct[50];
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Nhap thong tin cho cac loai sach"<<endl;
	do
	{
		cout<<"\nSack Giao khoa hay Sach Tham khao (G/T)? ";
		cin>>Loai;
		Loai=toupper(Loai);
		if (Loai=='G')
		{
			MSach[n] = new SachGK();
			MSach[n]->Nhap();
			sumSGK+=MSach[n]->getTTien();
		}

		else
		{
			MSach[n] = new SachTK();
			MSach[n]->Nhap();
			sumSTK+=MSach[n]->getTTien();
		}
		n++; //tang len so luong sach
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((n==100)||(Chon=='K'))
			break;
	}
	while (1);

	cout<<"Danh sach cac loai sach da nhap\n";
	for(i=0; i<n; i++)
	{
		MSach[i]->Xuat();
	}

	cout<<"\nTong thanh tien sach giao khoa: "<<sumSGK;
	cout<<"\nTong thanh tien sach tham khao: "<<sumSTK;
	tbcSTK=sumSTK/n;
	cout<<"\nTong TBCong thanh tien sach tham khao: "<<tbcSTK;

	char fnxb[50];
	cout<<"\nNha xuat ban can tim: ";
	cin.ignore();
	gets(fnxb);
	for(i=0; i<n; i++)
	{
		MSach[i]->timSGK(fnxb);
	}

	getch();
	return 1;
}


//Dinh nghia ham thanh vien cho lop QLSach
QLSach::QLSach()
{
	strcpy(MaSach,"");
	strcpy(NgayNhap,"");
	strcpy(NXB,"");
	ThanhTien=DonGia=SoLuong=0;
}

void QLSach::Nhap()
{
	cin.ignore();
	cout<<"\nMa sach: ";
	gets(MaSach);
	cout<<"Ngay nhap: ";
	gets(NgayNhap);
	cout<<"Don gia: ";
	cin>>DonGia;
	cout<<"So Luong: ";
	cin>>SoLuong;
	cin.ignore();
	cout<<"Nha xuat ban: ";
	gets(NXB);
}

void QLSach::Xuat()
{
	cout<<"[MS: "<<MaSach<<", NG: "<<NgayNhap;
	cout<<", DG: "<<DonGia<<", SL: "<<SoLuong;
	cout<<", TT: "<<ThanhTien<<", NXB: "<<NXB;
}

float QLSach::getTTien()
{
	return ThanhTien;
}

void QLSach::timSGK(char* X)
{
	if(stricmp(X,NXB) == 0) Xuat();
}

//Dinh nghia ham thanh vien cho lop SachGK
SachGK::SachGK(): QLSach()
{
	//QLSach::QLSach();
	TinhTrang=1; //mac nhien la Sach moi
}
void SachGK::TinhTien()
{
	if (TinhTrang==1)
		ThanhTien=SoLuong*DonGia;
	else
		ThanhTien=SoLuong*DonGia*0.5;
}

void SachGK::Nhap()
{
	QLSach::Nhap();
	do
	{
		cout<<"Tinh trang sach moi hay cu (1/0): ";
		cin>>TinhTrang;
	}
	while(TinhTrang>1 || TinhTrang<0);
	TinhTien();
}

void SachGK::Xuat()
{
	QLSach::Xuat();
	char ttrang[3];
	if(TinhTrang == 1) strcpy(ttrang, "Moi");
	else strcpy(ttrang, "Cu");
	cout<<", TTrang: "<<ttrang<<"]\n";
}

//Cac ham thanh vien trong lop SachTK
SachTK::SachTK(): QLSach()
{
	Thue=0;
}

void SachTK::Nhap()
{
	QLSach::Nhap();
	do
	{
		cout<<"Thue(5-20): ";
		cin>>Thue;
	}
	while(Thue<5 || Thue>20);
	Thue=Thue/100;
	TinhTien();
}

void SachTK::TinhTien()
{
	ThanhTien= SoLuong*DonGia + SoLuong*DonGia*Thue;
}

void SachTK::Xuat()
{
	QLSach::Xuat();
	cout<<", Thue: "<<Thue<<"]\n";
}



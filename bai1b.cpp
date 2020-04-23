/*Xây dựng cấu trúc điểm biểu diễn điểm trong mặt phẳng Oxy (tọa độ là các số thực). 
Viết chương trình cho phép người dùng nhập vào n (do người dùng nhập vào) điểm 
và xuất ra 2 điểm có khoảng cách lớn nhất trong các điểm vừa nhập.                 */

#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
    float fHoanhDo;  // x
    float fTungDo;   // y
};

void NhapSoN(int &); // tham chiếu
void SetDiem(Diem &,float,float ); //tham chiếu
void NhapNhieuDiem(Diem [],int);
void XuatDiem(Diem );
void XuatNhieuDiem(Diem [],int);
float KhoangCach(Diem ,Diem );
void TimKhoangCachLonNhat(Diem [],int ,int &,int &); // tham chiếu

int main()
{
    int n;
    int i=0 ;
	int j=0 ;
    NhapSoN(n);
    Diem a[n];
    NhapNhieuDiem(a,n);
    while(n==1)
    {
        cout<<"Ban chi nhan 1 diem moi nhap lai\n";
        NhapSoN(n);
    }
    if(n==2)
    {
        NhapNhieuDiem(a,n);
        i=0;j=1;
        cout<<"\nHai diem co khoang cach lon nhat: ";
        cout<<"\nDiem "<<i;
        XuatDiem(a[i]);
        cout<<"\nDiem "<<j;
        XuatDiem(a[j]);
        return 0;
    }
    XuatNhieuDiem(a,n);
    TimKhoangCachLonNhat(a,n,i,j);
    cout<<"\nHai diem co khoang cach lon nhat: ";
    XuatDiem(a[i]);
    XuatDiem(a[j]);
    return 0;
}

void NhapSoN(int &n)
{
    do{
        cout<<"Nhap n: ";
        cin>>n;
    }while(n<=0);
}

void SetDiem(Diem &diem, float fX , float fY ) //tham chiếu
{
	diem.fHoanhDo = fX;
	diem.fTungDo = fY;
}

void NhapNhieuDiem(Diem diem[],int n)
{
    	float fX;
    	float fY;
    	for (int i = 0; i <n ; i++)
    	{
		cout << "Nhap hoanh do: ";
		cin >> fX;
		cout << "Nhap tung do: ";
		cin >> fY;
		SetDiem(diem[i], fX, fY);
	}
}

void XuatDiem(Diem diem)
{
	cout << "\nHoanh do: " << diem.fHoanhDo;
	cout << "\nTung do: " << diem.fTungDo;
}

void XuatNhieuDiem(Diem diem[], int n)
{
	for (int i = 0; i < n; i++)
		XuatDiem(diem[i]);
}

float KhoangCach(Diem a, Diem b)
{
	return sqrt(pow((a.fHoanhDo - b.fHoanhDo), 2) +     /* CT : căn bậc 2( (x1-x2)^2 + (y1-y2)^2 )  */
				pow((a.fTungDo - b.fTungDo), 2));
}

void TimKhoangCachLonNhat(Diem diem[], int n, int &iViTri1, int &iViTri2)
{
	float fMax = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			float fKhoangCach = KhoangCach(diem[i], diem[j]);
			if (fKhoangCach > fMax)
			{
				fMax = fKhoangCach;
				iViTri1 = i;
				iViTri2 = j;
			}
		}
}

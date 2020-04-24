/* Dựa vào bài 1.b, xây dựng phương thức thiết lập giá trị (SetDiem) gồm 3 thành phần: 
- Tham số 1: điểm cần thiết lập giá trị (truyền tham chiếu) - 
Tham số 2: gán cho hoành độ - 
Tham số 3: gán cho tung độ 
Trong đó tham số 2 và 3 là 2 tham số mặc nhiên (=0). Viết chương trình nhập vào n (do người dùng nhập vào) điểm, 
trong đó việc nhập giá trị cho điểm thứ i sẽ gọi đến phương thức SetDiem nhằm thiết lập giá trị cho điểm theo mô tả sau: 
- Nếu i%3==0: nhập đầy đủ tung độ, hoành độ và gọi phương thức SetDiem với đầy đủ giá trị truyền vào cho tất cả các tham số.  
- Nếu i%3==1: chỉ nhập hoành độ và gọi phương thức SetDiem với 2 giá trị truyền vào cho tham số 1 và 2. 
- Nếu i%3==2: không nhập vào hoành độ và tung độ và gọi phương thức SetDiem với 1 giá trị tryền vào cho tham số 1.
 Xuất ra tọa độ tất cả các điểm và xuất ra 2 điểm có khoảng cách lớn nhất trong các điểm vừa nhập.     */

#include <iostream>
#include <cmath>
using namespace std;

struct Diem
{
    float fHoanhDo;     //x
    float fTungDo;      //y
};

void NhapSoN(int &); //tham chiếu
void SetDiem(Diem &,float ,float ); //tham chiếu
void NhapNhieuDiem(Diem [],int );
void XuatDiem(Diem );
void XuatNhieuDiem(Diem [], int );
float KhoangCach(Diem ,Diem );
void TimKhoangCachLonNhat(Diem [],int ,int &,int &); //tham chiếu

int main()
{
    int n;
    int i=0;
    int j=0;
    NhapSoN(n);
    Diem a[n];
    NhapNhieuDiem(a,n);
    while(n==1)
    {
        cout<<"Ban moi chi nhap 1 diem!"
        NhapSoN(n);
        NhapNhieuDiem(a,n);
    }
    XuatNhieuDiem(a,n);
    TimKhoangCachLonNhat(a,n,i,j);
    cout<<"\n2 diem co khoang cach lon nhat: ";
    XuatDiem(a[i]);
    XuatDiem(a[j]);
    return 0;
}

void NhapSoN(int &n) //tham chiếu
{
    do{
        cout<<"Nhap n: ";
        cin>>n;
    }while(n<=0);
}

void SetDiem(Diem &diem,float fX=0, float fY=0) //tham chiếu
{
    diem.fHoanhDo=fX;
    diem.fTungDo=fY;
}
void NhapNhieuDiem(Diem diem[],int n)
{
    float fX=0;
    float fY=0;
    for(int i=0;i<n;i++)
    {
        if(i%3==0)
        {
            cout<<"Nhap hoanh do: ";
            cin>>fX;
            cout<<"Nhap tung do: ";
            cin>>fY;
            SetDiem(diem[i],fX,fY);
        }
        else if(i%3==1)
        {
            cout<<"Nhap hoanh do: ";
            cin>>fX;
            SetDiem(diem[i],fX);
        }
        else if(i%3==2)
            SetDiem(diem[i]);
    }
}

//Xuất 1 điểm
void XuatDiem(Diem diem)
{
    cout<<"\nHoanh do: "<<diem.fHoanhDo;
    cout<<"\nTung do: "<<diem.fTungDo;
}

void XuatNhieuDiem(Diem diem[],int n)
{
    for(int i=0;i<n;i++)
    {
        XuatDiem(diem[i]); //Xuất điểm ở vị trí i
    }
}

//Tìm khoảng cách giữa 2 điểm
float KhoangCach(Diem a,Diem b) // CT: căn bậc 2 ( (x1-x2)^2 + (y1-y2)^2 )
{
    return sqrt(pow( (a.fHoanhDo - b.fHoanhDo) ,2)   
               +pow( (a.fTungDo - b.fTungDo) ,2));
}

//Tìm khoảng cách lớn nhất giữa các điểm 
void TimKhoangCachLonNhat(Diem diem[],int n,int &ViTri1,int &ViTri2) //truyền tham chiếu cho 2 vị trí có khoảng cách lớn nhất
{
    float fMax=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            float fKhoangCach=KhoangCach(diem[i],diem[j]);
            if(fMax<fKhoangCach)
            {
                fMax=fKhoangCach;
                ViTri1=i;
                ViTri2=j;    
            }
        }
}
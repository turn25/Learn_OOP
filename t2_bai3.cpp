/*Bài 3: Cho một danh sách lưu thông tin của các nhân viên trong một công ty, thông tin gồm:
- Mã nhân viên (chuỗi, tối đa là 8 ký tự)
- Họ và tên (chuỗi, tối đa là 20 ký tự)
- Phòng ban (chuỗi, tối đa 10 ký tự)
- Lương cơ bản (số nguyên)
- Thưởng (số nguyên)
- Thực lãnh (số nguyên, trong đó thực lãnh = lương cơ bản + thưởng )
Hãy thực hiện các công việc sau:
a.	Tính tổng thực lãnh tháng của tất cả nhân viên trong công ty.
b.	In danh sách những nhân viên có mức lương cơ bản thấp nhất.
c.	Đếm số lượng nhân viên có mức thưởng >= 1200000.
d.	In danh sách các nhân viên tăng dần theo phòng ban, nếu phòng ban trùng nhau thì giảm dần theo mã nhân viên. */

#include <iostream>
#include <string.h>
using namespace std;

struct NHANVIEN
{
    char MaNhanVien[8];
    char HoTen[20];
    char PhongBan[10];
    int LuongCoBan;
    int Thuong;
    int ThucLanh;
};

void clear();
void NhapSoNhanVien(int &); //tham chiếu
void NhapNhanVien(NHANVIEN &); //tham chiếu
void XuatNhanVien(NHANVIEN );
int TongThucLanh(NHANVIEN [],int );//câu a
int LuongMin(NHANVIEN [],int ); //câu b
int DemLuongThuongCao(NHANVIEN [],int ); // câu c
void Swap(NHANVIEN &,NHANVIEN &); //tham chiếu
void TangDan(NHANVIEN [],int ); // câu d

int main()
{
    int n;
    NhapSoNhanVien(n);
    NHANVIEN DSNhanVien[n];
    for(int i=0;i<n;i++)
    {
        NhapNhanVien(DSNhanVien[i]);
    }
    int TongTL = TongThucLanh(DSNhanVien,n);
    cout<<"Tong thuc lanh cua tat ca nhan vien cong ty la: "<<TongTL<<endl; // câu a
    
    int min = LuongMin(DSNhanVien,n);  //câu b
    cout<<"Nhung nhan vien co muc luong co ban thap nhat la: ";
    for(int i=0;i<n;i++)
        if(DSNhanVien[i].LuongCoBan == min)
            XuatNhanVien(DSNhanVien[i]);
    
    int dem=DemLuongThuongCao(DSNhanVien,n); // câu c
    cout<<"\nSo luong nhan vien co muc thuc >= 1200000 la: "<<dem<<endl; 
    
    TangDan(DSNhanVien,n); // câu d
    cout<<"Danh sach nhan vien duoc sap xep lai la: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<< DSNhanVien[i].HoTen <<" ";
    }
    return 0;
}

void clear()
{
    cin.clear(); //reset cờ báo lỗi
    cin.ignore(10000,'\n'); // bỏ qua 10000 kí tự hoặc cho đến khi xuống dòng
}
void NhapSoNhanVien(int &Number)
{
    int bad_input;
    do{
        bad_input=1;
        cout<<"Nhap so nhan vien: ";
        if(!(cin>>Number)) //nếu ko nhập vào kiểu int
        {
            bad_input=0;
            cout<<"Lam on hay chi nhap so!\n";
        }
        clear();
    }while(Number<0 || bad_input==0);
}

void NhapNhanVien(NHANVIEN &NhanVien)
{
    cout<<"Nhap ma nhan vien: ";
    gets(NhanVien.MaNhanVien);
    cout<<"Nhap ho ten: ";
    gets(NhanVien.HoTen);
    cout<<"Nhap phong ban: ";
    gets(NhanVien.PhongBan);
    cout<<"Nhap luong co ban: ";
    cin>>NhanVien.LuongCoBan;
    cout<<"Nhap Thuong: ";
    cin>>NhanVien.Thuong;
    NhanVien.ThucLanh = NhanVien.LuongCoBan + NhanVien.Thuong;
    clear();
}

void XuatNhanVien(NHANVIEN NhanVien)
{
    cout<<"\nMa nhan vien: "<<NhanVien.MaNhanVien<<endl;
    cout<<"Ten nhan vien: "<<NhanVien.HoTen;
}

int TongThucLanh(NHANVIEN NhanVien[],int n)
{
    int Tong=0;
    for(int i=0;i<n;i++)
    {
        Tong=Tong + NhanVien[i].ThucLanh;
    }
    return Tong;
}

int LuongMin(NHANVIEN NhanVien[],int n)
{
    int min= NhanVien[0].LuongCoBan;
    for(int i=1;i<n;i++)
        if(NhanVien[i].LuongCoBan < min)
            min=NhanVien[i].LuongCoBan;
    return min;
}

int DemLuongThuongCao(NHANVIEN NhanVien[],int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
        if(NhanVien[i].Thuong >= 1200000)
            dem++;
    return dem;
}

void Swap(NHANVIEN &a,NHANVIEN &b) //tham chiếu
{
    NHANVIEN temp = a;
    a=b;
    b=temp;
}

void TangDan(NHANVIEN NhanVien[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
        {
            int compare = strcmp(NhanVien[i].PhongBan,NhanVien[j].PhongBan);
            if(compare > 0 )
                Swap(NhanVien[i],NhanVien[j]);
            else if(compare == 0 )
            {
                compare = strcmp(NhanVien[i].MaNhanVien,NhanVien[j].MaNhanVien);
                if(compare < 0)
                    Swap(NhanVien[i],NhanVien[j]);
            }
        }    
}
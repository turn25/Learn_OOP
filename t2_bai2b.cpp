//b.Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình và xuất kết quả.

#include <iostream>
#include <string>
using namespace std;

struct HOCSINH{
    string HoTen;
    float DiemToan;
    float DiemVan;
};

void Nhap(HOCSINH &);
float DiemTrungBinh(HOCSINH );

int main()
{
    HOCSINH a;
    Nhap(a);
    float kq = DiemTrungBinh(a);
    cout<<"Diem trung binh cua hoc sinh "<<a.HoTen<<" la: "<<kq;
    return 0;
}

void Nhap(HOCSINH &HocSinh)
{
    cout<<"Nhap ho ten hoc sinh: ";
    getline(cin,HocSinh.HoTen);
    do{
        cout<<"Nhap diem Toan: ";
        cin>>HocSinh.DiemToan;
        cout<<"Nhap diem Van: ";
        cin>>HocSinh.DiemVan;
    }while((HocSinh.DiemToan<0 || HocSinh.DiemToan >10 ) || (HocSinh.DiemVan <0 || HocSinh.DiemVan>10));
}

float DiemTrungBinh(HOCSINH HocSinh)
{
    return (HocSinh.DiemVan + HocSinh.DiemToan)/2;
}
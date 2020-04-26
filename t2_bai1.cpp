/* Bài 1:
a.	Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
b.	Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
c.	Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả. */

#include <iostream>
using namespace std;

struct PHANSO
{
    int iTuSo;
    int iMauSo;
};

void clear();
void ChonBaiGiai(int &);
void NhapPhanSo(PHANSO &); //tham chiếu
void XuatPhanSo(PHANSO );
//Muốn rút gọn phân số thì tìm ước chung LN của tử và mẫu số, sau đó lấy tử=tử/UCLN mẫu=mẫu/UCLN.
int GCD(int ,int ); //Ước chung lớn nhất
void RutGonPhanSo(PHANSO &); //tham chiếu
int SoSanh(PHANSO ,PHANSO );
PHANSO Tong(PHANSO ,PHANSO );
PHANSO Hieu(PHANSO ,PHANSO );
PHANSO Tich(PHANSO ,PHANSO );
PHANSO Thuong(PHANSO ,PHANSO );
void BatDauLai(int &);

int main()
{
    int BatDau=1;
    int n;
    while(BatDau==1){
        ChonBaiGiai(n);
        cout<<"Ban da chon so "<<n<<endl;    
        if(n==1){
            PHANSO a;
            NhapPhanSo(a);
            RutGonPhanSo(a);
            cout<<"Phan so: duoc rut gon: ";
            XuatPhanSo(a);
            BatDauLai(BatDau);
        }
        if(n!=1){
            BatDau=0;
            PHANSO a;PHANSO b;
            cout<<"Phan so 1\n";
            NhapPhanSo(a);
            cout<<"Phan so 2\n";
            NhapPhanSo(b);
            if(n==2){
                int r= SoSanh(a,b);
                cout<<"Phan so lon nhat la ";
                if(r > 0)
                    XuatPhanSo(a);
                else
                    XuatPhanSo(b);
                BatDauLai(BatDau);
            }
            if(n==3){
                PHANSO c;
                cout<<"Tong 2 phan so la: ";
                c=Tong(a,b);
                XuatPhanSo(c);
                cout<<"\nHieu 2 phan so la: ";
                c=Hieu(a,b);
                XuatPhanSo(c);
                cout<<"\nTich 2 phan so la: ";
                c=Tich(a,b);
                XuatPhanSo(c);
                cout<<"\nTich 2 phan so la: ";
                c=Tong(a,b);
                XuatPhanSo(c);
                BatDauLai(BatDau);
            }
        }
    }
    return 0;
}

void clear()
{
    cin.clear();//reset lại cờ báo lỗi
    cin.ignore(10000,'\n');//xóa kí tự trong bộ nhớ đệm (bỏ qua 10000 kí tự cho hoặc đến khi xuống hàng '\n')

}

void ChonBaiGiai(int &Number)
{
    cout<<"1: cau a\n2: cau b\n3: cau c\n";
    do{
        cout<<"Nhap so: ";
        if(!(cin>>Number)) // !cin = cờ báo lỗi nếu nhập kiểu dữ liệu khác ngoài int
        {
            cout<<"Lam on chi nhap so\n";
            clear(); // xóa bộ nhớ đệm
        }
        clear();// Tránh TH nhập "1 2" vì 1 là kiểu int nên sẽ đc nhập cho biến Number còn " 2" vẫn đc giữ trong bộ nhớ đệm 
    }while(Number<1 || Number>3); //nếu n<1 hoặc n>3
}

void NhapPhanSo(PHANSO &PhanSo) //tham chiếu
{
    int bad_input;
    do{
        bad_input=0;
        cout<<"Nhap tu so: ";
        if(!(cin>>PhanSo.iTuSo))
        {
            bad_input=1;
            cout<<"Lam on chi nhap so\n";
            clear();
        }
        clear();//clear bộ nhớ đệm (vd nhập "1 2" thì giá trị 1 đc nhập vào iTuSo 
                //còn 2 đc giữ trong bộ nhớ đệm cho biến tiếp theo , ở đây là iMauSo)
    }while(bad_input==1);
    do{
        bad_input=0;
        cout<<"Nhap mau so: ";
        if(!(cin>>PhanSo.iMauSo))
        {
            bad_input=1;
            cout<<"Lam on chi nhap so\n";
            clear();
        }
        clear();
    }while(bad_input==1);
}

void XuatPhanSo(PHANSO PhanSo)
{
    if(PhanSo.iMauSo==1)
        cout<<PhanSo.iTuSo;
    else
        cout<<PhanSo.iTuSo<<"/"<<PhanSo.iMauSo;
}

int GCD(int a,int b) //hàm int trả về dữ liệu nên ko cần truyền tham chiếu
{  
    if( a == 0 || b == 0)    // Nếu a=0 -> UCLN(a,b)=b;
        return a+b;          // Nếu b=0 -> UCLN(a,b)=a;
    while(a != b) //Đến khi a=b thì dừng
    {
        if(a > b)
            a -= b; // a=a-b;
        else
            b -= a; // b=b-a;
    }
    return a; //hoặc b vì lúc này a = b; 
}

void RutGonPhanSo(PHANSO &PhanSo) //tham chiếu
{
    int UCLN=GCD(PhanSo.iTuSo,PhanSo.iMauSo);
    PhanSo.iTuSo = PhanSo.iTuSo / UCLN;
    PhanSo.iMauSo = PhanSo.iMauSo / UCLN;
}

int SoSanh(PHANSO a,PHANSO b) //So sánh để tìm phân số lớn nhất 
{
    return a.iTuSo * b.iMauSo - b.iTuSo * a.iMauSo;
}

PHANSO Tong(PHANSO a,PHANSO b)
{
    PHANSO kq;
    kq.iTuSo = a.iTuSo * b.iMauSo + b.iTuSo * a.iMauSo ;
    kq.iMauSo = a.iMauSo * b.iMauSo ;
    return kq;
}

PHANSO Hieu(PHANSO a,PHANSO b)
{
    PHANSO kq;
    kq.iTuSo = a.iTuSo * b.iMauSo - b.iTuSo * a.iMauSo ;
    kq.iMauSo = a.iMauSo * b.iMauSo ;
    return kq;
}

PHANSO Tich(PHANSO a,PHANSO b)
{
    PHANSO kq;
    kq.iTuSo =  a.iTuSo * b.iTuSo ;
    kq.iMauSo = a.iMauSo * b.iMauSo ; 
    return kq;
}

PHANSO Thuong(PHANSO a,PHANSO b)
{
    PHANSO kq;
    kq.iTuSo = a.iTuSo * b.iMauSo ;
    kq.iMauSo = a.iMauSo * b.iTuSo ;
    return kq;
}

void BatDauLai(int &flag)
{
    do{
        cout<<"\nBan co muon thu lai? ( 1:y/ 0:n) : ";
        if(!(cin>>flag))
        {
            cout<<"Chi nhap so!\n";
            clear();
        }
        clear();
    }while(flag!=0 && flag!=1); //khi ko bằng cả 2 
}

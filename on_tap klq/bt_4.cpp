/*Câu 4: (Đề thi HKI 2015)
 Viết hàm tìm giá trị lớn nhất nhưng không phải là số nguyên tố trong mảng số nguyên
*/

#include <iostream>
using namespace std;
void NhapChuoi(int [],int &);
int KiemTraNguyenTo(int );
int TimMax(int [],int );

int main(){
    int n;
    int a[200];
    NhapChuoi(a,n);   
    int maxn = TimMax(a,n);
    if(n==1 && maxn==-1)
        cout<<"Mang ko co gia tri lon nhat khong phai so nguyen to! ";
    else
        cout<<"Gia tri lon nhat nhung khong phai so nguyen to la: "<<a[maxn];
    return 0;
}

void NhapChuoi(int a[],int &n){
    do {
        cout<<"Nhap n: ";
        cin>>n;
    }while(n<=0);
    for(int i=0;i<n;i++){
        cout<<"Nhap a["<<i<<"]: ";
        cin>>a[i];
    }
}

int KiemTraNguyenTo(int number){
    if(number<2) // <2 thì ko phái snt
        return 0; 
    for(int i=2;i<number;i++)
        if((number%i) == 0) //Nếu n chia hết cho i thì ko phải snt vì snt chỉ chia hết cho chính nó và 1
            return 0;
    return 1;
}

int TimMax(int a[],int n){
    int i=0;
    while(i<n && KiemTraNguyenTo(a[i]) == 1) //kt nếu là snt
        i++;
    if(i == n) // cả mảng đều là snt;
        return -1; //trong mảng ko có gt -1
    int max=i;
    i++; //kt gt tiếp theo
    while(i < n){
        if(KiemTraNguyenTo(a[i]) == 0 && a[i] > a[max] )   // nếu a[i] ko phải snt và a[i] > a[max]
            max=i;
        i++;
    } 
    return max;
}
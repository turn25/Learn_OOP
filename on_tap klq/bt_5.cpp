/*Câu 5: 
Viết chương trình nhập vào một số nguyên dương, sau đó xuất ra số đó dưới dạng nhị phân,dùng đệ quy
Ví dụ: input:5 -> out: 101
*/

#include <iostream>
using namespace std;

void NhiPhan(int );

int main(){
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    cout<<"Chuyen qua dang nhi phan la: ";
    NhiPhan(n);
    return 0;
}

void NhiPhan(int n){
    if(n<0)
        return;
    if(n==0){
        cout<<0;
        return;
    }
    if(n==1){
        cout<<1;
        return;
    }
    else{
        NhiPhan(n/2);
        cout<<n%2;
    }
}
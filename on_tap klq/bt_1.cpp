/*Viết chương trình thực hiện các yêu cầu sau: 
Cho phép nhập số nguyên n từ bàn phím. Điều kiện giá trị của n: n>10. Nếu giá trị n không thỏa điều kiện này thì yêu cầu người dùng nhập lại cho đến khi nào giá trị n thỏa điều kiện trên ( 1đ) 
- Chương trình tính và in giá trị của biểu thức S sau ra màn hình (1đ) 
𝑆 = √𝑛 + √𝑛 − 1 + ⋯ + √1 , có n dấu căn
(10 phút)
*/

#include <iostream>
#include <cmath>
using namespace std;
float DeQuy(int );

int main(){
    int n;
    float S=0;
    do{
        cout<<"Nhap n: ";
        cin>>n;
    }while(n<10);
    for(int i=1;i<=n;i++){
        S=sqrt(i+S);
    }
    cout<<S<<endl;
    cout<<DeQuy(n);
}

float DeQuy(int n){
    if(n==1)
        return 1;
    else
        return sqrt(n+DeQuy(n-1));
}
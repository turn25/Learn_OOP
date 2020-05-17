/*Câu 3: (Đề thi HKI 2015)
 Viết chương trình cho phép nhập vào một chuỗi ký tự, sau đó in ra màn hình cho biết trong chuỗi vừa nhập có bao nhiêu từ. 
Ví dụ: nhập chuỗi ký tự "Truong Dai hoc Cong Nghe Thong Tin ! ", chương trình in ra chuỗi có 8 từ.
*/

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char a[200];
    cout<<"Moi nhap chuoi ki tu: ";
    cin.getline(a,200,'\n');
    //Input: " Vu Quang Tuan !"

    //Tìm độ dài của chuỗi
    int len= strlen(a); 
    int count=0; // Biến đếm
    
    //Đếm số lượng từ trừ kí tự đầu tiên 
    for(int i=1;i<len;i++){
        if(a[i] != ' ' && a[i-1] == ' ') // a là kí tự và trước a là khoảng cách
            count++;
    }

    //Nếu kí tự đầu tiên ko phải khoảng cách
    if(a[0] != ' ')
        count++;
    cout<<"So tu trong chuoi la: "<<count;
    return 0;
}
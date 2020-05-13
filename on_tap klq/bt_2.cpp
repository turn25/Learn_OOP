/*Câu 2. Viết chương trình thực hiện các yêu cầu sau: 
Cho phép người dùng nhập vào một chuỗi ký tự từ bàn phím chứa Họ Tên người dùng. 
- Thực hiện loại bỏ các khoảng trắng (space) dư thừa trong chuỗi (nếu có). 
- Chuyển các ký tự đầu tiên của mỗi từ thành chữ in hoa, các ký tự còn lại thành chữ in thường. 
- In ra màn hình chuỗi họ tên sau khi thực hiện các xử lý trên. 
Ví dụ: người dùng nhập vào chuỗi như sau: “     NGuyeN   VaN      Nam   ” Chương trình sẽ in ra: “Nguyen Van Nam”
*/
#include <iostream>
#include <string.h>
using namespace std;

int remove_char_at(int ,char [],int &); 

int main(){
    char HoTen[200];
    cout<<"Nhap ho ten: ";
    cin.getline(HoTen,200,'\n');  // Nhập vào tên , tối đa 200 kí tụ, kết thúc việc nhập khi gặp '\n' (xuống hàng= enter)
    //Ví dụ nhập vào: "  Vu  QuAng   TuaN  "
    int len = strlen(HoTen);
    //CHỈNH LẠI KHOẢNG CÁCH
    //"  vU  quAng   TuaN  " -> "vU quAng TuaN"

    //xóa khoảng cách đầu chuỗi
    //xét 2 đk , thỏa đk đầu tiên thì mới xét đến đk thứ 2 
    // ' ' = char     || " " = const char
    while(HoTen[0] == ' ' && remove_char_at(0,HoTen,len)==1); //vị trí đầu = khoảng cách VẢ remove_char_at trả về gt 1(có thể xóa) 
    {}
    //xóa khoảng cách đầu chuỗi
    while(HoTen[len-1] == ' ' && remove_char_at(len-1,HoTen,len)==1) //vị trí cuối = khoảng cách VẢ remove_char_at trả về gt 1(có thể xóa) 
    {}
    //xóa khoảng cách ở giữa các chữ   
    int i = 0;
    while(i < len-1){   // xét chạy từ 0 đến cuối chuỗi-1 vì đã xét TH cuối chuỗi ở trên
        if(HoTen[i] == ' ' && HoTen[i+1] == ' ')   // có 2 khoảng cách giữa các từ thì xóa 1 cái
            remove_char_at(i,HoTen,len);
        else // nếu mà ko có 2 khoảng cách giữa các từ (TH:0 có khoảng cách và 1 khoảng cách ) thì tăng i lên xét tiếp
            i++;
    }

    //CHUYỂN CHỮ IN HOA SANG CHỮ THƯỜNG VÀ NGƯỢC LẠI (thường sang HOA -32 || HOA sang thường +32)
    //"vU quAng TuaN" -> "Vu Quang Tuan"
    i = 0;
    
    //Chữ đầu là chữ in hoa
    if(HoTen[0] >= 'a' && HoTen[0] <= 'z') // nằm trong khoảng a->z(thường)
        HoTen[0] = HoTen[0] - 32;   // -32 để chuyển từ v sang V ;
        //HoTen[0] -= 32;
    i++;  
    while(i < len){     // Xét từ 1 đến cuối chuỗi
        if((HoTen[i] >= 'a' && HoTen[i] <= 'z') && HoTen[i-1] == ' ') //nằm trong khoảng a->z(thường) và trước i là khoảng cách
            HoTen[i] = HoTen[i] - 32;   // chuyển từ chữ thường sang IN HOA (a->A)
        if((HoTen[i] >= 'A' && HoTen[i] <= 'Z') && HoTen[i-1] != ' ') //nằm trong khoảng A->Z(HOA) và trước i ko phải là khoảng cách
            HoTen[i] = HoTen[i] + 32;   // chuyển từ IN HOA sang chữ thường (A->a)
        i++;
    }
    
    HoTen[len] = '\0';    //kết thúc chuỗi ở vị trí len , bỏ các kí tự ở sau len
    cout<<HoTen;
    return 0;
}

int remove_char_at(int i,char a[],int &n){  //truyền tham chiếu cho n
    if( i>=0 && i<=n-1){    // chỉ số i trong khoảng 0-> n-1
        for(int j=i;j<n;j++)
            a[j]=a[j+1];     //xóa vị trí j và dời tất cả vị trí sau j sang bên trái 1 đơn vị
        n--; //độ dài mảng -1
        return 1;  // xóa thành công
    }  
    return 0;   // ko xóa đc
}
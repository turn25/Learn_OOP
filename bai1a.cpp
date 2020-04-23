/*Viết chương trình nhập vào một mảng n (do người dùng nhập vào)
 phần tử là các số nguyên và xuất ra mảng theo thứ tự tăng dần. */

#include <iostream>
using namespace std;

void InputNumberOfElements(int &); // tham chiếu
void InputArr(int [],int );
void OutputArr(int [],int );
void MergeSort(int [],int ,int );

int main()
{
    int n;
    InputNumberOfElements(n);
    int a[n];
    InputArr(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    OutputArr(a,n);
    return 0;
}

void InputNumberOfElements(int &n) // tham chiếu
{
    do{
        cout<<"Input n: ";
        cin>>n;
    }while(n<=0);
}

void InputArr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Input a["<<i<<"]: ";
        cin>>a[i];
    }
}

void OutputArr(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void MergeSort(int a[],int left,int right)
{
    if(left<right) //đk dừng đệ quy .. chia nhỏ đến khi còn 1 phần tử thì xem như đã đc sắp xếp
    {
        int mid=(left+right)/2; //tìm vị trí chia đôi (ở giữa)
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        int SubArr[right+1];
        int i=left; //vị trí xét bên trái
        int j=mid+1; // vị trí xét bên phải
        int pos=0; // vị trí mảng phụ
        while(i<=mid || j<=right) // khi nào còn 1 trong 2 cái thì vẫn tiếp tục
        {
            if(i>mid) //nếu bên trái hết phần tử
            {
                SubArr[pos]=a[j]; //copy phần tử bên phải vảo mảng phụ
                j++;
                pos++;
            }
            else if(j>right) //nếu bên phải hết phần tử
            {
                SubArr[pos]=a[i]; //copy phần tử bên trái vảo mảng phụ
                i++;
                pos++;
            }
            else if(a[i]>a[j]) // nếu phần tử bên trái > phải 
            {
                SubArr[pos]=a[j]; //copy phần tử bên phải vảo mảng phụ
                j++;
                pos++;
            }
            else              // nếu phần tử bên trái < phải
            {
                SubArr[pos]=a[i]; //copy phần tử bên trái vảo mảng phụ
                i++;
                pos++;
            }
        }
        for(int i=0;i<pos;i++) //copy mảng phụ về mảng a
            a[left+i]=SubArr[i];
    }
}
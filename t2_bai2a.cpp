#include <iostream>
using namespace std;

int namNhuan (int year)
{
	return ((year%400==0) || ((year%4==0)&&(year%100!=0))); //Đúng return 1 , sai return 0
}
int ngayTrongThang(int month)
{
	int day, year;
	if ( month < 1 || month > 12) day = -1;
	else 
	{
		switch (month)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			{
				day = 31;
				break;
			}	
			case 4: case 6: case 9: case 11:
			{
				day = 30;
				break;
			}	
			default:
			{
				if (namNhuan(year) == 0) day = 28;
				else day = 29;
				break;
			}		
		}
	}
	return day;	
}
int ngayTiepTheo(int& ngay,int& month, int& year )
{
	int day;
	day = ngayTrongThang (month); // Giới hạn số ngày trong tháng
	if (day == -1 || ngay <1 || ngay > day) //Ngày ko hợp lệ
		return -1; 
	else 
	{
		if (ngay < day) ngay++;
		else if (month!=12) //ko phải tháng 12 và số ngày vượt quá giới hạn của tháng trước = qua tháng
			{
				ngay = 1;
				month++;
			}	
		else  // qua năm mới
			{
				ngay = month = 1;
				year++;
			}
	}		
}
int main()
{
	int year,month,ngay;
	cout << " Hay nhap nam: " ; 
	cin >> year ; cout << endl;   //Năm
	cout << " Hay nhap thang: " ; 
	cin >> month ; cout << endl;//Tháng
	cout << " Hay nhap ngay: " ; 
	cin >> ngay ; cout << endl; //Ngày
	if (ngayTiepTheo(ngay, month, year) == -1) 
		cout<<" Ban vua nhap ngay thang khong hop le " << endl;
	else   
		cout<<" Ngay tiep theo sau  la ngay :  " << ngay << " / " << month << " / " << year << endl;
	return 0;
}
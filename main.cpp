#include <iostream>
using namespace std;
struct ngaythangnam
{
    int ngay;
    int thang;
    int nam;
};
bool nhuan(ngaythangnam a)
{
    if (a.nam%400==0||(a.nam%4==0&&a.nam%100!=0)) return true;
    return false;
}
void nhap(ngaythangnam &a)
{
    cout<<"NHAP NGAY: ";
    cin >> a.ngay;
    cout<<endl;
    cout<<"NHAP THANG: ";
    cin>>a.thang;
    cout<< endl;
    cout<<"NHAP NAM: ";
    cin>>a.nam;
}
void xuat (ngaythangnam a)
{
    cout<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
}
int ngaycuathang(ngaythangnam a)
{
    int ngay;
    switch(a.thang)
    {
        case 2:
            if (nhuan(a)) ngay=29;
            else ngay=28;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ngay=31;
            break;
        default:
            ngay=30;
    }
    return ngay;
}
bool hople(ngaythangnam a)
{
    if (a.nam < 1582) return false;
    if (a.thang < 1 || a.thang > 12) return false;
    if (a.ngay < 1 || a.ngay > ngaycuathang(a)) return false;
    return true;
}
int thucuangay(ngaythangnam a)
{
    int d = a.ngay;
    int m = a.thang;
    int y = a.nam;
    if (m < 3)
    {
        m += 12;
        y--;
    }
    int K=y%100;
    int J=y/100;
    int f=d+(13*(m+1))/5+K+(K/4)+(J/4)+(5*J);
    return f % 7;
}
int main()
{
    ngaythangnam a;
    nhap( a);
    xuat(a);
    cout<< " LA ";
    int ngay=thucuangay( a);
    if (ngay==1)
    {
        cout<<"CHU NHAT";
    }
    else cout << "THU "<<(ngay==0?7:ngay);
    return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

void inputArray(int a[], int &na)
{
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }
}

void outputArray(int a[], int na)
{
    for (int i = 0; i < na; i++)
    {
        cout << a[i] << " ";
    }
}

bool SNT(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            return false;
        }
    return true;
}

int checkSNT(int a[], int na, int dem)
{
    dem = 0;
    for (int i = 0; i < na; i++)
        if (SNT(a[i]) == true)
            dem++;
    return dem;
}

void saveSNTToB(int a[], int na, int b[], int &m)
{
   int j = 0;
    for (int i = 0; i < na && j < m; i++)
    {
        if (SNT(a[i]))
        {
            b[j++] = a[i];
            
        }
    }
    m = j;
}
int filterPrimes(int a[], int na, int b[], int &nb, int m)
{
    int dem = checkSNT(a, na, dem);
    
    if (dem != 0)
    {
        if (dem < m)
        {
            cout << "Mang a khong co du " << m << " so nguyen to " << endl;
            saveSNTToB(a, na, b, dem);
            nb = dem;
        }

        if (dem >= m)
        {
            saveSNTToB(a, na, b, m);
            nb = m;
        }
    }
    if (dem == 0)
    {
        // cout << "dem3 = " << dem << endl;
        // cout << "m = " << m << endl;
        cout << "Mang a khong chua so nguyen to" << endl;
        nb = 0;
    }
}
int main()
{
    int na, a[100], nb, b[100];
    cin >> na;
    inputArray(a, na);
    cout << "Mang a:" << endl;
    outputArray(a, na);

    cout << endl;

    int m;
    cin >> m;
    filterPrimes(a, na, b, nb, m); // tao ra mang b bang cach tach m so nguyen to tu a
    cout<<"Mang b:"<<endl;
    outputArray(b,nb);

    system("pause");
    return 0;
}

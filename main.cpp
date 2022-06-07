#include <iostream>
#include <algorithm>

using namespace std;

class Frac
{
public:
    int x, y; // ???摮?嚗????瘥?

    Frac(int a, int b) : x(a), y(b) 
    {
        int temp;

        if (x < 0 && y < 0 || x >0 && y > 0)
            temp = 1;
        
        else
            temp = -1;
        
        int g = gcd();
        x /= g;
        y /= g;

        x *= temp;
    }

    int gcd()
    {
        int a = max(x, y), b = min(x, y), t;

        while (a % b)
        {
            t = a;
            a = b;
            b = t % b;
        }

        return b;
    }

    Frac operator+(const Frac &a) const
    {
        int result_x, result_y = a.y * y;
        result_x = x * a.y + a.x * y;
        return Frac(result_x, result_y);
    }

    Frac operator-(const Frac &a) const
    {
        int result_x, result_y = a.y * y;
        result_x = x * a.y - a.x * y;
        return Frac(result_x, result_y);
    }

    Frac operator*(const Frac &a) const
    {
        int result_x = x * a.x, result_y = a.y * y;
        return Frac(result_x, result_y);
    }

    Frac operator/(const Frac &a) const
    {
        int result_x = x * a.y, result_y = y * a.x;
        return Frac(result_x, result_y);
    }

    Frac operator%(const Frac &a) const
    {
        cout << "哭啊" << endl;
        return Frac(1, 1);
    }

    bool operator==(const Frac &a) const
    {
        return a.x == x && a.y == y;
    }

    bool operator>(const Frac &a) const
    {
        return x * a.y > a.x * y;
    }

    bool operator<(const Frac &a) const
    {
        return x * a.y < a.x * y;
    }

    bool operator>=(const Frac &a) const
    {
        return x * a.y >= a.x * y;
    }

    bool operator<=(const Frac &a) const
    {
        return x * a.y <= a.x * y;
    }

    bool operator!=(const Frac &a) const
    {
        return x * a.y != a.x * y;
    }

    void print()
    {
        if (y == 1 || x == 0)
            cout << x;
        
        else
            cout << x << "/" << y;
    }
};

int main(void)
{
    Frac a(4, 6), b(2, 3);
    
    if (a > b)
        cout << "a比較大";
    
    else if (a == b)
        cout << "a等於b";
    
    else
        cout << "a小於b";
}
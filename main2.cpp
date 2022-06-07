#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    unsigned long long x, y;

    Solution(unsigned long long x = 0, unsigned long long y = 1) : x(x), y(y) 
    {
        init();
    }

    void init() 
    {
        int temp;

        if (y < 0 && x < 0 || x > 0 && y > 0)
            temp = 1;
        
        else
            temp = -1;
        
        x = abs(x);
        y = abs(y);
        unsigned long long g = llgcd(x, y);
        x /= g, y /= g;
        y *= temp;
    }

    long long llgcd(long long x, long long y) const 
    {
        long long maxa = max(x, y);
        long long minb = min(x, y);
        long long t;

        while (maxa % minb)
            t = maxa, maxa = minb, minb = t % maxa;
        
        return minb;
    }

    Solution operator-(const Solution &a) const 
    {
        unsigned long long va = 0, vb = a.y / llgcd(y, a.y) * y;
        va = vb / y * x - vb / a.y * a.x;
        return Solution(va, vb);
    }

    Solution operator+(const Solution &a) const 
    {
        unsigned long long va = 0, vb = a.y / llgcd(y, a.y) * y;
        va = vb / y * x + vb / a.y * a.x;
        return Solution(va, vb);
    }

    Solution operator*(const Solution a) const 
    {
        long long g1 = llgcd(x, a.y), g2 = llgcd(a.x, y);
        long long va = 0, vb = 0;
        va = (x / g1) * (a.x / g2);
        vb = (y / g2) * (a.y / g1);
        return Solution(va, vb);
    }
    
    Solution operator/(const Solution a) const 
    {
        long long g1 = llgcd(y, a.y), g2 = llgcd(x, a.x);
        long long va = 0, vb = 0;
        va = (a.y / g1) * (x / g2);
        vb = (y / g1) * (a.x / g2);
        return Solution(va, vb);
    }

    bool operator==(const Solution &a) const 
    {
        return x - a.x == 0 && y - a.y == 0;
    }

    bool operator<(const Solution &a) const 
    {
        return x * a.y < a.x * y;
    }

    bool operator<=(const Solution &a) const 
    {
        return x * a.y <= a.x * y;
    }

    bool operator>=(const Solution &a) const
    {
        return x *a.y >= a.x * y;
    }

    void print() 
    {
        if (y == 1)

            cout << x << endl;
            
        else
            cout << x << "/" << y << endl;
    }
};

int main(void) 
{
    int cases = 0;
    long long v1, d1, v2, d2;

    while (cin >> v1 >> d1 >> v2 >> d2 && (v1 || d1 || v2 || d2)) 
    {
        cout << "Case #" << ++ cases << ": ";
        Solution p(d1, v1), q(d2, v2), r = (p + q) * Solution(1, 2);

        if (p < q)
            cout << "You owe me a beer!" << endl;

        else
            cout << "No beer for the captain." << endl;

        cout << "Avg. arrival time: ";
        r.print();
    }
}
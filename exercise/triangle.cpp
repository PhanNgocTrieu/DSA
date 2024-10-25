#include <bits/stdc++.h>
using namespace std;

bool rightTriangle(int a, int b, int c) {
    return (a*a + b*b == c*c) ||(b*b + c*c == a*a) || (a*a + c*c == b*b);
}

bool isocelesTriangle(int a, int b, int c) {
    return (a == b) || (b == c) || (c == a);
}

bool acuteTriangle(int a, int b, int c) {
    return (a == b == c);
}

bool equilateralTriangle(int a, int b, int c) {
    return (a == b && b == c);
}

bool acuteRightTriangle(int a, int b, int c) {
    return
        ( 
            (
                a*a + b*b == c*c
            )
            &&
            (
                a == b
            )
        )
        ||
        ( 
            (
                a*a + c*c == b*b
            )
            &&
            (
                a == c
            )
        )
        ||
                ( 
            (
                c*c + b*b == a*a
            )
            &&
            (
                c == b
            )
        );
}


int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (acuteRightTriangle(a,b,c)) {
        cout << "acute right triangle!" << endl;
    }
    else if (rightTriangle(a,b,c)) {
        cout << "right triangle!" << endl;
    }
    else if (equilateralTriangle(a,b,c))  {
        cout << "equilateral triangle!" << endl;
    }
    else if (isocelesTriangle(a,b,c)) {
        cout << "isoceles triangle!" << endl;
    }
    else {
        cout << "scalene triangle!" << endl;
    }

    return 0;
}
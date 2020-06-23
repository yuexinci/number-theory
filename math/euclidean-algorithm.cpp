
#include <iostream>
#include <string> 
#include <ios>
#include <limits> 
using namespace std;

int main() {

    int x = -1;
    int y = -1;
    int temp = 0;
    int q = 0;
    int r = -1;
    int tempx = 0;
    int tempy = 0;

    char showWork = 'a';

    //to be written somewhere later: fermat, linear equations and the greates common divisor
    cout << "Welcome to the GCD calculator! This program uses the Euclidean algorithm to find the greatest common divisor of two integers"
    << endl;
    cout << "Please enter two nonzero integers: " << endl;

    //get input
    while (!(cin >> x >> y) || x == 0 || y == 0) {
      cout << "bad format" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ^^ these two are to avoid issues w/cin so we can get input again
      cout << "Please enter two nonzero integers: " << endl;
    }

    //swap the values so x is always greater
    if (y > x) {
        temp = y;
        y = x;
        x = temp;
    }
    tempx = x;
    tempy = y;

    //show-work option
    cout << "Would you like to show the work? (y/n)" << endl;
    cin >> showWork;
    while (showWork != 'y' && showWork != 'n') {
        cout << "please select y or n" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin >> showWork;
    }

    //algorithm
    while (r != 0) {
        q = tempx / tempy;
        r = tempx - (q * tempy);
        if (showWork == 'y') {
            cout << tempx << " = " << q << " x " << tempy << " + " << r << endl;
        }
        tempx = tempy;
        if (r != 0) {
            tempy = r;
        }
    }
    cout << "gcd(" << x << "," << y << ") = " << tempy << endl;

    return 0;
}
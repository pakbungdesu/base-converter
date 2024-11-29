

#include <iostream>
#include <string>
using namespace std;


string decimaltoany1(int d, int any) {
    char cmod;
    if (d == 0) {
        return "";
    }
    else {
        int mod = d % any;
        if (mod >= 0 && mod <= 9) {
            cmod = mod + '0';
            return decimaltoany1(d / any, any) + cmod;
        }
        else {
            cmod = mod + 'A' - 10;
            return decimaltoany1(d / any, any) + cmod;
        }
    }
}


string decimaltoany2(double n, int base) {
    string res = "";
    int digit;
    double process, frac_left;

    for (int i = 0; i < 6; i++) {
        process = n * base;
        digit = (int)process;
        frac_left = process - digit;

        if (digit >= 0 && digit <= 9) {
            res += digit + '0';
        }
        else {
            res += digit + 'A' - 10;
        }

        n = frac_left;
    }

    return res;
}



int anytodecimal1(string s, int base) {
    int res = 0, expo = 0, p = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        char d = s[i];
        if (d >= '0' && d <= '9') {
            p = d -= '0';
        }
        else { // Handle hexadecimal digits
            p = d -= 'A' - 10;
        }
        res += p * pow(base, expo);
        expo += 1;
    }
    return res;
}



double anytodecimal2(string frac, int base) {
    double res = 0.0;
    int p;

    for (int i = 0; i < frac.length(); i++) {
        char d = frac[i];

        if (d >= '0' && d <= '9') {
            p = d -= '0';
        }
        else { // Handle hexadecimal digits
            p = d -= 'A' - 10;
        }

        res += p * pow(base, -i-1);
    }
    return res;
}



int main()
{

    double f1;
    int base1, base2, r1;
    bool arbituary = false;
    string original_num, r2, f2;

    cout << "Insert original number: "; cin >> original_num;
    cout << "Insert original base: "; cin >> base1;
    cout << "Insert target's base: "; cin >> base2;

    for (auto& n: original_num) {
        if (n == '.') {
            arbituary = true;
        }
    }

    if (arbituary == true) {

        // integer part
        int idx = original_num.find(".");
        string int_part = original_num.substr(0, idx);
        r1 = anytodecimal1(int_part, base1);
        r2 = decimaltoany1(r1, base2);

        // fraction part
        string frac_part = original_num.substr(idx + 1);
        f1 = anytodecimal2(frac_part, base1);
        string f2 = decimaltoany2(f1, base2);

        r2 = r2 + "." + f2;
    }
    else {
        // integer only
        r1 = anytodecimal1(original_num, base1);
        r2 = decimaltoany1(r1, base2);
    }

    cout << "Convert " << original_num << " from base " << base1 << " to base " << base2 << endl;
    cout << "Result: " << r2 << endl;

}



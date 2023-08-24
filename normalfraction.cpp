#include<iostream>
#include<string>
#include <sstream>
#include<iomanip>

using namespace std;

std::string formatDoublee(double value) {
    std::ostringstream stream;
    stream << std::fixed;
    stream << std::setprecision(4); // You can adjust the precision as needed

    stream << value;
    std::string result = stream.str();

    // Remove trailing zeros after the decimal point
    size_t pos = result.find_last_not_of('0');
    if (pos != std::string::npos && result[pos] == '.')
        pos--;

    if (pos != std::string::npos)
        result.erase(pos + 1);

    return result;
}


int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string decimalToFraction(double decimal) {
    if (decimal == static_cast<int>(decimal)) {
        return formatDoublee(decimal);
    }

    const int MAX_DENOMINATOR = 100000;  // You can adjust the maximum denominator as needed

    int numerator = decimal * MAX_DENOMINATOR;
    int denominator = MAX_DENOMINATOR;
    
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    
    return(to_string(numerator)+"/"+to_string(denominator));
}
// int main()
// {
//     cout<<decimalToFraction(5.5);
// }

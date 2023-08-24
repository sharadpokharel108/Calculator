#include <iostream>
#include <string>
#include <regex>
#include"normalfraction.cpp"
#include<cmath>
#include <algorithm>
int findGCDD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

std::string simplifyFraction(int numerator, int denominator) {
    int gcd = findGCDD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

std::string fract(double digit,int length,double decimal)
{
    int powered=pow(10,length);
    int numerator=digit*powered+decimal-digit;
    int denominator=powered-1;
    return(simplifyFraction(numerator,denominator));

}
std::string fraction_repeating(std::string input_decimal)
{

    double decimal=std::stod(input_decimal);
        if (decimal== static_cast<int>(decimal)) {
    
        return decimalToFraction(decimal);
    }
    size_t decimal_point_position = input_decimal.find('.');
    std::string decimal_part = input_decimal.substr(decimal_point_position + 1);
    
    std::regex pattern(R"((.+?)\1+)");
    std::smatch match;
    if (std::regex_search(decimal_part, match, pattern)) {
        
        std::string repeating_part = match.str(1);
        if (!(repeating_part[0]==decimal_part[0]))
            return decimalToFraction(decimal);
        std::string whole_part = input_decimal.substr(0, decimal_point_position);
        int repeating_length = repeating_part.length();
        return(fract(std::stod(whole_part),repeating_length,std::stod(repeating_part)));
    } 
    else {

        return decimalToFraction(decimal);
    }    
}
// int main()
// {
//     cout<<fraction_repeating("14.38954500000000003012701")<<endl;

// }

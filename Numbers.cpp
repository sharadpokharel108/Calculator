#include <iostream>
#include <string>
#include <sstream>
#include <cmath>



bool isBinary(const std::string& binary) {
    for (char digit : binary) {
        if (digit != '0' && digit != '1' && digit!='.') {
            return false;
        }
    }
    return true;
}

bool isOctal(const std::string& octal) {
    for (char digit : octal) {
        if (digit ==8 or digit==9) {
            return false;
        }
    }
    return true;
}


double hexadecimalToDecimal(const std::string& hexadecimal) {
    double decimal = 0.0;
    double base = 16.0;

    int decimalPointIndex = hexadecimal.find('.');
    int integerPartLength = (decimalPointIndex == std::string::npos) ? hexadecimal.length() : decimalPointIndex;
    
    for (int i = integerPartLength - 1; i >= 0; i--) {
        int digitValue = (isdigit(hexadecimal[i])) ? (hexadecimal[i] - '0') : (toupper(hexadecimal[i]) - 'A' + 10);
        decimal += digitValue * pow(base, integerPartLength - 1 - i);
    }

    if (decimalPointIndex != std::string::npos) {
        int fractionalPartLength = hexadecimal.length() - (decimalPointIndex + 1);
        for (int i = 0; i < fractionalPartLength; i++) {
            int digitValue = (isdigit(hexadecimal[decimalPointIndex + 1 + i])) ? 
            (hexadecimal[decimalPointIndex + 1 + i] - '0') : 
            (toupper(hexadecimal[decimalPointIndex + 1 + i]) - 'A' + 10);
            decimal += digitValue * pow(base, -1 * (i + 1));
        }
    }
    
    return decimal;
}


double octalToDecimal(const std::string& octal) {

    double decimal = 0.0;
    double base = 8.0;

    int decimalPointIndex = octal.find('.');
    int integerPartLength = (decimalPointIndex == std::string::npos) ? octal.length() : decimalPointIndex;
    
    for (int i = integerPartLength - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * pow(base, integerPartLength - 1 - i);
    }

    if (decimalPointIndex != std::string::npos) {
        int fractionalPartLength = octal.length() - (decimalPointIndex + 1);
        for (int i = 0; i < fractionalPartLength; i++) {
            decimal += (octal[decimalPointIndex + 1 + i] - '0') * pow(base, -1 * (i + 1));
        }
    }
    
    return decimal;
}




double binaryToDecimal(const std::string& binary) {
    double decimal = 0.0;
    double base = 2.0;

    int decimalPointIndex = binary.find('.');
    int integerPartLength = (decimalPointIndex == std::string::npos) ? binary.length() : decimalPointIndex;
    
    for (int i = integerPartLength - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(base, integerPartLength - 1 - i);
        }
    }

    if (decimalPointIndex != std::string::npos) {
        int fractionalPartLength = binary.length() - (decimalPointIndex + 1);
        for (int i = 0; i < fractionalPartLength; i++) {
            if (binary[decimalPointIndex + 1 + i] == '1') {
                decimal += pow(base, -1 * (i + 1));
            }
        }
    }
    
    return decimal;
}

// Function to convert decimal to binary
std::string decimalToBinary(int decimal) {
    std::string binary = "";
    while (decimal > 0) {
        binary = std::to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Function to convert decimal fraction to binary fraction
std::string decimalFractionToBinary(double fraction) {
    std::string binary = ".";
    int maxDigits = 5; // Maximum number of digits after the decimal point
    
    while (fraction > 0 && binary.length() <= maxDigits + 1) {
        fraction *= 2;
        binary += std::to_string(static_cast<int>(fraction));
        fraction -= static_cast<int>(fraction);
    }
    return binary;
}

// Function to convert decimal to octal
std::string decimalToOctal(int decimal) {
    std::string octal = "";
    while (decimal > 0) {
        octal = std::to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

// Function to convert decimal fraction to octal fraction
std::string decimalFractionToOctal(double fraction) {
    std::string octal = ".";
    int maxDigits = 5; // Maximum number of digits after the decimal point
    
    while (fraction > 0 && octal.length() <= maxDigits + 1) {
        fraction *= 8;
        int intPart = static_cast<int>(fraction);
        octal += std::to_string(intPart);
        fraction -= intPart;
    }
    return octal;
}

// Function to convert decimal to hexadecimal
std::string decimalToHexadecimal(int decimal) {
    std::string hexadecimal = "";
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal = std::to_string(remainder) + hexadecimal;
        } else {
            hexadecimal = char('A' + remainder - 10) + hexadecimal;
        }
        decimal /= 16;
    }
    return hexadecimal;
}

// Function to convert decimal fraction to hexadecimal fraction
std::string decimalFractionToHexadecimal(double fraction) {
    std::string hexadecimal = ".";
    int maxDigits = 5; // Maximum number of digits after the decimal point
    
    while (fraction > 0 && hexadecimal.length() <= maxDigits + 1) {
        fraction *= 16;
        int intPart = static_cast<int>(fraction);
        char digit = (intPart < 10) ? ('0' + intPart) : ('A' + intPart - 10);
        hexadecimal += digit;
        fraction -= intPart;
    }
    return hexadecimal;
}

std::string decimalTo(std::string input)
{
    std::istringstream iss(input);
    double decimalNumber;
    int base;
    char comma;
    if (!(iss >> decimalNumber >> comma >> base) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }
    std::string binary = decimalToBinary(static_cast<int>(decimalNumber));
    std::string binaryResult = binary;
    if (decimalNumber != static_cast<int>(decimalNumber)) {
        std::string binaryFraction = decimalFractionToBinary(decimalNumber - static_cast<int>(decimalNumber));
        binaryResult += binaryFraction;
    }

    // Convert to octal
    std::string octal = decimalToOctal(static_cast<int>(decimalNumber));
    std::string octalResult = octal;
    if (decimalNumber != static_cast<int>(decimalNumber)) {
        std::string octalFraction = decimalFractionToOctal(decimalNumber - static_cast<int>(decimalNumber));
        octalResult += octalFraction;
    }

    // Convert to hexadecimal
    std::string hexadecimal = decimalToHexadecimal(static_cast<int>(decimalNumber));
    std::string hexadecimalResult = hexadecimal;
    if (decimalNumber != static_cast<int>(decimalNumber)) {
        std::string hexadecimalFraction = decimalFractionToHexadecimal(decimalNumber - static_cast<int>(decimalNumber));
        hexadecimalResult += hexadecimalFraction;
    }
    switch(base)
        {
            case 10:
                return std::to_string(decimalNumber);
            case 2:
                return binaryResult;
            case 8:
                return octalResult;
            case 16:
                return hexadecimalResult;
            default:
            return("Base not matched");
    
}
}
std::string binaryto(std::string input)
{
    std::istringstream iss(input);
    double binaryNumber;
    int base;
    char comma;
    if (!(iss >> binaryNumber >> comma >> base) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }
    if (!isBinary(std::to_string(binaryNumber))) {
        return("Base not matched");
    }


    double decimalNumber = binaryToDecimal(std::to_string(binaryNumber));
    switch(base)
        {
            case 2:
                return (std::to_string(binaryNumber));
            case 10:
                return (std::to_string(decimalNumber));
            case 8:
                return decimalTo(std::to_string(decimalNumber)+",8");
            case 16:
                return decimalTo(std::to_string(decimalNumber)+",16");
            default:
                return("Base not matched");
    
}
}
std::string octalto(std::string input)
{
    std::istringstream iss(input);
    double octalNumber;
    int base;
    char comma;
    if (!(iss >> octalNumber >> comma >> base) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }
    if (!isOctal(std::to_string(octalNumber))) {
        return("Base not matched1");
    }


    double decimalNumber = octalToDecimal(std::to_string(octalNumber));
    switch(base)
        {
            case 2:
                return decimalTo(std::to_string(decimalNumber)+",2");
            case 10:
                return (std::to_string(decimalNumber));
            case 8:
                return (std::to_string(octalNumber));
            case 16:
                return decimalTo(std::to_string(decimalNumber)+",16");
            default:
                return("Base not matched");
    
}
}

std::string hexato(std::string input)
{
    std::istringstream iss(input);
    double hexaNumber;
    int base;
    char comma;
    if (!(iss >> hexaNumber >> comma >> base) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }
    if (!isOctal(std::to_string(hexaNumber))) {
        return("Base not matched1");
    }


    double decimalNumber = octalToDecimal(std::to_string(hexaNumber));
    switch(base)
        {
            case 2:
                return decimalTo(std::to_string(decimalNumber)+",2");
            case 10:
                return (std::to_string(decimalNumber));
            case 8:
                return decimalTo(std::to_string(decimalNumber)+",8");
            case 16:
                return (std::to_string(hexaNumber));
            default:
                return("Base not matched");
    
}
}
// int main()
// {
//     std::cout<<binaryto("8,3");
// }
#include <iostream>
#include <cmath>
#include <sstream>
#include<string>

double calculateLogWithBase(double base, double number) {
    return log(number) / log(base);
}

std::string base_log(std::string input) {
    // Parse the input string to extract base and number
    std::istringstream iss(input);
    double base, number;
    char comma;
    if (!(iss >> base >> comma >> number) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }

    if (base <= 0 || number <= 0) {
        return "Negative not allowed";
    }

    // Calculate and return the logarithm result as a string
    // base=evaluateExpression(to_string(base));
    // number=evaluateExpression(to_string(number));
    double result = calculateLogWithBase(base, number);
    return std::to_string(result);
}

std::string inverse(std::string input) {
    // Parse the input string to extract base and number
    std::istringstream iss(input);
    double base, number;
    char comma;
    if (!(iss >> base >> comma >> number) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }

    // Calculate and return the logarithm result as a string
    double result = 1.0 / std::pow(base, number);
    std::cout<<result;
    return std::to_string(result);
}

std::string root(std::string input) {
    // Parse the input string to extract base and number
    std::istringstream iss(input);
    double base, number;
    char comma;
    if (!(iss >> base >> comma >> number) || comma != ',' || iss >> comma) {
        return("Syntax error");
    }

    // Calculate and return the logarithm result as a string
    double result = pow(base, 1.0 / number);
    std::cout<<result;
    return std::to_string(result);
}

// int main()
// {
//     std::cout<<base_log("9,0");
// }
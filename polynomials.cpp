#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

std::string roots(const std::string& input1,int x) {
    std::string input=input1;

    size_t pos = input.find('~');
    if (pos != std::string::npos) {
        input.replace(pos, 1, "-");
    }

    double a, b, c;
    
    // Parse coefficients from input string
    std::istringstream iss(input);
    char comma;
    if (!(iss >> a >> comma >> b >> comma >> c) || comma != ',' || iss >> comma) {
        return "Syntax error";
    }

    double discriminant = b * b - 4 * a * c;
    std::ostringstream oss;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        oss << std::fixed << std::setprecision(2) << root1 << "," << root2;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        oss << std::fixed << std::setprecision(2) << root;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        oss << std::fixed << std::setprecision(2) << realPart << "+" << imaginaryPart << "i,"
            << realPart << "-" << imaginaryPart << "i";
    }

    return oss.str();
}
std::string roots(const std::string& input1,char xx) {

    std::string input=input1;

    size_t pos = input.find('~');
    if (pos != std::string::npos) {
        input.replace(pos, 1, "-");
    }

    double a, b, c, d;

    // Parse coefficients from input string
    std::istringstream iss(input);
    char comma;
    if (!(iss >> a >> comma >> b >> comma >> c >> comma >> d) || comma != ',' || iss >> comma) {
        return "Syntax error";
    }

    // Calculate cubic roots using Cardano's formula
    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

    double discriminant = q * q / 4 + p * p * p / 27;

    if (discriminant > 0) {
        // One real root and two complex conjugate roots
        double root = -q / 2 + sqrt(discriminant);
        root = (root < 0) ? -cbrt(-root) : cbrt(root);
        double realPart = -b / (3 * a);
        double complexPart = sqrt(3) * root / (3 * a);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << root + realPart << "+"
            << complexPart << "i," << root + realPart << "-"
            << complexPart << "i," << root + realPart;
        return oss.str();
    } else if (discriminant == 0) {
        // Three real and equal roots
        double root = -q / 2;
        root = (root < 0) ? -cbrt(-root) : cbrt(root);
        double realPart = -b / (3 * a);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << root + realPart;
        return oss.str();
    } else {
        // Three real and distinct roots
        double root = sqrt(-p / 3);
        double angle = acos(-q / (2 * root * root * root));
        double realPart = -b / (3 * a);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << 2 * root * cos(angle / 3) + realPart << ","
            << 2 * root * cos((angle + 2 * M_PI) / 3) + realPart << ","
            << 2 * root * cos((angle + 4 * M_PI) / 3) + realPart;
        return oss.str();
    }
}
// int main()
// {
//     std::cout<<roots("1,9,10",1);
// }
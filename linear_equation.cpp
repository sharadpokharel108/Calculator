#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

std::string solve(const std::string& input1,int abc) {
    std::string input=input1;

    size_t pos = input.find('~');
    if (pos != std::string::npos) {
        input.replace(pos, 1, "-");
    }
    std::istringstream iss(input);
    double a1, b1, c1, a2, b2, c2;
    char comma;

    if (!(iss >> a1 >> comma >> b1 >> comma >> c1 >> comma >> a2 >> comma >> b2 >> comma >> c2) || comma != ',' || iss >> comma) {
        return "Syntax error";
    }

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        return "Infinite solutions"; // System has infinitely many solutions
    }

    double x = (c1 * b2 - c2 * b1) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;

    std::ostringstream oss;
    oss << "x = " << std::fixed << std::setprecision(2) << x << ", y = " << y;

    return oss.str();
}

std::string solve(const std::string& input1,char ab) {
    std::string input=input1;

    size_t pos = input.find('~');
    if (pos != std::string::npos) {
        input.replace(pos, 1, "-");
    }
    std::istringstream iss(input);
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    char comma;

    if (!(iss >> a1 >> comma >> b1 >> comma >> c1 >> comma >> d1 >> comma >> a2 >> comma >> b2 >> comma >> c2 >> comma >> d2 >> comma >> a3 >> comma >> b3 >> comma >> c3 >> comma >> d3) || comma != ',' || iss >> comma) {
        return "Syntax error";
    }

    double determinant = a1 * (b2 * c3 - c2 * b3) - b1 * (a2 * c3 - c2 * a3) + c1 * (a2 * b3 - b2 * a3);

    if (determinant == 0) {
        return "Infinite solutions"; // System has infinitely many solutions
    }

    double x = (d1 * (b2 * c3 - c2 * b3) - b1 * (d2 * c3 - c2 * d3) + c1 * (d2 * b3 - b2 * d3)) / determinant;
    double y = (a1 * (d2 * c3 - c2 * d3) - d1 * (a2 * c3 - c2 * a3) + c1 * (a2 * d3 - d2 * a3)) / determinant;
    double z = (a1 * (b2 * d3 - d2 * b3) - b1 * (a2 * d3 - d2 * a3) + d1 * (a2 * b3 - b2 * a3)) / determinant;

    std::ostringstream oss;
    oss << "x = " << std::fixed << std::setprecision(2) << x << ", y = " << y << ", z = " << z;

    return oss.str();
}

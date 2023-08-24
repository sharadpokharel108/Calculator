#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

std::string solvematrix(const std::string& input1) {
    std::string input=input1;

    size_t pos = input.find('~');
    if (pos != std::string::npos) {
        input.replace(pos, 1, "-");
    }
    // Parse coefficients from input string
    std::istringstream iss(input);
    char comma;
    double a, b, c, d, e, f, g, h, i;
    if (!(iss >> a >> comma >> b >> comma >> c >> comma >> d >> comma >> e >> comma >> f >> comma >> g >> comma >> h >> comma >> i) || comma != ',' || iss >> comma) {
        return "Syntax error";
    }

    // Calculate determinant and inverse
    double determinant = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    double inv_a, inv_b, inv_c, inv_d, inv_e, inv_f, inv_g, inv_h, inv_i;

    if (determinant != 0) {
        inv_a = (e * i - f * h) / determinant;
        inv_b = (c * h - b * i) / determinant;
        inv_c = (b * f - c * e) / determinant;
        inv_d = (f * g - d * i) / determinant;
        inv_e = (a * i - c * g) / determinant;
        inv_f = (c * d - a * f) / determinant;
        inv_g = (d * h - e * g) / determinant;
        inv_h = (b * g - a * h) / determinant;
        inv_i = (a * e - b * d) / determinant;

        std::ostringstream oss;
        oss << "Determinant: " << determinant<<std::endl;
        oss << "Inverse: ";
        oss << std::fixed << std::setprecision(2)
            <<""<< inv_a << "\t\t" << inv_b << "\t\t" << inv_c << std::endl
            <<"\t\t\t\t\t\t\t\t"<< inv_d << "\t\t" << inv_e << "\t\t" << inv_f << std::endl
            <<"\t\t\t\t\t\t\t\t"<< inv_g << "\t\t" << inv_h << "\t\t" << inv_i;
        return oss.str();
    } else {
        return "Determinant: " + std::to_string(determinant) + "\nInverse not possible.";
    }
}


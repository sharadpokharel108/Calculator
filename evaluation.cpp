#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include<vector>
#include <sstream>
#include <iomanip>
#include"hcf_lcm.cpp"
#include"check_syntax.cpp"
#include"log_inverse_root.cpp"
#include"Numbers.cpp"
#include"polynomials.cpp"
#include"linear_equation.cpp"

#include"matrix.cpp"
using namespace std;
bool extra=false;

bool checkdigit(std::string input) {
    return (input.find(',') != std::string::npos) ? 0 : 1;
}

std::string formatDouble(double value);
int precision;

float inrad(float degree)
{
    return (M_PI/180)*degree;
}
const double rad2deg = 180.0 / M_PI;



bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'||c=='%';
}

bool isFunction(const string& token) {
    return token == "sin" || token == "cos" || token == "tan" || token == "sqrt";
}

int getOperatorPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/'||op=='%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return (int(a)%int(b));
        case '^': return pow(a, b);
        default: return 0.0;
    }
}

double evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> operators;

    map<string, double (*)(double)> functions = {
        {"sin", sin},
        {"cos", cos},
        {"tan", tan},
        {"sqrt", sqrt}
    };

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isdigit(c) || c == '.') {
            string numStr;
            while (i < expression.size() && (isdigit(c) || c == '.')) {
                numStr += c;
                c = expression[++i];
            }
            values.push(stod(numStr));
            i--; // Move back one step
        } else if (isalpha(c)) {
            string funcName;
            while (i < expression.size() && isalpha(c)) {
                funcName += c;
                c = expression[++i];
            }
            i--; // Move back one step
            if (isFunction(funcName) && expression[i + 1] == '(') {
                operators.push('(');
                for (char funcChar : funcName) {
                    operators.push(funcChar);
                }
            }
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                if (isFunction(string(1, operators.top()))) {
                    string funcName;
                    while (!operators.empty() && isalpha(operators.top())) {
                        funcName = operators.top() + funcName;
                        operators.pop();
                    }
                    operators.pop(); // Pop '('
                    double val = values.top(); values.pop();
                    values.push(functions[funcName](val));
                } else {
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    char op = operators.top(); operators.pop();
                    values.push(applyOperator(a, b, op));
                }
            }
            operators.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && getOperatorPrecedence(operators.top()) >= getOperatorPrecedence(c)) {
                if (isFunction(string(1, operators.top()))) {
                    string funcName;
                    while (!operators.empty() && isalpha(operators.top())) {
                        funcName = operators.top() + funcName;
                        operators.pop();
                    }
                    double val = values.top(); values.pop();
                    values.push(functions[funcName](val));
                } else {
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    char op = operators.top(); operators.pop();
                    values.push(applyOperator(a, b, op));
                }
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        if (isFunction(string(1, operators.top()))) {
            string funcName;
            while (!operators.empty() && isalpha(operators.top())) {
                funcName = operators.top() + funcName;
                operators.pop();
            }
            double val = values.top(); values.pop();
            values.push(functions[funcName](val));
        } else {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            char op = operators.top(); operators.pop();
            values.push(applyOperator(a, b, op));
        }
    }

    return values.top();
}





string trigno(string trig,string check)
{
    string changed;
    float value;
    std::vector<std::string> endElements = {")"};
    while(1)
    {
        size_t startPos = trig.find(check);
        size_t nearestEndPos = std::string::npos;

        for (const std::string& endElement : endElements) {
            size_t endPos = trig.find(endElement, startPos + check.length());
            if (endPos != std::string::npos && (nearestEndPos == std::string::npos || endPos < nearestEndPos)) {
                nearestEndPos = endPos;
            }
        }

        if (startPos != std::string::npos && nearestEndPos != std::string::npos && startPos < nearestEndPos) {
            startPos += check.length(); // Move past the start element
            std::string extractedSubstring = trig.substr(startPos, nearestEndPos - startPos);
            if(extractedSubstring=="")
                return ("Syntax error");
            if(check=="sin(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=inrad(evaluateExpression(extractedSubstring));
                changed=std::to_string(sin(value));
            }
            if(check=="cos(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=inrad(evaluateExpression(extractedSubstring));
                changed=std::to_string(cos(value));
            }
            if(check=="tan(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=inrad(evaluateExpression(extractedSubstring));
                changed=std::to_string(tan(value));
            }
            if(check=="sin~(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(asin(value)*rad2deg);
            }
            if(check=="cos~(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(acos(value)*rad2deg);
            }
            if(check=="tan~(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(atan(value)*rad2deg);
            }
            if(check=="ln(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(log(value));
            }
            if(check=="log(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(log10(value));
            }
            if(check=="sqrt(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(sqrt(value));
            }
            if(check=="lcm(")
            {
                value=hcf_lcm("lcm",extractedSubstring);
                changed=std::to_string(value);
            }
            if(check=="hcf(")
            {
                value=hcf_lcm("hcf",extractedSubstring);
                changed=std::to_string(value);
            }
            if(check=="sinh(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(sinh(value));
            }
            if(check=="cosh(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(cosh(value));
            }
            if(check=="tanh(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(tanh(value));
            }
            if(check=="sinh~(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(asinh(value));
            }
            if(check=="cosh~(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(acosh(value));
            }
            if(check=="tanh~(")
            {
                if(!checkdigit(extractedSubstring))
                    return ("Syntax error");
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(atanh(value));
            }
            if(check=="fact(")
            {
                value=evaluateExpression(extractedSubstring);
                changed=std::to_string(tgamma(value+1));
            }
            if(check=="logb(")
            {
                changed=base_log(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
            }
            if(check=="in(")
            {
                changed=inverse(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
            }
            if(check=="root(")
            {
                changed=root(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
            }
            if(check=="DEC(")
            {
                changed=decimalTo(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
                else if (changed=="Base not matched")
                {
                    return("Base not matched");
                }
            }
            if(check=="BIN(")
            {
                changed=binaryto(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
                else if (changed=="Base not matched")
                {
                    return("Base not matched");
                }
            }
            if(check=="OCT(")
            {
                changed=octalto(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
                else if (changed=="Base not matched")
                {
                    return("Base not matched");
                }
            }
            if(check=="HEX(")
            {
                changed=hexato(extractedSubstring);
                if(changed=="Syntax error")
                {
                    return("Syntax error");
                }
                else if (changed=="Base not matched")
                {
                    return("Base not matched");
                }
            }
            if(check=="Quad(")
            {
                extra=true;
                changed=roots(extractedSubstring,1);
                return changed;
            }
            if(check=="Cubic(")
            {
                extra=true;
                changed=roots(extractedSubstring,'a');
                return changed;
            }
            if(check=="Eqn2(")
            {
                extra=true;
                changed=solve(extractedSubstring,2);
                return changed;
            }
            if(check=="Eqn3(")
            {
                extra=true;
                changed=solve(extractedSubstring,'3');
                return changed;
            }
            if(check=="Matrix(")
            {
                extra=true;
                changed=solvematrix(extractedSubstring);
                return changed;
            }
            trig.replace(startPos-check.length(), nearestEndPos - startPos+check.length()+1, changed);
        } else {
            break;
        }
    }
    return trig;
}




string equalsto(string expression,const int n=4)
{
    extra=false;
    precision=n;
    string evaluate;
    if(check(expression)=="Right")
    {
    }
    else
    {
        return(check(expression));
    }
    evaluate=trigno(expression,"sin(");
    evaluate=trigno(evaluate,"tan(");
    evaluate=trigno(evaluate,"cos(");
    evaluate=trigno(evaluate,"sin~(");
    evaluate=trigno(evaluate,"tan~(");
    evaluate=trigno(evaluate,"cos~(");
    evaluate=trigno(evaluate,"ln(");
    evaluate=trigno(evaluate,"log(");
    evaluate=trigno(evaluate,"sqrt(");
    evaluate=trigno(evaluate,"lcm(");
    evaluate=trigno(evaluate,"hcf(");
    evaluate=trigno(evaluate,"sinh(");
    evaluate=trigno(evaluate,"cosh(");
    evaluate=trigno(evaluate,"tanh(");
    evaluate=trigno(evaluate,"sinh~(");
    evaluate=trigno(evaluate,"cosh~(");
    evaluate=trigno(evaluate,"tanh~(");
    evaluate=trigno(evaluate,"fact(");

    evaluate=trigno(evaluate,"logb(");
    if(evaluate=="Syntax error")
    return("Syntax error");

    evaluate=trigno(evaluate,"in(");
    if(evaluate=="Syntax error")
    return("Syntax error");

    evaluate=trigno(evaluate,"root(");
    if(evaluate=="Syntax error")
    return("Syntax error");

    evaluate=trigno(evaluate,"DEC(");
    if(evaluate=="Syntax error")
        return("Syntax error");
    else if(evaluate=="Base not matched")
        return ("Base not matched");

    evaluate=trigno(evaluate,"BIN(");
    if(evaluate=="Syntax error")
        return("Syntax error");
    else if(evaluate=="Base not matched")
        return ("Base not matched");

    evaluate=trigno(evaluate,"OCT(");
    if(evaluate=="Syntax error")
        return("Syntax error");
    else if(evaluate=="Base not matched")
        return ("Base not matched");

    evaluate=trigno(evaluate,"HEX(");
    if(evaluate=="Syntax error")
        return("Syntax error");
    else if(evaluate=="Base not matched")
        return ("Base not matched");
    
    evaluate=trigno(evaluate,"Quad(");
    evaluate=trigno(evaluate,"Cubic(");
    evaluate=trigno(evaluate,"Eqn2(");
    evaluate=trigno(evaluate,"Eqn3(");
    evaluate=trigno(evaluate,"Matrix(");
    if(extra)
        return evaluate;
    double result=evaluateExpression(evaluate);
    return formatDouble(result);

}



std::string formatDouble(double value) {
    std::ostringstream stream;
    stream << std::fixed;
    stream << std::setprecision(precision); // You can adjust the precision as needed

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

// int main()
// {
//     std::cout<<equalsto("Quad(2,3,4)",23);
// }
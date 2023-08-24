#include <iostream>
#include <stack>
#include <string>

bool isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/'||c==','||c=='^';
}

bool isNumeric(char c) {
    return c >= '0' && c <= '9';
}

std::string isValidExpression(const std::string& expression) {
    std::stack<char> bracketStack;
    char prevChar = '\0';  // Initialize to a non-operator/non-numeric character
    bool decimalUsed = false;

    for (char c : expression) {
        if (c == '(') {
            bracketStack.push(c);
        } else if (c == ')') {
            if (bracketStack.empty() || bracketStack.top() != '(') {
                return("Syntax error");
                
            }
            bracketStack.pop();
        } else if (isoperator(c)) {
            if (prevChar == '\0' || isoperator(prevChar)) {
                return("Syntax error");
                
            }
            decimalUsed = false;  // Reset decimal usage flag for a new operand
        } else if (c == '.') {
            if (prevChar == '\0' || !isNumeric(prevChar) || decimalUsed) {
                return("Syntax error");
                
            }
            decimalUsed = true;
        }  else {
            decimalUsed = false;  // Reset decimal usage flag for a new operand
        }

        prevChar = c;
    }

    if (!bracketStack.empty()) {
        return("Syntax error");
        
    }

    // Check if the last character is an operator or a decimal point
    if (isoperator(prevChar) || prevChar == '.') {
        return("Syntax error");
    }
    return("Right");
}

std::string check(std::string expression)
{
    // Validate the expression
    return(isValidExpression(expression)) ;
}


// int main()
// {
//     std::cout<<check("5666.66.6");
// }
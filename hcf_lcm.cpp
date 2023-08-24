#include <iostream>
#include <vector>
#include <sstream>
#include<string>

// Function to find the HCF of two numbers using Euclidean algorithm
int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the LCM of two numbers using HCF
int findLCM(int a, int b) {
    return (a * b) / findHCF(a, b);
}

// Function to find the HCF of multiple numbers
int findHCFOfMultiple(const std::vector<int>& numbers) {
    int hcf = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        hcf = findHCF(hcf, numbers[i]);
    }
    return hcf;
}

// Function to find the LCM of multiple numbers
int findLCMOfMultiple(const std::vector<int>& numbers) {
    int lcm = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        lcm = findLCM(lcm, numbers[i]);
    }
    return lcm;
}

int hcf_lcm(std::string what,std::string input){
    std::vector<int> numbers;
    int num;
    
    std::istringstream stream(input);
    while (stream >> num) {
        numbers.push_back(num);
        if (stream.peek() == ',') {
            stream.ignore();
        }
    }
    
    if(what=="hcf")
        return findHCFOfMultiple(numbers);
    if(what=="lcm")
        return findLCMOfMultiple(numbers);

    return 0;
}
// int main()
// {
//     std::cout<<hcf_lcm("lcm","12,18");
// }

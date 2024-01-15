// Develop a calculator program that performs basic arithmetic
// operations such as addition, subtraction, multiplication, and
// division. Allow the user to input two numbers and choose an
// operation to perform.
 
#include <iostream>

int main() {
    char anotherOperation;

    do {
        double num1, num2;
        char operation;

        // Get user input
        std::cout << "Enter first number: ";
        std::cin >> num1;

        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Get the arithmetic operation
        std::cout << "Choose an operation (+, -, *, /): ";
        std::cin >> operation;

        // Perform the selected operation
        switch (operation) {
            case '+':
                std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
                break;
            case '-':
                std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
                break;
            case '*':
                std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
                break;
            case '/':
                if (num2 != 0) {
                    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Cannot divide by zero." << std::endl;
                }
                break;
            default:
                std::cout << "Invalid operation. Please choose +, -, *, or /." << std::endl;
                break;
        }

        // Ask if the user wants to perform another operation
        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> anotherOperation;

    } while (anotherOperation == 'y' || anotherOperation == 'Y');

    std::cout << "Calculator closed. Goodbye!" << std::endl;

    return 0;
}

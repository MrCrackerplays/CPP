#include <iostream>
#include <stack>
#include "RPN.hpp"

static bool	isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

RPN::RPN(const std::string string) : _string(string) {
	if (string.empty() || string.size() % 2 == 0) {
		std::cerr << "Error" << std::endl;
		exit(1);
	}
	int	opcount = 0;
	int	numcount = 0;
	for (std::string::size_type i = 0; i < string.size(); i++) {
		if (i % 2 == 0) {
			if (isOperator(string[i])) {
				opcount++;
			} else if (isdigit(string[i])) {
				numcount++;
			} else {
				std::cerr << "Error" << std::endl;
				exit(1);
			}
		} else if (string[i] != ' ') {
			std::cerr << "Error" << std::endl;
			exit(1);
		}
	}
	if (opcount != numcount - 1) {
		std::cerr << "Error" << std::endl;
		exit(1);
	}
}

RPN::~RPN(void) {}

void	RPN::solve(void) const {
	std::stack<int>	stack;
	for (std::string::size_type i = 0; i < _string.size(); i += 2) {
		if (isdigit(_string[i])) {
			stack.push(_string[i] - '0');
		} else {
			if (stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			int	b = stack.top();
			stack.pop();
			int	a = stack.top();
			stack.pop();
			switch (_string[i]) {
			case '+':
				a += b;
				break;
			case '-':
				a -= b;
				break;
			case '*':
				a *= b;
				break;
			case '/':
				a /= b;
				break;
			
			default:
				std::cerr << "Error" << std::endl;
				exit(1);
				break;
			}
			stack.push(a);
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		exit(1);
	}
	std::cout << stack.top() << std::endl;
}

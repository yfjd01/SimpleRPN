//RPN CALCULATOR

#include <stack>
#include <iostream>
#include <string>

#include <sstream>


using namespace std;

bool isOperator(const string& input);
void performOp(const string& input, stack<double>& calcStack);


int main()
{
	stack<double> calcStack;
	string input;
	
	
	while(true)
	{
		//display prompt
		cout << ">>";
		//get input
		cin >> input;
		
		//check for numeric value
		double num;
		
		if(istringstream(input) >> num)
		{
			calcStack.push(num);
		}
		
		//check for operator
		else if(isOperator(input))
		{
			performOp(input, calcStack);
		}
		//check for quit
		else if(input == "q")
		{
		
		//invalid output
			cout << "Invalid input" << endl;
		}
	}
}



bool isOperator(const string& input)
{
	string ops[] ={"-","+","*","/"};

	for(int i = 0; i < 4; i++)
	{
		if(input == ops[i])
		{
			return true;
		}
	}
		return false;
}

void performOp(const string& input, stack<double>& calcStack)
{
	
	double lVal, rVal, result;
	
	string op = input;

	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

	if (input == "-")
	{
		result = lVal - rVal;
	
	}else if (input == "+")
	{
		result = lVal + rVal;
	
	}else if (input == "*")
	{
		result = lVal * rVal;
	
	}else if (input == "/")
	{
		result = lVal / rVal;
	
	}
	
	cout << result << endl;
	calcStack.push(result);
}

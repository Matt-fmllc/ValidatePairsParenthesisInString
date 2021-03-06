// ValidatePairsParenthesisInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <stack>

const char Token1 = '(';
const char Token2 = ')';

bool DetermineMatchingBraces(char* pInputStr)
{
	std::stack<char> cStack;
	int x = 0;

	printf("\nInput String = %s", pInputStr);

	while (pInputStr[x] != '\0') {
		if (pInputStr[x] == Token1) {
			cStack.push(Token1);
		}
		else if (pInputStr[x] == Token2) {
			// poping from empty stack means no match possible
			// illegal condition, TOKEN2 comes before TOKEN1
			if (cStack.empty()) {
				return false;
			}
			cStack.pop();
		}
		x++;
	}

	if (cStack.size() > 0) {
		return false;
	}

	return true;

}

int main()
{
	char pString1[] = "(abcd)((da3fda)(234234d))";
	char pString2[] = "(abcd)((da3fda)(234234d)";
	char pString3[] = "(abcd)((da3fda)(234234d)))";
	char pString4[] = "(abcd)((da3fda)(234234d))(";

	if (DetermineMatchingBraces(pString1)) {
		printf("\nString has matching braces");
	}
	else {
		printf("\nString does NOT have matching braces");
	}

	if (DetermineMatchingBraces(pString2)) {
		printf("\nString has matching braces");
	}
	else {
		printf("\nString does NOT have matching braces");
	}

	if (DetermineMatchingBraces(pString3)) {
		printf("\nString has matching braces");
	}
	else {
		printf("\nString does NOT have matching braces");
	}

	if (DetermineMatchingBraces(pString4)) {
		printf("\nString has matching braces");
	}
	else {
		printf("\nString does NOT have matching braces");
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

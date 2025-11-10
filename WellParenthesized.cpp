#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool parethesized(string exp) {
    stack<char> s;

    for (int i = 0; i < exp.length(); i++) 
	{
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']')
		 {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();

            if ((c == ')' && top != '(') || 
				(c == '}' && top != '{') ||
			 	(c == ']' && top != '['))
            {
            	 return false;
			}
               
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;

    if (parethesized(exp))
        cout << "Expression is well parenthesized.\n";
    else
        cout << "Expression is NOT well parenthesized.\n";

    return 0;
}


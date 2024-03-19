/*
Assignment 2 Task 3 Section S15, 16

Name: Mohamed Ayman Afifi
ID: 20230618
Make the regex and tern it into vector
____________________________

Name: Mahmoud Fathy Mohamed
ID:20230375
Make the functions (add, gcd, mult) and call them in the main when
the user enter which operation.
___________________________

Name: Menna Mohamed Hekal
ID: 20230422
Make the loop, check user input, and the error cases
___________________________
SudoCode:
1-make function gcd to simplify all fraction by division on greatest commen divisor.
2- function mult to make multiblication
    2.1 declare numerator and denumerator as integer
    2.2 make num = num1 *num3 and den = num2 * num4 witch i will take from user.
    2.3 call function gcd to simplify and return the result to print.
3- make add function for addition.
4- make sub function for subtraction.
5- print welcome message and ask the user if he want to make an operation or exit.
6- take user choice and if he want an operation take it from him.
7- make regex to store the input.
8- declare the valid operation, and if he enter invalid one print erroe.
9- declare oper = the index5 in regex.
    9.1 if oper = "+" call add function
    9.2 if oper = "*" call mult function
    9.3 if oper = "-" call sub function
    9.4 and if oper = "/" call mult function but swap the second num and den.
10- if user enter a fraction divied by zero make an error and let him enter again.
11- if user enter exit stop the program.
12- if he enter anything else print error.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;


// Greatest common divisor to simplify fraction
int gcd(int num1, int num2)
 {
    if (num1 == 0 || num2 == 0)
        {
        return 1; //because i can't division by 0
        }
    int result = min(abs(num1), abs(num2));
    while (result > 0)
        {
        if (num1 % result == 0 && num2 % result == 0)
            {
            return result;
            }
        result--;
        }
    return 1;
}

//function for multiplication and division.
string mult(int num1, int num2, int num3, int num4)
 {

    int num = num1 * num3; //numerator
    int den = num2 * num4; //denumerator
    num *= den / abs(den);
    den *= den / abs(den);
    int div = gcd(num, den);
    return to_string(num / div) + "/" + to_string(den / div);

}

//for addition.
string add(int num1, int num2, int num3, int num4)
 {

    num1 *= num2 / abs(num2);
    num2 *= num2 / abs(num2);
    num3 *= num4 / abs(num4);
    num4 *= num4 / abs(num4);

    int num = num1 * num4 + num2 * num3;
    int den = num2 * num4;

    int div = gcd(num, den);

    if (den == div || num == 0)
        {
        return to_string(num / div);
        }
    else
        {
        return to_string(num / div) + "/" + to_string(den / div);
        }
}


int main() {
    while (true) {
        try {
            int choice;
            //welcome message
            cout << "Welcome to our fraction calculator\n Enter what you want to do: \n 1- make an operation\n 2- exit\n";
            cin >> choice; //take user's choice
            if (choice == 1) {
                string input;
                cin.ignore();
                getline(cin, input);

                input += '/';

                vector<int> nums;
                int operation = -1;
                bool flag = false;

                string current = "";

                for (int i = 0; i < input.size();i++) {
                    char c = input[i];
                    if (c == '-' && current.size() == 0) {
                        current += c;
                    }
                    else if (c >= '0' && c <= '9') {
                        current += c;
                    }
                    else if (c == '/' && input[i - 1] != ' ') {
                        //cout << current << endl;
                        nums.push_back(stoi(current));
                        current = "";
                    }
                    else if (input[i - 1] == ' ') {
                        if (operation == -1) {
                            //cout << current << endl;
                            nums.push_back(stoi(current));
                            current = "";
                            if (nums.size() == 1) {
                                nums.push_back(1);
                            }
                            if (c == '+')
                                operation = 0;
                            else if (c == '-')
                                operation = 1;
                            else if (c == '*')
                                operation = 2;
                            else if (c == '/')
                                operation = 3;
                            else {
                                //cout << "invalid operation" << endl;
                                flag = true;
                                break;
                            }
                        }
                    }
                    else if(c != ' '){
                        flag = true;
                        //cout << "error: " << c << endl;
                    }
                }

                if (nums.size() == 3) {
                    nums.push_back(1);
                }

                if (flag || nums.size() < 4) {
                    cout << "invalid input" << endl;
                    continue;
                }

                if (nums[1] == 0 || nums[3] == 0) { // make the case that the user enter an error
                    cout << "Error, You can not division by zero" << endl;
                    continue;
                }

                if (operation == 0) {
                    cout << add(nums[0], nums[1], nums[2], nums[3]) << endl;
                } else if (operation == 1) {
                    cout << add(nums[0], nums[1], -int(nums[2]), nums[3]) << endl;
                } else if (operation == 2) {
                    cout << mult(nums[0], nums[1], nums[2], nums[3]) << endl;
                } else if (operation == 3) {
                    if (nums[3] == 0) {
                        cout << "Error, Can't divide by 0\n";
                        continue;
                    }
                    cout << mult(nums[0], nums[1], nums[3], nums[2]) << endl;
                }

            } else if (choice == 2) {
                cout << "Goodbye! " << endl;
                break;  // Exit the loop
            } else {
                cout << "Invalid choice. Please enter 1 or 2." << endl; //  if user enter another num
            }

        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            cout << "Error!" << endl;
        }
    }

    return 0;
}

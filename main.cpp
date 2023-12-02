#include <iostream>
#include <string>
using namespace std;

int const MAXNUMINT = 13;
int const MAXNUMDIGIT = 12;

bool isInt(char c);
bool isValidInt(string s);
int getNumInt();
int charToInt(char c);
string getInt(int index);
string format(string num);
string add(string num1, string num2);
string multiply(string num1, string num2);
void productSteps(string steps[MAXNUMDIGIT], string num1, string num2);
void sumSteps(string integers[], int numInt, string sum);

int main()
{
    int numInt;
    string sum;
    string product;
    string integers[MAXNUMINT];

    cout << "The program adds 2 and up to 13 very large numbers accurately." << endl;
    cout << "It multiplies the first and last numbers and shows the intermidiate steps of the product." << endl;
    cout << "Enter '0' into the number of integers prompt to end the program." << endl << endl;

    do
    {
        numInt = getNumInt();

        if (numInt != 0)
        {
            for (int i = 0; i < numInt; i++)
            {
                integers[i] = getInt(i);
            }

            for (int i = 0; i < numInt; i++)
            {
                sum = add(sum, integers[i]);
            }

            sumSteps(integers, numInt, sum);
            cout << endl << "   " << format(sum) << endl << endl;
            product = multiply(integers[0], integers[numInt - 1]);
            cout << endl << "   " << format(product) << endl;

            cout << "Press any key to continue . . ." << endl;

            system("read -n 1 -s");

            cout << endl;
        }

    } while (numInt != 0);
}

/*---------------------------------------------------------
Takes an integer stored as a char and returns the integer 
equivalent
---------------------------------------------------------*/
int charToInt(char c)
{
  return (c - '0');
}

/*---------------------------------------------------------
Given a character, returns true if the character is an 
integer and false otherwise
---------------------------------------------------------*/
bool isInt(char c)
{
  return (c >= '0' && c <= '9');
}

/*---------------------------------------------------------
Takes two numbers stored in a string from highest index to 
lowest index and returns the sum
---------------------------------------------------------*/
string add(string num1, string num2)
{
    int carry = 0;
    int digitSum;
    string sum = "";

    while (num1.length() < num2.length())
    {
        num1 += "0";
    }

    while (num2.length() < num1.length())
    {
        num2 += "0";
    }

    for (int i = 0; i < num1.length(); i++)
    {
        digitSum = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = digitSum / 10;
        sum += to_string(digitSum % 10);
    }

    if (carry != 0)
    {
        sum += to_string(carry);
    }

    return sum;
}

/*---------------------------------------------------------
Takes two numbers stored in a string from highest index to 
lowest index and returns the product
---------------------------------------------------------*/
string multiply(string num1, string num2)
{
    int carry;
    int digitProduct;
    string product = "0";
    string tempProduct;
    string steps[MAXNUMDIGIT];

    for (int i = 0; i < num1.length(); i++)
    {
        tempProduct = "";
        carry = 0;

        for (int j = 0; j < num2.length(); j++)
        {
            digitProduct = (num1[i] - '0') * (num2[j] - '0') + carry;
            carry = digitProduct / 10;
            tempProduct = tempProduct + to_string(digitProduct % 10);
        }

        if (carry != 0)
        {
            tempProduct = tempProduct + to_string(carry);
        }

        tempProduct = string(i, '0') + tempProduct;
        steps[i] = format(tempProduct);
        product = add(product, tempProduct);
    }

    productSteps(steps, num1, num2);

    return product;
}

/*---------------------------------------------------------
Takes a number stored in a string from highest index to 
lowest index and returns the standard format with
commas
---------------------------------------------------------*/
string format(string num)
{
    int counter = 1;
    string formatted = "";

    for (int i = 0; i < num.length(); i++)
    {
        if (counter > 3)
        {
            formatted = "," + formatted;
            counter = 1;
        }

        formatted = num[i] + formatted;
        counter++;
    }

    return formatted;
}

/*---------------------------------------------------------
Takes an array of integers and prints them
out in right aligned format
---------------------------------------------------------*/
void sumSteps(string integers[], int numInt, string sum)
{
    int maxLength = format(sum).length();

    cout << "The sum of:" << endl << endl;

    for (int i = 0; i < numInt - 1; i++)
    {
        if (!integers[i].empty())
        {
            cout << string(maxLength - format(integers[i]).length() + 3, ' ') << format(integers[i]) << endl;
        }
    }

    cout << "+)" << string(maxLength - format(integers[numInt - 1]).length() + 1, ' ') << format(integers[numInt - 1]) << endl;
    cout << string(maxLength + 3, '-');
}

/*---------------------------------------------------------
Takes an array of multiplycation steps and prints them
out in right aligned format
---------------------------------------------------------*/
void productSteps(string steps[MAXNUMDIGIT], string num1, string num2)
{
    int maxLength = 0;

    num1 = format(num1);
    num2 = format(num2);

    for (int i = 0; i < MAXNUMDIGIT - 1; i++)
    {
        if (steps[i].length() > maxLength)
        {
          maxLength = steps[i].length();
        }
    }

    cout << "The product of:" << endl << endl;
    cout << string(maxLength - num1.length() + 3, ' ') << num1 << endl;
    cout << "*)" << string(maxLength - num2.length() + 1, ' ') << num2 << endl;
    cout << string(maxLength + 3, '-') << endl;

    for (int i = MAXNUMDIGIT; i > 0; i--)
    {
        if (!steps[i].empty())
        {
            cout << string(maxLength - steps[i].length() + 3, ' ') << steps[i] << endl;
        }
    }

    cout << "+)" << string(maxLength - steps[0].length() + 1, ' ') << steps[0] << endl;
    cout << string(maxLength + 3, '-');
}

/*---------------------------------------------------------
Asks the user for a valid integer and returns a valid
input stored backwards
---------------------------------------------------------*/
string getInt(int index)
{
    string input;
    string backwards;

    cout << "Input number #" << index + 1 << " -> ";
    cin >> input;

    do{

        if (!isValidInt(input))
        {
            cout << "That integer is invalid. Please try again -> ";
            cin >> input;
        }

    } while (!isValidInt(input));

    for (int i = input.length() - 1; i >= 0; i--)
    {
        backwards += input[i];
    }

    cout << endl;

    return backwards;
}

/*---------------------------------------------------------
Asks the user for the number of polynomials to be operated 
on and validates the input
---------------------------------------------------------*/
int getNumInt()
{
  int numInt;
  string input;
  bool valid;

  cout << "How many numbers? -> ";

  do 
  {
    numInt = 0;
    valid = true;

    cin >> input;
    //getline(cin, input);

    if (input.length() == 0 || input.length() > 2)
    {
      valid = false;
    }
    else
    {
      for (int i = 0; i < input.length(); i++)
      {
        if (!isInt(input[i]))
        {
          valid = false;
        }
        else
        {
          numInt = numInt * 10 + charToInt(input[i]);
        }
      }
    }

    if (numInt < 0 || numInt > MAXNUMINT || numInt == 1)
    {
      valid = false;
    }
    
    if (!valid)
    {
      cout << "Invalid number of integers. Please try again -> ";
    }

  } while (!valid);

  cout << endl;

  return numInt;
}

/*---------------------------------------------------------
Given a string, returns true if the string is a valid 
integer and false otherwise
---------------------------------------------------------*/
bool isValidInt(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isInt(s[i]) || s.length() > MAXNUMDIGIT)
        {
            return false;
        }
    }
    return true;
}

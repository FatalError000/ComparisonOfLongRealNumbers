#include <iostream>
using namespace std;

string TakeSecondPart(string number)
{
    string result = "";

    for (int i = number.length() - 1; i >= 0; i--)
    {
        if ((i == (number.length() - 1)) && (number[i] == '.'))
        {
            result += '0';
        }
        else
        {
            result = number[i] + result;
        }

        if (number[i] == '.')
        {
            return result;
        }
    }
}

string TakeFirstPart(string number)
{
    string result = "";

    for (int i = 0; i < number.length(); i++)
    {
        if ((i == 0) && (number[i] == '.'))
        {
            result += '0';
        }
        else
        {
            result += number[i];
        }
        
        if (number[i] == '.')
        {
            return result;
        }
    }
}

string LongRealNumberComparisonInDetail(string number1part, string number2part, int part)
{
    string result = "";

    if (part == 1)
    {
        if (number1part.length() > number2part.length())
        {
            return result = "More";
        }
        else if (number1part.length() < number2part.length())
        {
            return result = "Less";
        }
        else
        {
            for (int i = 0; i < number1part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            return result = "Equal";
        }
    }
    else // (part == 2)
    {
        if (number1part.length() > number2part.length()) // первое большей длины
        {
            for (int i = 0; i < number2part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            for (int i = number2part.length() - 1; i < number1part.length(); i++)
            {
                if (number1part[i] > '0')
                {
                    return result = "More";
                }
            }

            return result = "Equal";
        }
        else if (number1part.length() < number2part.length()) // второе большей длины
        {
            for (int i = 0; i < number1part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            for (int i = number1part.length() - 1; i < number2part.length(); i++)
            {
                if (number1part[i] > '0')
                {
                    return result = "More";
                }
            }

            return result = "Equal";
        }
        else // равная длина
        {
            for (int i = 0; i < number1part.length(); i++)
            {
                if (number1part[i] > number2part[i])
                {
                    return result = "More";
                }
                else if (number1part[i] < number2part[i])
                {
                    return result = "Less";
                }
            }

            return result = "Equal";
        }
    }
}

string LongRealNumberComparison(string firstNumber, string secondNumber)
{
    string result = "";

    result = LongRealNumberComparisonInDetail(TakeFirstPart(firstNumber), TakeFirstPart(secondNumber), 1);

    if (result != "Equal")
        return result;

    result = LongRealNumberComparisonInDetail(TakeSecondPart(firstNumber), TakeSecondPart(secondNumber), 2);

    return result;
}

int LongNumberValidation(string number)
{
    int counter = 0;

    if ((number[0] == '-') || (number[0] == '.')
        || ((number[0] >= '0') && (number[0] <= '9')))
    {
        if (((number[0] == '-') || (number[0] == '.'))
            && (number.length() == 1))
        {
            cout << "Число некорректно! Есть минус или точка, и при этом длина числа = один символ. Должна быть хоть одна цифра!";
            return 0;
        }

        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] == '.')
            {
                counter++;
            }
        }

        if (counter < 2)
        {
            for (int i = 1; i < number.length(); i++)
            {
                counter = 0;

                if (((number[i] < '0') || (number[i] > '9'))
                    && (number[i] != '.'))
                {
                    cout << "Число некорректно! Присутсвуют недопустимые символы. Символ " << number[i];
                    return 0;
                }
                else
                {
                    if ((number[1] == '.') && (number.length() == 2)
                        && ((number[0] == '-')))
                    {
                        cout << "Число некорректно! Должно быть хоть одно число!";
                        return 0;
                    }
                }
            }

            cout << "Число корректно!";
        }
        else
        {
            cout << "Число некорректно! В нём две точки, допустима лишь одна!";
            return 0;
        }
    }
    else
    {
        cout << "Число некорректно! Первый символ не '-' или '.' или число.";
        return 0;
    }

    return 1;
}

int main()
{
    string firstNumber, secondNumber;

    do
    {
      cout << "Enter first number\n";
      cin >> firstNumber;
    } while (LongNumberValidation(firstNumber) != 1);

    do
    {
      cout << "Enter second number\n";
      cin >> secondNumber;
    } while (LongNumberValidation(secondNumber) != 1);

    cout << LongRealNumberComparison(firstNumber, secondNumber);

    return 0;
}
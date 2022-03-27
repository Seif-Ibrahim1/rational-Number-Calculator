// Program Name: ratonalNumberCalculator.cpp
// Program Description: take two rational numbers from the user and get the sum, subtraction, divison or multiplication of them as the user typed 
// Last Modification Date: 23/03/2022
// Author: Seif Ibrahim Ramadan
// Purpose: calculate mathmatic operations with rational numbers

#include <iostream>
using namespace std;

// decalring important functions
void get_fractions(string&, string&, string&, string&, string&, string&);
void sum(string&, string&, string&, string&, int&, int&);
void sub(string&, string&, string&, string&, int&, int&);
void mul(string&, string&, string&, string&, int&, int&);
void div(string&, string&, string&, string&, int&, int&);
void reset(string&, string&, string&, string&);
void simplize(int&, int&);
bool is_valid(string&, string&, string&);
bool valid_result(int&);


int main()
{
    cout << "Welcome to our rational numbers calculator ! " << endl;
    cout << endl;
    
    // initializing variables, n1 = numerator1 and d1 = denominator1 .. etc
    string input;
    string n1 = "";
    string d1 = "";
    string n2 = "";
    string d2 = "";
    string opreation;
    int index;
    int denominator;
    int numerator;

    // main program loop
    while (true)
    {
        cout << "Please enter a rational number operations (or exit): " << endl;
        cout << endl;

        // initializing and getting user input
        string fraction1 = "";
        string fraction2 = "";
        string operation = "";
        cin >> fraction1 >> operation >> fraction2; 

        // setting the input length into a variable

        // checking if user want to exit
        if (fraction1 == "exit")
        {
            cout << "Thanks for using our calculator, Good Bye !" << endl;
            break;
        }
        else
        {
            // checking if the input is valid
            if(is_valid(fraction1, operation, fraction2))
            {   
                // check if the opreation is sum
                if(operation == "+")
                {
                    // getting the fractions' numerator and denominator
                    get_fractions(fraction1, fraction2, n1, n2, d1, d2);

                    // adding the two fractions
                    sum(n1, n2, d1, d2, numerator, denominator);
                }

                // check if the opreation is subtract
                else if (operation == "-")
                {
                    // getting the fractions' numerator and denominator
                    get_fractions(fraction1, fraction2, n1, n2, d1, d2);

                    // subtracting the two fractions
                    sub(n1, n2, d1, d2, numerator, denominator);
                }

                // check if the opreation is multiply
                else if (operation == "*")
                {
                    // getting the fractions' numerator and denominator
                    get_fractions(fraction1, fraction2, n1, n2, d1, d2);

                    // multiplying the two fractions
                    mul(n1, n2, d1, d2, numerator, denominator);
                }

                // check if the opreation is divide
                else if (operation == "/")
                {
                    // getting the fractions' numerators and denominators
                    get_fractions(fraction1, fraction2, n1, n2, d1, d2);

                    // dividing the two fractions
                    div(n1, n2, d1, d2, numerator, denominator);
                }
            }

            else
                cout << "wrong input" << endl;

        } // end of the statments

        reset(n1, n2, d1, d2); // resetting the fractions' numerators and denominators

    } // end of the loop

} // end of the main function


void get_fractions(string& fraction1, string& fraction2, string& n1, string& n2, string& d1, string& d2)
{
    // the first half is the first numerator 
    bool firstHalf = true;

    // loop from the start till the end of fraction1
    for (int i = 0; i < fraction1.length(); i++)
    { 
        if (fraction1[i] == '/')
        {   
            // first half ends if there is a (/) 
            firstHalf = false;
            continue;
        }

        if(firstHalf)
            n1 += fraction1[i]; // add it to the numerator1

        else
            d1 += fraction1[i]; // add it to the denominator1
    }

    // here the first half is the second numerator 
    firstHalf = true;

    // loop from the start till the end of fraction2
    for (int i = 0; i < fraction2.length(); i++)
    { 
        if (fraction2[i] == '/')
        {
            // first half ends if there is a (/)
            firstHalf = false;
            continue;
        }

        if(firstHalf)
            n2 += fraction2[i]; // add it to the numerator2

        else
            d2 += fraction2[i]; // add it to the denominator2

    }
}


void sum(string& n1, string& n2, string& d1, string& d2, int& numerator, int& denominator)
{
    // check if the two denominator are equal 
    if (d1 == d2)
    {
        // the result denominator will be one of them
        denominator = stoi(d1);

        // the result numerator will be the sum of the two numerators
        numerator = stoi(n1) + stoi(n2);
    }
    else
    {
        // the result denominator will be the multiplication of the two denominators
        denominator = stoi(d1) * stoi(d2);

        // the result numerator will be the sum of (the first numertor * the second denominator) and (the second numerator * the first denominator)
        numerator = (stoi(n1) * stoi(d2) + stoi(n2) * stoi(d1));
    }
    // simplize the fracation
    simplize(numerator, denominator);

    // print the fraction if valid
    valid_result(denominator) ? cout << numerator << "/" << denominator << endl : cout << "error dividing by zero" << endl;

}


void div(string& n1, string& n2, string& d1, string& d2, int& numerator, int& denominator)
{
    // the result numerator will be the divis on of the two numerators
    numerator = stoi(n1) * stoi(d2);

    // the result denominator will be the divison of the two denominators
    denominator = stoi(d1) * stoi(n2);
    
    // simplize the fraction
    simplize(numerator, denominator);

    // print the fraction if valid
    valid_result(denominator) ? cout << numerator << "/" << denominator << endl : cout << "error dividing by zero" << endl;
}


void sub(string& n1, string& n2, string& d1, string& d2, int& numerator, int& denominator)
{
    // check if the two denominator are equal
    if (d1 == d2)
    {
        // the result denominator will be one of them
        denominator = (stoi(d1));

        // the result numerator will be the subtraction of the two numerators
        numerator = (stoi(n1)) - (stoi(n2));
    }
    else
    {
        // the result denominator will be the multiplication of the two denominator
        denominator = stoi(d1) * stoi(d2);

        // the result numerator will be the subtraction of (the first numertor * the second denominator) and (the second numerator * the first denominator)
        numerator = (stoi(n1) * stoi(d2) - stoi(n2) * stoi(d1));
    }
    // simplize the fraction
    simplize(numerator, denominator);

    // print the fraction if valid
    valid_result(denominator) ? cout << numerator << "/" << denominator << endl : cout << "error dividing by zero" << endl;
}


void mul(string& n1, string& n2, string& d1, string& d2, int& numerator, int& denominator)
{
    // the result numerator will be the multiplication of the two numerators
    numerator = (stoi(n1)) * (stoi(n2));

    // the result denominator will be the multiplication of the two denominators
    denominator = (stoi(d1)) * (stoi(d2));

    // simplize the fraction
    simplize(numerator, denominator);

    // print the fraction if valid
    valid_result(denominator) ? cout << numerator << "/" << denominator << endl : cout << "error dividing by zero" << endl;
}


void reset(string& n1, string& n2, string& d1, string& d2)
{
    // resetting the variables to use again
    n1 = "";
    n2 = "";
    d1 = "";
    d2 = "";   
}


void simplize(int& numerator, int& denominator)
{
    // initializing the start
    int start;

    // the start will equal to the bigger from the numerator and denominator
    (numerator >= denominator) ? (start = numerator) : (start = denominator);

    // loop from the start number decreasing to 2
    for (int i = start; i >= 2; i--)
    {
        // check if the number is dividable on the numerator and denominator 
        if (numerator % i == 0 && denominator % i == 0)
        {
            // dividing the number from the numerator and denominator 
            numerator /= i; 
            denominator /= i;
        }
        else
            continue;
    }   

}


bool is_valid(string& fraction1, string& operation, string& fraction2)
{
    bool opreationValid = false;

    if (operation == "+" || operation == "-" || operation == "*" || operation == "/")
        opreationValid = true;

    else
        return false;

    // search for the (/)
    bool validLine = false;
    int firstLinePos;
    int secondLinePos;

    // looping from start till the end of fraction1 to search for the first fraction's (/)
    for (int i = 0; i < fraction1.length(); i++)
    {   
        if (fraction1[i] == '/')
        {
            validLine = true;
            
            // setting it's position in a variable
            firstLinePos = i;
        }
        else
            continue;
    }
    // if there is no denominator, adding denominator and set it to 1
    if (!validLine)
    {
        // add line to the end of fraction1
        fraction1.insert(fraction1.length(), "/");

        // adding it's position to a variable
        firstLinePos = fraction1.length() - 1;

        // add 1 to the end of fraction1
        fraction1.insert(fraction1.length(), "1");
    }

    validLine = false;
    // looping from start till the end of fraction2 to search for the second fraction's (/)
    for (int i = 0; i < fraction2.length(); i++)
    {   
        if (fraction2[i] == '/')
        {
            validLine = true;

            // setting it's position in a variable
            secondLinePos = i;
        }
        else
            continue;
    }

    // if there is no denominator, adding denominator and set it to 1
    if (!validLine)
    {
        // add line to the end of fraction2
        fraction2.insert(fraction2.length(), "/");

        // adding it's position to a variable
        secondLinePos = fraction2.length() - 1;

        // add 1 to the end of fraction2
        fraction2.insert(fraction2.length(), "1");
    }

    // checking if the first numerator has only numbers
    bool NumeratorValid = true;

    // looping from the start to the first line position
    for(int i = 0; i < firstLinePos; i++)
    {   
        if(!isdigit(fraction1[i]))
        {
            NumeratorValid = false;
            break;
        }
        else
            continue;
    }

    // checking if the second numerator has only numbers
    // looping from the start to the second line position
    for(int i = 0; i < secondLinePos; i++)
    {
        if(!isdigit(fraction2[i]))
        {
            NumeratorValid = false;
            break;
        }
        else
            continue;
    }

    // exiting with false if one of the numerators are not numbers
    if (!NumeratorValid)
        return false;

    // checking if the first denominator has only numbers
    bool secondPartValid = true;

    // looping afrer first line position till the end of fraction1
    for(int i = firstLinePos + 1; i < fraction1.length(); i++)
    {
        if(!isdigit(fraction1[i]))
        {
            secondPartValid = false;
            break;
        }
        else
            continue;
    }

    // checking if the second denominator has only numbers
    // looping after the second line position till the end of fraction2
    for(int i = secondLinePos + 1; i < fraction2.length(); i++)
    {
        if(!isdigit(fraction2[i]))
        {
            secondPartValid = false;
            break;
        }
        else
            continue;
    }

    // exiting with false if one of the denominators are not numbers
    if(!secondPartValid)
        return false;

    // if all valid return true
    return true;
}

bool valid_result(int& denominator)
{
    // if the denominator is zero the result will not be valid
    return denominator == 0 ? false : true;
}

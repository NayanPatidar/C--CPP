// Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.cpp"
#include "TickTakToe.cpp"

using namespace std;

int main()
{
  /*  string values = "345";
    cout << "Hello World" << endl;
    cout << "Values is : " << endl;
    cout << values << endl;
    bool isMale = false;

    string Name;
    cin >> Name;
    cout << "You are " << Name << " Patidar" << endl;

    int luckyNums[20] = { 4, 8, 12, 11, 54, 0 };

    for (int i = 0; i < 6; i++) {
        cout << luckyNums[i] << endl;
    }
   

    int num;
    cout << "Enter the number to be cubed : ";
    cin >> num;

    Function obj;
    obj.sayHi();
    cout <<  "\n" << obj.cubeOfNum(num);
     */


    TikTacToe obj;
    obj.start();
}


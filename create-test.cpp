#include <iostream>
#include <fstream>

using namespace std;

string input_nl(const string& message)
{
    cout << message;

    string inputted = "";

    while(true)
    {
        string tmp;
        cin >> tmp;

        if (tmp == "end") break;
        inputted += tmp + "\n";
    }

    return inputted;
}

int main()
{
    cout << "input test num >";
    string numStr;
    cin >> numStr;

    string testStr = input_nl("input test string >");
    ofstream outFile("test-data/test" + numStr);
    outFile << testStr << endl;
    outFile.close();

    string ansStr = input_nl("input ans string >");
    ofstream outAnsFile("test-data/ans" + numStr);
    outAnsFile << ansStr << endl;
    outAnsFile.close();

    return 0;
}


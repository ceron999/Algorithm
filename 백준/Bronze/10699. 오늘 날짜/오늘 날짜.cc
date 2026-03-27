#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

int main() 
{
    time_t rawTime = time(nullptr);
    rawTime += 9 * 60 * 60;
    tm* timeInfo = localtime(&rawTime);

    if (timeInfo)
    {
        cout << timeInfo->tm_year + 1900 << "-"
            << setw(2) << setfill('0') << timeInfo->tm_mon + 1 << "-"
            << setw(2) << setfill('0') << timeInfo->tm_mday;
    }

}
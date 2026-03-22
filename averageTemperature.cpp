#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomTemperature(int temp[], int dayInMonth[])
{
    int day = 0;

    for (int i = 0; i < dayInMonth[0]; i++)
        temp[day++] = -41 + (rand() % 20);

    for (int i = 0; i < dayInMonth[1]; i++)
        temp[day++] = -25 + (rand() % 15);

    for (int i = 0; i < dayInMonth[2]; i++)
        temp[day++] = -10 + (rand() % 18);

    for (int i = 0; i < dayInMonth[3]; i++)
        temp[day++] = 0 + (rand() % 15);

    for (int i = 0; i < dayInMonth[4]; i++)
        temp[day++] = 10 + (rand() % 10);

    for (int i = 0; i < dayInMonth[5]; i++)
        temp[day++] = 15 + (rand() % 15);

    for (int i = 0; i < dayInMonth[6]; i++)
        temp[day++] = 20 + (rand() % 20);

    for (int i = 0; i < dayInMonth[7]; i++)
        temp[day++] = 15 + (rand() % 20);

    for (int i = 0; i < dayInMonth[8]; i++)
        temp[day++] = 10 + (rand() % 15);

    for (int i = 0; i < dayInMonth[9]; i++)
        temp[day++] = 0 + (rand() % 15);

    for (int i = 0; i < dayInMonth[10]; i++)
        temp[day++] = -5 + (rand() % 15);

    for (int i = 0; i < dayInMonth[11]; i++)
        temp[day++] = -15 + (rand() % 20);
}

int main()
{
    srand(time(0));

    const char *monthName[12] = {"Январь", "Февраль", "Март", "Апрель", "Май",
                                 "Июнь", "Июль", "Август", "Сентябрь",
                                 "Октябрь", "Ноябрь", "Декабрь"};
    int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int allYearTemp[365]{};
    randomTemperature(allYearTemp, dayInMonth);

    int averageTemp[12]{};
    int curDay = 0;

    for (int month = 0; month < 12; month++)
    {
        int sum = 0;
        for (int day = 0; day < dayInMonth[month]; day++)
        {
            sum += allYearTemp[curDay];
            curDay++;
        }
        averageTemp[month] = sum / dayInMonth[month];
    }

    cout << "Средние температуры по месяцам:" << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << monthName[i] << ": " << averageTemp[i] << "°C" << endl;
    }
    cout << endl;

    int coldestMonth = 0;
    int hottestMonth = 0;

    for (int i = 1; i < 12; i++)
    {
        if (averageTemp[i] > averageTemp[hottestMonth])
            hottestMonth = i;
        if (averageTemp[i] < averageTemp[coldestMonth])
            coldestMonth = i;
    }

    cout << "Самый холодный месяц: " << monthName[coldestMonth]
         << " (" << averageTemp[coldestMonth] << "°C)" << endl;
    cout << "Самый теплый месяц: " << monthName[hottestMonth]
         << " (" << averageTemp[hottestMonth] << "°C)" << endl;
}
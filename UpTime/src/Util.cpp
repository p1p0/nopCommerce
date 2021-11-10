#include "../include/pch.h"
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include<iostream>

using namespace std;

unsigned int const dayBySecond(86400);
unsigned int const hourBySecond(3600);
unsigned int const mintesBySecond(60);


Time readFile(string file)
{
    Time uptime = Time();
    ifstream fileFlux;
    fileFlux.open(file.c_str());

    if (fileFlux)
    {
        double firstNumber;
        fileFlux >> firstNumber;

        double secondNumber;
        fileFlux >> secondNumber;

        uptime.startServer = firstNumber;
        uptime.inActivity = secondNumber;

    }
    else
    {
        cout << "ERROR: Unable to open file for reading." << endl;
    }

    fileFlux.close();

    return uptime;
}



string getCurrentTime()
{

    time_t     now = time(0);
    struct tm  currentTime;
    char       formatedTime[80];
    currentTime = *localtime(&now);

    // format time to hours:minutes:seconds
    strftime(formatedTime, sizeof(formatedTime), "%X", &currentTime);

    //cout << formatedTime << endl;
    return formatedTime;
}

Result convertFromSecond(double time)
{
    int seconds = time;
    // for start time duration
    int days = seconds / dayBySecond;

    seconds = seconds % dayBySecond;
    int hours = seconds / hourBySecond;

    seconds %= hourBySecond;
    int minutes = seconds / mintesBySecond;

    Result res;
    res.days = days;
    res.hours = hours;
    res.minutes = minutes;

    return res;
}

Duration converstion(double startServer, double inActivity)
{
    Result resOfstartServer, resOfinActivity;
    string currentTime = getCurrentTime();

    resOfstartServer = convertFromSecond(startServer);
    resOfstartServer.now = currentTime;
    resOfstartServer.type = "up";

    resOfinActivity = convertFromSecond(inActivity);
    resOfinActivity.now = currentTime;
    resOfinActivity.type = "idle";

    Duration duration;

    duration.startServer = formatDuration(resOfstartServer);
    duration.inActivity = formatDuration(resOfinActivity);

    cout << "\n" << duration.startServer << "\n" << duration.inActivity << endl;

    return duration;
}

string formatDuration(Result res)
{
    string duration = res.now + " " + res.type + " ";
    if (res.days == 0)
    {
        if (res.hours == 0)
        {
            duration += to_string(res.minutes) + " min";
        }
        else
        {
            duration += to_string(res.hours) + ":";
            if (res.minutes < 10)
            {
                duration += "0" + to_string(res.minutes);
            }
            else
            {
                duration += to_string(res.minutes);
            }
        }
    }
    else if (res.days == 1)
    {
        duration += to_string(res.days) + " day, ";
        if (res.hours == 0)
        {
            duration += to_string(res.minutes) + " min";
        }
        else
        {
            duration += to_string(res.hours) + ":";
            if (res.minutes < 10)
            {
                duration += "0" + to_string(res.minutes);
            }
            else
            {
                duration += to_string(res.minutes);
            }
        }
    }
    else
    {
        duration += to_string(res.days) + " days, ";
        if (res.hours == 0)
        {
            duration += to_string(res.minutes) + " min";
        }
        else
        {
            duration += to_string(res.hours) + ":";
            if (res.minutes < 10)
            {
                duration += "0" + to_string(res.minutes);
            }
            else
            {
                duration += to_string(res.minutes);
            }
        }
    }
    return duration;
}
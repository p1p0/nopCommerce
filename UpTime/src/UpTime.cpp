#pragma warning(disable : 4996) // _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "../include/Duration.h"
#include "../include/Result.h"
#include "../include/Time.h"
#include "../include/Util.h"
#include <chrono>

using namespace std::chrono;

using namespace std;

std::string const filePath("data/uptime_file.txt");


int main()
{

    auto start = high_resolution_clock::now();

    Time uptime = readFile(filePath);
    converstion(uptime.startServer, uptime.inActivity);

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop - start);
    
    cout << "\nTime taken by this programme: "
         << dur.count() << " microseconds" << endl;

    return 0;
}












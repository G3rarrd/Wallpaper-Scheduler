#include "scheduler.h"
#include <chrono>
#include <ctime>
#include <windows.h>

namespace
{
    constexpr int secondsPerDay = 86400;
}

namespace scheduler {
    int secondsSinceMidnight(int offsetHours) {
        SYSTEMTIME local;
        GetLocalTime(&local);

        int seconds =
            local.wHour * 3600 +
            local.wMinute * 60 +
            local.wSecond;

        seconds += offsetHours * 3600;
        seconds %= secondsPerDay;

        if (seconds < 0) seconds += secondsPerDay;

        return seconds;
    }

    int currentIndex(int imageCount, int offsetHours) {
        int secondsPerImage = secondsPerDay / imageCount;
        return secondsSinceMidnight(offsetHours) / secondsPerImage;
    }

    // int secondsUntilNextChange(int imageCount, int offsetHours){
    //     int secondsPerImage = secondsPerDay / imageCount;

    //     int currentTime = secondsSinceMidnight(offsetHours);

    //     int nextTime = ((currentTime / secondsPerImage) + 1) * secondsPerImage;

    //     nextTime %= secondsPerDay;

    //     if (nextTime > currentTime) return nextTime - currentTime;

    //     return secondsPerDay - currentTime + nextTime;
    // }
}
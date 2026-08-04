#pragma once

namespace scheduler
{
    int secondsSinceMidnight(int offsetHours);
    
    int currentIndex(int imageCount, int offsetHours);

    int secondsUntilNextChange(int imageCount, int offsetHours);
}
// Alex Donahue
// Kent State University - Computer Science 2 - Lab 2
// time.cpp
// All of my implementation of Time.

#include "time.hpp"

bool TimePart::operator==(const TimePart &rhs)
{
    return hour == rhs.hour && minute == rhs.minute && second == rhs.second;
}

std::ostream &operator<<(std::ostream &out, const TimePart &tp)
{
    out << std::setfill('0') << std::setw(2) << tp.hour << ":";
    out << std::setfill('0') << std::setw(2) << tp.minute << ":";
    out << std::setfill('0') << std::setw(2) << tp.second;
    return out;
}

// Helper function for the hours/minutes/seconds. Seperating these processes into their own
// functions help cut down on code bloat.

int validateHour(int hour)
{
    int returnHour = 0;
    if (hour < 0)
    {
        returnHour = 0;
    }
    else if (hour > 23)
    {
        returnHour = hour % 24;
    }
    else if (hour >= 0 && hour < 24)
    {
        returnHour = hour;
    }
    else
    {
        throw std::invalid_argument("Invalid hour");
    }
    return returnHour;
}

int validateMinute(int minute)
{
    int returnMinute = 0;

    if (minute < 0)
    {
        // Say we enter -5 here, the modulus result back will be -5, adding this result
        // to 60 gives us the value we actually want.
        returnMinute = (minute % 60) + 60;
    }
    else if (minute > 59)
    {
        returnMinute = minute % 60;
    }
    else if (minute >= 0 && minute < 60)
    {
        returnMinute = minute;
    }
    else
    {
        throw std::invalid_argument("Invalid minute");
    }
    return returnMinute;
}

int validateSecond(int second)
{
    int returnSecond = 0;

    if (second < 0)
    {
        // Say we enter -5 here, the modulus result back will be -5, adding this result
        // to 60 gives us the value we actually want.
        returnSecond = (second % 60) + 60;
    }
    else if (second > 59)
    {
        returnSecond = second % 60;
    }
    else if (second >= 0 && second < 60)
    {
        returnSecond = second;
    }
    else
    {
        throw std::invalid_argument("Invalid second");
    }
    return returnSecond;
}

/*
    This function acts as the centerpiece to control the rest of the functions. It was important to have a function like this
    because of the way that the time needs to increment. I originally had a design that only used the validate functions, but
    this proved insufficient for the task.
*/
TimePart validateTime(int hour, int minute, int second)
{
    TimePart time;
    // Start with seconds, as the seconds logic can cascade up to change the other values.

    // Logic to check for the rollover of seconds.
    if (second > 59)
    {
        // Integer division allows for the proper value to be stored.
        minute += second / 60;
    }
    else if (second < -60)
    {
        // The integer division solution isn't as clean for negatives, so I added extra logic.
        minute = minute + (second / 60 - 1);
    }
    else if (second < 0)
    {
        minute -= 1;
    }
    time.second = validateSecond(second);

    // Logic to check for the rollover of minutes.
    if (minute > 59)
    {
        hour += minute / 60;
    }
    else if (minute < -60)
    {
        hour = hour + (minute / 60 - 1);
    }
    else if (minute < 0)
    {
        hour -= 1;
    }
    time.minute = validateMinute(minute);
    // Hour exists independent of minutes/seconds, no need for extra checking
    time.hour = validateHour(hour);

    return time;
}

Time::Time()
{
    _time.hour = 0;
    _time.minute = 0;
    _time.second = 0;
}

Time::Time(int hour)
{
    TimePart formattedTime = validateTime(hour, 0, 0);
    _time.hour = formattedTime.hour;
    _time.minute = formattedTime.minute;
    _time.second = formattedTime.second;
}

Time::Time(int hour, int minute)
{
    TimePart formattedTime = validateTime(hour, minute, 0);
    _time.hour = formattedTime.hour;
    _time.minute = formattedTime.minute;
    _time.second = formattedTime.second;
}

Time::Time(int hour, int minute, int second)
{
    TimePart formattedTime = validateTime(hour, minute, second);
    _time.hour = formattedTime.hour;
    _time.minute = formattedTime.minute;
    _time.second = formattedTime.second;
}

bool Time::operator==(const Time &rhs)
{
    return _time.hour == rhs._time.hour && _time.minute == rhs._time.minute && _time.second == rhs._time.second;
}

void Time::increment()
{
    /*
        I love how elegant this solution is! My validate time function is already doing
        a ton of heavy lifting in rolling the time over, so we can just pass the Time's
        current values with second + 1, and it will ensure that we roll everything over!
    */
    TimePart formattedTime = validateTime(_time.hour, _time.minute, _time.second + 1);
    _time.hour = formattedTime.hour;
    _time.minute = formattedTime.minute;
    _time.second = formattedTime.second;
}

void Time::decrement()
{
    // Same idea as increment.
    TimePart formattedTime = validateTime(_time.hour, _time.minute, _time.second - 1);
    _time.hour = formattedTime.hour;
    _time.minute = formattedTime.minute;
    _time.second = formattedTime.second;
}

void Time::add(int seconds)
{
    // Same idea with a variable amount of seconds be added.
    TimePart formattedTime = validateTime(_time.hour, _time.minute, _time.second + seconds);
    _time.hour = formattedTime.hour;
    _time.minute = formattedTime.minute;
    _time.second = formattedTime.second;
}

int Time::diff(const Time sub)
{
    int tempSeconds = 0;
    int tempMinutes = 0;
    int tempHours = 0;

    tempHours = _time.hour - sub._time.hour;
    tempMinutes = _time.minute - sub._time.minute;
    tempSeconds = _time.second - sub._time.second;

    // Return is only in seconds, so this calculates out the total seconds.
    return (tempHours * 3600) + (tempMinutes * 60) + tempSeconds;
}

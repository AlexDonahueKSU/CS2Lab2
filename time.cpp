// John Sipahioglu
// Kent State University - Computer Science 2 - Lab 2
// time.cpp
// write the implementation of class Time here

#include "time.hpp"


bool TimePart::operator==(const TimePart &rhs) {
    return hour == rhs.hour && minute == rhs.minute && second == rhs.second;
}

std::ostream& operator<<(std::ostream &out, const TimePart &tp) {
    out << std::setfill('0') << std::setw(2) << tp.hour << ":";
    out << std::setfill('0') << std::setw(2) << tp.minute << ":";
    out << std::setfill('0') << std::setw(2) << tp.second;
    return out;
}

Time::Time() {
    _time.hour = 0;
    _time.minute = 0;
    _time.second = 0;
}

//...
Time::Time(int hour)
{
    _time.minute = 0;
    _time.second = 0;
    if (hour < 0)
    {
        _time.hour = 0;
    }
    else if (hour > 23)
    {
        hour = hour % 24;
        _time.hour = hour;
    }
    else if (hour >= 0 && hour <= 24)
    {
        _time.hour = hour;
    }
    else
    {
        throw std::invalid_argument("Invalid hour");
    }

}

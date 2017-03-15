#include "stdio.h"
#include "time.h"

typedef unsigned short HT;
typedef unsigned short MT;
typedef unsigned short ST;


class TTime
{
public:
    TTime();
    TTime(const HT h, const MT m, const ST s)
    {
        if(h > 24 || m > 60 || s > 60)
        {
            _time = _h = _m = _s = 0;
            return;
        }
        _h = h;
        _m = m;
        _s = s;
        _time = _h*3600 + _m*60 + _s;
    }
    TTime(const TTime&);
    TTime& operator=(const TTime&);
    TTime& operator+(const TTime&);
    TTime& operator-(const TTime&);
    bool operator ==(const TTime& t)
    {
        return _time == t._time;
    }
    bool operator < (const TTime& t)
    {
        return _time < t._time;
    }
    bool operator > (const TTime& t)
    {
        return _time > t._time;
    }
    bool operator <=(const TTime& t)
    {
        return _time <= t._time;
    }
    bool operator >=(const TTime& t)
    {
        return _time >= t._time;
    }
    /*%2d:%2d:%2d*/
    void print(const char* frmt)
    {
        printf(frmt,_h,_m,_s);
    }
    void printAMPM()
    {
        static const char PM[] = "PM";
        static const char AM[] = "AM";
        printf("%2d:%2d:%2d %s\n",_h%12 ? _h%12 : _h,_m,_s,_h%12 ? PM : AM);
    }
private:
    unsigned long _time;
    HT _h;
    MT _m;
    ST _s;
};

TTime::TTime()
{
    time_t cur_time = time(NULL);
    tm* now = localtime(&cur_time);
    _h = now->tm_hour;
    _m = now->tm_min;
    _s = now->tm_sec;
    _time = _s + _m*60 + _h*3600;
}

TTime& TTime::operator=(const TTime& t)
{
    _time = t._time;
    _h = t._h;
    _m = t._m;
    _s = t._s;
    return *this;
}

TTime::TTime(const TTime& t)
{
    operator=(t);
}

TTime& TTime::operator+(const TTime& t)
{
    _time += t._time;
    if(_time > 24*3600)
        _time %= 24*3600;
    _s = _time%60;
    _time -= _s;
    _h = _time/3600;
    _m = (_time - _h*3600)/60;
    return *this;
}

TTime& TTime::operator-(const TTime& t)
{
    _time += t._time;
    if(_time <= 0)
        _h = _m = _s = 0;
    _s = _time%60;
    _time -= _s;
    _h = _time/3600;
    _m = (_time - _h*3600)/60;
    return *this; 
}

int main()
{
    TTime t = TTime();
    TTime t2(22,59,59);
    t = t + t2;
    t.print("%2d:%2d:%2d\n");
    t.print("%2d.%2d.%2d\n");
    t.printAMPM();
    return 0;
}

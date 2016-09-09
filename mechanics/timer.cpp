#include "timer.h"
#include <iostream>

using namespace mechanics;
Timer::Timer(int ttl) : Action(), tickLeft(ttl),startTickConst(ttl)
{
}

Timer::~Timer()
{

}


void Timer::execute()
{
    tickLeft--;
    if (tickLeft > 0)
    {
        OnTick();
        Action::call(this);
        deleteMe = false;
    }
    if (tickLeft <= 0)
    {
        deleteMe = true;
        try{
            OnExpire();
        }catch(exception e)
        {
            std::cerr << e.what() << "\n";
            deleteMe = true;
        }
    }
}

void Timer::OnTick()
{

}

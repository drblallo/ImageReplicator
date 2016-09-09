#include "characteristic.h"
#include "rawbonus.h"
#include "algorithm"

using namespace mechanics;

//########################################
//##### Constructors and Conversions #####
//########################################
Characteristic::Characteristic(float base, string nm) :  chached(base), baseValue(base), name(nm) {}

Characteristic::operator float() const
{
    return chached;
}

Characteristic::~Characteristic()
{
    for (int a = rawExtraBonus.size() - 1; a >= 0; a--)
        removeRawBonuss(rawExtraBonus[a]);

    for (int a = multiplierExtraBonus.size() - 1; a >= 0; a--)
        removeRawBonuss(multiplierExtraBonus[a]);
}

//########################################
//#####           Methods            #####
//########################################
float Characteristic::calculate()
{
    chached = getTotalRaw() * getTotalMultiplier();
    return chached;
}

void Characteristic::addRawBonus(RawBonus *bonus)
{
    if (!bonus || rawExtraBonus.end() != find(rawExtraBonus.begin(), rawExtraBonus.end(), bonus))
        return;

    rawExtraBonus.push_back(bonus);
    bonus->chars.push_back(this);
}

void Characteristic::addMultiplierBonus(RawBonus *bonus)
{
    if (!bonus || multiplierExtraBonus.end() != find(multiplierExtraBonus.begin(), multiplierExtraBonus.end(), bonus))
        return;

    multiplierExtraBonus.push_back(bonus);
    bonus->chars.push_back(this);
}

void Characteristic::removeRawBonuss(RawBonus *bonus)
{
    if (!bonus)
        return;

    rawExtraBonus.erase(remove(rawExtraBonus.begin(), rawExtraBonus.end(), bonus), rawExtraBonus.end());
    bonus->chars.erase(remove(bonus->chars.begin(), bonus->chars.end(), this), bonus->chars.end());
}

void Characteristic::removeMultiplierBonus(RawBonus* bonus)
{
    if (!bonus)
        return;

    multiplierExtraBonus.erase(remove(multiplierExtraBonus.begin(), multiplierExtraBonus.end(), bonus), multiplierExtraBonus.end());
    bonus->chars.erase(remove(bonus->chars.begin(), bonus->chars.end(), this), bonus->chars.end());
}

void Characteristic::removeBonus(RawBonus* bonus)
{
    if (!bonus)
        return;

    rawExtraBonus.erase(remove(rawExtraBonus.begin(), rawExtraBonus.end(), bonus ), rawExtraBonus.end());
    multiplierExtraBonus.erase(remove(multiplierExtraBonus.begin(), multiplierExtraBonus.end(), bonus), multiplierExtraBonus.end());
    bonus->chars.erase(remove(bonus->chars.begin(), bonus->chars.end(), this), bonus->chars.end());
}

//########################################
//#####         Accessors            #####
//########################################
float Characteristic::getTotalRaw() const
{
    float base(baseValue);
    for (unsigned int a = 0; a < rawExtraBonus.size(); a++)
        if (rawExtraBonus[a]->isEnabled())
            base += rawExtraBonus[a]->getValue();

    return base;
}

float Characteristic::getTotalMultiplier() const
{
    float multiplier(1);
    for (unsigned int a = 0; a < multiplierExtraBonus.size(); a++)
        if (multiplierExtraBonus[a]->isEnabled())
            multiplier += multiplierExtraBonus[a]->getValue();

    return multiplier;
}

float Characteristic::getBaseValue() const
{
    return baseValue;
}

const vector<RawBonus* >* Characteristic::getRawBonuses() const
{
    return &rawExtraBonus;
}

const vector<RawBonus*>* Characteristic::getMultiplierBonuses() const
{
    return &multiplierExtraBonus;
}

const string* Characteristic::getName() const
{
    return &name;
}

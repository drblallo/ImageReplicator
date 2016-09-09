#include "rawbonus.h"
#include "characteristic.h"

using namespace mechanics;

//########################################
//##### Constructors and Conversions #####
//########################################
RawBonus::RawBonus(float val, const string* des) : value(val), description(*des), enabled(true) {}

RawBonus::operator float() const
{
    return value;
}

RawBonus::~RawBonus()
{
    for (int a = chars.size() - 1; a >= 0; a++)
        chars[a]->removeBonus(this);
}

//########################################
//#####           Methods            #####
//########################################
void RawBonus::setValue(float newValue)
{
    value = newValue;
}

void RawBonus::setDescription(const string* newDes)
{
    description = *newDes;
}

void RawBonus::setEnabled(bool ena)
{
    enabled = ena;
}

//########################################
//#####          Accessors           #####
//########################################
const string* RawBonus::getDescription() const
{
    return &description;
}

float RawBonus::getValue() const
{
    return value;
}

bool RawBonus::isEnabled() const
{
    return enabled;
}

const vector<Characteristic*>* RawBonus::getCarateristics() const
{
    return &chars;
}

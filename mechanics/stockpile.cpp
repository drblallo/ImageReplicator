#include "stockpile.h"
#include <string>

using namespace mechanics;

StockPile::StockPile(int baseValue, string n) : count(baseValue), addModifiers(1, std::string("Stock Pile Increase")), name(n)
{

}

void StockPile::add(float t)
{
    count += t*addModifiers;
}

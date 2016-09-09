#pragma once
#include "vector"
#include <string>

using namespace std;

namespace mechanics
{
    class RawBonus;
    class Characteristic
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            Characteristic(float base, string nm);
            operator float() const;
            ~Characteristic();

        //########################################
        //#####           Methods            #####
        //########################################
            float calculate();
            void addRawBonus(RawBonus* bonus);
            void addMultiplierBonus(RawBonus* bonus);
            void removeRawBonuss(RawBonus *bonus);
            void removeMultiplierBonus(RawBonus* bonus);
            void removeBonus(RawBonus* bonus);

        //########################################
        //#####         Accessors            #####
        //########################################
            float getTotalRaw() const;
            float getTotalMultiplier() const;
            float getBaseValue() const;
            const vector<RawBonus*>* getRawBonuses() const;
            const vector<RawBonus*>* getMultiplierBonuses() const;
            const string* getName() const;

        //########################################
        //#####         Privatizing          #####
        //########################################
            Characteristic(const Characteristic&) = delete;
            Characteristic& operator= ( const Characteristic&) = delete;

        private:
        //########################################
        //#####           Fields             #####
        //########################################
            vector<RawBonus* > rawExtraBonus;
            vector<RawBonus*> multiplierExtraBonus;
            float chached;
            float baseValue;
            string name;

    };
}

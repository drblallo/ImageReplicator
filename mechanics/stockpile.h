#pragma once
#include "characteristic.h"
#include <string>

namespace mechanics
{
    class StockPile
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            StockPile(int baseValue, string n);
            inline operator float() const {return count;}

        //########################################
        //#####         Privatizing          #####
        //########################################
            StockPile(const StockPile&) = delete;
            StockPile& operator= (const StockPile&) = delete;

        //########################################
        //#####          Accessors           #####
        //########################################
            inline float getValue() const {return count;}
            inline Characteristic* getIncreaseModifier(){return &addModifiers;}
            inline const std::string* getName() const {return &name;}

        //########################################
        //#####           Methods            #####
        //########################################
            void add(float t);

        private:
        //########################################
        //#####           Fields             #####
        //########################################
            float count;
            Characteristic addModifiers;
            std::string name;
    };
}

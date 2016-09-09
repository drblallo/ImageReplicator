#pragma once
#include <string>
#include <vector>


using namespace std;

namespace mechanics
{
    class Characteristic;
    class RawBonus
    {
        public:
        friend class Characteristic;

        //########################################
        //##### Constructors and Conversions #####
        //########################################
            RawBonus(float val, const string* des);
            operator float() const;
            virtual ~RawBonus();

        //########################################
        //#####           Methods            #####
        //########################################
            void setValue(float newValue);
            void setDescription(const string* newDes);
            void setEnabled(bool ena);

        //########################################
        //#####          Accessors           #####
        //########################################
            const string* getDescription() const;
            float getValue() const;
            bool isEnabled() const;
            const vector<Characteristic*>* getCarateristics() const;

        //########################################
        //#####         Privatizing          #####
        //########################################
            RawBonus(const RawBonus&) = delete;
            RawBonus& operator= (const RawBonus&) = delete;

        private:
        //########################################
        //#####           Fields             #####
        //########################################
            float value;
            string description;
            bool enabled;
            vector<Characteristic*> chars;

    };
}

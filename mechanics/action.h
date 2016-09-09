#pragma once
#include <vector>
#include <mutex>

using namespace std;
namespace mechanics
{
    class Action
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            Action();

        //########################################
        //#####         Privatizing          #####
        //########################################
            Action(const Action&) = delete;
            Action& operator= (const Action&) = delete;

        //########################################
        //#####           Methods            #####
        //########################################
            static void call(Action* action);
            static void uncall(Action* action);
            static void resolveAllPending();

        //########################################
        //#####         Accessors            #####
        //########################################
            inline static const vector<Action*>* getPendingActions()
            {
                return &pendingActions;
            }
            inline bool isPending()const {return pending;}

        protected:
            virtual void execute() = 0;
            bool deleteMe;
            virtual ~Action();

        private:
        //########################################
        //#####           Fields             #####
        //########################################
            static vector<Action*> pendingActions;
            static vector<Action*> allActions;
            static mutex pendingActionsMutex;
            static mutex resolveAllMutex;
            static mutex allActionsMutex;

            bool pending;
    };
}

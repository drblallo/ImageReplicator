#include "gamedata.h"
#include "gamesupercluster.h"
#include "gamecluster.h"
#include "gamegalaxy.h"
#include "gamesegment.h"

using namespace game;

GameData* GameData::data(NULL);

GameData::GameData() :superCluster(NULL), cluster(NULL), galaxy(NULL), segment(NULL)
{

}

void GameData::setSuperCluster(int targetSuperCluster)
{
    if (targetSuperCluster > 3 || targetSuperCluster < 0)
        return;
    if (!superCluster)
    {
        superCluster = new GameSuperCluster(targetSuperCluster);
        return;
    }

    if (superCluster->getAdress() == targetSuperCluster)
    {
        return;
    }

    delete superCluster;
    superCluster = new GameSuperCluster(targetSuperCluster);

    if (cluster)
        delete cluster;
    cluster = NULL;

    if (galaxy)
        delete galaxy;
    galaxy = NULL;

    if (segment)
        delete segment;
    segment = NULL;

}

void GameData::setCurrentCluster(int x, int y)
{
    setCurrentCluster((50*x)+y);
}

void GameData::setCurrentCluster(int targetCluster)
{
    if (targetCluster < 0  || targetCluster >= 50*50)
        return;
    if (!superCluster)
        return;

    if (!cluster)
    {
        cluster = new GameCluster(superCluster->getAdress(), targetCluster);
        return;
    }
    if (cluster->getAdress() == targetCluster)
        return;

    delete cluster;
    cluster = new GameCluster(superCluster->getAdress(), targetCluster);

    if (galaxy)
        delete galaxy;
    galaxy  = NULL;

    if (segment)
        delete segment;
    segment = NULL;
}

void GameData::setCurrentGalaxy(int targetGalaxy)
{
   if (!cluster)
       return;
    int effectiveAdress(((superCluster->getAdress()*1000000)+(cluster->getAdress()*1000)+targetGalaxy));


   if (!galaxy)
   {
       galaxy =  new GameGalaxy(effectiveAdress);
       return;
   }

   if (galaxy->getSeed() == effectiveAdress)
       return;

   delete galaxy;
   galaxy  = new GameGalaxy(effectiveAdress);


    if (segment)
        delete segment;
    segment = NULL;
}

void GameData::setCurrentSegment(int x, int y)
{
   if (!galaxy)
       return;

    if (x < 0 || y < 0 || x >= GALAXY_SLOT_SIZE || y >= GALAXY_SLOT_SIZE)
        return;

   if (!segment)
   {
       segment =  new GameSegment(x, y);
       return;
   }

   if (segment->getSegmentX() == x && segment->getSegmentY() == y)
       return;

   delete segment;
   segment  = new GameSegment(x, y);

}

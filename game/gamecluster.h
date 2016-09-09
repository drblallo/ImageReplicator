#pragma once
#include <vector>
#include "render/textureswarmobject.h"

namespace game {
    class GameCluster
    {
        public:
            GameCluster(int superClusterAdress, int clusterAdress);

            inline std::vector<renderer::FloatingQuad>* getQuads(){return &galaxies;}
            inline int getAdress(){return adress;}
            inline int getX(){return adress/50;}
            inline int getY(){return adress%50;}

        private:
            int adress;
            int superClusterAdress;
            std::vector<renderer::FloatingQuad> galaxies;


    };
}

#pragma once
#include <vector>
#include "render/dottedobject.h"
#include "render/textureswarmobject.h"
#define SIZE 20.0f
#define EXT_SIZE 30.0f

using namespace renderer;
using namespace std;
namespace game
{
    struct Node
    {
        public:
            Node(QVector3D p) : pos(p){}
            Node(QVector3D p, QVector3D c) : pos(p), color(c){}
            Node(float x, float y, float z) : pos(x, y, z){}
            QVector3D pos;
            vector<Node*> adjactent;
            vector<Node*> inferiorNodes;
            QVector3D color;
            void setAdjactent(Node* n)
            {
                n->adjactent.push_back(this);
                adjactent.push_back(this);
            }

    };

    class GameWall
    {
        public:
            GameWall();
            inline const vector<Dot>* getDots() const {return &dots;}
            inline const vector<Dot*>* getSuperCluster(int a) const {return &superClusters[a];}
          //  inline vector<FloatingQuad>* getQuads() {return &loc;}

        private:
            vector<Dot> dots;
          //  vector<FloatingQuad> loc;
            vector<Dot*> superClusters[4];


            void generate(int seed);
    };
}

#include "gamegalaxy.h"
#include "galaxygenerator.h"
#include <cmath>

using namespace renderer;
using namespace game;
using namespace std;
GameGalaxy::GameGalaxy(int s) : seed(s)
{
    GalaxyGenerator gen(seed);
    gen.populate(&dots, &quads);

    for (unsigned int a = 0; a < dots.size(); a++)
    {
        Dot* d(&dots[a]);

        if (abs(d->pos.x()) > GALAXY_SLOT_SIZE/2 || abs(d->pos.y()) > GALAXY_SLOT_SIZE/2)
                continue;

        int x(d->pos.x());
        int y(d->pos.y());

        dotSlots[x+25][y+25].push_back(Dot(QVector3D(d->pos.x() - x, d->pos.y() - y, 0), d->col));
    }

    for (unsigned int a = 0; a < quads.size(); a++)
    {
        FloatingQuad* q(&quads[a]);

        if (abs(q->transform.translation().x()) > GALAXY_SLOT_SIZE/2 || abs(q->transform.translation().y()) > GALAXY_SLOT_SIZE/2)
            continue;

        int x(floor(q->transform.translation().x()));
        int y(floor(q->transform.translation().y()));

        Transform3D t;
        t.setTranslation(q->transform.translation().x() - x, q->transform.translation().y() - y, 0);

        quadSlots[x+25][y+25].push_back(FloatingQuad(t, q->color[0]));
    }

}

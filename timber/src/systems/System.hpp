#pragma once

#include "../entities/Entity.hpp";

class System {
    protected:
        void next(Entity* entity, float deltaSecs);
};

#pragma once
#pragma once

#include "../entities/Entity.hpp";

class System {
    protected:
        virtual void next(Entity* entity, float deltaSecs);
};

#pragma once
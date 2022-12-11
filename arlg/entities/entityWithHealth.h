#include "../../age/entity/entity.h"

class EntityWithHealth: public cs246e::Entity {
    int health;
    void addHealth(int x);
public:
    EntityWithHealth(int t, float x, float y, int height,
        std::vector<EntityForm> forms, std::vector<Movement> movements,
        int health);
    
    void collideInto(Entity &e) override;
};

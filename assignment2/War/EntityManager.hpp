#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Entity.hpp"

// In this case, we can also use `typedef` instead of `using`
using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
public:
  std::shared_ptr<Entity> addEntity(const std::string &entityTag);
  void update();
  const EntityVec &getEntities() const;

  EntityManager() = default;
  ~EntityManager() = default;

private:
  // Vector of objects that actually on the screen
  EntityVec m_Entities;
  // Vector of objects that waiting to be drawn
  EntityVec m_EntitiesToAdd;
  // Vector of objects for quick retrieval
  EntityMap m_EntitiesMap;
  size_t m_TotalEntities = 0;

  void removeDeadEntities(EntityVec &entities);
};

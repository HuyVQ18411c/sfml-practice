#include <memory>
#include <string>
#include <vector>

#include "Entity.hpp"

using EntityVec = std::vector<Entity>;

class EntityManager {
private:
  EntityVec m_Entities;
  size_t m_TotalEntities = 0;

  void removeDeadEntities(EntityVec &entities);
  const EntityVec &getEntities() const;

public:
  std::shared_ptr<Entity> addEntity(const std::string &entityTag);
  void update();
  EntityManager() = default;
  ~EntityManager() = default;
};

#include <algorithm>
#include <memory>
#include <string>

#include "EntityManager.hpp"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &entityTag) {
  auto entity =
      std::shared_ptr<Entity>(new Entity(m_TotalEntities++, entityTag));
  m_EntitiesToAdd.push_back(entity);
  return entity;
}

const EntityVec &EntityManager::getEntities() const { return m_Entities; }

void EntityManager::removeDeadEntities(EntityVec &entities) {
  EntityVec entitiesToRemove;

  //  std::remove_if(entities.begin(), entities.end(),
  //                 [](const std::shared_ptr<Entity> &entity) {
  //                   return !entity->isActive();
  //                 });
}

void EntityManager::update() {
  // Release waiting queue
  for (auto e : m_EntitiesToAdd) {
    m_Entities.push_back(e);
    m_EntitiesMap[e->getTag()].push_back(e);
  }
  m_EntitiesToAdd.clear();

  // Remove dead entities
  removeDeadEntities(m_Entities);
}

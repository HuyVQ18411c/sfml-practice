#include <memory>
#include <string>

#include "EntityManager.hpp"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &entityTag) {
  return std::shared_ptr<Entity>(new Entity(m_TotalEntities++, entityTag));
}

void EntityManager::removeDeadEntities(EntityVec &entities) {}

void EntityManager::update() { removeDeadEntities(m_Entities); }

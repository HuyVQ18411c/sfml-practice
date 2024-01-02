#include <string>

#include "Entity.hpp"

Entity::Entity(size_t id, const std::string &entityTag)
    : m_Id(id), m_Tag(entityTag) {}

bool Entity::isActive() const { return m_Active; }

const std::string &Entity::getTag() const { return m_Tag; }

const size_t Entity::getId() const { return m_Id; }

void Entity::destroy() { m_Active = false; }

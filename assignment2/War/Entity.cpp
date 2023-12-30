#include "Entity.hpp"
#include <string>

Entity::Entity(size_t id, const std::string &entityTag)
    : m_Id(id), m_Tag(entityTag) {}

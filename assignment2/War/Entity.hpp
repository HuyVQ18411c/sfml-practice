#include <memory>
#include <string>

#include "Component.hpp"

class Entity {
public:
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CShape> cShape;
  std::shared_ptr<CCollision> cCollision;
  std::shared_ptr<CInput> cInput;
  std::shared_ptr<CScore> cScore;
  std::shared_ptr<CLifespan> cLifespan;

  bool isActive() const;
  const std::string &getTag() const;
  const size_t getId() const;
  void destroy();

private:
  friend class EntityManager;
  bool m_Active = true;
  size_t m_Id = 0;
  std::string m_Tag = "default";
  Entity() = default;
  Entity(const size_t id, const std::string &tag);
  ~Entity();
};

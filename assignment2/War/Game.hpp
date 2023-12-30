// C++ libraries
#include <memory>

// 3rd party libraries
#include <SFML/Graphics.hpp>

// Custom modules
#include "EntityManager.hpp"

struct PlayerConfig {
  int SR, CR, FR, FG, FB, OR, OG, OB, OT, V;
  float S;
};

struct EnemyConfig {
  int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI;
  float SMIN;
};

struct BulletConfig {
  int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L;
  float S;
};

class Game {
public:
  Game(const std::string &configPath);
  void run();

private:
  sf::RenderWindow m_Window;
  EntityManager m_EntityManager;
  sf::Font m_Font;
  sf::Text m_Text;
  PlayerConfig m_PlayerConfig;
  EnemyConfig m_EnemyConfig;
  int m_Score = 0;
  int m_CurrentFrame = 0;
  bool m_IsPaused = false;
  bool m_IsRunning = false;

  std::shared_ptr<Entity> m_Player;
  void init(const std::string &configPath);
  void readConfigFile(const std::string &configPath);
  void setPause();

  void sMovement();
  void sUserInput();
  void sLifespan();
  void sRender();
  void sEnemySpawner();
  void sCollision();

  void spawnPlayer();
  void spawnEnemy();
  void spawnSmallEnemies(std::shared_ptr<Entity> entity);
  void spawnBullet(std::shared_ptr<Entity> entity, const Vec2d &mousePosition);
  void spawnSpecialWeapon(std::shared_ptr<Entity> entity);
};

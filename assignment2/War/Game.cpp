#include "Game.hpp"
#include <fstream>
#include <memory>

#define W_WIDTH 1200
#define W_HEIGHT 720
#define W_TITLE "Geomatry War"
#define W_FPS 60

Game::Game(const std::string &configPath) { init(configPath); }

void Game::readConfigFile(const std::string &configPath) {
  std::ifstream fin(configPath);
}

void Game::init(const std::string &configPath) {
  m_Window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITLE);
  m_Window.setFramerateLimit(W_FPS);

  // Start by spawning player
  spawnPlayer();
}

void Game::run() {
  while (m_IsRunning) {
    m_EntityManager.update();

    if (!m_IsPaused) {
      sEnemySpawner();
      sMovement();
      sCollision();
      sUserInput();
    }

    sRender();
    m_CurrentFrame++;
  }
}

void Game::setPause() { m_IsPaused = true; }

void Game::spawnPlayer() {
  auto player = m_EntityManager.addEntity("player");
  player->cTransform = std::make_shared<CTransform>(Vec2d(200.0f, 200.0f),
                                                    Vec2d(1.0f, 1.0f), 0.0f);
  player->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10),
                                            sf::Color(255, 0, 0), 1.0f);
  player->cInput = std::make_shared<CInput>();
  m_Player = player;
}

void Game::sEnemySpawner() {}

void Game::sMovement() {}

void Game::sCollision() {}

void Game::sUserInput() {}

void Game::sRender() {}

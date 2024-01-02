#include "Game.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
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

void Game::spawnEnemy() {
  auto enemy = m_EntityManager.addEntity("enemy");

  // rand() is not considered as a safe random function to use
  // since with a specific seed, it will always output the same sequence
  float eX = rand() % m_Window.getSize().x;
  float eY = rand() % m_Window.getSize().y;

  enemy->cTransform =
      std::make_shared<CTransform>(Vec2d(eX, eY), Vec2d(0.0f, 0.f), 0.0f);
  enemy->cShape = std::make_shared<CShape>(16.0f, 3, sf::Color(0, 0, 255),
                                           sf::Color(255, 255, 255), 4.0f);

  m_LastEnemySpawnTime = m_CurrentFrame;
}

void Game::sEnemySpawner() { spawnEnemy(); }

void Game::sMovement() {}

void Game::sCollision() {}

void Game::sUserInput() {
  // Handle user inputs
  sf::Event event;
  if (event.type == sf::Event::Closed) {
    m_IsRunning = false;
  }

  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
    case sf::Keyboard::Space:
      m_IsPaused = true;
    default:
      std::cout << "Happy coding" << event.key.code << std::endl;
      return;
    }
  }
}

void Game::sRender() {
  // Ensure all objects are cleared before moving to the next frame
  m_Window.clear();

  for (auto &entity : m_EntityManager.getEntities()) {
    m_Window.draw(entity->cShape->circle);
  }
  // Draw objects
  m_Window.display();
}

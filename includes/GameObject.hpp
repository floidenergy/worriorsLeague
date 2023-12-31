#pragma once
#include <raylib.h>
#include <string>
#include <iostream>

class GameObject{
private:
  Rectangle object_rec;
  Vector2 position;
  float health;
  float base_damage;
  bool isLocal;
  std::string username;
public:
  GameObject(std::string username, Vector2 position, bool isLocal = false, float health = 100, float base_damage = 20) ;
  void transform(Vector2 _position);
  const Vector2 getPosition()const;
  void update();
  void draw();
  // void onCollision(GameObject* other){}; // pure virtual function, must be overridden in derived class
  int takeDamage(float damage);
  bool isAlive();
  void setUsername(std::string userName);
  std::string getUsername();
  ~GameObject() ;
};
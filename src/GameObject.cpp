#include <GameObject.hpp>

GameObject::GameObject(std::string username, Vector2 position, bool isLocal, float health, float base_damage) : username(username), position(position), isLocal(isLocal), health(health), base_damage(base_damage), object_rec({position.x, position.y, 50, 50}) {}

void GameObject::transform(Vector2 _position)
{
  this->position = _position;
}

const Vector2 GameObject::getPosition() const
{
  return this->position;
}

void GameObject::update() {}

void GameObject::draw()
{
  DrawRectanglePro(this->object_rec, {object_rec.x / 2, object_rec.y / 2}, 0, GREEN);
}

int GameObject::takeDamage(float damage)
{
  this->health = this->health - damage;
  return health;
}

bool GameObject::isAlive()
{
  return this->health <= 0;
}

void GameObject::setUsername(std::string username)
{
  this->username = username;
}

GameObject::~GameObject(){}
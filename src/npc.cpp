#include "npc.hpp"
#include <cmath>

NPC::NPC(const std::string& name, double x, double y, const std::string& type)
    : name_(name), x_(x), y_(y), type_(type) {}

const std::string& NPC::getName() const { return name_; }
double NPC::getX() const { return x_; }
double NPC::getY() const { return y_; }
const std::string& NPC::getType() const { return type_; }

double NPC::distanceTo(const NPC& other) const {
    double dx = x_ - other.x_;
    double dy = y_ - other.y_;
    return std::sqrt(dx * dx + dy * dy);
}
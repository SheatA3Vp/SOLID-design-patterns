#pragma once
#include "npc.hpp"

class Desman : public NPC {
public:
    Desman(const std::string& name, double x, double y);
    void accept(Visitor& visitor) override;
};
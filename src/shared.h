#pragma once

#include <string>

std::string GetName();

std::string* AllocateName();
void FreeName(std::string* value);

#include <string>

std::string* AllocateName()
{
	auto* name = new std::string("ABCDEFGHIJABCDEFGHIJABCDEFGHIJ");
	return name;
}

void FreeName(std::string* value)
{
	delete value;
}

std::string GetName()
{
	std::string name = "123456789012345678901234567890";
	return name;
}


#include "shared.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::cerr << "Start of test...\n";
	auto name = GetName();
	std::cerr << "name: " << name << '\n';
	std::cerr << "end of test!\n";
}

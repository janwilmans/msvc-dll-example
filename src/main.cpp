#include "shared.h"

#include <iostream>
#include <string>

void example_of_normal_string()
{
	{
		std::cerr << "Start example_of_normal_string...\n";
		{
			auto name = GetName();
			std::cerr << "name: " << name << '\n';

			// here the Application will try to free the std::string 'name' and fail!
		}
		std::cerr << "end example_of_normal_string!\n";
	}
}

void example_of_resource_handled_string()
{
	{
		std::cerr << "Start example_of_resource_handled_string...\n";
		{
			auto* name = AllocateName();
			std::cerr << "name: " << *name << '\n';
			FreeName(name);
		}
		std::cerr << "end example_of_resource_handled_string!\n";
	}
}

int main(int argc, char* argv[])
{
	example_of_resource_handled_string(); // this works with /MT (statically linking the runtime) or with /MD (dynamic linking the runtime)
	example_of_normal_string(); // this does NOT work with /MT (statically linking the runtime)
}

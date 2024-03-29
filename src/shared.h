#pragma once

#include <string>

std::string GetName();

std::string* AllocateName();
void FreeName(std::string* value);


__declspec(noinline) void RemoteRelease(std::string* object);

template <typename T>
class Remote
{
public:
	Remote(const T& object) : data(new T(object))
	{
	}

	T* data;

	~Remote()
	{
		RemoteRelease(data);
	}
};

Remote<std::string> GetRemoteName();

#pragma once
#include <string>
#include <unordered_map>

template<typename Resource>
class ResourceManager
{
public:
	ResourceManager(const std::string& folder, const std::string& extention) :
		folder("res/" + folder + "/"),
		extention("." + extention),
		resources()
	{
		
	}
	bool IsExist(const std::string& name)
	{
		return resources.contains(name);
	}

	Resource& Get(const std::string& name)
	{
		if (!IsExist(name))
			LoadAsset(name);
		return resources[name];
	}
	
private:
	void LoadAsset(const std::string& name)
	{
		auto fullpath = GetFullpath(name);
		Resource resource;
		bool result = resource.loadFromFile(fullpath);
		if (result)
		{
			resources.insert(std::make_pair(name, resource));
		}
		else
		{
			//todo
		}
	}
	std::string GetFullpath(const std::string& name)
	{
		return folder + name + extention;
	}
	std::string folder;
	std::string extention;
	std::unordered_map<std::string, Resource> resources;
};
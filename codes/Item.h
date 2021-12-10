#ifndef ITEM_H
#define ITEM_H
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <functional>
using namespace std;

class Item {
public:
	Item(int x, int y);

public:
	// this return the symbol for the for renderring
    virtual char get_symbol() = 0;
	virtual const std::string& get_effect_type()const;
    virtual void set_effect_val(int val);
	virtual int get_effect_val()const;

public:
	static std::string GetName();
	
public:
	int x_cor;
	int y_cor;
	int effect_val;
	std::string effect_type;
};


class CItemFactory
{
public:
	using CreateItem = std::function<std::shared_ptr<Item>(int, int)>;

    CItemFactory() = delete;

	static bool Register(const std::string& szName, CreateItem creater)
	{
		if (szName.empty())
		{
			return false;
		}
		auto& map = GetMap();
		auto it = map.find(szName);
		if (it == map.cend())
		{
			map[szName] = creater;
			return true;
		}

		return false;
	}

	static std::shared_ptr<Item> Create(const std::string& szName, int x, int y)
	{
		auto& map = GetMap();
		auto it = map.find(szName);
		if (it != map.cend())
		{
			return it->second(x, y);
		}
		return nullptr;
	}

	static std::map<std::string, CreateItem>& GetMap()
	{
		static std::map<std::string, CreateItem> s_map;
		return s_map;
	}
	
	static size_t GetKeys(std::vector<std::string>& arrKeys)
	{
		std::vector<std::string> arrTemp;
		auto& map = GetMap();
		for (auto i : map)
		{
			if (i.first.empty() == false)
			{
				arrTemp.emplace_back(i.first);
			}
		}
		arrKeys.swap(arrTemp);
		return arrKeys.size();
	}

};

template <typename T>
class ItemFactoryHelper
{
public:
	ItemFactoryHelper()
	{
		std::ignore = m_bRegistered;
	}

	static std::shared_ptr<Item> CreateItem(int x, int y);


protected:
	static bool m_bRegistered;
};

template <typename T>
std::shared_ptr<Item> ItemFactoryHelper<T>::CreateItem(int x, int y)
{
    return std::make_shared<T>(x, y);
}

template <typename T>
bool ItemFactoryHelper<T>::m_bRegistered = CItemFactory::Register(T::GetName(), ItemFactoryHelper::CreateItem);

#endif

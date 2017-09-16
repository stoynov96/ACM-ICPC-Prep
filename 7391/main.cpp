#include <unordered_map>
#include <iostream>
#include <string>

int main() {
	int T, num_cities;
	std::unordered_map<std::string, int> count_map;
	std::string city_name;

	std::cin >> T;

	while (T--)
	{
		std::cin >> num_cities;
		for (int i = 0; i < num_cities; i++)
		{
			std::cin >> city_name;
			count_map[city_name]++;
		}
		std::cout << count_map.size() << std::endl;
		count_map.clear();
	}

	return 0;
}
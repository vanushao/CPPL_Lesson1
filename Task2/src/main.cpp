#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>
#include <ctime>


std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}


int main(){
    setlocale(LC_ALL, "Russian");
    auto var = get_variant();
    if (std::holds_alternative<int>(var)){
        std::cout << std::get<int>(var)*2 << std::endl;
    }else if(std::holds_alternative<std::string>(var)){
        std::cout << std::get<std::string>(var) << std::endl;
    }else{
        for(auto v : std::get<std::vector<int>>(var)){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
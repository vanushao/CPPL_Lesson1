#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

const double PI = std::acos(-1);

int main(){
    setlocale(LC_ALL, "Russian");
    std::vector<double> angles;
    for (int i = 30; i <= 90; i+=30) angles.push_back(i*PI/180);

    std::vector<std::function<void (double)>> functions;

    functions.push_back([](double a){
        std::cout << "sin: " << std::sin(a) << " ";
        });
    functions.push_back([](double a){
        std::cout << "cos: " << std::cos(a) << " ";
        });
    //functions.push_back([](double a){
    //    std::cout << "tan: " << std::tan(a) << " ";
    //    });

    for (const auto& angle : angles) {
	    std::cout << angle << ": ";
	    for (const auto& function : functions)
		    function(angle);
	    std::cout << std::endl;
    }

    return 0;
}
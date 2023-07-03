#include <iostream>
#include <vector>
#include <algorithm>

void vprint (const std::string &s, const std::vector<int> &vec){
    std::cout << s << " ";
    for(const auto v : vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main(){
    setlocale(LC_ALL, "Russian");
    std::vector<int> vec = {4, 7, 9, 14, 12};
    vprint ("Input data:", vec);

    std::for_each(vec.begin(), vec.end(), [](int &n){
        n = (n%2 != 0)?n*3:n;
    });

    vprint ("Output data:", vec);

    return 0;
}
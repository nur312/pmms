#include <fstream>
#include <iostream>
#include <map>

int GetPermutationID(double a, double b, double c) {

    if(a <= b && b <= c) {
        return 0;
    } else if(a <= c && c <= b) {
        return 1;
    } else if(b <= a && a <= c) {
        return 2;
    } else if(b <= c && c <= a) {
        return 3;
    } else if(c <= a && a <= b) {
        return 4;
    } else if(c <= b && b <= a) {
        return 5;
    }


    return -1;
}


int main() {


    std::ifstream in{"random-nums.txt"};

    double a, b, c;
    std::map<int, int> map;

    for (int i = 0; i < 333; ++i) {

        in >> a >> b >> c;

        std::cout << a << b << c << GetPermutationID(a, b, c) << "\n";

        ++map[GetPermutationID(a, b, c)];
    }
    in.close();


    std::ofstream out{"permutations.txt"};

    for(const auto& p : map) {

        out << p.second << "\n";
    }
    out.close();

    return 0;
}
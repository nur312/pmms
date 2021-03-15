#include <fstream>

class Random{
private:
    int current = 1661;
public:

    double Next(){
        // Для этого берётся некое начальное четырёхзначное число z1 и возводится
        // в квадрат — получается восьмизначное число

        int sq = current * current;

        // Средние четыре цифры этого восьмизначного числа задают
        // следующий элемент этой последовательности

        int prev = current;

        current = (sq / 100) % 10000; //NOLINT


        // В конце укладываем все полученные числа в пределы от нуля до единицы простым способом
        return prev / 10000.0;
    }
};

int main() {

    Random rnd;

    std::ofstream out{"random-nums.txt"};

    for (int i = 0; i < 100; ++i) {

        out << rnd.Next() << "\n";
    }

    out.close();
    return 0;
}
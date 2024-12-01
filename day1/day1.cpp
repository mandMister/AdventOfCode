#include <iostream>
#include <fstream>
#include <cstring>

#include "slice.hpp"

int main() {
    std::ifstream file("input");
    if (!file.is_open()) {
        std::cerr << "Failed to open input file\n";
        return 1;
    }

    aoc::Slice<long> left, right;
    char line[256];

    while (file.getline(line, sizeof(line))) {
        char *tok = std::strtok(line, " \t");
        long val1 = tok ? std::atol(tok) : 0;

        tok = std::strtok(nullptr, " \t");
        long val2 = tok ? std::atol(tok) : 0;

        left.Append(std::move(val1));
        right.Append(std::move(val2));
    }

    file.close();

    left.Sort();
    right.Sort();

    if (left.Size() != right.Size()) {
        std::cerr << "Lists have different sizes\n";
        return 1;
    }

    long sum = 0;
    for (int i = 0; i < left.Size(); ++i) {
        sum += std::abs(left[i] - right[i]);
    }

    std::cout << "Part One: " << sum << std::endl;

    int score = 0;
    for (int i = 0; i < left.Size(); ++i) {
        int c = left[i];
        int n = 0;
        int j = 0;
        for (; j < right.Size() && c > right[j]; ++j) {
        }
        for (; j < right.Size() && c == right[j]; ++j, ++n) {
        }
        score += n * c;
    }

    std::cout << "Part Two: " << score << std::endl;

    return 0;
}

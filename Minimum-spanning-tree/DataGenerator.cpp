#include "DataGenerator.h"

std::vector<std::vector<int>> GenerateData(const std::string& filename) {
    std::vector<std::vector<int>> matrix;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<int> row;
            std::stringstream ss(line);
            std::string value;

            while (std::getline(ss, value, ',')) {
                row.push_back(std::stoi(value));
            }

            if (!row.empty()) {
                matrix.push_back(row);
            }
        }
    }
    file.close();
    return matrix;
}
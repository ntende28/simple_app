#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

void printTable(const std::vector<std::vector<std::string>> &table) {
    if (table.empty()) return;

    // Determine column widths
    std::vector<size_t> colWidths(table[0].size(), 0);
    for (const auto &row : table) {
        for (size_t i = 0; i < row.size(); ++i) {
            colWidths[i] = std::max(colWidths[i], row[i].size());
        }
    }

    // Print table with borders
    for (const auto &row : table) {
        std::cout << "+";
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << std::string(colWidths[i] + 2, '-') << "+";
        }
        std::cout << "\n|";

        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << " " << std::setw(colWidths[i]) << std::left << row[i] << " |";
        }
        std::cout << "\n";
    }

    // Print bottom border
    std::cout << "+";
    for (size_t i = 0; i < colWidths.size(); ++i) {
        std::cout << std::string(colWidths[i] + 2, '-') << "+";
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<std::string>> data = {
        {"ID", "Name", "Description"},
        {"1", "Alice", "A long description that wraps text properly"},
        {"2", "Bob", "Another long text here"},
        {"3", "Charlie", "Short text"}
    };

    printTable(data);
    return 0;
}

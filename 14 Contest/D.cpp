#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> bookCounts;
    std::vector<std::string> authors;

    for (int i = 0; i < N; ++i) {
        int type;
        std::cin >> type;

        if (type == 1) {
            std::string author;
            std::cin >> author;
            bookCounts[author]++;
            authors.push_back(author);
        } else if (type == 2) {
            int k;
            std::cin >> k;
            std::sort(authors.begin(), authors.end());

            if (k >= 1 && k <= authors.size()) {
                std::cout << authors[k - 1] << std::endl;
            }
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

class GridTraveller {
public:
    int gridTraveller(int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m == 0 || n == 0) {
            return 0;
        }
        return gridTraveller(m - 1, n) + gridTraveller(m, n - 1);
    }

    int gridTravellerMemo(int m, int n, std::unordered_map<std::string, int>& memo) {
        std::string key = std::to_string(m) + "," + std::to_string(n);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m == 0 || n == 0) {
            return 0;
        }
        memo[key] = gridTravellerMemo(m - 1, n, memo) + gridTravellerMemo(m, n - 1, memo);
        return memo[key];
    }
};

int main() {
    GridTraveller G;
    std::unordered_map<std::string, int> memo;
    std::cout << "enter the grid dimensions: " << std::endl;
    std::cout << "rows: ";
    int m, n;
    std::cin >> m;
    std::cout << "columns: ";
    std::cin >> n;
    std::cout << "regular :- " << G.gridTraveller(m, n) << std::endl;
    std::cout << "memoized :- " << G.gridTravellerMemo(m, n, memo) << std::endl;
    return 0;
}
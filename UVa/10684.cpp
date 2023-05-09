#include <iostream>

//input
// 5
// 12 -4
// -10 4
// 9
// 3
// -2 -1 -2
// 0

int main() {
    int n;
    while (std::cin >> n && n) {
        int max_streak = 0;
        int current_streak = 0;
        int bet;
        for (int i = 0; i < n; i++) {
            std::cin >> bet;
            std::cout <<"curr bet is" << bet << '\n';
            current_streak += bet;
            if (current_streak < 0) {
                current_streak = 0;
            }
            max_streak = std::max(max_streak, current_streak);
        }
        if (max_streak > 0) {
            std::cout << "The maximum winning streak is " << max_streak << "." << std::endl;
        } else {
            std::cout << "Losing streak." << std::endl;
        }
    }

    return 0;
}

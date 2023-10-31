// This is the 2023 update of this in C++
#include <iostream>
#include <string>
const int DMS = 17;

// Function to plot a straight line graph
void plot(int m, int c, std::string arr[DMS][DMS * 2 + 1]) {
    for (int x = -DMS; x <= DMS; x++) {
        if ((-(m * x + c) + DMS / 2) < DMS && (-(m * x + c) + DMS / 2) >= 0 && (x * 2 + DMS) < DMS * 2 + 1 && (x * 2 + DMS) >= 0) {
            arr[(-(m * x + c) + DMS / 2)][x * 2 + DMS] = "x";
        }
    }
}

int main() {
    try {
        std::string arr[DMS][DMS * 2 + 1];
        int m, c;
        
        std::cout << "Enter the gradient (m): ";
        std::cin >> m;

        std::cout << "Enter the y-intercept (c): ";
        std::cin >> c;

        if (std::cin.fail()) throw 1;

        // Initialize the array
        for (int i = 0; i < DMS; i++) {
            for (int j = 0; j < DMS * 2 + 1; j++) {
                arr[i][j] = (i == DMS / 2 ? std::string(1, '-') : (j == DMS ? std::string(1, char(197)) : " "));
            }
        }

        arr[DMS / 2][DMS] = std::string(1, char(197));

        plot(m, c, arr);

        // Print the graph
        for (int i = 0; i < DMS; i++, std::cout << "\n") {
            for (int j = 0; j < DMS * 2 + 1; j++) {
                std::cout << arr[i][j];
            }
        }

        return 0;
    } catch (int err) {
        std::cout << "Invalid input. Please try again.";
    }
}

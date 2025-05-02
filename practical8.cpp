#include <iostream>
#include <iomanip>

double bayes_theorem() {
    double P_six = 1.0 / 6.0;
    double P_not_six = 5.0 / 6.0;
    double P_truth = 0.75;
    double P_lie = 0.25;

    double P_says_six_given_six = P_truth;
    double P_says_six_given_not_six = P_lie * (1.0 / 5.0);

    double P_says_six = (P_says_six_given_six * P_six) + (P_says_six_given_not_six * P_not_six);
    double P_six_given_says_six = (P_says_six_given_six * P_six) / P_says_six;

    return P_six_given_says_six;
}

int main() {
    double result = bayes_theorem();
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Probability that it actually is a six: " << result 
              << " (" << result * 100 << "%)" << std::endl;
    return 0;
}

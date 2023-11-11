#include <iostream>
#include <vector>

// Function to calculate mean
double mean(const std::vector<double>& v) {
    double sum = 0;
    for (auto& i : v) sum += i;
    return sum / v.size();
}

// Function to calculate covariance
double covariance(const std::vector<double>& x, const std::vector<double>& y, double meanX, double meanY) {
    double sum = 0;
    for (size_t i = 0; i < x.size(); i++)
        sum += (x[i] - meanX) * (y[i] - meanY);
    return sum / (x.size() - 1);
}

// Function to calculate variance
double variance(const std::vector<double>& v, double meanV) {
    double sum = 0;
    for (auto& i : v) sum += (i - meanV) * (i - meanV);
    return sum / (v.size() - 1);
}

// Main function to perform linear regression
void linearRegression(const std::vector<double>& x, const std::vector<double>& y) {
    double meanX = mean(x);
    double meanY = mean(y);
    double a = covariance(x, y, meanX, meanY) / variance(x, meanX);
    double b = meanY - a * meanX;

    std::cout << "Linear Regression Equation: y = " << a << " * x + " << b << std::endl;
}

int main() {
    // Example usage
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 6, 8, 10};

    linearRegression(x, y);

    return 0;
}

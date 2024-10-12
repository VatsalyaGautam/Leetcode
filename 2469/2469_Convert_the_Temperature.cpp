#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        double Kelvin = celsius + 273.15;
        double Fahrenheit = celsius * 1.80 + 32.00;
        return {Kelvin, Fahrenheit};
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    double celsius;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    vector<double> result = solution.convertTemperature(celsius);

    cout << "Temperature in Kelvin: " << result[0] << endl;
    cout << "Temperature in Fahrenheit: " << result[1] << endl;

    return 0;
}
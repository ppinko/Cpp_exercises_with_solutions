/*
Implementation Task
 
Two real valued signals are given as:

1. A sine wave with a frequency of 10 Hz, an amplitude of 3 and a phase offset of 90°.
2. A symmetrical square wave with a frequency of 40 Hz, an amplitude of 1 and a phase offset of 0°.

1. Both signals shall be sampled with a sampling frequency of 200 Hz (for a duration of 1 second) 
into a data buffer and printed to the screen.
2. Create a third mixed signal by multiplying both, print it as well.
3. Compute the mean of the mixed signals first quarter (the first 0.25 seconds) and the integral 
of the second quarter. Print the results as well.
*/

/*
IMPORTANT ASSUMPTIONS:
a) It was assumed that sampling with a frequency of 200 Hz started at time = 0 s, and ended 
at time = 0.995 s. In total 200 measuring points.
b) Mean of first quarter was calculated as mean of first 50 points.
c) Integral of second quarter was calculated as integral of points in range 51-100 inclusive.
*/

#define M_PI           3.14159265358979323846  // pi

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

// function prototypes
float round_num(float value, int decimal_places);
float sin_wave(float time, float amplitude, float offset, float frequency);
float square_wave(float time, float amplitude, float offset, float frequency);

float round_num(float value, int decimal_places) {
    const float multiplier = std::pow(10.0, decimal_places);
    return std::round(value * multiplier) / multiplier;
}

float sin_wave(float time, float amplitude, float offset, float frequency){
    return amplitude * (std::sin(frequency * time * 2 * M_PI + offset));
    }

float square_wave(float time, float amplitude, float offset, float frequency){
    float answer {0};
    // initial offset 0.5 * M_PI to make square wave symmetrical to y-axis
    float temp = sin_wave(time, amplitude, offset + (0.5 * M_PI), frequency);
    float temp_rounded = round_num(temp, 2);
    if (temp_rounded > 0) answer = amplitude;
    else if (temp_rounded < 0) answer = -amplitude;
    return answer;
    }

int main() {
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "\nA sine wave with a frequency of 10 Hz, an amplitude of 3 and a phase offset of 90°:" <<std::endl;
    int i = 0;
    while (i < 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << "s, point = " << 
            sin_wave(t, 3, M_PI / 2, 10) << std::endl;
        i++;
        }
    i = 0;
    
    std::cout << "\nA symmetrical square wave with a frequency of 40 Hz, an amplitude of 1 and a phase offset of 0°:" <<std::endl;
    while (i < 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << "s, point = " << 
            square_wave(t, 1, 0, 40) << std::endl;
        i++;
        }
    i = 0;

    std::cout << "\nA mixed signal:" <<std::endl;
    std::vector<float> mixed_signal {};
    while (i < 200){
        float t = (float)i / 200;
        mixed_signal.push_back(square_wave(t, 1, 0, 40) * sin_wave(t, 3, M_PI / 2, 10));
        std::cout << i << ". time = " << t << "s, point = " << mixed_signal.back() 
            << std::endl;
        i++;
        }
    
    float mean_frst_quarter = (float)std::accumulate(mixed_signal.begin(), mixed_signal.begin() + 50, 0) / 50;
    std::cout << "\nMean of the mixed signals sin quarter = " << mean_frst_quarter << std::endl;
    
    // calculating estimated integral of second quarter based on vector mixed_signal
    // 3 - aplitude of sin wave, 4 - number of quarters, 10 - frequence of sin wave, 200 - sampling frequency
    float avg_density = (float)3 * 4 * 10 / 200;
    float integral_sd_quarter = (float)std::accumulate(mixed_signal.begin() + 50, mixed_signal.begin() + 100, 0) * avg_density;
    std::cout << "\nIntegral of the mixed signals second quarter = " << integral_sd_quarter << "\n\n";
    return 0;
}
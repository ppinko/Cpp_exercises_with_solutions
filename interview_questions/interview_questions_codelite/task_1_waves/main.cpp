#define M_PI           3.14159265358979323846  /* pi */

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

// function prototypes
float sin_wave(float time, float amplitude, float offset, float frequency);
float square_wave(float time, float amplitude, float offset, float frequency);

float sin_wave(float time, float amplitude, float offset, float frequency){
    return amplitude * (std::sin(frequency * time * 2 * M_PI + offset));
    }

float square_wave(float time, float amplitude, float offset, float frequency){
    float answer {0};
    // initial offset 0.25 * M_PI to make square wave symmetrical to y-axis
    float temp = sin_wave(time, amplitude, offset + (0.25 * M_PI), frequency);
    if (temp > 0) answer = amplitude;
    else if (temp < 0) answer = -amplitude;
    return answer;
    }

int main() {
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "\nA sine wave with a frequency of 10 Hz, an amplitude of 3 and a phase offset of 90°:" <<std::endl;
    int i = 1;
    while (i <= 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << "s, point = " << 
            sin_wave(t, 3, M_PI / 2, 10) << std::endl;
        i++;
        }
    i = 1;
    
    std::cout << "\nA symmetrical square wave with a frequency of 40 Hz, an amplitude of 1 and a phase offset of 0°:" <<std::endl;
    while (i <= 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << "s, point = " << 
            square_wave(t, 1, 0, 40) << std::endl;
        i++;
        }
    i = 1;

    std::cout << "\nA mixed signal:" <<std::endl;
    std::vector<float> mixed_signal {};
    while (i <= 200){
        float t = (float)i / 200;
        mixed_signal.push_back(square_wave(t, 1, 0, 40) * sin_wave(t, 3, M_PI / 2, 10));
        std::cout << i << ". time = " << t << "s, point = " << mixed_signal.back() 
            << std::endl;
        i++;
        }
    
    float mean_frst_quarter = (float)std::accumulate(mixed_signal.begin(), mixed_signal.begin() + 50, 0) / 50;
    std::cout << "\nMean of the mixed signals sin quarter = " << mean_frst_quarter << std::endl;
    
    // calculating estimated integral of second quarter based
    float avg_density = M_PI * std::pow(3, 2) * 0.5 * 10 / 100;
    float integral_sd_quarter = (float)std::accumulate(mixed_signal.begin() + 50, mixed_signal.begin() + 100, 0) * avg_density;
    std::cout << "\nIntegral of the mixed signals second quarter = " << integral_sd_quarter << std::endl;
    
    // TESTING
    
    std::cout << "\nTESTING SIN\n" << std::endl;
    i = 0;
    while (i <= 12){
        float t = (float)i / 12;
        std::cout << i << ". time = " << t << "s, point = " << 
            sin_wave(t, 1, 0, 1) << std::endl;
        i++;
        }
    std::cout << "\nCHANGING AMPLITUDE" << std::endl;
    i = 0;
    while (i <= 12){
        float t = (float)i / 12;
        std::cout << i << ". time = " << t << "s, point = " << 
            sin_wave(t, 3, 0, 1) << std::endl;
        i++;
        }
    
    std::cout << "\nCHANGING FREQUENCY" << std::endl;
    i = 0;
    while (i <= 12){
        float t = (float)i / 12;
        std::cout << i << ". time = " << t << "s, point = " << 
            sin_wave(t, 3, 0, 2) << std::endl;
        i++;
        }
    
    std::cout << "\nCHANGING OFFSET" << std::endl;
    i = 0;
    while (i <= 12){
        float t = (float)i / 12;
        std::cout << i << ". time = " << t << "s, point = " << 
            sin_wave(t, 3, M_PI / 2, 2) << std::endl;
        i++;
        }
//    std::vector<int> v {1, 1, 1, 2, 2, 3, 3, 4, 4};
//    float mean_test = (float)std::accumulate(v.begin(), v.begin() + 3, 0);
//    std::cout << "\nMean of the mixed signals sin quarter = " << mean_test << std::endl;
    return 0;
}
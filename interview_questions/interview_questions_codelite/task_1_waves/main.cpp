#define M_PI           3.14159265358979323846  /* pi */

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
    std::cout << "\nIntegral of the mixed signals second quarter = " << integral_sd_quarter << std::endl;
    
    // TESTING
    
//    std::cout << "\nTESTING SIN\n" << std::endl;
//    i = 0;
//    while (i <= 12){
//        float t = (float)i / 12;
//        std::cout << i << ". time = " << t << "s, point = " << 
//            sin_wave(t, 1, 0, 1) << std::endl;
//        i++;
//        }
//    std::cout << "\nCHANGING AMPLITUDE" << std::endl;
//    i = 0;
//    while (i <= 12){
//        float t = (float)i / 12;
//        std::cout << i << ". time = " << t << "s, point = " << 
//            sin_wave(t, 3, 0, 1) << std::endl;
//        i++;
//        }
//    
//    std::cout << "\nCHANGING FREQUENCY" << std::endl;
//    i = 0;
//    while (i <= 12){
//        float t = (float)i / 12;
//        std::cout << i << ". time = " << t << "s, point = " << 
//            sin_wave(t, 3, 0, 2) << std::endl;
//        i++;
//        }
//    
//    std::cout << "\nCHANGING OFFSET" << std::endl;
//    i = 0;
//    while (i <= 12){
//        float t = (float)i / 12;
//        std::cout << i << ". time = " << t << "s, point = " << 
//            sin_wave(t, 3, M_PI / 2, 2) << std::endl;
//        i++;
//        }
    
    // TESTING SQUARE WAVE
    
//    std::cout << "\nTESTING SQUARE\n" << std::endl;
//    i = -12;
//    while (i <= 12){
//        float t = (float)i / 12;
//        std::cout << i << ". time = " << t << "s, point = " << 
//            square_wave(t, 1, 0, 1) << std::endl;
//        i++;
//        }
    
//    std::vector<int> v {1, 1, 1, 2, 2, 3, 3, 4, 4};
//    float mean_test = (float)std::accumulate(v.begin(), v.begin() + 3, 0);
//    std::cout << "\nMean of the mixed signals sin quarter = " << mean_test << std::endl;
    return 0;
}
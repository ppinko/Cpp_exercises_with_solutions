#define M_PI           3.14159265358979323846  /* pi */

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cmath>

float first_wave(float time, float amplitude, float offset, float frequency);
float square_wave(float time, float amplitude, float offset, float frequency);

float first_wave(float time, float amplitude, float offset, float frequency){
    return amplitude * (std::sin(frequency * time * 2 * M_PI + offset));
    }

float square_wave(float time, float amplitude, float offset, float frequency){
    float answer {0};
    float temp = first_wave(time, amplitude, offset + (0.25 * M_PI), frequency);
    if (temp > 0) answer = amplitude;
    else if (temp < 0) answer = -amplitude;
    return answer;
    }

int main() {
    std::cout << "\nA sine wave with a frequency of 10 Hz, an amplitude of 3 and a phase offset of 90°:" <<std::endl;
    int i = 0;
    while (i <= 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << ", point = " << 
            first_wave(t, 3, M_PI / 2, 10) << std::endl;
        i++;
        }
    i = 0;
    
    std::cout << "\nA symmetrical square wave with a frequency of 40 Hz, an amplitude of 1 and a phase offset of 0°:" <<std::endl;
    while (i <= 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << ", point = " << 
            square_wave(t, 1, 0, 40) << std::endl;
        i++;
        }
    i = 0;

    std::cout << "\nA mixed signal:" <<std::endl;
    while (i <= 200){
        float t = (float)i / 200;
        std::cout << i << ". time = " << t << ", point = " << 
            square_wave(t, 1, 0, 40) * first_wave(t, 3, M_PI / 2, 10) << std::endl;
        i++;
        }
    return 0;
}
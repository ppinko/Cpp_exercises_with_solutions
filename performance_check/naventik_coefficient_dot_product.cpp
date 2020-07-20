/*
Having an array A of values <double> of length N and array C of coefficients <double> of
length K create an array of dot products for every length K in C.  
*/

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <deque>

std::vector<double> raw_dot_product(std::vector<int> &A, std::vector<double> &C);
std::vector<double> raw_dot_product_with_indexing(std::vector<int> &A, std::vector<double> &C);


std::vector<double> raw_dot_product(std::vector<int> &A, std::vector<double> &C){
    int N = A.size();
    int K = C.size();
    std::vector<double> result {};
    for (int i = 0; i < N - K + 1; ++i)
    {   
        double temp = 0;
        for (int j = 0; j < K; ++j)
        {
            temp += A[i+j] * C[j];
        }
        result.push_back(temp);        
    }
    return result;    
}

std::vector<double> raw_dot_product_with_indexing(std::vector<int> &A, std::vector<double> &C){
    int N = A.size();
    int K = C.size();
    std::vector<double> result (N-K+1, 0);
    for (int i = 0; i < N - K + 1; ++i)
    {   
        double temp = 0;
        for (int j = 0; j < K; ++j)
        {
            temp += A[i+j] * C[j];
        }
        result[i] = temp;        
    }
    return result;    
}

int main(){
    std::vector<int> Arr (1000000, 0);
    std::vector<double> Coeff (1000, 0);

    std::random_device crypto_random_generator;
    std::uniform_real_distribution<double> coeff_distribution(0,1);
    std::uniform_int_distribution<int> arr_distribution(0,9);

    for (int i = 0; i < 1000; ++i)
    {
        Coeff[i] = coeff_distribution(crypto_random_generator);
    }

    for (int i = 0; i < 1000000; ++i)
    {
        Arr[i] = arr_distribution(crypto_random_generator);
    }

    {
        auto raw_dot_product_start = std::chrono::high_resolution_clock::now();
        raw_dot_product(Arr, Coeff);
        auto raw_dot_product_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = raw_dot_product_end - raw_dot_product_start;
        std::cout << "Time needed for raw dot product algorithm = " << elapsed.count() 
            << "s.\n";
        // Result t = 6.30s
    }

    {
        auto raw_dot_product_start = std::chrono::high_resolution_clock::now();
        raw_dot_product_with_indexing(Arr, Coeff);
        auto raw_dot_product_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = raw_dot_product_end - raw_dot_product_start;
        std::cout << "Time needed for raw dot product with indexing algorithm = " << elapsed.count() 
            << "s.\n";
        // Result t = 6.23s
    }

    return 0;
}
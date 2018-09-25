#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "sort/heapSort.hpp"

int main()
{
    // INIT vector with random values
    std::vector<int> randomVector(7);
    auto limitRand = [](int &number) { number = number % 100; };
    std::generate(randomVector.begin(), randomVector.end(), rand);
    std::for_each(randomVector.begin(), randomVector.end(), limitRand);
    const std::vector<int> test = randomVector;

    for (int value : randomVector)
    {
        std::cout << value << std::endl;
    }
    std::cout << "--------------" << std::endl;
    heapSort(randomVector);
    for (int value : randomVector)
    {
        std::cout << value << std::endl;
    }
    /*std::cout << "--------------" << std::endl;
    for (int value : test)
    {
        std::cout << value << std::endl;
    }
    std::cout << "--------------" << std::endl;
    std::vector<int> result = mergeSort(test);
    for (int value : result)
    {
        std::cout << value << std::endl;
    }
    //std::reverse(randomVector.begin(), randomVector.end());
*/
    return 0;
}

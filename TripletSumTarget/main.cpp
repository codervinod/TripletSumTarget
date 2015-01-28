//
//  main.cpp
//  TripletSumTarget
//
//  Created by Vinod Gupta on 1/28/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>

void printArray(int ar[],int high)
{
    for (int i = 0; i < high; ++i)
    {
        std::cout << ar[i] << "\t";
    }
    std::cout << std::endl;
}

bool findTripletWithSum(int ar[], int high, int sum)
{
    for (int i = 0; i < high; ++i)
    {
        int itr = i+1;
        int revItr = high - 1;
        while (itr < revItr)
        {
            int tmp = ar[i] + ar[itr] + ar[revItr];
            if (tmp < sum)
            {
                ++itr;
            }
            else if (tmp > sum)
            {
                --revItr;
            }
            else
            {
                std::cout << ar[i] << "\t" << ar[itr] << "\t" << ar[revItr] << "\n";
                return true;
            }
        }
    }
    std::cout << "Not found" << std::endl;
    return false;
}

int main(int argc, char* argv[])
{
    int ar[] = { 3, 9, 2, 7, 34, 12, 42, 22, 52 };
    int high = sizeof ar / sizeof(int);
    
    printArray(ar, high);
    std::sort(std::begin(ar), std::end(ar));
    findTripletWithSum(ar, high, 51);
    return 0;
    
}

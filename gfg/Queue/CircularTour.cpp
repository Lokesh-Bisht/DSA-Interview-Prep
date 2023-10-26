/**
 * Copyright (C) 2023 Lokesh Bisht
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1?page=1&category[]=Queue&sortBy=submissions
 * 
 * TC => O(n)
 * SC => O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class PetrolPump {
    public:
        int petrol;
        int distance;
};

int tour(vector<PetrolPump> petrolPump, int n) {
    int start = 0, end = 1;
    int curPetrol = petrolPump[0].petrol - petrolPump[0].distance;
    while (start != end || curPetrol < 0) {
        while (start != end && curPetrol < 0) {
            curPetrol -= petrolPump[start].petrol - petrolPump[start].distance;
            start = (start + 1) % n;
            if (start == 0) {
                return -1;
            }
        }
        curPetrol += petrolPump[end].petrol - petrolPump[end].distance;
        end = (end + 1) % n;
    }
    return start;
}
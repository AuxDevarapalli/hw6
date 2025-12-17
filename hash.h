#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        //hold length of k for later loop exit
        int val=k.size()-1;
        //initialize
        unsigned long long w[5]={0,0,0,0,0};
        //this will allwo fo rus to go backwards
        for(int i=4;i>=0;i--){
            int num=1;
            //limit ot 6 characters ND STOP when k run out of length
            for(int z=0;z<6;z++){
                if(val<0){
                    break;
                }
                else{
                w[i]+=letterDigitToNumber(k[val])*(num);
                val-=1;
                //using multiplier instead of a power funciton
                num*=36;
                }
                if(val>0){
                    //
                }
            }
        }
        //use the equation givin in he instructions and return this value
        HASH_INDEX_T v=(rValues[0]*w[0])+(rValues[1]*w[1])+(rValues[2]*w[2])+(rValues[3]*w[3])+(rValues[4]*w[4]);
        return v;


    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        //meaning it is not a number
        //just checks each letter then uses its ascii value as starting value and substract from there
        if(letter>='a' && letter<='z'){
            return (letter-97);
        }
        if(letter>=48 && letter<=57){
            return (letter-22);
        }
        if(letter>='A'&& letter<='Z'){
            return (letter-65);
        }
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif

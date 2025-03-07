#pragma once
#include <bits/stdc++.h>
using namespace std;

class Passenger
{
private:
    string id;
    string name;
    int age;
    char gender;
    char berth;

public:
    Passenger() : id(""), name(""), age(0), gender('U'), berth('U') {}

    //setter functions
    void setId(int passenger_count);
    void setName(string name);
    void setAge(int age);
    void setGender(char gender);
    void setBerth(char berth);
    
    //getter functions
    string getId();
    string getName();
    int getAge();
    char getGender();
    char getBerth();
};

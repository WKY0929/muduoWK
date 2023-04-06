#pragma once
#include<iostream>
#include<mutex>
#include<thread>
#include<memory>
using namespace std;
class Singleton
{
private:
    Singleton();
public:
    static Singleton* m_instance;
    static Singleton* getInstance();
    void fun();
    static mutex mu_;
};
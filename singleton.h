#pragma once
//单例设计模式
template<class T>
class Singleton
{
protected:
    Singleton() = default;

private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    static T& GetInstance()
    {
        static T instance;
        return instance;
    }
};



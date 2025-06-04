#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal// [필수/도전 기능 구현 과제 HW02]
{
public:
    virtual void makeSound() = 0; // 순수가상함수 선언
    virtual void move() = 0;
};

class Zoo
{
private:
    Animal* animals[10];
    int count = 0;

public:
    void addAnimal(Animal* animal)
    {
        if (count < 10) // 배열 범위 확인
        {
            animals[count] = animal;
            count++;
        }
        else
        {
            cout << "동물원이 꽉 찼습니다." << endl;
        }
    }


    void performActions()
    {
        for (int i = 0; i < count; i++)
        {
            animals[i]->makeSound();
            animals[i]->move();
        }
    }




    ~Zoo()
    {
        for (int i = 0; i < count; i++)
        {
            delete animals[i];
        }
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "개가 짖습니다. 왈왈!" << endl;
    }
    void move()
    {
        cout << "개가 앞으로 달려갑니다." << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        cout << "고양이가 우네요. 야옹~" << endl;
    }
    void move()
    {
        cout << "고양이가 뒹굴뒹굴 구릅니다." << endl;
    }
};

class Cow : public Animal
{
public:
    void makeSound()
    {
        cout << "소가 기뻐보이네요. 음메~" << endl;
    }
    void move()
    {
        cout << "소는 지쳤는지 움직임이 없습니다." << endl;
    }
};

Animal* createRandomAnimal()
{
    int randNum = rand() % 3;

    if (randNum == 0)
    {
        return new Dog();
    }
    else if (randNum == 1)
    {
        return new Cat();
    }
    else
    {
        return new Cow();
    }
}


int main() 
{
    srand(time(0)); //랜덤 시드 초기화

    Zoo myZoo;

    for (int i = 0; i < 10; i++)
    {
        Animal* animal = createRandomAnimal();
        myZoo.addAnimal(animal);
    }

    cout << "동물원 개장 시간 입니다. 동물들이 활동을 시작합니다!" << endl;

    myZoo.performActions();

    return 0;
}

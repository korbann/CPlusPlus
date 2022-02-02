
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    char name[100];
    size_t age;
    size_t averageScore;

public:
    Person(const char*, size_t, size_t);

    const char* get_name() const { return name; }
    size_t get_age() { return age; }
    size_t get_averageScore() { return averageScore; }
};

Person::Person(const char* name_, size_t age_, size_t averageScore_)
{
    strcpy(name, name_);
    age = age_;
    averageScore = averageScore_;
}

bool compareScore(Person p1, Person p2)
{
    return (p1.get_averageScore() < p2.get_averageScore());
}

void sortByAverageScore(Person *array, size_t size)
{
    std::sort(array, array + size, compareScore);
}

double averageAge(Person* array, size_t size)
{
    double averageAge = 0;

    for (size_t i = 0; i < size; i++)
    {
        averageAge += array[i].get_age();
    }
    return averageAge / size;
}

int main()
{
    const size_t max_size = 10;

    Person personsArr[] = {
        Person("Korolchuk Vladislav", 15, 70),
        Person("Volozin Dmitry",      17, 73),
        Person("Krilaty Igor",        16, 85),
        Person("Voznesenskaya Julia", 16, 77),
        Person("Kuznetsov Roman",     14, 60),
        Person("Vilenski Ilya",       20, 54),
        Person("Konopatskaia Irina",  19, 24),
        Person("Sergeichik Ivan",     20, 88),
        Person("Davidovich Anton",    18, 92),
        Person("Frolov Pavel",        22, 94),
    };

    std::cout << averageAge(personsArr, max_size) << '\n';

    sortByAverageScore(personsArr, max_size);

    cout << "Persons sorted by average score : \n";
    for (int i = 0; i < max_size; i++)
        cout << "name: " << personsArr[i].get_name() << ", score: " << personsArr[i].get_averageScore() << '\n';

    return 0;
}
#include "FullSailCourse.h"
#include <iostream>

//definitions
void FullSailCourse::GetGrades(std::vector<float>& gradesToFill) const
{
    for (size_t i = 0; i < 10; i++)
    {
        gradesToFill.push_back(rand() % 10001 / 100.0);
    }
}

void FullSailCourse::ShowGrades(const std::vector<float>& gradesToShow) const
{
    std::cout << "\nPG2 Grades: 2410\n";
    for (auto& grade : gradesToShow)
    {
        std::cout << grade << "\n";
    }
}

std::string FullSailCourse::GetName() const
{
    return name_;
}

void FullSailCourse::SetName(const std::string& newName)
{
    if (newName.size() > 0)
        name_ = newName;
}

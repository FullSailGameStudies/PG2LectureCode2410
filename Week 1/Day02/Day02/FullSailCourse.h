#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	//declarations
	void GetGrades(std::vector<float>& gradesToFill) const;
	void ShowGrades(const std::vector<float>& gradesToShow) const;

	std::string GetName() const;
	void SetName(const std::string& newName);

private:
	std::string name_;
};


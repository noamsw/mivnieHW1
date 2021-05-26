#include <string>
class GradedModel{
public:
    int type;
    int model;
    int grade=0;
    int numsold=0;

    GradedModel();
    GradedModel(int type, int model);
    GradedModel(int type, int model, int grade, int numSold);
    GradedModel(const GradedModel& other) = default;
    void setGradedModel(int type, int model,int grade, int numsold);
    void complaint(int numMonths);
    GradedModel& operator=(const GradedModel& other) = default;
    bool operator==(const GradedModel& other) const;
    bool operator>(const GradedModel& other) const;
    bool operator<(const GradedModel& other) const;
    bool operator==(const GradedModel& other);
    bool operator>(const GradedModel& other);
    bool operator<(const GradedModel& other);
    friend std::ostream& operator<<(std::ostream& os, const GradedModel& car);
};
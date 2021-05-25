#ifndef MOST_SOLD_H_
#define MOST_SOLD_H_

#include "iostream"
#include "avl.h"

class MostSold{
public:
    int type;
    int model;
    int numsold=0;

    MostSold();
    MostSold(int type, int model, int numsold);
    MostSold(const MostSold& other) = default;
    MostSold& operator=(const MostSold& other) = default;
    void set(int type, int model, int numsold);
    bool operator==(const MostSold& other) const;
    bool operator>(const MostSold& other) const;
    bool operator<(const MostSold& other) const;
    bool operator==(const MostSold& other);
    bool operator>(const MostSold& other);
    bool operator<(const MostSold& other);
    friend std::ostream& operator<<(std::ostream& os, const MostSold& car);
};


#endif



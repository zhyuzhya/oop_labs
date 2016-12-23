#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
 
//5-угольник
class Pentagon {
public:
    Pentagon();
    Pentagon(size_t a);
    Pentagon(const Pentagon& orig);
 

    friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
    friend std::istream& operator>>(std::istream& is, Pentagon& obj);

    Pentagon& operator=(const Pentagon& right);
    friend Pentagon operator+(const Pentagon& left, const Pentagon& right);
    Pentagon& operator++();

    friend bool operator == (const Pentagon& left, const Pentagon &right ) {
        return (left.side == right.side);
    }
 
    virtual ~Pentagon();
private:
    size_t side;
};
 
#endif

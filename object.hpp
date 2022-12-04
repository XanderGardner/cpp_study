#ifndef OBJECT  // To make sure you don't declare the function more than once by including the header multiple times.
#define OBJECT

class Object
{
private:
    int m_day;

public:
    Object(int day); // constructor
    virtual ~Object(); // destructor

    void set_day(int day);
    int getDay()  { return m_day; }
};

#endif
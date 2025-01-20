#include <iostream>

// curiously recurring template pattern.
// CRTP
template <typename Derived>
class Base{
public:

private:
};


class Derived:public Base<Derived>{

};

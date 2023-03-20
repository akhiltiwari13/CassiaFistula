#include <iostream>
using namespace std;

// Defining a policy for creating objects.
// The gist of this design is combining multiple inheritance and templates
// Below are the implementation of the policy called policy classes.

// policy classes:
template <class T> struct OpNewCreator {
  static T *Create() { return new T; }
};

template <class T> struct MallocCreator {
  static T *Create() {
    void *buf = std::malloc(sizeof(T));
    if (!buf)
      return 0;
    return new (buf) T;
  }
};

template <class T> struct PrototypeCreator {
  PrototypeCreator(T *pObj = 0) : pPrototype_(pObj) {}
  T *Create() { return pPrototype_ ? pPrototype_->Clone() : 0; }
  T *GetPrototype() { return pPrototype_; }
  void SetPrototype(T *pObj) { pPrototype_ = pObj; }
private:
  T *pPrototype_;
};

int main(int argc, char **argv) { return 0; }

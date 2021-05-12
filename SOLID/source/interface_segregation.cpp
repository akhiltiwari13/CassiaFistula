/*
 * INTERFACE SEGREGATION- Clients should not be forced to depend on functions that it does not use.
 */

#include <iostream>
#include <vector>

struct Document; // Declaration.

// This is an interface that could do a bunch of processing with the IMachine.
struct IMachine
{
  virtual void print(std::vector<Document *> docs) = 0;
  virtual void scan(std::vector<Document *> docs) = 0;
  virtual void fax(std::vector<Document *> docs) = 0;
};

struct MFP : IMachine //multi-functional peripherals..
{
  void fax(std::vector<Document*> docs) override;
  void print(std::vector<Document*> docs) override;
  void scan(std::vector<Document*> docs) override;
};

// All of the 3 services i.e fax, print & scan.

/* These functionalities should be segregated in different interfaces. */
/* when multiple interfaces are required, a new interface can be created using multiple inheritance and a (concrete class) DECORATOR can be used. */

/**
 * @brief for testing the design pattern.
 * @return exit status
 */
int main()
{
return 0;
}

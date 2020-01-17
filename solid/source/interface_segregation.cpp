/*
 * Copyright (C) Edelweiss Securities Ltd., - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * 
 * File:   interface_segregation.cpp
 * Author: Akhil Tiwari <akhil.tiwari@edelweissfin.com>.
 * Created on 13 June, 2019, 3:25 PM.
 */

/*
 * INTERFACE SEGREGATION- No client should be forced to depend on methods (member function) it does not use.
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

//These functionalities should be segregated in different interfaces. OR a DECORATOR should be used.

/**
 * @brief for testing the design pattern.
 * @return exit status
 */
int main()
{

}
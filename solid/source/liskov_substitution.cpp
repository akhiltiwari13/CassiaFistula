/*
 * Copyright (C) Edelweiss Securities Ltd., - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * 
 * File:   liskov_substitution.cpp
 * Author: Akhil Tiwari <akhil.tiwari@edelweissfin.com>.
 * Created on 13 June, 2019, 10:42 AM.
 */

/**
 * @brief Liskov's substitution; named after Barbra Liskov, states that Objects should be replaceable with  instances of their sub-types without altering the correctness of the program.
 */

#include <iostream>

class Rectangle
{
protected:
  int hieght, width;

public:

  Rectangle(int hieght = 0, int width = 0) :
  hieght(hieght), width(width)
  {
  }

  virtual ~Rectangle()
  {
  }

  virtual int GetHieght() const
  {
    return hieght;
  }

  virtual void SetHieght(int hieght)
  {
    this->hieght = hieght;
  }

  virtual int GetWidth() const
  {
    return width;
  }

  virtual void SetWidth(int width)
  {
    this->width = width;
  }

  int Area()
  {
    return hieght*width;
  }
};

void ProcessRectangle(Rectangle& rect)
{
  int w = rect.GetWidth();
  rect.SetHieght(10);
  std::cout << "Expected Area=" << 10 * w << " Actual Area=" << rect.Area() << std::endl;
}

// Break Liskov's substitution by creating this child class.
class Square : public Rectangle
{
public:

  Square(int size = 0) :
  Rectangle(size, size)
  {
  }

  int GetHieght() const
  {
    return hieght;
  }

  void SetHieght(int hieght)
  {
    this->hieght = hieght;
    this->width = hieght; //for maintaining SQUARES' geometric properties.
  }

  int GetWidth() const
  {
    return width;
  }

  void SetWidth(int width)
  {
    this->width = width;
    this->hieght = width; //for maintaining SQUARES' geometric properties.
  }

  int Area()
  {
    return hieght*width;
  }

};

// ============================================================================
//                              MAIN
// ============================================================================

/**
 * @brief for testing the design pattern.
 * @return exit status
 */
int main()
{
  //create & use rectangle objects.
  std::cout << "for rectangle \n";
  Rectangle r(2, 3);
  ProcessRectangle(r);

  std::cout << "for square \n";
  Square s(4);
  ProcessRectangle(s); //This does not work as expected for a square object.

  /**
   * A solution could be to use a FACTORY to get the objects for rectangle and square. Also, a non polymorphic function may be used for altering rectangles size.
   */

}

// E.g This is  a sample factory struct.
struct RectangleFactory
{
  static Rectangle CreateRectangle(int w, int h);
  static Square CreateSquare(int w, int h);
};
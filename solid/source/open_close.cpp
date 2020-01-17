/*
 * Copyright (C) Edelweiss Securities Ltd., - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * 
 * File:   open_close_principal.cpp
 * Author: Akhil Tiwari <akhil.tiwari@edelweissfin.com>.
 * Created on 11 June, 2019, 3:20 PM.
 */

#include <iostream>
#include <string>
#include <vector>

enum class Color
{
  Red, Green, Blue
};

enum class Size
{
  Small, Medium, Large
};

struct Product
{
  std::string name;
  Size size;
  Color color;

  Product(std::string nm, Size sz, Color clr) : name(nm), size(sz), color(clr)
  {
  }

};

typedef std::vector<Product *> Items;

// ============================================================================
//               VIOLATION OF OPEN CLOSE PRINCIPLE.
// ============================================================================

/**
 * OPEN-CLOSE principle states that a class should be open for extension and 
 * closed for modification. It goes hand in hand with the SINGLE RESPONSIBILITY 
 * which says a class should have only one reason to change. 
 */
struct ProductFilter
{
  // one of the functions for filtering the product by size.

  static Items by_size(const Items& items, Size size)
  {
    Items result;
    for (auto& itr : items)
    {
      if (size == itr->size)
      {
        result.push_back(itr);
      }
    }
    return result;
  }

  static Items by_color(const Items& items, Color color)
  {
    Items result;
    for (auto& itr : items)
    {
      if (color == itr->color)
      {
        result.push_back(itr);
      }
    }
    return result;
  }

  static Items by_size_n_color(const Items& items, Size size, Color color)
  {
    Items result;
    for (auto& itr : items)
    {
      if ((color == itr->color) && (size == itr->size))
      {
        result.push_back(itr);
      }
    }
    return result;
  }
  // For any new filter category, a new member-function is needed to be added to 
  // this class. This is in violation of the open-close principle. This ProductFilter
  // class could have been designed based on the specification pattern.
};


// ============================================================================
//                    SPECIFICATION PATTERN
// ============================================================================

/**
 * BetterProductFilter is designed based on the SPECIFICATION pattern which
 * would make the base class/interface follow the open close principle.
 */
template<typename T>
struct ISpecification
{
  // This Interface defines satiation criteria.
  virtual bool is_satisfied(T* item) = 0;
};

/**
 * This generic base class is open for extension but closed for modification.
 */
template<typename T>
struct IFilter
{
  //This Interface defines filtration criteria.
  /**
   * 
   * @param items List of data to Filter.
   * @param specification The spec instance.
   * @return 
   */
  virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};

template<typename T>
struct AndSpecification : ISpecification<T>
{
  //This Interface defines filtration criteria based on 2 specification
  ISpecification<T>& spec_a;
  ISpecification<T>& spec_b;

  AndSpecification(ISpecification<T>& spec_a, ISpecification<T>& spec_b) :
  spec_a(spec_a), spec_b(spec_b)
  {
  }

  bool is_satisfied(T* item) override
  {
    return spec_a.is_satisfied(item) && spec_b.is_satisfied(item);
  }
};

struct BetterProductFilter : IFilter<Product>
{

  /**
   * 
   * @param items List of Product* to Filter
   * @param spec  The spec instance.
   * @return 
   */
  std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec) override
  {
    Items result;
    for (auto itr : items)
      if (spec.is_satisfied(itr))result.push_back(itr);
    return result;
  }
};

struct ColorSpecification : ISpecification<Product>
{
  Color color;

  ColorSpecification(const Color c) : color{c}
  {
    //constructor for this specification
  }

  bool is_satisfied(Product* product) override
  {
    return color == product->color;
  }
};

struct SizeSpecification : ISpecification<Product>
{
  Size size;

  SizeSpecification(const Size s) : size(s)
  {
    //constructor for this specification
  }

  bool is_satisfied(Product* product) override
  {
    return size == product->size;
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
  Product p1("dell xps 13", Size::Small, Color::Blue);
  Product p2("dell xps 15", Size::Medium, Color::Green);
  Product p3("dell inspirion", Size::Large, Color::Red);
  Product p4("macbook pro", Size::Large, Color::Green);
  Product p5("macbook air", Size::Small, Color::Blue);
  Product p6("razor blade", Size::Medium, Color::Green);

  Items inventory;
  inventory.push_back(&p1);
  inventory.push_back(&p2);
  inventory.push_back(&p3);
  inventory.push_back(&p4);
  inventory.push_back(&p5);
  inventory.push_back(&p6);

  Items filtered = ProductFilter::by_size(inventory, Size::Medium);
  std::cout << "filtered by size:\n";
  for (auto itr : filtered)std::cout << itr->name << std::endl;

  filtered = ProductFilter::by_color(inventory, Color::Red);
  std::cout << "filtered by color:\n";
  for (auto itr : filtered)std::cout << itr->name << std::endl;

  filtered = ProductFilter::by_size_n_color(inventory, Size::Medium, Color::Green);
  std::cout << "filtered by size n color:\n";
  for (auto itr : filtered)std::cout << itr->name << std::endl;

  // ============================================================================
  //                        TESTING SPECIFICATION PATTERN.
  // ============================================================================

  ColorSpecification csp(Color::Green);
  SizeSpecification sspec(Size::Medium);
//  AndSpecification<Product>& and_spec(sspec, csp);
  AndSpecification<Product> and_spec(csp,sspec);

  BetterProductFilter bpf;
  filtered = bpf.filter(inventory, csp);
  std::cout << "SPECIFICAION by Color:\n";
  for (auto itr : filtered)std::cout << itr->name << std::endl;

  filtered = bpf.filter(inventory, sspec);
  std::cout << "SPECIFICAION by Size:\n";
  for (auto itr : filtered)std::cout << itr->name << std::endl;

  filtered = bpf.filter(inventory, and_spec);
  std::cout << "SPECIFICAION by Size AND Color:\n";
  for (auto itr : filtered)std::cout << itr->name << std::endl;

}
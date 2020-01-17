/*
 * Copyright (C) Edelweiss Securities Ltd., - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * 
 * File:   builder_pattern.cpp
 * Author: Akhil Tiwari <akhil.tiwari@edelweissfin.com>.
 * Created on 14 June, 2019, 11:45 AM.
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
 * BUILDER PATTERN- When piecewise object construction is complicated, provides and API for doing it succinctly.
 * This program employs builder pattern in creating and HTML renderer.
 */

// for representing html tags.
struct HtmlElement
{
  std::string name;
  std::string text;
  std::vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement()
  {
  }

  HtmlElement(std::string name, std::string text) :
  name(name), text(text)
  {
  }

  // recursively prints out each element from the root.

  std::string str(int indent = 0) const
  {
    std::ostringstream oss;
    std::string i(indent_size*indent, ' '); // spaces to be inserted for indenting html tags.
    std::string iv(indent_size * indent + 1, ' '); //spaces for html texts.
    oss << i << "<" << name << ">"<<std::endl;
    if (text.size() > 0)
    {
      oss << iv << text << std::endl;
    }
    for (const auto& itr : elements)
    {
      oss << itr.str(indent + 1);
    }
    oss <<i << "<\\" << name << ">"<<std::endl;

    return oss.str();
  }
};

struct HtmlBuilder
{
  HtmlElement root; // the root element of the child.

  HtmlBuilder(std::string root_name)
  {
    root.name = root_name;
  }

  // logic for adding the element.

  void AddElement(std::string child_name, std::string child_text)
  {
    HtmlElement e(child_name, child_text);
    root.elements.push_back(e);
  }

  std::string str() const
  {
    return root.str();
  }
};

/**
 * @brief for testing the design pattern.
 * @return exit status
 */
int main()
{
  HtmlBuilder builder("ul");
  builder.AddElement("li", "hello");
  builder.AddElement("li", "world");
  std::cout << builder.str() << std::endl;

}
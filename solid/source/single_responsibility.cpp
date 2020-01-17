/*
 * Copyright (C) Edelweiss Securities Ltd., - All Rights Reserved.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 * Proprietary and confidential.
 * 
 * File:   single_responsibility.cpp
 * Author: Akhil Tiwari <akhil.tiwari@edelweissfin.com>.
 * Created on 11 June, 2019, 1:54 PM.
 */

#include <string>
#include <vector>
#include <fstream>

struct Journal
{
  std::string title;
  std::vector<std::string> entries;

  explicit Journal(const std::string& title) : title(title)
  {
  }

  /**
   * @brief Any real life journal would have entries corresponding to various title.
   * @param title, gets saved in entries.
   */
  void add(const std::string& entry)
  {
    entries.push_back(entry);
  }
};

// PersistanceManager takes the responsibility for persisting an in-memory entries
// to disk.
struct PersistanceManager
{
  static void save_to_disk(const Journal& journal, const std::string& filepath)
  {
    //create an output file stream from the provided file path.
    std::ofstream ofs(filepath);
    for (auto& itr : journal.entries)
    {
      ofs << itr << std::endl;
    }
  }
};

/**
 * @brief for testing the design pattern.
 * @return exit status
 */
int main()
{
  Journal j1("Akhil\'s Journal");
  j1.add("Harry Potter and Socerer\'s stone");
  j1.add("Harry Potter and The Chamber of secrets");
  j1.add("Harry Potter and The prisoner of Azkaban");
  j1.add("Harry Potter and The Goblet of Fire");
  
  PersistanceManager::save_to_disk(j1, "journal.txt");   
}

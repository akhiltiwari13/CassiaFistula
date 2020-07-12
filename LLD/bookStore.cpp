#include <bits/stdc++.h>
#include <chrono>
#include <cstdint>
#include <vector>
using namespace std;

class BookData {
public:
  BookData(uint16_t id, std::string author_name, uint16_t shelf,
           uint16_t cabinet)
      : id(id), authorName(author_name), cabinet(cabinet), shelf(shelf) {}

  uint16_t getId() { return this->id; }
  uint16_t getShelf() { return this->shelf; }
  uint16_t getCabinet() { return this->cabinet; }
  std::string getAuthorName() { return this->authorName; }
  std::string getBookName() { return this->bookName; }

private:
  uint16_t id;
  std::string bookName;
  std::string authorName;
  uint16_t shelf;
  uint16_t cabinet;
};

// a DTO perhaps?
struct BookSearchParam {
  uint16_t id;
  std::string bookName;
};

// global function to fetch data from records.
vector<BookData> getBookData(const BookSearchParam &param) {
  vector<BookData> searchResult;
  // search logic?

  return searchResult;
}

/* components of the API to be exposed. */
struct FindBookRequest {
  std::string bookName;
  std::string authorName;
};

struct FindBookResponse {
  uint16_t shelf;
  uint16_t cabinet;
};

vector<FindBookResponse> findBook(const FindBookRequest &param) {
  vector<FindBookResponse> apiSearchResult;
  // search logic?

  return apiSearchResult;
}

int main() { return 0; }

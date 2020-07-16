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
  std::string authorName; //@added, FindBookRequest should only have fields
                          // which are also present in BookSearchParam.
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

BookSearchParam formBookSearchParam(const FindBookRequest &param) {
  BookSearchParam result;
  if (!param.bookName.empty())
    result.bookName = param.bookName;
  if (!param.authorName.empty())
    result.authorName = param.authorName;

  return result;
}

vector<FindBookResponse> findBook(const FindBookRequest &param) {
  vector<FindBookResponse> apiSearchResult;
  // search logic?
  BookSearchParam bsParam = formBookSearchParam(param);
  auto bookSearchResultSet = getBookData(bsParam);

  for (auto book : bookSearchResultSet) {
    FindBookResponse bookLocation;
    bookLocation.cabinet = book.getCabinet();
    bookLocation.shelf = book.getShelf();
    apiSearchResult.push_back(bookLocation);
  }

  return apiSearchResult;
}

int main() { return 0; }

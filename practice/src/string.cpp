#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
  /*
   * namespace std{
   *  template<typename charT, typename traits=char_traits<charT>, typename Allocator=allocator<char T>>
   *  class basic_string;
   *
   *  typedef basic_string<char> string
   *  typedef basic_string<wchar> wstring; // supports unicode or some asian character.
   */

  /*
   * String & CStrings
   * 1. data() and c_str() will give c stype string. it has '\0' character in the end.
   * 2. copy() copies the content to char array. s.copy(a,100);
   * c_str() gets invalidated if we append more character because of rellocation.
   *
   * s = "hello"
   * char *p = s.c_str();
   * s+= "world";
   * p is invalidated pointer.
   *
   *
   * to remove all characters in the string do any of the following:
   * s = ""
   * s.clear();
   * s.erase();
   */

    // Input / output operators.
    // operator >> reads a string from input stream
    // operator << outputs string to output stream
    string s;
    getline(std::cin, s);
    cout<<s<<endl;
    // searching and finding

    s= "Hi Bill. I'm ill, so please pay the bill";
    s.find("il");          // returns 4 (first substring il"
    s.find("il", 10);      // returns 13 frm ill.
    s.rfind("il");         // returns 37 last substring bill.
    s.find_first_of("il"); // find first character that is part of "i" or "l".
    s.find_last_of("il");  // last char 'i' or 'l'
    s.find("hi");          // returns npos

    // if a search function fails, it returns string::npos ( -1 )
    //
    //Numeric conversions
    // stoi, stol, stoul, stoll, stod, to_string, to_wstring

    // iterator support for string.

  return 0;
}



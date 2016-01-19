#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <string>
#include <locale>
#include <map>
using namespace std;

std::locale loc;               // locale to use in string comparision
map<string, int> db;

typedef struct books{
  string title;
  string author;
  int borrowed;
  int returned;
  books(char *s, char *t): title(s), author(t),borrowed(0), returned(0){
  }
  books(const char *s): title(s), borrowed(0),returned(0){}
}Books;

bool mytitle_authorcomp(const Books b1, const Books b2){ 
  if(b1.author == b2.author) 
    return b1.title < b2.title ; 
  else return b1.author < b2.author;
}
bool mytitle_comp(const Books b1, const Books b2){ return b1.title < b2.title ; }

int getCode(char *command){
  if(strcmp(command, "BORROW") == 0) return 0;
  if(strcmp(command, "RETURN") == 0) return 1;
  if(strcmp(command, "SHELVE") == 0) return 2;
  return -1;
}

void printBooks(vector<Books> &vb){
  for(auto book : vb){
    cout<<book.title<<"   "<<book.author<<"   "<<book.borrowed<<" RET: "<<book.returned<<endl;
  }
}

void printShelve(vector<Books> &vb){
  int index = -1;
  for(int i=0; i < vb.size(); i++){
    if(vb[i].returned && index == -1){
      printf("Put \"%s\" first\n", vb[i].title.c_str());
      vb[i].borrowed = 0;
      vb[i].returned = 0;
    }
    else if(vb[i].returned){
      printf("Put \"%s\" after \"%s\"\n", vb[i].title.c_str(), vb[index].title.c_str());
      vb[i].borrowed = 0;
      vb[i].returned = 0;
    }
    if(vb[i].borrowed == 0)
      index = i;
  }
  printf("END\n");
}

vector<Books>::iterator findBook(vector<Books> &vb, string title){
  return vb.begin() + db[title];
}

int main(int argc, const char *argv[])
{
  char line[200], author[100], title[100];
  char command[100];
  vector<Books> vb;

  while(scanf("%[^\n]", line) && strcmp(line,"END")){
    //printf("%s\n", line);

    sscanf(line, "\"%[^\"]\"%*s %[^\n]",title,author);
    Books b(title, author);
    vb.push_back(b);

    getchar();
  }
  
  // sort the books
  std::sort(vb.begin(), vb.end(), mytitle_authorcomp);
  int index=0;
  for(auto book: vb){
    db[book.title] = index;
    index++;
  }
  getchar();
  while(scanf("%[^\n]", line) && strcmp(line, "END")){
    //printf("%s\n", line);
    sscanf(line,"%s \"%[^\"]\"", command, title);
    vector<Books>::iterator i;
    switch(getCode(command)){
      case 0: // borrow
        i = findBook(vb, string(title));
        i->borrowed=1;
        i->returned=0;
        break;
      case 2: // SHELVE
        //printBooks(vb);
        printShelve(vb);
        break;
      case 1: // return
        i = findBook(vb, string(title));
        i->returned = 1;
        i->borrowed = 0;
        break;
    }
    getchar();
  }
  return 0;
}

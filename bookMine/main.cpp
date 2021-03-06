//main.cpp
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

typedef map<string, int> strKeyintMap;
typedef multimap<int, string> intKeystrMap;


string alphaOnly(string str){
  string new_str;
  //new_str.reserve(str.length()); Avoid Allocations?
  //  however on larder files reduces runtime by 10%
  for(int i = 0; i < str.length(); i++){
    if(isalnum(str[i]))
      new_str += str[i];
  }

  return new_str;
}



void incrementWord(istream& in, strKeyintMap& word, set<string> c) {
  string str;
  
  while (in >> str){
    str = alphaOnly(str);
    if(c.count(str)){
    }
    else
      ++word[str];
  }
}

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B> &p){
  return std::pair<B, A> (p.second, p.first);
}

template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A, B> &src){
  std::multimap<B, A> dst;
  std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair<A, B>);
  return dst;

}



int main(int argc, char** argv){

  //Reading a list of common words from common.txt into a set: named "commons"
  ifstream cFile("common.txt");

  istream_iterator<string> start(cFile), end;
  set<string> commons(start, end);

  cFile.close();


  ifstream inFile(argv[1]);
  
  strKeyintMap words;
  incrementWord(inFile, words, commons);

  intKeystrMap topWords = flip_map(words);

  intKeystrMap::reverse_iterator p = topWords.rbegin();
  for(int i = 0; i < 20; i++){
  //for(intKeystrMap::reverse_iterator p = topWords.rbegin(); p!= topWords.rend(); ++p){
    cout << p -> second << " occurred " << p -> first << " times.\n";
    p++;
  }


  inFile.close();
  return 0;
}

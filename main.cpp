#include <iostream>
#include <vector>
#include <string>

std::string genLink(std::string keywrd){
  //Base link for cppreference, it will only be for cpp for now 
  std::string baseLink = "https://en.cppreference.com/w/cpp";

  //there are like 3 more, but i will go with these for the sake of conceptualization
  std::vector<std::string> containers = {
  "vector","map","span","unordered_map","array","tuple"
  };
  std::vector<std::string> strr = {
  "basic_string","char_traits","wstring"
  };
  std::vector<std::string> threadd = {
  "latch","thread","mutex","condition_variable"
  };

  std::string finalLink;
  
  auto checkType = [&](std::string l_keywrd) -> std::string{
    std::string rslt;
    for(auto& tmp : containers){
      if(l_keywrd == tmp){
        rslt = "container";
      }
    }
    for(auto& tmp : strr){
      if(l_keywrd == tmp){
        rslt = "string";
      }
    }
    for(auto& tmp : threadd){
      if(l_keywrd == tmp){
        rslt = "thread";
      }
    }
    return rslt;
  };

  finalLink = baseLink + "/" + checkType(keywrd) + "/" + keywrd;
  
  return finalLink;
}


int main() {
  std::cout << genLink("mutex");
}

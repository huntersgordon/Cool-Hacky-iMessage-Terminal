#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch);

string nextString(string after);

void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

string reverse(string str){
  string ret = "";
  for (int i = str.length()-1; i >= 0; i--){
    ret += str[i];
  }
  return ret;
}

int main(){

  ifstream inFile;
  inFile.open("temp.ichat");
  stringstream strStream;
  strStream << inFile.rdbuf();
  string conversation = strStream.str();
  reverseStr(conversation);

  std::vector<size_t> vec;

  // Get All occurrences of the 'is' in the vector 'vec'
	findAllOccurances(vec, conversation , reverse("NSArray"));
	for(size_t pos : vec)
    if (nextString(conversation.substr(pos+15)).find('-') != string::npos){ //we've found a hyphen
      //look for the string before it. cout it and the program will exit.
      cout << reverse(nextString(conversation.substr(conversation.find(nextString(conversation.substr(pos+15)))+nextString(conversation.substr(pos+15)).length()+8)));
      exit (EXIT_FAILURE);
    }

  findAllOccurances(vec, conversation , reverse("InstantMessage"));
  size_t ourGuy = 0; //impeccable nomenclature
	for(size_t pos : vec)
    if (nextString(conversation.substr(pos+15)).find('-') != string::npos){ //we've found a hyphen
      //look for the string before it. cout it and the program will exit.
      cout << reverse(nextString(conversation.substr(conversation.find(nextString(conversation.substr(pos+15)))+nextString(conversation.substr(pos+15)).length()+8)));
      exit (EXIT_FAILURE);
    }
  //find  the first reversed(</string>) to the next reversed(<string>) after that
}

string nextString(string after){
  unsigned first = after.find(reverse("</string>"));
  unsigned last = after.find(reverse("<string>"));
  return after.substr(first+9,last-first-9);
}

void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Add position to the vector
		vec.push_back(pos);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + toSearch.size());
	}
}

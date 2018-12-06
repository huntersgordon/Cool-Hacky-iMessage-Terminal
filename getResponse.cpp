#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reverseStr(string& str);
int nthSubstr(int n, const string& s,const string& p);
string reverse(string s);
string getMostRecentText(string file); //takes in the ascii text of a .ichat file converted to .plist.

int main(){

////////////////////////
string file = "";
string line = "";
ifstream myfile ("temp.ichat");
 if (myfile.is_open())
 {
   while ( getline (myfile,line) )
   {
     file += line;
   }
   myfile.close();
 }
 else cout << "Unable to open file";
///////////////////////////

 cout << getMostRecentText(file);

 return 0;
 }

 string getMostRecentText(string file){
   reverseStr(file);
   string strMarker =  "</string>";
   reverseStr(strMarker);
   //int marker = nthSubstr(2 , file , reverse("InstantMessage"));
   int marker = nthSubstr(3 , file , "yarrASN");
   string gettingThere = file.substr(marker);
   int secondStringMarker = nthSubstr(2 , gettingThere, strMarker);
   string almostThere = gettingThere.substr(secondStringMarker+9);
   string response = almostThere.substr(0,almostThere.find(reverse("<string>")));
   reverseStr(response);
   return response;

 }

 int nthSubstr(int n, const string& s,
              const string& p) {
   string::size_type i = s.find(p);     // Find the first occurrence

   int j;
   for (j = 1; j < n && i != string::npos; ++j)
      i = s.find(p, i+1); // Find the next occurrence

   if (j == n)
     return(i);
   else
     return(-1);
}

string reverse(string s){

  string ret = "";

  for (int i = s.length()-1; i >= 0; i--){
    ret += s[i];
  }

  return ret;


}

 void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

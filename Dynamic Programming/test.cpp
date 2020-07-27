// CPP program to illustrate substr() 
#include <string.h> 
#include <iostream> 
using namespace std; 

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

int main() 
{ 
  kush_gupta();

  std::string str="0123456789";
   
  std::string str2 = str.substr (2,5-(2-1));
  cout<<str2<<endl;
  /*std::size_t pos = str.find("live");

  std::string str3 = str.substr (pos);

  std::cout << str2 << ' ' << str3 << '\n';
*/
  return 0;
} 

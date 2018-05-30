// string::find_first_of
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t

int main ()
{
  int arr[3] = {2, 3, 5};
  for(int &i: arr){
      ++i;
  }

  std::cout << arr[0];

  return 0;
}
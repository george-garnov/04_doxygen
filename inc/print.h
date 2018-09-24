#include <iostream>
#include <string>
#include <vector>
#include <list>

template <bool condition, typename Type>
struct EnableIf;
 
template <typename Type>
struct EnableIf<true, Type>
{
    using type = Type;
};

void print(...)
{
    //
}


template <typename T>
typename EnableIf<std::is_integral<T>::value, void>::type
print(T value)
{
  size_t n = sizeof(T);
  while(n)
  {
    n--;
    std::cout << ((value >> n*8) & 0xFF);
    if (n) std::cout << ".";
  }
  std::cout << std::endl;
}

template <typename T>
decltype(begin(std::declval<T>()), end(std::declval<T>()), void())
print(T container)
{
  for(auto value : container)
  {
    print(value);
  }
  std::cout << std::endl;
}

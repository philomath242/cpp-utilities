#include <bits/stdc++.h>

using namespace std;

template <typename T> void print(T t) {
  cout << t;
  cout << "\n";
}

// recursive variadic function
template <typename T, typename... Args> void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}

int main() {

  print(3.14, "prashik", 's', 4);

  return 0;
}

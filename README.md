# Red-black tree
Red-black tree realization in C++

# Example:
```cpp
#include <iostream>
#include "Tree.h"
int main() {
  rbt::Tree<int, int> tree;
  
  tree.insert(4, 7);
  
  std::cout << "data at key 4:" << *(tree.find(4)) << std::endl;
    
  tree.remove(4);
}
```

Function ``` rbt::Tree::runDotty()``` need in installed [Gravhviz](https://www.graphviz.org/).
Function ``` testingVsMap() ``` need in installed [gnuplot](http://www.gnuplot.info/).

Сomparison rbt::Tree<int, int> with std::map<int,int> :
![i](insert)
![r](remove)
![f](find)

[insert]: https://raw.githubusercontent.com/pozdnyako/Red-black-tree/blob/master/plot/insert.png "i"
[remove]: https://raw.githubusercontent.com/pozdnyako/Red-black-tree/blob/master/plot/remove.png "r"
[find]: https://raw.githubusercontent.com/pozdnyako/Red-black-tree/blob/master/plot/find.png "f"

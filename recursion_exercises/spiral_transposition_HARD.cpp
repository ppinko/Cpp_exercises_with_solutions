/*
Create a function that takes a two-dimensional array as an argument and 
returns a one-dimensional array with the values of the original 2d array 
that are arranged by spiralling through it (starting from the top-left).

Examples:

spiralTransposition({
  {7, 2},
  {5, 0}
})

➞ {7, 2, 0, 5}

spiralTransposition({
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
})

➞ {1, 2, 3, 6, 9, 8, 7, 4, 5}

spiralTransposition({
  {1, 1, 1},
  {4, 5, 2},
  {3, 3, 2}
})

➞ {1, 1, 1, 2, 2, 3, 3, 4, 5}
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<int> spiralTransposition(std::vector< std::vector<int> > arr);
std::vector< std::vector<int> > vec_tranform (std::vector< std::vector<int> > arr);
std::vector<int> rec_spiralTransposition(std::vector< std::vector<int> > arr, std::vector<int> &v);

std::vector<int> spiralTransposition(std::vector< std::vector<int> > arr) {
  std::vector<int> v {};
  return rec_spiralTransposition(arr, v);
}

std::vector<int> rec_spiralTransposition(std::vector< std::vector<int> > arr, std::vector<int> &v) {
  std::vector< std::vector<int> > temp {arr};
  if (arr.size() == 1){
    for (auto element : arr.at(0)){
      v.push_back(element);
      }
    return v;
  }
  else {
    for (auto k: arr[0])
      v.push_back(k);
  }
  auto arr2 = vec_tranform(arr);
  return rec_spiralTransposition(arr2, v);
}

std::vector< std::vector<int> > vec_tranform (std::vector< std::vector<int> > arr){
    std::vector< std::vector<int> > temp {};
    int row_size = arr.at(0).size();
    for (int j {row_size - 1}; j >= 0; j--){
      std::vector<int> row {};
      for (int i {1}; i < arr.size(); i++){
        row.push_back(arr.at(i).at(j));  
      }
      temp.push_back(row);       
      row.clear(); 
    }
    return temp;
}

int main(){
  auto vec = spiralTransposition({{2, 4, 6, 8}, {7, 3, 0, 5}});
  for (auto i: vec){
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
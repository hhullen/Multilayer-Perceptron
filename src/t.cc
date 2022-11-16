#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::begin;
using std::cout;
using std::end;
using std::make_pair;
using std::map;
using std::stod;
using std::string;
using std::vector;

int main() {
  map<int, double> m;
  m[20] = 1.11;
  m[5] = 4.12456;
  cout << m[20] << "\n";
  cout << m[5] << "\n";
  // vector<double> v;
  // v[20] = 1.11;
  // map<int, char> abc({{1, 'V'},  {2, 'W'},  {3, 'X'},  {4, 'Y'},  {5, 'Z'},
  //                     {6, 'A'},  {7, 'H'},  {8, 'M'},  {9, 'N'},  {10, 'U'},
  //                     {11, 'I'}, {12, 'J'}, {13, 'L'}, {14, 'T'}, {15, 'E'},
  //                     {16, 'F'}, {17, 'P'}, {18, 'R'}, {19, 'K'}, {20, 'B'},
  //                     {21, 'C'}, {22, 'D'}, {23, 'G'}, {24, 'O'}, {25, 'Q'},
  //                     {26, 'S'}});

  // abc.emplace(make_pair(1, 'a'), 2, 'b');

  // for (auto &var : abc) {

  // cout << abc[1] << "\n";
  // cout << abc[3] << "\n";
  // }

  // size_t file_iter = 2;
  // string line = "12,0,255,2,45,0,0,0";
  // for (int i = 0; i < 7; ++i) {
  //   while (line[file_iter] < '0' || line[file_iter] > '9') {
  //     ++file_iter;
  //   }
  //   cout << stod(&line.data()[file_iter], nullptr) << "\n";
  //   while (line[file_iter] >= '0' && line[file_iter] <= '9') {
  //     ++file_iter;
  //   }
  // }
}

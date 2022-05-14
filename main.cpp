#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2096;

/*
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
*/

tuple<Node *, int, int, string>
testFixture1()
{
  auto root = new Node(5);
  root->left = new Node(1);
  root->left->left = new Node(3);

  root->right = new Node(2);
  root->right->left = new Node(6);
  root->right->right = new Node(4);

  return make_tuple(root, 3, 6, "UURL");
}

/*
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
*/

tuple<Node *, int, int, string>
testFixture2()
{
  auto root = new Node(2);
  root->left = new Node(1);

  return make_tuple(root, 2, 1, "L");
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto path = sol.getDirection(get<0>(f), get<1>(f), get<2>(f));
  cout << "Expect to see :" << get<3>(f) << endl;
  cout << path << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  auto path = sol.getDirection(get<0>(f), get<1>(f), get<2>(f));
  cout << "Expect to see :" << get<3>(f) << endl;
  cout << path << endl;
}

main()
{
  test1();
  test2();
  return 0;
}
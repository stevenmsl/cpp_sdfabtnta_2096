
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol2096
{

  class Solution
  {
  private:
    bool visit(Node *root, int val, string &path);

  public:
    string getDirection(Node *root, int start, int dest);
  };
}
#endif
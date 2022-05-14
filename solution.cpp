#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol2096;
using namespace std;

/*takeaways
  - the shortest path has to pass the LCA (least common ancestor)
  - use example 1 as an example
    from root to the start the path is LL
    from root to the dest the path is RL
  - so these two paths are different right from the get-go
    so the common prefix is empty meaning the root is the LCA
  - so all we have to do is to change LL to UU as we are walking
    up from the start to the root. From root to dest should
    remain the same RL
  - so the final path is UURL

*/

bool Solution::visit(Node *root, int val, string &path)
{
  if (root == nullptr)
    return false;
  if (root->val == val)
    return true;

  auto found = visit(root->left, val, path);
  if (found)
    path.push_back('L');
  else
  {
    found = visit(root->right, val, path);
    if (found)
      path.push_back('R');
  }
  return found;
}

string Solution::getDirection(Node *root, int start, int dest)
{
  string rs, rd;
  visit(root, start, rs);
  visit(root, dest, rd);
  const int m = rs.size(), n = rd.size();

  /*
    - the path was constructed backward from the
      bottom up so you need to reverse it
  */
  if (m)
    sort(rs.rbegin(), rs.rend());
  if (n)
    sort(rd.rbegin(), rd.rend());
  /* remove the common prefix as this was the path
     from the root to the lowest common ancestor
     which will not be included in the final path
  */
  auto i = 0;
  for (; i < min(m, n); i++)
    if (rs[i] != rd[i])
      break;
  string path;
  /* from LCA to start the path should all be changed to U */
  path += string(m - i, 'U');
  path += rd.substr(i);

  return path;
}
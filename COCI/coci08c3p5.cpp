#include <cstdio>
#include <map>
using namespace std;

int main() {
   int n;
   scanf("%d", &n);

   map<int, int> depth;
   long long  c = 0;
   for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      int d = 0;
      map<int, int>::iterator it = depth.lower_bound(x);
      if (it != depth.end()) {
        d = max(d, it->second+1);
      }
      if (it != depth.begin()) {
        d = max(d, (--it)->second+1);
      }
      depth[x] = d;
      c += d;
      printf("%lld\n", c);
   }
   
   return 0;
}
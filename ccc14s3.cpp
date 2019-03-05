#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	vector<char> results(t);

	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);

		stack<int> mountain;
		stack<int> branch;

		for (int j = 0; j < n; ++j)
		{
			int x;
			scanf("%d", &x);
			mountain.push(x);
		}

        int c = 1;

        while (true)
        {
            if (mountain.size() && mountain.top() == c)
            {
                mountain.pop();
                c++;
            }
            else if (branch.size() && branch.top() == c)
            {
                branch.pop();
                c++;
            }
            else if (mountain.size())
            {
                branch.push(mountain.top());
                mountain.pop();
            }
            else break;
        }

		if (branch.size() == 0 && mountain.size() == 0)
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
}
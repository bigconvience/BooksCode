#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec)
{
	cout << msg;
	for (int ix = 0; ix < vec.size(); ++ix)
	{
		elemType t = vec[ix];
		cout << t << ' ';
	}
	cout << endl;
}

int main()
{
	int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia +8 );
	string msg("vector before sort: ");

	display_message(msg, vec);
	return 0;
}

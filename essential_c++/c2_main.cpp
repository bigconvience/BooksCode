#include <iostream>
using namespace std;

bool fibo_elem( int pos, int &elem )
{
	if ( pos <= 0 || pos > 1024 ) 
	{
		cerr << "invalid position: " << pos
			<< " -- cannot handle request!\n";
	}

	elem = 1;
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix)
	{
		elem = n_2 + n_1;
		n_2 = n_1; n_1 = elem;
	}
	return true;
}

void prog1(）
{
	int pos;

	cout << "Please enter a position: ";
	cin >> pos;

	int elem;

	if ( fibo_elem( pos, elem ))
		cout << "element # " << pos
			<< " is " << elem << endl;
	else
		cout << "Sorry. Could not calculate element # "
			<< pos << endl;

	print_sequence( pos );
}

int main()
{
	prog1();

	return 0;
}
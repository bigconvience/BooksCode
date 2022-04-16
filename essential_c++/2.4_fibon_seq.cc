#include <iostream>
#include <vector>
using namespace std;

const vector<int> * fibon_seq(int);
void display( const vector<int> * );

int main() 
{
	int pos;

	cout << "Please enter a position: ";
	cin >> pos;

	const vector<int>* seq = fibon_seq(pos);

	if ( seq )
		display(seq);
	else
		cout << "Sorry. Could not calculate element # "
			<< pos << endl;

	return 0;
}

const vector<int> * fibon_seq(int size)
{
	const int max_size = 1024;
	static vector<int> elems;
   if ( size <= 0 || size > max_size ){
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " -- can’t fulfill request.\n";
        return 0;
	}

	for(int ix = elems.size(); ix < size; ++ix) {
		if (ix == 0 || ix == 1)
			elems.push_back(1);
		else
			elems.push_back( elems[ix - 1] + elems[ix - 2]);
	}

	return &elems;
}

void display( const vector<int>* vec )
{
	for ( int ix = 0; ix < vec->size(); ++ix )
		   cout << (*vec)[ix] << ' ';
	cout << endl;
}

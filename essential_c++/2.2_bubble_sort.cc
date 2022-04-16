#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void display ( vector<int> vec)
{
	for ( int ix = 0; ix < vec.size(); ++ix )
		cout << vec[ix] << ' ';
	cout << endl;
}

void swap ( int val1, int val2 )
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

void bubble_sort ( vector<int> vec)
{
	for ( int ix = 0; ix < vec.size(); ++ix)
		for ( int jx = ix + 1; jx < vec.size(); ++jx)
			if (vec[ix] > vec[jx])
				swap( vec[ix], vec[jx]);
}

ofstream ofil ("text_out1.out");
void bubble_sort2 ( vector<int> vec)
{
	for ( int ix = 0; ix < vec.size(); ++ix)
		for ( int jx = ix + 1; jx < vec.size(); ++jx)
			if (vec[ix] > vec[jx])
			{
				ofil << "about to call swap!"
				<< " ix: " << ix << " jx: " << jx << '\t'
				<< " swapping: " << vec[ix] << " with " << vec[jx] << endl;
 				swap( vec[ix], vec[jx]);
			}
}

void swap2(int val1, int val2)
{
	ofil << "swap(" << val1 << ", " << val2 << ")\n";

	int temp = val1;
	val1 = val2;
	val2 = temp;
	cerr << "after swap(): val1 " <<val1 << " val2: " << val2 << "\n";
}

void bubble_sort3( vector<int> vec )
{
	for ( int ix = 0; ix < vec.size(); ++ix )
		   for ( int jx = ix+1; jx < vec.size(); ++jx )
      			      if ( vec[ ix ] > vec[ jx ] )				  
                           swap2( vec[ix], vec[jx] );			
}

void swap3( int & val1, int & val2 )
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void display ( const vector<int> *vec)
{
	if (!vec) {
		cout << "display(): the vector pointer is 0\n";
		return;
	}
	for ( int ix = 0; ix < vec->size(); ++ix )
		cout << (*vec)[ix] << ' ';
	cout << endl;
}

void bubble_sort4 ( vector<int> vec)
{
	for ( int ix = 0; ix < vec.size(); ++ix)
		for ( int jx = ix + 1; jx < vec.size(); ++jx)
			if (vec[ix] > vec[jx])
			{
				cerr << "about to call swap!"
				<< " ix: " << ix << " jx: " << jx << '\t'
				<< " swapping: " << vec[ix] << " with " << vec[jx] << endl;
 				swap3( vec[ix], vec[jx]);
 				display(vec);
			}
}

void prog3()
{
	int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia +8 );

	cout << "vector before sort: ";
	display( &vec );
}

void prog2()
{
	int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia +8 );

	cout << "vector before sort: ";
	display( vec );

	bubble_sort( vec );

	cout << "vector after sort: ";
	display( vec );	
}

void prog2a()
{
    int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia+8 );

	cout << "vector before sort: ";
	display( vec ); 
    bubble_sort2( vec );
    cout << "vector after sort:  ";
	display( vec ); 
}

void prog2b()
{
    int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia+8 );

	cout << "vector before sort: ";
	display( vec ); 
    bubble_sort3( vec );
    cout << "vector after sort:  ";
	display( vec ); 
}

void prog2c()
{
    int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
	vector<int> vec( ia, ia+8 );

	cout << "vector before sort: ";
	display( vec ); 
    bubble_sort4( vec );
    cout << "vector after sort:  ";
	display( vec ); 
}

int main()
{
	// prog2();
	// prog2a();
	// prog2b();
	// prog2c();
	// prog3();
	return 0;
}
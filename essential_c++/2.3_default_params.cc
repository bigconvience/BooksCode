#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void swap( int &val1, int &val2, ofstream *ofil=0 )
{
	if ( ofil )
	   (*ofil) << "swap( " << val1 
               << ", " << val2 << " )\n";
	int temp = val1;
    val1 = val2;
    val2 = temp;
	if ( ofil )
	   (*ofil) << "after swap(): val1 " << val1 
               << "  val2: " << val2 << "\n";
}

void bubble_sort5( vector<int> &vec, ofstream *ofil = 0 )
{
	for ( int ix = 0; ix < vec.size(); ++ix )
		 for ( int jx = ix+1; jx < vec.size(); ++jx )
			  if ( vec[ ix ] > vec[ jx ] )	
			  {
				  if ( ofil != 0 ) {
		         (*ofil) << "about to call swap! ix: " << ix 
		                 << " jx: " << jx << "\tswapping: " 
		                 << vec[ix] << " with " << vec[ jx ] << endl;
		      }
          swap( vec[ix], vec[jx], ofil );
			  }
}

void display( vector<int> vec )
{
	for ( int ix = 0; ix < vec.size(); ++ix )
		   cout << vec[ix] << ' ';
	cout << endl;
}

void display( const vector<int> &vec, ofstream &os )
{
	for ( int ix = 0; ix < vec.size(); ++ix )
		   os << vec[ix] << ' ';
	os << endl;
}


void prog4()
{
   int ia[ 8 ] = { 8, 34, 3, 13, 1, 21, 5, 2 };
   vector<int> vec( ia, ia+8 );

   // no debug information -- 
   // it is as if we invoked bubble_sort( vec, 0 );
   // bubble_sort5( vec );
   display( vec );

   // ok: debug information generated ...
   //     the default value is not used ...
   ofstream ofil( "data.out" );
   bubble_sort5( vec, &ofil ); 
   display( vec, ofil );
}

int main()
{
	prog4();

	return 0; // to quiet vc6++
}
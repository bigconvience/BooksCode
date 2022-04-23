#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class even_elem {
public:
	bool operator()( int elem ) 
         { return elem%2 ? false : true; }
};

void ex3_4()
{
	vector< int > input;
	istream_iterator<int> in( cin ), eos;

	ofstream even_file( "even_file" ), 
              odd_file( "odd_file"  );

	if ( ! even_file || ! odd_file ){ 
         cerr << "arghh!! unable to open the output files. bailing out!";
	     return ;
	}

	copy( in, eos, back_inserter( input ));
	vector<int>::iterator division =
               partition( input.begin(), input.end(), even_elem() );

	ostream_iterator<int> even_iter( even_file, "\n" ), 
                           odd_iter( odd_file, " "  );

	copy( input.begin(), division, even_iter );
	copy( division, input.end(), odd_iter );
}


int main()
{
	ex3_4();
}

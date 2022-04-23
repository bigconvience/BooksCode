#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class LessThan {
public:
	bool operator()( const string &s1, const string &s2 ) 
	               { return s1.size() < s2.size(); }
};


template <typename elemType>
void display_vector( const vector<elemType> &vec,
                     ostream &os=cout, int len= 8 )
{
	typename vector<elemType>::const_iterator iter = vec.begin();
	typename vector<elemType>::const_iterator end_it = vec.end();

  int elem_cnt = 1;
  while ( iter != end_it ) 
	    os << *iter++
             << ( !(elem_cnt++ % len ) ? '\n' : ' ');
  os << endl;
}

void ex3_2()
{
  ifstream ifile( "MooCat.txt" );
	ofstream ofile( "MooCat.sort" );

  if ( !ifile || ! ofile ){
       cerr << "Unable to open file -- bailing out!\n";
       return;
  }

	vector<string> text;
  string word;

  while ( ifile >> word ) {
	  cout << word << ' ';
    text.push_back( word );
	}
  cout << "\n\n";

	sort( text.begin(), text.end(), LessThan() );

	for ( vector<string>::iterator it = text.begin();
	      it != text.end(); ++it )
			  cout << *it << ' ';
    cout << endl;

	display_vector( text, ofile );
}

int main() {
	ex3_2();
	return 0;
}
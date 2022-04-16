#include <vector>
#include <string>
#include <iostream>
using namespace std;

extern bool calc_elements( vector<int> &vec, int pos );
extern void really_calc_elems( vector<int> &vec, int pos );
extern void display_elems( vector<int>&, 
                                 const string&, ostream& = cout );

inline bool calc_elems( vector<int> &vec, int pos )
{
   if ( pos <= 0 || pos > 64 )
   {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
   }
 
   if ( vec.size() < pos )
        really_calc_elems( vec, pos );

   return true;
}

void really_calc_elems( vector<int> &vec, int pos )
{
	for ( int ix = vec.size()+1; ix <= pos; ++ix ){
	     // cout << "ix : " << ix << " == " << (ix*(3*ix-1))/2 << endl;
          vec.push_back( (ix*(3*ix-1))/2 );
	}
}

void display_elems( vector<int> &vec, const string &title,
                    ostream &os )
{
   os << '\n' << title << "\n\t";
   for ( int ix = 0; ix < vec.size(); ++ix ) 
          os << vec[ ix ] << ' ';
   os << endl;
}


void ex2_3() 
{
    vector<int> pent;
    const string title( "Pentagonal Numeric Series" );

    if ( calc_elems( pent, 0 ))
         display_elems( pent, title );

    if ( calc_elems( pent, 8 ))
         display_elems( pent, title );

    if ( calc_elems( pent, 14 ))
         display_elems( pent, title );

	if ( calc_elems( pent, 138 ))
         display_elems( pent, title );
}

int main(void)
{
	ex2_3();
	return 0;
}
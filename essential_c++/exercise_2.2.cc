#include <iostream>
#include <vector>
using namespace std;

extern void display_elems( vector<int>&, 
						   const string&, ostream& = cout );


bool calc_elements( vector<int> &vec, int pos ) 
{
   if ( pos <= 0 || pos > 64 )
   {
        cerr << "Sorry. Invalid position: "
             << pos << endl;
        return false;
   }

   for ( int ix = vec.size()+1; ix <= pos; ++ix ){
	     // cout << "ix : " << ix << " == " << (ix*(3*ix-1))/2 << endl;
         vec.push_back( (ix*(3*ix-1))/2 );
   }

   return true;
}

void display_elems( vector<int> &vec, const string &title,
                    ostream &os )
{
   os << '\n' << title << "\n\t";
   for ( int ix = 0; ix < vec.size(); ++ix ) 
	     os << vec[ ix ] << ' ';
   os << endl;
}


void ex2_2()
{
    vector<int> pent;
    const string title( "Pentagonal Numeric Series" );

    if ( calc_elements( pent, 0 ))
         display_elems( pent, title );

    if ( calc_elements( pent, 8 ))
         display_elems( pent, title );

    if ( calc_elements( pent, 14 ))
         display_elems( pent, title );

	if ( calc_elements( pent, 138 ))
         display_elems( pent, title );
}


int main() 
{
     ex2_2();
     return 0;
}


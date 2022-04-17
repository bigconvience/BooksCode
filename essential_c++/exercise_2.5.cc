#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline int max( int t1, int t2 )
       { return t1 > t2 ? t1 : t2; }

inline float max( float t1, float t2 )
       { return t1 > t2 ? t1 : t2; }

inline string max( const string& t1, const string& t2 )
       { return t1 > t2 ? t1 : t2; }

inline int max( const vector<int> &vec )
       { return *max_element( vec.begin(), vec.end() ); }

inline float max( const vector<float> &vec )
       { return *max_element( vec.begin(), vec.end() ); }

inline string max( const vector<string> &vec )
       { return *max_element( vec.begin(), vec.end() ); }

inline int max( const int *parray, int size )
       { return *max_element( parray, parray+size ); }

inline float max( const float *parray, int size )
       { return *max_element( parray, parray+size ); }

inline string max( const string *parray, int size )
       { return *max_element( parray, parray+size ); }

int main() 
{
    string sarray[]={ "we", "were", "her", "pride", "of", "ten" };
    vector<string> svec( sarray, sarray+6 );

    int iarray[]={ 12, 70, 2, 169, 1, 5, 29 };
    vector<int> ivec( iarray, iarray+7 );

    float farray[]={ 2.5, 24.8, 18.7, 4.1, 23.9 };
    vector<float> fvec( farray, farray+5 );

    int imax = max( max( ivec ), max( iarray, 7 ));
    float fmax = max( max( fvec ), max( farray, 5 ));
    string smax = max( max( svec ), max( sarray, 6 ));

	cout << "imax should be 169  -- found: " << imax << "\n"
	     << "fmax should be 24.8 -- found: " << fmax << "\n"
		 << "smax should be were -- found: " << smax << "\n";
}
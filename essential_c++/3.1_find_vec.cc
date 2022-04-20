#include <iostream>
#include <vector>
using namespace std;

// globals as convenience for executing procedures
const int int_size = 12;
const int string_size = 4;
const int int_not_present = 1024;

int    ia[int_size]    = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
string sa[string_size] = { "pooh", "piglet", "eeyore", "tigger" };

vector<int> ivec( ia, ia+int_size );
vector<string> svec( sa, sa+string_size );

template <typename elemType>
inline const elemType* 
vec_begin( const vector<elemType> &vec )
	 { return vec.empty() ? 0 : &vec[0]; }

template <typename elemType>
inline const elemType* 
vec_end(  const vector<elemType> &vec )
	{ return vec.empty() ? 0 : &vec[vec.size()]; }

const int* find_ver1(const vector<int> &vec, int value)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];
	return 0;
}

template <typename elemType>
const elemType* find_ver2(const vector<elemType> &vec, const elemType &value)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];
	return 0;
}

template <typename elemType>
const elemType* find_ver3(const elemType *array, int size, 
						const elemType &value)
{
	if (!array || size < 1)
		return 0;
	for (int ix = 0; ix < size; ++ix)
		if (array[ix] == value)
			return &array[ix];
	return 0;
}

template <typename elemType>
const elemType* find_ver4(const elemType *array, int size,
							const elemType &value)
{
	if (!array || size < 1)
		return 0;
	for (int ix = 0; ix < size; ++ix, ++array)
		if (*array == value)
			return array;
	return 0;
}

template <typename elemType>
const elemType* find_ver5( const elemType *first,
				const elemType *last, const elemType &value)
{
	if (!first || !last)
		return 0;
	for (; first != last; ++first)
		if (*first == value)
			return first;
	return 0;
}

void prog_find_vers()
{
    const int *iptr = find_ver1( ivec, ivec[2] );
	if ( iptr != &ivec[2] )
		 cerr << "?? find_ver1 failed!\n";
	else cerr << "!! find_ver1 ok!\n";

	const string* sptr = find_ver2( svec, svec[2] );
	if ( sptr != &svec[2] )
		 cerr << "?? find_ver2 failed with string!\n";
	else cerr << "!! find_ver2 ok with string!\n";

	iptr = find_ver3( ia, int_size, ia[2] );
	if ( iptr != &ia[2] )
		 cerr << "?? find_ver3 failed with int array!\n";
	else cerr << "!! find_ver3 ok with int array!\n";

	sptr = find_ver3( sa, string_size, sa[2] );
	if ( sptr != &sa[2] )
		 cerr << "?? find_ver3 failed with string array!\n";
	else cerr << "!! find_ver3 ok with string array!\n";

	iptr = find_ver4( vec_begin( ivec ), ivec.size(), ivec[2] );
	if ( iptr != &ivec[2] )
		 cerr << "?? find_ver4 failed with int vector!\n";
	else cerr << "!! find_ver4 ok with int vector!\n";

	sptr = find_ver4( vec_begin( svec ), svec.size(), svec[2] );
	if ( sptr != &svec[2] )
		 cerr << "?? find_ver4 failed with string vector!\n";
	else cerr << "!! find_ver4 ok with string vector!\n";

	iptr = find_ver5( vec_begin( ivec ), vec_end( ivec ), ivec[2] );
	if ( iptr != &ivec[2] )
		 cerr << "?? find_ver5 failed with int vector!\n";
	else cerr << "!! find_ver5 ok with int vector!\n";

	iptr = find_ver5( vec_begin( ivec ), vec_end( ivec ), int_not_present );
	if ( iptr != 0 )
		 cerr << "?? find_ver5 failed with int not present in vector!\n";
	else cerr << "!! find_ver5 ok with int not present in vector!\n";
}

int main()
{
	cerr << "About to execute prog_find_vers()\n\n";
	prog_find_vers();
	
	return 0; // quiet vc6++
}

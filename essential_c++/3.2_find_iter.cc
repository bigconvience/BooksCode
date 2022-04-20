#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// globals as convenience for executing procedures
const int int_size = 12;
const int string_size = 4;
const int int_not_present = 1024;

int    ia[int_size]    = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
string sa[string_size] = { "pooh", "piglet", "eeyore", "tigger" };

vector<int> ivec( ia, ia+int_size );
vector<string> svec( sa, sa+string_size );

template <typename IteratorType, typename elemType>
IteratorType find_ver6(IteratorType first, IteratorType last, const elemType &value)
{
	for (; first != last; ++first)
		if (value == *first)
			return first;
	return last;
}

void prog_find_vers()
{
	const string *sptr = find_ver6( sa, sa+string_size, sa[2] );
	if ( sptr != &sa[2] )
		 cerr << "?? find_ver6 failed with string array and iterators!\n";
	else cerr << "!! find_ver3 ok with string array and iterators!\n";

	vector< int >::iterator it;	
	it = find_ver6(  ivec.begin(), ivec.end(), ivec[2] );
	if ( *it != ivec[2] )
		 cerr << "?? find_ver6 failed with int vector and iterators!\n";
	else cerr << "!! find_ver4 ok with int vector and iterators!\n";
}


int main()
{
	cerr << "About to execute prog_find_vers()\n\n";
	prog_find_vers();
	
	return 0; // quiet vc6++
}
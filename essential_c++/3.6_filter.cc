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

vector<int> less_than_10(const vector<int> &vec)
{
	vector<int> nvec;
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] < 10)
			nvec.push_back(vec[ix]);
	return nvec;		
}

bool less_than( int v1, int v2 ) 
     { return v1 < v2 ? true : false; }

bool greater_than( int v1, int v2 ) 
     { return v1 > v2 ? true : false; }


vector<int> filter_ver1(const vector<int> &vec,
	int filter_value, bool (*pred)(int, int))
{
	vector<int> nvec;
	for (int ix = 0; ix < vec.size(); ++ix)
		if (pred(vec[ix], filter_value))
			nvec.push_back(vec[ix]);
	return nvec;
}

vector<int> 
filter_ver2( const vector<int> &vec, 
             int val, less<int> lt )
{
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    while (( iter = 
             find_if( iter, vec.end(), 
                      bind2nd( lt, val ))) != vec.end() )
    {
             // each time iter != vec.end(), 
             // iter addresses an element less than val
             nvec.push_back( *iter );
             iter++;
    }
    return nvec;
}

template <typename InputIterator, typename OutputIterator,
		typename ElemType, typename Comp>
OutputIterator
filter_ver3(InputIterator first, InputIterator last,
	OutputIterator at, const ElemType &val, Comp pred)
{
	while((first = find_if(first, last, bind2nd(pred, val))) != last)
	{
		cout << "found value: " << *first << endl;
		*at++ = *first++;
	}
	return at;
}

vector<int> sub_vec(const vector<int> &vec, int val)
{
	vector<int> local_vec(vec);
	sort(local_vec.begin(), local_vec.end());

	vector<int>::iterator iter =
		find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
	local_vec.erase(iter, local_vec.end());
	return local_vec;
}

void prog_filter_vers()
{
	const int solution_size = 6;

    vector<int> local_vec = less_than_10( ivec );
	if ( local_vec.size() != solution_size )
		 cerr << "?? less_than_10 failed! expected expected "
		      << solution_size << ", received: " 
		      << local_vec.size() << endl;
	else cerr << "!! less_than_10 ok!\n";

	const int partition_value = 10;
	local_vec = filter_ver1( ivec, partition_value, greater_than );

	if ( local_vec.size() != solution_size )
		 cerr << "?? filter_ver1 failed! expected expected "
		      << solution_size << ", received: "  
		      << local_vec.size() << endl;
	else cerr << "!! filter_ver1 ok!\n";

	local_vec = filter_ver2( ivec, partition_value, less<int>() );
	if ( local_vec.size() != solution_size )
		 cerr << "?? filter_ver2 failed! expected "
		      << solution_size << ", received: " 
		      << local_vec.size() << endl;
	else cerr << "!! filter_ver2 ok!\n";

	int ia2[ solution_size ];
	filter_ver3( ia, ia+int_size, ia2, partition_value, less<int>() );

	int err_cnt = 0;
	for ( int ix = 0; ix < solution_size; ++ix )
		  if ( ia[ ix ] != ia2[ ix ] )
			   ++err_cnt;

	if ( err_cnt )
		 cerr << "?? filter_ver3 failed for array! "
		      << err_cnt << " unexpected values\n";
	else cerr << "!! filter_ver3 for array ok!\n";

	vector<int> ivec2( solution_size );
	filter_ver3( ivec.begin(), ivec.end(), ivec2.begin(), 
                 partition_value, greater<int>() );

	err_cnt = 0;
	int ix = solution_size;

	for ( int iy = 0; ix < ivec.size(); ++ix, ++iy )
		  if ( ivec[ ix ] != ivec2[ iy ] )
			   ++err_cnt;

	if ( err_cnt )
		 cerr << "?? filter_ver3 failed for vector! "
		      << err_cnt << " unexpected values\n";
	else cerr << "!! filter_ver3 for vector ok!\n";

	// illustrate using an inserter
	vector<int> ivec3;
	filter_ver3( ivec.begin(), ivec.end(), back_inserter( ivec3 ), 
                 partition_value, greater<int>() );

	if ( ivec3.size() != solution_size )
		 cerr << "?? filter_ver3 with back inserter failed! expected "
		      << solution_size << ", received: " 
		      << ivec3.size() << endl;
	else cerr << "!! filter_ver3 with back inserter ok!\n";

	ivec3 = sub_vec( ivec, partition_value );
	if ( ivec3.size() != solution_size )
		 cerr << "?? sub_vec failed! expected "
		      << solution_size << ", received: " 
		      << ivec3.size() << endl;
	else cerr << "!! sub_vec ok!\n";

}

int main()
{
	cerr << "About to execute prog_filter_vers()\n\n";
    prog_filter_vers();

	cerr << "\n\nOk -- done!\n\n";
	return 0; // quiet vc6++
}
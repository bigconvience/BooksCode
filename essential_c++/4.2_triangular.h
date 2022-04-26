#ifndef TRINGULAR_H
#define TRINGULAR_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Triangular_iterator
{
public:
	Triangular_iterator(int index) : _index(index - 1){};
	bool operator==(const Triangular_iterator& ) const;
	bool operator!=(const Triangular_iterator& ) const;
	int operator*() const;
	Triangular_iterator& operator++();
	Triangular_iterator& operator++(int);

private:
	void check_integrity() const;
	int _index;
};

class Triangular {
	friend class Triangular_iterator;
public:
	Triangular(int len = 1, int bp = 1 );
	Triangular( const Triangular& );

	int length()  const { return _length;  }
	int beg_pos() const { return _beg_pos; }
	int elem( int pos ) const;

	void length( int nlen ) { _length = nlen; }
	void beg_pos( int npos ){ _beg_pos = npos; }

	bool next( int &val ) const;
	void next_reset() const { _next = 1; }

	static bool is_elem( int );
  	static void gen_elements( int length );
  	static void gen_elems_to_value( int value );
	static void display( int length, int beg_pos, ostream &os = cout );

	typedef Triangular_iterator iterator;

	Triangular_iterator begin() const
        { return Triangular_iterator( _beg_pos ); }

   Triangular_iterator end() const
        { return Triangular_iterator( _beg_pos+_length ); }

private:
	int _length;
	int _beg_pos;
	mutable int _next;

	enum { _max_elems = 1024 };
	static vector<int> _elems;
};

ostream&
operator<<( ostream &os, const Triangular &rhs )
{
    os << "( "
	    << rhs.beg_pos() << " , "
	    << rhs.length()  << " ) ";

    rhs.display( rhs.length(), rhs.beg_pos(), os );
    return os;
}

istream&
operator>>( istream &is, Triangular &rhs )
{
	char ch1, ch2;
	int bp, len;

   // given the input: ( 3 , 6 ) 6, 10, 15, 21, 28, 36 
   // ch1 == ‘(’, bp == 3, ch2 == ‘,’, len == 6
	is >> ch1 >> bp >> ch2 >> len;

   rhs.beg_pos( bp ); 
   rhs.length( len ); 
   rhs.next_reset();

	return is;
}

#endif
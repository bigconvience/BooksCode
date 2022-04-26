#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Stack {
public:    
	bool   push( const string& );
    bool   pop ( string &elem );
	bool   peek( string &elem );

    bool   find(  const string &elem ) const;
	int    count( const string &elem ) const;

	bool   empty() const { return _stack.empty(); }
	bool   full()  const { return _stack.size() == _stack.max_size(); }
	int    size()  const { return _stack.size(); }

private:
	vector<string> _stack;
};

bool
Stack::pop( string &elem ) 
{
    if ( empty() )
         return false;

    elem = _stack.back();
    _stack.pop_back(); 
    
    return true;
}

bool
Stack::peek( string &elem ) 
{
    if ( empty() )
         return false;

    elem = _stack.back();
    return true;
}

bool
Stack::push( const string &elem ) 
{
    if ( full() )
         return false;

    _stack.push_back( elem );
    return true;
}

#include <algorithm>

bool
Stack::find( const string &elem ) const
{
	vector<string>::const_iterator end_it = _stack.end();
	return std::find( _stack.begin(), end_it, elem ) != end_it;
}

int
Stack::count( const string &elem ) const 
{
	return std::count( _stack.begin(), _stack.end(), elem );
}

#endif
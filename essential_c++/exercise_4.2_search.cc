#include "exercise_4.1_stack.h"

void ex_4_2() 
{
	Stack st;

	cout << "Please enter a series of strings.\n";

    string str;
    while ( cin >> str && ! st.full() )
            st.push( str );

    cout << '\n'
	     << "Read in " << st.size() << " strings!\n";

	cin.clear();

	cout << "what word to search for? ";
	cin >> str;
    
	bool found = st.find( str );
	int  count = found ? st.count( str ) : 0;

	cout << str << (found ? " is " : " isn\'t " )
		 << "in the stack. ";

	if ( found ) 
		 cout << "It occurs " << count << " times\n";
}

int main() 
{
	ex_4_2();

	return 0;
}
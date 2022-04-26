#include "exercise_4.1_stack.h"

void ex_4_1() 
{

 	Stack st;
    string str;

	cout << "Please enter a series of strings.\n";
    while ( cin >> str && ! st.full() )
            st.push( str );

    if ( st.empty() ) {
         cout << '\n' << "Oops: no strings were read -- bailing out\n ";
         return;
	 }
         
    st.peek( str );
    if ( st.size() == 1 && str.empty() ) {
         cout << '\n' << "Oops: no strings were read -- bailing out\n ";
         return;
	 }

    cout << '\n' << "Read in " << st.size() << " strings!\n"
		   << "The strings, in reverse order: \n";

    while ( st.size() ) 
		 if ( st.pop( str ))
	         cout << str << ' ';
	
	cout << '\n' << "There are now " << st.size() 
		  << " elements in the stack!\n";
}

int main() 
{
	ex_4_1();

	return 0;
}
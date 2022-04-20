#include <iostream>
#include <string>
using namespace std;

#include "1.1_user.h"

int main()
{
	user_profile up;

	if ( greet_user( &up ) )
	{
		 play_game( &up );
		 display_statistics( &up );
	}

	return 0;
}





#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

typedef vector<string> vstring;

void populate_map( ifstream&, map<string,vstring> &families);
void display_map( const map<string,vstring> &families, ostream &os = cout );
void query_map( const string &family, const map<string,vstring> &families );

void ex3_3()
{
   map< string, vstring > families;

	ifstream nameFile( "families.txt" );
	if ( !nameFile ) {
			cerr << "Unable to find families.txt file. Bailing Out!\n";
			return;
	}

  populate_map( nameFile, families );

  string family_name;
  while ( 1 )
	{ 
		cout << "Please enter a family name or q to quit ";
		cin >> family_name;
		if ( family_name == "q" )
		 	break;
     	query_map( family_name, families );
	}
	display_map( families );
}

void populate_map( ifstream &nameFile,
				   map<string,vstring> &families )
{
	string textline;
	while ( getline( nameFile, textline, '\n' ))
	{
   	    string fam_name;
	    vector<string> child;
		cout << "textline: " << textline << endl;

	    string::size_type pos = 0, prev_pos = 0, 
			              text_size = textline.size();

		if ( ! text_size )
			 continue;

        // ok: find each word separated by a space
   	    while ((  pos = textline.find_first_of( ' ', pos )) 
                     != string::npos )
		{
		    string::size_type end_pos = pos-prev_pos;
		    if ( ! prev_pos )
			     fam_name = textline.substr( prev_pos, end_pos  );
		    else child.push_back(textline.substr(prev_pos,end_pos));
			prev_pos = ++pos;
		}
     
		// now handle last child
		if ( prev_pos < text_size )
			 child.push_back(textline.substr(prev_pos,pos-prev_pos)); 

		cout << "family name: " << fam_name
			 << " children: "   << child.size() << endl;

	    if ( ! families.count( fam_name ))
	         families[ fam_name ] = child;
        else cerr << "Oops! We already have a "
                  << fam_name << " family in our map!\n";
	}
}

void display_map( const map<string,vstring> &families, ostream &os )
{
	map< string, vstring >::const_iterator 
			     it = families.begin(), 
                 end_it = families.end();

	while ( it != end_it )
	{
		    os << "The "
			   << it->first  // print out family name
			   << " family ";

			if ( it->second.empty() )
			     os << "has no children\n";
            else 
			{  // print out vector of children
                os   << "has " << it->second.size() 
                     << " children: ";

			    vector< string >::const_iterator 
                        iter = it->second.begin(),
                        end_iter = it->second.end();
			      
			    while ( iter != end_iter ) 
				      { os << *iter << " "; ++iter; }
				os << endl;
			}

			++it;
	}
}

void query_map( const string &family, const map<string,vstring> &families ) 
{
	map<string,vstring>::const_iterator it = families.find( family );
	if ( it == families.end() ) 
	{
		 cout << "Sorry. The "
			  << family << " family is not currently entered.\n";
		return;
	}
		
	cout << "The " << family << " family "; 
    if ( ! it->second.size() )
		 cout << " has no children\n";
	else 
    {     // print out vector of children
          cout << " has " << it->second.size() 
               << " children: ";

		  vector< string >::const_iterator 
                    iter = it->second.begin(),
                    end_iter = it->second.end();
			      
		  while ( iter != end_iter ) 
			    { cout << *iter << " "; ++iter; }
		  cout << endl;
	}
}

int main() {
	ex3_3();
	return 0;
}
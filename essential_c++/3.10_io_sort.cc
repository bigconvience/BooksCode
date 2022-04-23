#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;

void prog_std()
{
	string word;
	vector<string> text;

	while(cin >> word)
		text.push_back(word);

	sort(text.begin(), text.end());

	for (int ix = 0; ix < text.size(); ++ix)
		cout << text[ix] << ' ';
}

void prog_io_std()
{
	istream_iterator<string> is(cin);
	istream_iterator<string> eof;

	vector<string> text;
	copy(is, eof, back_inserter(text));

	sort(text.begin(), text.end());

	ostream_iterator<string> os(cout, " ");
	copy(text.begin(), text.end(), os);
}

void prog_io_fill()
{
	ifstream in_file("3.10_input_file.txt");
	ofstream out_file("3.10_output_file.txt");

	if (!in_file || !out_file)
	{
		cerr << "?? unable to open the necessary files.\n";
		return;
	}
	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;

	vector<string> text;
	copy(is, eof, back_inserter(text));

	sort(text.begin(), text.end());

	ostream_iterator<string> os(out_file, " ");
	copy(text.begin(), text.end(), os);
}

void prog_io_iters()
{
	// prog_std();
	// prog_io_std();

	prog_io_fill();
}

int main()
{
	cerr << "\n\nAbout to execute prog_io_iters()\n\n";
	prog_io_iters();

	cerr << "\n\nOk -- done!\n\n";
	return 0; // quiet vc6++
}
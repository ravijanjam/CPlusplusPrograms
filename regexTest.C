#include <iostream>
#include <regex>

void regexTest(){


	string rexp[100], s[100], ss, tg, rg;

	s[0] = "this subject has a submarine";
	s[1] = "987256, 8839";
	s[2] = "goat@milk.com";

	smatch m;
	
	rexp[0] = "\\b(sub)([^ ]*)";
	rexp[1] = "[[:digit:]]+";
	/* matches a word */
	rexp[2] = "\\w+";

	// Loop over input strings
	for (int i=0; i<4; i++){

	cout << "============================== " << endl;
	cout << "Target sequence: " << s[i] << endl;
	string msg = "The following matches and submatches were found  ";
	msg += rexp[i];
	cout << msg << endl;

	ss = s[i];
	regex e(rexp[i]);

	// Loop over strings
	cout << "Results : " << endl;
	while (regex_search(ss, m, e)){
		for (auto x:m) cout << x << ", ";
		ss = m.suffix().str();
		//cout << ss;
		} 
	cout << endl;
	}
	
} //close - regexTest



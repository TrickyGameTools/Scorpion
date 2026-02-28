// License:
// 
// Scorpion
// Base Pipe Loader
// 
// 
// 
// 	(c) Jeroen P. Broks, 2026
// 
// 		This program is free software: you can redistribute it and/or modify
// 		it under the terms of the GNU General Public License as published by
// 		the Free Software Foundation, either version 3 of the License, or
// 		(at your option) any later version.
// 
// 		This program is distributed in the hope that it will be useful,
// 		but WITHOUT ANY WARRANTY; without even the implied warranty of
// 		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// 		GNU General Public License for more details.
// 		You should have received a copy of the GNU General Public License
// 		along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// 	Please note that some references to data like pictures or audio, do not automatically
// 	fall under this licenses. Mostly this is noted in the respective files.
// 
// Version: 26.02.28
// End License

#define Always_Be_Verbose

#include <stdio.h>
#include <iostream>

#include <SlyvQCol.hpp>
#include <SlyvString.hpp>

using namespace std;
using namespace Slyvina;
using namespace Slyvina::Units;

std::string Chain{""};
bool Verbose{false};

inline void Out(String T,String V) {
#ifndef Always_Be_Verbose
	if (!Verbose) {
#endif // Always_Be_Verbose
		QCol->LMagenta(T+"> ");
		QCol->Grey(V);
#ifndef Always_Be_Verbose
	}
#endif // Always_Be_Verbose
}
inline void Out(String V) { Out("Pipe",V); }

int main(int c, char**a) {
	FILE* bt;
	char buff[512];
	for (int i=1;i<c;++i) {
		Verbose=Verbose || Upper(a[i])=="VERBOSE";
	}

	Chain="Scorpion_GUI";
	do {
		if(!(bt = popen(Chain.c_str(), "r"))){
			QCol->Error("Pipe failed");
			QCol->LMagenta(Chain+"\n\n");
			QCol->Reset();
			return 1;
		}
		Chain="";
		while(fgets(buff, sizeof(buff), bt)!=NULL ) {
			Out(buff);
		}
	} while(Chain!="");
	pclose(bt);
	return 0;
}

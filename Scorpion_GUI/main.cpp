// License:
//
// Scorpion
// C++ Main file
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
#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>

#include <SlyvQCol.hpp>


#include "UI_Main.hpp"

int main( int argc, char * argv[] )
{
	QCol->Doing("Scorpion","GUI");
	QCol->Doing("Coded by","Jeroen P. Broks");

	Slyvina::Scorpion::Init();
	Slyvina::Scorpion::Run();
	Slyvina::Scorpion::Done();

}

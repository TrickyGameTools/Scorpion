// License:
//
// Scorpion
// Main User Interface Manager
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
// Version: 26.02.28 I
// End License
#include <SlyvString.hpp>
#include <SlyvQCol.hpp>

#include "UI_Main.hpp"
#include "UI_Overview.hpp"

using namespace Slyvina::TQSG;
using namespace Slyvina::TQSE;
using namespace Slyvina::Units;
using namespace Slyvina::June19;

namespace Slyvina {
	namespace Scorpion {
		bool GoOn{true};
		std::map<std::string,CB> CB::Register {};
		void CB::Activate(std::string key) {
			Trans2Upper(key);
			for(auto&A:Register) A.second.Gadget->Visible=key==A.first;
		}

		June19::j19gadget* CB::Get(std::string Key){
			Trans2Upper(Key);
			if (!Register.count(Key)) {
				Register[Key].Tag=Key;
				Register[Key].Gadget=CreatePanel(0,0,WorkScreen()->W(),WorkScreen()->H(),WorkScreen());
				Register[Key].Gadget->Visible=true;
				QCol->Doing("Created Panel",Key);
			}
			return Register[Key].Gadget;
		}

		void FatalError(std::string M) {
			QCol->Error(M);
			TQSE::Notify("Fatal Error:\n\n"+M);
			GoOn=false;
		}


		void Init(){
			Graphics(1800,1200,"Scorpion");
			InitOverview();
			CB::Activate("OVERVIEW");
		}
		void Run(){
			while(GoOn){
				Cls();
				Poll();
				if (AppTerminate()) {GoOn=false; return;}
				WorkScreen()->Draw();
				Flip();
			}
		}


		void Done(){
			CloseGraphics();
		}
	}
}

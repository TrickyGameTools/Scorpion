
#include <SlyvQCol.hpp>
#include <SlyvDirry.hpp>
#include <SlyvGINIE.hpp>
#include <SlyvString.hpp>

#include "Chosen.hpp"

using namespace Slyvina::Units;

namespace Slyvina {
	namespace Scorpion{

		static GINIE _Config{nullptr};
		static std::map<std::string,TChosen> _CReg{};

		GINIE CFG(){
			std::string _CFGFile{Dirry("$AppSupport$/ScyndiCreativeInterpreter/GlobalConfig.ini")};
			if (!_Config) {
				QCol->Doing("Loading",_CFGFile);
				_Config=LoadOptGINIE(_CFGFile,_CFGFile,"Scyndi's Creative Interpreter!\nConfig file\nLast saved by Scorpion");
			}
		}

		void ScanForGames(){
			_CReg.clear();
		}
		void ScanForGames(June19::j19gadget* G) {
			ScanForGames();
			G->ClearItems();
			for(auto&d:_CReg) G->AddItem(d.second.Title);
		}

		std::string CodeName(std::string inp) {
			// Alles in hoofdletters
			Trans2Upper(inp);
			// Verwijder lidwoordn
			if (Prefixed(inp,"THE ")) inp=inp.substr(4);
			else if (Prefixed(inp,"A ")) inp=inp.substr(2);
			// Verwijder spaties
			inp=StReplace(inp," ","");
			// Retourneer de codenaam
			return inp;
		}
	}
}

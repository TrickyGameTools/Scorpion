#include <string>
#include <vector>

#include <SlyvGINIE.hpp>

#include <June19.hpp>

namespace Slyvina {
	namespace Scorpion{

		struct TChosen {
			int
				ButR{255},ButG{255},ButB{255},
				HedR{255},HedG{180},HedB{0},
				TxtR{255},TxtG{255},TxtB{255};
			std::string
				Head{""},
				ScyndiVersion{""},
				BuildDate{""},
				FullFile{""},
				Title{""};
			std::vector<std::string> Description;
		};

		Units::GINIE CFG();

		void ScanForGames();
		void ScanForGames(June19::j19gadget* G);

		std::string CodeName(std::string inp);
		inline std::string CodeName(TChosen& R) { return CodeName(R.Title); }
	}
}

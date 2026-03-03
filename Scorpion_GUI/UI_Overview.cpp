#include <June19.hpp>

#include "Assets.hpp"
#include "UI_Main.hpp"

using namespace Slyvina::June19;


namespace Slyvina {
	namespace Scorpion {

		j19gadget
			* BgPic{nullptr};

		void Recolor(){}

		void InitOverview(){
			auto bg{CB::Get("OVERVIEW")};
			BgPic = CreatePicture(0,0,bg->W(),bg->H(),bg);
			BaseBackground(BgPic);
			auto __ico{CreatePicture(5,5,30,30,BgPic,Pic_FullStretch)};
			__ico->Image(Assets(),"GFX/Icon.png");
		}
	}
}


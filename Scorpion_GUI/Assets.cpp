#include <map>

#include <TQSG.hpp>

#include <SlyvQCol.hpp>
#include <SlyvString.hpp>

#include <JCR6_Core.hpp>
#include <JCR6_zlib.hpp>

#include "UI_Main.hpp"

#include "Assets.hpp"

#undef AssetFileDebug

using namespace Slyvina::TQSG;
using namespace Slyvina::JCR6;
using namespace Slyvina::Units;
using namespace Slyvina::June19;

namespace Slyvina {
	namespace Scorpion {

		std::string EXE;

		std::string AssetFile() {
			static std::string ret{""};
			if (ret=="") {
				std::vector<std::string> asf{ EXE,ExtractDir(EXE)+"/Scorpion.jcr",StripExt(EXE)+".jcr"};
				#ifdef SlyvLinux
				asf.push_back("/proc/self/exe");
				#endif // SlyvLinux
				for (auto&a:asf) {
					auto rec{_JT_Dir::Recognize(a)};
					#ifdef AssetFileDebug
					QCol->Yellow(a); QCol->Magenta(" -> "); (rec!="NONE"?QCol->Green(rec):QCol->Red(rec)); std::cout <<"\n";
					#endif // AssetFileDebug
					if (rec!="NONE") {ret=a; break; }
				}
			}
			if (ret=="") {QCol->Error("No assets!");}
			return ret;
		}

		JCR6::JT_Dir Assets() {
			static JT_Dir ret{ nullptr };
			if (!ret) {
				QCol->Doing("Fetching",AssetFile());
				init_zlib();
				ret=JCR6_Dir(AssetFile());
				if (!ret){
					FatalError("JCR6 file "+AssetFile()+" not properly loaded\n\n"+Last()->ErrorMessage+"\nE:"+Last()->Entry+"\nM:"+Last()->MainFile);
					return nullptr;
				}
			}
			return ret;
		}

		void BaseBackground(June19::j19gadget*G) {
			static TImage img {nullptr};
			if (!img) {
				QCol->Doing("Loading","Base Background");
				img = LoadImage(Assets(),"GFX/Background.bmp");
			}
			if (!img) {
				FatalError("Background image could not be properly loaded\n\n"+Last()->ErrorMessage+"\nE:"+Last()->Entry+"\nM:"+Last()->MainFile);
				return;
			}
			G->Image(img);
			G->IntFlag = Pic_Tiled;
			G->SetForeground(255,255,255);
			G->Visible=true;
		}
	}
}

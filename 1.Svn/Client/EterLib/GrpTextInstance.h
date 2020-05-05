///Add
#include "../UserInterface/Locale_inc.h"
#include <memory>

//Find
		void HideOutLine();
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
		void CheckMultiLine();
#endif

//Find
		std::vector<SHyperlink> m_hyperlinkVector;
		
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
		std::vector<std::shared_ptr<CGraphicTextInstance>> multi_text;
		bool IsBaseObject;
#endif
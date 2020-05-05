///Add
#if defined(__ENABLE_MULTITEXTLINE__)
#include <regex>
void CGraphicTextInstance::CheckMultiLine()
{
	const auto SplitMultiLine = [&]() -> std::vector<decltype(m_stText)>
	{
		static const std::regex re(R"(\\n|\n)");
		const std::sregex_token_iterator first{ m_stText.begin(), m_stText.end(), re, -1 }, last;
		return { first, last };
	};
	if (IsBaseObject) {
		auto MultiVec = SplitMultiLine();
		
		if (MultiVec.size() > 1) {
			if (!multi_text.empty())
				multi_text.clear();
			m_stText.assign(MultiVec.at(0));
			MultiVec.erase(MultiVec.begin());
			multi_text.reserve(MultiVec.size());
			
			for (const auto& v : MultiVec) {
				auto pTextInstance = std::make_shared<CGraphicTextInstance>(*this);
				pTextInstance->multi_text.clear();
				pTextInstance->IsBaseObject = false;
				pTextInstance->SetValueString(v);
				multi_text.emplace_back(pTextInstance);
			}

			SetPosition(m_v3Position.x, m_v3Position.y, m_v3Position.z);
		}
	}
}
#endif

//Find
	if (m_isUpdate)
		return;
	
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	for (const auto& v : multi_text)
		v->Update();
#endif

//Find
	if (!m_isUpdate)
		return;
	
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	for (const auto& v : multi_text)
		v->Render();
#endif

//Find
	m_stText = c_stValue;
	
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	CheckMultiLine();
#endif

//Find
	m_stText = c_szText;
	
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	CheckMultiLine();
#endif

//Find
	m_v3Position.z = fz;

///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	for (size_t i = 0; i < multi_text.size(); i++)
		multi_text.at(i)->SetPosition(fx, fy + (i+1) * 10.0f, fz);
#endif

//Find in void CGraphicTextInstance::__Initialize()
	m_isUpdate = false;
	
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	IsBaseObject = true;
#endif

//Find in void CGraphicTextInstance::Destroy()
	m_hyperlinkVector.clear();
	
///Add
#if defined(__ENABLE_MULTITEXTLINE__)
	multi_text.clear();
#endif
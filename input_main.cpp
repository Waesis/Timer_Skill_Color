Search : void CInputMain::SetSkillColor(LPCHARACTER ch, const char* pcData)
  
 Add :
#ifdef Timer_Skill_Color

	quest::CQuestManager& q = quest::CQuestManager::instance();
	quest::PC* pPC = q.GetPC(ch->GetPlayerID());

	int last_use_time = pPC->GetFlag("skill_color.skill_color_timer");

	if (get_global_time() - last_use_time < 60)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Poti schimba culoarea in %d secunde.", 60 - (get_global_time() - last_use_time));
		return;
	}

	pPC->SetFlag("skill_color.skill_color_timer", get_global_time());

#endif

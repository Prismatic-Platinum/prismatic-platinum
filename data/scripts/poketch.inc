Poketch_Startup_EventScript::
    lock
    playse SE_POKENAV_ON
    waitse
    message Poketch_Menu_Text
    waitmessage
    multichoice 17, 6, MULTI_POKETCH, FALSE
    switch VAR_RESULT
    case 0, Poketch_TimeChanger_EventScript
    case 1, Poketch_DayCare_EventScript
    case 2, Poketch_FriendshipChecker_EventScript

Poketch_Exit_EventScript::
    lock
    msgbox Poketch_Exit_Text, MSGBOX_DEFAULT
    playse SE_POKENAV_OFF
    release
    end

Poketch_TimeChanger_EventScript::
    lock
    special GetDayOrNight
    goto_if_eq VAR_RESULT, 1, TimeChanger_N_EventScript
    goto_if_eq VAR_RESULT, 0, TimeChanger_D_EventScript
    end

TimeChanger_D_EventScript::
    lock
    msgbox Poketch_TimeChanger_TxtStartup_Day, MSGBOX_YESNO
    switch VAR_RESULT
	case NO, Poketch_Exit_EventScript
	case YES, Time_Change_Night_EventScript
	case MULTI_B_PRESSED, Poketch_Exit_EventScript

TimeChanger_N_EventScript::
    lock
    msgbox Poketch_TimeChanger_TxtStartup_Night, MSGBOX_YESNO
    switch VAR_RESULT
	case NO, Poketch_Exit_EventScript
	case YES, Time_Change_Day_EventScript
	case MULTI_B_PRESSED, Poketch_Exit_EventScript

Time_Change_Day_EventScript::
    lock
    playse SE_M_GRASSWHISTLE
    waitse
    msgbox Poketch_Time_TxtDay, MSGBOX_DEFAULT
    special ToggleDayNight
    special RunOnResumeMapScript
    special DoCurrentWeather
    playse SE_POKENAV_OFF
    release
    closemessage
    end
    
Time_Change_Night_EventScript::
    lock
    playse SE_M_PERISH_SONG
    waitse
    msgbox Poketch_Time_TxtNight, MSGBOX_DEFAULT
    special ToggleDayNight
    special RunOnResumeMapScript
    special DoCurrentWeather
    playse SE_POKENAV_OFF
    release
    closemessage
    end

Poketch_DayCare_EventScript::
    lock
    msgbox Poketch_DCA_TxtStartup, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, DCA_Check_EventScript
    playse SE_POKENAV_OFF
	release
	end

DCA_Check_EventScript::
    special GetDaycareMonNicknames
    playse SE_POKENAV_CALL
    waitse
    specialvar VAR_RESULT, GetDaycareState
    goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, DCA_Waiting_EventScript
    msgbox Poketch_DCA_TxtEggNone, MSGBOX_DEFAULT
    playse SE_POKENAV_OFF
    releaseall
    end

DCA_Waiting_EventScript::
    msgbox Poketch_DCA_TxtEggWaiting, MSGBOX_DEFAULT
    playse SE_POKENAV_OFF
    releaseall
    end

Poketch_FriendshipChecker_EventScript::
	lock
	msgbox Poketch_FCA_Txt_Startup, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, FCA_NONE_EventScript
	case FRIENDSHIP_1_TO_49, FCA_1_TO_49_EventScript
	case FRIENDSHIP_50_TO_99, FCA_50_TO_99_EventScript
	case FRIENDSHIP_100_TO_149, FCA_100_TO_149_EventScript
	case FRIENDSHIP_150_TO_199, FCA_150_TO_199_EventScript
	case FRIENDSHIP_200_TO_254, FCA_200_TO_254_EventScript
	case FRIENDSHIP_MAX, FCA_MAX_EventScript
	release
	end

FCA_NONE_EventScript::
	msgbox FCA_Txt_NONE, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

FCA_1_TO_49_EventScript::
	msgbox FCA_Txt_1_TO_49, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

FCA_50_TO_99_EventScript::
	msgbox FCA_Txt_50_TO_99, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

FCA_100_TO_149_EventScript::
	msgbox FCA_Txt_100_TO_149, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

FCA_150_TO_199_EventScript::
	msgbox FCA_Txt_150_TO_199, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

FCA_200_TO_254_EventScript::
	msgbox FCA_Txt_200_TO_254, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

FCA_MAX_EventScript::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
    playmoncry SPECIES_ROTOM, CRY_MODE_NORMAL
    waitmoncry
	msgbox FCA_Txt_MAX, MSGBOX_DEFAULT
	closemessage
    playse SE_POKENAV_OFF
	end

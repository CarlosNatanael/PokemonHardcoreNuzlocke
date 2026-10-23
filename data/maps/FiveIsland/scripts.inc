FiveIsland_EventScript_IslandSign::
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end

FiveIsland_EventScript_BugCatcher::
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

FiveIsland_EventScript_Fisher::
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end

FiveIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
	.byte 0

FiveIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND
	call FiveIsland_EventScript_SetupOppositeGenderRival
	end

FiveIsland_EventScript_SetupOppositeGenderRival::
	// Se já foram derrotados, esconde ambos
	goto_if_set FLAG_DEFEATED_FIVE_ISLAND_RIVAL, FiveIsland_EventScript_HideBoth
	
	// Verifica o género do jogador (0 = MALE, 1 = FEMALE)
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, FiveIsland_EventScript_ShowLeaf
	
	// Se o jogador for FEMALE, mostra o Red e esconde a Leaf
	clearflag FLAG_HIDE_FIVE_ISLAND_RIVAL_RED
	setflag FLAG_HIDE_FIVE_ISLAND_RIVAL_LEAF
	return

FiveIsland_EventScript_ShowLeaf::
	// Se o jogador for MALE, mostra a Leaf e esconde o Red
	clearflag FLAG_HIDE_FIVE_ISLAND_RIVAL_LEAF
	setflag FLAG_HIDE_FIVE_ISLAND_RIVAL_RED
	return

FiveIsland_EventScript_HideBoth::
	setflag FLAG_HIDE_FIVE_ISLAND_RIVAL_RED
	setflag FLAG_HIDE_FIVE_ISLAND_RIVAL_LEAF
	return

// --- SCRIPT DO RED ---
FiveIsland_EventScript_RivalRed::
	lock
	faceplayer
	msgbox FiveIsland_Text_RedIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_RIVAL_RED_FIVE_ISLAND, FiveIsland_Text_RedDefeat
	goto FiveIsland_EventScript_RivalPostBattle

// --- SCRIPT DA LEAF (GREEN) ---
FiveIsland_EventScript_RivalLeaf::
	lock
	faceplayer
	msgbox FiveIsland_Text_LeafIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_RIVAL_LEAF_FIVE_ISLAND, FiveIsland_Text_LeafDefeat
	goto FiveIsland_EventScript_RivalPostBattle

// --- FINAL COMUM PARA AMBOS ---
FiveIsland_EventScript_RivalPostBattle::
	msgbox FiveIsland_Text_RivalPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_RED
	removeobject LOCALID_LEAF
	setflag FLAG_DEFEATED_FIVE_ISLAND_RIVAL
	fadescreen FADE_FROM_BLACK
	release
	end

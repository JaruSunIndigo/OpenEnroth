#pragma once
#include <array>

#include "Engine/Time.h"
#include "Engine/Strings.h"

constexpr unsigned int MAX_SAVE_SLOTS = 45;

struct SavegameList {
    static void Initialize();
    SavegameList();

    void Reset();

    std::array<String, MAX_SAVE_SLOTS> pFileList;
};

/*  244 */
#pragma pack(push, 1)
struct SavegameHeader {
    char pName[20]{};
    char pLocationName[20]{};
    GameTime playing_time{};  // unsigned __int64 uWordTime;
    char field_30[52]{};
};
#pragma pack(pop)

void SaveGame(bool NotSaveWorld);
void SaveGameToSlot(int slot);
void Autosave(bool NotSaveWorld);
void AutosaveOnNewGame();
void LoadGame(unsigned int uSlot);
bool Initialize_GamesLOD_NewLOD();

extern unsigned int uNumSavegameFiles;
extern std::array<unsigned int, MAX_SAVE_SLOTS> pSavegameUsedSlots;
extern struct SavegameList *pSavegameList;
extern std::array<SavegameHeader, MAX_SAVE_SLOTS> pSavegameHeader;

extern std::array<class Image *, MAX_SAVE_SLOTS> pSavegameThumbnails;

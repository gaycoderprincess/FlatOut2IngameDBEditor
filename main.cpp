#include <windows.h>
#include <d3d9.h>
#include <format>
#include "toml++/toml.hpp"

#include "nya_commonmath.h"
#include "nya_commonhooklib.h"

#include "fo2.h"
#include "../nya-common-fouc/fo2versioncheck.h"
#include "chloemenulib.h"

uint32_t nodeVtable = 0x67B1C0;
void DBEditor_PatchOnApply() {
	NyaHookLib::Patch(0x558695 + 1, "PropertyDb: Table '%s' not found!");
	NyaHookLib::Fill(0x675268, 0x90, 0x675294-0x675268);
}

#include "../FlatOutUCIngameDBEditor/dbeditor.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			DoFlatOutVersionCheck(FO2Version::FO2_1_2);
			ChloeMenuLib::RegisterMenu("In-Game DB Editor - gaycoderprincess", DBEditorLoop);
		} break;
		default:
			break;
	}
	return TRUE;
}
#include "tonccpy.h"
#include "bg.h"
#include <nds.h>
#include <fat.h>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int arrowKeysDownHandler(int keys, int cursorLocation);

int main() {
    touchPosition touchPosition;

    videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);
	vramSetPrimaryBanks(VRAM_A_MAIN_BG,
	                    VRAM_B_MAIN_SPRITE,
	                    VRAM_C_SUB_BG,
	                    VRAM_D_LCD);
	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 3, 0);
	bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 3, 0);
	decompress(bgBitmap, bgGetGfxPtr(bg3), LZ77Vram);
	tonccpy(BG_PALETTE, bgPal, bgPalLen);
	PrintConsole consoleSub;
	consoleInit(&consoleSub, 0, BgType_Bmp8, BgSize_T_256x256, 16, 6, false, true);
	consoleSetWindow(&consoleSub, 5, 5, 32, 32);
	fatInitDefault();

    return 0;
}

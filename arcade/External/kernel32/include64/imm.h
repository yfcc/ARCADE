#ifndef _IMM_
#define _IMM_
#ifndef _IMM_SDK_DEFINED_
#define _IMM_SDK_DEFINED_
#if (WINVER >=0x040A)
DECLARE_HANDLE(HIMC);
DECLARE_HANDLE(HIMCC);
#else
typedef DWORD HIMC;
typedef DWORD HIMCC;
#endif 
typedef HKL *LPHKL;
typedef UINT *LPUINT;
typedef struct tagCOMPOSITIONFORM {
	DWORD dwStyle;
	POINT ptCurrentPos;
	RECT rcArea;
} COMPOSITIONFORM,*PCOMPOSITIONFORM,*NPCOMPOSITIONFORM,*LPCOMPOSITIONFORM;
typedef struct tagCANDIDATEFORM {
	DWORD dwIndex;
	DWORD dwStyle;
	POINT ptCurrentPos;
	RECT rcArea;
} CANDIDATEFORM,*PCANDIDATEFORM,*NPCANDIDATEFORM,*LPCANDIDATEFORM;
typedef struct tagCANDIDATELIST {
	DWORD dwSize;
	DWORD dwStyle;
	DWORD dwCount;
	DWORD dwSelection;
	DWORD dwPageStart;
	DWORD dwPageSize;
	DWORD dwOffset[1];
} CANDIDATELIST,*PCANDIDATELIST,*NPCANDIDATELIST,*LPCANDIDATELIST;
typedef struct tagREGISTERWORDA {
	LPSTR lpReading;
	LPSTR lpWord;
} REGISTERWORDA,*PREGISTERWORDA,*NPREGISTERWORDA,*LPREGISTERWORDA;
typedef struct tagREGISTERWORDW {
	LPWSTR lpReading;
	LPWSTR lpWord;
} REGISTERWORDW,*PREGISTERWORDW,*NPREGISTERWORDW,*LPREGISTERWORDW;
#ifdef UNICODE
typedef REGISTERWORDW REGISTERWORD;
typedef PREGISTERWORDW PREGISTERWORD;
typedef NPREGISTERWORDW NPREGISTERWORD;
typedef LPREGISTERWORDW LPREGISTERWORD;
#else
typedef REGISTERWORDA REGISTERWORD;
typedef PREGISTERWORDA PREGISTERWORD;
typedef NPREGISTERWORDA NPREGISTERWORD;
typedef LPREGISTERWORDA LPREGISTERWORD;
#endif 
#if (WINVER >=0x040A)
typedef struct tagRECONVERTSTRING {
	DWORD dwSize;
	DWORD dwVersion;
	DWORD dwStrLen;
	DWORD dwStrOffset;
	DWORD dwCompStrLen;
	DWORD dwCompStrOffset;
	DWORD dwTargetStrLen;
	DWORD dwTargetStrOffset;
} RECONVERTSTRING,*PRECONVERTSTRING,*NPRECONVERTSTRING,*LPRECONVERTSTRING;
#endif 
#define STYLE_DESCRIPTION_SIZE 32
typedef struct tagSTYLEBUFA {
	DWORD dwStyle;
	CHAR szDescription[STYLE_DESCRIPTION_SIZE];
} STYLEBUFA,*PSTYLEBUFA,*NPSTYLEBUFA,*LPSTYLEBUFA;
typedef struct tagSTYLEBUFW {
	DWORD dwStyle;
	WCHAR szDescription[STYLE_DESCRIPTION_SIZE];
} STYLEBUFW,*PSTYLEBUFW,*NPSTYLEBUFW,*LPSTYLEBUFW;
#ifdef UNICODE
typedef STYLEBUFW STYLEBUF;
typedef PSTYLEBUFW PSTYLEBUF;
typedef NPSTYLEBUFW NPSTYLEBUF;
typedef LPSTYLEBUFW LPSTYLEBUF;
#else
typedef STYLEBUFA STYLEBUF;
typedef PSTYLEBUFA PSTYLEBUF;
typedef NPSTYLEBUFA NPSTYLEBUF;
typedef LPSTYLEBUFA LPSTYLEBUF;
#endif 
#if (WINVER >=0x040A)
#define IMEMENUITEM_STRING_SIZE 80
typedef struct tagIMEMENUITEMINFOA {
	UINT cbSize;
	UINT fType;
	UINT fState;
	UINT wID;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	DWORD dwItemData;
	CHAR szString[IMEMENUITEM_STRING_SIZE];
	HBITMAP hbmpItem;
} IMEMENUITEMINFOA,*PIMEMENUITEMINFOA,*NPIMEMENUITEMINFOA,*LPIMEMENUITEMINFOA;
typedef struct tagIMEMENUITEMINFOW {
	UINT cbSize;
	UINT fType;
	UINT fState;
	UINT wID;
	HBITMAP hbmpChecked;
	HBITMAP hbmpUnchecked;
	DWORD dwItemData;
	WCHAR szString[IMEMENUITEM_STRING_SIZE];
	HBITMAP hbmpItem;
} IMEMENUITEMINFOW,*PIMEMENUITEMINFOW,*NPIMEMENUITEMINFOW,*LPIMEMENUITEMINFOW;
#ifdef UNICODE
typedef IMEMENUITEMINFOW IMEMENUITEMINFO;
typedef PIMEMENUITEMINFOW PIMEMENUITEMINFO;
typedef NPIMEMENUITEMINFOW NPIMEMENUITEMINFO;
typedef LPIMEMENUITEMINFOW LPIMEMENUITEMINFO;
#else
typedef IMEMENUITEMINFOA IMEMENUITEMINFO;
typedef PIMEMENUITEMINFOA PIMEMENUITEMINFO;
typedef NPIMEMENUITEMINFOA NPIMEMENUITEMINFO;
typedef LPIMEMENUITEMINFOA LPIMEMENUITEMINFO;
#endif 
typedef struct tagIMECHARPOSITION {
	DWORD dwSize;
	DWORD dwCharPos;
	POINT pt;
	UINT cLineHeight;
	RECT rcDocument;
} IMECHARPOSITION,*PIMECHARPOSITION,*NPIMECHARPOSITION,*LPIMECHARPOSITION;
typedef BOOL(CALLBACK* IMCENUMPROC)(HIMC,LPARAM);
#endif 
HKL WINAPI ImmInstallIMEA(LPCSTR lpszIMEFileName,LPCSTR lpszLayoutText);
HKL WINAPI ImmInstallIMEW(LPCWSTR lpszIMEFileName,LPCWSTR lpszLayoutText);
#ifdef UNICODE
#define ImmInstallIME ImmInstallIMEW
#else
#define ImmInstallIME ImmInstallIMEA
#endif 
HWND WINAPI ImmGetDefaultIMEWnd(HWND);
UINT WINAPI ImmGetDescriptionA(HKL,LPSTR,UINT uBufLen);
UINT WINAPI ImmGetDescriptionW(HKL,LPWSTR,UINT uBufLen);
#ifdef UNICODE
#define ImmGetDescription ImmGetDescriptionW
#else
#define ImmGetDescription ImmGetDescriptionA
#endif 
UINT WINAPI ImmGetIMEFileNameA(HKL,LPSTR,UINT uBufLen);
UINT WINAPI ImmGetIMEFileNameW(HKL,LPWSTR,UINT uBufLen);
#ifdef UNICODE
#define ImmGetIMEFileName ImmGetIMEFileNameW
#else
#define ImmGetIMEFileName ImmGetIMEFileNameA
#endif 
DWORD WINAPI ImmGetProperty(HKL,DWORD);
BOOL WINAPI ImmIsIME(HKL);
BOOL WINAPI ImmSimulateHotKey(HWND,DWORD);
HIMC WINAPI ImmCreateContext(void);
BOOL WINAPI ImmDestroyContext(HIMC);
HIMC WINAPI ImmGetContext(HWND);
BOOL WINAPI ImmReleaseContext(HWND,HIMC);
HIMC WINAPI ImmAssociateContext(HWND,HIMC);
#if (WINVER >=0x040A)
BOOL WINAPI ImmAssociateContextEx(HWND,HIMC,DWORD);
#endif 
LONG WINAPI ImmGetCompositionStringA(HIMC,DWORD,LPVOID,DWORD);
LONG WINAPI ImmGetCompositionStringW(HIMC,DWORD,LPVOID,DWORD);
#ifdef UNICODE
#define ImmGetCompositionString ImmGetCompositionStringW
#else
#define ImmGetCompositionString ImmGetCompositionStringA
#endif 
BOOL WINAPI ImmSetCompositionStringA(HIMC,DWORD dwIndex,LPVOID lpComp,DWORD,LPVOID lpRead,DWORD);
BOOL WINAPI ImmSetCompositionStringW(HIMC,DWORD dwIndex,LPVOID lpComp,DWORD,LPVOID lpRead,DWORD);
#ifdef UNICODE
#define ImmSetCompositionString ImmSetCompositionStringW
#else
#define ImmSetCompositionString ImmSetCompositionStringA
#endif 
DWORD WINAPI ImmGetCandidateListCountA(HIMC,LPDWORD lpdwListCount);
DWORD WINAPI ImmGetCandidateListCountW(HIMC,LPDWORD lpdwListCount);
#ifdef UNICODE
#define ImmGetCandidateListCount ImmGetCandidateListCountW
#else
#define ImmGetCandidateListCount ImmGetCandidateListCountA
#endif 
DWORD WINAPI ImmGetCandidateListA(HIMC,DWORD deIndex,LPCANDIDATELIST,DWORD dwBufLen);
DWORD WINAPI ImmGetCandidateListW(HIMC,DWORD deIndex,LPCANDIDATELIST,DWORD dwBufLen);
#ifdef UNICODE
#define ImmGetCandidateList ImmGetCandidateListW
#else
#define ImmGetCandidateList ImmGetCandidateListA
#endif 
DWORD WINAPI ImmGetGuideLineA(HIMC,DWORD dwIndex,LPSTR,DWORD dwBufLen);
DWORD WINAPI ImmGetGuideLineW(HIMC,DWORD dwIndex,LPWSTR,DWORD dwBufLen);
#ifdef UNICODE
#define ImmGetGuideLine ImmGetGuideLineW
#else
#define ImmGetGuideLine ImmGetGuideLineA
#endif 
BOOL WINAPI ImmGetConversionStatus(HIMC,LPDWORD,LPDWORD);
BOOL WINAPI ImmSetConversionStatus(HIMC,DWORD,DWORD);
BOOL WINAPI ImmGetOpenStatus(HIMC);
BOOL WINAPI ImmSetOpenStatus(HIMC,BOOL);
#if defined(_WINGDI_) && !defined(NOGDI)
BOOL WINAPI ImmGetCompositionFontA(HIMC,LPLOGFONTA);
BOOL WINAPI ImmGetCompositionFontW(HIMC,LPLOGFONTW);
#ifdef UNICODE
#define ImmGetCompositionFont ImmGetCompositionFontW
#else
#define ImmGetCompositionFont ImmGetCompositionFontA
#endif 
BOOL WINAPI ImmSetCompositionFontA(HIMC,LPLOGFONTA);
BOOL WINAPI ImmSetCompositionFontW(HIMC,LPLOGFONTW);
#ifdef UNICODE
#define ImmSetCompositionFont ImmSetCompositionFontW
#else
#define ImmSetCompositionFont ImmSetCompositionFontA
#endif 
#endif 
BOOL WINAPI ImmConfigureIMEA(HKL,HWND,DWORD,LPVOID);
BOOL WINAPI ImmConfigureIMEW(HKL,HWND,DWORD,LPVOID);
#ifdef UNICODE
#define ImmConfigureIME ImmConfigureIMEW
#else
#define ImmConfigureIME ImmConfigureIMEA
#endif 
LRESULT WINAPI ImmEscapeA(HKL,HIMC,UINT,LPVOID);
LRESULT WINAPI ImmEscapeW(HKL,HIMC,UINT,LPVOID);
#ifdef UNICODE
#define ImmEscape ImmEscapeW
#else
#define ImmEscape ImmEscapeA
#endif 
DWORD WINAPI ImmGetConversionListA(HKL,HIMC,LPCSTR,LPCANDIDATELIST,DWORD dwBufLen,UINT uFlag);
DWORD WINAPI ImmGetConversionListW(HKL,HIMC,LPCWSTR,LPCANDIDATELIST,DWORD dwBufLen,UINT uFlag);
#ifdef UNICODE
#define ImmGetConversionList ImmGetConversionListW
#else
#define ImmGetConversionList ImmGetConversionListA
#endif 
BOOL WINAPI ImmNotifyIME(HIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
BOOL WINAPI ImmGetStatusWindowPos(HIMC,LPPOINT);
BOOL WINAPI ImmSetStatusWindowPos(HIMC,LPPOINT);
BOOL WINAPI ImmGetCompositionWindow(HIMC,LPCOMPOSITIONFORM);
BOOL WINAPI ImmSetCompositionWindow(HIMC,LPCOMPOSITIONFORM);
BOOL WINAPI ImmGetCandidateWindow(HIMC,DWORD,LPCANDIDATEFORM);
BOOL WINAPI ImmSetCandidateWindow(HIMC,LPCANDIDATEFORM);
BOOL WINAPI ImmIsUIMessageA(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI ImmIsUIMessageW(HWND,UINT,WPARAM,LPARAM);
#ifdef UNICODE
#define ImmIsUIMessage ImmIsUIMessageW
#else
#define ImmIsUIMessage ImmIsUIMessageA
#endif 
UINT WINAPI ImmGetVirtualKey(HWND);
typedef int (CALLBACK *REGISTERWORDENUMPROCA)(LPCSTR,DWORD,LPCSTR,LPVOID);
typedef int (CALLBACK *REGISTERWORDENUMPROCW)(LPCWSTR,DWORD,LPCWSTR,LPVOID);
#ifdef UNICODE
#define REGISTERWORDENUMPROC REGISTERWORDENUMPROCW
#else
#define REGISTERWORDENUMPROC REGISTERWORDENUMPROCA
#endif 
BOOL WINAPI ImmRegisterWordA(HKL,LPCSTR lpszReading,DWORD,LPCSTR lpszRegister);
BOOL WINAPI ImmRegisterWordW(HKL,LPCWSTR lpszReading,DWORD,LPCWSTR lpszRegister);
#ifdef UNICODE
#define ImmRegisterWord ImmRegisterWordW
#else
#define ImmRegisterWord ImmRegisterWordA
#endif 
BOOL WINAPI ImmUnregisterWordA(HKL,LPCSTR lpszReading,DWORD,LPCSTR lpszUnregister);
BOOL WINAPI ImmUnregisterWordW(HKL,LPCWSTR lpszReading,DWORD,LPCWSTR lpszUnregister);
#ifdef UNICODE
#define ImmUnregisterWord ImmUnregisterWordW
#else
#define ImmUnregisterWord ImmUnregisterWordA
#endif 
UINT WINAPI ImmGetRegisterWordStyleA(HKL,UINT nItem,LPSTYLEBUFA);
UINT WINAPI ImmGetRegisterWordStyleW(HKL,UINT nItem,LPSTYLEBUFW);
#ifdef UNICODE
#define ImmGetRegisterWordStyle ImmGetRegisterWordStyleW
#else
#define ImmGetRegisterWordStyle ImmGetRegisterWordStyleA
#endif 
UINT WINAPI ImmEnumRegisterWordA(HKL,REGISTERWORDENUMPROCA,LPCSTR lpszReading,DWORD,LPCSTR lpszRegister,LPVOID);
UINT WINAPI ImmEnumRegisterWordW(HKL,REGISTERWORDENUMPROCW,LPCWSTR lpszReading,DWORD,LPCWSTR lpszRegister,LPVOID);
#ifdef UNICODE
#define ImmEnumRegisterWord ImmEnumRegisterWordW
#else
#define ImmEnumRegisterWord ImmEnumRegisterWordA
#endif 
#if (WINVER >=0x040A)
BOOL WINAPI ImmDisableIME(DWORD);
BOOL WINAPI ImmEnumInputContext(DWORD idThread,IMCENUMPROC lpfn,LPARAM lParam);
DWORD WINAPI ImmGetImeMenuItemsA(HIMC,DWORD,DWORD,LPIMEMENUITEMINFOA,LPIMEMENUITEMINFOA,DWORD);
DWORD WINAPI ImmGetImeMenuItemsW(HIMC,DWORD,DWORD,LPIMEMENUITEMINFOW,LPIMEMENUITEMINFOW,DWORD);
#ifdef UNICODE
#define ImmGetImeMenuItems ImmGetImeMenuItemsW
#else
#define ImmGetImeMenuItems ImmGetImeMenuItemsA
#endif 
BOOL WINAPI ImmDisableTextFrameService(DWORD idThread);
#endif 
#define IMC_GETCANDIDATEPOS 7
#define IMC_SETCANDIDATEPOS 8
#define IMC_GETCOMPOSITIONFONT 9
#define IMC_SETCOMPOSITIONFONT 10
#define IMC_GETCOMPOSITIONWINDOW 11
#define IMC_SETCOMPOSITIONWINDOW 12
#define IMC_GETSTATUSWINDOWPOS 15
#define IMC_SETSTATUSWINDOWPOS 16
#define IMC_CLOSESTATUSWINDOW 33
#define IMC_OPENSTATUSWINDOW 34
#define NI_OPENCANDIDATE 16
#define NI_CLOSECANDIDATE 17
#define NI_SELECTCANDIDATESTR 18
#define NI_CHANGECANDIDATELIST 19
#define NI_FINALIZECONVERSIONRESULT 20
#define NI_COMPOSITIONSTR 21
#define NI_SETCANDIDATE_PAGESTART 22
#define NI_SETCANDIDATE_PAGESIZE 23
#define NI_IMEMENUSELECTED 24
#define ISC_SHOWUICANDIDATEWINDOW 1
#define ISC_SHOWUICOMPOSITIONWINDOW 0x80000000
#define ISC_SHOWUIGUIDELINE 0x40000000
#define ISC_SHOWUIALLCANDIDATEWINDOW 15
#define ISC_SHOWUIALL 0xc000000f
#define CPS_COMPLETE 1
#define CPS_CONVERT 2
#define CPS_REVERT 3
#define CPS_CANCEL 4
#define MOD_ALT 1
#define MOD_CONTROL 2
#define MOD_SHIFT 4
#define MOD_LEFT 0x8000
#define MOD_RIGHT 0x4000
#define MOD_ON_KEYUP 2048
#define MOD_IGNORE_ALL_MODIFIER 1024
#define IME_CHOTKEY_IME_NONIME_TOGGLE 16
#define IME_CHOTKEY_SHAPE_TOGGLE 17
#define IME_CHOTKEY_SYMBOL_TOGGLE 18
#define IME_JHOTKEY_CLOSE_OPEN 48
#define IME_KHOTKEY_SHAPE_TOGGLE 80
#define IME_KHOTKEY_HANJACONVERT 81
#define IME_KHOTKEY_ENGLISH 82
#define IME_THOTKEY_IME_NONIME_TOGGLE 112
#define IME_THOTKEY_SHAPE_TOGGLE 113
#define IME_THOTKEY_SYMBOL_TOGGLE 114
#define IME_HOTKEY_DSWITCH_FIRST 256
#define IME_HOTKEY_DSWITCH_LAST 287
#define IME_HOTKEY_PRIVATE_FIRST 512
#define IME_ITHOTKEY_RESEND_RESULTSTR 512
#define IME_ITHOTKEY_PREVIOUS_COMPOSITION 513
#define IME_ITHOTKEY_UISTYLE_TOGGLE 514
#define IME_ITHOTKEY_RECONVERTSTRING 515
#define IME_HOTKEY_PRIVATE_LAST 543
#define GCS_COMPREADSTR 1
#define GCS_COMPREADATTR 2
#define GCS_COMPREADCLAUSE 4
#define GCS_COMPSTR 8
#define GCS_COMPATTR 16
#define GCS_COMPCLAUSE 32
#define GCS_CURSORPOS 128
#define GCS_DELTASTART 256
#define GCS_RESULTREADSTR 512
#define GCS_RESULTREADCLAUSE 1024
#define GCS_RESULTSTR 2048
#define GCS_RESULTCLAUSE 0x1000
#define CS_INSERTCHAR 0x2000
#define CS_NOMOVECARET 0x4000
#define IMEVER_0310 0x3000a
#define IMEVER_0400 0x40000
#define IME_PROP_AT_CARET 0x10000
#define IME_PROP_SPECIAL_UI 0x20000
#define IME_PROP_CANDLIST_START_FROM_1 0x40000
#define IME_PROP_UNICODE 0x80000
#define IME_PROP_COMPLETE_ON_UNSELECT 0x100000
#define UI_CAP_2700 1
#define UI_CAP_ROT90 2
#define UI_CAP_ROTANY 4
#define SCS_CAP_COMPSTR 1
#define SCS_CAP_MAKEREAD 2
#define SCS_CAP_SETRECONVERTSTRING 4
#define SELECT_CAP_CONVERSION 1
#define SELECT_CAP_SENTENCE 2
#define GGL_LEVEL 1
#define GGL_INDEX 2
#define GGL_STRING 3
#define GGL_PRIVATE 4
#define GL_LEVEL_NOGUIDELINE 0
#define GL_LEVEL_FATAL 1
#define GL_LEVEL_ERROR 2
#define GL_LEVEL_WARNING 3
#define GL_LEVEL_INFORMATION 4
#define GL_ID_UNKNOWN 0
#define GL_ID_NOMODULE 1
#define GL_ID_NODICTIONARY 16
#define GL_ID_CANNOTSAVE 17
#define GL_ID_NOCONVERT 32
#define GL_ID_TYPINGERROR 33
#define GL_ID_TOOMANYSTROKE 34
#define GL_ID_READINGCONFLICT 35
#define GL_ID_INPUTREADING 36
#define GL_ID_INPUTRADICAL 37
#define GL_ID_INPUTCODE 38
#define GL_ID_INPUTSYMBOL 39
#define GL_ID_CHOOSECANDIDATE 40
#define GL_ID_REVERSECONVERSION 41
#define GL_ID_PRIVATE_FIRST 0x8000
#define GL_ID_PRIVATE_LAST 0xffff
#define IGP_GETIMEVERSION (DWORD)(-4)
#define IGP_PROPERTY 4
#define IGP_CONVERSION 8
#define IGP_SENTENCE 12
#define IGP_UI 16
#define IGP_SETCOMPSTR 20
#define IGP_SELECT 24
#define SCS_SETSTR (GCS_COMPREADSTR|GCS_COMPSTR)
#define SCS_CHANGEATTR (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)
#define SCS_SETRECONVERTSTRING 0x10000
#define SCS_QUERYRECONVERTSTRING 0x20000
#define ATTR_INPUT 0
#define ATTR_TARGET_CONVERTED 1
#define ATTR_CONVERTED 2
#define ATTR_TARGET_NOTCONVERTED 3
#define ATTR_INPUT_ERROR 4
#define ATTR_FIXEDCONVERTED 5
#define CFS_DEFAULT 0
#define CFS_RECT 1
#define CFS_POINT 2
#define CFS_FORCE_POSITION 32
#define CFS_CANDIDATEPOS 64
#define CFS_EXCLUDE 128
#define GCL_CONVERSION 1
#define GCL_REVERSECONVERSION 2
#define GCL_REVERSE_LENGTH 3
#define IME_CMODE_ALPHANUMERIC 0
#define IME_CMODE_NATIVE 1
#define IME_CMODE_CHINESE IME_CMODE_NATIVE
#define IME_CMODE_HANGEUL IME_CMODE_NATIVE
#define IME_CMODE_HANGUL IME_CMODE_NATIVE
#define IME_CMODE_JAPANESE IME_CMODE_NATIVE
#define IME_CMODE_KATAKANA 2 
#define IME_CMODE_LANGUAGE 3
#define IME_CMODE_FULLSHAPE 8
#define IME_CMODE_ROMAN 16
#define IME_CMODE_CHARCODE 32
#define IME_CMODE_HANJACONVERT 64
#define IME_CMODE_SOFTKBD 128
#define IME_CMODE_NOCONVERSION 256
#define IME_CMODE_EUDC 512
#define IME_CMODE_SYMBOL 1024
#define IME_CMODE_FIXED 2048
#define IME_CMODE_RESERVED 0xf0000000
#define IME_SMODE_NONE 0
#define IME_SMODE_PLAURALCLAUSE 1
#define IME_SMODE_SINGLECONVERT 2
#define IME_SMODE_AUTOMATIC 4
#define IME_SMODE_PHRASEPREDICT 8
#define IME_SMODE_CONVERSATION 16
#define IME_SMODE_RESERVED 0xf000
#define IME_CAND_UNKNOWN 0
#define IME_CAND_READ 1
#define IME_CAND_CODE 2
#define IME_CAND_MEANING 3
#define IME_CAND_RADICAL 4
#define IME_CAND_STROKE 5
#define IMN_CLOSESTATUSWINDOW 1
#define IMN_OPENSTATUSWINDOW 2
#define IMN_CHANGECANDIDATE 3
#define IMN_CLOSECANDIDATE 4
#define IMN_OPENCANDIDATE 5
#define IMN_SETCONVERSIONMODE 6
#define IMN_SETSENTENCEMODE 7
#define IMN_SETOPENSTATUS 8
#define IMN_SETCANDIDATEPOS 9
#define IMN_SETCOMPOSITIONFONT 10
#define IMN_SETCOMPOSITIONWINDOW 11
#define IMN_SETSTATUSWINDOWPOS 12
#define IMN_GUIDELINE 13
#define IMN_PRIVATE 14
#if (WINVER >=0x040A)
#define IMR_COMPOSITIONWINDOW 1
#define IMR_CANDIDATEWINDOW 2
#define IMR_COMPOSITIONFONT 3
#define IMR_RECONVERTSTRING 4
#define IMR_CONFIRMRECONVERTSTRING 5
#define IMR_QUERYCHARPOSITION 6
#define IMR_DOCUMENTFEED 7
#endif 
#define IMM_ERROR_NODATA (-1)
#define IMM_ERROR_GENERAL (-2)
#define IME_CONFIG_GENERAL 1
#define IME_CONFIG_REGISTERWORD 2
#define IME_CONFIG_SELECTDICTIONARY 3
#define IME_ESC_QUERY_SUPPORT 3
#define IME_ESC_RESERVED_FIRST 4
#define IME_ESC_RESERVED_LAST 2047
#define IME_ESC_PRIVATE_FIRST 2048
#define IME_ESC_PRIVATE_LAST 4095
#define IME_ESC_SEQUENCE_TO_INTERNAL 0x1001
#define IME_ESC_GET_EUDC_DICTIONARY 0x1003
#define IME_ESC_SET_EUDC_DICTIONARY 0x1004
#define IME_ESC_MAX_KEY 0x1005
#define IME_ESC_IME_NAME 0x1006
#define IME_ESC_SYNC_HOTKEY 0x1007
#define IME_ESC_HANJA_MODE 0x1008
#define IME_ESC_AUTOMATA 0x1009
#define IME_ESC_PRIVATE_HOTKEY 0x100a
#define IME_ESC_GETHELPFILENAME 0x100b
#define IME_REGWORD_STYLE_EUDC 1
#define IME_REGWORD_STYLE_USER_FIRST 0x80000000
#define IME_REGWORD_STYLE_USER_LAST 0xffffffff
#if (WINVER >=0x040A)
#define IACE_CHILDREN 1
#define IACE_DEFAULT 16
#define IACE_IGNORENOCONTEXT 32
#define IGIMIF_RIGHTMENU 1
#define IGIMII_CMODE 1
#define IGIMII_SMODE 2
#define IGIMII_CONFIGURE 4
#define IGIMII_TOOLS 8
#define IGIMII_HELP 16
#define IGIMII_OTHER 32
#define IGIMII_INPUTTOOLS 64
#define IMFT_RADIOCHECK 1
#define IMFT_SEPARATOR 2
#define IMFT_SUBMENU 4
#define IMFS_GRAYED MFS_GRAYED
#define IMFS_DISABLED MFS_DISABLED
#define IMFS_CHECKED MFS_CHECKED
#define IMFS_HILITE MFS_HILITE
#define IMFS_ENABLED MFS_ENABLED
#define IMFS_UNCHECKED MFS_UNCHECKED
#define IMFS_UNHILITE MFS_UNHILITE
#define IMFS_DEFAULT MFS_DEFAULT
#endif 
#define SOFTKEYBOARD_TYPE_T1 1
#define SOFTKEYBOARD_TYPE_C1 2
#endif 
#endif 
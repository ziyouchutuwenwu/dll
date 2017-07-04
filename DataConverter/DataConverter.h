//---------------------------------------------------------------------------

#ifndef DataConverterH
#define DataConverterH
//---------------------------------------------------------------------------
#include <vcl.h>

class DataConverter
{
public:
    static AnsiString hexToString(int hex);
    static int stringToHex(AnsiString hex);

    static AnsiString bytesToString(byte* data, int length);
};
#endif

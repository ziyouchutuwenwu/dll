//---------------------------------------------------------------------------


#pragma hdrstop

#include "DataConverter.h"

AnsiString DataConverter::hexToString(int hex)
{
    AnsiString result = "0x" + IntToHex(hex,8);
    return result;
}

int DataConverter::stringToHex(AnsiString hex)
{
    AnsiString lowHex = hex.LowerCase();
    
    AnsiString hexString;

    int prefixIndx = lowHex.Pos("0x");

    if ( 0 == prefixIndx ) return 0;

    hexString = lowHex.Delete(prefixIndx, 2);

    return StrToInt("$" + hexString);
}

AnsiString DataConverter::bytesToString(byte* data, int length)
{
    AnsiString hexString = "";
    for(int i=0; i < length; i++)
    {
        AnsiString hex = IntToHex(data[i], 2);
        hexString += hex;

        if ( i != length - 1)
        {
            hexString += " ";
        }
    }

    return hexString;
}

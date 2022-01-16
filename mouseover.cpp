/*
MIT License

Copyright (c) 2022 Algebra970

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */
#include <iostream>
//#include <vector>
#include <string>

#include <windows.h>

using namespace std;

int main()
{
    BOOL current_awt = FALSE;
    SystemParametersInfo(SPI_GETACTIVEWINDOWTRACKING, 0, &current_awt, 0);
    // cout << "active window tracking enabled: " << current_awt << endl;
    // DWORD current_awt_to = -1;
    // SystemParametersInfo(SPI_GETACTIVEWNDTRKTIMEOUT, 0, &current_awt_to, 0);
    // cout << "active window tracking timeout: " << current_awt_to << endl;

    if (current_awt == FALSE)
    {
        PVOID *new_awt = (PVOID*)TRUE;
        SystemParametersInfo(SPI_SETACTIVEWINDOWTRACKING, 0, new_awt, 0);
        PVOID *new_awt_to = (PVOID*)0;
        SystemParametersInfo(SPI_SETACTIVEWNDTRKTIMEOUT, 0, new_awt_to, 0);
        cout << "Enabled active window tracking, tranking timeout is 0ms" << endl;
    }
    else
    {
        PVOID *new_awt = (PVOID*)FALSE;
        SystemParametersInfo(SPI_SETACTIVEWINDOWTRACKING, 0, new_awt, 0);
        PVOID *new_awt_to = (PVOID*)500;
        SystemParametersInfo(SPI_SETACTIVEWNDTRKTIMEOUT, 0, new_awt_to, 0);
        cout << "Disabled active window tracking" << endl;
    }
}

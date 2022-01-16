#!python3
# MIT License
# 
# Copyright (c) 2022 Algebra970
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import argparse

import win32gui
import win32con

arg_parser = argparse.ArgumentParser("Focus follows mouse tool")
arg_parser.add_argument("--timeout_ms", "-t", type=int)
args = arg_parser.parse_args()

timeout_ms_specified = args.timeout_ms is not None
if not timeout_ms_specified:
    args.timeout_ms =  0

active_window_tracking_enabled = win32gui.SystemParametersInfo(win32con.SPI_GETACTIVEWINDOWTRACKING)
active_window_tracking_timeout_ms = win32gui.SystemParametersInfo(win32con.SPI_GETACTIVEWNDTRKTIMEOUT)

if not active_window_tracking_enabled or timeout_ms_specified:
    win32gui.SystemParametersInfo(win32con.SPI_SETACTIVEWINDOWTRACKING, True, 0)
    win32gui.SystemParametersInfo(win32con.SPI_SETACTIVEWNDTRKTIMEOUT, args.timeout_ms, 0)
    print(f"Enabled active window tracking, tranking timeout is {args.timeout_ms}ms")
else:
    win32gui.SystemParametersInfo(win32con.SPI_SETACTIVEWINDOWTRACKING, False, 0)
    win32gui.SystemParametersInfo(win32con.SPI_SETACTIVEWNDTRKTIMEOUT, 500, 0)
    print("Disabled active window tracking")


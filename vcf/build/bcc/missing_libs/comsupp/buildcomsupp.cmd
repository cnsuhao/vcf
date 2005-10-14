@echo off
@SET BCC=bcc32
@%BCC% -v- -6 -O2 -a8 -A- -RT -w-inl -DWIN32;_MBCS -c comsupp.cpp comutil.cpp
@tlib comsupp.lib /a comsupp.obj comutil.obj
@del *.obj
@%BCC% -v -6 -Od -RT -a8  -A- -w-inl -D_DEBUG;WIN32;_MBCS -c comsupp.cpp comutil.cpp
@tlib comsuppd.lib /a comsupp.obj comutil.obj
@del *.obj
@%BCC% -v- -6 -O2 -RT -a8 -A- -w-inl -WU -DWIN32;UNICODE;_UNICODE -c comsupp.cpp comutil.cpp
@tlib comsuppw.lib /a comsupp.obj comutil.obj
@del *.obj
@%BCC% -v -6 -Od -RT -a8 -A- -w-inl -WU -D_DEBUG;WIN32;UNICODE;_UNICODE -c comsupp.cpp comutil.cpp
@tlib comsuppwd.lib /a comsupp.obj comutil.obj
@del *.obj

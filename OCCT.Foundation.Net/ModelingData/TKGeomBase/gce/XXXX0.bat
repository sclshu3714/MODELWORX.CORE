@echo off
ren *.hxx *.h
ren *.cxx *.cpp
del *.gxx
del *.lxx
del FILES
for %%i in (*.*)  do ren "%%i" x"%%i"



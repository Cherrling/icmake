//#define XERR
#include "compilefork.ih"

mutex CompileFork::s_staticData;
mutex CompileFork::s_echo;
size_t CompileFork::s_dataIdx = 0;
bool CompileFork::s_ok = true;



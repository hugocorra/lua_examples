extern "C"
{
    #include <lualib.h>
    #include <lauxlib.h>
    #include <lua.h>
}

#include <iostream>
#include <LuaBridge/LuaBridge.h>

using namespace luabridge;

static int greet(lua_State *L)
{
    std::cout << "hello world!" << std::endl;
    return 0;
}


extern "C" int luaopen_libgetme(lua_State* L) 
{
    getGlobalNamespace(L)
        .beginNamespace("hello_module")
            .addFunction("greet", greet)
        .endNamespace();

    return 0;
}



LuaCEmbedTypeModule newLuaCEmbedTypeModule(){
    LuaCEmbedTypeModule  self = {0};
    self.NOT_FOUND = LUA_CEMBED_NOT_FOUND;
    self.STRING = LUA_CEMBED_STRING;
    self.NUMBER = LUA_CEMBED_NUMBER;
    self.BOOL = LUA_CEMBED_BOOL;
    self.NILL = LUA_CEMBED_NIL;
    self.TABLE = LUA_CEMBED_TABLE;
    self.FUNCTION = LUA_CEMBED_FUNCTION;
    return self;
}
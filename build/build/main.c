

#include "definition.c"

int main(){
    dtw = newDtwNamespace();
    stack = newCTextStackModule();

    int error = create_lua_code();
    if(error){
        return error;
    }

    CTextStack *final_compilation = stack.newStack_string_format("gcc c/main.c -o %s",FINAL_OUPTUT);
    error = system(final_compilation->rendered_text);
    stack.free(final_compilation);
    if(error){
        return error;
    }
    #ifdef  RUN_AFTER

    CTextStack *run_command = stack.newStack_string_format("./%s",FINAL_OUPTUT);
        error = system(run_command->rendered_text);
        stack.free(run_command);

        if(error){
            return error;
        }
    #endif


    return 0;
}

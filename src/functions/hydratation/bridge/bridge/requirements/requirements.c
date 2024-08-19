
#include "../uniq.definitions_requirements.h"





void CWebHyDrationBridge_add_function(CWebHyDrationBridge *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *result = private_CWeb_format_vaarg(function,args);
    va_end(args);
    CwebStringArray_add_getting_ownership(self->entries_callbacks, result);
}

void private_CWebHyDrationBridge_add_elements_by_query_selector(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,bool auto_convert){
    const char *auto_convert_str = "false";
    if(auto_convert){
        auto_convert_str = "true";
    }
    CWebHyDrationBridge_add_function(self,
        "function (args,content){\
            private_cweb_get_elements_and_set_to_content({\
            content:content,\
            query_selector:`%s`,\
            search_name:`%s`,\
            auto_convert:%s\
            })\
        }",
        search_name,
        query_selector,
        auto_convert_str
    );

}



void CWebHyDrationBridge_add_elements_by_query_selector(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,...){

    va_list  args;
    va_start(args,query_selector);
    char *formmated_query_selector = private_CWeb_format_vaarg(query_selector,args);
    va_end(args);

    private_CWebHyDrationBridge_add_elements_by_query_selector(
        self,
        search_name,
        formmated_query_selector,
        true
    );
    free(formmated_query_selector);
}




void CWebHyDrationBridge_add_elements_by_query_selector_not_auto_converting(CWebHyDrationBridge *self,const char *search_name,const char *query_selector,...){

    va_list  args;
    va_start(args,query_selector);
    char *formmated_query_selector = private_CWeb_format_vaarg(query_selector,args);
    va_end(args);

    private_CWebHyDrationBridge_add_elements_by_query_selector(
        self,
        search_name,
        formmated_query_selector,
        false
    );
    free(formmated_query_selector);
}




void CWebHyDrationBridge_add_elements_by_attribute(CWebHyDrationBridge *self,const char *search_name,const char *attribute,const char*attribute_value,...){

    va_list  args;
    va_start(args,attribute_value);
    char *formmated_attribute = private_CWeb_format_vaarg(attribute_value,args);
    va_end(args);

    CWebHyDrationBridge_add_elements_by_query_selector(
        self,
        search_name,
        "[%s='%s']",
        attribute,
        attribute_value
    );
    free(formmated_attribute);
}

void CWebHyDrationBridge_add_elements_by_attribute_converting_to_number(CWebHyDrationBridge *self,const char *search_name,const char *attribute,const char*attribute_value,...){

    va_list  args;
    va_start(args,attribute_value);
    char *formmated_attribute = private_CWeb_format_vaarg(attribute_value,args);
    va_end(args);

    CWebHyDrationBridge_add_elements_by_query_selector_converting_to_number(
        self,
        search_name,
        "[%s='%s']",
        attribute,
        attribute_value
    );
    free(formmated_attribute);
}



void CWebHyDrationBridge_add_elements_by_class_name(CWebHyDrationBridge *self,const char *search_name,const char*class_value,...){

    va_list  args;
    va_start(args,class_value);
    char *formmatted_class = private_CWeb_format_vaarg(class_value,args);
    va_end(args);

    CWebHyDrationBridge_add_elements_by_query_selector(
        self,
        search_name,
        "[class='%s']",
        formmatted_class
    );
    free(formmatted_class);
}

void CWebHyDrationBridge_add_elements_by_class_name_converting_to_number(CWebHyDrationBridge *self,const char *search_name,const char*class_value,...){

    va_list  args;
    va_start(args,class_value);
    char *formmatted_class = private_CWeb_format_vaarg(class_value,args);
    va_end(args);

    CWebHyDrationBridge_add_elements_by_query_selector_converting_to_number(
        self,
        search_name,
        "[class='%s']",
        formmatted_class
    );
    free(formmatted_class);
}


void CWebHyDrationBridge_add_elements_by_id(CWebHyDrationBridge *self,const char *search_name,const char*id_values,...){

    va_list  args;
    va_start(args,id_values);
    char *formmated_id = private_CWeb_format_vaarg(id_values,args);
    va_end(args);

    CWebHyDrationBridge_add_elements_by_query_selector(
        self,
        search_name,
        "[id='%s']",
        formmated_id
    );
    free(formmated_id);
}

void CWebHyDrationBridge_add_elements_by_id_converting_to_number(CWebHyDrationBridge *self,const char *search_name,const char*id_values,...){

    va_list  args;
    va_start(args,id_values);
    char *formmated_id = private_CWeb_format_vaarg(id_values,args);
    va_end(args);

    CWebHyDrationBridge_add_elements_by_query_selector_converting_to_number(
        self,
        search_name,
        "[id='%s']",
        formmated_id
    );
    free(formmated_id);
}

void CWebHyDrationBridge_add_session_storage_item(CWebHyDrationBridge *self,const char *search_name,const char *name,...){

    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationBridge_add_function(self,
        "function (args,content){\
            private_cweb_get_session_storage_item({\
            content:content,\
            name:`%s`,\
            search_name:`%s`,\
            convert_to_number:false\
            })\
        }",
        formmated_name,
        search_name
    );
    free(formmated_name);
}


void CWebHyDrationBridge_add_session_storage_item_converting_to_number(CWebHyDrationBridge *self,const char *search_name,const char *name,...){

    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationBridge_add_function(self,
        "function (args,content){\
            private_cweb_get_session_storage_item({\
            content:content,\
            name:`%s`,\
            search_name:`%s`,\
            convert_to_number:true\
            })\
        }",
        formmated_name,
        search_name
    );
    free(formmated_name);
}

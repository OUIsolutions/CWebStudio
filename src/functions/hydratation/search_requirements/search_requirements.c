
#include "../uniq.definitions_requirements.h"






void private_CWebHyDrationSearchRequirements_free(CWebHyDrationSearchRequirements *self){
        free(self->name);
        free(self);
}


void CWebHyDrationSearchRequirements_add_function(CWebHyDrationSearchRequirements *self,const char *function,...){
    va_list  args;
    va_start(args,function);
    char *result = private_CWeb_format_vaarg(function,args);
    va_end(args);
    CwebStringArray_add_getting_ownership(self->bridge->entries_callbacks, result);
}

void private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,bool auto_convert
){
    const char *auto_convert_str = "false";
    if(auto_convert){
        auto_convert_str = "true";
    }
    CWebHyDrationSearchRequirements_add_function(self,
        "function (args,content){\
            private_cweb_get_elements_and_set_to_content({\
            content:content,\
            query_selector:`%s`,\
            search_name:`%s`,\
            auto_convert:%s\
            })\
        }",
        self->name,
        query_selector,
        auto_convert_str
    );

}



void CWebHyDrationSearchRequirements_add_elements_by_query_selector(
    CWebHyDrationSearchRequirements *self,
    const char *query_selector,
    ...
){

    va_list  args;
    va_start(args,query_selector);
    char *formmated_query_selector = private_CWeb_format_vaarg(query_selector,args);
    va_end(args);

    private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        formmated_query_selector,
        true
    );
    free(formmated_query_selector);
}




void CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
    CWebHyDrationSearchRequirements *self,const char *query_selector,...){

    va_list  args;
    va_start(args,query_selector);
    char *formmated_query_selector = private_CWeb_format_vaarg(query_selector,args);
    va_end(args);

    private_CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        formmated_query_selector,
        false
    );
    free(formmated_query_selector);
}




void CWebHyDrationSearchRequirements_add_elements_by_attribute(
    CWebHyDrationSearchRequirements *self,
   const char *attribute,
   const char*attribute_value,
   ...
){

    va_list  args;
    va_start(args,attribute_value);
    char *formmated_attribute = private_CWeb_format_vaarg(attribute_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        "[%s='%s']",
        attribute,
        attribute_value
    );
    free(formmated_attribute);
}

void CWebHyDrationSearchRequirements_add_elements_by_attribute_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char *attribute,
    const char*attribute_value,
    ...
){

    va_list  args;
    va_start(args,attribute_value);
    char *formmated_attribute = private_CWeb_format_vaarg(attribute_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
        self,
        "[%s='%s']",
        attribute,
        attribute_value
    );
    free(formmated_attribute);
}



void CWebHyDrationSearchRequirements_add_elements_by_class_name(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,
    ...
){

    va_list  args;
    va_start(args,class_value);
    char *formmatted_class = private_CWeb_format_vaarg(class_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        "[class='%s']",
        formmatted_class
    );
    free(formmatted_class);
}

void CWebHyDrationSearchRequirements_add_elements_by_class_name_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*class_value,...
){
    va_list  args;
    va_start(args,class_value);
    char *formmatted_class = private_CWeb_format_vaarg(class_value,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
        self,
        "[class='%s']",
        formmatted_class
    );
    free(formmatted_class);
}


void CWebHyDrationSearchRequirements_add_elements_by_id(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
){

    va_list  args;
    va_start(args,id_values);
    char *formmated_id = private_CWeb_format_vaarg(id_values,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector(
        self,
        "[id='%s']",
        formmated_id
    );
    free(formmated_id);
}

void CWebHyDrationSearchRequirements_add_elements_by_id_not_auto_converting(
    CWebHyDrationSearchRequirements *self,
    const char*id_values,
    ...
){

    va_list  args;
    va_start(args,id_values);
    char *formmated_id = private_CWeb_format_vaarg(id_values,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_elements_by_query_selector_not_auto_converting(
        self,
        "[id='%s']",
        formmated_id
    );
    free(formmated_id);
}

void CWebHyDrationSearchRequirements_add_session_storage_item_not_converting(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
){

    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_function(self,
        "function (args,content){\
            private_cweb_get_session_storage_item({\
            content:content,\
            name:`%s`,\
            search_name:`%s`,\
            auto_convert:false\
            })\
        }",
        formmated_name
    );
    free(formmated_name);
}


void CWebHyDrationSearchRequirements_add_session_storage_item(
    CWebHyDrationSearchRequirements *self,
    const char *name,
    ...
){

    va_list  args;
    va_start(args,name);
    char *formmated_name = private_CWeb_format_vaarg(name,args);
    va_end(args);

    CWebHyDrationSearchRequirements_add_function(self,
        "function (args,content){\
            private_cweb_get_session_storage_item({\
            content:content,\
            name:`%s`,\
            search_name:`%s`,\
            auto_convert:true\
            })\
        }",
        formmated_name
    );
    free(formmated_name);
}

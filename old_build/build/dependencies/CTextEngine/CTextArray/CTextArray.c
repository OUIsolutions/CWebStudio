
CTextArray * newCTextArray(){
    CTextArray  *self = (CTextArray*) malloc(sizeof (CTextArray));
    self->size = 0;
    self->stacks = (CTextStack**) malloc(0);
    return self;
}

void CTextArray_append(CTextArray *self,CTextStack *element){
    self->stacks =  (CTextStack**) realloc(
            self->stacks,
            (self->size+1)* sizeof (CTextStack*)
            );

    self->stacks[self->size] = element;
    self->size+=1;
}



void CTextArray_append_string(CTextArray *self,const char *element){
    CTextStack *new_element = newCTextStack_string(element);
    CTextArray_append(self,new_element);
}

CTextStack * CTextArray_join(CTextArray *self,const char *separator){
    CTextStack  *result  = newCTextStack_string_empty();
    for(int i = 0; i < self->size; i++){
        if(i < self->size -1){
            CTextStack_format(result,"%t%s",self->stacks[i],separator);
        }
        else{
            CTextStack_format(result,"%t",self->stacks[i]);

        }

    }
    return result;
}

CTextArray *CTextArray_split(const char *element,const char *target){
    CTextArray *self = newCTextArray();
    CTextStack *text = newCTextStack_string(element);
    long target_size = (long)strlen(target);
    CTextStack  *acumulated = newCTextStack_string_empty();

    for(int i = 0; i <text->size; i++){
        CTextStack  *possible_division = CTextStack_substr(text,i,target_size + i);
        if(CTextStack_equal(possible_division,target)){
            CTextArray_append(self,acumulated);
            acumulated = newCTextStack_string_empty();
            CTextStack_free(possible_division);
            continue;
        }
        CTextStack_free(possible_division);

        CTextStack_format(acumulated,"%c",text->rendered_text[i]);
    }

    CTextArray_append(self,acumulated);
    CTextStack_free(text);
    return self;
}

bool CTextStack_equal(struct  CTextStack *self,const char *element){
    return strcmp(self->rendered_text,element) == 0;
}


void  CTextArray_free(CTextArray *self){
    for(int i = 0; i < self->size; i++){
            CTextStack_free(self->stacks[i]);
    }
    free(self->stacks);
    free(self);
}

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();
    for(int i = 0; i < self->size; i++){
        CTextStack *result = caller(self->stacks[i]);
        CTextArray_append(new_array,result);
    }
    return new_array;
}


CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();

    for(int i = 0; i < self->size; i++){
        if(caller(self->stacks[i])){

            CTextArray_append(new_array, CTextStack_clone(self->stacks[i]));
        }
    }

    return new_array;
}

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element)){
    for(int i = 0; i < self->size; i++){
        caller(self->stacks[i]);
    }
}

bool CTextArray_includes(CTextArray *self,const char *element){
    for(int i = 0 ; i < self->size;i++){
        if(CTextStack_equal(self->stacks[i],element)){
            return true;
        }
    }
    return false;
}


void CTextArray_represent(CTextArray *self){
    for(int i =0; i < self->size; i++){
        CTextStack_represent(self->stacks[i]);
    }
}
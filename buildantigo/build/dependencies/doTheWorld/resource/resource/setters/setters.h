//
// Created by mateusmoutinho on 05/08/23.
//
void private_dtw_resource_set_primary_key(DtwResource *self, unsigned  char *element, long size);

void DtwResource_set_binary(DtwResource *self, unsigned char *element, long size);


void DtwResource_set_string(DtwResource *self,const  char *element);

void DtwResource_set_binary_sha(DtwResource *self, unsigned  char *value, long size);


void DtwResource_set_string_sha(DtwResource *self,const char *value);


void DtwResource_set_long(DtwResource *self,long element);


void DtwResource_set_double(DtwResource *self,double element);

void DtwResource_set_bool( DtwResource *self,bool element);


# DoTheWorld
DoTheWorld is a Windows/Linux single file library designed to handle files in C/C++ in a number of ways, providing everything from simple functions for reading/writing files and folders, to complex functions like taking sha256 from files, checking modification dates. And functionalities of atomic writing of folders/files through transaction systems.



## Learning
In These Current Markdown you will see some basic exemples of usage of these library
but if you want to get an deep knolege see at **exemples** folder, you will find an lot of exemplos of how you can use DoTheWorld

# Installation
The installation of DoTheWorld is made to be as dumb as possible, just  download the file  **doTheWorld.h** :

[Download link](https://github.com/OUIsolutions/DoTheWorld/releases/download/v7.001/doTheWorld.h)

 And include in your project.
if this compiles then the library will work:
~~~c
#include "doTheWorld.h"

int main(int argc, char *argv[]){


    return 0;
}
~~~

## Full Folder
Alternatively you can download the entire **src** folder and include the **src/one.c** file

~~~c

#include "src/one.c"

int main(int argc, char *argv[]){

    return 0;
}

~~~
## Pre Compiled version
You also can download the pre compiled versions
[Pre Compiled Linux](https://github.com/OUIsolutions/DoTheWorld/releases/download/v7.001/pre_compiled_linux.zip) or
[Pre Compiled Windows](https://github.com/OUIsolutions/DoTheWorld/releases/download/v7.001/pre_compiled_windows.zip) to
optimize compilation time, extract the zip , than you can run with:
~~~c
#include "doTheWorldDeclaration.h"

int main(){
  return 0;
}
~~~
compile with:

~~~shel
gcc main.c cJSON.o doTheWorld.o sha256.o
~~~


# Bulding the Project
if you want to exec all tests, or generate your own amalgamation,
just run the **./build.out** or **build.exe** located into the root dir of the repo

~~~shel
./build.out
~~~
# IO Operations

## Reading strings
if you are sure that the content you are going to read is not binary you can call the function **dtw_load_string_file_content**
codeof: exemples/io/loading_string.c

### Reading Any Content

codeof: exemples/io/loading_any.c

### Reading Double bools and Integers
you also can direclty load all types from an file  with numerical ios

codeof: exemples/numerical_io/loading_data.c

to write strings in text files is very simple, just call the function **dtw_write_string_file_content**
(Note that the target directory does not need to exist, if it does not exist it will be created automatically)

codeof: exemples/io/writing_strings.c


### Writing Any
if you want to write anything to a file, it's also very simple, use the **dtw_write_any_content** function, but note that it will be necessary to pass the writing size


codeof: exemples/io/write_any.c

### Writing Double , bool and Integers
You also can write any type direclty to an file

codeof: exemples/numerical_io/writing_data.c

If you want to create dirs you can call the function **dtw_create_dir_recursively**
passing the folder you want to create,dont wory about if the previews path dont exist
it will create till reachs the target folder

codeof: exemples/io/create_dirs.c

### Copying Anything
With the function **dtw_copy_any** you can copy either files or folders to one position to anoter position

codeof: exemples/io/copying_files.c

### Moving Any
You can move either folders or files with **dtw_move_any** function

codeof:exemples/io/move_any.c


With the listage functions you can extract all Strings Arrays of elements in an folder

## Listing files

codeof: exemples/monodimension_listage/list_files.c

### Listing Dirs

codeof:exemples/monodimension_listage/list_dirs.c

### Listing All

codeof:exemples/monodimension_listage/list_all.c

The By Using multi dimension listage functions , you can see all itens listed in all sub folders of the "main" folder

## Listing Files Recursively

codeof:exemples/multidimension_listage/list_files_recursively.c

## Listing Dirs Recursively

codeof:exemples/multidimension_listage/list_dirs_recursively.c

## Listing All Recursively

codeof:exemples/multidimension_listage/list_all_recursively.c

## Dealing with base64
You can easly transform an binary file to an base64 string like these

codeof:exemples/extras/converting_file_to_base64.c

You also can reconvert an base64 string to binary

codeof:exemples/extras/converting_b64_to_binary.c


## Sha256
Generating Sha from file

codeof:exemples/extras/generating_sha_from_file.c

### Unix

codeof: exemples/extras/get_entity_last_modification_in_unix.c


codeof: exemples/extras/get_entity_last_modification.c


## Locker
With the locker you can Lock files and ensure that even with multprocessment, they will
be executed in an order

codeof:exemples/locker/locker_test.c

## Resources
With Resources you can iterate over all types of values ,and modifie than into an single transaction or one by one
### Setting Values

codeof:exemples/resources/setters.c




### Getting values of Resource
codeof:exemples/resources/getters.c


### Generating transaction
with transactions you can make all modifications and executed or denny it one time,avoid nod
wanted side effects

codeof:exemples/transaction/transaction_executiong.c


You also can dump the transaction to an json file to store it

codeof:exemples/transaction/transaction_dumping_to_json.c

codeof:exemples/transaction/transaction_loading_from_json.c



### Schemas

Schema its a way to handle resources into a serializible way, providing foreing key and primary key concepts

### Creating a insertion
in these example we are creating a user using schema concept

codeof:exemples/schema/user_creation.c



### Removing a insertion
In these example we also can destroy the user , automaticly destroying the index

codeof:exemples/schema/user_remove.c


### Finding a insertion
With  primary keys you can find values without loop iteration increasing readability and speed,

codeof:exemples/schema/user_find.c


### Iterating over insertions
you also can iterate over insertions

codeof:exemples/schema/user_iteration.c

### Iterable Resources

with iterable functional system , you can iterate into Resources easly



#### Each
with each, you can pass  also a filtrage callback, a start point (defaults its 0),
and the total elements (defaults its all)
codeof:exemples/resources/Foreach.c

#### Schema Each
you also can iterate over schemas with schema each

codeof:exemples/schema/schema_each.c

#### Map
with map you can construct, objects lists, with what ever you want
you just need to pass the object, the retriver, and some append function
to be called each generated object

codeof:exemples/resources/map.c

of course, it also works with schemas

codeof:exemples/schema/schema_map.c

#### CJson Array Map
you also can directly map a cJSON Array

codeof:exemples/resources/cJSON_ArrayMap.c

#### CJSON Object Map
you also can generate a cJSON object, but you need to
provide a "keey_provider" function ,to determine the key of each
object generation (note that these key can bee released(free) after, you pass the),
free_key prop into the props object

codeof:exemples/resources/cJSON_ArrayObject.c

#### CCHash
you can use [CHash](https://github.com/OUIsolutions/CHashManipulator) objects too
but in these case , you need to use define  DTW_ALLOW_CHASH , and include the lib
into the project since CHashManipulator, its not included into the amalgamation
codeof:exemples/resources/CHashArray_map.c

### Trees and TreeParts
with tree concepts, you can manipulate files as trees, and implement IO modifications with atomic concepts

### Loading An TreePart

codeof:exemples/tree_parts/loading_tree_part.c


### Creating an empty tree Part

codeof:exemples/trees/creating_tree_part.c

### Modifying an tree part

codeof:exemples/tree_parts/tree_part_content_modification.c


### Retriing Paths Paramns

codeof:exemples/path/getting_path_paramns.c

### Changing path Atributes at once


codeof:exemples/path/change_path_attributes.c

With the **hardware_modify** , **hardware_write**, **hardware_remove**
Functions , you can generate modifications, without implement it, in these
way , you can create massive atomic transactions, and execute all at once


### hardware_modify
Will Modificate the original content, for exemple, if you change the extension of an file, it will modificate the original content


codeof:exemples/tree_parts/hardware_modify.c

Will write the file as an "new" file, ignoring the existence of the
old file

codeof:exemples/tree_parts/hardware_write.c


Will Delete the current Content


codeof:exemples/tree_parts/hardware_remove.c

With Trees you can make massive folders and files modifications with
easy steps
### Loading Tree From Hardware

codeof:exemples/trees/add_tree_from_hardware.c

### Iterating over An Tree

codeof:exemples/trees/tree_iteration.c

### Finding An Tree by name

codeof:exemples/trees/find_tree_part_by_name.c


### Finding An Tree by Path

codeof:exemples/trees/find_tree_part_by_full_path.c

### Finding An Tree by Function

codeof:exemples/trees/finding_tree_part_by_function.c

Trees suports even Maps or filters, it returns an new tree of the of the current lambda procediment
#### Filter
with filter you can filter the contents you want in an tree with an bool lambda

codeof:exemples/trees/tree_filter.c

### Map

codeof:exemples/trees/tree_map.c

With **hardware_commit_tree** you can commit all modifications at Once
turning system ultra securty


codeof:exemples/trees/tree_commit.c


With transactin Reports , you can see what will be modified

codeof:exemples/trees/transaction_report.c

With Json Trees Operations you can save or load trees, from hardware or strings in an super easy mode

#### Dumping Tree Json To File
It will transform the tree in an json document

codeof:exemples/trees/dumps_json_tree_to_file.c


codeof:exemples/trees/dumps_json_tree_to_string.c

If you want to recuperate the file you saved in the json file
you can load it

codeof:exemples/trees/loads_json_tree_from_file.c


codeof:exemples/trees/loads_json_tree_from_string.c


## Hash

By using hash Object you can digest values,( its very usefull in dynamic programing)
or to avoid recomputation in compilers or bundlers

### Simple Hashing

codeof:exemples/hash/simple_digest.c

codeof:exemples/hash/file_hashing.c

codeof:exemples/hash/file_hashing_by_last_modification.c


### Randonizer
Randonizer it's a way to generate random values,integers or strings

#### Numerical Random
codeof:exemples/randonizer/num_randonizer.c

#### Token  Random
codeof:exemples/randonizer/token_randonizer.c


## CJson<br><br>
**CJson**: from https://github.com/DaveGamble/cJSON <br>
Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## sha-256 <br>
**sha-256**: from https://github.com/amosnier/sha-2 <br>

Zero Clause BSD License
© 2021 Alain Mosnier

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

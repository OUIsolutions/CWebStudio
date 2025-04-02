
void private_cweb_load_file_and_include(
        CTextStack *code,
        CTextStack *src,
        privateCwebRecursionList * recursion_listage
);
void private_cweb_generate_inline_inclusion(CTextStack *code, const char *content, long content_size,
                                            privateCwebRecursionList *recursion_listage, const char *filename);

## Search Result

SearchResult are the objects used to retrieve the information sent by the browser, defined in the search requirements.

```c
CWebHyDrationSearchResult * name = result_module.get_search_by_name(bridge,"name");
char *first_result_of_name = result_module.get_string(name,0);
```

This example demonstrates how to retrieve search results from the browser.
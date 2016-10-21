#include <stdio.h>
#include <string.h>
#define IMPORT_FROM_AQUA
#include <aqua.h>
#include <criterion/criterion.h>

Test(string, cstr2s) {
    string s = cstr2s("hello");

    cr_assert(strcmp(s->data, "hello") == 0, "string is hello");
    cr_assert(s->len == 5, "length is 5");
    sdestroy(s);
}

Test(string_builder, sbldaddchar) {
    string_builder b;
    string s;
    char *cstr;

    b = sbldcreate();
    sbldaddchar(b, 'a');
    s = sbld2s(b);
    cstr = s2cstr(s);

    cr_assert(strcmp(cstr, "a") == 0, "check we can add a char to string builder");
    free(cstr);
}

Test(string_builder, sbldadds) {
    string_builder b;
    string s;
    string s2;
    char *cstr;

    b = sbldcreate();
    s = cstr2s("abc");
    sbldadds(b, s);
    s2 = sbld2s(b);
    cstr = s2cstr(s2);

    cr_assert(strcmp(cstr, "abc") == 0, "check we can add a string to string builder");
    free(cstr);    
}

Test(string_builder, sblddestroy)
{
    string_builder b;

    b = sbldcreate();
    sbldaddchar(b, 'x');
    sblddestroy(b);
}

Test(getline, test)
{
    FILE *fp;
    int has_term;
    string s;

    fp = fopen("../LICENSE", "r");

    cr_assert(fp, "should be able to open file");

    s = getline(fp, &has_term);
    cr_assert(has_term, "should have line termination character");
    cr_assert(strcmp(s->data, "GNU LESSER GENERAL PUBLIC LICENSE\n") == 0, "should get the first line");
    sdestroy(s);
}

Test(url_encode, test)
{
    char *str = "name=one&value=1&comment=what's up doc?";
    char *str2 = url_encode(str);
    char *str3;
    str3 = url_decode(str2);
    cr_assert(strcmp(str, str3) == 0, "check that decode matches original string");
    printf("%s\n", str);
    printf("%s\n", str2);
    printf("%s\n", str3);
    free(str2);
    free(str3);
}
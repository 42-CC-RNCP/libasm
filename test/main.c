#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);
extern char* ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

void test_strlen();
void test_strcpy();
void test_strcmp();

int main() {
    printf("======= Simple Tests ==========\n");
    test_strlen();
    printf("-------------------------------\n");
    test_strcpy();
    printf("-------------------------------\n");
    test_strcmp();
    printf("\n");
    return 0;
}

void test_strlen() {
    const char *tests[] = {
        "", "a", "abc", "hello world", "1234567890",
        "abc\0hidden",                      // embedded null
        "This is a long string with 123!", // mixed content
        "🔥UTF8🔥"                          // multibyte UTF-8 (length in bytes)
    };
    int n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; i++) {
        size_t expected = strlen(tests[i]);
        size_t actual = ft_strlen(tests[i]);
        printf("ft_strlen(\"%s\") = %zu | strlen = %zu | %s\n",
               tests[i], actual, expected,
               (actual == expected) ? "✅" : "❌ MISMATCH");
    }
}

void test_strcpy() {
    const char *tests[] = {
        "", "abc", "hello", "1234567890",
        "a very very long string here...",
        "with space and !@#$%", "🔥🔥"
    };
    char buf[100];
    int n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; i++) {
        memset(buf, 0x42, sizeof(buf));  // Fill with dummy data
        ft_strcpy(buf, tests[i]);
        printf("ft_strcpy(\"%s\") = \"%s\" | %s\n",
               tests[i], buf,
               (strcmp(buf, tests[i]) == 0) ? "✅" : "❌ MISMATCH");
    }
}

void test_strcmp() {
    const char *s1[] = {
        "abc", "abc",  "ab",   "",    "abc", "",    "Abc",
        "a",   "a\1b", "abcd", "abc", "🔥",  "🔥"
    };
    const char *s2[] = {
        "abc", "ab",   "abc",  "",    "",    "abc", "abc",
        "b",   "a\1b", "abce", "abc\0x", "🔥", "💥"
    };
    int n = sizeof(s1) / sizeof(s1[0]);

    for (int i = 0; i < n; i++) {
        int expected = strcmp(s1[i], s2[i]);
        int actual = ft_strcmp(s1[i], s2[i]);
        printf("ft_strcmp(\"%s\", \"%s\") = %d | strcmp = %d | %s\n",
               s1[i], s2[i], actual, expected,
               (actual == expected) ? "✅" : "❌ MISMATCH");
    }
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern size_t ft_strlen(const char *str);
extern char* ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strdup(const char *s);

void test_strlen();
void test_strcpy();
void test_strcmp();
void test_write();
void test_read();
void test_strdup();

int main() {
    printf("======= Simple Tests ==========\n");
    test_strlen();
    printf("-------------------------------\n");
    test_strcpy();
    printf("-------------------------------\n");
    test_strcmp();
    printf("-------------------------------\n");
    test_write();
    printf("-------------------------------\n");
    test_read();
    printf("-------------------------------\n");
    test_strdup();
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
               ((actual & (1 << 31)) == (expected & (1 << 31))) ? "✅" : "❌ MISMATCH");
    }
}

void test_write() {
    const char *msg = "Hello from ft_write\n";
    ssize_t ret;

    printf("[ft_write to STDOUT]:\n");
    ret = ft_write(1, msg, strlen(msg));
    printf("Return: %zd | errno: %d (%s)\n", ret, errno, strerror(errno));

    printf("[ft_write to bad fd]:\n");
    ret = ft_write(-1, msg, strlen(msg));
    printf("Return: %zd | errno: %d (%s)\n", ret, errno, strerror(errno));
}

void test_read() {
    char buffer[100];
    ssize_t ret;

    printf("[ft_read from STDIN] (type something then Enter):\n");
    memset(buffer, 0, sizeof(buffer));
    ret = ft_read(0, buffer, sizeof(buffer) - 1);
    printf("Return: %zd | errno: %d (%s)\n", ret, errno, strerror(errno));
    printf("Buffer: \"%s\"\n", buffer);

    printf("[ft_read from bad fd]:\n");
    memset(buffer, 0, sizeof(buffer));
    ret = ft_read(-1, buffer, 10);
    printf("Return: %zd | errno: %d (%s)\n", ret, errno, strerror(errno));
}

void test_strdup() {
    const char *tests[] = {
        "", "a", "abc", "hello world", "1234567890",
        "🔥🔥", "string with space", "newline\ninside", "null\0hidden"
    };
    int n = sizeof(tests) / sizeof(tests[0]);

    printf("[ft_strdup Tests]:\n");
    for (int i = 0; i < n; i++) {
        const char *input = tests[i];
        char *dup = ft_strdup(input);
        int same = strcmp(dup, input) == 0;

        printf("ft_strdup(\"%s\") = \"%s\" | %s\n",
               input, dup ? dup : "(null)",
               (dup && same) ? "✅" : "❌ MISMATCH OR NULL");

        free(dup); // free to avoid memory leak
    }
}

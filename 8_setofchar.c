#include <stdio.h>
#include <string.h>

void generateStrings(const char *characters, int k, char *current)
{
	int i;
    if (k == 0)
    {
        printf("%s\n", current);
        return;
    }

    for (i = 0; i < strlen(characters); i++)
    {
        current[k - 1] = characters[i];
        generateStrings(characters, k - 1, current);
    }
}

int main()
{
    const char *input_characters = "abc"; // replace with your set of characters
    int k = 3;                            // replace with your desired length

    char current[k + 1];
    current[k] = '\0'; // null-terminate the string

    generateStrings(input_characters, k, current);

    return 0;
}

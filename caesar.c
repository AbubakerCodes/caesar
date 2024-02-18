#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string msg);
string encryptMessage(int key, string msg);
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if(only_digits(argv[1]))
    {
        int cipherKey = atoi(argv[1]);
        string userMessage = get_string("Your message: ");
        string cipherText = encryptMessage(cipherKey, userMessage);
        printf("ciphertext: %s\n", cipherText);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool only_digits(string msg)
{
    for(int i = 0, n = strlen(msg); i < n; i++)
    {
        if(!isdigit(msg[i]))
        {
            return false;
        }
    }
    return true;
}
string encryptMessage(int key, string msg)
{
    int n = strlen(msg);
    char encryptedMessage[n + 1];

    for(int i = 0; i < n; i++)
    {
        if (isalpha(msg[i]))
        {
            if (isupper(msg[i]))
            {
                encryptedMessage[i] = 'A' + (msg[i] - 'A' + key) % 26;
            }
            else
            {
                encryptedMessage[i] = 'a' + (msg[i] - 'a' + key) % 26;
            }
        }
        else
        {
            encryptedMessage[i] = msg[i];
        }
    }

    encryptedMessage[n] = '\0';

    // Convert the character array to a string
    char *result = malloc(strlen(encryptedMessage) + 1);
    strcpy(result, encryptedMessage);
    return result;
}
